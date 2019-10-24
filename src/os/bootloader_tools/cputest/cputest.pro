QT -= gui

CONFIG += c++17

TARGET = cputest
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_CPUTEST \
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
    src/bits64/main/cputest.cpp \
    src/bits64/main/cputestgui.cpp \
    src/main.cpp

HEADERS += \
    src/bits64/main/cputest.h \
    src/bits64/main/cputestgui.h \
    src/bits64/other/cacheinfo.h \
    test/bits64/sections/section1/bits64/types.h \
    test/bits64/sections/section1/testcase.h
