#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512DQ_ASM_TESTAVX512DQVCVTQQ2PS_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512DQ_ASM_TESTAVX512DQVCVTQQ2PS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvx512dqVcvtqq2ps(bad_uint64 *a, float *b);



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512DQ_ASM_TESTAVX512DQVCVTQQ2PS_H
