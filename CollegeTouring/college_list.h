#ifndef COLLEGE_LIST_H
#define COLLEGE_LIST_H

#include <QWidget>

namespace Ui {
class CollegeList;
}

class CollegeList : public QWidget
{
    Q_OBJECT

public:
    explicit CollegeList(QWidget *parent = nullptr);
    ~CollegeList();

private:
    Ui::CollegeList *ui;
};

#endif // COLLEGE_LIST_H
