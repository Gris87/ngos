#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIHARDWARESECURITYENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIHARDWARESECURITYENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmihardwaresecuritysettings.h>



struct DmiHardwareSecurityEntry
{
    DmiEntryHeader              header;
    DmiHardwareSecuritySettings settings;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIHARDWARESECURITYENTRY_H
