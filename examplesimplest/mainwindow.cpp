#include "qsystemdetection.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    CFramelessWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#ifdef Q_OS_WIN
    setTitleBar(ui->titlebar);
#elif defined Q_OS_MAC
    setDraggableAreaHeight(ui->titlebar->height());
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
