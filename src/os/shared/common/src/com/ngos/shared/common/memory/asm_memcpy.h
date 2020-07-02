#ifndef OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMCPY_H
#define OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMCPY_H



#include <ngos/linkage.h>
#include <ngos/types.h>



CPP_EXTERN_C
void* memcpy(void *dest, const void *src, u64 length); // TEST: MODULE=memory.h



#endif // OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMCPY_H
