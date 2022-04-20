#include "college_list.h"
#include "ui_collegelist.h"
#include "dbcolleges.h"

CollegeList::CollegeList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegeList)
{
    ui->setupUi(this);


    //QObject::connect(this->ui->loadEntriesButton, SIGNAL(clicked()), this, SLOT(onCellDoubleClicked(int, int)));

    this->displayColleges(); //Populates the table with the colleges currently in the map
    this->updateComboBox();  //Populates the combo box with the states of the colleges in the map

}

CollegeList::~CollegeList()
{
    delete ui;
}

void CollegeList::displayColleges(SortType sort, const QString& stateName)
{
    QVector<College> displayedColleges;

    if(sort == ALPHABETICAL)
    {
        this->updateComboBox();

        for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
        {
            displayedColleges.push_back(iterator->value);
        }
    }
    else if(sort == STATE)
    {
        this->updateComboBox();

        OrderedMap<QString,College> stateSorting;

        //Inserts colleges into another ordered map with the states as part of the key in order to sort it.
        for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
        {
            stateSorting.insert(QString(iterator->value.state).replace(" ", "") + iterator->value.name, iterator->value);
        }

        for(auto iterator = stateSorting.cbegin(); iterator != stateSorting.cend(); iterator++)
        {
            displayedColleges.push_back(iterator->value);
        }
    }
    else if(sort == SPECIFIC)
    {
        //Only populate the vector with the colleges that share the same state as the specified parameter
        for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
        {
            if(stateName == QString(iterator->value.state).replace(" ", ""))
            {
                displayedColleges.push_back(iterator->value);
            }
        }
    }
    else if(sort == SADDLEBACK)
    {
        for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
        {
            if(iterator->value.distances.contains("Saddleback College"))
            {
                displayedColleges.push_back(iterator->value);
            }
        }
    }

    //Makes sure table is empty
    this->ui->collegeTable->clear();

    // Resize the table so we have the correct number of rows.
    if(sort == SADDLEBACK)
    {
        this->ui->collegeTable->setColumnCount(4);
    }
    else
    {
        this->ui->collegeTable->setColumnCount(3);
    }

    this->ui->collegeTable->setHorizontalHeaderItem(0, new QTableWidgetItem("College"));
    this->ui->collegeTable->setHorizontalHeaderItem(1, new QTableWidgetItem("State"));
    this->ui->collegeTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Undergrads"));
    if(sort == SADDLEBACK)
    {
        this->ui->collegeTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Distance"));
    }

    this->ui->collegeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->ui->collegeTable->setRowCount(displayedColleges.size());

    for(int index = 0; index < displayedColleges.size(); index++)
    {
        //row & column indicies start at 0
        this->ui->collegeTable->setItem(index, 0, new QTableWidgetItem(displayedColleges.at(index).name));
        this->ui->collegeTable->setItem(index, 1, new QTableWidgetItem(displayedColleges.at(index).state));
        this->ui->collegeTable->setItem(index, 2, new QTableWidgetItem(QString::number(displayedColleges.at(index).undergrads)));
        if(sort == SADDLEBACK)
        {
            this->ui->collegeTable->setItem(index, 3, new QTableWidgetItem(QString::number(displayedColleges.at(index).distances.at("Saddleback College"))));
        }
    }
}

void CollegeList::updateComboBox()
{
    //Clear the combo box
    this->ui->comboBoxState->clear();

    //Inserts generic empty state and blocks signal (prevents currentIndexChanged)
    this->ui->comboBoxState->blockSignals(true);
    this->ui->comboBoxState->addItem(" - ");

    QVector<QString> states;

    //Inserts unique states into a vector
    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        if(!states.contains(QString(iterator->value.state).replace(" ", "")))
        {
            states.push_back(QString(iterator->value.state).replace(" ", ""));
        }
    }

    //Inserts the unique states into the combo box
    for(const QString& currentState : states)
    {
        this->ui->comboBoxState->addItem(currentState, QVariant(currentState));
    }

    this->ui->comboBoxState->blockSignals(false); //unblocks signal
}

void CollegeList::on_sortAlphabeticallyButton_clicked()
{
    this->displayColleges(ALPHABETICAL);
}


void CollegeList::on_sortByStateButton_clicked()
{
    this->displayColleges(STATE);
}


void CollegeList::on_comboBoxState_currentIndexChanged(int index)
{
    if(index != -1 && index > 0) // Index returns -1 when there is a clear, index0 is an empty state
    {
        this->displayColleges(SPECIFIC, this->ui->comboBoxState->itemData(index).toString());
    }
    else if(index == 0)
    {
        this->displayColleges(ALPHABETICAL);
    }
}


void CollegeList::on_pushButton_clicked()
{
    this->displayColleges(SADDLEBACK);
}
