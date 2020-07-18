#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_MALLOC_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_MALLOC_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



void* malloc(u64 size); // TEST: NO
NgosStatus free(void *address); // TEST: NO
void* realloc(void* address, u64 oldSize, u64 newSize); // TEST: NO
void* operator new(size_t size); // TEST: NO
void operator delete(void *address); // TEST: NO
void operator delete(void *address, size_t size); // TEST: NO
void* operator new[](size_t size); // TEST: NO
void operator delete[](void *address); // TEST: NO
void operator delete[](void *address, size_t size); // TEST: NO



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_MALLOC_H