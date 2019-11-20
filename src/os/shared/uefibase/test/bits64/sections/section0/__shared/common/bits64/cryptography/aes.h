#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CRYPTOGRAPHY_AES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CRYPTOGRAPHY_AES_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/checksum/crc.h>
#include <common/src/bits64/cryptography/aes.h>
#include <common/src/bits64/memory/malloc.h>
#include <common/src/bits64/string/string.h>
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
            u8 key3[32] = { 3, 1, 9, 4, 6, 8, 9, 2, 3, 7, 9, 1, 6, 7, 9, 1, 3, 4, 7, 8, 9, 2, 3, 4, 3, 4, 7, 8, 9, 2, 3, 4 };



            TEST_ASSERT_EQUALS(aes.setKey(key1, sizeof(key1)), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mExpandKeyFunction,   nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKey,           nullptr);

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 11 * 16), 0x0495671B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 11 * 16), 0xAA263E486D960ACD);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 11 * 16), 0xC4C8131C);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 11 * 16), 0xF4C91CB7B40C7925);



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

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 13 * 16), 0x0495671B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 13 * 16), 0xAA263E486D960ACD);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 13 * 16), 0xC4C8131C);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 13 * 16), 0xF4C91CB7B40C7925);



            TEST_ASSERT_EQUALS(aes.releaseKey(), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mExpandKeyFunction,   nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKeyAllocated,      nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKeyAllocated,      nullptr);
            TEST_ASSERT_EQUALS(aes.mEncodeKey,               nullptr);
            TEST_ASSERT_EQUALS(aes.mDecodeKey,               nullptr);



            TEST_ASSERT_EQUALS(aes.setKey(key3, sizeof(key3)), NgosStatus::OK);



            TEST_ASSERT_NOT_EQUALS(aes.mExpandKeyFunction,   nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeBlockFunction, nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKeyAllocated,  nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mEncodeKey,           nullptr);
            TEST_ASSERT_NOT_EQUALS(aes.mDecodeKey,           nullptr);

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 15 * 16), 0x0495671B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 15 * 16), 0xAA263E486D960ACD);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 15 * 16), 0xC4C8131C);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 15 * 16), 0xF4C91CB7B40C7925);
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

            const char8 *key1 = "NGOS is the best";
            const char8 *key2 = "NGOS is the best OS ever";
            const char8 *key3 = "NGOS is the best OS ever !!!!!!!";

            TEST_ASSERT_EQUALS(strlen(key1), 16);
            TEST_ASSERT_EQUALS(strlen(key2), 24);
            TEST_ASSERT_EQUALS(strlen(key3), 32);



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



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key1, strlen(key1)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 11 * 16), 0xE5F76028);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 11 * 16), 0xC172975B03490927);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 11 * 16), 0x6F98A19E);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 11 * 16), 0xB1E3801C9D9249A0);



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



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key2, strlen(key2)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 13 * 16), 0x0495671B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 13 * 16), 0xAA263E486D960ACD);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 13 * 16), 0xC4C8131C);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 13 * 16), 0xF4C91CB7B40C7925);



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



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key3, strlen(key3)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 15 * 16), 0x0495671B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 15 * 16), 0xAA263E486D960ACD);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 15 * 16), 0xC4C8131C);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 15 * 16), 0xF4C91CB7B40C7925);



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

            const char8 *key1 = "NGOS is the best";
            const char8 *key2 = "NGOS is the best OS ever";
            const char8 *key3 = "NGOS is the best OS ever !!!!!!!";

            TEST_ASSERT_EQUALS(strlen(key1), 16);
            TEST_ASSERT_EQUALS(strlen(key2), 24);
            TEST_ASSERT_EQUALS(strlen(key3), 32);



            u8 in1[16] __attribute__((aligned(16))) = { 0x88, 0x10, 0x31, 0x80, 0xE2, 0x9E, 0xCD, 0x89, 0x28, 0x33, 0x85, 0xC6, 0xDC, 0xC0, 0xB8, 0xB0 };
            u8 in2[16] __attribute__((aligned(16))) = { 0x2F, 0xD0, 0x6A, 0x96, 0xEA, 0x2A, 0xF4, 0xAE, 0x34, 0xCC, 0x59, 0x69, 0x4B, 0x50, 0xAC, 0xB0 };
            u8 in3[16] __attribute__((aligned(16))) = { 0x93, 0xAB, 0x63, 0x70, 0xC5, 0x68, 0x33, 0x81, 0x71, 0x7B, 0x90, 0x63, 0x64, 0xFF, 0x11, 0x27 };

            u8  out[16] __attribute__((aligned(16)));
            u64 outSize;



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key1, strlen(key1)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 11 * 16), 0xE5F76028);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 11 * 16), 0xC172975B03490927);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 11 * 16), 0x6F98A19E);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 11 * 16), 0xB1E3801C9D9249A0);



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



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key2, strlen(key2)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 13 * 16), 0x0495671B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 13 * 16), 0xAA263E486D960ACD);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 13 * 16), 0xC4C8131C);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 13 * 16), 0xF4C91CB7B40C7925);



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



            TEST_ASSERT_EQUALS(aes.setKey((u8 *)key3, strlen(key3)), NgosStatus::OK);

            TEST_ASSERT_EQUALS(Crc::crc32(aes.mEncodeKey, 15 * 16), 0x0495671B);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mEncodeKey, 15 * 16), 0xAA263E486D960ACD);
            TEST_ASSERT_EQUALS(Crc::crc32(aes.mDecodeKey, 15 * 16), 0xC4C8131C);
            TEST_ASSERT_EQUALS(Crc::crc64(aes.mDecodeKey, 15 * 16), 0xF4C91CB7B40C7925);



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
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CPU_CPU_H
