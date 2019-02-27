#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX2_ASM_TESTAVX2VPHADDD_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX2_ASM_TESTAVX2VPHADDD_H



#include <buildconfig.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvx2Vphaddd(u32 *a, u32 *b, u32 *c);



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX2_ASM_TESTAVX2VPHADDD_H
