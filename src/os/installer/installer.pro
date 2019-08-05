QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle
CONFIG -= qt

TARGET = installer.elf
TEMPLATE = app



INCLUDEPATH += \
    ../shared/ \                # src/os/shared/
    ../include/ \               # src/os/include/
    ../../../include/ \         # include/
    ../../../include/stdinc/    # include/stdinc/



include(../shared/common/common.pri)
include(../shared/kernelbase/kernelbase.pri)



QMAKE_LFLAGS += \
    -T linker.ld
