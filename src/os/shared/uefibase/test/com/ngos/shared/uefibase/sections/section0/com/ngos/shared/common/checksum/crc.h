#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H



#include <buildconfig.h>
#include <com/ngos/shared/common/checksum/crc.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_checksum_crc);
{
    TEST_CASE("crc32()");
    {
        const char8 *str = "Hello";

        bad_uint8 temp1[256];
        bad_uint8 temp2[256];
        bad_uint8 temp3[256];

        for (bad_int64 i = 0; i < 256; ++i)
        {
            temp1[i] = i * 37;
            temp2[i] = i * 13;
            temp3[i] = i * 19;
        }

        TEST_ASSERT_EQUALS(Crc::crc32((bad_uint8 *)str, strlen(str)),   0xF7D18982);
        TEST_ASSERT_EQUALS(Crc::crc32(temp1,     sizeof(temp1)), 0x3BA79CCF);
        TEST_ASSERT_EQUALS(Crc::crc32(temp2,     sizeof(temp2)), 0xA6C977D8);
        TEST_ASSERT_EQUALS(Crc::crc32(temp3,     sizeof(temp3)), 0x981FA0FF);
    }
    TEST_CASE_END();



    TEST_CASE("crc64()");
    {
        const char8 *str = "Hello";

        bad_uint8 temp1[256];
        bad_uint8 temp2[256];
        bad_uint8 temp3[256];

        for (bad_int64 i = 0; i < 256; ++i)
        {
            temp1[i] = i * 37;
            temp2[i] = i * 13;
            temp3[i] = i * 19;
        }

        TEST_ASSERT_EQUALS(Crc::crc64((bad_uint8 *)str, strlen(str)),   0x51CF5C3BC87BACC8);
        TEST_ASSERT_EQUALS(Crc::crc64(temp1,     sizeof(temp1)), 0x795E41105C8EC855);
        TEST_ASSERT_EQUALS(Crc::crc64(temp2,     sizeof(temp2)), 0xC9ABC0CE4C2FEF10);
        TEST_ASSERT_EQUALS(Crc::crc64(temp3,     sizeof(temp3)), 0x7D487F5A6914336D);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H
