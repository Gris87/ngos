#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPE_H



#include <common/src/com/ngos/shared/common/dmi/dmientrytype.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmibaseboardtype.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelementtypeselect.h>



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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPE_H
