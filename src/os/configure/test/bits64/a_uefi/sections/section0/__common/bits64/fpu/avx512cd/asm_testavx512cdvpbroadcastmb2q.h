#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_ASM512CD_ASM_TESTAVX512CDVPBROADCASTMB2Q_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_ASM512CD_ASM_TESTAVX512CDVPBROADCASTMB2Q_H



#include <buildconfig.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_EXTERN_C
void testAvx512cdVpbroadcastmb2q(u64 *a, u8 mask);



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_ASM512CD_ASM_TESTAVX512CDVPBROADCASTMB2Q_H
