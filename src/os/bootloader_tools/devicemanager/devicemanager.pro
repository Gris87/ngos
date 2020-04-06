QT -= gui

CONFIG += c++17

TARGET = devicemanager
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_DEVICEMANAGER \
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
    src/bits64/main/devicemanager.cpp \
    src/bits64/main/devicemanagergui.cpp \
    src/bits64/other/devicemanagerentry.cpp \
    src/bits64/other/devicemanagerentrydmi.cpp \
    src/bits64/other/devicemanagerentryrecord.cpp \
    src/bits64/sources/dmi/devicemanagerdmi.cpp \
    src/main.cpp

HEADERS += \
    src/bits64/main/devicemanager.h \
    src/bits64/main/devicemanagergui.h \
    src/bits64/other/devicemanagerentry.h \
    src/bits64/other/devicemanagerentrydmi.h \
    src/bits64/other/devicemanagerentryrecord.h \
    src/bits64/other/devicemanagerimage.h \
    src/bits64/sources/dmi/devicemanagerdmi.h \
    test/bits64/sections/section1/bits64/types.h \
    test/bits64/sections/section1/testcase.h
