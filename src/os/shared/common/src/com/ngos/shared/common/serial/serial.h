#ifndef COM_NGOS_SHARED_COMMON_SERIAL_SERIAL_H
#define COM_NGOS_SHARED_COMMON_SERIAL_SERIAL_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



class Serial
{
public:
    static NgosStatus initConsole(); // TEST: NO

    static NgosStatus print(char8 ch); // TEST: NO
    static NgosStatus print(const char8 *str); // TEST: NO
    static NgosStatus println(); // TEST: NO
    static NgosStatus println(char8 ch); // TEST: NO
    static NgosStatus println(const char8 *str); // TEST: NO
    static i64 printf(const char8 *format, ...); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_SERIAL_SERIAL_H
