#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX_ASM_TESTAVXVMINPS_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX_ASM_TESTAVXVMINPS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/linkage.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvxVminps(float *a, float *b, float *c);



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX_ASM_TESTAVXVMINPS_H
