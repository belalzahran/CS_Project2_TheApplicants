/********************************************************************************
** Form generated from reading UI file 'collegelist.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLEGELIST_H
#define UI_COLLEGELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollegeList
{
public:
    QGridLayout *gridLayout;
    QTableWidget *collegeTable;
    QVBoxLayout *verticalLayout;
    QPushButton *sortAlphabeticallyButton;
    QPushButton *sortByStateButton;
    QPushButton *sortBySaddleback;
    QLabel *totalUnderGradsLabel;
    QLabel *sumUndergrads;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QComboBox *comboBoxCollege;
    QLabel *label;
    QComboBox *comboBoxState;

    void setupUi(QWidget *CollegeList)
    {
        if (CollegeList->objectName().isEmpty())
            CollegeList->setObjectName(QString::fromUtf8("CollegeList"));
        CollegeList->resize(654, 509);
        gridLayout = new QGridLayout(CollegeList);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        collegeTable = new QTableWidget(CollegeList);
        if (collegeTable->columnCount() < 3)
            collegeTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        collegeTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        collegeTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        collegeTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        collegeTable->setObjectName(QString::fromUtf8("collegeTable"));

        gridLayout->addWidget(collegeTable, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sortAlphabeticallyButton = new QPushButton(CollegeList);
        sortAlphabeticallyButton->setObjectName(QString::fromUtf8("sortAlphabeticallyButton"));

        verticalLayout->addWidget(sortAlphabeticallyButton);

        sortByStateButton = new QPushButton(CollegeList);
        sortByStateButton->setObjectName(QString::fromUtf8("sortByStateButton"));

        verticalLayout->addWidget(sortByStateButton);

        sortBySaddleback = new QPushButton(CollegeList);
        sortBySaddleback->setObjectName(QString::fromUtf8("sortBySaddleback"));

        verticalLayout->addWidget(sortBySaddleback);

        totalUnderGradsLabel = new QLabel(CollegeList);
        totalUnderGradsLabel->setObjectName(QString::fromUtf8("totalUnderGradsLabel"));
        totalUnderGradsLabel->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(totalUnderGradsLabel);

        sumUndergrads = new QLabel(CollegeList);
        sumUndergrads->setObjectName(QString::fromUtf8("sumUndergrads"));
        sumUndergrads->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));

        verticalLayout->addWidget(sumUndergrads);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(CollegeList);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        comboBoxCollege = new QComboBox(CollegeList);
        comboBoxCollege->setObjectName(QString::fromUtf8("comboBoxCollege"));

        verticalLayout->addWidget(comboBoxCollege);

        label = new QLabel(CollegeList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        comboBoxState = new QComboBox(CollegeList);
        comboBoxState->setObjectName(QString::fromUtf8("comboBoxState"));

        verticalLayout->addWidget(comboBoxState);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);


        retranslateUi(CollegeList);

        QMetaObject::connectSlotsByName(CollegeList);
    } // setupUi

    void retranslateUi(QWidget *CollegeList)
    {
        CollegeList->setWindowTitle(QCoreApplication::translate("CollegeList", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = collegeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CollegeList", "College Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = collegeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CollegeList", "State", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = collegeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CollegeList", "Undergrads", nullptr));
        sortAlphabeticallyButton->setText(QCoreApplication::translate("CollegeList", "Alphabetical Order", nullptr));
        sortByStateButton->setText(QCoreApplication::translate("CollegeList", "Sort by State", nullptr));
        sortBySaddleback->setText(QCoreApplication::translate("CollegeList", "Saddleback Only", nullptr));
        totalUnderGradsLabel->setText(QCoreApplication::translate("CollegeList", "Total Undergrads: ", nullptr));
        sumUndergrads->setText(QString());
        label_2->setText(QCoreApplication::translate("CollegeList", "Specific College", nullptr));
        label->setText(QCoreApplication::translate("CollegeList", "Specific State", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollegeList: public Ui_CollegeList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLEGELIST_H
