#ifndef OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H
#define OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



char8 toLower(char8 ch);
char16 toLower(char16 ch);
char8 toUpper(char8 ch);
char16 toUpper(char16 ch);
char8* strcpy(char8 *str1, const char8 *str2);
char16* strcpy(char16 *str1, const char16 *str2);
char8* strdup(const char8 *str);
char16* strdup(const char16 *str);
char8* strcat(char8 *str1, const char8 *str2);
char16* strcat(char16 *str1, const char16 *str2);
char8* strapp(char8 *str1, const char8 *str2);
char16* strapp(char16 *str1, const char16 *str2);
i64 strlen(const char8 *str);
i64 strlen(const char16 *str);
i64 strnlen(const char8 *str, i64 maxlen);
i64 strnlen(const char16 *str, i64 maxlen);
i8 strcmp(const char8 *str1, const char8 *str2);
i8 strcmp(const char16 *str1, const char16 *str2);
i8 strcmpi(const char8 *str1, const char8 *str2);
i8 strcmpi(const char16 *str1, const char16 *str2);
i8 strncmp(const char8 *str1, const char8 *str2, i64 length);
i8 strncmp(const char16 *str1, const char16 *str2, i64 length);
i8 strncmpi(const char8 *str1, const char8 *str2, i64 length);
i8 strncmpi(const char16 *str1, const char16 *str2, i64 length);
bool strequal(const char8 *str1, const char8 *str2);
bool strequal(const char16 *str1, const char16 *str2);
bool strequali(const char8 *str1, const char8 *str2);
bool strequali(const char16 *str1, const char16 *str2);
bool strnequal(const char8 *str1, const char8 *str2, i64 length);
bool strnequal(const char16 *str1, const char16 *str2, i64 length);
bool strnequali(const char8 *str1, const char8 *str2, i64 length);
bool strnequali(const char16 *str1, const char16 *str2, i64 length);
const char8* strstr(const char8 *str1, const char8 *str2);
const char16* strstr(const char16 *str1, const char16 *str2);
const char8* strstri(const char8 *str1, const char8 *str2);
const char16* strstri(const char16 *str1, const char16 *str2);
bool strend(const char8 *str1, const char8 *str2);
bool strend(const char16 *str1, const char16 *str2);
bool strendi(const char8 *str1, const char8 *str2);
bool strendi(const char16 *str1, const char16 *str2);



#endif // OS_SHARED_COMMON_SRC_BITS64_STRING_STRING_H
