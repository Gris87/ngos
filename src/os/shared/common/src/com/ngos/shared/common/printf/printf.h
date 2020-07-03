#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <stdarg.h>



extern char8 printfBuffer[1024]; // printfBuffer declared in printf.cpp file



i64 vsprintf(char8 *buffer, const char8 *format, va_list args); // TEST: NO
i64 sprintf(char8 *buffer, const char8 *format, ...);
char8* vmprintf(const char8 *format, va_list args); // TEST: NO
char8* mprintf(const char8 *format, ...); // TEST: NO



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H
