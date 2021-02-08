#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSREADCOMPLETIONBOUNDARY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSREADCOMPLETIONBOUNDARY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressReadCompletionBoundary: u8
{
    _64_BYTES  = 0,
    _128_BYTES = 1
};



inline const char8* enumToString(PciExpressReadCompletionBoundary boundary) // TEST: NO
{
    // COMMON_LT((" | boundary = %u", boundary)); // Commented to avoid bad looking logs



    switch (boundary)
    {
        case PciExpressReadCompletionBoundary::_64_BYTES:  return "64_BYTES";
        case PciExpressReadCompletionBoundary::_128_BYTES: return "128_BYTES";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressReadCompletionBoundary boundary) // TEST: NO
{
    // COMMON_LT((" | boundary = %u", boundary)); // Commented to avoid bad looking logs



    static char8 res[17];

    sprintf(res, "0x%02X (%s)", (u8)boundary, enumToString(boundary));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSREADCOMPLETIONBOUNDARY_H
