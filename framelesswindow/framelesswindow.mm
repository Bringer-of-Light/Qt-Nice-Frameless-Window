#include "framelesswindow.h"

#include <Cocoa/Cocoa.h>

CFramelessWindow::CFramelessWindow(QWidget *parent)
    : QMainWindow(parent),
      m_bWinMoving(false),
      m_bMousePressed(false),
      m_bNativeSystemBtn(false)
{
    initUI();
}

//此类用于支持重载关闭按钮的行为
@interface ButtonPasser : NSObject
+ (void)buttonPassthrough:(id)sender;
@end

@implementation ButtonPasser
+ (void)buttonPassthrough:(id)sender
{
    Q_UNUSED(sender);
    ProcessSerialNumber pn;
    GetFrontProcess (&pn);
    ShowHideProcess(&pn,false);
}
@end

void CFramelessWindow::initUI()
{
    m_bNativeSystemBtn = false;

    //setAttribute(Qt::WA_MacNoClickThrough,true);
    //setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_MacShowFocusRect,false);

    //如果当前osx版本老于10.9，则后续代码不可用。转为使用定制的系统按钮，不支持自由缩放窗口及窗口阴影
    if (QSysInfo::MV_None == QSysInfo::macVersion())
    {
        if (QSysInfo::MV_None == QSysInfo::MacintoshVersion) {setWindowFlags(Qt::FramelessWindowHint); return;}
    }
    if (QSysInfo::MV_10_9 >= QSysInfo::MacintoshVersion) {setWindowFlags(Qt::FramelessWindowHint); return;}

    //以下实现隐藏标题栏，但同时仍保留系统按钮、可变大小边框、圆角矩形、窗口阴影等 默认效果
    //获取view所在的window
    NSView* view = (NSView*)winId();
    if (0 == view) {setWindowFlags(Qt::FramelessWindowHint); return;}
    NSWindow *window = view.window;
    if (0 == window) {setWindowFlags(Qt::FramelessWindowHint); return;}

    //          NSToolbar *toolbar = [[NSToolbar alloc] initWithIdentifier:@"shenjingtoolbar"];
    //          window.toolbar = toolbar;

    //设置标题文字和图标为不可见
    window.titleVisibility = NSWindowTitleHidden;   //MAC_10_10及以上版本支持
    //设置标题栏为透明
    window.titlebarAppearsTransparent = YES;        //MAC_10_10及以上版本支持
    //设置不可由标题栏拖动,避免与自定义拖动冲突
    [window setMovable:NO];                         //MAC_10_6及以上版本支持
    //window.movableByWindowBackground = YES;
    //设置view扩展到标题栏
    window.styleMask |= NSFullSizeContentViewWindowMask; //MAC_10_10及以上版本支持

    m_bNativeSystemBtn = true;

    //重载关闭按钮的行为，原理为
    //https://stackoverflow.com/questions/27643659/setting-c-function-as-selector-for-nsbutton-produces-no-results
    //https://developer.apple.com/library/content/documentation/General/Conceptual/CocoaEncyclopedia/Target-Action/Target-Action.html
    NSButton *closeButton = [window standardWindowButton:NSWindowCloseButton];
    [closeButton setTarget:[ButtonPasser class]];
    [closeButton setAction:@selector(buttonPassthrough:)];
}


void CFramelessWindow::mousePressEvent(QMouseEvent *event)
{
    if (isMaximized())
    {
        QMainWindow::mousePressEvent(event);
        return;
    }
    QRect rc;
    rc.setRect(0,0,size().width(), size().height());
    if(rc.contains(this->mapFromGlobal(QCursor::pos()))==true)//如果按下的位置
    {
        if (event->button() == Qt::LeftButton)
        {
            m_WindowPos = this->pos();
            m_MousePos = event->globalPos();
            this->m_MousePressed = true;
            event->accept();
            return;
        }
    }
    QMainWindow::mousePressEvent(event);
    return;
}

void CFramelessWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_bWinMoving = false;
    if (isMaximized())
    {
        return QMainWindow::mouseReleaseEvent(event);
    }
    if (event->button() == Qt::LeftButton)
    {
        this->m_MousePressed = false;
        emit windowMoved();
        event->accept();
        return;
    }
    QMainWindow::mouseReleaseEvent(event);
}

void CFramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_MousePressed)
    {
        m_bWinMoving = true;
        emit windowMoving();
        this->move(m_WindowPos + (event->globalPos() - m_MousePos));
        event->accept();
        return;
    }
    QMainWindow::mouseMoveEvent(event);
}

