#ifndef DISPLAYSOUVENIR_H
#define DISPLAYSOUVENIR_H

#include <QWidget>

namespace Ui {
class displaySouvenir;
}

class displaySouvenir : public QWidget
{
    Q_OBJECT

public:
    explicit displaySouvenir(QWidget *parent = nullptr);
    ~displaySouvenir();

private:
    Ui::displaySouvenir *ui;
};

#endif // DISPLAYSOUVENIR_H
