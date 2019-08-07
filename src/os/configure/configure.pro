QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle
CONFIG -= qt

TARGET = configure.elf
TEMPLATE = app



INCLUDEPATH += \
    ../shared \                # /src/os/shared
    ../include \               # /src/os/include
    ../../../include \         # /include
    ../../../include/stdinc    # /include/stdinc



include(../shared/common/common.pri)
include(../shared/uefibase/uefibase.pri)



QMAKE_LFLAGS += \
    -T linker.ld



SOURCES += \
    asm/arch/x86_64/main.S \
    src/bits64/a_uefi/main/exitbootservices.cpp \
    src/bits64/a_uefi/main/setupbootparams.cpp \
    src/bits64/a_uefi/main/setupkernellocation.cpp \
    src/bits64/a_uefi/main/setupmemorymapentries.cpp \
    src/bits64/a_uefi/main/setuppciio.cpp \
    src/bits64/b_early/main/decompressors/gzip/decompress.cpp \
    src/bits64/b_early/main/decompressors/xz/decompress.cpp \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzbcjdecoder.cpp \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzfilterbcj.cpp \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzfilterlzma2.cpp \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzlzma2decoder.cpp \
    src/bits64/b_early/main/kernelextraction.cpp \
    src/bits64/b_early/main/procesself.cpp \
    src/bits64/b_early/main/randomization.cpp \
    src/bits64/b_early/other/pagetable/pagetable.cpp \
    src/main.cpp

HEADERS += \
    src/bits64/other/configuredefines.h \
    src/bits64/a_uefi/main/exitbootservices.h \
    src/bits64/a_uefi/main/setupbootparams.h \
    src/bits64/a_uefi/main/setupkernellocation.h \
    src/bits64/a_uefi/main/setupmemorymapentries.h \
    src/bits64/a_uefi/main/setuppciio.h \
    src/bits64/a_uefi/other/pciregisters.h \
    src/bits64/b_early/main/decompressors/gzip/decompress.h \
    src/bits64/b_early/main/decompressors/gzip/lib/gzipcompressionmethod.h \
    src/bits64/b_early/main/decompressors/gzip/lib/gzipmemberextraflags.h \
    src/bits64/b_early/main/decompressors/gzip/lib/gzipmemberflags.h \
    src/bits64/b_early/main/decompressors/gzip/lib/gzipmemberfooter.h \
    src/bits64/b_early/main/decompressors/gzip/lib/gzipmemberheader.h \
    src/bits64/b_early/main/decompressors/gzip/lib/gzipoperatingsystem.h \
    src/bits64/b_early/main/decompressors/xz/decompress.h \
    src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzma2.h \
    src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzma2decoder.h \
    src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzma2sequence.h \
    src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmadecoder.h \
    src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmadictionary.h \
    src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmalengthdecoder.h \
    src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmarcdecoder.h \
    src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmastate.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzbcjdecoder.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzblockflags.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzblockheader.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzbuffer.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzfilter.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzfilterbcj.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzfilterlzma2.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzlzma2decoder.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzstreamflags.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzstreamfooter.h \
    src/bits64/b_early/main/decompressors/xz/lib/xz/xzstreamheader.h \
    src/bits64/b_early/main/procesself.h \
    src/bits64/b_early/main/randomization.h \
    src/bits64/b_early/other/memoryarea.h \
    src/bits64/b_early/other/pagetable/asm_switchtofivelevelpaging.h \
    src/bits64/b_early/other/pagetable/pageallocationcontext.h \
    src/bits64/b_early/other/pagetable/pagetable.h \
    src/bits64/b_early/other/unavailablememoryarea.h \
    src/bits64/other/asm/generated/asmoffsets.h \
    src/bits64/other/kerneldescriptor.h \
    test/bits64/a_uefi/sections/section1/bits64/types.h \
    test/bits64/a_uefi/sections/section1/testcase.h
