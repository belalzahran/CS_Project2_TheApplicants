#include "mainwindow.h"
#include "dbcolleges.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DBColleges::getInstance().loadFromDatabase(); //Try to load from the database first
    if(DBColleges::getInstance().collegeMap.empty()) //If the database is empty, run the loadfile function
    {
        DBColleges::getInstance().loadCollegeEntries(); //Be sure to select Distances.csv
        DBColleges::getInstance().loadSouvenirEntries();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
