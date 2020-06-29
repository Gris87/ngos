QT -= gui

CONFIG += c++17

TARGET = networktest
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_NETWORKTEST \
    UEFI_APPLICATION



INCLUDEPATH += \
    ../../shared \              # /src/os/shared
    ../../include \             # /src/os/include
    ../../../../include \       # /include
    ../../../../include/stdinc  # /include/stdinc



include(../../shared/common/common.pri)
include(../../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/bootloader_tools/networktest/main.S \
    src/com/ngos/bootloader_tools/networktest/main.cpp \
    src/com/ngos/bootloader_tools/networktest/main/networktest.cpp \
    src/com/ngos/bootloader_tools/networktest/main/networktestgui.cpp

HEADERS += \
    src/com/ngos/bootloader_tools/networktest/main/networktest.h \
    src/com/ngos/bootloader_tools/networktest/main/networktestgui.h \
    test/com/ngos/bootloader_tools/networktest/sections/section1/com/ngos/bootloader_tools/networktest/types.h \
    test/com/ngos/bootloader_tools/networktest/sections/section1/testcase.h
