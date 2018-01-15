QT+= core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    dialog.cpp \
    dataformat.cpp \
    encryption.cpp \
    password.cpp

HEADERS += \
    window.h \
    dialog.h \
    dataformat.h \
    encryption.h \
    password.h
