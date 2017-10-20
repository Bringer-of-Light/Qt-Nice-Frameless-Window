#ifndef CFRAMELESSWINDOW_H
#define CFRAMELESSWINDOW_H
#include "qsystemdetection.h"
#include <QObject>
#include <QMainWindow>

//A nice frameless window for both Windows and OSX
//Author: Bringer-of-Light
//Github: https://github.com/Bringer-of-Light/Qt-Nice-Frameless-Window
// Usage: use "CFramelessWindow" as base class instead of "QMainWindow", and enjoy
//

#ifdef Q_OS_WIN
#include <QWidget>
#include <QList>
#include <QMargins>
class CFramelessWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CFramelessWindow(QWidget *parent = 0);
private:
    void initUI();
protected:
    //设置可调整大小区域的宽度，在此区域内，可以使用鼠标调整窗口大小
    //set border width, inside this aera, window can be resized by mouse
    void setResizeableAreaWidth(int width = 5);

    //默认情况下，此类会自动调整外边距，以避免窗口最大化时，窗口内容超出屏幕外
    //但从最大化恢复正常大小时，窗口会闪烁一次，如果要避免闪烁，可以关闭自动调整外边距
    //by default, we will auto adjust margins, to avoid the window content extend OUT of screen when maximized
    //but when the window restore to normal size, a twinkle will occur
    //if you want to avoid twinkle, set auto adjust margin to false
    void setAutoAdjustMargins(bool bAutoAdust = true);

    //设置一个标题栏widget，此widget会被当做标题栏对待
    //set a widget which will be treat as SYSTEM titlebar
    void setTitleBar(QWidget* titlebar);

    //在标题栏控件内，也可以有子控件如标签控件“label1”，此label1遮盖了标题栏，导致不能通过label1拖动窗口
    //要解决此问题，使用addIgnoreWidget(label1)
    //generally, we can add widget say "label1" on titlebar, and it will cover the titlebar under it
    //as a result, we can not drag and move the MainWindow with this "label1" again
    //we can fix this by add "label1" to a ignorelist, just call addIgnoreWidget(label1)
    void addIgnoreWidget(QWidget* widget);

    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private slots:
    void onTitleBarDestroyed();
public:
    void setContentsMargins(const QMargins &margins);
    void setContentsMargins(int left, int top, int right, int bottom);
private:
    QWidget* m_titlebar;
    QList<QWidget*> m_whiteList;
    QMargins m_margins;
    bool m_bAutoAdjustMargin;
    int m_borderWidth;
};

#elif defined Q_OS_MAC
#include <QMouseEvent>
#include <QPoint>
class CFramelessWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CFramelessWindow(QWidget *parent = 0);
private:
    void initUI();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    bool    m_bWinMoving;
    bool    m_MousePressed;
    QPoint  m_MousePos;
    QPoint  m_WindowPos;
protected:
    bool m_bNativeSystemBtn;
}
#endif

#endif // CFRAMELESSWINDOW_H
