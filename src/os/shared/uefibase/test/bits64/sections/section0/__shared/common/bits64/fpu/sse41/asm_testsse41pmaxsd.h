#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE41_ASM_TESTSSE41PMAXSD_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE41_ASM_TESTSSE41PMAXSD_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testSse41Pmaxsd(i32 *a, i32 *b, i32 *c);



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_SSE41_ASM_TESTSSE41PMAXSD_H
