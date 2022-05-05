#include "customtrip.h"
#include "ui_customtrip.h"
#include "dbcolleges.h"
#include "purchase.h"
#include "graph.h"
#include <QMessageBox>



// add select all button


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

    selectedColleges.clear();

    fillComboBox(selectedColleges);

    ui->spinBox->hide();
    ui->comboBox_purchase->hide();
    ui->pushButton_confirm->hide();
    ui->pushButton_next->hide();
    ui->label_collegeName->hide();
    ui->label_4_souvenir->hide();
    ui->label_5_quantity->hide();
    ui->label_distances->hide();
    ui->checkBox_2efficient->setChecked(false);
    ui->checkBoxuserOrder->setChecked(false);



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
            amountSpentAtCollege.push_back(0);
            ui->label_distances->show();




            if (ui->checkBoxuserOrder->isChecked())
            {
                fillSouvenirCombo();
                changeCollegeLabel();
                this->updateDistance();
            }
            if (ui->checkBox_2efficient->isChecked())
            {
                std::vector<College> newColleges = this->selectedColleges;
                   QString currentCollegeName = newColleges[0].name;
                   this->selectedColleges.clear();

                   //Searches for optimial route from the initial college
                   while(!newColleges.empty())
                   {
                       //Switches index0 to closest college to the current.
                       for(unsigned int index = 1; index < newColleges.size(); index++)
                       {
                           double currentDist = DBColleges::getInstance().collegesGraph.sierrasDijkstras(
                                       DBColleges::getInstance().collegesGraph.getIdFromName(currentCollegeName.toStdString()),
                                       DBColleges::getInstance().collegesGraph.getIdFromName(newColleges[index].name.toStdString())
                                       );
                           double bestDist = DBColleges::getInstance().collegesGraph.sierrasDijkstras(
                                       DBColleges::getInstance().collegesGraph.getIdFromName(currentCollegeName.toStdString()),
                                       DBColleges::getInstance().collegesGraph.getIdFromName(newColleges[0].name.toStdString())
                                        );
                           if(currentDist < bestDist)
                           {
                               //Swap index with 0
                               College prev = newColleges[index];
                               newColleges[index] = newColleges[0];
                               newColleges[0] = prev;
                           }
                       }

                       //Switch current college the closest one, and push it to the selectedColleges vector
                       //Repeats until every college has been added back to the visitedColleges vector
                       currentCollegeName = newColleges[0].name;
                       this->selectedColleges.push_back(newColleges[0]);
                       newColleges.erase(newColleges.begin());
                   }

                   updateTable();
                   fillComboBox(this->selectedColleges);
                   fillSouvenirCombo();
                   changeCollegeLabel();

                   this->updateDistance();

            }
        }



    }
    else
    {
        QMessageBox::warning(this,"Error","Please check one box!");
    }

}

void customtrip::updateDistance()
{
    double totalMileage = 0;

        for(unsigned int index = 0; index < this->selectedColleges.size() - 1; index++)
        {
            totalMileage += DBColleges::getInstance().collegesGraph.sierrasDijkstras(
                            DBColleges::getInstance().collegesGraph.getIdFromName(this->selectedColleges[index].name.toStdString()),
                            DBColleges::getInstance().collegesGraph.getIdFromName(this->selectedColleges[index + 1].name.toStdString())
                            );
        }
        this->ui->label_distances->setText("Total Trip Distance: " + QString::number(totalMileage)+ " miles");
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

    if (collNum + 1 < selectedColleges.size())
    {
        collNum++;
        amountSpentAtCollege.push_back(0);
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
        amountSpentAtCollege.at(collNum) += (selectedColleges.at(collNum).souvenirs.at(ui->comboBox_purchase->currentIndex()).price * ui->spinBox->value());
        QMessageBox::information(this, "Purchased", ui->spinBox->text() + " " + ui->comboBox_purchase->currentText() + "s purchased!");
        ui->spinBox->setValue(0);

    }
}


void customtrip::on_pushButton_addAll_clicked()
{

    if (ui->comboBoxCollege->count() > 0)
    {
        for (int i = 0; i < ui->comboBoxCollege->count(); i++)
        {
            selectedColleges.push_back(getCollegeFromString(ui->comboBoxCollege->itemText(i)));
        }

        updateTable();
        fillComboBox(selectedColleges);
    }
    else
    {
        QMessageBox::warning(this,"Error","There are no more colleges left to add!");
    }


}

