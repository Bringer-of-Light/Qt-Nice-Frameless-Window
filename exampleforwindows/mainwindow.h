#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framelesswindow.h"
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public CFramelessWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_btnMin_clicked();
    void on_btnMax_clicked();
    void on_btnClose_clicked();
    void on_bthFull_clicked();
    void on_btnIncreaseMargin_clicked();
    void on_btnDecreaseMargin_clicked();
    void on_btnResizeable_clicked();

    void on_btnSubWindow_clicked();

private:
    QString currentMargins();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
