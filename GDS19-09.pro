#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T06:31:25
#
# Update 30/05/2019
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GDS19
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    dialog_store_windows.cpp \
    form_filter.cpp \
    dataBase.cpp \
    dialog_parts_id_update.cpp \
    dialog_parts_id_delete.cpp

HEADERS  += mainwindow.h \
    dialog_store_windows.h \
    form_filter.h \
    dataBase.h \
    dialog_parts_id_update.h \
    dialog_parts_id_delete.h

FORMS    += mainwindow.ui \
    dialog_store_windows.ui \
    form_filter.ui \
    dialog_parts_id_update.ui \
    dialog_parts_id_delete.ui
