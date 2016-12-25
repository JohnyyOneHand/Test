#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T22:06:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    #viewer_sfml.cpp \
    QSFMLCanvas.cpp \
    QSFMLCanvasEventHandler.cpp \
    canvas_test.cpp \
    qvector2.cpp \
    keyconverter.cpp \
    widget1.cpp \
    scale.cpp \
    vec_extr.cpp

HEADERS  += mainwindow.h \
    viewer.h \
    QSFMLCanvas.hpp \
    canvas_test.h \
    qvector2.hpp \
    keyconverter.hpp \
    widget1.h \
    scale.h \
    vec_extr.h

FORMS    += mainwindow.ui \
    #viewer_sfml.ui
    widget1.ui


LIBS += -LC:/Users/Blazejek/Desktop/QT/SFML-2.4.1-windows-gcc-6.1.0-mingw-32-bit/SFML-2.4.1/lib



INCLUDEPATH += C:/Users/Blazejek/Desktop/QT/SFML-2.4.1-windows-gcc-6.1.0-mingw-32-bit/SFML-2.4.1/include
DEPENDPATH += C:/Users/Blazejek/Desktop/QT/SFML-2.4.1-windows-gcc-6.1.0-mingw-32-bit/SFML-2.4.1/include


CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

RESOURCES += \
    resources.qrc

