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

// fill the combobox w colleges
void admin::fillCollegeCombo()
{

    ui->comboBox->clear();

    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        ui->comboBox->addItem(iterator->value.name);

    }

}

// fill the souvenir combo box with the respective items
void admin::fillCollegeSouvenirCombo(College selectedCollege)
{
        ui->comboBox_2->clear();

    for (int i = 0; i < selectedCollege.souvenirs.size(); i++)
        ui->comboBox_2->addItem(selectedCollege.souvenirs.at(i).name);

}


// when the college selected changes
void admin::on_comboBox_currentTextChanged(const QString &arg1)
{
    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        if (iterator->value.name == arg1)
            selectedCollege = iterator->value;
    }

     fillCollegeSouvenirCombo(selectedCollege);
}


// when add button is clicked
void admin::on_pushButton_clicked()
{
//    SouvenirItem newItem(ui->lineEdit_price->text().toDouble(),ui->lineEdit_name->text());

//    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
//    {
//        if (iterator->value.name == selectedCollege.name)
//            iterator->value.souvenirs.
//    }



}

// when the delete button is clicked
void admin::on_pushButton_2_clicked()
{

}

