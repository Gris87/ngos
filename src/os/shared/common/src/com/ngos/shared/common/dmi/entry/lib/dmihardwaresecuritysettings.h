#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSETTINGS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSETTINGS_H



#include <com/ngos/shared/common/dmi/entry/lib/dmihardwaresecuritystatus.h>



struct DmiHardwareSecuritySettings
{
    union
    {
        struct
        {
            u8 frontPanelResetStatus:       2; // TODO: Use enum DmiHardwareSecurityStatus
            u8 administratorPasswordStatus: 2; // TODO: Use enum DmiHardwareSecurityStatus
            u8 keyboardPasswordStatus:      2; // TODO: Use enum DmiHardwareSecurityStatus
            u8 powerOnPasswordStatus:       2; // TODO: Use enum DmiHardwareSecurityStatus
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSETTINGS_H
