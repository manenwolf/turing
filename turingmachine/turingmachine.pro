#-------------------------------------------------
#
# Project created by QtCreator 2015-11-01T12:13:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = turingmachine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    machine.cpp \
    transition.cpp \
    state.cpp \
    symbol.cpp \
    transitionfunction.cpp \
    tinyxml/tinystr.cpp \
    tinyxml/tinyxml.cpp \
    tinyxml/tinyxmlerror.cpp \
    tinyxml/tinyxmlparser.cpp \
    tape.cpp

HEADERS  += mainwindow.h \
    transition.h \
    state.h \
    symbol.h \
    transitionfunction.h \
    machine.h \
    tinyxml/tinystr.h \
    tinyxml/tinyxml.h \
    tape.h

FORMS    += mainwindow.ui
