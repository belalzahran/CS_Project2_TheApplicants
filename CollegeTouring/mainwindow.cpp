#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbcolleges.h"
#include <iomanip>
#include "admin.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "login.h"
#include "displaysouvenirs.h"
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
    ui->tabWidget->setCurrentIndex(0);


    //Returns the college struct with the key Arizona State University
    //DBColleges::getInstance().collegeMap.at("Arizona State University");


    //Iterates through collegeMap. It can be obtained with DBColleges::getInstance().collegeMap
    //for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
    //{
    //    //qDebug() << iterator->value.name; //Value is the college struct.
    //}


    //Returns distance from Arizona State University to Northwestern
    //DBColleges::getInstance().collegeMap.at("Arizona State University").distances.at("Northwestern");


    //DBColleges::readSouvenirs(path);


    //These functions save the data stored in collegeMap into the database.
    //DBColleges::getInstance().saveColleges();
    //DBColleges::getInstance().saveDistances();
    //DBColleges::getInstance().saveSouvenirs();

    //printColleges(db.collegeVector);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_2_clicked()
{
    login* login1 = new login;
    login1->setAttribute(Qt::WA_DeleteOnClose);
    login1->setWindowTitle("Admistrative Login");
    login1->show();

}


