/********************************************************************************
** Form generated from reading UI file 'displaysouvenirs.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYSOUVENIRS_H
#define UI_DISPLAYSOUVENIRS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displaySouvenirs
{
public:
    QPushButton *pushButton;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QWidget *displaySouvenirs)
    {
        if (displaySouvenirs->objectName().isEmpty())
            displaySouvenirs->setObjectName(QString::fromUtf8("displaySouvenirs"));
        displaySouvenirs->resize(579, 414);
        pushButton = new QPushButton(displaySouvenirs);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 240, 75, 24));
        comboBox = new QComboBox(displaySouvenirs);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 200, 171, 22));
        tableWidget = new QTableWidget(displaySouvenirs);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(290, 100, 231, 281));
        tableWidget->setShowGrid(true);
        tableWidget->setRowCount(8);
        label = new QLabel(displaySouvenirs);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 70, 211, 20));

        retranslateUi(displaySouvenirs);

        QMetaObject::connectSlotsByName(displaySouvenirs);
    } // setupUi

    void retranslateUi(QWidget *displaySouvenirs)
    {
        displaySouvenirs->setWindowTitle(QCoreApplication::translate("displaySouvenirs", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("displaySouvenirs", "Click Me", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("displaySouvenirs", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("displaySouvenirs", "Price", nullptr));
        label->setText(QCoreApplication::translate("displaySouvenirs", "<html><head/><body><p><span style=\" font-size:11pt;\">College Name</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displaySouvenirs: public Ui_displaySouvenirs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYSOUVENIRS_H
