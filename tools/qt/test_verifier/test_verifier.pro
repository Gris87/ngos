QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

TARGET = test_verifier
TEMPLATE = app



# Warnings as errors - BEGIN
QMAKE_CFLAGS_WARN_ON   += -Werror
QMAKE_CXXFLAGS_WARN_ON += -Werror
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
    ../include/     # tools/qt/include/



include(../include/console/console.pri)



SOURCES += \
    src/main.cpp \
    src/other/testentry.cpp \
    src/other/testmessageinfo.cpp \
    src/threads/testverifythread.cpp \
    src/threads/testworkerthread.cpp

HEADERS += \
    src/other/testentry.h \
    src/other/testentrytype.h \
    src/other/testmessageinfo.h \
    src/threads/testverifythread.h \
    src/threads/testworkerthread.h
