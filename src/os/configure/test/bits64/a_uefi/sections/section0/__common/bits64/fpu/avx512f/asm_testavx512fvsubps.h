#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX512F_ASM_TESTAVX512FVSUBPS_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX512F_ASM_TESTAVX512FVSUBPS_H



#include <buildconfig.h>
#include <ngos/linkage.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvx512fVsubps(float *a, float *b, float *c);



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX512F_ASM_TESTAVX512FVSUBPS_H
