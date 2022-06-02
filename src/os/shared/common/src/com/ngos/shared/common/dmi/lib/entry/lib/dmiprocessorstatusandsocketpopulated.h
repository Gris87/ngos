#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorstatus.h>



struct DmiProcessorStatusAndSocketPopulated
{
    union
    {
        struct
        {
            u8 status:          3; // TODO: Use enum DmiProcessorStatus
            u8 __reserved:      3;
            u8 socketPopulated: 1;
            u8 __reserved2:     1;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H
