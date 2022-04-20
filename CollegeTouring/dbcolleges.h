#ifndef DBCOLLEGES_H
#define DBCOLLEGES_H
#include <QObject>
#include <QSqlDatabase>
//#include <QSqlError>
#include <QString>
#include <QVector>
#include <QMutex>
#include <iostream>
#include <fstream>
#include <string>
#include "orderedmap.h"


struct SouvenirItem
{
    double price;
    QString name;

//    SouvenirItem(double price, QString name)
//    {
//        this->price = price;
//        this->name = name;
//    }
};

struct College
{
    QString name;
    QString state;
    int undergrads;

    //The key is the ending college name, and the value is the actual distance
    OrderedMap<QString,double> distances;

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

    // Make the constructor private so this is a singleton.
    DBColleges();

    //Should the destructor also be placed in private so that we won't have unwanted destruction?
    ~DBColleges();

    //QVector<std::string> line;          // This is the line that has been read in from readLine

    QSqlDatabase database; // Will be set during construction

public:

    //Deletes these operations to not allow the user to use them.
    DBColleges(const DBColleges&) = delete;
    DBColleges(DBColleges&&) = delete;
    DBColleges& operator=(const DBColleges&) = delete;
    DBColleges& operator=(DBColleges&&) = delete;

    //I am unsure whether or not the instance should be a static object or pointer, but for now its returning a reference
    static DBColleges& getInstance()
    {
        static DBColleges instance;
        return instance;
    }

    OrderedMap<QString,College> collegeMap;     // list of colleges that are parsed in


    /*!
     * \brief readLine
     * \param file - csv file to be read into data
     * \param line - vector of strings to be read in from the file
     *
     * Will read a single line of
     */
    void readLine(std::istream& file, std::vector<std::string>& line);


    void readEntries(const std::string& path);


    void readSouvenirs(const std::string& path);


    void loadSouvenirEntries();
    void loadCollegeEntries();


    /*!
     * \brief loadFromDatabase
     *
     * Will load data from the sqlite database into collegeMap
     */
    void loadFromDatabase();

    /*!
     * \brief saveColleges
     *
     * Saves college information from collegeMap into the sqlite database
     */
    void saveColleges();

    /*!
     * \brief saveDistances
     *
     * Saves distances information from collegeMap into the sqlite database
     */
    void saveDistances();

    /*!
     * \brief saveSouvenirs
     *
     * Saves souvenir information from collegeMap into the sqlite database
     */
    void saveSouvenirs();

    /*!
     * \brief saveSouvenirs
     *
     * Saves all data from the collegeMap to the sqlite database
     */
    void saveToDatabase();

};

#endif // DBCOLLEGES_H
