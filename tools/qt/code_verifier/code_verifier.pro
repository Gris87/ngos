QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

TARGET = code_verifier
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
    ../../../include/ \     # include/
    ../include/             # tools/qt/include/



include(../include/console/console.pri)



SOURCES += \
    src/main.cpp \
    src/other/codefileinfo.cpp \
    src/other/codemessageinfo.cpp \
    src/threads/codeworkerthread.cpp \
    src/verifiers/basecodeverifier.cpp \
    src/verifiers/zzz_types/common/asciitextverifier.cpp \
    src/verifiers/zzz_types/common/avoidtabsverifier.cpp \
    src/verifiers/zzz_types/common/blanklinesverifier.cpp \
    src/verifiers/zzz_types/common/hexverifier.cpp \
    src/verifiers/zzz_types/common/indentspacesverifier.cpp \
    src/verifiers/zzz_types/common/indenttabsverifier.cpp \
    src/verifiers/zzz_types/common/lineseparatorverifier.cpp \
    src/verifiers/zzz_types/common/whitespaceverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppalignmentverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppblockdefinitionverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppblockorderverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppdefinesverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppemptycodeverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppenumverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppequalalignmentverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppexterndeclaredverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppforverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppincludeverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppindentverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppngoslogsverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppngostestverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppngostraceverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppoperatorspacesverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cpppowerof2verifier.cpp \
    src/verifiers/zzz_types/cpp_h/cpppunctuationverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppreleaseusageverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppshiftverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppsinglecharverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppsinglelineforverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppsinglelineifverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppsinglelinewhileverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppstatementspacesverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppstaticfunctionsverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppswitchverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cpptypesverifier.cpp \
    src/verifiers/zzz_types/cpp_h/cppzeroconditionverifier.cpp \
    src/verifiers/zzz_types/h/cpphdefinesverifier.cpp \
    src/verifiers/zzz_types/includes/qtincludesverifier.cpp \
    src/verifiers/zzz_types/php/phpalignmentverifier.cpp \
    src/verifiers/zzz_types/php/phpblockdefinitionverifier.cpp \
    src/verifiers/zzz_types/php/phpemptycodeverifier.cpp \
    src/verifiers/zzz_types/php/phpequalalignmentverifier.cpp \
    src/verifiers/zzz_types/php/phpforverifier.cpp \
    src/verifiers/zzz_types/php/phpindentverifier.cpp \
    src/verifiers/zzz_types/php/phpoperatorspacesverifier.cpp \
    src/verifiers/zzz_types/php/phppunctuationverifier.cpp \
    src/verifiers/zzz_types/php/phpshiftverifier.cpp \
    src/verifiers/zzz_types/php/phpsinglelineforverifier.cpp \
    src/verifiers/zzz_types/php/phpsinglelineifverifier.cpp \
    src/verifiers/zzz_types/php/phpsinglelinewhileverifier.cpp \
    src/verifiers/zzz_types/php/phpstatementspacesverifier.cpp \
    src/verifiers/zzz_types/php/phpswitchverifier.cpp \
    src/verifiers/zzz_types/pri/qtpriverifier.cpp \
    src/verifiers/zzz_types/pro/qtproverifier.cpp \
    src/verifiers/zzz_types/qrc/qtqrcverifier.cpp \
    src/verifiers/zzz_types/s/asmcommentsverifier.cpp \
    src/verifiers/zzz_types/s/asmindentverifier.cpp

