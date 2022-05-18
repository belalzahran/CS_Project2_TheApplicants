#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QDialog>
namespace Ui {
class login;
}

/*! @class login
 *  @extends public QWidget
 */
class login : public QDialog
{
    Q_OBJECT

public:

    /*! @fn explicit login(QWidget *parent = nullptr)
     *  @param QWidget *parent = nullptr
     */
    explicit login(QWidget *parent = nullptr);

    /*! @fn ~login()
     *
     */
    ~login();

private slots:

    /*! @fn void processLogin()
     *
     */
    void processLogin();

private:

    /*! @var Ui::login *ui
     *
     */
    Ui::login *ui;

};

#endif // LOGIN_H
