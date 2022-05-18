/********************************************************************************
** Form generated from reading UI file 'tripplanner.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPLANNER_H
#define UI_TRIPPLANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripPlanner
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *CustomTrippushButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *college_comboBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *DFSpushButton;
    QPushButton *BFSpushButton;
    QPushButton *MSTpushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *TripPlanner)
    {
        if (TripPlanner->objectName().isEmpty())
            TripPlanner->setObjectName(QString::fromUtf8("TripPlanner"));
        TripPlanner->resize(600, 400);
        TripPlanner->setMinimumSize(QSize(600, 400));
        verticalLayout = new QVBoxLayout(TripPlanner);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(TripPlanner);
        label->setObjectName(QString::fromUtf8("label"));
        label->setScaledContents(false);
        label->setWordWrap(false);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(TripPlanner);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        CustomTrippushButton = new QPushButton(groupBox_2);
        CustomTrippushButton->setObjectName(QString::fromUtf8("CustomTrippushButton"));

        horizontalLayout_3->addWidget(CustomTrippushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        groupBox = new QGroupBox(TripPlanner);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAutoFillBackground(false);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        college_comboBox = new QComboBox(groupBox);
        college_comboBox->setObjectName(QString::fromUtf8("college_comboBox"));

        horizontalLayout_2->addWidget(college_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        DFSpushButton = new QPushButton(groupBox);
        DFSpushButton->setObjectName(QString::fromUtf8("DFSpushButton"));

        horizontalLayout->addWidget(DFSpushButton);

        BFSpushButton = new QPushButton(groupBox);
        BFSpushButton->setObjectName(QString::fromUtf8("BFSpushButton"));

        horizontalLayout->addWidget(BFSpushButton);

        MSTpushButton = new QPushButton(groupBox);
        MSTpushButton->setObjectName(QString::fromUtf8("MSTpushButton"));

        horizontalLayout->addWidget(MSTpushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(TripPlanner);

        QMetaObject::connectSlotsByName(TripPlanner);
    } // setupUi

    void retranslateUi(QWidget *TripPlanner)
    {
        TripPlanner->setWindowTitle(QCoreApplication::translate("TripPlanner", "Form", nullptr));
        label->setText(QCoreApplication::translate("TripPlanner", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; text-decoration: underline;\">Trip Planner</span></p></body></html>", nullptr));
        groupBox_2->setTitle(QString());
        CustomTrippushButton->setText(QCoreApplication::translate("TripPlanner", "Custom Trip", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QCoreApplication::translate("TripPlanner", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; text-decoration: underline;\">Graph Related Operations</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("TripPlanner", "Starting College", nullptr));
        DFSpushButton->setText(QCoreApplication::translate("TripPlanner", "DFS", nullptr));
        BFSpushButton->setText(QCoreApplication::translate("TripPlanner", "BFS", nullptr));
        MSTpushButton->setText(QCoreApplication::translate("TripPlanner", "MST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripPlanner: public Ui_TripPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPLANNER_H
