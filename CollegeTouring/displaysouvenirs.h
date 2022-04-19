#ifndef DISPLAYSOUVENIRS_H
#define DISPLAYSOUVENIRS_H

#include <QWidget>
#include "dbcolleges.h"

namespace Ui {
class displaySouvenirs;
}

class displaySouvenirs : public QWidget
{
    Q_OBJECT

public:
    explicit displaySouvenirs(QWidget *parent = nullptr);
    ~displaySouvenirs();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);
    void fillComboxBox();
    void setTable(QString collegeName);

private:
    Ui::displaySouvenirs *ui;
};

#endif // DISPLAYSOUVENIRS_H
