#include "mainwindow.h"
#include "dbcolleges.h"

#include <QApplication>

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
    }
    DBColleges::getInstance().populateGraph(); //Populates the graph based on the collegeMap

    //DBColleges::getInstance().collegesGraph.minimumSpanningTree(0);
    // DBColleges::getInstance().collegesGraph.graphDijkstras(4);
    DBColleges::getInstance().collegesGraph.PerformDFS(6);

    //MainWindow w;
   // w.show();
    return a.exec();
}
