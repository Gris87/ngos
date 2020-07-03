#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIHARDWARESECURITYENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIHARDWARESECURITYENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmihardwaresecuritysettings.h>



struct DmiHardwareSecurityEntry
{
    DmiEntryHeader              header;
    DmiHardwareSecuritySettings settings;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIHARDWARESECURITYENTRY_H
