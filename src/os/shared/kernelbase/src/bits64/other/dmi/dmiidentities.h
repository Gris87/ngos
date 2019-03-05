#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIIDENTITIES_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIIDENTITIES_H



#include <ngos/types.h>



enum class DmiIdentity: u8
{
    BIOS_VENDOR,
    BIOS_VERSION,
    BIOS_RELEASE_DATE,
    SYSTEM_MANUFACTURER,
    SYSTEM_PRODUCT_NAME,
    SYSTEM_VERSION,
    SYSTEM_SERIAL_NUMBER,
    SYSTEM_SKU_NUMBER,
    SYSTEM_FAMILY,
    MAX
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIIDENTITIES_H
