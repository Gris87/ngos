#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX_ASM_TESTAVXVMAXPS_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX_ASM_TESTAVXVMAXPS_H



#include <buildconfig.h>
#include <ngos/linkage.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvxVmaxps(float *a, float *b, float *c);



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX_ASM_TESTAVXVMAXPS_H
