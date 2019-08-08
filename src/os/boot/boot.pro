QT -= gui

CONFIG += c++17

TARGET = boot
TEMPLATE = uefi



QMAKE_LFLAGS += \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/main.S
