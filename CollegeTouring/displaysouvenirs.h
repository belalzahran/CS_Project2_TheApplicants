#ifndef DISPLAYSOUVENIRS_H
#define DISPLAYSOUVENIRS_H

#include <QWidget>
#include "dbcolleges.h"

namespace Ui {
class displaySouvenirs;
}

/*! @class displaySouvenirs
 *  @extends public QWidget
 */
class displaySouvenirs : public QWidget
{
    Q_OBJECT

public:
    /*! @fn explicit displaySouvenirs(QWidget *parent = nullptr)
     *  @param QWidget *parent = nullptr
     */
    explicit displaySouvenirs(QWidget *parent = nullptr);

    /*! @fn ~displaySouvenirs(
     *
     */
    ~displaySouvenirs();

private slots:
    /*! @fn void on_comboBox_currentTextChanged(const QString &arg1)
     *  @param const QString &arg1
     */
    void on_comboBox_currentTextChanged(const QString &arg1);

    /*! @fn void fillComboxBox()
     *
     */
    void fillComboxBox();

    /*! @fn void setTable(QString collegeName)
     *  @param QString collegeName
     */
    void setTable(QString collegeName);

private:
    /*! @var Ui::displaySouvenirs *ui
     *
     */
    Ui::displaySouvenirs *ui;
};

#endif // DISPLAYSOUVENIRS_H
