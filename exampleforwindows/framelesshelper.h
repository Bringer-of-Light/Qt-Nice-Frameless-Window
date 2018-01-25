#ifndef FRAMELESSHELPER_H
#define FRAMELESSHELPER_H

#include <QObject>
//FramelessHelper

#include <QWidget>
#include <QRubberBand>
#include <QObject>
#include <QEvent>
#include <QRect>
#include <QPoint>
#include <QHoverEvent>
#include <QMouseEvent>

class FramelessHelper : public QObject {
    Q_OBJECT

public:
    enum Edge {
        None = 0x0,
        Left = 0x1,
        Top = 0x2,
        Right = 0x4,
        Bottom = 0x8,
        TopLeft = 0x10,
        TopRight = 0x20,
        BottomLeft = 0x40,
        BottomRight = 0x80,
    };
    Q_ENUM(Edge)
    Q_DECLARE_FLAGS(Edges, Edge)

    FramelessHelper(QWidget *target);

    void setBorderWidth(int w) {
        _borderWidth = w;
    }
    int borderWidth() const {
        return _borderWidth;
    }

protected:
    bool eventFilter(QObject *o, QEvent *e) override;
    void mouseHover(QHoverEvent*);
    void mouseLeave(QEvent*);
    void mousePress(QMouseEvent*);
    void mouseRealese(QMouseEvent*);
    void mouseMove(QMouseEvent*);
    void mouseDoubleClick(QMouseEvent *e);
    void updateCursorShape(const QPoint &);
    void calculateCursorPosition(const QPoint &, const QRect &, Edges &);

private:
    QWidget *_target = nullptr;
    QRubberBand *_rubberband = nullptr;
    bool _cursorchanged;
    bool _leftButtonPressed;
    Edges _mousePress = Edge::None;
    Edges _mouseMove = Edge::None;
    int _borderWidth;

    QPoint _dragPos;
    bool _dragStart = false;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(FramelessHelper::Edges)

#endif // FRAMELESSHELPER_H
