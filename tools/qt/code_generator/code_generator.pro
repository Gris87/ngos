QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

TARGET = code_generator
TEMPLATE = app

RESOURCES += Resources.qrc



# Warnings as errors - BEGIN
win32-msvc* {
    QMAKE_CXXFLAGS += /WX
} else {
    QMAKE_CXXFLAGS += -Werror
}
# Warnings as errors - END

# Release optimization - BEGIN
QMAKE_CFLAGS_RELEASE -= -O1
QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CFLAGS_RELEASE += -O3

QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
# Release optimization - END

# Target dirs - BEGIN
DESTDIR     = build/
OBJECTS_DIR = build/gen
MOC_DIR     = build/gen
RCC_DIR     = build/gen
UI_DIR      = build/gen
# Target dirs - END



INCLUDEPATH += \
    ../../../3rd_party/libs/freetype/include \  # /3rd_party/libs/freetype/include
    ../../../include \                          # /include
    ../../../src/os/configure \                 # /src/os/configure
    ../../../src/os/include \                   # /src/os/include
    ../include                                  # /tools/qt/include



LIBS += \
    -L../../../3rd_party/libs/freetype/objs/.libs -lfreetype



include(../include/console/console.pri)



SOURCES += \
    src/com/ngos/devtools/code_generator/generators/assets/assetsgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/assets/zzz_generators/consoleglyphgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/assets/zzz_generators/guiglyphgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/common/commongenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/bytesdecimalsgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/hexcharsgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/numberdecimalsgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/x86bugsnamesgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/x86featuresnamesgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/configure/configuregenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/configure/zzz_generators/asmoffsetsgenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/generator.cpp \
    src/com/ngos/devtools/code_generator/generators/usb_boot_maker/usbbootmakergenerator.cpp \
    src/com/ngos/devtools/code_generator/generators/usb_boot_maker/zzz_generators/protectivembrgenerator.cpp \
    src/com/ngos/devtools/code_generator/main.cpp

HEADERS += \
    src/com/ngos/devtools/code_generator/generators/assets/assetsgenerator.h \
    src/com/ngos/devtools/code_generator/generators/assets/zzz_generators/consoleglyphgenerator.h \
    src/com/ngos/devtools/code_generator/generators/assets/zzz_generators/guiglyphgenerator.h \
    src/com/ngos/devtools/code_generator/generators/common/commongenerator.h \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/bytesdecimalsgenerator.h \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/hexcharsgenerator.h \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/numberdecimalsgenerator.h \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/x86bugsnamesgenerator.h \
    src/com/ngos/devtools/code_generator/generators/common/zzz_generators/x86featuresnamesgenerator.h \
    src/com/ngos/devtools/code_generator/generators/configure/configuregenerator.h \
    src/com/ngos/devtools/code_generator/generators/configure/zzz_generators/asmoffsetsgenerator.h \
    src/com/ngos/devtools/code_generator/generators/generator.h \
    src/com/ngos/devtools/code_generator/generators/usb_boot_maker/usbbootmakergenerator.h \
    src/com/ngos/devtools/code_generator/generators/usb_boot_maker/zzz_generators/protectivembrgenerator.h
