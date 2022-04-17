#include "college_list.h"
#include "ui_collegelist.h"

CollegeList::CollegeList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegeList)
{
    ui->setupUi(this);


//QObject::connect(this->ui->loadEntriesButton, SIGNAL(clicked()), this, SLOT(onCellDoubleClicked(int, int)));
}

CollegeList::~CollegeList()
{
    delete ui;
}

//void CollegeList::updateColleges(QString databaseName)
//{
//    //Makes sure table is empty
//    this->ui->restList->clearContents();
//    // Get a reference to the list of colleges FROM DATABASE.
//    // code to do this

//    // Resize the table so we have the correct number of rows.
//    this->ui->collegeTable->setRowCount(this->.length());

//    for(qsizetype i = 0; i < restList.length(); i++)
//    {
//        // setItem(row (i), column, data)
//        this->ui->restList->setItem(i, 0, new QTableWidgetItem(restList[i].name));
//        this->ui->restList->setItem(i, 1, new QTableWidgetItem(QString::number(restList[i].milesFromCollege, 'f', 2)));
//        this->ui->restList->setItem(i, 2, new QTableWidgetItem(QVariant(restList[i].menuItems.length()).toString()));
//    }
//}
