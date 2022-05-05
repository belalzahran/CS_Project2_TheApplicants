#ifndef PURCHASE_H
#define PURCHASE_H

#include <QWidget>
#include "customtrip.h"
#include "dbcolleges.h"

namespace Ui {
class purchase;
}

class purchase : public QWidget
{
    Q_OBJECT

public:
    explicit purchase(QWidget *parent = nullptr);
//    purchase()
//    {
//        selectedColleges = {bad};
//        collNum = 0;

//    };
//    purchase(vector<College> colleges)
//    {
//        selectedColleges = colleges;
//        collNum = 0;
//    }
    ~purchase();
    void fillCombo(int collNum);

private:
    Ui::purchase *ui;
    vector<College> selectedColleges;
    int collNum;
    //College bad;
};

#endif // PURCHASE_H
