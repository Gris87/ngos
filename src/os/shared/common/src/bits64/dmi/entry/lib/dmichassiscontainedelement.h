#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H



#include <common/src/bits64/dmi/dmientrytype.h>
#include <common/src/bits64/dmi/entry/lib/dmibaseboardtype.h>
#include <common/src/bits64/dmi/entry/lib/dmichassiscontainedelementtypeselect.h>



struct DmiChassisContainedElement
{
    union
    {
        struct
        {
            u8 baseboardtype: 7; // TODO: Use enum DmiBaseboardType
            u8 typeSelect:    1; // TODO: Use enum DmiChassisContainedElementTypeSelect
        };

        struct
        {
            u8 dmiEntrytype: 7; // TODO: Use enum DmiEntryType
            u8 __pad:        1; // Ignore this field. The same as typeSelect
        };

        u8 typeAndTypeSelect;
    };

    u8 minimum;
    u8 maximum;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H
