#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_UTILS_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_UTILS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_ngos_utils);
{
    TEST_CASE("__ROUND_MASK()");
    {
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 1),      0);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 2),      1);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 4),      3);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 8),      7);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 16),     15);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 32),     31);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 64),     63);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 128),    127);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 256),    255);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 512),    511);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 1024),   1023);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 2048),   2047);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 4096),   4095);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 8192),   8191);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 16384),  16383);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 32678),  32677);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 65536),  65535);
        TEST_ASSERT_EQUALS(__ROUND_MASK(0, 131072), 131071);

        TEST_ASSERT_EQUALS(__ROUND_MASK((i8)0, 1024), -1);
        TEST_ASSERT_EQUALS(__ROUND_MASK((u8)0, 1024), 255);

        TEST_ASSERT_EQUALS(__ROUND_MASK((i8)0, 131072), -1);
        TEST_ASSERT_EQUALS(__ROUND_MASK((u8)0, 131072), 255);

        TEST_ASSERT_EQUALS(__ROUND_MASK((i16)0, 131072), -1);
        TEST_ASSERT_EQUALS(__ROUND_MASK((u16)0, 131072), 65535);
    }
    TEST_CASE_END();



    TEST_CASE("ROUND_UP()");
    {
        TEST_ASSERT_EQUALS(ROUND_UP(0, 4), 0);
        TEST_ASSERT_EQUALS(ROUND_UP(1, 4), 4);
        TEST_ASSERT_EQUALS(ROUND_UP(2, 4), 4);
        TEST_ASSERT_EQUALS(ROUND_UP(3, 4), 4);
        TEST_ASSERT_EQUALS(ROUND_UP(4, 4), 4);
        TEST_ASSERT_EQUALS(ROUND_UP(5, 4), 8);

        TEST_ASSERT_EQUALS(ROUND_UP(0,  8), 0);
        TEST_ASSERT_EQUALS(ROUND_UP(1,  8), 8);
        TEST_ASSERT_EQUALS(ROUND_UP(2,  8), 8);
        TEST_ASSERT_EQUALS(ROUND_UP(10, 8), 16);
        TEST_ASSERT_EQUALS(ROUND_UP(18, 8), 24);
    }
    TEST_CASE_END();



    TEST_CASE("ROUND_DOWN()");
    {
        TEST_ASSERT_EQUALS(ROUND_DOWN(0, 4), 0);
        TEST_ASSERT_EQUALS(ROUND_DOWN(1, 4), 0);
        TEST_ASSERT_EQUALS(ROUND_DOWN(2, 4), 0);
        TEST_ASSERT_EQUALS(ROUND_DOWN(3, 4), 0);
        TEST_ASSERT_EQUALS(ROUND_DOWN(4, 4), 4);
        TEST_ASSERT_EQUALS(ROUND_DOWN(5, 4), 4);

        TEST_ASSERT_EQUALS(ROUND_DOWN(0,  8), 0);
        TEST_ASSERT_EQUALS(ROUND_DOWN(1,  8), 0);
        TEST_ASSERT_EQUALS(ROUND_DOWN(2,  8), 0);
        TEST_ASSERT_EQUALS(ROUND_DOWN(10, 8), 8);
        TEST_ASSERT_EQUALS(ROUND_DOWN(18, 8), 16);
    }
    TEST_CASE_END();



    TEST_CASE("DIV_UP()");
    {
        TEST_ASSERT_EQUALS(DIV_UP(4, 2), 2);
        TEST_ASSERT_EQUALS(DIV_UP(5, 2), 3);
        TEST_ASSERT_EQUALS(DIV_UP(6, 2), 3);

        TEST_ASSERT_EQUALS(DIV_UP(4, 3), 2);
        TEST_ASSERT_EQUALS(DIV_UP(5, 3), 2);
        TEST_ASSERT_EQUALS(DIV_UP(6, 3), 2);
        TEST_ASSERT_EQUALS(DIV_UP(7, 3), 3);
    }
    TEST_CASE_END();



    TEST_CASE("WORD_BIT()");
    {
        TEST_ASSERT_EQUALS(WORD_BIT(0, 0),   0);
        TEST_ASSERT_EQUALS(WORD_BIT(0, 1),   1);
        TEST_ASSERT_EQUALS(WORD_BIT(0, 2),   2);
        TEST_ASSERT_EQUALS(WORD_BIT(0, 31),  31);

        TEST_ASSERT_EQUALS(WORD_BIT(1, 0),   32);
        TEST_ASSERT_EQUALS(WORD_BIT(1, 1),   33);
        TEST_ASSERT_EQUALS(WORD_BIT(1, 2),   34);
        TEST_ASSERT_EQUALS(WORD_BIT(1, 31),  63);

        TEST_ASSERT_EQUALS(WORD_BIT(10, 0),   320);
        TEST_ASSERT_EQUALS(WORD_BIT(10, 1),   321);
        TEST_ASSERT_EQUALS(WORD_BIT(10, 2),   322);
        TEST_ASSERT_EQUALS(WORD_BIT(10, 31),  351);
    }
    TEST_CASE_END();



    TEST_CASE("OFFSET_OF()");
    {
        struct TestStruct
        {
            u8  a;
            u16 b;
            u32 c;
            u64 d;
            u16 e;
            u8  f;
            u64 g;
            u32 h;
        };



        TEST_ASSERT_EQUALS(OFFSET_OF(TestStruct, a), 0);
        TEST_ASSERT_EQUALS(OFFSET_OF(TestStruct, b), 2);
        TEST_ASSERT_EQUALS(OFFSET_OF(TestStruct, c), 4);
        TEST_ASSERT_EQUALS(OFFSET_OF(TestStruct, d), 8);
        TEST_ASSERT_EQUALS(OFFSET_OF(TestStruct, e), 16);
        TEST_ASSERT_EQUALS(OFFSET_OF(TestStruct, f), 18);
        TEST_ASSERT_EQUALS(OFFSET_OF(TestStruct, g), 24);
        TEST_ASSERT_EQUALS(OFFSET_OF(TestStruct, h), 32);
    }
    TEST_CASE_END();



    TEST_CASE("IS_ALIGNED()");
    {
        TEST_ASSERT_EQUALS(IS_ALIGNED(1, 1), true);
        TEST_ASSERT_EQUALS(IS_ALIGNED(2, 1), true);
        TEST_ASSERT_EQUALS(IS_ALIGNED(3, 1), true);
        TEST_ASSERT_EQUALS(IS_ALIGNED(4, 1), true);

        TEST_ASSERT_EQUALS(IS_ALIGNED(1, 2), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(2, 2), true);
        TEST_ASSERT_EQUALS(IS_ALIGNED(3, 2), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(4, 2), true);

        TEST_ASSERT_EQUALS(IS_ALIGNED(1, 4), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(2, 4), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(3, 4), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(4, 4), true);

        TEST_ASSERT_EQUALS(IS_ALIGNED(1,  8), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(2,  8), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(3,  8), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(7,  8), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(8,  8), true);
        TEST_ASSERT_EQUALS(IS_ALIGNED(9,  8), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(10, 8), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(16, 8), true);
        TEST_ASSERT_EQUALS(IS_ALIGNED(23, 8), false);
        TEST_ASSERT_EQUALS(IS_ALIGNED(24, 8), true);
    }
    TEST_CASE_END();



    TEST_CASE("IS_POWER_OF_2()");
    {
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(1),  true);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(2),  true);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(3),  false);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(4),  true);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(5),  false);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(6),  false);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(7),  false);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(8),  true);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(9),  false);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(16), true);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(32), true);
        TEST_ASSERT_EQUALS(IS_POWER_OF_2(64), true);
    }
    TEST_CASE_END();



    TEST_CASE("MIN()");
    {
        TEST_ASSERT_EQUALS(MIN(0, 1),      0);
        TEST_ASSERT_EQUALS(MIN(1, 0),      0);
        TEST_ASSERT_EQUALS(MIN(1, 1),      1);
        TEST_ASSERT_EQUALS(MIN(1000, 5),   5);
        TEST_ASSERT_EQUALS(MIN(3, 2000),   3);
        TEST_ASSERT_EQUALS(MIN(100000, 5), 5);
        TEST_ASSERT_EQUALS(MIN(3, 200000), 3);
    }
    TEST_CASE_END();



    TEST_CASE("MIN_TYPED()");
    {
        TEST_ASSERT_EQUALS(MIN_TYPED(u8, 0,  1),  0);
        TEST_ASSERT_EQUALS(MIN_TYPED(u8, 1,  0),  0);
        TEST_ASSERT_EQUALS(MIN_TYPED(u8, 1,  1),  1);
        TEST_ASSERT_EQUALS(MIN_TYPED(u8, -1, 1),  1);
        TEST_ASSERT_EQUALS(MIN_TYPED(u8, 1,  -1), 1);
        TEST_ASSERT_EQUALS(MIN_TYPED(u8, -1, -1), 255);
        TEST_ASSERT_EQUALS(MIN_TYPED(i8, -1, 1),  -1);
        TEST_ASSERT_EQUALS(MIN_TYPED(i8, 1,  -1), -1);
        TEST_ASSERT_EQUALS(MIN_TYPED(i8, -1, -1), -1);
    }
    TEST_CASE_END();



    TEST_CASE("MAX()");
    {
        TEST_ASSERT_EQUALS(MAX(0, 1),      1);
        TEST_ASSERT_EQUALS(MAX(1, 0),      1);
        TEST_ASSERT_EQUALS(MAX(1, 1),      1);
        TEST_ASSERT_EQUALS(MAX(1000, 5),   1000);
        TEST_ASSERT_EQUALS(MAX(3, 2000),   2000);
        TEST_ASSERT_EQUALS(MAX(100000, 5), 100000);
        TEST_ASSERT_EQUALS(MAX(3, 200000), 200000);
    }
    TEST_CASE_END();



    TEST_CASE("MAX_TYPED()");
    {
        TEST_ASSERT_EQUALS(MAX_TYPED(u8, 0,  1),  1);
        TEST_ASSERT_EQUALS(MAX_TYPED(u8, 1,  0),  1);
        TEST_ASSERT_EQUALS(MAX_TYPED(u8, 1,  1),  1);
        TEST_ASSERT_EQUALS(MAX_TYPED(u8, -1, 1),  255);
        TEST_ASSERT_EQUALS(MAX_TYPED(u8, 1,  -1), 255);
        TEST_ASSERT_EQUALS(MAX_TYPED(u8, -1, -1), 255);
        TEST_ASSERT_EQUALS(MAX_TYPED(i8, -1, 1),  1);
        TEST_ASSERT_EQUALS(MAX_TYPED(i8, 1,  -1), 1);
        TEST_ASSERT_EQUALS(MAX_TYPED(i8, -1, -1), -1);
    }
    TEST_CASE_END();



    TEST_CASE("ABS()");
    {
        TEST_ASSERT_EQUALS(ABS(0),     0);
        TEST_ASSERT_EQUALS(ABS(10),    10);
        TEST_ASSERT_EQUALS(ABS(-5),    5);
        TEST_ASSERT_EQUALS(ABS(5 - 6), 1);
        TEST_ASSERT_EQUALS(ABS(5 - 4), 1);
    }
    TEST_CASE_END();



    TEST_CASE("CLAMP()");
    {
        TEST_ASSERT_EQUALS(CLAMP(0, 0, 5),    0);
        TEST_ASSERT_EQUALS(CLAMP(10, 1, 3),   3);
        TEST_ASSERT_EQUALS(CLAMP(-5, -10, 0), -5);
        TEST_ASSERT_EQUALS(CLAMP(5, 6, 7),    6);
        TEST_ASSERT_EQUALS(CLAMP(5, 3, 4),    4);
    }
    TEST_CASE_END();



    TEST_CASE("htons()");
    {
        TEST_ASSERT_EQUALS(htons(0x01),   0x0100);
        TEST_ASSERT_EQUALS(htons(0x0102), 0x0201);
    }
    TEST_CASE_END();



    TEST_CASE("ntohs()");
    {
        TEST_ASSERT_EQUALS(ntohs(0x01),   0x0100);
        TEST_ASSERT_EQUALS(ntohs(0x0102), 0x0201);
    }
    TEST_CASE_END();



    TEST_CASE("htonl()");
    {
        TEST_ASSERT_EQUALS(htonl(0x01),       0x01000000);
        TEST_ASSERT_EQUALS(htonl(0x01020304), 0x04030201);
    }
    TEST_CASE_END();



    TEST_CASE("ntohl()");
    {
        TEST_ASSERT_EQUALS(ntohl(0x01),       0x01000000);
        TEST_ASSERT_EQUALS(ntohl(0x01020304), 0x04030201);
    }
    TEST_CASE_END();



    TEST_CASE("htonll()");
    {
        TEST_ASSERT_EQUALS(htonll(0x01),               0x0100000000000000);
        TEST_ASSERT_EQUALS(htonll(0x0102030405060708), 0x0807060504030201);
    }
    TEST_CASE_END();



    TEST_CASE("ntohll()");
    {
        TEST_ASSERT_EQUALS(ntohll(0x01),               0x0100000000000000);
        TEST_ASSERT_EQUALS(ntohll(0x0102030405060708), 0x0807060504030201);
    }
    TEST_CASE_END();



    TEST_CASE("clamp()");
    {
        TEST_ASSERT_EQUALS(clamp(0, 0, 5),    0);
        TEST_ASSERT_EQUALS(clamp(10, 1, 3),   3);
        TEST_ASSERT_EQUALS(clamp(-5, -10, 0), -5);
        TEST_ASSERT_EQUALS(clamp(5, 6, 7),    6);
        TEST_ASSERT_EQUALS(clamp(5, 3, 4),    4);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_UTILS_H
