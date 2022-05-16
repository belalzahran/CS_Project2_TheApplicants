#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    fillCollegeCombo();
    ui->doubleSpinBox->hide();
    ui->pushButton_3done->hide();

    // This will emit a signal that mainwindow can pick up when the addColleges button is
    // clicked.
    QObject::connect(this->ui->pushButton_addColleges, SIGNAL(clicked()),
                     this, SLOT(sendUpdateColleges()));

    // This will emit a signal that mainwindow can pick up when the addSouvenirs button is
    // clicked.
    QObject::connect(this->ui->pushButton_addSouvenirs, SIGNAL(clicked()),
                     this, SLOT(sendUpdateSouvenirs()));
}

admin::~admin()
{
    delete ui;
}


void admin::sendUpdateColleges(){

    DBColleges::getInstance().loadNewColleges();
    this->fillCollegeCombo();
    emit this->updateCollegesClicked();
}

void admin::sendUpdateSouvenirs(){
    DBColleges::getInstance().loadNewSouvenirs();
    emit this->updateSouvenirsClicked();
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
     ui->doubleSpinBox->hide();
     ui->pushButton_3done->hide();
}


void admin::on_pushButton_edit3_clicked()
{

    for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
    {
        if (iterator->value.name == selectedCollege.name)
        {
            for (int i = 0; i < iterator->value.souvenirs.size(); i++)
            {
                if (iterator->value.souvenirs.at(i).name == ui->comboBox_2->currentText())
                {
                    selectedSouvenir = iterator->value.souvenirs.at(i);
                }

            }
        }
    }

    ui->doubleSpinBox->show();
    ui->pushButton_3done->show();
    ui->doubleSpinBox->setValue(selectedSouvenir.price);
}

void admin::on_pushButton_3done_clicked()
{

    SouvenirItem newS;
    newS.name = selectedSouvenir.name;
    newS.price = ui->doubleSpinBox->value();
    for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
    {
        if (iterator->value.name == selectedCollege.name)
        {
            for (int i = 0; i < iterator->value.souvenirs.size(); i++)
            {
                if (iterator->value.souvenirs.at(i).name == ui->comboBox_2->currentText())
                {
                    iterator->value.souvenirs.erase(iterator->value.souvenirs.begin() + i);
                }

            }

            iterator->value.souvenirs.push_back(newS);
        }
    }

    ui->doubleSpinBox->hide();
    ui->pushButton_3done->hide();
    QMessageBox::information(this, "Change Souvenir Price","Succesfully changed " + ui->comboBox_2->currentText() + " price to $" + QString::number(ui->doubleSpinBox->value()));

    DBColleges::getInstance().saveSouvenirs();
}


void admin::on_pushButton_addSouvenir_clicked()
{

    if (ui->doubleSpinBox_2->value() == 0 && ui->lineEdit_name->text() == "")
    {
        QMessageBox::warning(this, "New Souvenir Item","No name or price entered");

    }
    else if  (ui->doubleSpinBox_2->value() == 0 && ui->lineEdit_name->text() != "")
    {
        QMessageBox::warning(this, "New Souvenir Item","No price entered.");

    }
    else if  (ui->doubleSpinBox_2->value() != 0 && ui->lineEdit_name->text() == "")
    {
        QMessageBox::warning(this, "New Souvenir Item","No name entered");

    }
    else
    {
        SouvenirItem newItem(ui->doubleSpinBox_2->value(),ui->lineEdit_name->text());

       for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
       {
           if (iterator->value.name == selectedCollege.name)
               iterator->value.souvenirs.push_back(newItem);
       }

       ui->lineEdit_name->clear();
       ui->doubleSpinBox_2->clear();

       on_comboBox_currentTextChanged(ui->comboBox->currentText());

       QMessageBox::information(this, "New Souvenir Item","Succesfully added " + newItem.name + "!");

       DBColleges::getInstance().saveSouvenirs();


    }

}


void admin::on_pushButton_deleteSouvenir_clicked()
{
    for(auto iterator = DBColleges::getInstance().collegeMap.begin(); iterator != DBColleges::getInstance().collegeMap.end(); iterator++)
    {
        if (iterator->value.name == selectedCollege.name)
        {
            for (int i = 0; i < iterator->value.souvenirs.size(); i++)
            {
                if (iterator->value.souvenirs.at(i).name == ui->comboBox_2->currentText())
                {
                    selectedSouvenir = iterator->value.souvenirs.at(i);
                    iterator->value.souvenirs.erase(iterator->value.souvenirs.begin() + i);
                }

            }
        }
    }


    on_comboBox_currentTextChanged(ui->comboBox->currentText());
    QMessageBox::information(this, "Delete Souvenir Item","Succesfully deleted " + selectedSouvenir.name + "!");

    DBColleges::getInstance().saveSouvenirs();

    ui->doubleSpinBox->hide();
    ui->pushButton_3done->hide();
}

