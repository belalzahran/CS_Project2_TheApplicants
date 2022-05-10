#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbcolleges.h"
#include <iomanip>
#include "admin.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "login.h"
#include "displaysouvenirs.h"
#include "college_list.h"
#include "tripplanner.h"
#include "displaysouvenir.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(4,false);
    QObject::connect(this->ui->pushButton_2, SIGNAL(clicked()),
                     this, SLOT(adminClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::adminClicked()
{

    login win;
    if (win.exec())
    {
        ui->tabWidget->setCurrentIndex(4);
        ui->tabWidget->setTabEnabled(4,true);

        // Update college list with new Colleges
        QObject::connect(this->ui->adminTab, SIGNAL(updateCollegesClicked()),
                         this->ui->collegeList, SLOT(updateCollegeList()));

        // Update list in souvenirs to reflect changes
        QObject::connect(this->ui->adminTab, SIGNAL(updateCollegesClicked()),
                         this->ui->souvenirList, SLOT(fillComboxBox()));

    }
    else
    {

    }

}



