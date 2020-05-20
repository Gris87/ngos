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
    src/generators/assets/assetsgenerator.cpp \
    src/generators/assets/zzz_generators/consoleglyphgenerator.cpp \
    src/generators/assets/zzz_generators/guiglyphgenerator.cpp \
    src/generators/common/commongenerator.cpp \
    src/generators/common/zzz_generators/bytesdecimalsgenerator.cpp \
    src/generators/common/zzz_generators/hexcharsgenerator.cpp \
    src/generators/common/zzz_generators/numberdecimalsgenerator.cpp \
    src/generators/common/zzz_generators/x86bugsnamesgenerator.cpp \
    src/generators/common/zzz_generators/x86featuresnamesgenerator.cpp \
    src/generators/configure/configuregenerator.cpp \
    src/generators/configure/zzz_generators/asmoffsetsgenerator.cpp \
    src/generators/generator.cpp \
    src/generators/usb_boot_maker/usbbootmakergenerator.cpp \
    src/generators/usb_boot_maker/zzz_generators/protectivembrgenerator.cpp \
    src/main.cpp

HEADERS += \
    src/generators/assets/assetsgenerator.h \
    src/generators/assets/zzz_generators/consoleglyphgenerator.h \
    src/generators/assets/zzz_generators/guiglyphgenerator.h \
    src/generators/common/commongenerator.h \
    src/generators/common/zzz_generators/bytesdecimalsgenerator.h \
    src/generators/common/zzz_generators/hexcharsgenerator.h \
    src/generators/common/zzz_generators/numberdecimalsgenerator.h \
    src/generators/common/zzz_generators/x86bugsnamesgenerator.h \
    src/generators/common/zzz_generators/x86featuresnamesgenerator.h \
    src/generators/configure/configuregenerator.h \
    src/generators/configure/zzz_generators/asmoffsetsgenerator.h \
    src/generators/generator.h \
    src/generators/usb_boot_maker/usbbootmakergenerator.h \
    src/generators/usb_boot_maker/zzz_generators/protectivembrgenerator.h
