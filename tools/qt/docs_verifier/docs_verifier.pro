QT -= gui
QT += network

CONFIG += c++14 console
CONFIG -= app_bundle

TARGET = docs_verifier
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
    ../include              # /tools/qt/include



include(../include/console/console.pri)



SOURCES += \
    src/main.cpp \
    src/other/docsfileinfo.cpp \
    src/other/docsmessageinfo.cpp \
    src/threads/docsworkerthread.cpp \
    src/verifiers/basedocsverifier.cpp \
    src/verifiers/zzz_types/common/linksverifier.cpp \
    src/verifiers/zzz_types/md/mdnewlineverifier.cpp \
    src/verifiers/zzz_types/md/mdspellverifier.cpp \
    src/verifiers/zzz_types/md/mdstructureverifier.cpp

HEADERS += \
    src/other/docsfileinfo.h \
    src/other/docsmessageinfo.h \
    src/other/docsverificationfiletype.h \
    src/threads/docsworkerthread.h \
    src/verifiers/basedocsverifier.h \
    src/verifiers/zzz_types/common/linksverifier.h \
    src/verifiers/zzz_types/md/mdnewlineverifier.h \
    src/verifiers/zzz_types/md/mdspellverifier.h \
    src/verifiers/zzz_types/md/mdstructureverifier.h
