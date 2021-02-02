#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONTABLEENTRYSIZE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONTABLEENTRYSIZE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressVirtualChannelPortArbitrationTableEntrySize: bad_uint8
{
    _1_BIT  = 0,
    _2_BITS = 1,
    _4_BITS = 2,
    _8_BITS = 3
};



inline const char8* enumToString(PciExpressVirtualChannelPortArbitrationTableEntrySize size) // TEST: NO
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid bad looking logs



    switch (size)
    {
        case PciExpressVirtualChannelPortArbitrationTableEntrySize::_1_BIT:  return "1_BIT";
        case PciExpressVirtualChannelPortArbitrationTableEntrySize::_2_BITS: return "2_BITS";
        case PciExpressVirtualChannelPortArbitrationTableEntrySize::_4_BITS: return "4_BITS";
        case PciExpressVirtualChannelPortArbitrationTableEntrySize::_8_BITS: return "8_BITS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressVirtualChannelPortArbitrationTableEntrySize size) // TEST: NO
{
    // COMMON_LT((" | size = %u", size)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (bad_uint8)size, enumToString(size));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONTABLEENTRYSIZE_H
