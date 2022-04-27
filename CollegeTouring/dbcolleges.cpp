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
    this->database = QSqlDatabase::addDatabase("QSQLITE","collegedata.sqlite");
    this->database.setDatabaseName("collegedata.sqlite");

    if(this->database.open())
    {
        qDebug() << "DBColleges::DBColleges() Database connection successfully established.";


        QSqlQuery query(this->database);

        //Specifies the table headers for COLLEGES table. (Can be used for the vertices in a graph)
        query.exec("CREATE TABLE IF NOT EXISTS colleges ( College varchar(255), State varchar(255), Undergrads int )");

        //Specifies the table headers for SOUVENIRS table.
        query.exec("CREATE TABLE IF NOT EXISTS souvenirs ( College varchar(255), ItemName varchar(255), Price numeric )");

        //Specifies the table headers for DISTANCES table. (Can be used for the edges in a graph)
        query.exec("CREATE TABLE IF NOT EXISTS distances ( StartingCollege varchar(255), EndingCollege varchar(255), Distance numeric )");
    }
    else
    {
        qDebug() << "DBColleges::DBColleges() Database connection unsucessful.";
    }
}


DBColleges::~DBColleges()
{
    if(this->database.isOpen())
    {
        this->database.close();
        this->database.removeDatabase("collegedata.sqlite");
        qDebug() << "DBColleges::~DBColleges() Database connection removed.";
    }
}


/*!
 * \brief DBColleges::readLine
 * \param file - Path to the specified file (must be ifstream)
 * \param line - Vector of characters to be modified by reading the current line in stream
 *
 * Reads a single line in a csv file (Compatible with csv files only) and stores the characters
 * into a vector of characters (std::string)
 *
 * TODO: change vector to regular string since that's just a char vect.
 */
void DBColleges::readLine(std::istream& file, std::vector<std::string>& line)
{
    char ch;    // character we will read in
    std::string readline;            // line we will be using to read from
    std::string entry = "";         // current entry we are reading (before next ',')
    bool inquotes = false;          // If the entry contains quotes
    bool quoteFound = false;        // If a quote was found inside of a quoted entry
   // bool dollarSign = false;
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
            case '$':
                if (inquotes)
                {
                    entry += '$';
                }
                else
                {
                    entry = "";  // Don't add the dollar sign;
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


/*!
 * \brief DBColleges::readEntries
 * \param path - Path to csv file to be read
 *
 * Reads each line and stores data within corresponding objects.
 */
void DBColleges::readEntries(const std::string& path)
{
    // Temp data to be used for reading from the csv file
    College newCollege;
    College endCollege;
    QString nameInput;
    QString stateInput;
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
                i++;    // i = 2

                this->collegeMap[newCollege.name].distances.insert(nameInput,std::stoi(line.at(i)));
                i++;    // i = 3
            }
        }
        else // Else we are inputting a new college
        {
            if (this->collegeMap.size() > 0) // if we have more than 1 entry
            {
                j++;
            }
            // Clear the existing distances and ending colleges from previous entry
            newCollege.distances.clear();

            while(i < line.size())
            {
                nameInput =  QString::fromStdString(line.at(i));    // Should be first entry
                newCollege.name = nameInput;
                i++;    // i = 1

                nameInput = QString::fromStdString(line.at(i));    // Should be second entry
                i++;    // i = 2

                newCollege.distances.insert(nameInput,std::stoi(line.at(i)));
                i++;    // i = 3

                stateInput = QString::fromStdString(line.at(i));    // Fourth entry
                newCollege.state = stateInput;
                i++;    // i = 4

                newCollege.undergrads = std::stoi(line.at(i));  // convert from string to int
                i += 2;     // i > 4, so done with entry. Add 2 because last index will always
                            // be an empty value and make size 1 larger than actual entries

            }
            this->collegeMap.insert(newCollege.name,newCollege);  // Push new college into program map
        }
    }
    csvfile.close();
}

