#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderedmap.h"
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

    OrderedMap<QString,int> map;

    //Testing insertions
    map.insert("California",18);
    map.insert("Oregon",20);
    map.insert("Washington",37);
    map.insert("Nevada",42);
    map.insert("Colorado",51);
    map.insert("Arizona",63);
    map.insert("Texas",77);
    map.insert("Hawaii",89);


    //Testing iterators
    for(auto iterator = map.begin(); iterator != map.end(); iterator++)
    {
        qDebug() << iterator->key << " | " << iterator->value;
    }

    //Testing Find with existing key
    qDebug() << "Find: " << (map.find("Texas") != nullptr);

    //Testing erasing and size
    qDebug() << map.size();
    map.erase("Texas");
    //Testing erasing and size with invalid key
    qDebug() << map.size();
    map.erase("Florida");
    qDebug() << map.size();

    //Testing find on invalid key
    qDebug() << "Find: " << (map.find("Texas") != nullptr);

    //Testing iterators
    for(auto iterator = map.begin(); iterator != map.end(); iterator++)
    {
        qDebug() << iterator->key << " | " << iterator->value;
    }

    //Testing clear
    map.clear();
    qDebug() << map.size();
    qDebug() << map.empty();

    //Testing subscript operator + insert to override an existing key
    map["Ohio"] = 33;
    map["Idaho"] = 23;
    map["Virginia"] = 55;
    map.insert("Virginia",18);

    //Testing .at
    qDebug() << map.at("Ohio");
    qDebug() << map.at("Idaho");
    qDebug() << map.at("Virginia");

    qDebug() << map.size();
    qDebug() << map.empty();

    if(map.contains("Texas"))
    {
        qDebug() << map.at("Texas");
    }

    if(map.contains("Virginia"))
    {
        qDebug() << map.at("Virginia");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

