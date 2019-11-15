#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CRYPTOGRAPHY_AES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CRYPTOGRAPHY_AES_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/cryptography/aes.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_cryptography_aes);
{
    TEST_CASE("AES()");
    {
        if (CPU::hasFlag(X86Feature::AES))
        {
            AES aes;

            TEST_ASSERT_EQUALS(aes.mExpandKeyFunction,   nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKey,           nullptr);
        }
        else
        {
            UEFI_LVV(("X86Feature::AES not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("setKey()/releaseKey()");
    {
        if (CPU::hasFlag(X86Feature::AES))
        {
            AES aes;

            TEST_ASSERT_EQUALS(aes.mExpandKeyFunction,   nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKey,           nullptr);



            u8 key1[16] = { 3, 1, 9, 4, 6, 8, 9, 2, 3, 7, 9, 1, 6, 7, 9, 1 };
            u8 key2[24] = { 3, 1, 9, 4, 6, 8, 9, 2, 3, 7, 9, 1, 6, 7, 9, 1, 3, 4, 7, 8, 9, 2, 3, 4 };



            TEST_ASSERT_EQUALS(aes.setKey(key1, sizeof(key1)), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mExpandKeyFunction,   nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKey,           nullptr);

            TEST_ASSERT_EQUALS(aes.mEncodeKey[0], 10);



            TEST_ASSERT_EQUALS(aes.releaseKey(), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mExpandKeyFunction,   nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKeyAllocated,      nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKeyAllocated,      nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKey,               nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKey,               nullptr);



            TEST_ASSERT_EQUALS(aes.setKey(key2, sizeof(key2)), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mExpandKeyFunction,   nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKey,           nullptr);

            TEST_ASSERT_EQUALS(aes.mEncodeKey[0], 10);
        }
        else
        {
            UEFI_LVV(("X86Feature::AES not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CPU_CPU_H
