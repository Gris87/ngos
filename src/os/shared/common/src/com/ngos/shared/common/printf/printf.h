#ifndef COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H
#define COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H



#include <stdarg.h>

#include <com/ngos/shared/common/ngos/types.h>



extern char8 printfBuffer[1024]; // printfBuffer declared in printf.cpp file



i64 vsprintf(char8 *buffer, const char8 *format, va_list args); // TEST: NO
i64 sprintf(char8 *buffer, const char8 *format, ...);
char8* vmprintf(const char8 *format, va_list args); // TEST: NO
char8* mprintf(const char8 *format, ...); // TEST: NO



#endif // COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H
