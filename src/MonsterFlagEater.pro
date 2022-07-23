######################################################################
# Automatically generated by qmake (3.1) Sun Jul 19 11:18:32 2020
######################################################################

TEMPLATE = app
TARGET = src
INCLUDEPATH += .

QT += core widgets
TARGET = Boxes
DEPENDPATH += .
CONFIG += c++11

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += InteractibleObject.h Board.h BoxesController.h Common.h \
    EmptyLot.h \
    Flag.h \
    MainCharacter.h \
    IceFloor.h \
    PullBox.h \
    PushBox.h \
    Wall.h

SOURCES += InteractibleObject.cpp main.cpp Board.cpp BoxesController.cpp \
    EmptyLot.cpp \
    Flag.cpp \
    MainCharacter.cpp \
    IceFloor.cpp \
    PullBox.cpp \
    PushBox.cpp \
    Wall.cpp
