#-------------------------------------------------
#
# Project created by QtCreator 2015-11-15T00:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatappGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clientmanager.cpp \
    chatbox.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    clientmanager.h \
    chatbox.h \
    login.h

FORMS    += mainwindow.ui \
    login.ui
CONFIG += c++11

LIBS += -LC:/SFML-2.3.1-QT-BUILD/lib

INCLUDEPATH += C:/SFML-2.3.1-QT-BUILD/include
DEPENDPATH += C:/SFML-2.3.1-QT-BUILD/include


CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

