QT -= gui

CONFIG += c++20

TARGET   = cputest
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_CPUTEST \
    UEFI_APPLICATION



INCLUDEPATH += \
    src \                           # src/os/bootloader_tools/cputest/src
    test \                          # src/os/bootloader_tools/cputest/test
    ../../shared/common/src \       # src/os/shared/common/src
    ../../shared/uefibase/src \     # src/os/shared/uefibase/src
    ../../shared/uefibase/test \    # src/os/shared/uefibase/test
    ../../../../include \           # include
    ../../../../include/stdinc      # include/stdinc



include(../../shared/common/common.pri)
include(../../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/bootloader_tools/cputest/main.S \
    src/com/ngos/bootloader_tools/cputest/main.cpp \
    src/com/ngos/bootloader_tools/cputest/main/cputest.cpp \
    src/com/ngos/bootloader_tools/cputest/main/cputestgui.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testaes.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testavx.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testavx2.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512bw.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512cd.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512dq.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512f.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512vl.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testbase.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testbitwise.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testdouble.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testfloat.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testfma3.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testinteger.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testlogical.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testsse.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testsse2.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testsse3.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testsse41.cpp \
    src/com/ngos/bootloader_tools/cputest/tests/testsse42.cpp

HEADERS += \
    src/com/ngos/bootloader_tools/cputest/main/cputest.h \
    src/com/ngos/bootloader_tools/cputest/main/cputestgui.h \
    src/com/ngos/bootloader_tools/cputest/other/cacheinfo.h \
    src/com/ngos/bootloader_tools/cputest/other/testtype.h \
    src/com/ngos/bootloader_tools/cputest/tests/testaes.h \
    src/com/ngos/bootloader_tools/cputest/tests/testavx.h \
    src/com/ngos/bootloader_tools/cputest/tests/testavx2.h \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512bw.h \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512cd.h \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512dq.h \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512f.h \
    src/com/ngos/bootloader_tools/cputest/tests/testavx512vl.h \
    src/com/ngos/bootloader_tools/cputest/tests/testbase.h \
    src/com/ngos/bootloader_tools/cputest/tests/testbitwise.h \
    src/com/ngos/bootloader_tools/cputest/tests/testdouble.h \
    src/com/ngos/bootloader_tools/cputest/tests/testfloat.h \
    src/com/ngos/bootloader_tools/cputest/tests/testfma3.h \
    src/com/ngos/bootloader_tools/cputest/tests/testinteger.h \
    src/com/ngos/bootloader_tools/cputest/tests/testlogical.h \
    src/com/ngos/bootloader_tools/cputest/tests/testsse.h \
    src/com/ngos/bootloader_tools/cputest/tests/testsse2.h \
    src/com/ngos/bootloader_tools/cputest/tests/testsse3.h \
    src/com/ngos/bootloader_tools/cputest/tests/testsse41.h \
    src/com/ngos/bootloader_tools/cputest/tests/testsse42.h \
    test/com/ngos/bootloader_tools/cputest/sections/section1/com/ngos/bootloader_tools/cputest/types.h \
    test/com/ngos/bootloader_tools/cputest/sections/section1/testcase.h
