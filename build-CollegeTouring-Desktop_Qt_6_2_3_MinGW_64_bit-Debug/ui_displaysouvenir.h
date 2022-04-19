/********************************************************************************
** Form generated from reading UI file 'displaysouvenir.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYSOUVENIR_H
#define UI_DISPLAYSOUVENIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displaysouvenir
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *displaysouvenir)
    {
        if (displaysouvenir->objectName().isEmpty())
            displaysouvenir->setObjectName(QString::fromUtf8("displaysouvenir"));
        displaysouvenir->resize(453, 324);
        pushButton = new QPushButton(displaysouvenir);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 140, 75, 24));
        pushButton_2 = new QPushButton(displaysouvenir);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 220, 75, 24));

        retranslateUi(displaysouvenir);

        QMetaObject::connectSlotsByName(displaysouvenir);
    } // setupUi

    void retranslateUi(QWidget *displaysouvenir)
    {
        displaysouvenir->setWindowTitle(QCoreApplication::translate("displaysouvenir", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("displaysouvenir", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("displaysouvenir", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displaysouvenir: public Ui_displaysouvenir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYSOUVENIR_H
