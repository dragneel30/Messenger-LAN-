#-------------------------------------------------
#
# Project created by QtCreator 2015-11-15T00:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatappGuiServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    servermanager.cpp

HEADERS  += mainwindow.h \
    servermanager.h

FORMS    += mainwindow.ui

LIBS += -LC:/SFML-2.3.1-QT-BUILD/lib

INCLUDEPATH += C:/SFML-2.3.1-QT-BUILD/include
DEPENDPATH += C:/SFML-2.3.1-QT-BUILD/include


CONFIG += c++11

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
CONFIG += c++11;
