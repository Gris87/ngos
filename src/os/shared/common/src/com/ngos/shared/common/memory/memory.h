#ifndef COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H
#define COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H



#include <com/ngos/shared/common/memory/asm_memcpy.h>
#include <com/ngos/shared/common/memory/asm_memset.h>
#include <com/ngos/shared/common/memory/asm_memzero.h>



bad_int8 memcmp(const void *str1, const void *str2, bad_int64 length);
bool memempty(const void *src, bad_int64 length);
void* memmove(void *dest, const void *src, bad_int64 length);



#endif // COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H
