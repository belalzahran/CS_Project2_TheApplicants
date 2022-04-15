#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OrderedMap.h"
#include <QString>
#include <QDebug>

//Custom comparator class being passed into the map
struct QStringComparator
{
    bool operator() (const QString &lstr, const QString &rstr) const
    {
        return lstr < rstr;
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Testing orderedmap
    OrderedMap<QString,int> map;

    map["Saddleback"] = 15;
    map["Oceanside"] = 11;
    map["Sacremento"] = 28;
    map["Riverside"] = 44;
    map["Riverside"] = 99;

    qDebug() << map["Saddleback"];
    qDebug() << map["Oceanside"];
    qDebug() << map["Sacremento"];
    qDebug() << map["Riverside"];

    qDebug() << "Testing copy constructor";
    OrderedMap<QString,int> map2 = map;

    qDebug() << map2["Saddleback"];
    qDebug() << map2["Oceanside"];
    qDebug() << map2["Sacremento"];
    qDebug() << map2["Riverside"];
    qDebug() << "===";
    map["Riverside"] = 19;

    qDebug() << map["Riverside"];
    qDebug() << map2["Riverside"];

}

MainWindow::~MainWindow()
{
    delete ui;
}

