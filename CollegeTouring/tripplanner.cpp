#include "tripplanner.h"
#include "ui_tripplanner.h"
#include "customtrip.h"

TripPlanner::TripPlanner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripPlanner)
{
    ui->setupUi(this);
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

