QT -= gui

CONFIG += c++17

TARGET = devicemanager
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_DEVICEMANAGER \
    UEFI_APPLICATION



INCLUDEPATH += \
    src \                           # /src/os/bootloader_tools/devicemanager/src
    test \                          # /src/os/bootloader_tools/devicemanager/test
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
    asm/arch/x86_64/com/ngos/bootloader_tools/devicemanager/main.S \
    src/com/ngos/bootloader_tools/devicemanager/main.cpp \
    src/com/ngos/bootloader_tools/devicemanager/main/devicemanager.cpp \
    src/com/ngos/bootloader_tools/devicemanager/main/devicemanagergui.cpp \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.cpp \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrydmi.cpp \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrypci.cpp \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentryrecord.cpp \
    src/com/ngos/bootloader_tools/devicemanager/sources/devicemanagerdmi.cpp \
    src/com/ngos/bootloader_tools/devicemanager/sources/devicemanagermemorymap.cpp \
    src/com/ngos/bootloader_tools/devicemanager/sources/devicemanagerpci.cpp

HEADERS += \
    src/com/ngos/bootloader_tools/devicemanager/main/devicemanager.h \
    src/com/ngos/bootloader_tools/devicemanager/main/devicemanagergui.h \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrydmi.h \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrypci.h \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentryrecord.h \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerimage.h \
    src/com/ngos/bootloader_tools/devicemanager/other/devicemanagermode.h \
    src/com/ngos/bootloader_tools/devicemanager/sources/devicemanagerdmi.h \
    src/com/ngos/bootloader_tools/devicemanager/sources/devicemanagermemorymap.h \
    src/com/ngos/bootloader_tools/devicemanager/sources/devicemanagerpci.h \
    test/com/ngos/bootloader_tools/devicemanager/sections/section1/com/ngos/bootloader_tools/devicemanager/types.h \
    test/com/ngos/bootloader_tools/devicemanager/sections/section1/testcase.h
