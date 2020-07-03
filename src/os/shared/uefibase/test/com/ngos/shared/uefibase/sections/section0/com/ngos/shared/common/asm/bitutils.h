#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/asm/bitutils.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_asm_bitutils);
{
    TEST_CASE("CONST_BIT_ADDRESS()");
    {
        u64 buffer = 0x65198732AADCBF97;

        TEST_ASSERT_EQUALS(CONST_BIT_ADDRESS(&buffer, 0),  (u8 *)((u64)&buffer));
        TEST_ASSERT_EQUALS(CONST_BIT_ADDRESS(&buffer, 3),  (u8 *)((u64)&buffer));
        TEST_ASSERT_EQUALS(CONST_BIT_ADDRESS(&buffer, 8),  (u8 *)((u64)&buffer + 1));
        TEST_ASSERT_EQUALS(CONST_BIT_ADDRESS(&buffer, 13), (u8 *)((u64)&buffer + 1));
        TEST_ASSERT_EQUALS(CONST_BIT_ADDRESS(&buffer, 17), (u8 *)((u64)&buffer + 2));
    }
    TEST_CASE_END();



    TEST_CASE("CONST_BIT_IN_U8()");
    {
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(0), 1);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(1), 2);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(2), 4);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(3), 8);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(4), 16);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(5), 32);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(6), 64);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(7), 128);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(8), 1);
        TEST_ASSERT_EQUALS(CONST_BIT_IN_U8(9), 2);
    }
    TEST_CASE_END();



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



    TEST_CASE("clearSafe()");
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



    TEST_CASE("invert()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                           0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                           0x984ADBFACE231913);

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                           0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                           0x65198732AADCBF97);

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                           0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                           0xEADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                           0x98310ADADADADA19);

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                           0x98312ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                         0xAADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(BitUtils::invert((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                         0xEADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("invertSafe()");
    {
        u64 buffer[] = { 0x65198732AADCBF97, 0x984ADBFACE231913, 0xBADBADBADBAD0019, 0xEADFACEB00AFCDE7, 0x98312ADADADADA19 };

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                               0x984ADBEACE231913);

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, 100), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[1],                               0x984ADBFACE231913);

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                               0x65198712AADCBF97);

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, 37),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[0],                               0x65198732AADCBF97);

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                               0x6ADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, 255), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                               0xEADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                               0x98310ADADADADA19);

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, 301), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[4],                               0x98312ADADADADA19);



        u8 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                             0xAADFACEB00AFCDE7);

        TEST_ASSERT_EQUALS(BitUtils::invertSafe((u8 *)buffer, (temp - 1) & 0xFF), NgosStatus::OK);
        TEST_ASSERT_EQUALS(buffer[3],                                             0xEADFACEB00AFCDE7);
    }
    TEST_CASE_END();



    TEST_CASE("findFirstBit16()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit16(0xAB11), 1);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit16(0x1300), 9);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit16(0xDDAC), 3);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit16(0xDDA0), 6);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit16(0xB800), 12);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit16(0x0000), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findFirstBit32()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit32(0x4091AB11), 1);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit32(0x13971300), 9);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit32(0xDDADDDAC), 3);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit32(0xBCDEDDA0), 6);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit32(0x1ABBB800), 12);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit32(0x00000000), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findFirstBit64()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit64(0x134AD0654091AB11), 1);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit64(0x9713298713971300), 9);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit64(0xDADDDAAADDADDDAC), 3);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit64(0x321897ADBCDEDDA0), 6);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit64(0x009813981ABBB800), 12);
        TEST_ASSERT_EQUALS(BitUtils::findFirstBit64(0x0000000000000000), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findFirstZero16()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero16(0xAB11), 2);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero16(0x13FF), 11);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero16(0xDDFF), 10);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero16(0xDDAF), 5);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero16(0xB8FF), 9);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero16(0xFFFF), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findFirstZero32()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero32(0x4091AB11), 2);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero32(0x139713FF), 11);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero32(0xDDADDDFF), 10);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero32(0xBCDEDDAF), 5);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero32(0x1ABBB8FF), 9);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero32(0xFFFFFFFF), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findFirstZero64()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero64(0x134AD0654091AB11), 2);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero64(0x97132987139713FF), 11);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero64(0xDADDDAAADDADDDFF), 10);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero64(0x321897ADBCDEDDAF), 5);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero64(0x009813981ABBB8FF), 9);
        TEST_ASSERT_EQUALS(BitUtils::findFirstZero64(0xFFFFFFFFFFFFFFFF), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findLastBit16()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findLastBit16(0x134A), 13);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit16(0x9713), 16);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit16(0xDADD), 16);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit16(0x3218), 14);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit16(0x0098), 8);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit16(0x0000), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findLastBit32()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findLastBit32(0x134AD065), 29);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit32(0x97132987), 32);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit32(0xDADDDAAA), 32);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit32(0x321897AD), 30);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit32(0x00981398), 24);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit32(0x00000000), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findLastBit64()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findLastBit64(0x134AD0654091AB11), 61);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit64(0x9713298713971300), 64);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit64(0xDADDDAAADDADDDAC), 64);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit64(0x321897ADBCDEDDA0), 62);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit64(0x009813981ABBB800), 56);
        TEST_ASSERT_EQUALS(BitUtils::findLastBit64(0x0000000000000000), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findLastZero16()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findLastZero16(0xFD4A), 10);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero16(0xFFFE), 1);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero16(0xFADD), 11);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero16(0xF218), 12);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero16(0xFF98), 7);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero16(0xFFFF), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findLastZero32()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findLastZero32(0xFD4AD065), 26);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero32(0xFFFE2987), 17);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero32(0xFADDDAAA), 27);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero32(0xF21897AD), 28);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero32(0xFF981398), 23);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero32(0xFFFFFFFF), 0);
    }
    TEST_CASE_END();



    TEST_CASE("findLastZero64()");
    {
        TEST_ASSERT_EQUALS(BitUtils::findLastZero64(0xFD4AD0654091AB11), 58);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero64(0xFFFE298713971300), 49);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero64(0xFADDDAAADDADDDAC), 59);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero64(0xF21897ADBCDEDDA0), 60);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero64(0xFF9813981ABBB800), 55);
        TEST_ASSERT_EQUALS(BitUtils::findLastZero64(0xFFFFFFFFFFFFFFFF), 0);
    }
    TEST_CASE_END();



    TEST_CASE("getCountOrder16()");
    {
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder16(0x8000), 15);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder16(0x8100), 16);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder16(0x0010), 4);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder16(0x0011), 5);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder16(0x0000), -1);
    }
    TEST_CASE_END();



    TEST_CASE("getCountOrder32()");
    {
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder32(0x80000000), 31);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder32(0x81000000), 32);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder32(0x00000010), 4);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder32(0x00000011), 5);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder32(0x00000000), -1);
    }
    TEST_CASE_END();



    TEST_CASE("getCountOrder64()");
    {
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder64(0x8000000000000000), 63);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder64(0x8100000000000000), 64);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder64(0x0000001000000000), 36);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder64(0x0000001100000000), 37);
        TEST_ASSERT_EQUALS(BitUtils::getCountOrder64(0x0000000000000000), -1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H
