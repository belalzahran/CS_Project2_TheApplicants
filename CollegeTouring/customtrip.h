#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QWidget>
#include "dbcolleges.h"

namespace Ui {
class customtrip;
}

/*! @class customTrip
 *  @extends public QWidget
 *
 */
class customtrip : public QWidget
{
    Q_OBJECT

public:
    /*! @fn explicit customtrip(QWidget *parent = nullptr)
     *  @param QWidget *parent = nullptr
     */
    explicit customtrip(QWidget *parent = nullptr);

    /*! @fn void fillComboBox(std::vector<College> exclude)
     *
     */
    void fillComboBox(std::vector<College> exclude);

    /*! @fn bool skipCollege (College current)
     *
     */
    bool skipCollege (College current);

    /*! @fn void setTable()
     *
     */
    void setTable();

    /*! @fn void updateTable()
     *
     */
    void updateTable();

    /*! @fn ~customtrip()
     *
     */
    ~customtrip();

private slots:
    /*! @fn void on_pushButton_addCollege_clicked()
     *
     */
    void on_pushButton_addCollege_clicked();

    /*! @fn void on_pushButton_return_clicked()
     *
     */
    void on_pushButton_return_clicked();

    /*! @fn void on_pushButton_clearTable_clicked()
     *
     */
    void on_pushButton_clearTable_clicked();

    /*! @fn void on_pushButton_start_clicked()
     *
     */
    void on_pushButton_start_clicked();

    /*! @fn void fillSouvenirCombo()
     *
     */
    void fillSouvenirCombo();

    /*! @fn void changeCollegeLabel()
     *
     */
    void changeCollegeLabel();

    /*! @fn void on_pushButton_next_clicked()
     *
     */
    void on_pushButton_next_clicked();

    /*! @fn void on_pushButton_confirm_clicked()
     *
     */
    void on_pushButton_confirm_clicked();
    //void prepSouveniersBoughtVector();
    /*! @fn void updateDistance()
     *
     */
    void updateDistance();

    /*! @fn void on_pushButton_addAll_clicked()
     *
     */
    void on_pushButton_addAll_clicked();

private:
    /*! @var Ui::customtrip *ui
     *
     */
    Ui::customtrip *ui;

    /*! @varstd::vector<College> selectedColleges
     *
     */
    std::vector<College> selectedColleges;

    /*! @var vector<float> amountSpentAtCollege
     *
     */
    vector<float> amountSpentAtCollege;

    /*! @var int collNum
     *
     */
    int collNum = 0;

    /*! @var float totalSpent
     *
     */
    float totalSpent = 0;

    /*! @var vector <vector <int>> souvenirsBought
     *
     */
    vector <vector <int>> souvenirsBought;


};

#endif // CUSTOMTRIP_H
