#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICESTATUSFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICESTATUSFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_express_device_status_flags;

enum class PciExpressDeviceStatusFlag: pci_express_device_status_flags
{
    NONE                         = 0,
    CORRECTABLE_ERROR_DETECTED   = (1ULL << 0),
    NON_FATAL_ERROR_DETECTED     = (1ULL << 1),
    FATAL_ERROR_DETECTED         = (1ULL << 2),
    UNSUPPORTED_REQUEST_DETECTED = (1ULL << 3),
    AUX_POWER_DETECTED           = (1ULL << 4),
    TRANSACTIONS_PENDING         = (1ULL << 5)
};

DEFINE_FLAGS(PciExpressDeviceStatusFlags, pci_express_device_status_flags); // TEST: NO



inline const char8* flagToString(PciExpressDeviceStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressDeviceStatusFlag::NONE:                         return "NONE";
        case PciExpressDeviceStatusFlag::CORRECTABLE_ERROR_DETECTED:   return "CORRECTABLE_ERROR_DETECTED";
        case PciExpressDeviceStatusFlag::NON_FATAL_ERROR_DETECTED:     return "NON_FATAL_ERROR_DETECTED";
        case PciExpressDeviceStatusFlag::FATAL_ERROR_DETECTED:         return "FATAL_ERROR_DETECTED";
        case PciExpressDeviceStatusFlag::UNSUPPORTED_REQUEST_DETECTED: return "UNSUPPORTED_REQUEST_DETECTED";
        case PciExpressDeviceStatusFlag::AUX_POWER_DETECTED:           return "AUX_POWER_DETECTED";
        case PciExpressDeviceStatusFlag::TRANSACTIONS_PENDING:         return "TRANSACTIONS_PENDING";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressDeviceStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%04X (%s)", (pci_express_device_status_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressDeviceStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[167];

    FLAGS_TO_STRING(res, flags.flags, PciExpressDeviceStatusFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressDeviceStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[176];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressDeviceStatusFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICESTATUSFLAGS_H
