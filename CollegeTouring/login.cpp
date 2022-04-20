#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "admin.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{

    password = ui->lineEdit->text();
    if (password == "")
    {
        admin* admin1 = new admin;
        admin1->setAttribute(Qt::WA_DeleteOnClose);
        admin1->setWindowTitle("Admistrative Login");
        admin1->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Incorrect Password","The password is incorrect, try again.");

    }
}

