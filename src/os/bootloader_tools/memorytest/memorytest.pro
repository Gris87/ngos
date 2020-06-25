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
    asm/arch/x86_64/bits64/tests/readmemoryblock.S \
    asm/arch/x86_64/bits64/tests/writememoryblock.S \
    asm/arch/x86_64/main.S \
    src/bits64/main/memorytest.cpp \
    src/bits64/main/memorytestgui.cpp \
    src/bits64/tests/testbase.cpp \
    src/bits64/tests/testrandomread.cpp \
    src/bits64/tests/testrandomwrite.cpp \
    src/bits64/tests/testsequentialread.cpp \
    src/bits64/tests/testsequentialwrite.cpp \
    src/main.cpp

HEADERS += \
    src/bits64/main/memorytest.h \
    src/bits64/main/memorytestgui.h \
    src/bits64/other/memorytestmode.h \
    src/bits64/other/memorytesttype.h \
    src/bits64/tests/asm_readmemoryblock.h \
    src/bits64/tests/asm_writememoryblock.h \
    src/bits64/tests/testbase.h \
    src/bits64/tests/testrandomread.h \
    src/bits64/tests/testrandomwrite.h \
    src/bits64/tests/testsequentialread.h \
    src/bits64/tests/testsequentialwrite.h \
    test/bits64/sections/section1/bits64/types.h \
    test/bits64/sections/section1/testcase.h
