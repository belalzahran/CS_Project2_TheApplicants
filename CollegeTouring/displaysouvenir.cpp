#include "displaysouvenir.h"
#include "ui_displaysouvenir.h"

displaySouvenir::displaySouvenir(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displaySouvenir)
{
    ui->setupUi(this);
}

displaySouvenir::~displaySouvenir()
{
    delete ui;
}
