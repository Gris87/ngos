QT -= gui

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET   = qmake
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
    src \                   # tools/qt/qmake/src
    build/gen \             # tools/qt/qmake/build/gen
    ../../../include \      # include
    ../shared/console/src   # tools/qt/shared/console/src



include(../shared/console/console.pri)



SOURCES += \
    src/com/ngos/devtools/qmake/main.cpp \
    src/com/ngos/devtools/qmake/main/qmake.cpp \
    src/com/ngos/devtools/qmake/threads/searchdependenciesthread.cpp

HEADERS += \
    src/com/ngos/devtools/qmake/main/qmake.h \
    src/com/ngos/devtools/qmake/threads/searchdependenciesthread.h
