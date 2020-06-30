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
    src/com/ngos/devtools/image_builder/main.cpp \
    src/com/ngos/devtools/image_builder/main/imagebuilder.cpp \
    src/com/ngos/devtools/image_builder/pe/coffheader.cpp \
    src/com/ngos/devtools/image_builder/pe/datadirectory.cpp \
    src/com/ngos/devtools/image_builder/pe/imagesectionheader.cpp \
    src/com/ngos/devtools/image_builder/pe/peheader.cpp \
    src/com/ngos/devtools/image_builder/pe/peoptheader.cpp

HEADERS += \
    src/com/ngos/devtools/image_builder/main/imagebuilder.h \
    src/com/ngos/devtools/image_builder/pe/coffheader.h \
    src/com/ngos/devtools/image_builder/pe/datadirectory.h \
    src/com/ngos/devtools/image_builder/pe/imagesectionheader.h \
    src/com/ngos/devtools/image_builder/pe/peheader.h \
    src/com/ngos/devtools/image_builder/pe/peoptheader.h
