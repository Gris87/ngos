#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSITEM_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSITEM_H



#include <common/src/com/ngos/shared/common/dmi/dmientrytype.h>



struct DmiGroupAssociationsItem
{
    DmiEntryType type;
    u16          handle;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIGROUPASSOCIATIONSITEM_H
