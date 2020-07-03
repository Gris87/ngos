#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_ASM_INSTRUCTIONS_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_ASM_INSTRUCTIONS_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/asm/instructions.h>
#include <common/src/com/ngos/shared/common/cpu/cpu.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_asm_instructions);
{
    TEST_CASE("rdrand()");
    {
        if (CPU::hasFlag(X86Feature::RDRAND))
        {
            u64 value1 = 0;
            u64 value2 = 0;
            u64 value3 = 0;

            TEST_ASSERT_EQUALS(rdrand(&value1), NgosStatus::OK);
            TEST_ASSERT_EQUALS(rdrand(&value2), NgosStatus::OK);
            TEST_ASSERT_EQUALS(rdrand(&value3), NgosStatus::OK);

            TEST_ASSERT_NOT_EQUALS(value1, 0);
            TEST_ASSERT_NOT_EQUALS(value2, 0);
            TEST_ASSERT_NOT_EQUALS(value3, 0);

            TEST_ASSERT_NOT_EQUALS(value1, value2);
            TEST_ASSERT_NOT_EQUALS(value1, value3);
            TEST_ASSERT_NOT_EQUALS(value2, value3);
        }
        else
        {
            UEFI_LVV(("X86Feature::RDRAND not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("rdtsc()");
    {
        u64 value1 = rdtsc();
        u64 value2 = rdtsc();
        u64 value3 = rdtsc();

        TEST_ASSERT_NOT_EQUALS(value1, 0);
        TEST_ASSERT_NOT_EQUALS(value2, 0);
        TEST_ASSERT_NOT_EQUALS(value3, 0);

        TEST_ASSERT(value2 > value1);
        TEST_ASSERT(value3 > value2);
    }
    TEST_CASE_END();



    TEST_CASE("bt()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 100), true);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 87),  false);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 37),  true);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 13),  true);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 204), false);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 123), true);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 67),  false);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 0),   true);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 255), true);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 256), true);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 300), false);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, 301), true);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(bt((u8 *)buffer, temp),              true);
        TEST_ASSERT_EQUALS(bt((u8 *)buffer, (temp + 4) & 0xFF), false);
    }
    TEST_CASE_END();



    TEST_CASE("bts()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, 87),  false);
        TEST_ASSERT_EQUALS(buffer[1],              0x984ADBFACEA31913);

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, 204), false);
        TEST_ASSERT_EQUALS(buffer[3],              0xEADFACEB00AFDDE7);

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, 67),  false);
        TEST_ASSERT_EQUALS(buffer[1],              0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, 300), false);
        TEST_ASSERT_EQUALS(buffer[4],              0x98313ADADADADA19);

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, 87),  true);
        TEST_ASSERT_EQUALS(buffer[1],              0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, 204), true);
        TEST_ASSERT_EQUALS(buffer[3],              0xEADFACEB00AFDDE7);

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, 67),  true);
        TEST_ASSERT_EQUALS(buffer[1],              0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, 300), true);
        TEST_ASSERT_EQUALS(buffer[4],              0x98313ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, (temp + 4) & 0xFF), false);
        TEST_ASSERT_EQUALS(buffer[0],                            0x65198732AADCBF9F);

        TEST_ASSERT_EQUALS(bts((u8 *)buffer, (temp + 4) & 0xFF), true);
        TEST_ASSERT_EQUALS(buffer[0],                            0x65198732AADCBF9F);
    }
    TEST_CASE_END();



    TEST_CASE("btsSafe()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, 87),  false);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBFACEA31913);

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, 204), false);
        TEST_ASSERT_EQUALS(buffer[3],                  0xEADFACEB00AFDDE7);

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, 67),  false);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, 300), false);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98313ADADADADA19);

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, 87),  true);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, 204), true);
        TEST_ASSERT_EQUALS(buffer[3],                  0xEADFACEB00AFDDE7);

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, 67),  true);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, 300), true);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98313ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, (temp + 4) & 0xFF), false);
        TEST_ASSERT_EQUALS(buffer[0],                                0x65198732AADCBF9F);

        TEST_ASSERT_EQUALS(btsSafe((u8 *)buffer, (temp + 4) & 0xFF), true);
        TEST_ASSERT_EQUALS(buffer[0],                                0x65198732AADCBF9F);
    }
    TEST_CASE_END();



    TEST_CASE("btsPure()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btsPure((u8 *)buffer, 87),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBFACEA31913);

        TEST_ASSERT_EQUALS(btsPure((u8 *)buffer, 204), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                  0xEADFACEB00AFDDE7);

        TEST_ASSERT_EQUALS(btsPure((u8 *)buffer, 67),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(btsPure((u8 *)buffer, 300), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98313ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btsPure((u8 *)buffer, (temp + 4) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                                0x65198732AADCBF9F);
    }
    TEST_CASE_END();



    TEST_CASE("btsPureSafe()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btsPureSafe((u8 *)buffer, 87),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                      0x984ADBFACEA31913);

        TEST_ASSERT_EQUALS(btsPureSafe((u8 *)buffer, 204), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                      0xEADFACEB00AFDDE7);

        TEST_ASSERT_EQUALS(btsPureSafe((u8 *)buffer, 67),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                      0x984ADBFACEA3191B);

        TEST_ASSERT_EQUALS(btsPureSafe((u8 *)buffer, 300), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                      0x98313ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btsPureSafe((u8 *)buffer, (temp + 4) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                                    0x65198732AADCBF9F);
    }
    TEST_CASE_END();



    TEST_CASE("btr()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, 100), true);
        TEST_ASSERT_EQUALS(buffer[1],              0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, 37),  true);
        TEST_ASSERT_EQUALS(buffer[0],              0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, 255), true);
        TEST_ASSERT_EQUALS(buffer[3],              0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, 301), true);
        TEST_ASSERT_EQUALS(buffer[4],              0x98310ADADADADA19);

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, 100), false);
        TEST_ASSERT_EQUALS(buffer[1],              0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, 37),  false);
        TEST_ASSERT_EQUALS(buffer[0],              0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, 255), false);
        TEST_ASSERT_EQUALS(buffer[3],              0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, 301), false);
        TEST_ASSERT_EQUALS(buffer[4],              0x98310ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, (temp - 1) & 0xFF), true);
        TEST_ASSERT_EQUALS(buffer[3],                            0x2ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btr((u8 *)buffer, (temp - 1) & 0xFF), false);
        TEST_ASSERT_EQUALS(buffer[3],                            0x2ADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("btrSafe()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, 100), true);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, 37),  true);
        TEST_ASSERT_EQUALS(buffer[0],                  0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, 255), true);
        TEST_ASSERT_EQUALS(buffer[3],                  0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, 301), true);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98310ADADADADA19);

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, 100), false);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, 37),  false);
        TEST_ASSERT_EQUALS(buffer[0],                  0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, 255), false);
        TEST_ASSERT_EQUALS(buffer[3],                  0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, 301), false);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98310ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, (temp - 1) & 0xFF), true);
        TEST_ASSERT_EQUALS(buffer[3],                                0x2ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btrSafe((u8 *)buffer, (temp - 1) & 0xFF), false);
        TEST_ASSERT_EQUALS(buffer[3],                                0x2ADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("btrPure()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btrPure((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btrPure((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                  0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btrPure((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                  0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btrPure((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98310ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btrPure((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                0x2ADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("btrPureSafe()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btrPureSafe((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                      0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btrPureSafe((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                      0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btrPureSafe((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                      0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btrPureSafe((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                      0x98310ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btrPureSafe((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                    0x2ADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("btc()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, 100), true);
        TEST_ASSERT_EQUALS(buffer[1],              0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, 100), false);
        TEST_ASSERT_EQUALS(buffer[1],              0x984ADBFACE231913);

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, 37),  true);
        TEST_ASSERT_EQUALS(buffer[0],              0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, 37),  false);
        TEST_ASSERT_EQUALS(buffer[0],              0x65198732AADCBF97);

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, 255), true);
        TEST_ASSERT_EQUALS(buffer[3],              0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, 255), false);
        TEST_ASSERT_EQUALS(buffer[3],              0xEADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, 301), true);
        TEST_ASSERT_EQUALS(buffer[4],              0x98310ADADADADA19);

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, 301), false);
        TEST_ASSERT_EQUALS(buffer[4],              0x98312ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, (temp - 1) & 0xFF), true);
        TEST_ASSERT_EQUALS(buffer[3],                            0xAADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btc((u8 *)buffer, (temp - 1) & 0xFF), false);
        TEST_ASSERT_EQUALS(buffer[3],                            0xEADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("btcSafe()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, 100), true);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, 100), false);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBFACE231913);

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, 37),  true);
        TEST_ASSERT_EQUALS(buffer[0],                  0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, 37),  false);
        TEST_ASSERT_EQUALS(buffer[0],                  0x65198732AADCBF97);

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, 255), true);
        TEST_ASSERT_EQUALS(buffer[3],                  0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, 255), false);
        TEST_ASSERT_EQUALS(buffer[3],                  0xEADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, 301), true);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98310ADADADADA19);

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, 301), false);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98312ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, (temp - 1) & 0xFF), true);
        TEST_ASSERT_EQUALS(buffer[3],                                0xAADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcSafe((u8 *)buffer, (temp - 1) & 0xFF), false);
        TEST_ASSERT_EQUALS(buffer[3],                                0xEADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("btcPure()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                  0x984ADBFACE231913);

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                  0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                  0x65198732AADCBF97);

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                  0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                  0xEADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98310ADADADADA19);

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                  0x98312ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                0xAADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcPure((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                0xEADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("btcPureSafe()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                      0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                      0x984ADBFACE231913);

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                      0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                      0x65198732AADCBF97);

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                      0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                      0xEADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                      0x98310ADADADADA19);

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                      0x98312ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                    0xAADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(btcPureSafe((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                    0xEADFACEB00AFCDE7);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_ASM_INSTRUCTIONS_H
