#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMCPY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMCPY_H



#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



CPP_EXTERN_C
void* memcpy(void *dest, const void *src, u64 length); // TEST: MODULE=memory.h



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMCPY_H
