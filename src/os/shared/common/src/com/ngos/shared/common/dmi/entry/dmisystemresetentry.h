#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMRESETENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMRESETENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemresetcapabilities.h>



#define DMI_SYSTEM_RESET_RESET_COUNT_UNKNOWN    0xFFFF
#define DMI_SYSTEM_RESET_RESET_LIMIT_UNKNOWN    0xFFFF
#define DMI_SYSTEM_RESET_TIMER_INTERVAL_UNKNOWN 0xFFFF
#define DMI_SYSTEM_RESET_TIMEOUT_UNKNOWN        0xFFFF



struct DmiSystemResetEntry
{
    DmiEntryHeader             header;
    DmiSystemResetCapabilities capabilities;
    bad_uint16                        resetCount;
    bad_uint16                        resetLimit;
    bad_uint16                        timerInterval;
    bad_uint16                        timeout;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMRESETENTRY_H
