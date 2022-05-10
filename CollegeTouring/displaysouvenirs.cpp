#include "displaysouvenirs.h"
#include "ui_displaysouvenirs.h"

displaySouvenirs::displaySouvenirs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displaySouvenirs)
{
    ui->setupUi(this);
    fillComboxBox();
}

displaySouvenirs::~displaySouvenirs()
{
    delete ui;
}


void displaySouvenirs::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->label->setText(arg1);

    setTable(arg1);
}


void displaySouvenirs::setTable(QString collegeName)
{
    College selectedCollege;

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // loop through the colleges to find the selected college
    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        if (iterator->value.name == collegeName)
        {
            selectedCollege = iterator->value;
        }

    }

    // clear the table from the last restaurant menu selction
        ui->tableWidget->clear();

       // table settings adjusted
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setFocusPolicy(Qt::NoFocus);
        ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

     // changing the font of the table title
        QFont font;
        font.setPointSize(12);
        ui->label->setFont(font);

     // setting the table row count
        ui->tableWidget->setRowCount(6);

        // settnig the width of the columns
        ui->tableWidget->setColumnWidth(0,200);
        ui->tableWidget->setColumnWidth(1,100);

        // adding the hearder labels and removing vertical number lables
        QStringList headerLabels;
        headerLabels.push_back("Item");
        headerLabels.push_back("Price ($)");
        ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

        ui->tableWidget->verticalHeader()->setVisible(false);


        // begin filling the table
        QString itemName;
        QString itemPrice;
        int existingSouvenirItems = 0;

        // finding out how many menu items are in a specific list for LCV variable
         existingSouvenirItems = selectedCollege.souvenirs.size();

        // loop through the table to set each item
         for (int row = 0; row < existingSouvenirItems; row++)

         {
             QTableWidgetItem *item;

             // reinitialize column to 0 for iteration
             int column = 0;
             while (column < 2)
             {

                 item = new QTableWidgetItem;

                 // if column == 0 set text to the item name
                 if (column == 0)
                 {
                     itemName = selectedCollege.souvenirs.at(row).name;
                     item->setText(itemName);
                 }
                 // if column == 1 set text to item price
                 else if (column == 1)
                 {
                      itemPrice = QString::number(selectedCollege.souvenirs.at(row).price);
                      item->setText("$"+itemPrice);
                 }

                 // adding some item settings and font
                 item->setTextAlignment(Qt::AlignCenter);


                 // establish item in table
                 ui->tableWidget->setItem(row, column, item);

                 // increment column
                 column++;
             }

         }


}


void displaySouvenirs::fillComboxBox()
{
    this->ui->comboBox->clear(); // clear this first so duplicates are not made

    for(auto iterator = DBColleges::getInstance().collegeMap.cbegin(); iterator != DBColleges::getInstance().collegeMap.cend(); iterator++)
    {
        ui->comboBox->addItem(iterator->value.name);

    }
}
