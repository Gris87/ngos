#ifndef COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H
#define COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H



#include <com/ngos/shared/common/memory/asm_memcpy.h>
#include <com/ngos/shared/common/memory/asm_memset.h>
#include <com/ngos/shared/common/memory/asm_memzero.h>



i8 memcmp(const void *str1, const void *str2, i64 length);
bool memempty(const void *src, i64 length);
void* memmove(void *dest, const void *src, i64 length);



#endif // COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H
