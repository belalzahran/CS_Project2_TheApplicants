#include "customtrip.h"
#include "ui_customtrip.h"
#include "dbcolleges.h"
#include <QMessageBox>

customtrip::customtrip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customtrip)
{
    ui->setupUi(this);
    fillComboBox(selectedColleges);
    setTable();
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

void customtrip::on_pushButton_clear_clicked()
{

    ui->tableWidget->clear();

    //QMessageBox::information(this,"asdf", "selected college size is " + QString::number(selectedColleges.size()));

    selectedColleges.clear();


    //QMessageBox::information(this,"asdf", "selected college size is " + QString::number(selectedColleges.size()));



    fillComboBox(selectedColleges);

}


void customtrip::on_pushButton_clicked()
{
    if (ui->comboBoxCollege->currentText().size() != 0)
    {
        //QMessageBox::information(this,"running", ui->comboBoxCollege->currentText());

        selectedColleges.push_back(getCollegeFromString(ui->comboBoxCollege->currentText()));
        updateTable();
        fillComboBox(selectedColleges);
    }

}




void customtrip::on_pushButton_4_clicked()
{
    this->close();
}


void customtrip::on_mostEfficientpushButton_clicked()
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
               //Replace with dijkstras for distances comparison
            if(newColleges[index].distances[currentCollegeName] < newColleges[0].distances[currentCollegeName])
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

    this->on_tripOrderpushButton_clicked();
}


void customtrip::on_tripOrderpushButton_clicked()
{
    double totalMileage = 0;

    for(unsigned int index = 0; index < this->selectedColleges.size() - 1; index++)
    {
                        //Replace this with djikstras
        totalMileage += this->selectedColleges[index].distances[this->selectedColleges[index + 1].name];
    }

    this->ui->distanceDisplaylineEdit->setText(QString::number(totalMileage) + " mi");
}

