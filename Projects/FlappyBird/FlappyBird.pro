#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T13:08:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlappyBird
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainscene.cpp

HEADERS  += mainwindow.h \
    mainscene.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
