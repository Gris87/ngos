#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMZERO_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMZERO_H



#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



CPP_EXTERN_C
void* memzero(void *dest, u64 length); // TEST: MODULE=memory.h



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMZERO_H
