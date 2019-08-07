QT -= gui

CONFIG += c++17

TARGET = bootloader.elf
TEMPLATE = app



VECTORIZATION_FLAGS = -mno-mmx -mno-sse
FMA_FLAGS           = -mno-fma



DEFINES += \
    BUILD_TARGET_BOOTLOADER \
    UEFI_APPLICATION



INCLUDEPATH += \
    ../shared \                # /src/os/shared
    ../include \               # /src/os/include
    ../../../include \         # /include
    ../../../include/stdinc    # /include/stdinc



include(../shared/common/common.pri)
include(../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/main.S \
    src/bits64/main/bootloader.cpp \
    src/main.cpp

HEADERS += \
    src/bits64/main/bootloader.h \
    src/bits64/other/volumeinfo.h \
    src/bits64/other/volumetype.h \
    test/bits64/sections/section1/bits64/types.h \
    test/bits64/sections/section1/testcase.h
