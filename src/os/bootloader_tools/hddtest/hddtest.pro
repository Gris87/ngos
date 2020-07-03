QT -= gui

CONFIG += c++17

TARGET = hddtest
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_HDDTEST \
    UEFI_APPLICATION



INCLUDEPATH += \
    ../../shared/common/src \       # /src/os/shared/common/src
    ../../shared/uefibase/src \     # /src/os/shared/uefibase/src
    ../../shared/uefibase/test \    # /src/os/shared/uefibase/test
    ../../../../include \           # /include
    ../../../../include/stdinc      # /include/stdinc



include(../../shared/common/common.pri)
include(../../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/bootloader_tools/hddtest/main.S \
    src/com/ngos/bootloader_tools/hddtest/main.cpp \
    src/com/ngos/bootloader_tools/hddtest/main/hddtest.cpp \
    src/com/ngos/bootloader_tools/hddtest/main/hddtestgui.cpp

HEADERS += \
    src/com/ngos/bootloader_tools/hddtest/main/hddtest.h \
    src/com/ngos/bootloader_tools/hddtest/main/hddtestgui.h \
    test/com/ngos/bootloader_tools/hddtest/sections/section1/com/ngos/bootloader_tools/hddtest/types.h \
    test/com/ngos/bootloader_tools/hddtest/sections/section1/testcase.h
