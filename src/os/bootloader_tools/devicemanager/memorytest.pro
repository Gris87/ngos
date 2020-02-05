QT -= gui

CONFIG += c++17

TARGET = memorytest
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_MEMORYTEST \
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
    src/bits64/main/memorytest.cpp \
    src/bits64/main/memorytestgui.cpp \
    src/main.cpp

HEADERS += \
    src/bits64/main/memorytest.h \
    src/bits64/main/memorytestgui.h \
    test/bits64/sections/section1/bits64/types.h \
    test/bits64/sections/section1/testcase.h
