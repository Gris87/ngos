#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFITIME_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFITIME_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiTime
{
    u16 year;       // 1998 - 20XX
    u8  month;      // 1 - 12
    u8  day;        // 1 - 31
    u8  hour;       // 0 - 23
    u8  minute;     // 0 - 59
    u8  second;     // 0 - 59
    u8  __pad1;
    u32 nanosecond; // 0 - 999999999
    i16 timeZone;   // -1440 to 1440 or 2047
    u8  daylight;
    u8  __pad2;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFITIME_H
