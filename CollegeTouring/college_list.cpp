#include "college_list.h"
#include "ui_collegelist.h"
#include "dbcolleges.h"

CollegeList::CollegeList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegeList)
{
    ui->setupUi(this);


    //QObject::connect(this->ui->loadEntriesButton, SIGNAL(clicked()), this, SLOT(onCellDoubleClicked(int, int)));


    //This process only needs to be run once when the program first starts.
    if(DBColleges::getInstance().collegeMap.empty())
    {
        DBColleges::getInstance().loadFromDatabase(); //Try to load from the database first
        if(DBColleges::getInstance().collegeMap.empty()) //If the database is empty, run the loadfile function
        {
            DBColleges::getInstance().loadFileEntries();
        }
    }

    this->displayColleges();

}

CollegeList::~CollegeList()
{
    delete ui;
}

void CollegeList::displayColleges(SortType sort)
{
    QVector<College> displayedColleges;

    if(sort == ALPHABETICAL)
    {
        for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
        {
            displayedColleges.push_back(iterator->value);
        }
    }
    else if(sort == STATE)
    {
        OrderedMap<QString,College> stateSorting;

        //Inserts colleges into another ordered map with the states as part of the key in order to sort it.
        for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
        {
            stateSorting.insert(QString(iterator->value.state).replace(" ", "") + iterator->value.name, iterator->value);
        }

        for(auto iterator = stateSorting.begin(); iterator != stateSorting.end(); iterator++)
        {
            displayedColleges.push_back(iterator->value);
        }
    }

    //Makes sure table is empty
    this->ui->collegeTable->clear();

    // Resize the table so we have the correct number of rows.
    this->ui->collegeTable->setColumnCount(3);
    this->ui->collegeTable->setHorizontalHeaderItem(0, new QTableWidgetItem("College"));
    this->ui->collegeTable->setHorizontalHeaderItem(1, new QTableWidgetItem("State"));
    this->ui->collegeTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Undergrads"));
    this->ui->collegeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->ui->collegeTable->setRowCount(DBColleges::getInstance().collegeMap.size());

    for(int index = 0; index < displayedColleges.size(); index++)
    {
        // setItem(row (i), column, data)
        this->ui->collegeTable->setItem(index, 0, new QTableWidgetItem(displayedColleges.at(index).name));
        this->ui->collegeTable->setItem(index, 1, new QTableWidgetItem(displayedColleges.at(index).state));
        this->ui->collegeTable->setItem(index, 2, new QTableWidgetItem(QString::number(displayedColleges.at(index).undergrads)));

    }
}

void CollegeList::on_sortAlphabeticallyButton_clicked()
{
    this->displayColleges(ALPHABETICAL);
}


void CollegeList::on_sortByStateButton_clicked()
{
    this->displayColleges(STATE);
}