HEADERS += \
    src/other/codefileinfo.h \
    src/other/codemessageinfo.h \
    src/other/codeverificationfiletype.h \
    src/threads/codeworkerthread.h \
    src/verifiers/basecodeverifier.h \
    src/verifiers/zzz_types/common/asciitextverifier.h \
    src/verifiers/zzz_types/common/avoidtabsverifier.h \
    src/verifiers/zzz_types/common/blanklinesverifier.h \
    src/verifiers/zzz_types/common/hexverifier.h \
    src/verifiers/zzz_types/common/indentspacesverifier.h \
    src/verifiers/zzz_types/common/indenttabsverifier.h \
    src/verifiers/zzz_types/common/lineseparatorverifier.h \
    src/verifiers/zzz_types/common/whitespaceverifier.h \
    src/verifiers/zzz_types/cpp_h/cppalignmentverifier.h \
    src/verifiers/zzz_types/cpp_h/cppblockdefinitionverifier.h \
    src/verifiers/zzz_types/cpp_h/cppblockorderverifier.h \
    src/verifiers/zzz_types/cpp_h/cppdefinesverifier.h \
    src/verifiers/zzz_types/cpp_h/cppemptycodeverifier.h \
    src/verifiers/zzz_types/cpp_h/cppenumverifier.h \
    src/verifiers/zzz_types/cpp_h/cppequalalignmentverifier.h \
    src/verifiers/zzz_types/cpp_h/cppexterndeclaredverifier.h \
    src/verifiers/zzz_types/cpp_h/cppforverifier.h \
    src/verifiers/zzz_types/cpp_h/cppincludeverifier.h \
    src/verifiers/zzz_types/cpp_h/cppindentverifier.h \
    src/verifiers/zzz_types/cpp_h/cppngoslogsverifier.h \
    src/verifiers/zzz_types/cpp_h/cppngostestverifier.h \
    src/verifiers/zzz_types/cpp_h/cppngostraceverifier.h \
    src/verifiers/zzz_types/cpp_h/cppoperatorspacesverifier.h \
    src/verifiers/zzz_types/cpp_h/cpppowerof2verifier.h \
    src/verifiers/zzz_types/cpp_h/cpppunctuationverifier.h \
    src/verifiers/zzz_types/cpp_h/cppreleaseusageverifier.h \
    src/verifiers/zzz_types/cpp_h/cppshiftverifier.h \
    src/verifiers/zzz_types/cpp_h/cppsinglecharverifier.h \
    src/verifiers/zzz_types/cpp_h/cppsinglelineforverifier.h \
    src/verifiers/zzz_types/cpp_h/cppsinglelineifverifier.h \
    src/verifiers/zzz_types/cpp_h/cppsinglelinewhileverifier.h \
    src/verifiers/zzz_types/cpp_h/cppstatementspacesverifier.h \
    src/verifiers/zzz_types/cpp_h/cppstaticfunctionsverifier.h \
    src/verifiers/zzz_types/cpp_h/cppswitchverifier.h \
    src/verifiers/zzz_types/cpp_h/cpptypesverifier.h \
    src/verifiers/zzz_types/cpp_h/cppzeroconditionverifier.h \
    src/verifiers/zzz_types/h/cpphdefinesverifier.h \
    src/verifiers/zzz_types/includes/qtincludesverifier.h \
    src/verifiers/zzz_types/php/phpalignmentverifier.h \
    src/verifiers/zzz_types/php/phpblockdefinitionverifier.h \
    src/verifiers/zzz_types/php/phpemptycodeverifier.h \
    src/verifiers/zzz_types/php/phpequalalignmentverifier.h \
    src/verifiers/zzz_types/php/phpforverifier.h \
    src/verifiers/zzz_types/php/phpindentverifier.h \
    src/verifiers/zzz_types/php/phpoperatorspacesverifier.h \
    src/verifiers/zzz_types/php/phppunctuationverifier.h \
    src/verifiers/zzz_types/php/phpshiftverifier.h \
    src/verifiers/zzz_types/php/phpsinglelineforverifier.h \
    src/verifiers/zzz_types/php/phpsinglelineifverifier.h \
    src/verifiers/zzz_types/php/phpsinglelinewhileverifier.h \
    src/verifiers/zzz_types/php/phpstatementspacesverifier.h \
    src/verifiers/zzz_types/php/phpswitchverifier.h \
    src/verifiers/zzz_types/pri/qtpriverifier.h \
    src/verifiers/zzz_types/pro/qtproverifier.h \
    src/verifiers/zzz_types/qrc/qtqrcverifier.h \
    src/verifiers/zzz_types/s/asmcommentsverifier.h \
    src/verifiers/zzz_types/s/asmindentverifier.h
