#include "college_list.h"
#include "ui_collegelist.h"

CollegeList::CollegeList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegeList)
{
    ui->setupUi(this);
}

CollegeList::~CollegeList()
{
    delete ui;
}
