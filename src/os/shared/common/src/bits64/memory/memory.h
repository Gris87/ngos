#ifndef OS_COMMON_SRC_BITS64_MEMORY_MEMORY_H
#define OS_COMMON_SRC_BITS64_MEMORY_MEMORY_H



#include <src/bits64/memory/asm_memcpy.h>
#include <src/bits64/memory/asm_memset.h>
#include <src/bits64/memory/asm_memzero.h>



i8 memcmp(const char *str1, const char *str2, i64 length); // TEST: NO
bool memempty(const void *src, i64 length); // TEST: NO
void* memmove(void *dest, const void *src, i64 length); // TEST: NO



#endif // OS_COMMON_SRC_BITS64_MEMORY_MEMORY_H
