#include "login.h"
#include "ui_login.h"
#include <QCryptographicHash>
#include <QDebug>
#include <QMessageBox>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QObject::connect(this->ui->buttonBox, SIGNAL(accepted()), this, SLOT(processLogin()));
        this->ui->entryPassword->setFocus();
}

login::~login()
{
    delete ui;
}


void login::processLogin()
{
       if (ui->entryPassword->text() == "1234567890")
       {
           this->accept();
       }
       else
       {
           QMessageBox::critical(this, "Incorrect Password", "The password entered is incorrect.");
       }
}
