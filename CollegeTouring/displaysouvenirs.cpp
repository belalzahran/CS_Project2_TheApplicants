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
    // code for filling in the table w souvenirs here



}

void displaySouvenirs::fillComboxBox()
{

    ui->comboBox->addItem("Arizona State University");
    ui->comboBox->addItem("Massachusetts Institute of Technology");
    ui->comboBox->addItem("Northwestern");
    ui->comboBox->addItem("Ohio State University");
    ui->comboBox->addItem("Saddleback College");
    ui->comboBox->addItem("University of Michigan");
    ui->comboBox->addItem("University of California, Irvine");
    ui->comboBox->addItem("University of California, Los Angeles");
    ui->comboBox->addItem("University of Oregon");
    ui->comboBox->addItem("University of Wisconsin");
    ui->comboBox->addItem("University of the Pacific");
    ui->comboBox->adjustSize();

}
