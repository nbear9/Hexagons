#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T20:20:07
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Hexagons
TEMPLATE = app

SOURCES += main.cpp\
    boardgraphicshexagon.cpp \
        widget.cpp \
    graphicsscene.cpp \
    boardhexagon.cpp
#    draggablepiece.cpp

HEADERS  += widget.h \
    boardgraphicshexagon.h \
    graphicsscene.h \
    boardhexagon.h
#    draggablepiece.h

RESOURCES = hexagon.qrc
