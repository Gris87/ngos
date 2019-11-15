QT -= gui

CONFIG += c++17

TARGET = cputest
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_CPUTEST \
    UEFI_APPLICATION



INCLUDEPATH += \
    ../../shared \              # /src/os/shared
    ../../include \             # /src/os/include
    ../../../../include \       # /include
    ../../../../include/stdinc  # /include/stdinc



include(../../shared/common/common.pri)
include(../../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/main.S \
    src/bits64/main/cputest.cpp \
    src/bits64/main/cputestgui.cpp \
    src/bits64/tests/testaes.cpp \
    src/bits64/tests/testavx.cpp \
    src/bits64/tests/testavx2.cpp \
    src/bits64/tests/testavx512bw.cpp \
    src/bits64/tests/testavx512cd.cpp \
    src/bits64/tests/testavx512dq.cpp \
    src/bits64/tests/testavx512f.cpp \
    src/bits64/tests/testavx512vl.cpp \
    src/bits64/tests/testbase.cpp \
    src/bits64/tests/testbitwise.cpp \
    src/bits64/tests/testdouble.cpp \
    src/bits64/tests/testfloat.cpp \
    src/bits64/tests/testfma3.cpp \
    src/bits64/tests/testinteger.cpp \
    src/bits64/tests/testlogical.cpp \
    src/bits64/tests/testsse.cpp \
    src/bits64/tests/testsse2.cpp \
    src/bits64/tests/testsse3.cpp \
    src/bits64/tests/testsse41.cpp \
    src/bits64/tests/testsse42.cpp \
    src/main.cpp

HEADERS += \
    src/bits64/main/cputest.h \
    src/bits64/main/cputestgui.h \
    src/bits64/other/cacheinfo.h \
    src/bits64/other/testtype.h \
    src/bits64/tests/testaes.h \
    src/bits64/tests/testavx.h \
    src/bits64/tests/testavx2.h \
    src/bits64/tests/testavx512bw.h \
    src/bits64/tests/testavx512cd.h \
    src/bits64/tests/testavx512dq.h \
    src/bits64/tests/testavx512f.h \
    src/bits64/tests/testavx512vl.h \
    src/bits64/tests/testbase.h \
    src/bits64/tests/testbitwise.h \
    src/bits64/tests/testdouble.h \
    src/bits64/tests/testfloat.h \
    src/bits64/tests/testfma3.h \
    src/bits64/tests/testinteger.h \
    src/bits64/tests/testlogical.h \
    src/bits64/tests/testsse.h \
    src/bits64/tests/testsse2.h \
    src/bits64/tests/testsse3.h \
    src/bits64/tests/testsse41.h \
    src/bits64/tests/testsse42.h \
    test/bits64/sections/section1/bits64/types.h \
    test/bits64/sections/section1/testcase.h
