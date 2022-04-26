#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

#include <QWidget>

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

private:
    /*! @var Ui::TripPlanner *ui
     *
     */
    Ui::TripPlanner *ui;
};

#endif // TRIPPLANNER_H
