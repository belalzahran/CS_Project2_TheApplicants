#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

#include <QWidget>
#include "dbcolleges.h"

namespace Ui {
class TripPlanner;
}

/*! @class TripPlanner
 *  @extends public QWidget
 */
class TripPlanner : public QWidget
{
    Q_OBJECT

public:

    /*! @fn explicit TripPlanner(QWidget *parent = nullptr)
     *  @param QWidget *parent = nullptr
     */
    explicit TripPlanner(QWidget *parent = nullptr);

    /*! @fn ~TripPlanner()
     *
     */
    ~TripPlanner();

    /*! @fn void updateGraphComboBox()
     *
     */
    void updateGraphComboBox();

private slots:

    /*! @fn void on_MSTpushButton_clicked()
     *
     */
    void on_MSTpushButton_clicked();

private:

    /*! @var Ui::TripPlanner *ui
     *
     */
    Ui::TripPlanner *ui;
};

#endif // TRIPPLANNER_H
