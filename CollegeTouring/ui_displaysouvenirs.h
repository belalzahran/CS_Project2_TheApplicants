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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displaySouvenirs
{
public:
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QWidget *displaySouvenirs)
    {
        if (displaySouvenirs->objectName().isEmpty())
            displaySouvenirs->setObjectName(QString::fromUtf8("displaySouvenirs"));
        displaySouvenirs->resize(690, 447);
        comboBox = new QComboBox(displaySouvenirs);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 220, 171, 22));
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
        tableWidget->setGeometry(QRect(310, 110, 311, 211));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableWidget->setShowGrid(true);
        tableWidget->setRowCount(8);
        label = new QLabel(displaySouvenirs);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 70, 311, 31));
        label->setScaledContents(false);

        retranslateUi(displaySouvenirs);

        QMetaObject::connectSlotsByName(displaySouvenirs);
    } // setupUi

    void retranslateUi(QWidget *displaySouvenirs)
    {
        displaySouvenirs->setWindowTitle(QCoreApplication::translate("displaySouvenirs", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("displaySouvenirs", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("displaySouvenirs", "Price", nullptr));
        label->setText(QCoreApplication::translate("displaySouvenirs", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">College Name</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displaySouvenirs: public Ui_displaySouvenirs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYSOUVENIRS_H
