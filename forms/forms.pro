#-------------------------------------------------
#
# Project created by QtCreator 2015-08-06T14:42:19
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = forms
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    client.h

FORMS    += mainwindow.ui
