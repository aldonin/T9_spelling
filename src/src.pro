QT += core
QT -= gui

TARGET = Trie

TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += node.cpp \
    trie.cpp \
    itrie.cpp

HEADERS += \
    itrie.h \
    node.h \
    trie.h \

