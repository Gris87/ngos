#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512VL_ASM_TESTAVX512VLVRCP14PS_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512VL_ASM_TESTAVX512VLVRCP14PS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/linkage.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvx512vlVrcp14ps(float *a, float *b);



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512VL_ASM_TESTAVX512VLVRCP14PS_H
