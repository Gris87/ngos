#ifndef OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H
#define OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H



#include <ngos/types.h>



i64 strlen(const char *str);
i64 strnlen(const char *str, i64 maxlen);
i64 strlen(const u16 *str);
i64 strnlen(const u16 *str, i64 maxlen);
i8 strcmp(const char *str1, const char *str2);
i8 strncmp(const char *str1, const char *str2, i64 length);



#endif // OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H
