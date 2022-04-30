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
    void on_pushButton_clear_clicked();

    void on_pushButton_clicked();
private:
    Ui::customtrip *ui;
    std::vector<College> selectedColleges;
};

#endif // CUSTOMTRIP_H
