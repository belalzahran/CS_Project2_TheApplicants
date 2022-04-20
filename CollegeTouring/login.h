#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    QString password;
};

#endif // LOGIN_H
