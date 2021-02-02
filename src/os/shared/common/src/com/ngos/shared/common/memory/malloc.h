#ifndef COM_NGOS_SHARED_COMMON_MEMORY_MALLOC_H
#define COM_NGOS_SHARED_COMMON_MEMORY_MALLOC_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



void* malloc(bad_uint64 size); // TEST: NO
NgosStatus free(void *address); // TEST: NO
void* realloc(void* address, bad_uint64 oldSize, bad_uint64 newSize); // TEST: NO
void* operator new(size_t size); // TEST: NO
void operator delete(void *address); // TEST: NO
void operator delete(void *address, size_t size); // TEST: NO
void* operator new[](size_t size); // TEST: NO
void operator delete[](void *address); // TEST: NO
void operator delete[](void *address, size_t size); // TEST: NO



#endif // COM_NGOS_SHARED_COMMON_MEMORY_MALLOC_H
