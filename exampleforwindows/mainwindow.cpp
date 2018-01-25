#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRect>
#include "framelesshelper.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    CFramelessWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#ifdef Q_OS_WIN
    //feel free to change this number to see how it works
    setResizeableAreaWidth(8);

    //set titlebar widget, wo we can drag MainWindow by it
    setTitleBar(ui->widgetTitlebar);

    //labelTitleText is a child widget of widgetTitlebar
    //add labelTitleText to ignore list, so we can drag MainWindow by it too
    addIgnoreWidget(ui->labelTitleText);

    //further more, btnMin/btnMax... are child widgets of widgetTitlebar too
    //but we DO NOT want to drag MainWindow by them
#endif

    ui->labelMargins->setText(currentMargins());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMin_clicked()
{
    showMinimized();
}
void MainWindow::on_btnMax_clicked()
{
    if (isMaximized()) showNormal();
    else showMaximized();
}
void MainWindow::on_btnClose_clicked()
{
    close();
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << event->type();
}

void MainWindow::on_bthFull_clicked()
{
    if (isFullScreen()) showNormal();
    else showFullScreen();
}

void MainWindow::on_btnIncreaseMargin_clicked()
{
    QMargins margin = contentsMargins();
    margin += 2;
    setContentsMargins(margin);
    ui->labelMargins->setText(currentMargins());
}

void MainWindow::on_btnDecreaseMargin_clicked()
{
    QMargins margin = contentsMargins();
    margin -= 2;
    setContentsMargins(margin);
    ui->labelMargins->setText(currentMargins());
}

QString MainWindow::currentMargins()
{
    QMargins margins = contentsMargins();
    QRect rect = contentsRect();
    return QString("Current Margins:%1,%2,%3,%4; ContentRect:%5,%6,%7,%8").\
            arg(margins.left()).arg(margins.top()).\
            arg(margins.right()).arg(margins.bottom()).\
            arg(rect.left()).arg(rect.top()).\
            arg(rect.right()).arg(rect.bottom());
}

void MainWindow::on_btnResizeable_clicked()
{
    setResizeable(!isResizeable());
}

void MainWindow::on_btnSubWindow_clicked()
{
    QWidget * subWin = new QWidget(this);
    FramelessHelper * fl = new FramelessHelper(subWin);

    subWin->setAttribute(Qt::WA_DeleteOnClose);
    subWin->setWindowFlag(Qt::Window,true);

    QVBoxLayout* vl = new QVBoxLayout(subWin);
    vl->setMargin(0);
    vl->setSpacing(0);
    subWin->setLayout(vl);

    QLabel* titleBar = new QLabel(subWin);
    titleBar->setStyleSheet("background-color:red");
    titleBar->resize(500,50);
    titleBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    titleBar->installEventFilter(fl);

    QLabel * content = new QLabel(subWin);
    content->setStyleSheet("QLabel{background-color:gray}");
    content->setText("test content");
    content->setAlignment(Qt::AlignCenter);
    content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    content->resize(500,100);

    vl->addWidget(titleBar);
    vl->addWidget(content);

    subWin->resize(500,400);
    subWin->show();
}
