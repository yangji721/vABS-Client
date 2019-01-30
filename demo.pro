#-------------------------------------------------
#
# Project created by QtCreator 2018-10-14T13:57:07
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    dialog.cpp \
    dialog2.cpp \
    pbutton.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    dialog.h \
    dialog2.h \
    pbutton.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    dialog.ui \
    dialog2.ui
