QT -= gui
QT += network

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET   = docs_verifier
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
    src \                                   # tools/qt/docs_verifier/src
    build/gen \                             # tools/qt/docs_verifier/build/gen
    ../../../include \                      # include
    ../../../src/os/shared/common/src \     # src/os/shared/common/src
    ../shared/console/src \                 # tools/qt/shared/console/src
    ../shared/utils/src                     # tools/qt/shared/utils/src



include(../shared/console/console.pri)
include(../shared/utils/utils.pri)



SOURCES += \
    src/com/ngos/devtools/docs_verifier/main.cpp \
    src/com/ngos/devtools/docs_verifier/other/docsfileinfo.cpp \
    src/com/ngos/devtools/docs_verifier/other/docsmessageinfo.cpp \
    src/com/ngos/devtools/docs_verifier/threads/docsworkerthread.cpp \
    src/com/ngos/devtools/docs_verifier/verifiers/basedocsverifier.cpp \
    src/com/ngos/devtools/docs_verifier/verifiers/zzz_types/common/linksverifier.cpp \
    src/com/ngos/devtools/docs_verifier/verifiers/zzz_types/md/mdnewlineverifier.cpp \
    src/com/ngos/devtools/docs_verifier/verifiers/zzz_types/md/mdspellverifier.cpp \
    src/com/ngos/devtools/docs_verifier/verifiers/zzz_types/md/mdstructureverifier.cpp

HEADERS += \
    src/com/ngos/devtools/docs_verifier/other/docsfileinfo.h \
    src/com/ngos/devtools/docs_verifier/other/docsmessageinfo.h \
    src/com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h \
    src/com/ngos/devtools/docs_verifier/threads/docsworkerthread.h \
    src/com/ngos/devtools/docs_verifier/verifiers/basedocsverifier.h \
    src/com/ngos/devtools/docs_verifier/verifiers/zzz_types/common/linksverifier.h \
    src/com/ngos/devtools/docs_verifier/verifiers/zzz_types/md/mdnewlineverifier.h \
    src/com/ngos/devtools/docs_verifier/verifiers/zzz_types/md/mdspellverifier.h \
    src/com/ngos/devtools/docs_verifier/verifiers/zzz_types/md/mdstructureverifier.h
