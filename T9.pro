QT += core
QT -= gui

CONFIG += c++11

TARGET = T9
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    node.cpp

HEADERS += \
    itrie.h \
    node.h
