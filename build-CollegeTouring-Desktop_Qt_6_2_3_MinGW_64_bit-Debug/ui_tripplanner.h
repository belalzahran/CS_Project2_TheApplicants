/********************************************************************************
** Form generated from reading UI file 'tripplanner.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPLANNER_H
#define UI_TRIPPLANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripPlanner
{
public:
    QLabel *label;

    void setupUi(QWidget *TripPlanner)
    {
        if (TripPlanner->objectName().isEmpty())
            TripPlanner->setObjectName(QString::fromUtf8("TripPlanner"));
        TripPlanner->resize(400, 300);
        label = new QLabel(TripPlanner);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 131, 31));

        retranslateUi(TripPlanner);

        QMetaObject::connectSlotsByName(TripPlanner);
    } // setupUi

    void retranslateUi(QWidget *TripPlanner)
    {
        TripPlanner->setWindowTitle(QCoreApplication::translate("TripPlanner", "Form", nullptr));
        label->setText(QCoreApplication::translate("TripPlanner", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Trip Planner</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripPlanner: public Ui_TripPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPLANNER_H
