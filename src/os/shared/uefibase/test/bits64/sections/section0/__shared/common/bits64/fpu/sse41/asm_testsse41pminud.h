#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE41_ASM_TESTSSE41PMINUD_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE41_ASM_TESTSSE41PMINUD_H



#include <buildconfig.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testSse41Pminud(u32 *a, u32 *b, u32 *c);



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE41_ASM_TESTSSE41PMINUD_H
