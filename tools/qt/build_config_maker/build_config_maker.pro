QT -= gui

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET   = build_config_maker
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
    src \                   # tools/qt/build_config_maker/src
    build/gen \             # tools/qt/build_config_maker/build/gen
    ../shared/console/src   # tools/qt/shared/console/src



include(../shared/console/console.pri)



SOURCES += \
    src/com/ngos/devtools/build_config_maker/main.cpp \
    src/com/ngos/devtools/build_config_maker/main/buildconfigmaker.cpp

HEADERS += \
    src/com/ngos/devtools/build_config_maker/main/buildconfigmaker.h
