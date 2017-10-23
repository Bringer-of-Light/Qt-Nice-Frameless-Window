#-------------------------------------------------
#
# Project created by QtCreator 2017-10-20T09:59:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exampleforwindows
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp
HEADERS  += mainwindow.h
FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../framelesswindow/release/ -lframelesswindow
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../framelesswindow/debug/ -lframelesswindow
else:macx: LIBS += -L$$OUT_PWD/../framelesswindow/ -lframelesswindow

INCLUDEPATH += $$PWD/../framelesswindow
DEPENDPATH += $$PWD/../framelesswindow

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../framelesswindow/release/libframelesswindow.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../framelesswindow/debug/libframelesswindow.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../framelesswindow/release/framelesswindow.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../framelesswindow/debug/framelesswindow.lib
else:macx: PRE_TARGETDEPS += $$OUT_PWD/../framelesswindow/libframelesswindow.a

include (../projectinclude/common.pri)
