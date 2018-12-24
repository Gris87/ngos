#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___INCLUDE_ASM_BITUTILS_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___INCLUDE_ASM_BITUTILS_H



#include <asm/bitutils.h>
#include <buildconfig.h>

#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_asm_bitutils);
{
    TEST_CASE("test()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 100), true);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 87),  false);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 37),  true);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 13),  true);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 204), false);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 123), true);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 67),  false);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 0),   true);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 255), true);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 256), true);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 300), false);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, 301), true);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, temp),              true);
        TEST_ASSERT_EQUALS(BitUtils::test((u8 *)buffer, (temp + 4) & 0xFF), false);
    }
    TEST_CASE_END();



    TEST_CASE("set()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(BitUtils::set((u8 *)buffer, 87),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                        0x984ADBFACEA31913);

        TEST_ASSERT_EQUALS(BitUtils::set((u8 *)buffer, 204), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                        0xEADFACEB00AFDDE7);

        TEST_ASSERT_EQUALS(BitUtils::set((u8 *)buffer, 67),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                        0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(BitUtils::set((u8 *)buffer, 300), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                        0x98313ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(BitUtils::set((u8 *)buffer, (temp + 4) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                                      0x65198732AADCBF9F);
    }
    TEST_CASE_END();



    TEST_CASE("setSafe()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(BitUtils::setSafe((u8 *)buffer, 87),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                            0x984ADBFACEA31913);

        TEST_ASSERT_EQUALS(BitUtils::setSafe((u8 *)buffer, 204), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                            0xEADFACEB00AFDDE7);

        TEST_ASSERT_EQUALS(BitUtils::setSafe((u8 *)buffer, 67),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                            0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(BitUtils::setSafe((u8 *)buffer, 300), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                            0x98313ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(BitUtils::setSafe((u8 *)buffer, (temp + 4) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                                          0x65198732AADCBF9F);
    }
    TEST_CASE_END();



    TEST_CASE("clear()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(BitUtils::clear((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                          0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(BitUtils::clear((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                          0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(BitUtils::clear((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                          0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(BitUtils::clear((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                          0x98310ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(BitUtils::clear((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                        0x2ADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("clear()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(BitUtils::clearSafe((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                              0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(BitUtils::clearSafe((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                              0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(BitUtils::clearSafe((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                              0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(BitUtils::clearSafe((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                              0x98310ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(BitUtils::clearSafe((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                            0x2ADFACEB00AFCDE7);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___INCLUDE_ASM_BITUTILS_H
