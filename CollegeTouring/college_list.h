#ifndef COLLEGE_LIST_H
#define COLLEGE_LIST_H

#include <QWidget>

enum SortType
{
    ALPHABETICAL,
    STATE
};

namespace Ui {
class CollegeList;

}

class CollegeList : public QWidget
{
    Q_OBJECT

public:
    explicit CollegeList(QWidget *parent = nullptr);
    ~CollegeList();

    void displayColleges(SortType sort = ALPHABETICAL);

private slots:
    void on_sortAlphabeticallyButton_clicked();

    void on_sortByStateButton_clicked();

private:
    Ui::CollegeList *ui;
};

#endif // COLLEGE_LIST_H
