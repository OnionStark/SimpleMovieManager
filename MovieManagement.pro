#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T20:01:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MovieManagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    movie.cpp \
    seat.cpp \
    session.cpp \
    MovieCatalog.cpp \
    moviecatalogui.cpp \
    movieinfomationlabel.cpp \
    order.cpp \
    ordercatalog.cpp \
    user.cpp \
    administrator.cpp \
    comment.cpp \
    commentcatalog.cpp \
    usercatalog.cpp \
    usercatalogui.cpp

HEADERS  += mainwindow.h \
    movie.h \
    seat.h \
    session.h \
    MovieCatalog.h \
    moviecatalogui.h \
    ../build-MovieManagement-Desktop_Qt_5_8_0_MinGW_32bit-Debug/ui_mainwindow.h \
    movieinformationlabel.h \
    order.h \
    ordercatalog.h \
    user.h \
    administrator.h \
    comment.h \
    commentcatalog.h \
    usercatalog.h \
    usercatalogui.h

FORMS    += mainwindow.ui

DISTFILES += \
    images/1.jpg \
    images/人再囧途之泰囧.jpg \
    images/催眠大师.jpg \
    images/冰雪奇缘.jpg \
    images/夏日大作战.jpg \
    images/澳门风云.jpg \
    images/终结者-创世纪.jpg \
    images/超凡蜘蛛侠2.jpg
