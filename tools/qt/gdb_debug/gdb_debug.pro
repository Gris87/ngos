QT += core gui widgets

CONFIG += c++17

TARGET = gdb_debug
TEMPLATE = app

RC_FILE    = Resources.rc
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
    ../include      # /tools/qt/include



include(../include/elf/elf.pri)



SOURCES += \
    src/main.cpp \
    src/main/aboutdialog.cpp \
    src/main/mainwindow.cpp \
    src/main/memorymapdialog.cpp \
    src/other/global.cpp \
    src/processes/gdbprocess.cpp \
    src/processes/qemuprocess.cpp \
    src/threads/addbreakpointthread.cpp \
    src/threads/deletebreakpointthread.cpp \
    src/threads/dumpmemorythread.cpp \
    src/threads/interpretthread.cpp \
    src/threads/memorymapthread.cpp \
    src/threads/qemureaderthread.cpp \
    src/threads/registersthread.cpp \
    src/threads/restartthread.cpp \
    src/threads/startthread.cpp \
    src/threads/stepthread.cpp \
    src/threads/stopthread.cpp \
    src/threads/waitforbreakthread.cpp \
    src/widgets/hexgraphicsview.cpp \
    src/widgets/scalegraphicsview.cpp \
    src/widgets/trackingtablewidget.cpp

HEADERS += \
    src/generated/hexarrays.h \
    src/main/aboutdialog.h \
    src/main/mainwindow.h \
    src/main/memorymapdialog.h \
    src/other/defines.h \
    src/other/global.h \
    src/other/memorymapinfo.h \
    src/processes/gdbprocess.h \
    src/processes/qemuprocess.h \
    src/threads/addbreakpointthread.h \
    src/threads/deletebreakpointthread.h \
    src/threads/dumpmemorythread.h \
    src/threads/interpretthread.h \
    src/threads/memorymapthread.h \
    src/threads/qemureaderthread.h \
    src/threads/registersthread.h \
    src/threads/restartthread.h \
    src/threads/startthread.h \
    src/threads/stepthread.h \
    src/threads/stopthread.h \
    src/threads/waitforbreakthread.h \
    src/widgets/hexgraphicsview.h \
    src/widgets/scalegraphicsview.h \
    src/widgets/trackingtablewidget.h

FORMS += \
    src/main/aboutdialog.ui \
    src/main/mainwindow.ui \
    src/main/memorymapdialog.ui
