#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qsystemdetection.h>
#include "framelesswindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public CFramelessWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
#ifdef Q_OS_MAC
private slots:
    void on_toggleClose_clicked();
    void on_toggleMin_clicked();
    void on_toggleZoom_clicked();
#endif
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
