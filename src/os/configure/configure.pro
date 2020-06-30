QT -= gui

CONFIG += c++17

TARGET = configure
TEMPLATE = uefi

RESOURCES += Resources.qrc



DEFINES += \
    BUILD_TARGET_CONFIGURE \
    UEFI_APPLICATION



INCLUDEPATH += \
    ../shared \                # /src/os/shared
    ../include \               # /src/os/include
    ../../../include \         # /include
    ../../../include/stdinc    # /include/stdinc



include(../shared/common/common.pri)
include(../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -pie \
    --no-dynamic-linker \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/com/ngos/configure/b_early/other/pagetable/switchtofivelevelpaging.S \
    asm/arch/x86_64/com/ngos/configure/main.S \
    src/com/ngos/configure/a_uefi/main/exitbootservices.cpp \
    src/com/ngos/configure/a_uefi/main/setupbootparams.cpp \
    src/com/ngos/configure/a_uefi/main/setupkernellocation.cpp \
    src/com/ngos/configure/a_uefi/main/setupmemorymapentries.cpp \
    src/com/ngos/configure/a_uefi/main/setuppciio.cpp \
    src/com/ngos/configure/b_early/main/decompressors/gzip/decompress.cpp \
    src/com/ngos/configure/b_early/main/decompressors/xz/decompress.cpp \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzbcjdecoder.cpp \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzfilterbcj.cpp \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzfilterlzma2.cpp \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzlzma2decoder.cpp \
    src/com/ngos/configure/b_early/main/kernelextraction.cpp \
    src/com/ngos/configure/b_early/main/procesself.cpp \
    src/com/ngos/configure/b_early/main/randomization.cpp \
    src/com/ngos/configure/b_early/other/pagetable/pagetable.cpp \
    src/com/ngos/configure/main.cpp

HEADERS += \
    src/com/ngos/configure/a_uefi/main/exitbootservices.h \
    src/com/ngos/configure/a_uefi/main/setupbootparams.h \
    src/com/ngos/configure/a_uefi/main/setupkernellocation.h \
    src/com/ngos/configure/a_uefi/main/setupmemorymapentries.h \
    src/com/ngos/configure/a_uefi/main/setuppciio.h \
    src/com/ngos/configure/a_uefi/other/pciregisters.h \
    src/com/ngos/configure/b_early/main/decompressors/gzip/decompress.h \
    src/com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipcompressionmethod.h \
    src/com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipmemberextraflags.h \
    src/com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipmemberflags.h \
    src/com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipmemberfooter.h \
    src/com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipmemberheader.h \
    src/com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipoperatingsystem.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/decompress.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2decoder.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2sequence.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmadecoder.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmadictionary.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmalengthdecoder.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmarcdecoder.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmastate.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzbcjdecoder.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzblockflags.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzblockheader.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzbuffer.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzfilter.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzfilterbcj.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzfilterlzma2.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzlzma2decoder.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzstreamflags.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzstreamfooter.h \
    src/com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzstreamheader.h \
    src/com/ngos/configure/b_early/main/procesself.h \
    src/com/ngos/configure/b_early/main/randomization.h \
    src/com/ngos/configure/b_early/other/memoryarea.h \
    src/com/ngos/configure/b_early/other/pagetable/asm_switchtofivelevelpaging.h \
    src/com/ngos/configure/b_early/other/pagetable/pageallocationcontext.h \
    src/com/ngos/configure/b_early/other/pagetable/pagetable.h \
    src/com/ngos/configure/b_early/other/unavailablememoryarea.h \
    src/com/ngos/configure/other/asm/generated/asmoffsets.h \
    src/com/ngos/configure/other/configuredefines.h \
    src/com/ngos/configure/other/kerneldescriptor.h \
    test/com/ngos/configure/sections/section1/com/ngos/configure/types.h \
    test/com/ngos/configure/sections/section1/testcase.h
