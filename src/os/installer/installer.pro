QT -= gui

CONFIG += c++17

TARGET = installer
TEMPLATE = kernel

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_INSTALLER



INCLUDEPATH += \
    ../shared \                # /src/os/shared
    ../include \               # /src/os/include
    ../../../include \         # /include
    ../../../include/stdinc    # /include/stdinc



include(../shared/common/common.pri)
include(../shared/kernelbase/kernelbase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    --emit-relocs \
    -T linker.ld
