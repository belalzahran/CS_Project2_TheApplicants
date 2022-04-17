#ifndef DBCOLLEGES_H
#define DBCOLLEGES_H
#include <QObject>
//#include <QSqlDatabase>
//#include <QSqlError>
#include <QString>
#include <QVector>
#include <QMutex>
#include <iostream>
#include <fstream>
#include <string>


struct SouvenirItem
{
    double price;
    QString name;
};

struct College
{
    QString name;
    QString state;
    int undergrads;

    // The way we will be storing these will make it so that each idx for endingCollege
    // will correspond to the idx of each distance
    // ex: endingColleges[0] will have a distance stored in distances[0]
    QVector<QString> endingColleges;    // list of destination colleges
    QVector<double> distances;          // list of destination distances

    QVector<SouvenirItem> souvenirs;    // list of souvenir items
};

/*!
 * This is the database that will manage the colleges. It will also handle
 * the loading and saving.
 *
 * It is a singleton, so it cannot be constructed manually. Instead, use the
 * \c DBColleges::getInstance() method to get a pointer to the current
 * instance.
 */
class DBColleges
{
private:

    QVector<std::string> line;          // This is the line that has been read in from readLine

public:
    // Make the constructor private so this is a singleton.
    DBColleges();
    ~DBColleges();
    QVector<College> collegeVector;     // list of colleges that are parsed in

    /*!
     * \brief readLine
     * \param file - csv file to be read into data
     * \param line - vector of strings to be read in from the file
     *
     * Will read a single line of
     */
    void readLine(std::istream& file, std::vector<std::string>& line);


    void readEntries(const std::string& path);


    void loadFileEntries();



};

#endif // DBCOLLEGES_H
