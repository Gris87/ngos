#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_MD5_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_MD5_H



#include <buildconfig.h>
#include <common/src/bits64/checksum/md5.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_checksum_md5);
{
    TEST_CASE("md5()");
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

        UEFI_LF(("%s", md5HashToString(MD5::md5((u8 *)str, strlen(str)))));
        UEFI_LF(("%s", md5HashToString(MD5::md5(temp1, sizeof(temp1)))));
        UEFI_LF(("%s", md5HashToString(MD5::md5(temp2, sizeof(temp2)))));
        UEFI_LF(("%s", md5HashToString(MD5::md5(temp3, sizeof(temp3)))));

        TEST_ASSERT_EQUALS(MD5::md5((u8 *)str, strlen(str)),   Md5Hash(0x961261C453991A8B, 0xD70478C4F8AB27A8));
        TEST_ASSERT_EQUALS(MD5::md5(temp1,     sizeof(temp1)), Md5Hash(0, 0));
        TEST_ASSERT_EQUALS(MD5::md5(temp2,     sizeof(temp2)), Md5Hash(0, 0));
        TEST_ASSERT_EQUALS(MD5::md5(temp3,     sizeof(temp3)), Md5Hash(0, 0));
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_MD5_H
