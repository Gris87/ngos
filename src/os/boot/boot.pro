QT -= gui

CONFIG += c++20

TARGET   = boot
TEMPLATE = uefi



QMAKE_LFLAGS += \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/boot/main.S
