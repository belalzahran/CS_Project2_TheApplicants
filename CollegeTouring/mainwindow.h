#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*! @class MainWindow
 *  @extends public QMainWindow
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*! @fn MainWindow(QWidget *parent = nullptr)
     *  @param QWidget *parent = nullptr
     */
    MainWindow(QWidget *parent = nullptr);

    /*! @fn ~MainWindow()
     *
     */
    ~MainWindow();

private slots:

    /*! @fn
     *
     */
    void on_pushButton_2_clicked();

private:

    /*! @var Ui::MainWindow *ui
     *
     */
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
