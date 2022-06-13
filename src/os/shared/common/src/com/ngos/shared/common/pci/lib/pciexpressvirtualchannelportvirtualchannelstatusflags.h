#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELSTATUSFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELSTATUSFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_express_virtual_channel_port_virtual_channel_status_flags;

enum class PciExpressVirtualChannelPortVirtualChannelStatusFlag: pci_express_virtual_channel_port_virtual_channel_status_flags
{
    NONE                                     = 0,
    VIRTUAL_CHANNEL_ARBITRATION_TABLE_STATUS = BIT_0
};

DEFINE_FLAGS(PciExpressVirtualChannelPortVirtualChannelStatusFlags, pci_express_virtual_channel_port_virtual_channel_status_flags); // TEST: NO



inline const char8* flagToString(PciExpressVirtualChannelPortVirtualChannelStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressVirtualChannelPortVirtualChannelStatusFlag::NONE:                                     return "NONE";
        case PciExpressVirtualChannelPortVirtualChannelStatusFlag::VIRTUAL_CHANNEL_ARBITRATION_TABLE_STATUS: return "VIRTUAL_CHANNEL_ARBITRATION_TABLE_STATUS";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressVirtualChannelPortVirtualChannelStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[50];

    sprintf(res, "0x%04X (%s)", (pci_express_virtual_channel_port_virtual_channel_status_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressVirtualChannelPortVirtualChannelStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[56];

    FLAGS_TO_STRING(res, flags.flags, PciExpressVirtualChannelPortVirtualChannelStatusFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressVirtualChannelPortVirtualChannelStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[65];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressVirtualChannelPortVirtualChannelStatusFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELSTATUSFLAGS_H
