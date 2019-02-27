#ifndef OS_COMMON_SRC_BITS64_STRING_STRING_H
#define OS_COMMON_SRC_BITS64_STRING_STRING_H



#include <ngos/types.h>



i64 strlen(const char *str); // TEST: NO
i64 strnlen(const char *str, i64 maxlen); // TEST: NO
i8 strcmp(const char *str1, const char *str2); // TEST: NO
i8 strncmp(const char *str1, const char *str2, i64 length); // TEST: NO



#endif // OS_COMMON_SRC_BITS64_STRING_STRING_H
