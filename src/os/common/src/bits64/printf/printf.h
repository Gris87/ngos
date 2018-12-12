#ifndef OS_COMMON_SRC_BITS64_PRINTF_PRINTF_H
#define OS_COMMON_SRC_BITS64_PRINTF_PRINTF_H



#include <ngos/types.h>
#include <stdarg.h>



extern char printfBuffer[1024];



i64 vsprintf(char *buffer, const char *format, va_list args); // TEST: NO
i64 sprintf(char *buffer, const char *format, ...); // TEST: NO



#endif // OS_COMMON_SRC_BITS64_PRINTF_PRINTF_H
