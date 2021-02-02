#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H



#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorstatus.h>



struct DmiProcessorStatusAndSocketPopulated
{
    union
    {
        struct
        {
            bad_uint8 status:          3; // TODO: Use enum DmiProcessorStatus
            bad_uint8 __reserved:      3;
            bad_uint8 socketPopulated: 1;
            bad_uint8 __reserved2:     1;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H
