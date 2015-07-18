#-------------------------------------------------
#
# Project created by QtCreator 2015-06-06T10:58:31
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EquipmentManager
TEMPLATE = app


SOURCES += main.cpp\
    configdialog.cpp \
    logindialog.cpp \
    userpage.cpp \
    userinfodialog.cpp \
    LoginManager.cpp \
    User.cpp \
    UserAccess.cpp \
    Admin.cpp \
    AdminAccess.cpp \
    UserManager.cpp \
    equipmentpage.cpp \
    equipmentinfodialog.cpp \
    Equipment.cpp \
    EquipmentAccess.cpp \
    EquipmentManager.cpp \
    Order.cpp \
    OrderAccess.cpp \
    OrderManager.cpp \
    orderpage.cpp \
    orderinfodialog.cpp \
    homepage.cpp

HEADERS  += \
    configdialog.h \
    logindialog.h \
    userpage.h \
    userinfodialog.h \
    User.h \
    UserAccess.h \
    LoginManager.h \
    Admin.h \
    AdminAccess.h \
    UserManager.h \
    equipmentpage.h \
    equipmentinfodialog.h \
    Equipment.h \
    EquipmentAccess.h \
    EquipmentManager.h \
    Order.h \
    OrderAccess.h \
    OrderManager.h \
    orderpage.h \
    orderinfodialog.h \
    homepage.h

FORMS    += mainwindow.ui \
    logindialog.ui

CONFIG += console
