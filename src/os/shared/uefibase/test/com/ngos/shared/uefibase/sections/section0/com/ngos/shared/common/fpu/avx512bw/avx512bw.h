#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512BW_AVX512BW_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512BW_AVX512BW_H



#include <buildconfig.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512bw/asm_testavx512bwvpbroadcastb.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512bw/asm_testavx512bwvpbroadcastw.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512bw/asm_testavx512bwvpsllvw.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512bw/asm_testavx512bwvpsrlvw.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_fpu_avx512bw_avx512bw);
{
    TEST_CASE("vpbroadcastb");
    {
        if (CPU::hasFeature(X86Feature::AVX512BW))
        {
            u8 a[64] __attribute__((aligned(64)));

            testAvx512bwVpbroadcastb(a, 100);

            TEST_ASSERT_EQUALS(a[0],  100);
            TEST_ASSERT_EQUALS(a[1],  100);
            TEST_ASSERT_EQUALS(a[2],  100);
            TEST_ASSERT_EQUALS(a[3],  100);
            TEST_ASSERT_EQUALS(a[4],  100);
            TEST_ASSERT_EQUALS(a[5],  100);
            TEST_ASSERT_EQUALS(a[6],  100);
            TEST_ASSERT_EQUALS(a[7],  100);
            TEST_ASSERT_EQUALS(a[8],  100);
            TEST_ASSERT_EQUALS(a[9],  100);
            TEST_ASSERT_EQUALS(a[10], 100);
            TEST_ASSERT_EQUALS(a[11], 100);
            TEST_ASSERT_EQUALS(a[12], 100);
            TEST_ASSERT_EQUALS(a[13], 100);
            TEST_ASSERT_EQUALS(a[14], 100);
            TEST_ASSERT_EQUALS(a[15], 100);
            TEST_ASSERT_EQUALS(a[16], 100);
            TEST_ASSERT_EQUALS(a[17], 100);
            TEST_ASSERT_EQUALS(a[18], 100);
            TEST_ASSERT_EQUALS(a[19], 100);
            TEST_ASSERT_EQUALS(a[20], 100);
            TEST_ASSERT_EQUALS(a[21], 100);
            TEST_ASSERT_EQUALS(a[22], 100);
            TEST_ASSERT_EQUALS(a[23], 100);
            TEST_ASSERT_EQUALS(a[24], 100);
            TEST_ASSERT_EQUALS(a[25], 100);
            TEST_ASSERT_EQUALS(a[26], 100);
            TEST_ASSERT_EQUALS(a[27], 100);
            TEST_ASSERT_EQUALS(a[28], 100);
            TEST_ASSERT_EQUALS(a[29], 100);
            TEST_ASSERT_EQUALS(a[30], 100);
            TEST_ASSERT_EQUALS(a[31], 100);
            TEST_ASSERT_EQUALS(a[32], 100);
            TEST_ASSERT_EQUALS(a[33], 100);
            TEST_ASSERT_EQUALS(a[34], 100);
            TEST_ASSERT_EQUALS(a[35], 100);
            TEST_ASSERT_EQUALS(a[36], 100);
            TEST_ASSERT_EQUALS(a[37], 100);
            TEST_ASSERT_EQUALS(a[38], 100);
            TEST_ASSERT_EQUALS(a[39], 100);
            TEST_ASSERT_EQUALS(a[40], 100);
            TEST_ASSERT_EQUALS(a[41], 100);
            TEST_ASSERT_EQUALS(a[42], 100);
            TEST_ASSERT_EQUALS(a[43], 100);
            TEST_ASSERT_EQUALS(a[44], 100);
            TEST_ASSERT_EQUALS(a[45], 100);
            TEST_ASSERT_EQUALS(a[46], 100);
            TEST_ASSERT_EQUALS(a[47], 100);
            TEST_ASSERT_EQUALS(a[48], 100);
            TEST_ASSERT_EQUALS(a[49], 100);
            TEST_ASSERT_EQUALS(a[50], 100);
            TEST_ASSERT_EQUALS(a[51], 100);
            TEST_ASSERT_EQUALS(a[52], 100);
            TEST_ASSERT_EQUALS(a[53], 100);
            TEST_ASSERT_EQUALS(a[54], 100);
            TEST_ASSERT_EQUALS(a[55], 100);
            TEST_ASSERT_EQUALS(a[56], 100);
            TEST_ASSERT_EQUALS(a[57], 100);
            TEST_ASSERT_EQUALS(a[58], 100);
            TEST_ASSERT_EQUALS(a[59], 100);
            TEST_ASSERT_EQUALS(a[60], 100);
            TEST_ASSERT_EQUALS(a[61], 100);
            TEST_ASSERT_EQUALS(a[62], 100);
            TEST_ASSERT_EQUALS(a[63], 100);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512BW not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vpbroadcastw");
    {
        if (CPU::hasFeature(X86Feature::AVX512BW))
        {
            u16 a[32] __attribute__((aligned(64)));

            testAvx512bwVpbroadcastw(a, 1000);

            TEST_ASSERT_EQUALS(a[0],  1000);
            TEST_ASSERT_EQUALS(a[1],  1000);
            TEST_ASSERT_EQUALS(a[2],  1000);
            TEST_ASSERT_EQUALS(a[3],  1000);
            TEST_ASSERT_EQUALS(a[4],  1000);
            TEST_ASSERT_EQUALS(a[5],  1000);
            TEST_ASSERT_EQUALS(a[6],  1000);
            TEST_ASSERT_EQUALS(a[7],  1000);
            TEST_ASSERT_EQUALS(a[8],  1000);
            TEST_ASSERT_EQUALS(a[9],  1000);
            TEST_ASSERT_EQUALS(a[10], 1000);
            TEST_ASSERT_EQUALS(a[11], 1000);
            TEST_ASSERT_EQUALS(a[12], 1000);
            TEST_ASSERT_EQUALS(a[13], 1000);
            TEST_ASSERT_EQUALS(a[14], 1000);
            TEST_ASSERT_EQUALS(a[15], 1000);
            TEST_ASSERT_EQUALS(a[16], 1000);
            TEST_ASSERT_EQUALS(a[17], 1000);
            TEST_ASSERT_EQUALS(a[18], 1000);
            TEST_ASSERT_EQUALS(a[19], 1000);
            TEST_ASSERT_EQUALS(a[20], 1000);
            TEST_ASSERT_EQUALS(a[21], 1000);
            TEST_ASSERT_EQUALS(a[22], 1000);
            TEST_ASSERT_EQUALS(a[23], 1000);
            TEST_ASSERT_EQUALS(a[24], 1000);
            TEST_ASSERT_EQUALS(a[25], 1000);
            TEST_ASSERT_EQUALS(a[26], 1000);
            TEST_ASSERT_EQUALS(a[27], 1000);
            TEST_ASSERT_EQUALS(a[28], 1000);
            TEST_ASSERT_EQUALS(a[29], 1000);
            TEST_ASSERT_EQUALS(a[30], 1000);
            TEST_ASSERT_EQUALS(a[31], 1000);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512BW not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vpsllvw");
    {
        if (CPU::hasFeature(X86Feature::AVX512BW))
        {
            u16 a[32] __attribute__((aligned(64))) = { 1, 2, 3, 1, 9, 3, 1, 7, 6, 2, 4, 3, 2, 1, 8, 6, 2, 7, 3, 2, 9, 7, 1, 2, 9, 4, 6, 2, 3, 7, 6, 2 };
            u16 b[32] __attribute__((aligned(64))) = { 6, 2, 7, 3, 2, 9, 7, 1, 2, 9, 4, 6, 2, 3, 7, 6, 2, 1, 2, 3, 1, 9, 3, 1, 7, 6, 2, 4, 3, 2, 1, 8 };
            u16 c[32] __attribute__((aligned(64)));

            testAvx512bwVpsllvw(a, b, c);

            TEST_ASSERT_EQUALS(a[0],  1);
            TEST_ASSERT_EQUALS(a[1],  2);
            TEST_ASSERT_EQUALS(a[2],  3);
            TEST_ASSERT_EQUALS(a[3],  1);
            TEST_ASSERT_EQUALS(a[4],  9);
            TEST_ASSERT_EQUALS(a[5],  3);
            TEST_ASSERT_EQUALS(a[6],  1);
            TEST_ASSERT_EQUALS(a[7],  7);
            TEST_ASSERT_EQUALS(a[8],  6);
            TEST_ASSERT_EQUALS(a[9],  2);
            TEST_ASSERT_EQUALS(a[10], 4);
            TEST_ASSERT_EQUALS(a[11], 3);
            TEST_ASSERT_EQUALS(a[12], 2);
            TEST_ASSERT_EQUALS(a[13], 1);
            TEST_ASSERT_EQUALS(a[14], 8);
            TEST_ASSERT_EQUALS(a[15], 6);
            TEST_ASSERT_EQUALS(a[16], 2);
            TEST_ASSERT_EQUALS(a[17], 7);
            TEST_ASSERT_EQUALS(a[18], 3);
            TEST_ASSERT_EQUALS(a[19], 2);
            TEST_ASSERT_EQUALS(a[20], 9);
            TEST_ASSERT_EQUALS(a[21], 7);
            TEST_ASSERT_EQUALS(a[22], 1);
            TEST_ASSERT_EQUALS(a[23], 2);
            TEST_ASSERT_EQUALS(a[24], 9);
            TEST_ASSERT_EQUALS(a[25], 4);
            TEST_ASSERT_EQUALS(a[26], 6);
            TEST_ASSERT_EQUALS(a[27], 2);
            TEST_ASSERT_EQUALS(a[28], 3);
            TEST_ASSERT_EQUALS(a[29], 7);
            TEST_ASSERT_EQUALS(a[30], 6);
            TEST_ASSERT_EQUALS(a[31], 2);

            TEST_ASSERT_EQUALS(b[0],  6);
            TEST_ASSERT_EQUALS(b[1],  2);
            TEST_ASSERT_EQUALS(b[2],  7);
            TEST_ASSERT_EQUALS(b[3],  3);
            TEST_ASSERT_EQUALS(b[4],  2);
            TEST_ASSERT_EQUALS(b[5],  9);
            TEST_ASSERT_EQUALS(b[6],  7);
            TEST_ASSERT_EQUALS(b[7],  1);
            TEST_ASSERT_EQUALS(b[8],  2);
            TEST_ASSERT_EQUALS(b[9],  9);
            TEST_ASSERT_EQUALS(b[10], 4);
            TEST_ASSERT_EQUALS(b[11], 6);
            TEST_ASSERT_EQUALS(b[12], 2);
            TEST_ASSERT_EQUALS(b[13], 3);
            TEST_ASSERT_EQUALS(b[14], 7);
            TEST_ASSERT_EQUALS(b[15], 6);
            TEST_ASSERT_EQUALS(b[16], 2);
            TEST_ASSERT_EQUALS(b[17], 1);
            TEST_ASSERT_EQUALS(b[18], 2);
            TEST_ASSERT_EQUALS(b[19], 3);
            TEST_ASSERT_EQUALS(b[20], 1);
            TEST_ASSERT_EQUALS(b[21], 9);
            TEST_ASSERT_EQUALS(b[22], 3);
            TEST_ASSERT_EQUALS(b[23], 1);
            TEST_ASSERT_EQUALS(b[24], 7);
            TEST_ASSERT_EQUALS(b[25], 6);
            TEST_ASSERT_EQUALS(b[26], 2);
            TEST_ASSERT_EQUALS(b[27], 4);
            TEST_ASSERT_EQUALS(b[28], 3);
            TEST_ASSERT_EQUALS(b[29], 2);
            TEST_ASSERT_EQUALS(b[30], 1);
            TEST_ASSERT_EQUALS(b[31], 8);

            TEST_ASSERT_EQUALS(c[0],  64);
            TEST_ASSERT_EQUALS(c[1],  8);
            TEST_ASSERT_EQUALS(c[2],  384);
            TEST_ASSERT_EQUALS(c[3],  8);
            TEST_ASSERT_EQUALS(c[4],  36);
            TEST_ASSERT_EQUALS(c[5],  1536);
            TEST_ASSERT_EQUALS(c[6],  128);
            TEST_ASSERT_EQUALS(c[7],  14);
            TEST_ASSERT_EQUALS(c[8],  24);
            TEST_ASSERT_EQUALS(c[9],  1024);
            TEST_ASSERT_EQUALS(c[10], 64);
            TEST_ASSERT_EQUALS(c[11], 192);
            TEST_ASSERT_EQUALS(c[12], 8);
            TEST_ASSERT_EQUALS(c[13], 8);
            TEST_ASSERT_EQUALS(c[14], 1024);
            TEST_ASSERT_EQUALS(c[15], 384);
            TEST_ASSERT_EQUALS(c[16], 8);
            TEST_ASSERT_EQUALS(c[17], 14);
            TEST_ASSERT_EQUALS(c[18], 12);
            TEST_ASSERT_EQUALS(c[19], 16);
            TEST_ASSERT_EQUALS(c[20], 18);
            TEST_ASSERT_EQUALS(c[21], 3584);
            TEST_ASSERT_EQUALS(c[22], 8);
            TEST_ASSERT_EQUALS(c[23], 4);
            TEST_ASSERT_EQUALS(c[24], 1152);
            TEST_ASSERT_EQUALS(c[25], 256);
            TEST_ASSERT_EQUALS(c[26], 24);
            TEST_ASSERT_EQUALS(c[27], 32);
            TEST_ASSERT_EQUALS(c[28], 24);
            TEST_ASSERT_EQUALS(c[29], 28);
            TEST_ASSERT_EQUALS(c[30], 12);
            TEST_ASSERT_EQUALS(c[31], 512);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512BW not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vpsrlvw");
    {
        if (CPU::hasFeature(X86Feature::AVX512BW))
        {
            u16 a[32] __attribute__((aligned(64))) = { 64, 8, 384, 8, 36, 1536, 128, 14, 24, 1024, 64, 192, 8, 8, 1024, 384, 8, 14, 12, 16, 18, 3584, 8, 4, 1152, 256, 24, 32, 24, 28, 12, 512 };
            u16 b[32] __attribute__((aligned(64))) = { 6,  2, 7,   3, 2,  9,    7,   1,  2,  9,    4,  6,   2, 3, 7,    6,   2, 1,  2,  3,  1,  9,    3, 1, 7,    6,   2,  4,  3,  2,  1,  8   };
            u16 c[32] __attribute__((aligned(64)));

            testAvx512bwVpsrlvw(a, b, c);

            TEST_ASSERT_EQUALS(a[0],  64);
            TEST_ASSERT_EQUALS(a[1],  8);
            TEST_ASSERT_EQUALS(a[2],  384);
            TEST_ASSERT_EQUALS(a[3],  8);
            TEST_ASSERT_EQUALS(a[4],  36);
            TEST_ASSERT_EQUALS(a[5],  1536);
            TEST_ASSERT_EQUALS(a[6],  128);
            TEST_ASSERT_EQUALS(a[7],  14);
            TEST_ASSERT_EQUALS(a[8],  24);
            TEST_ASSERT_EQUALS(a[9],  1024);
            TEST_ASSERT_EQUALS(a[10], 64);
            TEST_ASSERT_EQUALS(a[11], 192);
            TEST_ASSERT_EQUALS(a[12], 8);
            TEST_ASSERT_EQUALS(a[13], 8);
            TEST_ASSERT_EQUALS(a[14], 1024);
            TEST_ASSERT_EQUALS(a[15], 384);
            TEST_ASSERT_EQUALS(a[16], 8);
            TEST_ASSERT_EQUALS(a[17], 14);
            TEST_ASSERT_EQUALS(a[18], 12);
            TEST_ASSERT_EQUALS(a[19], 16);
            TEST_ASSERT_EQUALS(a[20], 18);
            TEST_ASSERT_EQUALS(a[21], 3584);
            TEST_ASSERT_EQUALS(a[22], 8);
            TEST_ASSERT_EQUALS(a[23], 4);
            TEST_ASSERT_EQUALS(a[24], 1152);
            TEST_ASSERT_EQUALS(a[25], 256);
            TEST_ASSERT_EQUALS(a[26], 24);
            TEST_ASSERT_EQUALS(a[27], 32);
            TEST_ASSERT_EQUALS(a[28], 24);
            TEST_ASSERT_EQUALS(a[29], 28);
            TEST_ASSERT_EQUALS(a[30], 12);
            TEST_ASSERT_EQUALS(a[31], 512);

            TEST_ASSERT_EQUALS(b[0],  6);
            TEST_ASSERT_EQUALS(b[1],  2);
            TEST_ASSERT_EQUALS(b[2],  7);
            TEST_ASSERT_EQUALS(b[3],  3);
            TEST_ASSERT_EQUALS(b[4],  2);
            TEST_ASSERT_EQUALS(b[5],  9);
            TEST_ASSERT_EQUALS(b[6],  7);
            TEST_ASSERT_EQUALS(b[7],  1);
            TEST_ASSERT_EQUALS(b[8],  2);
            TEST_ASSERT_EQUALS(b[9],  9);
            TEST_ASSERT_EQUALS(b[10], 4);
            TEST_ASSERT_EQUALS(b[11], 6);
            TEST_ASSERT_EQUALS(b[12], 2);
            TEST_ASSERT_EQUALS(b[13], 3);
            TEST_ASSERT_EQUALS(b[14], 7);
            TEST_ASSERT_EQUALS(b[15], 6);
            TEST_ASSERT_EQUALS(b[16], 2);
            TEST_ASSERT_EQUALS(b[17], 1);
            TEST_ASSERT_EQUALS(b[18], 2);
            TEST_ASSERT_EQUALS(b[19], 3);
            TEST_ASSERT_EQUALS(b[20], 1);
            TEST_ASSERT_EQUALS(b[21], 9);
            TEST_ASSERT_EQUALS(b[22], 3);
            TEST_ASSERT_EQUALS(b[23], 1);
            TEST_ASSERT_EQUALS(b[24], 7);
            TEST_ASSERT_EQUALS(b[25], 6);
            TEST_ASSERT_EQUALS(b[26], 2);
            TEST_ASSERT_EQUALS(b[27], 4);
            TEST_ASSERT_EQUALS(b[28], 3);
            TEST_ASSERT_EQUALS(b[29], 2);
            TEST_ASSERT_EQUALS(b[30], 1);
            TEST_ASSERT_EQUALS(b[31], 8);

            TEST_ASSERT_EQUALS(c[0],  1);
            TEST_ASSERT_EQUALS(c[1],  2);
            TEST_ASSERT_EQUALS(c[2],  3);
            TEST_ASSERT_EQUALS(c[3],  1);
            TEST_ASSERT_EQUALS(c[4],  9);
            TEST_ASSERT_EQUALS(c[5],  3);
            TEST_ASSERT_EQUALS(c[6],  1);
            TEST_ASSERT_EQUALS(c[7],  7);
            TEST_ASSERT_EQUALS(c[8],  6);
            TEST_ASSERT_EQUALS(c[9],  2);
            TEST_ASSERT_EQUALS(c[10], 4);
            TEST_ASSERT_EQUALS(c[11], 3);
            TEST_ASSERT_EQUALS(c[12], 2);
            TEST_ASSERT_EQUALS(c[13], 1);
            TEST_ASSERT_EQUALS(c[14], 8);
            TEST_ASSERT_EQUALS(c[15], 6);
            TEST_ASSERT_EQUALS(c[16], 2);
            TEST_ASSERT_EQUALS(c[17], 7);
            TEST_ASSERT_EQUALS(c[18], 3);
            TEST_ASSERT_EQUALS(c[19], 2);
            TEST_ASSERT_EQUALS(c[20], 9);
            TEST_ASSERT_EQUALS(c[21], 7);
            TEST_ASSERT_EQUALS(c[22], 1);
            TEST_ASSERT_EQUALS(c[23], 2);
            TEST_ASSERT_EQUALS(c[24], 9);
            TEST_ASSERT_EQUALS(c[25], 4);
            TEST_ASSERT_EQUALS(c[26], 6);
            TEST_ASSERT_EQUALS(c[27], 2);
            TEST_ASSERT_EQUALS(c[28], 3);
            TEST_ASSERT_EQUALS(c[29], 7);
            TEST_ASSERT_EQUALS(c[30], 6);
            TEST_ASSERT_EQUALS(c[31], 2);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512BW not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512BW_AVX512BW_H
