#-------------------------------------------------
#
# Project created by QtCreator 2010-11-11T19:49:20
#
#-------------------------------------------------

QT       += core gui

TARGET = AGF
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    agfgraphicsview.cpp \
    agfgraphicsitem.cpp \
    transformations/agfprojective.cpp \
    transformations/agfeuclidean.cpp \
    transformations/agfaffine.cpp \
    items/agfshape.cpp \
    items/agfgrid.cpp

HEADERS  += mainwindow.h \
    agfgraphicsview.h \
    agfgraphicsitem.h \
    transformations/agfprojective.h \
    transformations/agfeuclidean.h \
    transformations/agfaffine.h \
    items/agfshape.h \
    items/agfgrid.h

FORMS    += mainwindow.ui
