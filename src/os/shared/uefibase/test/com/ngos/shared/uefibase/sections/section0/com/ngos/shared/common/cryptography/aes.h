#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/checksum/adler.h>
#include <common/src/com/ngos/shared/common/checksum/crc.h>
#include <common/src/com/ngos/shared/common/checksum/md5.h>
#include <common/src/com/ngos/shared/common/cpu/cpu.h>
#include <common/src/com/ngos/shared/common/cryptography/aes.h>
#include <common/src/com/ngos/shared/common/memory/malloc.h>
#include <common/src/com/ngos/shared/common/memory/memory.h>
#include <common/src/com/ngos/shared/common/string/string.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_cryptography_aes);
{
    TEST_CASE("AES()");
    {
        if (CPU::hasFlag(X86Feature::AES))
        {
            AES aes;

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

            TEST_ASSERT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKey,           nullptr);



            u8 key16[16] = { 3, 1, 9, 4, 6, 8, 9, 2, 3, 7, 9, 1, 6, 7, 9, 1 };
            u8 key24[24] = { 3, 1, 9, 4, 6, 8, 9, 2, 3, 7, 9, 1, 6, 7, 9, 1, 3, 4, 7, 8, 9, 2, 3, 4 };
            u8 key32[32] = { 3, 1, 9, 4, 6, 8, 9, 2, 3, 7, 9, 1, 6, 7, 9, 1, 3, 4, 7, 8, 9, 2, 3, 4, 3, 4, 7, 8, 9, 2, 3, 4 };



            TEST_ASSERT_EQUALS(aes.setKey(key16, sizeof(key16)), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKey,           nullptr);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 11 * 16), 0x98C94D76);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     11 * 16), 0x0495671B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     11 * 16), 0xAA263E486D960ACD);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       11 * 16), Md5Hash(0x22BD8D8930A3C4DE, 0x939E6E4870ADDE14));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 11 * 16), 0xB5635614);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     11 * 16), 0xC4C8131C);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     11 * 16), 0xF4C91CB7B40C7925);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       11 * 16), Md5Hash(0x152CEB119DAFA637, 0xD250D862DBDEFC9D));



            TEST_ASSERT_EQUALS(aes.releaseKey(), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKeyAllocated,      nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKeyAllocated,      nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKey,               nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKey,               nullptr);



            TEST_ASSERT_EQUALS(aes.setKey(key24, sizeof(key24)), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKey,           nullptr);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 13 * 16), 0xAEAA587C);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     13 * 16), 0xDA69EE0E);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     13 * 16), 0xAA956958D3E85FAD);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       13 * 16), Md5Hash(0xBD9117A66B49132E, 0x8B684C3733A38E37));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 13 * 16), 0x05505C78);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     13 * 16), 0x0D554BB2);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     13 * 16), 0x98F4BE8CB01C793B);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       13 * 16), Md5Hash(0x6202BFDFF0F08B2A, 0x8202E5D3C1C6D7C0));



            TEST_ASSERT_EQUALS(aes.releaseKey(), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKeyAllocated,      nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKeyAllocated,      nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKey,               nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKey,               nullptr);



            TEST_ASSERT_EQUALS(aes.setKey(key32, sizeof(key32)), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKey,           nullptr);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 15 * 16), 0x2DA4612C);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     15 * 16), 0x4EBCB0FB);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     15 * 16), 0xE076BD5EE0F7DF77);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       15 * 16), Md5Hash(0x3B9102904F2F836E, 0xA3493207A5791FB4));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 15 * 16), 0x7C186DA0);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     15 * 16), 0x3FDADD3E);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     15 * 16), 0x321FE632D2A16B24);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       15 * 16), Md5Hash(0xF3B30806DB05973B, 0x5044BEC4E1DCB262));
        }
        else
        {
            UEFI_LVV(("X86Feature::AES not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("encode()");
    {
        if (CPU::hasFlag(X86Feature::AES))
        {
            AES aes;

            const char8 *key16 = "NGOS is the best";
            const char8 *key24 = "NGOS is the best OS ever";
            const char8 *key32 = "NGOS is the best OS ever !!!!!!!";

            TEST_ASSERT_EQUALS(strlen(key16), 16);
            TEST_ASSERT_EQUALS(strlen(key24), 24);
            TEST_ASSERT_EQUALS(strlen(key32), 32);



            u8  in[16] __attribute__((aligned(16)));
            u64 inSize;
            u8  out[16] __attribute__((aligned(16)));
            u64 outSize;



            in[0]  = 'H';
            in[1]  = 'e';
            in[2]  = 'l';
            in[3]  = 'l';
            in[4]  = 'o';
            in[5]  = 0;
            inSize = 5;



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key16, strlen(key16)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 11 * 16), 0x5C545A98);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     11 * 16), 0xE5F76028);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     11 * 16), 0xC172975B03490927);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       11 * 16), Md5Hash(0x0EB7F80E6350F4EC, 0x2C03CB2F2CEBA577));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 11 * 16), 0xE613559E);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     11 * 16), 0x6F98A19E);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     11 * 16), 0xB1E3801C9D9249A0);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       11 * 16), Md5Hash(0x0BEBD7D3B1AFDD78, 0x869209C8940EDC53));



            TEST_ASSERT_EQUALS(aes.encode(in, inSize, out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 16);
            TEST_ASSERT_EQUALS(out[0],  0x88);
            TEST_ASSERT_EQUALS(out[1],  0x10);
            TEST_ASSERT_EQUALS(out[2],  0x31);
            TEST_ASSERT_EQUALS(out[3],  0x80);
            TEST_ASSERT_EQUALS(out[4],  0xE2);
            TEST_ASSERT_EQUALS(out[5],  0x9E);
            TEST_ASSERT_EQUALS(out[6],  0xCD);
            TEST_ASSERT_EQUALS(out[7],  0x89);
            TEST_ASSERT_EQUALS(out[8],  0x28);
            TEST_ASSERT_EQUALS(out[9],  0x33);
            TEST_ASSERT_EQUALS(out[10], 0x85);
            TEST_ASSERT_EQUALS(out[11], 0xC6);
            TEST_ASSERT_EQUALS(out[12], 0xDC);
            TEST_ASSERT_EQUALS(out[13], 0xC0);
            TEST_ASSERT_EQUALS(out[14], 0xB8);
            TEST_ASSERT_EQUALS(out[15], 0xB0);



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key24, strlen(key24)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 13 * 16), 0xA9345D34);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     13 * 16), 0xA6ABF5AF);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     13 * 16), 0x2D83EF2BAC5302FD);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       13 * 16), Md5Hash(0xD9D0B897B9857F3E, 0x9698542CAB8C71E5));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 13 * 16), 0x069D64BA);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     13 * 16), 0xA46830FD);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     13 * 16), 0x6B6E204D03AB08EC);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       13 * 16), Md5Hash(0x2A4A2B867F6D6348, 0x9BA73FFF38F4A186));



            TEST_ASSERT_EQUALS(aes.encode(in, inSize, out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 16);
            TEST_ASSERT_EQUALS(out[0],  0x2F);
            TEST_ASSERT_EQUALS(out[1],  0xD0);
            TEST_ASSERT_EQUALS(out[2],  0x6A);
            TEST_ASSERT_EQUALS(out[3],  0x96);
            TEST_ASSERT_EQUALS(out[4],  0xEA);
            TEST_ASSERT_EQUALS(out[5],  0x2A);
            TEST_ASSERT_EQUALS(out[6],  0xF4);
            TEST_ASSERT_EQUALS(out[7],  0xAE);
            TEST_ASSERT_EQUALS(out[8],  0x34);
            TEST_ASSERT_EQUALS(out[9],  0xCC);
            TEST_ASSERT_EQUALS(out[10], 0x59);
            TEST_ASSERT_EQUALS(out[11], 0x69);
            TEST_ASSERT_EQUALS(out[12], 0x4B);
            TEST_ASSERT_EQUALS(out[13], 0x50);
            TEST_ASSERT_EQUALS(out[14], 0xAC);
            TEST_ASSERT_EQUALS(out[15], 0xB0);



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key32, strlen(key32)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 15 * 16), 0x629D6DB5);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     15 * 16), 0xD9A5C95B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     15 * 16), 0x642CBC3BEEBFBA69);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       15 * 16), Md5Hash(0x54593CE37EFC37C6, 0xDBD85BC517C940D3));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 15 * 16), 0x7D687607);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     15 * 16), 0x701A88A1);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     15 * 16), 0x1FE81C032BFC3548);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       15 * 16), Md5Hash(0x3307EC988BACCCF4, 0xB3B524FFBAFEC9D2));



            TEST_ASSERT_EQUALS(aes.encode(in, inSize, out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 16);
            TEST_ASSERT_EQUALS(out[0],  0x93);
            TEST_ASSERT_EQUALS(out[1],  0xAB);
            TEST_ASSERT_EQUALS(out[2],  0x63);
            TEST_ASSERT_EQUALS(out[3],  0x70);
            TEST_ASSERT_EQUALS(out[4],  0xC5);
            TEST_ASSERT_EQUALS(out[5],  0x68);
            TEST_ASSERT_EQUALS(out[6],  0x33);
            TEST_ASSERT_EQUALS(out[7],  0x81);
            TEST_ASSERT_EQUALS(out[8],  0x71);
            TEST_ASSERT_EQUALS(out[9],  0x7B);
            TEST_ASSERT_EQUALS(out[10], 0x90);
            TEST_ASSERT_EQUALS(out[11], 0x63);
            TEST_ASSERT_EQUALS(out[12], 0x64);
            TEST_ASSERT_EQUALS(out[13], 0xFF);
            TEST_ASSERT_EQUALS(out[14], 0x11);
            TEST_ASSERT_EQUALS(out[15], 0x27);
        }
        else
        {
            UEFI_LVV(("X86Feature::AES not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("decode()");
    {
        if (CPU::hasFlag(X86Feature::AES))
        {
            AES aes;

            const char8 *key16 = "NGOS is the best";
            const char8 *key24 = "NGOS is the best OS ever";
            const char8 *key32 = "NGOS is the best OS ever !!!!!!!";

            TEST_ASSERT_EQUALS(strlen(key16), 16);
            TEST_ASSERT_EQUALS(strlen(key24), 24);
            TEST_ASSERT_EQUALS(strlen(key32), 32);



            u8 in1[16] __attribute__((aligned(16))) = { 0x88, 0x10, 0x31, 0x80, 0xE2, 0x9E, 0xCD, 0x89, 0x28, 0x33, 0x85, 0xC6, 0xDC, 0xC0, 0xB8, 0xB0 };
            u8 in2[16] __attribute__((aligned(16))) = { 0x2F, 0xD0, 0x6A, 0x96, 0xEA, 0x2A, 0xF4, 0xAE, 0x34, 0xCC, 0x59, 0x69, 0x4B, 0x50, 0xAC, 0xB0 };
            u8 in3[16] __attribute__((aligned(16))) = { 0x93, 0xAB, 0x63, 0x70, 0xC5, 0x68, 0x33, 0x81, 0x71, 0x7B, 0x90, 0x63, 0x64, 0xFF, 0x11, 0x27 };

            u8  out[16] __attribute__((aligned(16)));
            u64 outSize;



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key16, strlen(key16)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 11 * 16), 0x5C545A98);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     11 * 16), 0xE5F76028);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     11 * 16), 0xC172975B03490927);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       11 * 16), Md5Hash(0x0EB7F80E6350F4EC, 0x2C03CB2F2CEBA577));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 11 * 16), 0xE613559E);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     11 * 16), 0x6F98A19E);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     11 * 16), 0xB1E3801C9D9249A0);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       11 * 16), Md5Hash(0x0BEBD7D3B1AFDD78, 0x869209C8940EDC53));



            TEST_ASSERT_EQUALS(aes.decode(in1, 16, out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 16);
            TEST_ASSERT_EQUALS(out[0],  'H');
            TEST_ASSERT_EQUALS(out[1],  'e');
            TEST_ASSERT_EQUALS(out[2],  'l');
            TEST_ASSERT_EQUALS(out[3],  'l');
            TEST_ASSERT_EQUALS(out[4],  'o');
            TEST_ASSERT_EQUALS(out[5],  0);
            TEST_ASSERT_EQUALS(out[6],  0);
            TEST_ASSERT_EQUALS(out[7],  0);
            TEST_ASSERT_EQUALS(out[8],  0);
            TEST_ASSERT_EQUALS(out[9],  0);
            TEST_ASSERT_EQUALS(out[10], 0);
            TEST_ASSERT_EQUALS(out[11], 0);
            TEST_ASSERT_EQUALS(out[12], 0);
            TEST_ASSERT_EQUALS(out[13], 0);
            TEST_ASSERT_EQUALS(out[14], 0);
            TEST_ASSERT_EQUALS(out[15], 0);



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key24, strlen(key24)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 13 * 16), 0xA9345D34);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     13 * 16), 0xA6ABF5AF);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     13 * 16), 0x2D83EF2BAC5302FD);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       13 * 16), Md5Hash(0xD9D0B897B9857F3E, 0x9698542CAB8C71E5));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 13 * 16), 0x069D64BA);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     13 * 16), 0xA46830FD);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     13 * 16), 0x6B6E204D03AB08EC);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       13 * 16), Md5Hash(0x2A4A2B867F6D6348, 0x9BA73FFF38F4A186));



            TEST_ASSERT_EQUALS(aes.decode(in2, 16, out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 16);
            TEST_ASSERT_EQUALS(out[0],  'H');
            TEST_ASSERT_EQUALS(out[1],  'e');
            TEST_ASSERT_EQUALS(out[2],  'l');
            TEST_ASSERT_EQUALS(out[3],  'l');
            TEST_ASSERT_EQUALS(out[4],  'o');
            TEST_ASSERT_EQUALS(out[5],  0);
            TEST_ASSERT_EQUALS(out[6],  0);
            TEST_ASSERT_EQUALS(out[7],  0);
            TEST_ASSERT_EQUALS(out[8],  0);
            TEST_ASSERT_EQUALS(out[9],  0);
            TEST_ASSERT_EQUALS(out[10], 0);
            TEST_ASSERT_EQUALS(out[11], 0);
            TEST_ASSERT_EQUALS(out[12], 0);
            TEST_ASSERT_EQUALS(out[13], 0);
            TEST_ASSERT_EQUALS(out[14], 0);
            TEST_ASSERT_EQUALS(out[15], 0);



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key32, strlen(key32)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 15 * 16), 0x629D6DB5);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     15 * 16), 0xD9A5C95B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     15 * 16), 0x642CBC3BEEBFBA69);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       15 * 16), Md5Hash(0x54593CE37EFC37C6, 0xDBD85BC517C940D3));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 15 * 16), 0x7D687607);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     15 * 16), 0x701A88A1);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     15 * 16), 0x1FE81C032BFC3548);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       15 * 16), Md5Hash(0x3307EC988BACCCF4, 0xB3B524FFBAFEC9D2));



            TEST_ASSERT_EQUALS(aes.decode(in3, 16, out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 16);
            TEST_ASSERT_EQUALS(out[0],  'H');
            TEST_ASSERT_EQUALS(out[1],  'e');
            TEST_ASSERT_EQUALS(out[2],  'l');
            TEST_ASSERT_EQUALS(out[3],  'l');
            TEST_ASSERT_EQUALS(out[4],  'o');
            TEST_ASSERT_EQUALS(out[5],  0);
            TEST_ASSERT_EQUALS(out[6],  0);
            TEST_ASSERT_EQUALS(out[7],  0);
            TEST_ASSERT_EQUALS(out[8],  0);
            TEST_ASSERT_EQUALS(out[9],  0);
            TEST_ASSERT_EQUALS(out[10], 0);
            TEST_ASSERT_EQUALS(out[11], 0);
            TEST_ASSERT_EQUALS(out[12], 0);
            TEST_ASSERT_EQUALS(out[13], 0);
            TEST_ASSERT_EQUALS(out[14], 0);
            TEST_ASSERT_EQUALS(out[15], 0);
        }
        else
        {
            UEFI_LVV(("X86Feature::AES not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("encode()/decode(). Huge data");
    {
        if (CPU::hasFlag(X86Feature::AES))
        {
            AES aes;

            const char8 *key16 = "My dear password";
            const char8 *key24 = "My dear password. Don't ";
            const char8 *key32 = "My dear password. Don't touch it";

            TEST_ASSERT_EQUALS(strlen(key16), 16);
            TEST_ASSERT_EQUALS(strlen(key24), 24);
            TEST_ASSERT_EQUALS(strlen(key32), 32);



            u8 in1[1024] __attribute__((aligned(16)));
            u8 in2[1021] __attribute__((aligned(16)));

            u8  out[1024] __attribute__((aligned(16)));
            u64 outSize;



            memzero(in1, sizeof(in1));

            for (i64 i = 0; i < (i64)sizeof(in2); ++i)
            {
                in2[i] = i;
            }

            TEST_ASSERT_EQUALS(Adler::adler32(in1, sizeof(in1)), 0x04000001);
            TEST_ASSERT_EQUALS(Crc::crc32(in1,     sizeof(in1)), 0xEFB5AF2E);
            TEST_ASSERT_EQUALS(Crc::crc64(in1,     sizeof(in1)), 0xC37863972069270C);
            TEST_ASSERT_EQUALS(MD5::md5(in1,       sizeof(in1)), Md5Hash(0x206A1231093B340F, 0x3B8A012B7CD633F1));

            TEST_ASSERT_EQUALS(Adler::adler32(in2, sizeof(in2)), 0xED68FB16);
            TEST_ASSERT_EQUALS(Crc::crc32(in2,     sizeof(in2)), 0xB02C88C3);
            TEST_ASSERT_EQUALS(Crc::crc64(in2,     sizeof(in2)), 0xD48B50F4AEA8861E);
            TEST_ASSERT_EQUALS(MD5::md5(in2,       sizeof(in2)), Md5Hash(0xC98DADC0305B4A9D, 0xF1622901D278C2D3));



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key16, strlen(key16)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 11 * 16), 0x83F04CEB);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     11 * 16), 0xAA4FEC5B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     11 * 16), 0xFF7AD7EC97BE945E);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       11 * 16), Md5Hash(0x65D6157850007260, 0x51B3416E46443988));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 11 * 16), 0x270154F9);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     11 * 16), 0x67C493F8);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     11 * 16), 0x117874F11820B404);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       11 * 16), Md5Hash(0x974F07476FCE564C, 0xB550BC83C3A0442B));



            TEST_ASSERT_EQUALS(aes.encode(in1, sizeof(in1), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(out)), 0x79CFE010);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(out)), 0x29C10B16);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(out)), 0xDF44F11A5775710B);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(out)), Md5Hash(0x48F1A963D4489632, 0x4C45775772CAA0F9));



            TEST_ASSERT_EQUALS(aes.decode(out, sizeof(out), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(in1)), 0x04000001);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(in1)), 0xEFB5AF2E);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(in1)), 0xC37863972069270C);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(in1)), Md5Hash(0x206A1231093B340F, 0x3B8A012B7CD633F1));



            TEST_ASSERT_EQUALS(aes.encode(in2, sizeof(in2), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(out)), 0xC4B3F413);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(out)), 0x0D272E99);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(out)), 0x5C47870B657D6457);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(out)), Md5Hash(0x737DDBB38D05E8B7, 0x1AAD0DA1F50CC84B));



            TEST_ASSERT_EQUALS(aes.decode(out, sizeof(out), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(in2)), 0xED68FB16);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(in2)), 0xB02C88C3);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(in2)), 0xD48B50F4AEA8861E);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(in2)), Md5Hash(0xC98DADC0305B4A9D, 0xF1622901D278C2D3));



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key24, strlen(key24)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 13 * 16), 0xD48767CA);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     13 * 16), 0x59253515);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     13 * 16), 0x408DB89C7B6580BB);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       13 * 16), Md5Hash(0x4A6631D2919DE41F, 0x7AD4844F2E801AD2));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 13 * 16), 0x09796A2E);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     13 * 16), 0xADC7B273);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     13 * 16), 0x3173486106C406BE);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       13 * 16), Md5Hash(0xA100C88D79338823, 0x09216994C7140985));



            TEST_ASSERT_EQUALS(aes.encode(in1, sizeof(in1), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(out)), 0xFDC367DF);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(out)), 0x7C6BCE5E);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(out)), 0xDCAC84C2AC7D4534);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(out)), Md5Hash(0x43E20F001ADEBA15, 0x3B246605611C3CDF));



            TEST_ASSERT_EQUALS(aes.decode(out, sizeof(out), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(in1)), 0x04000001);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(in1)), 0xEFB5AF2E);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(in1)), 0xC37863972069270C);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(in1)), Md5Hash(0x206A1231093B340F, 0x3B8A012B7CD633F1));



            TEST_ASSERT_EQUALS(aes.encode(in2, sizeof(in2), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(out)), 0x4BDDF59E);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(out)), 0xC201D676);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(out)), 0x543E6CD575B19B5D);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(out)), Md5Hash(0x591370C08768A9A2, 0xE5B9090B68F362F1));



            TEST_ASSERT_EQUALS(aes.decode(out, sizeof(out), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(in2)), 0xED68FB16);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(in2)), 0xB02C88C3);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(in2)), 0xD48B50F4AEA8861E);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(in2)), Md5Hash(0xC98DADC0305B4A9D, 0xF1622901D278C2D3));



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key32, strlen(key32)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mEncodeKey, 15 * 16), 0xCECE76DC);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey,     15 * 16), 0x9D3D1B5B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey,     15 * 16), 0xD8C69E0E57F05BDD);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mEncodeKey,       15 * 16), Md5Hash(0x188DC615BE7B86D5, 0x3BF8BF81DC3F0CFA));

            TEST_ASSERT_EQUALS(Adler::adler32(aes.mDecodeKey, 15 * 16), 0x971F7B4E);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey,     15 * 16), 0x7ECC1A9E);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey,     15 * 16), 0x34E2C4D3702F8599);
            TEST_ASSERT_EQUALS(MD5::md5(aes.mDecodeKey,       15 * 16), Md5Hash(0x4C44CA6392F9BC30, 0x21D8368F400C237C));



            TEST_ASSERT_EQUALS(aes.encode(in1, sizeof(in1), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(out)), 0x16B5DCD0);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(out)), 0x49B097FA);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(out)), 0xCFD697AFB71E04A1);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(out)), Md5Hash(0x54F0277BB35CACA3, 0x7167925636792BEC));



            TEST_ASSERT_EQUALS(aes.decode(out, sizeof(out), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(in1)), 0x04000001);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(in1)), 0xEFB5AF2E);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(in1)), 0xC37863972069270C);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(in1)), Md5Hash(0x206A1231093B340F, 0x3B8A012B7CD633F1));



            TEST_ASSERT_EQUALS(aes.encode(in2, sizeof(in2), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(out)), 0x8706007E);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(out)), 0xD6247745);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(out)), 0x165E3E713FA071A9);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(out)), Md5Hash(0xF1416DF0D4C16F49, 0xC710F24BB1203434));



            TEST_ASSERT_EQUALS(aes.decode(out, sizeof(out), out, sizeof(out), &outSize), NgosStatus::OK);

            TEST_ASSERT_EQUALS(outSize, 1024);

            TEST_ASSERT_EQUALS(Adler::adler32(out, sizeof(in2)), 0xED68FB16);
            TEST_ASSERT_EQUALS(Crc::crc32(out,     sizeof(in2)), 0xB02C88C3);
            TEST_ASSERT_EQUALS(Crc::crc64(out,     sizeof(in2)), 0xD48B50F4AEA8861E);
            TEST_ASSERT_EQUALS(MD5::md5(out,       sizeof(in2)), Md5Hash(0xC98DADC0305B4A9D, 0xF1622901D278C2D3));
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



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H
