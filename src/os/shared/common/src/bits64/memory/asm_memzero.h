#ifndef OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMZERO_H
#define OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMZERO_H



#include <ngos/linkage.h>
#include <ngos/types.h>



CPP_EXTERN_C
void* memzero(void *dest, u64 length); // TEST: NO



#endif // OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMZERO_H
