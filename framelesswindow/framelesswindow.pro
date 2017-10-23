#-------------------------------------------------
#
# Project created by QtCreator 2017-10-20T09:48:14
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = framelesswindow
TEMPLATE = lib
CONFIG += staticlib

HEADERS += \
    framelesswindow.h

win32{
	SOURCES += \
		framelesswindow.cpp
}
macx{
    OBJECTIVE_SOURCES += \
		framelesswindow.mm
}
include (../projectinclude/common.pri)
