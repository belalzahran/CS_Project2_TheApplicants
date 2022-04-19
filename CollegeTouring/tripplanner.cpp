#include "tripplanner.h"
#include "ui_tripplanner.h"

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
