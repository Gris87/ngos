#ifndef COM_NGOS_SHARED_COMMON_STRING_STRING_H
#define COM_NGOS_SHARED_COMMON_STRING_STRING_H



#include <com/ngos/shared/common/ngos/types.h>



#ifdef DEVTOOLS_APPLICATION // Defined in pro file
char8* strapp(char8 *str1, const char8 *str2);
#else
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
bad_int64 strlen(const char8 *str);
bad_int64 strlen(const char16 *str);
bad_int64 strnlen(const char8 *str, bad_int64 maxlen);
bad_int64 strnlen(const char16 *str, bad_int64 maxlen);
bad_int8 strcmp(const char8 *str1, const char8 *str2);
bad_int8 strcmp(const char16 *str1, const char16 *str2);
bad_int8 strcmpi(const char8 *str1, const char8 *str2);
bad_int8 strcmpi(const char16 *str1, const char16 *str2);
bad_int8 strncmp(const char8 *str1, const char8 *str2, bad_int64 length);
bad_int8 strncmp(const char16 *str1, const char16 *str2, bad_int64 length);
bad_int8 strncmpi(const char8 *str1, const char8 *str2, bad_int64 length);
bad_int8 strncmpi(const char16 *str1, const char16 *str2, bad_int64 length);
bool strequal(const char8 *str1, const char8 *str2);
bool strequal(const char16 *str1, const char16 *str2);
bool strequali(const char8 *str1, const char8 *str2);
bool strequali(const char16 *str1, const char16 *str2);
bool strnequal(const char8 *str1, const char8 *str2, bad_int64 length);
bool strnequal(const char16 *str1, const char16 *str2, bad_int64 length);
bool strnequali(const char8 *str1, const char8 *str2, bad_int64 length);
bool strnequali(const char16 *str1, const char16 *str2, bad_int64 length);
const char8* strstr(const char8 *str1, const char8 *str2);
const char16* strstr(const char16 *str1, const char16 *str2);
const char8* strstri(const char8 *str1, const char8 *str2);
const char16* strstri(const char16 *str1, const char16 *str2);
bool strend(const char8 *str1, const char8 *str2);
bool strend(const char16 *str1, const char16 *str2);
bool strendi(const char8 *str1, const char8 *str2);
bool strendi(const char16 *str1, const char16 *str2);
#endif



#endif // COM_NGOS_SHARED_COMMON_STRING_STRING_H
