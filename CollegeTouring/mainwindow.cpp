#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbcolleges.h"
#include <iomanip>

//void printColleges(QVector<College>& collegeVector)
//{
//    for (int i = 0; i < collegeVector.size(); i++)
//    {
//        qDebug() << "Item " << i+1 << "Name:" << collegeVector.at(i).name << "\n";
//        qDebug() << "Undergrads: " << collegeVector.at(i).undergrads << "\n";
//        qDebug() << "State: " << collegeVector.at(i).state << "\n";

//        qDebug() << "Ending Colleges:\n";

//        // Print out ending colleges and their corresponding distances
//        for (int j = 0; j < collegeVector.at(i).endingColleges.size(); j++)
//        {
//            qDebug() << collegeVector.at(i).endingColleges.at(j) << " Distance: " << collegeVector.at(i).distances.at(j) << "\n";
//        }

//        qDebug() << "\n ==================================\n";
//    }
//}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // change the path to where you store the .csv file (currently included in project)
    std::string path = "D:/source/repos/Qt_Projects/MAIN_CollegeTouring/CS_Project2_TheApplicants/CollegeTouring/Distances.csv";
    // test parser
    DBColleges db;
    db.readEntries(path);
    //printColleges(db.collegeVector);

}

MainWindow::~MainWindow()
{
    delete ui;

}

