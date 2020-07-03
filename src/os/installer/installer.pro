QT -= gui

CONFIG += c++17

TARGET = installer
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_INSTALLER \
    UEFI_APPLICATION



INCLUDEPATH += \
    ../shared/common/src \     # /src/os/shared/common/src
    ../shared/uefibase/src \   # /src/os/shared/uefibase/src
    ../shared/uefibase/test \  # /src/os/shared/uefibase/test
    ../../../include \         # /include
    ../../../include/stdinc    # /include/stdinc



include(../shared/common/common.pri)
include(../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/installer/main.S \
    src/com/ngos/installer/main.cpp \
    src/com/ngos/installer/main/installer.cpp \
    src/com/ngos/installer/main/installergui.cpp

HEADERS += \
    src/com/ngos/installer/main/installer.h \
    src/com/ngos/installer/main/installergui.h \
    test/com/ngos/installer/sections/section1/com/ngos/installer/types.h \
    test/com/ngos/installer/sections/section1/testcase.h
