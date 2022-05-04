#include "customtrip.h"
#include "ui_customtrip.h"
#include "dbcolleges.h"
#include "purchase.h"
#include <QMessageBox>

customtrip::customtrip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customtrip)
{
    ui->setupUi(this);
    fillComboBox(selectedColleges);
    setTable();
    ui->spinBox->hide();
    ui->comboBox_purchase->hide();
    ui->pushButton_confirm->hide();
    ui->pushButton_next->hide();
    ui->label_collegeName->hide();
    ui->label_4_souvenir->hide();
    ui->label_5_quantity->hide();
}

customtrip::~customtrip()
{
    delete ui;
}



void customtrip::setTable()
{
    ui->tableWidget->setColumnWidth(0,250);

    QStringList headerLabels;
    headerLabels.push_back("Colleges");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
}


bool customtrip::skipCollege (College current)
{

    // if college current is not in vector return false
    for (int i = 0; i < selectedColleges.size(); i++)
    {
        if(selectedColleges.at(i).name == current.name)
        {
            return true;
        }
    }
    return false;

}

void customtrip::fillComboBox(std::vector<College> exclude)
{
    ui->comboBoxCollege->clear();
    QStringList headerLabels;
    headerLabels.push_back("Colleges");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        if (!skipCollege(iterator->value))
            ui->comboBoxCollege->addItem(iterator->value.name);
    }

}


College getCollegeFromString(QString name)
{
    College result;
    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        if(iterator->value.name == name)
            result = iterator->value;
    }

    return result;
}

void customtrip::updateTable()
{

    ui->tableWidget->clear();
    QStringList headerLabels;
    headerLabels.push_back("Colleges");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    int existingItems = selectedColleges.size();
    for (int row = 0; row < existingItems; row++)
    {
         QTableWidgetItem *item;

         item = new QTableWidgetItem;

         item->setText(selectedColleges.at(row).name);

         // adding some item settings and font
         item->setTextAlignment(Qt::AlignCenter);
         // establish item in table
         ui->tableWidget->setItem(row, 0, item);
    }

}

void customtrip::on_pushButton_addCollege_clicked()
{
    if (ui->comboBoxCollege->currentText().size() != 0)
    {
        //QMessageBox::information(this,"running", ui->comboBoxCollege->currentText());

        selectedColleges.push_back(getCollegeFromString(ui->comboBoxCollege->currentText()));
        updateTable();
        fillComboBox(selectedColleges);
    }

}


void customtrip::on_pushButton_return_clicked()
{
    this->close();
}




void customtrip::on_pushButton_clearTable_clicked()
{
    ui->tableWidget->clear();

    //QMessageBox::information(this,"asdf", "selected college size is " + QString::number(selectedColleges.size()));

    selectedColleges.clear();


    //QMessageBox::information(this,"asdf", "selected college size is " + QString::number(selectedColleges.size()));



    fillComboBox(selectedColleges);
}


void customtrip::on_pushButton_start_clicked()
{
    if (ui->checkBoxuserOrder->isChecked() || ui->checkBox_2efficient->isChecked())
    {

        if(ui->checkBoxuserOrder->isChecked() && ui->checkBox_2efficient->isChecked())
        {
            QMessageBox::warning(this,"Error","Please uncheck one box!");

        }
        else
        {

            ui->spinBox->show();
            ui->comboBox_purchase->show();
            ui->pushButton_confirm->show();
            ui->pushButton_next->show();
            ui->label_collegeName->show();
            ui->label_4_souvenir->show();
            ui->label_5_quantity->show();


            if (ui->checkBoxuserOrder->isChecked())
            {
                fillSouvenirCombo();
                changeCollegeLabel();
            }
            if (ui->checkBox_2efficient)
            {

            }
        }


    }
    else
    {
        QMessageBox::warning(this,"Error","Please check one box!");
    }

}


void customtrip::changeCollegeLabel()
{
    ui->label_collegeName->setText(selectedColleges.at(collNum).name);
}

void customtrip::fillSouvenirCombo()
{
    ui->comboBox_purchase->clear();

    for (int i = 0; i < selectedColleges.at(collNum).souvenirs.size(); i++)
    {
        ui->comboBox_purchase->addItem(selectedColleges.at(collNum).souvenirs.at(i).name);
    }

}


void customtrip::on_pushButton_next_clicked()
{
    QString receipt;
     if (amountSpentAtCollege.size() < collNum + 1)
         amountSpentAtCollege.push_back(0);

    if (collNum + 1 < selectedColleges.size())
    {
        collNum++;
        fillSouvenirCombo();
        changeCollegeLabel();
    }
    else
    {
        for (int i = 0; i < amountSpentAtCollege.size(); i++)
        {
            totalSpent += amountSpentAtCollege.at(i);
            if (amountSpentAtCollege.at(i) != 0)
                receipt += selectedColleges.at(i).name + "....$" + QString::number(amountSpentAtCollege.at(i)) + "\n";
        }
        receipt += "Total Spent: $" + QString::number(totalSpent) + "\n";

        QMessageBox::information(this,"Receipt", receipt);
        this->close();
    }
}


void customtrip::on_pushButton_confirm_clicked()
{
    if (ui->spinBox->value() > 0)
    {
        amountSpentAtCollege.push_back(selectedColleges.at(collNum).souvenirs.at(ui->comboBox_purchase->currentIndex()).price * ui->spinBox->value());
        ui->spinBox->setValue(0);
        QMessageBox::information(this, "Purchased", ui->spinBox->text() + " " + ui->comboBox_purchase->currentText() + "s purchased!");
    }
}

