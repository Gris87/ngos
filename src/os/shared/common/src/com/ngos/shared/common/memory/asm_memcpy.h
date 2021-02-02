#ifndef COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMCPY_H
#define COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMCPY_H



#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>



CPP_EXTERN_C
void* memcpy(void *dest, const void *src, bad_uint64 length); // TEST: MODULE=memory.h



#endif // COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMCPY_H
