#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_SERIAL_SERIAL_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_SERIAL_SERIAL_H



#include <common/src/com/ngos/shared/common/ngos/status.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



class Serial
{
public:
    static NgosStatus initConsole(); // TEST: NO

    static void print(char8 ch); // TEST: NO
    static void print(const char8 *str); // TEST: NO
    static void println(); // TEST: NO
    static void println(char8 ch); // TEST: NO
    static void println(const char8 *str); // TEST: NO
    static i64 printf(const char8 *format, ...); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_SERIAL_SERIAL_H
