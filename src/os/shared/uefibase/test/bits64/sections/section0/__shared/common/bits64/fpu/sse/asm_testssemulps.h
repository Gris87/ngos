#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE_ASM_TESTSSEMULPS_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE_ASM_TESTSSEMULPS_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testSseMulps(float *a, float *b, float *c);



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE_ASM_TESTSSEMULPS_H
