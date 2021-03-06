QT -= gui

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET   = image_builder
TEMPLATE = app



DEFINES += \
    DEVTOOLS_APPLICATION \
    _WIN32_WINNT=0x0A00



# Warnings as errors - BEGIN
win32-msvc* {
    QMAKE_CXXFLAGS += /WX
} else {
    QMAKE_CXXFLAGS += -Wall -Werror
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
OBJECTS_DIR = build/gen/$$TARGET/objs
MOC_DIR     = build/gen/$$TARGET/moc
RCC_DIR     = build/gen/$$TARGET/rcc
UI_DIR      = build/gen/$$TARGET/ui
# Target dirs - END



INCLUDEPATH += \
    src \                                   # tools/qt/image_builder/src
    build/gen \                             # tools/qt/image_builder/build/gen
    ../../../include \                      # include
    ../../../src/os/configure/src \         # src/os/configure/src
    ../../../src/os/shared/common/src \     # src/os/shared/common/src
    ../shared/console/src \                 # tools/qt/shared/console/src
    ../shared/elf/src                       # tools/qt/shared/elf/src



include(../shared/console/console.pri)
include(../shared/elf/elf.pri)



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
