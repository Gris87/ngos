#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSITEM_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSITEM_H



#include <com/ngos/shared/common/dmi/dmientrytype.h>



struct DmiGroupAssociationsItem
{
    DmiEntryType type;
    u16          handle;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSITEM_H
