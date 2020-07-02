#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512BW_ASM_TESTAVX512BWVPBROADCASTB_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512BW_ASM_TESTAVX512BWVPBROADCASTB_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvx512bwVpbroadcastb(u8 *a, u8 value);



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512BW_ASM_TESTAVX512BWVPBROADCASTB_H
