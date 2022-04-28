#include "tripplanner.h"
#include "ui_tripplanner.h"

TripPlanner::TripPlanner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripPlanner)
{
    ui->setupUi(this);
    this->updateGraphComboBox();
}

TripPlanner::~TripPlanner()
{
    delete ui;
}

void TripPlanner::updateGraphComboBox()
{
    //Clear the combo box
    this->ui->college_comboBox->clear();

    //Inserts the unique states into the combo box
    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        this->ui->college_comboBox->addItem(iterator->value.name);
    }
}

void TripPlanner::on_MSTpushButton_clicked()
{
    QString currentCollegeName = this->ui->college_comboBox->currentText();
    qDebug() << currentCollegeName;

    //TODO: External window opens up displaying the results of the MST.
}

