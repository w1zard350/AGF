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
    transformations/projective.cpp \
    transformations/euclidean.cpp \
    transformations/affine.cpp \
    items/agfshape.cpp \
    items/agfgrid.cpp

HEADERS  += mainwindow.h \
    agfgraphicsview.h \
    agfgraphicsitem.h \
    transformations/projective.h \
    transformations/euclidean.h \
    transformations/affine.h \
    items/agfshape.h \
    items/agfgrid.h

FORMS    += mainwindow.ui
