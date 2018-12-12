#ifndef OS_COMMON_SRC_BITS64_MEMORY_ASM_MEMCPY_H
#define OS_COMMON_SRC_BITS64_MEMORY_ASM_MEMCPY_H



#include <ngos/linkage.h>
#include <ngos/types.h>



CPP_EXTERN_C
void* memcpy(void *dest, const void *src, u64 length); // TEST: NO



#endif // OS_COMMON_SRC_BITS64_MEMORY_ASM_MEMCPY_H
