QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle
CONFIG -= qt

TARGET = ls
TEMPLATE = app



QMAKE_LFLAGS += \
    -T linker.ld
