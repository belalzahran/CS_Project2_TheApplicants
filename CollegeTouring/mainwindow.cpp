#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HashMap.h"
#include <QString>
#include <QDebug>

//Custom hash object being passed into the map
struct QStringCustomHash
{
    int operator() (const QString &str) const
    {
        int finalHashValue = 0;
        for(int index = 0; index< str.length(); index++)
        {
            //Calculates hash value based on numeric representation
            //of the character multiplied by the index
            finalHashValue += str[index].toLatin1() * (index+1);
        }
        return finalHashValue;
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Testing hashmap
    //Type Param1: Key, TypeParam2: Value, TypeParam3: Hash
    HashMap<QString,double,QStringCustomHash> map;
    map.put("Saddleback",2.0);

    qDebug() << map["Saddleback"];

    //Testing subscript operator
    map["Oceanside"] = 15.5;
    map["Saddleback"] = 10.0;

    qDebug() << map["Oceanside"];
    qDebug() << map["Saddleback"];

    //Testing copy constructor
    HashMap<QString,double,QStringCustomHash> map2 = map;

    qDebug() << map2["Oceanside"];
    qDebug() << map2["Saddleback"];

    map2["Oceanside"] = 33.3;

    qDebug() << map["Oceanside"];
    qDebug() << map2["Oceanside"];

}

MainWindow::~MainWindow()
{
    delete ui;
}

