#include "dbcolleges.h"
#include <algorithm>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextStream>
#include <QFileDialog>
#include <fstream>

DBColleges::DBColleges()
{

}

DBColleges::~DBColleges()
{

}


void DBColleges::readLine(std::istream& file, std::vector<std::string>& line)
{
    char ch;    // character we will read in
    std::string readline;            // line we will be using to read from
    std::string entry = "";         // current entry we are reading (before next ',')
    bool inquotes = false;          // If the entry contains quotes
    bool quoteFound = false;        // If a quote was found inside of a quoted entry
    bool carraigeReturn = false;    // If a carraige return was found
    bool newLine = false;           // Once line is finished, return

    if (file.peek() != EOF)
    {
        do
        {
            ch = file.get();

            switch(ch)
            {
            case '"':
                if (inquotes)   // if we're already reading an entry within quotes
                {
                    if (quoteFound)
                    {
                        quoteFound = false;     // switch this back to false & add to entry
                        entry += '"';
                    }
                    else
                    {
                        quoteFound = true;
                    }
                }
                else if (entry.length() == 0)   // If the first character in an entry is a quote, we're in a quoted entry
                {
                    inquotes = true;
                }
                else
                {
                    qDebug() << "Invalid quotes.";
                }
                break;
            case '\r':
                if (inquotes)
                {
                    entry += '\r';
                }
                else
                {
                    carraigeReturn = true;
                }
                break;
            case '\n':
                if (inquotes)
                {
                    entry += '\n';
                }
                else
                {
                    carraigeReturn = false;
                    newLine = true;
                }
                break;
            default:
                if (ch == ',')      // If we hit a comma, check if we're in quotes or not, else it's a separator
                {
                    if (inquotes)
                    {
                        if (quoteFound) // If entry is already in quotes, and we find the second set of quotes, input the entry
                        {
                            quoteFound = false;
                            inquotes = false;
                            line.push_back(entry);
                            entry = "";
                        }
                        else
                        {
                            entry += ',';    // else add comma to entry
                        }
                    }
                    else
                    {
                        line.push_back(entry);  // else move on to the next entry to be read in
                        entry = "";
                    }
                }
                else
                {
                    entry += ch;    // or just add the char to the entry
                }
                break;
            }
        }while(file.peek() != EOF && !newLine);

        line.push_back(entry);      // if empty, just add an empty string. All lines will have the same number of fields,
                                    // but not necessarily the same number of entries
    }

}

void DBColleges::readEntries(const std::string& path)
{
    // Temp data to be used for reading from the csv file
    College newCollege;
    College endCollege;
    QString nameInput;
    QString stateInput;
    int undergrads;
    std::vector<std::string> line;          // This is the line that has been read in from readLine


    std::ifstream csvfile;
    csvfile.open(path);

    // Check if file is actually open. If not, throw debug message and return
    if(!csvfile.is_open())
    {
        qDebug() << "Could not open specified csv file";
        csvfile.close();
        return;
    }
    else
    {
        qDebug() << "File successfully opened";
    }

    int j = 0;
    while(!csvfile.eof())
    {
        int i = 0;
        nameInput = "";
        stateInput = "";
        line.clear();       // Clear the list of data from the current line so we can read the next one

        // As long as you don't close the file, the stream should know where it is
        this->readLine(csvfile, line);
        nameInput = QString::fromStdString(line.at(0)); // convert the string into a Qstring

        if (nameInput == newCollege.name){
            while (i < 3)   // If we're only reading in the next distance, we're only reading in [1], and [2] of the line
            {
                i++;    // i = 1, skip the first entry since we already are on the new college still

                nameInput = QString::fromStdString(line.at(i));    // Insert end college name
                this->collegeVector[j].endingColleges.push_back(nameInput);
                i++;    // i = 2

                this->collegeVector[j].distances.push_back(std::stoi(line.at(i)));  // Insert distance to end college
                i++;    // i = 3
            }
        }
        else // Else we are inputting a new college
        {
            if (this->collegeVector.size() > 0) // if we have more than 1 entry
            {
                j++;
            }
            // Clear the existing distances and ending colleges from previous entry
            newCollege.distances.clear();
            newCollege.endingColleges.clear();

            while(i < line.size())
            {
                nameInput =  QString::fromStdString(line.at(i));    // Should be first entry
                newCollege.name = nameInput;
                i++;    // i = 1

                nameInput = QString::fromStdString(line.at(i));    // Should be second entry
                newCollege.endingColleges.push_back(nameInput);
                i++;    // i = 2

                newCollege.distances.push_back(std::stoi(line.at(i)));  // Third entry
                i++;    // i = 3

                stateInput = QString::fromStdString(line.at(i));    // Fourth entry
                newCollege.state = stateInput;
                i++;    // i = 4

                newCollege.undergrads = std::stoi(line.at(i));  // convert from string to int
                i += 2;     // i > 4, so done with entry. Add 2 because last index will always
                            // be an empty value and make size 1 larger than actual entries

            }
            this->collegeVector.push_back(newCollege);  // Push new college into program vector
        }
    }
    csvfile.close();
}

void DBColleges::loadFileEntries()
{
    QString file = QFileDialog::getOpenFileName();
    std::string path = file.toStdString();

    if (!file.trimmed().isEmpty())
    {
            DBColleges::readEntries(path);
    }
}
