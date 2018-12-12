#ifndef OS_COMMON_SRC_BITS64_MEMORY_ASM_MEMSET_H
#define OS_COMMON_SRC_BITS64_MEMORY_ASM_MEMSET_H



#include <ngos/linkage.h>
#include <ngos/types.h>



CPP_EXTERN_C
void* memset(void *dest, u8 ch, u64 length); // TEST: NO



#endif // OS_COMMON_SRC_BITS64_MEMORY_ASM_MEMSET_H
