#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSEXTENSION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSEXTENSION_H



#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsbiosreservedflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicssystemreservedflags.h>



struct DmiBiosCharacteristicsExtension
{
    dmi_bios_characteristics_bios_reserved_flags   biosReserved;
    dmi_bios_characteristics_system_reserved_flags systemReserved;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSEXTENSION_H
