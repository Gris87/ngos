QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle
CONFIG -= qt

TARGET = configure.elf
TEMPLATE = app



QMAKE_LFLAGS += \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/main.S
