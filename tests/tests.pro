#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T15:52:57
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testnode
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ..\src
SOURCES += tst_testnode.cpp ..\src\node.cpp
HEADERS += ..\src\node.h
DEFINES += SRCDIR=\\\"$$PWD/\\\"
