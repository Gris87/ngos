QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

TARGET = qmake
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
    ../../../include \      # /include
    ../shared/console       # /tools/qt/shared/console



include(../shared/console/console.pri)



SOURCES += \
    src/com/ngos/devtools/qmake/main.cpp \
    src/com/ngos/devtools/qmake/main/qmake.cpp \
    src/com/ngos/devtools/qmake/threads/searchdependenciesthread.cpp

HEADERS += \
    src/com/ngos/devtools/qmake/main/qmake.h \
    src/com/ngos/devtools/qmake/threads/searchdependenciesthread.h
