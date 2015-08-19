#-------------------------------------------------
#
# Project created by QtCreator 2015-08-06T14:42:19
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = forms
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    sendtoserver.cpp

HEADERS  += mainwindow.h \
    client.h \
    sendtoserver.h

FORMS    += mainwindow.ui
