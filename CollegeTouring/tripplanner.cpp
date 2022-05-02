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

void TripPlanner::on_CustomTrippushButton_clicked()
{
    customtrip* custom = new customtrip;
    custom->setAttribute(Qt::WA_DeleteOnClose);
    custom->setWindowTitle("Plan Custom Trip");
    custom->show();
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
    DBColleges::getInstance().collegesGraph.minimumSpanningTree(0);
}


void TripPlanner::on_DFSpushButton_clicked()
{
    QString currentCollegeName = this->ui->college_comboBox->currentText();
    int collegeId = DBColleges::getInstance().collegesGraph.getIdFromName(currentCollegeName.toStdString());

    if(collegeId != -1)
    {
        DBColleges::getInstance().collegesGraph.PerformDFS(collegeId);
    }
    else
    {
        qDebug() << "TripPlanner::on_DFSpushButton_clicked Invalid college";
    }
}


void TripPlanner::on_BFSpushButton_clicked()
{

}

