#ifndef OS_SHARED_COMMON_SRC_BITS64_MEMORY_MALLOC_H
#define OS_SHARED_COMMON_SRC_BITS64_MEMORY_MALLOC_H



#include <ngos/status.h>
#include <ngos/types.h>



void* malloc(u64 size); // TEST: NO
NgosStatus free(void *address); // TEST: NO



#endif // OS_SHARED_COMMON_SRC_BITS64_MEMORY_MALLOC_H
