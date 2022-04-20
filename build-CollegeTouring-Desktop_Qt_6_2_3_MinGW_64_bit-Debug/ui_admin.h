/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QLabel *label;

    void setupUi(QWidget *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QString::fromUtf8("admin"));
        admin->resize(400, 300);
        label = new QLabel(admin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 141, 31));

        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QWidget *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "Form", nullptr));
        label->setText(QCoreApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Admin Settings</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
