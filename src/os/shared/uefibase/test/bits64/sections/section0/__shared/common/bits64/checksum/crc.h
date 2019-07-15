#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_CRC_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_CRC_H



#include <buildconfig.h>
#include <common/src/bits64/checksum/crc.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_checksum_crc);
{
    TEST_CASE("crc32()");
    {
        u8 temp1[256];
        u8 temp2[256];
        u8 temp3[256];

        for (i64 i = 0; i < 256; ++i)
        {
            temp1[i] = i * 37;
            temp2[i] = i * 13;
            temp3[i] = i * 19;
        }

        TEST_ASSERT_EQUALS(Crc::crc32(temp1, sizeof(temp1)), 0);
        TEST_ASSERT_EQUALS(Crc::crc32(temp2, sizeof(temp2)), 0);
        TEST_ASSERT_EQUALS(Crc::crc32(temp3, sizeof(temp3)), 0);
    }
    TEST_CASE_END();



    TEST_CASE("crc64()");
    {
        u8 temp1[256];
        u8 temp2[256];
        u8 temp3[256];

        for (i64 i = 0; i < 256; ++i)
        {
            temp1[i] = i * 37;
            temp2[i] = i * 13;
            temp3[i] = i * 19;
        }

        TEST_ASSERT_EQUALS(Crc::crc64(temp1, sizeof(temp1)), 0);
        TEST_ASSERT_EQUALS(Crc::crc64(temp2, sizeof(temp2)), 0);
        TEST_ASSERT_EQUALS(Crc::crc64(temp3, sizeof(temp3)), 0);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_CRC_H