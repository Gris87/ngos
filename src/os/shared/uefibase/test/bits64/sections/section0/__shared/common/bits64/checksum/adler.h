#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_ADLER_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_ADLER_H



#include <buildconfig.h>
#include <common/src/bits64/checksum/adler.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_checksum_adler);
{
    TEST_CASE("adler32()");
    {
        const char8 *str = "Hello";

        u8 temp1[256];
        u8 temp2[256];
        u8 temp3[256];

        for (i64 i = 0; i < 256; ++i)
        {
            temp1[i] = i * 37;
            temp2[i] = i * 13;
            temp3[i] = i * 19;
        }

        TEST_ASSERT_EQUALS(Adler::adler32((u8 *)str, strlen(str)),   0x058C01F5);
        TEST_ASSERT_EQUALS(Adler::adler32(temp1,     sizeof(temp1)), 0xB3227F81);
        TEST_ASSERT_EQUALS(Adler::adler32(temp2,     sizeof(temp2)), 0x73227F81);
        TEST_ASSERT_EQUALS(Adler::adler32(temp3,     sizeof(temp3)), 0x56227F81);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_ADLER_H
