#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_MD5_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_MD5_H



#include <buildconfig.h>
#include <common/src/bits64/checksum/md5.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_checksum_md5);
{
    TEST_CASE("MD5()");
    {
        MD5 temp;

        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());
    }
    TEST_CASE_END();



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

        TEST_ASSERT_EQUALS(MD5::md5((u8 *)str, strlen(str)),   Md5Hash(0x961261C453991A8B, 0xD70478C4F8AB27A8));
        TEST_ASSERT_EQUALS(MD5::md5(temp1,     sizeof(temp1)), Md5Hash(0x68CAF689914D9F8B, 0xE29345064F180870));
        TEST_ASSERT_EQUALS(MD5::md5(temp2,     sizeof(temp2)), Md5Hash(0xEA3F9685AC01AD36, 0x4C6A66874E68FCCB));
        TEST_ASSERT_EQUALS(MD5::md5(temp3,     sizeof(temp3)), Md5Hash(0xE021465438334751, 0xCE7E980E9EF122D5));
    }
    TEST_CASE_END();



    TEST_CASE("update()");
    {
        MD5 temp;

        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());



        u8 temp1[256];

        for (i64 i = 0; i < 256; ++i)
        {
            temp1[i] = i * 37;
        }



        TEST_ASSERT_EQUALS(temp.update(temp1, 13), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 104);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());



        TEST_ASSERT_EQUALS(temp.update(temp1, 50), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 504);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());



        TEST_ASSERT_EQUALS(temp.update(temp1, 20), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 664);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0x13CF9EEE);
        TEST_ASSERT_EQUALS(temp.mState[1], 0x0E26E113);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x6355CBDC);
        TEST_ASSERT_EQUALS(temp.mState[3], 0x29E23236);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());



        TEST_ASSERT_EQUALS(temp.update(temp1, 58), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 1128);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0x6287FA0D);
        TEST_ASSERT_EQUALS(temp.mState[1], 0x09AA1BB0);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x9C8FC204);
        TEST_ASSERT_EQUALS(temp.mState[3], 0x8EA0831A);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());
    }
    TEST_CASE_END();



    TEST_CASE("finish()/getResult()");
    {
        MD5 temp1;
        MD5 temp2;
        MD5 temp3;

        TEST_ASSERT_EQUALS(temp1.mFinished, false);
        TEST_ASSERT_EQUALS(temp1.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp1.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp1.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp1.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp1.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp1.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp1.mResult,   Md5Hash());

        TEST_ASSERT_EQUALS(temp2.mFinished, false);
        TEST_ASSERT_EQUALS(temp2.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp2.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp2.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp2.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp2.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp2.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp2.mResult,   Md5Hash());

        TEST_ASSERT_EQUALS(temp3.mFinished, false);
        TEST_ASSERT_EQUALS(temp3.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp3.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp3.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp3.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp3.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp3.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp3.mResult,   Md5Hash());



        u8 temp4[256];

        for (i64 i = 0; i < 256; ++i)
        {
            temp4[i] = i * 37;
        }



        TEST_ASSERT_EQUALS(temp2.update(temp4, 13), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp3.update(temp4, 64), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp1.mFinished, false);
        TEST_ASSERT_EQUALS(temp1.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp1.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp1.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp1.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp1.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp1.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp1.mResult,   Md5Hash());

        TEST_ASSERT_EQUALS(temp2.mFinished, false);
        TEST_ASSERT_EQUALS(temp2.mCount[0], 104);
        TEST_ASSERT_EQUALS(temp2.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp2.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp2.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp2.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp2.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp2.mResult,   Md5Hash());

        TEST_ASSERT_EQUALS(temp3.mFinished, false);
        TEST_ASSERT_EQUALS(temp3.mCount[0], 512);
        TEST_ASSERT_EQUALS(temp3.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp3.mState[0], 0x13DEA70A);
        TEST_ASSERT_EQUALS(temp3.mState[1], 0xA1C439B3);
        TEST_ASSERT_EQUALS(temp3.mState[2], 0xA883BC47);
        TEST_ASSERT_EQUALS(temp3.mState[3], 0xE7C23F0D);
        TEST_ASSERT_EQUALS(temp3.mResult,   Md5Hash());



        TEST_ASSERT_EQUALS(temp1.finish(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp2.finish(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp3.finish(), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp1.mFinished,   true);
        TEST_ASSERT_EQUALS(temp1.mCount[0],   512);
        TEST_ASSERT_EQUALS(temp1.mCount[1],   0);
        TEST_ASSERT_EQUALS(temp1.mState[0],   0xD98C1DD4);
        TEST_ASSERT_EQUALS(temp1.mState[1],   0x04B2008F);
        TEST_ASSERT_EQUALS(temp1.mState[2],   0x980980E9);
        TEST_ASSERT_EQUALS(temp1.mState[3],   0x7E42F8EC);
        TEST_ASSERT_EQUALS(temp1.mResult,     Md5Hash(0x04B2008FD98C1DD4, 0x7E42F8EC980980E9));
        TEST_ASSERT_EQUALS(temp1.getResult(), Md5Hash(0x04B2008FD98C1DD4, 0x7E42F8EC980980E9));

        TEST_ASSERT_EQUALS(temp2.mFinished,   true);
        TEST_ASSERT_EQUALS(temp2.mCount[0],   512);
        TEST_ASSERT_EQUALS(temp2.mCount[1],   0);
        TEST_ASSERT_EQUALS(temp2.mState[0],   0x75C0A1BD);
        TEST_ASSERT_EQUALS(temp2.mState[1],   0x976F1A79);
        TEST_ASSERT_EQUALS(temp2.mState[2],   0x955516FD);
        TEST_ASSERT_EQUALS(temp2.mState[3],   0x9009BED3);
        TEST_ASSERT_EQUALS(temp2.mResult,     Md5Hash(0x976F1A7975C0A1BD, 0x9009BED3955516FD));
        TEST_ASSERT_EQUALS(temp2.getResult(), Md5Hash(0x976F1A7975C0A1BD, 0x9009BED3955516FD));

        TEST_ASSERT_EQUALS(temp3.mFinished,   true);
        TEST_ASSERT_EQUALS(temp3.mCount[0],   1024);
        TEST_ASSERT_EQUALS(temp3.mCount[1],   0);
        TEST_ASSERT_EQUALS(temp3.mState[0],   0x171762E9);
        TEST_ASSERT_EQUALS(temp3.mState[1],   0x4E8998BB);
        TEST_ASSERT_EQUALS(temp3.mState[2],   0xE52EF93C);
        TEST_ASSERT_EQUALS(temp3.mState[3],   0x196CB6E5);
        TEST_ASSERT_EQUALS(temp3.mResult,     Md5Hash(0x4E8998BB171762E9, 0x196CB6E5E52EF93C));
        TEST_ASSERT_EQUALS(temp3.getResult(), Md5Hash(0x4E8998BB171762E9, 0x196CB6E5E52EF93C));
    }
    TEST_CASE_END();



    TEST_CASE("transform()");
    {
        MD5 temp;

        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0x67452301);
        TEST_ASSERT_EQUALS(temp.mState[1], 0xEFCDAB89);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x98BADCFE);
        TEST_ASSERT_EQUALS(temp.mState[3], 0x10325476);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());



        u8 temp1[66];

        for (i64 i = 0; i < 66; ++i)
        {
            temp1[i] = i * 37;
        }



        TEST_ASSERT_EQUALS(temp.transform(&temp1[0]), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0x13DEA70A);
        TEST_ASSERT_EQUALS(temp.mState[1], 0xA1C439B3);
        TEST_ASSERT_EQUALS(temp.mState[2], 0xA883BC47);
        TEST_ASSERT_EQUALS(temp.mState[3], 0xE7C23F0D);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());



        TEST_ASSERT_EQUALS(temp.transform(&temp1[1]), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0xFE86C99E);
        TEST_ASSERT_EQUALS(temp.mState[1], 0x699B9798);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x0E938E6F);
        TEST_ASSERT_EQUALS(temp.mState[3], 0xD10BF2D3);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());



        TEST_ASSERT_EQUALS(temp.transform(&temp1[2]), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount[0], 0);
        TEST_ASSERT_EQUALS(temp.mCount[1], 0);
        TEST_ASSERT_EQUALS(temp.mState[0], 0xB62D64F2);
        TEST_ASSERT_EQUALS(temp.mState[1], 0xCDECD650);
        TEST_ASSERT_EQUALS(temp.mState[2], 0x1F255FC9);
        TEST_ASSERT_EQUALS(temp.mState[3], 0xF992FC28);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash());
    }
    TEST_CASE_END();



    TEST_CASE("decode()");
    {
        u8  a[32] = { 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x40, 0x41 };
        u32 b[8];



        TEST_ASSERT_EQUALS(MD5::decode(a, sizeof(a), b), NgosStatus::OK);



        TEST_ASSERT_EQUALS(b[0], 0x13121110);
        TEST_ASSERT_EQUALS(b[1], 0x17161514);
        TEST_ASSERT_EQUALS(b[2], 0x21201918);
        TEST_ASSERT_EQUALS(b[3], 0x25242322);
        TEST_ASSERT_EQUALS(b[4], 0x29282726);
        TEST_ASSERT_EQUALS(b[5], 0x33323130);
        TEST_ASSERT_EQUALS(b[6], 0x37363534);
        TEST_ASSERT_EQUALS(b[7], 0x41403938);
    }
    TEST_CASE_END();



    TEST_CASE("encode()");
    {
        u8  a[32];
        u32 b[8] = { 0x13121110, 0x17161514, 0x21201918, 0x25242322, 0x29282726, 0x33323130, 0x37363534, 0x41403938 };



        TEST_ASSERT_EQUALS(MD5::encode(b, sizeof(a), a), NgosStatus::OK);



        TEST_ASSERT_EQUALS(a[0],  0x10);
        TEST_ASSERT_EQUALS(a[1],  0x11);
        TEST_ASSERT_EQUALS(a[2],  0x12);
        TEST_ASSERT_EQUALS(a[3],  0x13);
        TEST_ASSERT_EQUALS(a[4],  0x14);
        TEST_ASSERT_EQUALS(a[5],  0x15);
        TEST_ASSERT_EQUALS(a[6],  0x16);
        TEST_ASSERT_EQUALS(a[7],  0x17);
        TEST_ASSERT_EQUALS(a[8],  0x18);
        TEST_ASSERT_EQUALS(a[9],  0x19);
        TEST_ASSERT_EQUALS(a[10], 0x20);
        TEST_ASSERT_EQUALS(a[11], 0x21);
        TEST_ASSERT_EQUALS(a[12], 0x22);
        TEST_ASSERT_EQUALS(a[13], 0x23);
        TEST_ASSERT_EQUALS(a[14], 0x24);
        TEST_ASSERT_EQUALS(a[15], 0x25);
        TEST_ASSERT_EQUALS(a[16], 0x26);
        TEST_ASSERT_EQUALS(a[17], 0x27);
        TEST_ASSERT_EQUALS(a[18], 0x28);
        TEST_ASSERT_EQUALS(a[19], 0x29);
        TEST_ASSERT_EQUALS(a[20], 0x30);
        TEST_ASSERT_EQUALS(a[21], 0x31);
        TEST_ASSERT_EQUALS(a[22], 0x32);
        TEST_ASSERT_EQUALS(a[23], 0x33);
        TEST_ASSERT_EQUALS(a[24], 0x34);
        TEST_ASSERT_EQUALS(a[25], 0x35);
        TEST_ASSERT_EQUALS(a[26], 0x36);
        TEST_ASSERT_EQUALS(a[27], 0x37);
        TEST_ASSERT_EQUALS(a[28], 0x38);
        TEST_ASSERT_EQUALS(a[29], 0x39);
        TEST_ASSERT_EQUALS(a[30], 0x40);
        TEST_ASSERT_EQUALS(a[31], 0x41);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_MD5_H
