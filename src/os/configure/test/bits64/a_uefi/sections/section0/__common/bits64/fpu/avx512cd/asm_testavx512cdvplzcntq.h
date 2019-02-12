#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX512CD_ASM_TESTAVX512CDVPLZCNTQ_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX512CD_ASM_TESTAVX512CDVPLZCNTQ_H



#include <buildconfig.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvx512cdVplzcntq(u64 *a, u64 *b);



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX512CD_ASM_TESTAVX512CDVPLZCNTQ_H