/*!
 * \brief DBColleges::readSouvenirs
 * \param path - Path to csv file
 *
 * Will read the file and assign data to its corresponding objects.
 */
void DBColleges::readSouvenirs(const std::string& path){

    std::vector<std::string> line;          // This is the line that has been read in from readLine

    std::ifstream csvfile;
    csvfile.open(path);

    // Check if file is actually open. If not, throw debug message and return
    if(!csvfile.is_open())
    {
        qDebug() << "Could not open specified csv file for reading souvenirs.";
        csvfile.close();
        return;
    }
    else
    {
        qDebug() << "File successfully opened to read in souvenirs.";
    }

    QString nameInput;
    std::string priceInput;
    QString currentCollege;
    while(!csvfile.eof())
    {
        int i = 0;
        nameInput = "";
        priceInput = "";
        line.clear();       // Clear the list of data from the current line so we can read the next one

        this->readLine(csvfile, line);
        //int j = 0;
        if (line.at(0) == ""){
            while (i < 3)   // If we're only reading in the next distance, we're only reading in [1], and [2] of the line
            {
                SouvenirItem newsouvenir;
                i++;    // i = 1, skip the first entry since we already are on the new college still

                nameInput = QString::fromStdString(line.at(i));    // Insert Souvenir item name
                i++;    // i = 2

                priceInput = line.at(i);    // Read item price
                newsouvenir.name = nameInput;
                newsouvenir.price = std::stod(priceInput);
                this->collegeMap[currentCollege].souvenirs.push_back(newsouvenir);
                i++;    // i = 3
            }   // If line.at(0) reads a college, then we will start reading in the souvenirs.
        }
        else
        {
            currentCollege = QString::fromStdString(line.at(0));
        }
    }

    csvfile.close();
}

void DBColleges::loadCollegeEntries()
{
    QString file = QFileDialog::getOpenFileName();
    std::string path = file.toStdString();

    if (!file.trimmed().isEmpty())
    {
            DBColleges::readEntries(path);
    }
}
void DBColleges::loadSouvenirEntries()
{
    QString file = QFileDialog::getOpenFileName();
    std::string path = file.toStdString();

    if (!file.trimmed().isEmpty())
    {
            DBColleges::readSouvenirs(path);
    }
}


// Populates the graph by creating vertices and edges from an existing map
void DBColleges::populateGraph()
{
    if(!this->collegeMap.empty())
    {
        OrderedMap<QString,int> temporaryId;
        int currentId = 0;

        //Assigns ids (indices) to the corresponding college names
        for(auto iterator = this->collegeMap.cbegin(); iterator != collegeMap.cend(); iterator++)
        {
            temporaryId.insert(iterator->value.name,currentId);
            currentId++;
        }

        //Inserts all of the edges of each college into the graph
        this->collegesGraph = Graph(this->collegeMap.size()); //Initalizes graph to have a size of the college map

        for(auto iterator = this->collegeMap.cbegin(); iterator != collegeMap.cend(); iterator++)
        {
            Vertex startingVertex(temporaryId[iterator->value.name], iterator->value.name.toStdString());


            for(auto iterator2 = iterator->value.distances.cbegin(); iterator2 != iterator->value.distances.cend(); iterator2++)
            {
                Vertex endingVertex(temporaryId[iterator2->key], iterator2->key.toStdString());

                //Adds the edge into collegesGraph
                this->collegesGraph.addEdge(startingVertex, endingVertex, iterator2->value);
            }
        }

        qDebug() << "Populated graph with colleges";
    }
    else
    {
        qDebug() << "Failed to populate graph because collegeMap is empty";
    }
}


