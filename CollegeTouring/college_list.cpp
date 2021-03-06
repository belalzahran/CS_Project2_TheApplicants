#include "college_list.h"
#include "ui_collegelist.h"
#include "dbcolleges.h"

CollegeList::CollegeList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegeList)
{
    ui->setupUi(this);
    this->updateCollegeList();
    this->sumUndergrads();
}

CollegeList::~CollegeList()
{
    delete ui;
}


void CollegeList::sumUndergrads(){
    int sum = 0;

    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        sum += iterator->value.undergrads;
    }

    QString total = QString::number(sum);
    this->ui->sumUndergrads->setText(total);
}


void CollegeList::displayColleges(SortType sort, const QString& stateName)
{
    QVector<College> displayedColleges;

    if(sort == ALPHABETICAL)
    {
        this->updateComboBox();
        this->updateCollegeComboBox();

        for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
        {
            displayedColleges.push_back(iterator->value);
        }
    }
    else if(sort == STATE)
    {
        this->updateComboBox();
        this->updateCollegeComboBox();

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
        this->updateCollegeComboBox();

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
        this->updateComboBox();
        this->updateCollegeComboBox();

        for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
        {
            if(iterator->value.distances.contains("Saddleback College"))
            {
                displayedColleges.push_back(iterator->value);
            }
        }
    }
    else if(sort == COLLEGE)
    {
        this->updateComboBox();
        displayedColleges.push_back(DBColleges::getInstance().collegeMap.at(stateName));
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


void CollegeList::updateCollegeComboBox()
{
    //Clear the combo box
    this->ui->comboBoxCollege->clear();

    //Inserts generic empty college and blocks signal (prevents currentIndexChanged)
    this->ui->comboBoxCollege->blockSignals(true);
    this->ui->comboBoxCollege->addItem(" - ");

    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        this->ui->comboBoxCollege->addItem(iterator->value.name, QVariant(iterator->value.name));
    }

    this->ui->comboBoxCollege->blockSignals(false); //unblocks signal
}


/*!
 * \brief CollegeList::updateCollegeList
 *
 * Will update the college display table with any new data.
 */
void CollegeList::updateCollegeList(){

    this->ui->collegeTable->clearContents(); // Clear anything we already have in the table
    this->displayColleges(); //Populates the table with the colleges currently in the map
    this->updateComboBox();  //Populates the combo box with the states of the colleges in the map
    this->updateCollegeComboBox(); //Populates the combo box with the colleges in the map
    this->sumUndergrads();     // Sums the total undergrads
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


void CollegeList::on_sortBySaddleback_clicked()
{
    this->displayColleges(SADDLEBACK);
}

void CollegeList::on_comboBoxCollege_currentIndexChanged(int index)
{
    if(index != -1 && index > 0) // Index returns -1 when there is a clear, index0 is an empty college
    {
        this->displayColleges(COLLEGE, this->ui->comboBoxCollege->itemData(index).toString());
    }
    else if(index == 0)
    {
        this->displayColleges(ALPHABETICAL);
    }
}

