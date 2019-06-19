#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE2_ASM_TESTSSE2ADDPD_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE2_ASM_TESTSSE2ADDPD_H



#include <buildconfig.h>
#include <ngos/linkage.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testSse2Addpd(double *a, double *b, double *c);



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE2_ASM_TESTSSE2ADDPD_H
