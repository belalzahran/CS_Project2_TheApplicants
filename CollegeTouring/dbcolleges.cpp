#include "dbcolleges.h"
#include <algorithm>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextStream>
#include <fstream>

DBColleges::DBColleges(QString dbPath)
{

}


void DBColleges::readLine(std::istream& file, std::vector<std::string>& line)
{

}

void DBColleges::readEntries(const std::string& path)
{
    // Temp data to be used for reading from the csv file
    College newCollege;
    College endCollege;
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
    while (csvfile)
    {
        // as long as you don't close the file, the stream should know where it is
        this->readLine(csvfile, line);
    }
}

void DBColleges::loadFileEntries()
{
//    QString file = QFileDialog::getOpenFileName();
//    if (!file.trimmed().isEmpty())
//    {
//        try
//        {
//            DBColleges::readEntries(file);
//        }
//        catch (FileStructureError e)
//        {
//            QMessageBox::critical(this, "File Structure Error", QString("Error in file structure: ") + e.what());
//        }
//        catch (InvalidDataError e)
//        {
//            QMessageBox::critical(this, "Invalid Data", QString("Error in file data: ") + e.what());
//        }
//    }
}
