#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/checksum/adler.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_checksum_adler);
{
    TEST_CASE("adler32()");
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

        TEST_ASSERT_EQUALS(Adler::adler32((bad_uint8 *)str, strlen(str)),   0x058C01F5);
        TEST_ASSERT_EQUALS(Adler::adler32(temp1,     sizeof(temp1)), 0xB3227F81);
        TEST_ASSERT_EQUALS(Adler::adler32(temp2,     sizeof(temp2)), 0x73227F81);
        TEST_ASSERT_EQUALS(Adler::adler32(temp3,     sizeof(temp3)), 0x56227F81);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H
