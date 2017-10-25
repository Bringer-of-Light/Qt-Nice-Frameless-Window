#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    CFramelessWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setCloseBtnQuit(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#ifdef Q_OS_MAC
void MainWindow::on_toggleClose_clicked()
{
    setCloseBtnEnabled(!isCloseBtnEnabled());
}

void MainWindow::on_toggleMin_clicked()
{
    setMinBtnEnabled(!isMinBtnEnabled());
}

void MainWindow::on_toggleZoom_clicked()
{
    setZoomBtnEnabled(!isZoomBtnEnabled());
}
#endif

