#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMRESETENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMRESETENTRY_H



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
    u16                        resetCount;
    u16                        resetLimit;
    u16                        timerInterval;
    u16                        timeout;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMRESETENTRY_H
