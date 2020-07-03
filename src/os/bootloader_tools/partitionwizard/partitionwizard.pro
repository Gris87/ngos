QT -= gui

CONFIG += c++17

TARGET = partitionwizard
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_PARTITIONWIZARD \
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
    asm/arch/x86_64/com/ngos/bootloader_tools/partitionwizard/main.S \
    src/com/ngos/bootloader_tools/partitionwizard/main.cpp \
    src/com/ngos/bootloader_tools/partitionwizard/main/partitionwizard.cpp \
    src/com/ngos/bootloader_tools/partitionwizard/main/partitionwizardgui.cpp

HEADERS += \
    src/com/ngos/bootloader_tools/partitionwizard/main/partitionwizard.h \
    src/com/ngos/bootloader_tools/partitionwizard/main/partitionwizardgui.h \
    test/com/ngos/bootloader_tools/partitionwizard/sections/section1/com/ngos/bootloader_tools/partitionwizard/types.h \
    test/com/ngos/bootloader_tools/partitionwizard/sections/section1/testcase.h
