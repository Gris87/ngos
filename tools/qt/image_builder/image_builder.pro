QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

TARGET = image_builder
TEMPLATE = app



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
    ../../../include \              # /include
    ../../../src/os/configure \     # /src/os/configure
    ../include                      # /tools/qt/include



include(../include/console/console.pri)
include(../include/elf/elf.pri)



SOURCES += \
    src/main.cpp \
    src/main/imagebuilder.cpp \
    src/pe/coffheader.cpp \
    src/pe/datadirectory.cpp \
    src/pe/imagesectionheader.cpp \
    src/pe/peheader.cpp \
    src/pe/peoptheader.cpp

HEADERS += \
    src/main/imagebuilder.h \
    src/pe/coffheader.h \
    src/pe/datadirectory.h \
    src/pe/imagesectionheader.h \
    src/pe/peheader.h \
    src/pe/peoptheader.h
