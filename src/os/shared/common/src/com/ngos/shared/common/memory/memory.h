#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H



#include <common/src/com/ngos/shared/common/memory/asm_memcpy.h>
#include <common/src/com/ngos/shared/common/memory/asm_memset.h>
#include <common/src/com/ngos/shared/common/memory/asm_memzero.h>



i8 memcmp(const void *str1, const void *str2, i64 length);
bool memempty(const void *src, i64 length);
void* memmove(void *dest, const void *src, i64 length);



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H
