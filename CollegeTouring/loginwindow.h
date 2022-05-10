#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QDialog>

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:
    void processLogin();

private:
#ifdef UI_TESTING
public:
#endif
    Ui::loginWindow *ui;
#ifdef UI_TESTING
private:
#endif
};

#endif // LOGIN_WINDOW_H
