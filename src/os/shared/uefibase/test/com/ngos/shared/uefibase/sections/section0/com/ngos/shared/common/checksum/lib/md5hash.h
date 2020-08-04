#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_LIB_MD5HASH_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_LIB_MD5HASH_H



#include <buildconfig.h>
#include <com/ngos/shared/common/checksum/lib/md5hash.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_checksum_lib_md5hash);
{
    TEST_CASE("Md5Hash()");
    {
        u8 bytes[16] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 110, 111, 112, 113, 114, 115, 116 };

        Md5Hash temp1;
        Md5Hash temp2(0x0102030405060708, 0x090A0B0C0D0E0F00);
        Md5Hash temp3(0xAABBCCDDEEFF1122, 0x33445566778899AC);
        Md5Hash temp4(bytes);



        TEST_ASSERT_EQUALS(temp1.quads[0], 0);
        TEST_ASSERT_EQUALS(temp1.quads[1], 0);

        TEST_ASSERT_EQUALS(temp1.dwords[0], 0);
        TEST_ASSERT_EQUALS(temp1.dwords[1], 0);
        TEST_ASSERT_EQUALS(temp1.dwords[2], 0);
        TEST_ASSERT_EQUALS(temp1.dwords[3], 0);

        TEST_ASSERT_EQUALS(temp1.bytes[0],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[1],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[2],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[3],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[4],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[5],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[6],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[7],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[8],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[9],  0);
        TEST_ASSERT_EQUALS(temp1.bytes[10], 0);
        TEST_ASSERT_EQUALS(temp1.bytes[11], 0);
        TEST_ASSERT_EQUALS(temp1.bytes[12], 0);
        TEST_ASSERT_EQUALS(temp1.bytes[13], 0);
        TEST_ASSERT_EQUALS(temp1.bytes[14], 0);
        TEST_ASSERT_EQUALS(temp1.bytes[15], 0);



        TEST_ASSERT_EQUALS(temp2.quads[0], 0x0102030405060708);
        TEST_ASSERT_EQUALS(temp2.quads[1], 0x090A0B0C0D0E0F00);

        TEST_ASSERT_EQUALS(temp2.dwords[0], 0x05060708);
        TEST_ASSERT_EQUALS(temp2.dwords[1], 0x01020304);
        TEST_ASSERT_EQUALS(temp2.dwords[2], 0x0D0E0F00);
        TEST_ASSERT_EQUALS(temp2.dwords[3], 0x090A0B0C);

        TEST_ASSERT_EQUALS(temp2.bytes[0],  0x08);
        TEST_ASSERT_EQUALS(temp2.bytes[1],  0x07);
        TEST_ASSERT_EQUALS(temp2.bytes[2],  0x06);
        TEST_ASSERT_EQUALS(temp2.bytes[3],  0x05);
        TEST_ASSERT_EQUALS(temp2.bytes[4],  0x04);
        TEST_ASSERT_EQUALS(temp2.bytes[5],  0x03);
        TEST_ASSERT_EQUALS(temp2.bytes[6],  0x02);
        TEST_ASSERT_EQUALS(temp2.bytes[7],  0x01);
        TEST_ASSERT_EQUALS(temp2.bytes[8],  0x00);
        TEST_ASSERT_EQUALS(temp2.bytes[9],  0x0F);
        TEST_ASSERT_EQUALS(temp2.bytes[10], 0x0E);
        TEST_ASSERT_EQUALS(temp2.bytes[11], 0x0D);
        TEST_ASSERT_EQUALS(temp2.bytes[12], 0x0C);
        TEST_ASSERT_EQUALS(temp2.bytes[13], 0x0B);
        TEST_ASSERT_EQUALS(temp2.bytes[14], 0x0A);
        TEST_ASSERT_EQUALS(temp2.bytes[15], 0x09);



        TEST_ASSERT_EQUALS(temp3.quads[0], 0xAABBCCDDEEFF1122);
        TEST_ASSERT_EQUALS(temp3.quads[1], 0x33445566778899AC);

        TEST_ASSERT_EQUALS(temp3.dwords[0], 0xEEFF1122);
        TEST_ASSERT_EQUALS(temp3.dwords[1], 0xAABBCCDD);
        TEST_ASSERT_EQUALS(temp3.dwords[2], 0x778899AC);
        TEST_ASSERT_EQUALS(temp3.dwords[3], 0x33445566);

        TEST_ASSERT_EQUALS(temp3.bytes[0],  0x22);
        TEST_ASSERT_EQUALS(temp3.bytes[1],  0x11);
        TEST_ASSERT_EQUALS(temp3.bytes[2],  0xFF);
        TEST_ASSERT_EQUALS(temp3.bytes[3],  0xEE);
        TEST_ASSERT_EQUALS(temp3.bytes[4],  0xDD);
        TEST_ASSERT_EQUALS(temp3.bytes[5],  0xCC);
        TEST_ASSERT_EQUALS(temp3.bytes[6],  0xBB);
        TEST_ASSERT_EQUALS(temp3.bytes[7],  0xAA);
        TEST_ASSERT_EQUALS(temp3.bytes[8],  0xAC);
        TEST_ASSERT_EQUALS(temp3.bytes[9],  0x99);
        TEST_ASSERT_EQUALS(temp3.bytes[10], 0x88);
        TEST_ASSERT_EQUALS(temp3.bytes[11], 0x77);
        TEST_ASSERT_EQUALS(temp3.bytes[12], 0x66);
        TEST_ASSERT_EQUALS(temp3.bytes[13], 0x55);
        TEST_ASSERT_EQUALS(temp3.bytes[14], 0x44);
        TEST_ASSERT_EQUALS(temp3.bytes[15], 0x33);



        TEST_ASSERT_EQUALS(temp4.quads[0], 0x1211100F0E0D0C0B);
        TEST_ASSERT_EQUALS(temp4.quads[1], 0x74737271706F6E13);

        TEST_ASSERT_EQUALS(temp4.dwords[0], 0x0E0D0C0B);
        TEST_ASSERT_EQUALS(temp4.dwords[1], 0x1211100F);
        TEST_ASSERT_EQUALS(temp4.dwords[2], 0x706F6E13);
        TEST_ASSERT_EQUALS(temp4.dwords[3], 0x74737271);

        TEST_ASSERT_EQUALS(temp4.bytes[0],  0x0B);
        TEST_ASSERT_EQUALS(temp4.bytes[1],  0x0C);
        TEST_ASSERT_EQUALS(temp4.bytes[2],  0x0D);
        TEST_ASSERT_EQUALS(temp4.bytes[3],  0x0E);
        TEST_ASSERT_EQUALS(temp4.bytes[4],  0x0F);
        TEST_ASSERT_EQUALS(temp4.bytes[5],  0x10);
        TEST_ASSERT_EQUALS(temp4.bytes[6],  0x11);
        TEST_ASSERT_EQUALS(temp4.bytes[7],  0x12);
        TEST_ASSERT_EQUALS(temp4.bytes[8],  0x13);
        TEST_ASSERT_EQUALS(temp4.bytes[9],  0x6E);
        TEST_ASSERT_EQUALS(temp4.bytes[10], 0x6F);
        TEST_ASSERT_EQUALS(temp4.bytes[11], 0x70);
        TEST_ASSERT_EQUALS(temp4.bytes[12], 0x71);
        TEST_ASSERT_EQUALS(temp4.bytes[13], 0x72);
        TEST_ASSERT_EQUALS(temp4.bytes[14], 0x73);
        TEST_ASSERT_EQUALS(temp4.bytes[15], 0x74);
    }
    TEST_CASE_END();



    TEST_CASE("operator==()");
    {
        TEST_ASSERT_EQUALS(Md5Hash(0x0102030405060708, 0x090A0B0C0D0E0F00) == Md5Hash(0x0102030405060708, 0x090A0B0C0D0E0F00), true);
        TEST_ASSERT_EQUALS(Md5Hash(0xAABBCCDDEEFF1122, 0x33445566778899AC) == Md5Hash(0xAABBCCDDEEFF1122, 0x33445566778899AC), true);

        TEST_ASSERT_EQUALS(Md5Hash(0x0102030405060708, 0x090A0B0C0D0E0F00) == Md5Hash(0xAABBCCDDEEFF1122, 0x33445566778899AC), false);
        TEST_ASSERT_EQUALS(Md5Hash(0xAABBCCDDEEFF1122, 0x33445566778899AC) == Md5Hash(0x0102030405060708, 0x090A0B0C0D0E0F00), false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CHECKSUM_LIB_MD5HASH_H
