#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPE_H



#include <com/ngos/shared/common/dmi/dmientrytype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibaseboardtype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelementtypeselect.h>



struct DmiChassisContainedElementType
{
    union
    {
        // DmiChassisContainedElementTypeSelect::BASEBOARD_TYPE
        struct
        {
            u8 baseboardType: 7; // TODO: Use enum DmiBaseboardType
            u8 typeSelect:    1; // TODO: Use enum DmiChassisContainedElementTypeSelect
        };

        // DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE
        struct
        {
            u8 dmiEntryType: 7; // TODO: Use enum DmiEntryType
            u8 __pad:        1; // Ignore this field. The same as typeSelect
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPE_H