void DBColleges::loadFromDatabase()
{
    QSqlQuery collegesQuery(this->database);
    QSqlQuery distancesQuery(this->database);
    QSqlQuery souvenirsQuery(this->database);

    if(collegesQuery.exec("SELECT * FROM colleges"))
    {
        while(collegesQuery.next())
        {
            College newCollege;
            newCollege.name = collegesQuery.value(0).toString();    //Column1(College) = college name
            newCollege.state = collegesQuery.value(1).toString();   //Column2(State) = state name
            newCollege.undergrads = collegesQuery.value(2).toInt(); //Column3(Undergrads) = undergrad number

            //Reads from the DISTANCES table and inserts endingColleges & distances into their respective vectors
            if (distancesQuery.exec("SELECT * FROM distances WHERE StartingCollege = '" + newCollege.name + "'"))
            {
                while(distancesQuery.next())
                {
                    //Column2(EndingCollege) = ending college name
                    //Column3(Distance) = distance to ending college
                    newCollege.distances.insert(distancesQuery.value(1).toString(), distancesQuery.value(2).toDouble());
                }
            }

            //Reads from the SOUVENIRS table and inserts the souvenirs into the vector
            if(souvenirsQuery.exec("SELECT * FROM souvenirs WHERE College = '" + newCollege.name + "'"))
            {
                while(souvenirsQuery.next())
                {
                    SouvenirItem souvenir;
                    souvenir.name = souvenirsQuery.value(1).toString();  //Column2(ItemName) = souvenir item name
                    souvenir.price = souvenirsQuery.value(2).toDouble(); //Column3(Price) = souvenir item price

                    newCollege.souvenirs.push_back(souvenir);
                }
            }

            this->collegeMap.insert(newCollege.name,newCollege); // Push new college into program map
        }
    }
}

void DBColleges::saveColleges()
{
    QSqlQuery query(this->database);

    //Clears the entries in COLLEGES table first.
    query.exec("DELETE FROM colleges");

    for(auto iterator = this->collegeMap.cbegin(); iterator != this->collegeMap.cend(); iterator++)
    {
        query.exec("INSERT INTO colleges VALUES ( '" +
                   iterator->value.name + "', " +                       //Column1(College) = college name
                   " '" + iterator->value.state + "', " +               //Column2(State) = state name
                   QString::number(iterator->value.undergrads) + " )"); //Column3(Undergrads) = undergrad number
    }
}

void DBColleges::saveDistances()
{
    QSqlQuery query(this->database);

    //Clears the entries in DISTANCES table first.
    query.exec("DELETE FROM distances");

    for(auto iterator = this->collegeMap.cbegin(); iterator != this->collegeMap.cend(); iterator++)
    {
        for(auto iterator2 = iterator->value.distances.cbegin(); iterator2 != iterator->value.distances.cend(); iterator2++)
        {
            query.exec("INSERT INTO distances VALUES ( '" +
                       iterator->value.name + "', " +             //Column1(StartingCollege) = starting college name
                       " '" + iterator2->key + "', " +            //Column2(EndingCollege) = ending college name
                       QString::number(iterator2->value) + " )"); //Column3(Distance) = distance to ending college
        }
    }
}

void DBColleges::saveSouvenirs()
{
    QSqlQuery query(this->database);

    //Clears the entries in SOUVENIRS table first.
    query.exec("DELETE FROM souvenirs");

    for(auto iterator = this->collegeMap.cbegin(); iterator != this->collegeMap.cend(); iterator++)
    {
        for(int index = 0; index < iterator->value.souvenirs.size(); index++)
        {
            SouvenirItem souvenir = iterator->value.souvenirs[index];

            query.exec("INSERT INTO souvenirs VALUES ( '" +
                       iterator->value.name + "', " +           //Column1(College) = college name that the souvenir item belongs to
                       " '" + souvenir.name + "', " +           //Column2(ItemName) = souvenir item name
                       QString::number(souvenir.price) + " )"); //Column3(Price) = souvenir item price
        }
    }
}

void DBColleges::saveToDatabase()
{
    DBColleges::saveColleges();
    DBColleges::saveDistances();
    DBColleges::saveSouvenirs();
}
