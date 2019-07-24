#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION1_BITS64_TYPES_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION1_BITS64_TYPES_H



#include <buildconfig.h>
#include <common/src/bits64/inflate/inflatecode.h>
#include <common/src/bits64/inflate/inflatedecoder.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/bits64/b_early/main/decompressors/gzip/lib/gzipmemberfooter.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/gzipmemberheader.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/blockheader.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/filter.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzma2decoder.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmadecoder.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmadictionary.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmalengthdecoder.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/lzma2/lzmarcdecoder.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/streamfooter.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/streamheader.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzbcjdecoder.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzbuffer.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzlzma2decoder.h"
#include "src/bits64/b_early/other/memoryarea.h"
#include "src/bits64/b_early/other/pagetable/pageallocationcontext.h"
#include "src/bits64/other/kerneldescriptor.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_types);
{
    TEST_CASE("Size of structures");
    {
#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP
        TEST_ASSERT_EQUALS(sizeof(InflateCode), 4);

        TEST_ASSERT_EQUALS(sizeof(InflateDecoder), 40);

        TEST_ASSERT_EQUALS(sizeof(GzipMemberFooter), 8);

        TEST_ASSERT_EQUALS(sizeof(GzipMemberHeader), 10);
#endif



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ
        TEST_ASSERT_EQUALS(sizeof(BlockHeader), 2);

        TEST_ASSERT_EQUALS(sizeof(Filter), 24);

        TEST_ASSERT_EQUALS(sizeof(Lzma2Decoder), 12);

        TEST_ASSERT_EQUALS(sizeof(LzmaDecoder), 28304);

        TEST_ASSERT_EQUALS(sizeof(LzmaDictionary), 56);

        TEST_ASSERT_EQUALS(sizeof(LzmaLengthDecoder), 1028);

        TEST_ASSERT_EQUALS(sizeof(LzmaRcDecoder), 40);

        TEST_ASSERT_EQUALS(sizeof(StreamFooter), 12);

        TEST_ASSERT_EQUALS(sizeof(StreamHeader), 12);

        TEST_ASSERT_EQUALS(sizeof(XzBcjDecoder), 4);

        TEST_ASSERT_EQUALS(sizeof(XzBuffer), 48);

        TEST_ASSERT_EQUALS(sizeof(XzLzma2Decoder), 28480);
#endif



        TEST_ASSERT_EQUALS(sizeof(MemoryArea), 16);

        TEST_ASSERT_EQUALS(sizeof(PageAllocationContext), 24);

        TEST_ASSERT_EQUALS(sizeof(KernelDescriptor), 16);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION1_BITS64_TYPES_H
