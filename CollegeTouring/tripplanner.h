#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

#include <QWidget>
#include "customtrip.h"
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
     *  Performs an MST on the colleges and displays the total mileage.
     */
    void on_MSTpushButton_clicked();

    /*! @fn void on_CustomTrippushButton_clicked()
     *
     */
    void on_CustomTrippushButton_clicked();

    /*! @fn void on_DFSpushButton_clicked()
     *  Performs a DFS on the graph using the specified college in the combobox
     *  and displays the total mileage.
     */
    void on_DFSpushButton_clicked();

    /*! @fn void on_BFSpushButton_clicked()
     *  Performs a BFS on the graph using the specified college in the combobox
     *  and displays the total mileage.
     */
    void on_BFSpushButton_clicked();

public slots:
    /*! @fn void updateComboBox()
     *  Updates the combobox with the colleges in DBColleges.
     */
    void updateComboBox();

private:

    /*! @var Ui::TripPlanner *ui
     *
     */
    Ui::TripPlanner *ui;
};

#endif // TRIPPLANNER_H
