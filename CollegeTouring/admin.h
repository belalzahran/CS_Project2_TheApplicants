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

    /*! @fn void fillCollegeSouvenirCombo(College selectedCollege)
     *  @param College selectedCollege
     *
     */
    void fillCollegeSouvenirCombo(College selectedCollege);

    /*! @fn void on_comboBox_currentTextChanged(const QString &arg1)
     *  @param const QString &arg1
     */
    void on_comboBox_currentTextChanged(const QString &arg1);

    // Prompts the user to select an input file for new colleges to add,
    // sends signal to be picked up by mainwindow to update collegeList and other tabs.
    void sendUpdateColleges();


    // Prompts the user to select an input file for new souvenirs to add,
    // sends signal to be picked up by mainwindow to update collegeList and other tabs.
    void sendUpdateSouvenirs();

    /*! @fn
     *
     */

    void on_pushButton_edit3_clicked();

    void on_pushButton_3done_clicked();

    void on_pushButton_addSouvenir_clicked();

    void on_pushButton_deleteSouvenir_clicked();

public slots:
    /*! @fn void fillCollegeCombo()
     *
     */
    void fillCollegeCombo();

signals:
    void updateCollegesClicked();
    void updateSouvenirsClicked();

private:

    /*! @var Ui::admin *ui
     *
     */
    Ui::admin *ui;

    /*! @var College selectedCollege
     *
     */
    College selectedCollege;
    SouvenirItem selectedSouvenir;
};

#endif // ADMIN_H
