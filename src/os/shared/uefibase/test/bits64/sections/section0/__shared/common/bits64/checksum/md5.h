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
        TEST_ASSERT_EQUALS(temp.mCount,    0);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));
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
        TEST_ASSERT_EQUALS(temp.mCount,    0);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));



        u8 temp1[256];

        for (i64 i = 0; i < 256; ++i)
        {
            temp1[i] = i * 37;
        }



        TEST_ASSERT_EQUALS(temp.update(temp1, 13), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount,    104);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));



        TEST_ASSERT_EQUALS(temp.update(temp1, 50), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount,    504);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));



        TEST_ASSERT_EQUALS(temp.update(temp1, 20), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount,    664);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0x0E26E11313CF9EEE, 0x29E232366355CBDC));



        TEST_ASSERT_EQUALS(temp.update(temp1, 58), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount,    1128);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0x09AA1BB06287FA0D, 0x8EA0831A9C8FC204));
    }
    TEST_CASE_END();



    TEST_CASE("finish()/getResult()");
    {
        MD5 temp1;
        MD5 temp2;
        MD5 temp3;

        TEST_ASSERT_EQUALS(temp1.mFinished, false);
        TEST_ASSERT_EQUALS(temp1.mCount,    0);
        TEST_ASSERT_EQUALS(temp1.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));

        TEST_ASSERT_EQUALS(temp2.mFinished, false);
        TEST_ASSERT_EQUALS(temp2.mCount,    0);
        TEST_ASSERT_EQUALS(temp2.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));

        TEST_ASSERT_EQUALS(temp3.mFinished, false);
        TEST_ASSERT_EQUALS(temp3.mCount,    0);
        TEST_ASSERT_EQUALS(temp3.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));



        u8 temp4[256];

        for (i64 i = 0; i < 256; ++i)
        {
            temp4[i] = i * 37;
        }



        TEST_ASSERT_EQUALS(temp2.update(temp4, 13), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp3.update(temp4, 64), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp1.mFinished, false);
        TEST_ASSERT_EQUALS(temp1.mCount,    0);
        TEST_ASSERT_EQUALS(temp1.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));

        TEST_ASSERT_EQUALS(temp2.mFinished, false);
        TEST_ASSERT_EQUALS(temp2.mCount,    104);
        TEST_ASSERT_EQUALS(temp2.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));

        TEST_ASSERT_EQUALS(temp3.mFinished, false);
        TEST_ASSERT_EQUALS(temp3.mCount,    512);
        TEST_ASSERT_EQUALS(temp3.mResult,   Md5Hash(0xA1C439B313DEA70A, 0xE7C23F0DA883BC47));



        TEST_ASSERT_EQUALS(temp1.finish(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp2.finish(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp3.finish(), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp1.mFinished,   true);
        TEST_ASSERT_EQUALS(temp1.mCount,      512);
        TEST_ASSERT_EQUALS(temp1.mResult,     Md5Hash(0x04B2008FD98C1DD4, 0x7E42F8EC980980E9));
        TEST_ASSERT_EQUALS(temp1.getResult(), Md5Hash(0x04B2008FD98C1DD4, 0x7E42F8EC980980E9));

        TEST_ASSERT_EQUALS(temp2.mFinished,   true);
        TEST_ASSERT_EQUALS(temp2.mCount,      512);
        TEST_ASSERT_EQUALS(temp2.mResult,     Md5Hash(0x976F1A7975C0A1BD, 0x9009BED3955516FD));
        TEST_ASSERT_EQUALS(temp2.getResult(), Md5Hash(0x976F1A7975C0A1BD, 0x9009BED3955516FD));

        TEST_ASSERT_EQUALS(temp3.mFinished,   true);
        TEST_ASSERT_EQUALS(temp3.mCount,      1024);
        TEST_ASSERT_EQUALS(temp3.mResult,     Md5Hash(0x4E8998BB171762E9, 0x196CB6E5E52EF93C));
        TEST_ASSERT_EQUALS(temp3.getResult(), Md5Hash(0x4E8998BB171762E9, 0x196CB6E5E52EF93C));
    }
    TEST_CASE_END();



    TEST_CASE("transform()");
    {
        MD5 temp;

        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount,    0);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0xEFCDAB8967452301, 0x1032547698BADCFE));



        u8 temp1[66];

        for (i64 i = 0; i < 66; ++i)
        {
            temp1[i] = i * 37;
        }



        TEST_ASSERT_EQUALS(temp.transform(&temp1[0]), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount,    0);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0xA1C439B313DEA70A, 0xE7C23F0DA883BC47));



        TEST_ASSERT_EQUALS(temp.transform(&temp1[1]), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount,    0);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0x699B9798FE86C99E, 0xD10BF2D30E938E6F));



        TEST_ASSERT_EQUALS(temp.transform(&temp1[2]), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mFinished, false);
        TEST_ASSERT_EQUALS(temp.mCount,    0);
        TEST_ASSERT_EQUALS(temp.mResult,   Md5Hash(0xCDECD650B62D64F2, 0xF992FC281F255FC9));
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CHECKSUM_MD5_H
