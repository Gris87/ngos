#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFITIME_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFITIME_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiTime
{
    bad_uint16 year;       // 1998 - 20XX
    bad_uint8  month;      // 1 - 12
    bad_uint8  day;        // 1 - 31
    bad_uint8  hour;       // 0 - 23
    bad_uint8  minute;     // 0 - 59
    bad_uint8  second;     // 0 - 59
    bad_uint8  __pad1;
    bad_uint32 nanosecond; // 0 - 999999999
    bad_int16 timeZone;   // -1440 to 1440 or 2047
    bad_uint8  daylight;
    bad_uint8  __pad2;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFITIME_H
