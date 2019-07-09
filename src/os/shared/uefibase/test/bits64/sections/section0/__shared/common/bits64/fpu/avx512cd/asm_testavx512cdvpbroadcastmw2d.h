#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512CD_ASM_TESTAVX512CDVPBROADCASTMW2D_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512CD_ASM_TESTAVX512CDVPBROADCASTMW2D_H



#include <buildconfig.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvx512cdVpbroadcastmw2d(u32 *a, u16 mask);



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512CD_ASM_TESTAVX512CDVPBROADCASTMW2D_H