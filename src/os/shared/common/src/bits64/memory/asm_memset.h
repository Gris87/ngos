#ifndef OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMSET_H
#define OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMSET_H



#include <ngos/linkage.h>
#include <ngos/types.h>



CPP_EXTERN_C
void* memset(void *dest, u8 ch, u64 length); // TEST: MODULE=memory.h



#endif // OS_SHARED_COMMON_SRC_BITS64_MEMORY_ASM_MEMSET_H
