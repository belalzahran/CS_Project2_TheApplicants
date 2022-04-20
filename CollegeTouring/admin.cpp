#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    fillCollegeCombo();
}

admin::~admin()
{
    delete ui;
}


void admin::fillCollegeCombo()
{

    ui->comboBox->clear();

    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        ui->comboBox->addItem(iterator->value.name);

    }

}

void admin::fillCollegeSouvenirCombo(College selectedCollege)
{
        ui->comboBox_2->clear();

    for (int i = 0; i < selectedCollege.souvenirs.size(); i++)
        ui->comboBox_2->addItem(selectedCollege.souvenirs.at(i).name);

}


void admin::on_comboBox_currentTextChanged(const QString &arg1)
{
    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        if (iterator->value.name == arg1)
            selectedCollege = iterator->value;
    }

     fillCollegeSouvenirCombo(selectedCollege);
}

