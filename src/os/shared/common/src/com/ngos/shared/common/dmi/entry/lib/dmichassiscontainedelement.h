#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H



#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelementtype.h>



struct DmiChassisContainedElement
{
    DmiChassisContainedElementType type;
    u8                             minimum;
    u8                             maximum;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H
