QT -= gui

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET   = code_verifier
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
    src \                                   # tools/qt/code_verifier/src
    build/gen \                             # tools/qt/code_verifier/build/gen
    ../../../include \                      # include
    ../../../src/os/shared/common/src \     # src/os/shared/common/src
    ../shared/console/src \                 # tools/qt/shared/console/src
    ../shared/utils/src                     # tools/qt/shared/utils/src



include(../shared/console/console.pri)
include(../shared/utils/utils.pri)



SOURCES += \
    src/com/ngos/devtools/code_verifier/main.cpp \
    src/com/ngos/devtools/code_verifier/other/codefileinfo.cpp \
    src/com/ngos/devtools/code_verifier/other/codemessageinfo.cpp \
    src/com/ngos/devtools/code_verifier/threads/codeworkerthread.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/basecodeverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/asciitextverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/avoidtabsverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/blanklinesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/hexverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/indentspacesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/indenttabsverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/lineseparatorverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/whitespaceverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppalignmentverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cpparrayinitializationverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppblockdefinitionverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppblockorderverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppcommentverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppdefinesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppemptycodeverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppenumverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppequalalignmentverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppexterndeclaredverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppforverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppincludeverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppindentverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppngoslogsverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppngostestverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppngostraceverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppoperatorspacesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cpppowerof2verifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cpppunctuationverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppreleaseusageverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsemicolonverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsinglecharverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsinglelineforverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsinglelineifverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsinglelinewhileverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppstatementspacesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppstaticfunctionsverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppswitchverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cpptypesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/h/cpphdefinesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/includes/qtincludesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpalignmentverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpblockdefinitionverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpemptycodeverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpequalalignmentverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpforverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpindentverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpoperatorspacesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phppunctuationverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpshiftverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpsinglelineforverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpsinglelineifverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpsinglelinewhileverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpstatementspacesverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpswitchverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/pri/qtpriverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/pro/qtproverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/qrc/qtqrcverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/s/asmcommentsverifier.cpp \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/s/asmindentverifier.cpp

HEADERS += \
    src/com/ngos/devtools/code_verifier/other/codefileinfo.h \
    src/com/ngos/devtools/code_verifier/other/codemessageinfo.h \
    src/com/ngos/devtools/code_verifier/other/codeverificationfiletype.h \
    src/com/ngos/devtools/code_verifier/threads/codeworkerthread.h \
    src/com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/asciitextverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/avoidtabsverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/blanklinesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/hexverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/indentspacesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/indenttabsverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/lineseparatorverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/common/whitespaceverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppalignmentverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cpparrayinitializationverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppblockdefinitionverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppblockorderverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppcommentverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppdefinesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppemptycodeverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppenumverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppequalalignmentverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppexterndeclaredverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppforverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppincludeverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppindentverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppngoslogsverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppngostestverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppngostraceverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppoperatorspacesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cpppowerof2verifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cpppunctuationverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppreleaseusageverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsemicolonverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsinglecharverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsinglelineforverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsinglelineifverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppsinglelinewhileverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppstatementspacesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppstaticfunctionsverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppswitchverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cpptypesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/h/cpphdefinesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/includes/qtincludesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpalignmentverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpblockdefinitionverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpemptycodeverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpequalalignmentverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpforverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpindentverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpoperatorspacesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phppunctuationverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpshiftverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpsinglelineforverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpsinglelineifverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpsinglelinewhileverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpstatementspacesverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/php/phpswitchverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/pri/qtpriverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/pro/qtproverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/qrc/qtqrcverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/s/asmcommentsverifier.h \
    src/com/ngos/devtools/code_verifier/verifiers/zzz_types/s/asmindentverifier.h
