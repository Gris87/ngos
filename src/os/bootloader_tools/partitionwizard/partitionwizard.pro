QT -= gui

CONFIG += c++17

TARGET = partitionwizard
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_PARTITIONWIZARD \
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
    asm/arch/x86_64/main.S \
    src/bits64/main/partitionwizard.cpp \
    src/bits64/main/partitionwizardgui.cpp \
    src/main.cpp

HEADERS += \
    src/bits64/main/partitionwizard.h \
    src/bits64/main/partitionwizardgui.h \
    test/bits64/sections/section1/bits64/types.h \
    test/bits64/sections/section1/testcase.h
