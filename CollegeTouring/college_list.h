#ifndef COLLEGE_LIST_H
#define COLLEGE_LIST_H

#include <QWidget>


/*! @enum SortType
 *  @var ALPHABETICAL
 *  @var STATE
 *  @var SPECIFIC
 *  @var SADDLEBACK
 *  this enum exists outside the scope of the class
 */
enum SortType
{
    ALPHABETICAL,
    STATE,
    SPECIFIC,
    SADDLEBACK
};

namespace Ui {
class CollegeList;

}

/*! @class CollegeList
 *  @extends public QWidget
 *
 */
class CollegeList : public QWidget
{
    Q_OBJECT

public:

    /*! @fn explicit CollegeList(QWidget *parent = nullptr)
     *  @param QWidget *parent = nullptr
     */
    explicit CollegeList(QWidget *parent = nullptr);
    ~CollegeList();

    /*! @fn void displayColleges(SortType sort = ALPHABETICAL, const QString& stateName = "California")
     *  @param SortType sort = ALPHABETICAL
     *  @param const QString& stateName = "California"
     *
     */
    void displayColleges(SortType sort = ALPHABETICAL, const QString& stateName = "California");

    /*! @fn void updateComboBox()
     * Updates the combo box with all unique states.
     */
    void updateComboBox();

private slots:

    /*! @fn void on_sortAlphabeticallyButton_clicked()
     * Sorts the contents of the table alphabetically
     */
    void on_sortAlphabeticallyButton_clicked();

    /*! @fn void on_sortByStateButton_clicked()
     * Sorts the contents of the table by state
     */
    void on_sortByStateButton_clicked();

    /*! @fn void on_comboBoxState_currentIndexChanged(int index)
     *  @param int index
     */
    void on_comboBoxState_currentIndexChanged(int index);

    /*! @fn void on_sortBySaddleback_clicked()
     *  Displays the distance to saddleback from each college.
     */
    void on_sortBySaddleback_clicked();


public slots:
    // Will clear the current table, load values from DB and reload all values
    // into the table.
    void updateCollegeList();
private:

    /*! @var Ui::CollegeList *ui
     *
     */
    Ui::CollegeList *ui;
};

#endif // COLLEGE_LIST_H
