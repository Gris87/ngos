#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSETTINGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSETTINGS_H



#include <com/ngos/shared/common/dmi/entry/lib/dmihardwaresecuritystatus.h>



struct DmiHardwareSecuritySettings
{
    union
    {
        struct
        {
            bad_uint8 frontPanelResetStatus:       2; // TODO: Use enum DmiHardwareSecurityStatus
            bad_uint8 administratorPasswordStatus: 2; // TODO: Use enum DmiHardwareSecurityStatus
            bad_uint8 keyboardPasswordStatus:      2; // TODO: Use enum DmiHardwareSecurityStatus
            bad_uint8 powerOnPasswordStatus:       2; // TODO: Use enum DmiHardwareSecurityStatus
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSETTINGS_H
