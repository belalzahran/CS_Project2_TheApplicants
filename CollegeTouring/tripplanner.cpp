#include "tripplanner.h"
#include "ui_tripplanner.h"
#include <QMessageBox>

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
    double totalMileage = DBColleges::getInstance().collegesGraph.minimumSpanningTree(0);

    QMessageBox msgBox;
    msgBox.setText("Minimum Spanning Tree");
    msgBox.setInformativeText("Total Mileage: " + QString::number(totalMileage) + " miles");
    msgBox.exec();
}


void TripPlanner::on_DFSpushButton_clicked()
{
    QString currentCollegeName = this->ui->college_comboBox->currentText();
    int collegeId = DBColleges::getInstance().collegesGraph.getIdFromName(currentCollegeName.toStdString());

    if(collegeId != -1)
    {
        double totalMileage = DBColleges::getInstance().collegesGraph.PerformDFS(collegeId);

        QMessageBox msgBox;
        msgBox.setText("DFS starting from " + currentCollegeName);
        msgBox.setInformativeText("Total Mileage: " + QString::number(totalMileage) + " miles");
        msgBox.exec();
    }
    else
    {
        qDebug() << "TripPlanner::on_DFSpushButton_clicked Invalid college";
    }
}


void TripPlanner::on_BFSpushButton_clicked()
{

}

