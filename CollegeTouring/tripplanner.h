#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

#include <QWidget>

namespace Ui {
class TripPlanner;
}

class TripPlanner : public QWidget
{
    Q_OBJECT

public:
    explicit TripPlanner(QWidget *parent = nullptr);
    ~TripPlanner();

private:
    Ui::TripPlanner *ui;
};

#endif // TRIPPLANNER_H
