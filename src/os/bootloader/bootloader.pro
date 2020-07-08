QT -= gui

CONFIG += c++17

TARGET = bootloader
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_BOOTLOADER \
    UEFI_APPLICATION



INCLUDEPATH += \
    src \                       # /src/os/bootloader/src
    test \                      # /src/os/bootloader/test
    ../shared/common/src \      # /src/os/shared/common/src
    ../shared/uefibase/src \    # /src/os/shared/uefibase/src
    ../shared/uefibase/test \   # /src/os/shared/uefibase/test
    ../../../include \          # /include
    ../../../include/stdinc     # /include/stdinc



include(../shared/common/common.pri)
include(../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/bootloader/main.S \
    src/com/ngos/bootloader/main.cpp \
    src/com/ngos/bootloader/main/bootloader.cpp \
    src/com/ngos/bootloader/main/bootloadergui.cpp

HEADERS += \
    src/com/ngos/bootloader/main/bootloader.h \
    src/com/ngos/bootloader/main/bootloadergui.h \
    src/com/ngos/bootloader/other/osinfo.h \
    src/com/ngos/bootloader/other/ostype.h \
    src/com/ngos/bootloader/other/volumeinfo.h \
    src/com/ngos/bootloader/other/volumetype.h \
    test/com/ngos/bootloader/sections/section1/com/ngos/bootloader/main/bootloader.h \
    test/com/ngos/bootloader/sections/section1/com/ngos/bootloader/types.h \
    test/com/ngos/bootloader/sections/section1/testcase.h
