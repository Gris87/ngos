#ifndef OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H
#define OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H



#include <ngos/types.h>



i64 strlen(const char8 *str);
i64 strlen(const char16 *str);
i64 strnlen(const char8 *str, i64 maxlen);
i64 strnlen(const char16 *str, i64 maxlen);
i8 strcmp(const char8 *str1, const char8 *str2);
i8 strcmp(const char16 *str1, const char16 *str2);
i8 strncmp(const char8 *str1, const char8 *str2, i64 length);
i8 strncmp(const char16 *str1, const char16 *str2, i64 length);
char8* strcat(char8 *str1, const char8 *str2);
char16* strcat(char16 *str1, const char16 *str2);
char8* strapp(char8 *str1, const char8 *str2);
char16* strapp(char16 *str1, const char16 *str2);



#endif // OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H
