#ifndef COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H                                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <stdarg.h>                                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
extern char8 timestampBuffer[32]; // timestampBuffer declared in printf.cpp file                                                                                                                         // Colorize: green
extern char8 printfBuffer[1024];  // printfBuffer declared in printf.cpp file                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#ifndef DEVTOOLS_APPLICATION // Defined in pro file                                                                                                                                                      // Colorize: green
i64 vsprintf(char8 *buffer, const char8 *format, va_list args); // TEST: NO                                                                                                                              // Colorize: green
i64 sprintf(char8 *buffer, const char8 *format, ...);                                                                                                                                                    // Colorize: green
char8* vmprintf(const char8 *format, va_list args); // TEST: NO                                                                                                                                          // Colorize: green
char8* mprintf(const char8 *format, ...); // TEST: NO                                                                                                                                                    // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_PRINTF_PRINTF_H                                                                                                                                                         // Colorize: green
