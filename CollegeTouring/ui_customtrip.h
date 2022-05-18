/********************************************************************************
** Form generated from reading UI file 'customtrip.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMTRIP_H
#define UI_CUSTOMTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customtrip
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QComboBox *comboBoxCollege;
    QLabel *label_2;
    QPushButton *pushButton_clearTable;
    QPushButton *pushButton_addCollege;
    QPushButton *pushButton_return;
    QSpinBox *spinBox;
    QPushButton *pushButton_next;
    QComboBox *comboBox_purchase;
    QLabel *label_collegeName;
    QPushButton *pushButton_confirm;
    QCheckBox *checkBox_2efficient;
    QPushButton *pushButton_start;
    QLabel *label_4_souvenir;
    QLabel *label_5_quantity;
    QLabel *label_distances;
    QPushButton *pushButton_addAll;

    void setupUi(QWidget *customtrip)
    {
        if (customtrip->objectName().isEmpty())
            customtrip->setObjectName(QString::fromUtf8("customtrip"));
        customtrip->resize(695, 495);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        customtrip->setPalette(palette);
        customtrip->setAutoFillBackground(false);
        label = new QLabel(customtrip);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 291, 31));
        tableWidget = new QTableWidget(customtrip);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 11)
            tableWidget->setRowCount(11);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 90, 271, 361));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->verticalHeader()->setVisible(false);
        comboBoxCollege = new QComboBox(customtrip);
        comboBoxCollege->setObjectName(QString::fromUtf8("comboBoxCollege"));
        comboBoxCollege->setGeometry(QRect(330, 100, 201, 22));
        label_2 = new QLabel(customtrip);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 401, 21));
        pushButton_clearTable = new QPushButton(customtrip);
        pushButton_clearTable->setObjectName(QString::fromUtf8("pushButton_clearTable"));
        pushButton_clearTable->setGeometry(QRect(330, 140, 81, 24));
        pushButton_addCollege = new QPushButton(customtrip);
        pushButton_addCollege->setObjectName(QString::fromUtf8("pushButton_addCollege"));
        pushButton_addCollege->setGeometry(QRect(420, 140, 75, 24));
        pushButton_return = new QPushButton(customtrip);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(590, 10, 91, 24));
        pushButton_return->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 111, 111);"));
        spinBox = new QSpinBox(customtrip);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(400, 360, 42, 22));
        pushButton_next = new QPushButton(customtrip);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(420, 400, 91, 24));
        comboBox_purchase = new QComboBox(customtrip);
        comboBox_purchase->setObjectName(QString::fromUtf8("comboBox_purchase"));
        comboBox_purchase->setGeometry(QRect(400, 330, 141, 22));
        label_collegeName = new QLabel(customtrip);
        label_collegeName->setObjectName(QString::fromUtf8("label_collegeName"));
        label_collegeName->setGeometry(QRect(340, 306, 241, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_collegeName->setFont(font);
        pushButton_confirm = new QPushButton(customtrip);
        pushButton_confirm->setObjectName(QString::fromUtf8("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(450, 360, 91, 24));
        pushButton_confirm->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(185, 255, 184);"));
        checkBox_2efficient = new QCheckBox(customtrip);
        checkBox_2efficient->setObjectName(QString::fromUtf8("checkBox_2efficient"));
        checkBox_2efficient->setGeometry(QRect(350, 230, 101, 20));
        pushButton_start = new QPushButton(customtrip);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(450, 230, 75, 24));
        label_4_souvenir = new QLabel(customtrip);
        label_4_souvenir->setObjectName(QString::fromUtf8("label_4_souvenir"));
        label_4_souvenir->setGeometry(QRect(340, 330, 49, 16));
        label_5_quantity = new QLabel(customtrip);
        label_5_quantity->setObjectName(QString::fromUtf8("label_5_quantity"));
        label_5_quantity->setGeometry(QRect(340, 360, 49, 16));
        label_distances = new QLabel(customtrip);
        label_distances->setObjectName(QString::fromUtf8("label_distances"));
        label_distances->setGeometry(QRect(340, 270, 211, 31));
        label_distances->setFont(font);
        pushButton_addAll = new QPushButton(customtrip);
        pushButton_addAll->setObjectName(QString::fromUtf8("pushButton_addAll"));
        pushButton_addAll->setGeometry(QRect(550, 100, 75, 24));
        pushButton_addAll->raise();
        label->raise();
        tableWidget->raise();
        comboBoxCollege->raise();
        label_2->raise();
        pushButton_clearTable->raise();
        pushButton_addCollege->raise();
        pushButton_return->raise();
        spinBox->raise();
        pushButton_next->raise();
        comboBox_purchase->raise();
        label_collegeName->raise();
        pushButton_confirm->raise();
        checkBox_2efficient->raise();
        pushButton_start->raise();
        label_4_souvenir->raise();
        label_5_quantity->raise();
        label_distances->raise();

        retranslateUi(customtrip);

        QMetaObject::connectSlotsByName(customtrip);
    } // setupUi

    void retranslateUi(QWidget *customtrip)
    {
        customtrip->setWindowTitle(QCoreApplication::translate("customtrip", "Form", nullptr));
        label->setText(QCoreApplication::translate("customtrip", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Custom Trip: Select Colleges</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("customtrip", "Colleges", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("customtrip", "New Row", nullptr));
        comboBoxCollege->setPlaceholderText(QCoreApplication::translate("customtrip", "Select College", nullptr));
        label_2->setText(QCoreApplication::translate("customtrip", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:696;\">Select the colleges you would like to visit:</span></p></body></html>", nullptr));
        pushButton_clearTable->setText(QCoreApplication::translate("customtrip", "Clear Table", nullptr));
        pushButton_addCollege->setText(QCoreApplication::translate("customtrip", "Add", nullptr));
        pushButton_return->setText(QCoreApplication::translate("customtrip", "Return", nullptr));
        pushButton_next->setText(QCoreApplication::translate("customtrip", "Next College", nullptr));
        label_collegeName->setText(QCoreApplication::translate("customtrip", "TextLabel", nullptr));
        pushButton_confirm->setText(QCoreApplication::translate("customtrip", "Confirm", nullptr));
        checkBox_2efficient->setText(QCoreApplication::translate("customtrip", "Most Efficient?", nullptr));
        pushButton_start->setText(QCoreApplication::translate("customtrip", "Start", nullptr));
        label_4_souvenir->setText(QCoreApplication::translate("customtrip", "Souvenir:", nullptr));
        label_5_quantity->setText(QCoreApplication::translate("customtrip", "Quantity:", nullptr));
        label_distances->setText(QString());
        pushButton_addAll->setText(QCoreApplication::translate("customtrip", "Add All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customtrip: public Ui_customtrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTRIP_H
