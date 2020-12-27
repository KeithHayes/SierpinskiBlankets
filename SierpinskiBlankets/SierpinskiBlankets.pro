QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    carpet.cpp \
    circle.cpp \
    fractalobject.cpp \
    gasket.cpp \
    graphical.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    objectcolor.cpp \
    optionsdialog.cpp \
    point.cpp \
    star.cpp \
    viewscreen.cpp

HEADERS += \
    carpet.h \
    circle.h \
    fractalobject.h \
    gasket.h \
    graphical.h \
    mainwindow.h \
    matrix.h \
    misc.h \
    objectcolor.h \
    options.h \
    optionsdialog.h \
    point.h \
    star.h \
    viewscreen.h

FORMS += \
    mainwindow.ui \
    optionsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
