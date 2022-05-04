#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QWidget>
#include "dbcolleges.h"

namespace Ui {
class customtrip;
}

class customtrip : public QWidget
{
    Q_OBJECT

public:
    explicit customtrip(QWidget *parent = nullptr);
    void fillComboBox(std::vector<College> exclude);
    bool skipCollege (College current);
    void setTable();
    void updateTable();
    ~customtrip();

private slots:
    void on_pushButton_addCollege_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_clearTable_clicked();

    void on_pushButton_start_clicked();
    void fillSouvenirCombo();
    void changeCollegeLabel();

    void on_pushButton_next_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::customtrip *ui;
    std::vector<College> selectedColleges;
    vector<float> amountSpentAtCollege;
    int collNum = 0;
    float totalSpent = 0;


};

#endif // CUSTOMTRIP_H
