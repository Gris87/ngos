#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSGROUP_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSGROUP_H



#include <common/src/bits64/dmi/dmientrytype.h>



struct DmiGroupAssociationsGroup
{
    DmiEntryType type;
    u16          handle;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSGROUP_H
