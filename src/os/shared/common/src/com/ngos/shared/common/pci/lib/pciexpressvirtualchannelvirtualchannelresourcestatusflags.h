#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCESTATUSFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCESTATUSFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint16 pci_express_virtual_channel_virtual_channel_resource_status_flags;

enum class PciExpressVirtualChannelVirtualChannelResourceStatusFlag: pci_express_virtual_channel_virtual_channel_resource_status_flags
{
    NONE                                = 0,
    PORT_ARBITRATION_TABLE_STATUS       = (1ULL << 0),
    VIRTUAL_CHANNEL_NEGOTIATION_PENDING = (1ULL << 1)
};

DEFINE_FLAGS(PciExpressVirtualChannelVirtualChannelResourceStatusFlags, pci_express_virtual_channel_virtual_channel_resource_status_flags); // TEST: NO



inline const char8* flagToString(PciExpressVirtualChannelVirtualChannelResourceStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressVirtualChannelVirtualChannelResourceStatusFlag::NONE:                                return "NONE";
        case PciExpressVirtualChannelVirtualChannelResourceStatusFlag::PORT_ARBITRATION_TABLE_STATUS:       return "PORT_ARBITRATION_TABLE_STATUS";
        case PciExpressVirtualChannelVirtualChannelResourceStatusFlag::VIRTUAL_CHANNEL_NEGOTIATION_PENDING: return "VIRTUAL_CHANNEL_NEGOTIATION_PENDING";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressVirtualChannelVirtualChannelResourceStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[45];

    sprintf(res, "0x%04X (%s)", (pci_express_virtual_channel_virtual_channel_resource_status_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressVirtualChannelVirtualChannelResourceStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[83];

    FLAGS_TO_STRING(res, flags.flags, PciExpressVirtualChannelVirtualChannelResourceStatusFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressVirtualChannelVirtualChannelResourceStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[92];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressVirtualChannelVirtualChannelResourceStatusFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCESTATUSFLAGS_H
