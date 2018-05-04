#-------------------------------------------------
#
# Project created by QtCreator 2018-03-29T08:32:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core gui opengl widgets

win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}

TARGET = CodeBrique
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    reflector.cpp \
    wall.cpp \
    brick.cpp \
    paddle.cpp \
    ball.cpp \
    player.cpp \
    model.cpp \
    myglwidget.cpp

HEADERS += \
        mainwindow.h \
    reflector.h \
    wall.h \
    brick.h \
    paddle.h \
    ball.h \
    player.h \
    model.h \
    myglwidget.h

FORMS += \
        mainwindow.ui
