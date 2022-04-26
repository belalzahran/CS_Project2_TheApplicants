#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
namespace Ui {
class login;
}



/*! @class login
 *  @extends public QWidget
 */
class login : public QWidget
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
    /*! @fn
     *
     */
    void on_pushButton_clicked();

private:
    /*! @var Ui::login *ui
     *
     */
    Ui::login *ui;

    /*! @var QString password
     *
     */
    QString password;
};

#endif // LOGIN_H
