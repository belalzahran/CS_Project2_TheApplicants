#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "dbcolleges.h"

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();


private slots:
    void fillCollegeCombo();
    void fillCollegeSouvenirCombo(College selectedCollege);

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::admin *ui;
    College selectedCollege;
};

#endif // ADMIN_H
