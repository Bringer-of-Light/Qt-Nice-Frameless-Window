#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framelesswindow.h"
#include <QResizeEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public CFramelessWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_toggleClose_clicked();
    void on_toggleMin_clicked();
    void on_toggleZoom_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
