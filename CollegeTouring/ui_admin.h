/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_addSouvenir;
    QComboBox *comboBox;
    QPushButton *pushButton_deleteSouvenir;
    QComboBox *comboBox_2;
    QPushButton *pushButton_edit3;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton_3done;
    QDoubleSpinBox *doubleSpinBox_2;
    QWidget *tab_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_addColleges;
    QPushButton *pushButton_addSouvenirs;

    void setupUi(QWidget *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QString::fromUtf8("admin"));
        admin->resize(623, 470);
        label = new QLabel(admin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 141, 31));
        tabWidget = new QTabWidget(admin);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 50, 581, 401));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lineEdit_name = new QLineEdit(tab);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(130, 110, 113, 22));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 351, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 110, 71, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 150, 49, 16));
        pushButton_addSouvenir = new QPushButton(tab);
        pushButton_addSouvenir->setObjectName(QString::fromUtf8("pushButton_addSouvenir"));
        pushButton_addSouvenir->setGeometry(QRect(270, 110, 81, 31));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(380, 20, 151, 22));
        pushButton_deleteSouvenir = new QPushButton(tab);
        pushButton_deleteSouvenir->setObjectName(QString::fromUtf8("pushButton_deleteSouvenir"));
        pushButton_deleteSouvenir->setGeometry(QRect(130, 290, 75, 31));
        comboBox_2 = new QComboBox(tab);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(130, 250, 161, 31));
        pushButton_edit3 = new QPushButton(tab);
        pushButton_edit3->setObjectName(QString::fromUtf8("pushButton_edit3"));
        pushButton_edit3->setGeometry(QRect(210, 290, 81, 31));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 60, 141, 31));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 190, 241, 31));
        doubleSpinBox = new QDoubleSpinBox(tab);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(330, 250, 62, 22));
        doubleSpinBox->setMaximum(1000.000000000000000);
        pushButton_3done = new QPushButton(tab);
        pushButton_3done->setObjectName(QString::fromUtf8("pushButton_3done"));
        pushButton_3done->setGeometry(QRect(400, 250, 71, 24));
        pushButton_3done->setAutoFillBackground(false);
        doubleSpinBox_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(130, 150, 62, 22));
        doubleSpinBox_2->setMaximum(1000.000000000000000);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(110, 60, 371, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_addColleges = new QPushButton(gridLayoutWidget);
        pushButton_addColleges->setObjectName(QString::fromUtf8("pushButton_addColleges"));

        gridLayout->addWidget(pushButton_addColleges, 0, 0, 1, 1);

        pushButton_addSouvenirs = new QPushButton(gridLayoutWidget);
        pushButton_addSouvenirs->setObjectName(QString::fromUtf8("pushButton_addSouvenirs"));

        gridLayout->addWidget(pushButton_addSouvenirs, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(admin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QWidget *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "Form", nullptr));
        label->setText(QCoreApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Admin Settings</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Select the college you would like to manage:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("admin", "Item Name: ", nullptr));
        label_4->setText(QCoreApplication::translate("admin", "Price: ", nullptr));
        pushButton_addSouvenir->setText(QCoreApplication::translate("admin", "Add", nullptr));
        pushButton_deleteSouvenir->setText(QCoreApplication::translate("admin", "Delete", nullptr));
        pushButton_edit3->setText(QCoreApplication::translate("admin", "Edit Price", nullptr));
        label_5->setText(QCoreApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Add a new Item:</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">...or manage existing inventory:</span></p></body></html>", nullptr));
        pushButton_3done->setText(QCoreApplication::translate("admin", "Done", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("admin", "Manage Souvenirs", nullptr));
        pushButton_addColleges->setText(QCoreApplication::translate("admin", "Upload New Colleges from File", nullptr));
        pushButton_addSouvenirs->setText(QCoreApplication::translate("admin", "Upload New Souvenirs from File", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("admin", "Upload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
