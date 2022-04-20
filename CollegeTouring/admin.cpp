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

    if (ui->lineEdit_price->text() == "" && ui->lineEdit_name->text() == "")
    {
        QMessageBox::warning(this, "New Souvenir Item","No name or price entered");

    }
    else if  (ui->lineEdit_price->text() == "" && ui->lineEdit_name->text() != "")
    {
        QMessageBox::warning(this, "New Souvenir Item","No price entered.");

    }
    else if  (ui->lineEdit_price->text() != "" && ui->lineEdit_name->text() == "")
    {
        QMessageBox::warning(this, "New Souvenir Item","No name entered");

    }
    else
    {
        SouvenirItem newItem(ui->lineEdit_price->text().toDouble(),ui->lineEdit_name->text());

       for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
       {
           if (iterator->value.name == selectedCollege.name)
               iterator->value.souvenirs.push_back(newItem);
       }

       ui->lineEdit_name->clear();
       ui->lineEdit_price->clear();

       fillCollegeSouvenirCombo(selectedCollege);
       QMessageBox::information(this, "New Souvenir Item","Succesfully added " + newItem.name + "!");


    }


}

// when the delete button is clicked


void admin::on_pushButton_2_clicked()
{

    QString selectedSouvenir;
    for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
    {
        if (iterator->value.name == selectedCollege.name)
        {
            for (int i = 0; i < iterator->value.souvenirs.size(); i++)
            {
                if (iterator->value.souvenirs.at(i).name == ui->comboBox_2->currentText())
                {
                    selectedSouvenir = selectedCollege.souvenirs.at(i).name;
                    iterator->value.souvenirs.erase(iterator->value.souvenirs.begin() + i);
                }

            }
        }
    }

    fillCollegeSouvenirCombo(selectedCollege);
    QMessageBox::information(this, "Delete Souvenir Item","Succesfully deleted " + selectedSouvenir + "!");


}

