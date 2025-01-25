#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql printsupport network multimedia charts
QT += axcontainer
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# Define to emit warnings for deprecated features
DEFINES += QT_DEPRECATED_WARNINGS

# Use C++11 standard
CONFIG += c++11

# Uncomment to disable deprecated APIs before Qt 6.0.0
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Sources
SOURCES += \
    arduino.cpp \
    client.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp

# Headers
HEADERS += \
    arduino.h \
    client.h \
    employee.h \
    mainwindow.h \
    connection.h

# Forms
FORMS += \
    mainwindow.ui

# Resources


# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
