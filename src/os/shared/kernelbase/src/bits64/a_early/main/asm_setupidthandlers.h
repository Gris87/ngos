#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_A_EARLY_MAIN_ASM_SETUPIDTHANDLERS_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_A_EARLY_MAIN_ASM_SETUPIDTHANDLERS_H



#include <ngos/linkage.h>



CPP_EXTERN_C
void earlyIdtDebugTrap(); // TEST: NO

CPP_EXTERN_C
void earlyIdtBreakpointTrap(); // TEST: NO



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_A_EARLY_MAIN_ASM_SETUPIDTHANDLERS_H