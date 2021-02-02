#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H



#include <com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelementtype.h>



struct DmiChassisContainedElement
{
    DmiChassisContainedElementType type;
    bad_uint8                             minimum;
    bad_uint8                             maximum;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENT_H
