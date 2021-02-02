#ifndef COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMSET_H
#define COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMSET_H



#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>



CPP_EXTERN_C
void* memset(void *dest, bad_uint8 ch, bad_uint64 length); // TEST: MODULE=memory.h



#endif // COM_NGOS_SHARED_COMMON_MEMORY_ASM_MEMSET_H
