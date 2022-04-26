#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "dbcolleges.h"

namespace Ui {



class admin;
}

/*! @class admin
 *  @extends public QWidget
 *
 */
class admin : public QWidget
{
    Q_OBJECT

public:
    /*! @fn explicit admin(QWidget *parent = nullptr)
     *  @param QWidget *parent = nullptr
     *
     */
    explicit admin(QWidget *parent = nullptr);

    /*! @fn ~admin()
     *
     */
    ~admin();


private slots:
    /*! @fn void fillCollegeCombo()
     *
     */
    void fillCollegeCombo();

    /*! @fn void fillCollegeSouvenirCombo(College selectedCollege)
     *  @param College selectedCollege
     *
     */
    void fillCollegeSouvenirCombo(College selectedCollege);

    /*! @fn void on_comboBox_currentTextChanged(const QString &arg1)
     *  @param const QString &arg1
     */
    void on_comboBox_currentTextChanged(const QString &arg1);

    /*! @fn
     *
     */
    void on_pushButton_clicked();

private:
    /*! @var Ui::admin *ui
     *
     */
    Ui::admin *ui;

    /*! @var College selectedCollege
     *
     */
    College selectedCollege;
};

#endif // ADMIN_H
