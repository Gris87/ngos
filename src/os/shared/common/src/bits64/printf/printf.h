#ifndef OS_SHARED_COMMON_SRC_BITS64_PRINTF_PRINTF_H
#define OS_SHARED_COMMON_SRC_BITS64_PRINTF_PRINTF_H



#include <ngos/types.h>
#include <stdarg.h>



extern char printfBuffer[1024]; // printfBuffer declared in printf.cpp file



i64 vsprintf(char *buffer, const char *format, va_list args); // TEST: NO
i64 sprintf(char *buffer, const char *format, ...); // TEST: NO



#endif // OS_SHARED_COMMON_SRC_BITS64_PRINTF_PRINTF_H