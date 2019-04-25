QT -= gui

CONFIG += c++14 console
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
    ../../../3rd_party/libs/freetype/include/ \ # 3rd_party/libs/freetype/include
    ../../../include/ \                         # include/
    ../../../src/os/configure/ \                # src/os/configure/
    ../../../src/os/include/ \                  # src/os/include/
    ../include/                                 # tools/qt/include/



LIBS += \
    -L../../../3rd_party/libs/freetype/objs/.libs -lfreetype



include(../include/console/console.pri)



SOURCES += \
    src/generators/assets/assetsgenerator.cpp \
    src/generators/assets/zzz_generators/consoleglyphgenerator.cpp \
    src/generators/common/commongenerator.cpp \
    src/generators/common/zzz_generators/cpubugsnamesgenerator.cpp \
    src/generators/common/zzz_generators/cpufeaturesnamesgenerator.cpp \
    src/generators/configure/configuregenerator.cpp \
    src/generators/configure/zzz_generators/asmoffsetsgenerator.cpp \
    src/generators/gdb_debug/gdbdebuggenerator.cpp \
    src/generators/gdb_debug/zzz_generators/hexarraysgenerator.cpp \
    src/generators/generator.cpp \
    src/generators/usb_boot_maker/usbbootmakergenerator.cpp \
    src/generators/usb_boot_maker/zzz_generators/protectivembrgenerator.cpp \
    src/main.cpp

HEADERS += \
    src/generators/assets/assetsgenerator.h \
    src/generators/assets/zzz_generators/consoleglyphgenerator.h \
    src/generators/common/commongenerator.h \
    src/generators/common/zzz_generators/cpubugsnamesgenerator.h \
    src/generators/common/zzz_generators/cpufeaturesnamesgenerator.h \
    src/generators/configure/configuregenerator.h \
    src/generators/configure/zzz_generators/asmoffsetsgenerator.h \
    src/generators/gdb_debug/gdbdebuggenerator.h \
    src/generators/gdb_debug/zzz_generators/hexarraysgenerator.h \
    src/generators/generator.h \
    src/generators/usb_boot_maker/usbbootmakergenerator.h \
    src/generators/usb_boot_maker/zzz_generators/protectivembrgenerator.h
