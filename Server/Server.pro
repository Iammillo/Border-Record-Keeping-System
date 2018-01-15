QT+= core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


HEADERS += \
    database.h \
    dataformat.h \
    encryption.h \
    myserver.h \
    window.h \
    dialog1.h \
    values.h \
    dialog2.h \
    dialog.h

SOURCES += \
    database.cpp \
    main.cpp \
    dataformat.cpp \
    encryption.cpp \
    myserver.cpp \
    window.cpp \
    dialog1.cpp \
    dialog2.cpp \
    dialog.cpp
