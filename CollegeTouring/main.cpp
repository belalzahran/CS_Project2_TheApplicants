#include "mainwindow.h"
#include "dbcolleges.h"

#include <QApplication>

/*! @mainpage The Applicants
 *  This Program allows students to view colleges, their distances, and their souvenirs and plan trips to colleges.
 *  @authors Sierra Martin
 *  @authors Erik Nguyen
 *  @authors Brandon Bautista
 *  @authors Belal Zahran
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DBColleges::getInstance().loadFromDatabase(); //Try to load from the database first
    if(DBColleges::getInstance().collegeMap.empty()) //If the database is empty, run the loadfile function
    {
        qDebug() << "Prompting for Distances.csv file";
        DBColleges::getInstance().loadCollegeEntries(); //Be sure to select Distances.csv
        qDebug() << "Prompting for Souvenirs.csv file";
        DBColleges::getInstance().loadSouvenirEntries();//Be sure to select Souvenirs.csv

        DBColleges::getInstance().saveToDatabase();
    }
    DBColleges::getInstance().populateGraph(); //Populates the graph based on the collegeMap


    MainWindow w;
    w.show();
    return a.exec();
}
