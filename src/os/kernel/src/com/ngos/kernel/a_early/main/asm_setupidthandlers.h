#ifndef KERNEL_SRC_COM_NGOS_KERNEL_A_EARLY_MAIN_ASM_SETUPIDTHANDLERS_H
#define KERNEL_SRC_COM_NGOS_KERNEL_A_EARLY_MAIN_ASM_SETUPIDTHANDLERS_H



#include <common/src/com/ngos/shared/common/ngos/linkage.h>



CPP_EXTERN_C
void earlyIdtDebugTrap(); // TEST: NO

CPP_EXTERN_C
void earlyIdtBreakpointTrap(); // TEST: NO



#endif // KERNEL_SRC_COM_NGOS_KERNEL_A_EARLY_MAIN_ASM_SETUPIDTHANDLERS_H
