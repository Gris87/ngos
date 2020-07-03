#ifndef CONFIGURE_TEST_COM_NGOS_CONFIGURE_SECTIONS_SECTION1_COM_NGOS_CONFIGURE_TYPES_H
#define CONFIGURE_TEST_COM_NGOS_CONFIGURE_SECTIONS_SECTION1_COM_NGOS_CONFIGURE_TYPES_H



#include <buildconfig.h>
#include <com/ngos/shared/uefibase/testengine.h>

#include "com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipmemberfooter.h"
#include "com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipmemberheader.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2decoder.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmadecoder.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmadictionary.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmalengthdecoder.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmarcdecoder.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzbcjdecoder.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzblockheader.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzbuffer.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzfilter.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzlzma2decoder.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzstreamfooter.h"
#include "com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzstreamheader.h"
#include "com/ngos/configure/b_early/other/memoryarea.h"
#include "com/ngos/configure/b_early/other/pagetable/pageallocationcontext.h"
#include "com/ngos/configure/b_early/other/unavailablememoryarea.h"
#include "com/ngos/configure/other/kerneldescriptor.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_configure_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(KernelDescriptor),      16);
        TEST_ASSERT_EQUALS(sizeof(MemoryArea),            16);
        TEST_ASSERT_EQUALS(sizeof(PageAllocationContext), 24);
        TEST_ASSERT_EQUALS(sizeof(UnavailableMemoryArea), 1);

#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP
        TEST_ASSERT_EQUALS(sizeof(GzipCompressionMethod), 1);
        TEST_ASSERT_EQUALS(sizeof(GzipMemberExtraFlag),   1);
        TEST_ASSERT_EQUALS(sizeof(GzipMemberFlag),        1);
        TEST_ASSERT_EQUALS(sizeof(GzipMemberFooter),      8);
        TEST_ASSERT_EQUALS(sizeof(GzipMemberHeader),      10);
        TEST_ASSERT_EQUALS(sizeof(GzipOperatingSystem),   1);
#endif

#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ
        TEST_ASSERT_EQUALS(sizeof(Lzma2Decoder),      12);
        TEST_ASSERT_EQUALS(sizeof(Lzma2Sequence),     1);
        TEST_ASSERT_EQUALS(sizeof(LzmaDecoder),       28304);
        TEST_ASSERT_EQUALS(sizeof(LzmaDictionary),    56);
        TEST_ASSERT_EQUALS(sizeof(LzmaLengthDecoder), 1028);
        TEST_ASSERT_EQUALS(sizeof(LzmaRcDecoder),     40);
        TEST_ASSERT_EQUALS(sizeof(LzmaState),         1);
        TEST_ASSERT_EQUALS(sizeof(XzBcjDecoder),      4);
        TEST_ASSERT_EQUALS(sizeof(XzBlockFlag),       1);
        TEST_ASSERT_EQUALS(sizeof(XzBlockHeader),     2);
        TEST_ASSERT_EQUALS(sizeof(XzBuffer),          48);
        TEST_ASSERT_EQUALS(sizeof(XzFilter),          24);
        TEST_ASSERT_EQUALS(sizeof(XzLzma2Decoder),    28480);
        TEST_ASSERT_EQUALS(sizeof(XzStreamFlag),      2);
        TEST_ASSERT_EQUALS(sizeof(XzStreamFooter),    12);
        TEST_ASSERT_EQUALS(sizeof(XzStreamHeader),    12);
#endif
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_COM_NGOS_CONFIGURE_SECTIONS_SECTION1_COM_NGOS_CONFIGURE_TYPES_H
