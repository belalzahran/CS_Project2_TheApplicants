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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_edit3_clicked();

    void on_pushButton_3done_clicked();

    void on_pushButton_return3_clicked();

private:
    Ui::admin *ui;
    College selectedCollege;
    SouvenirItem selectedSouvenir;
};

#endif // ADMIN_H
