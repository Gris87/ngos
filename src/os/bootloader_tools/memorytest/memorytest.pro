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
    ../../../../include \       # /include
    ../../../../include/stdinc  # /include/stdinc



include(../../shared/common/common.pri)
include(../../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/bootloader_tools/memorytest/main.S \
    asm/arch/x86_64/com/ngos/bootloader_tools/memorytest/tests/readmemoryblock.S \
    asm/arch/x86_64/com/ngos/bootloader_tools/memorytest/tests/writememoryblock.S \
    src/com/ngos/bootloader_tools/memorytest/main.cpp \
    src/com/ngos/bootloader_tools/memorytest/main/memorytest.cpp \
    src/com/ngos/bootloader_tools/memorytest/main/memorytestgui.cpp \
    src/com/ngos/bootloader_tools/memorytest/tests/testbase.cpp \
    src/com/ngos/bootloader_tools/memorytest/tests/testrandomread.cpp \
    src/com/ngos/bootloader_tools/memorytest/tests/testrandomwrite.cpp \
    src/com/ngos/bootloader_tools/memorytest/tests/testsequentialread.cpp \
    src/com/ngos/bootloader_tools/memorytest/tests/testsequentialwrite.cpp

HEADERS += \
    src/com/ngos/bootloader_tools/memorytest/main/memorytest.h \
    src/com/ngos/bootloader_tools/memorytest/main/memorytestgui.h \
    src/com/ngos/bootloader_tools/memorytest/other/testmode.h \
    src/com/ngos/bootloader_tools/memorytest/other/testtype.h \
    src/com/ngos/bootloader_tools/memorytest/tests/asm_readmemoryblock.h \
    src/com/ngos/bootloader_tools/memorytest/tests/asm_writememoryblock.h \
    src/com/ngos/bootloader_tools/memorytest/tests/testbase.h \
    src/com/ngos/bootloader_tools/memorytest/tests/testrandomread.h \
    src/com/ngos/bootloader_tools/memorytest/tests/testrandomwrite.h \
    src/com/ngos/bootloader_tools/memorytest/tests/testsequentialread.h \
    src/com/ngos/bootloader_tools/memorytest/tests/testsequentialwrite.h \
    test/com/ngos/bootloader_tools/memorytest/sections/section1/com/ngos/bootloader_tools/memorytest/types.h \
    test/com/ngos/bootloader_tools/memorytest/sections/section1/testcase.h
