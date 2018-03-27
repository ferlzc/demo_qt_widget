QT       += core gui charts network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo_embedded_gui
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    status.cpp \
    navigation.cpp \
    chart.cpp

HEADERS += \
        mainwindow.h \
    status.h \
    navigation.h \
    chart.h

FORMS += \
        mainwindow.ui \
    status.ui \
    navigation.ui

RESOURCES += \
    images.qrc

target.path = /home/root
INSTALLS += target
