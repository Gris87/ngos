#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKWIDTH_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKWIDTH_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressLinkWidth: u8
{
    NONE = 0,
    X1   = 1,
    X2   = 2,
    X4   = 4,
    X8   = 8,
    X12  = 12,
    X16  = 16,
    X32  = 32
};



inline const char8* enumToString(PciExpressLinkWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    switch (width)
    {
        case PciExpressLinkWidth::NONE: return "NONE";
        case PciExpressLinkWidth::X1:   return "X1";
        case PciExpressLinkWidth::X2:   return "X2";
        case PciExpressLinkWidth::X4:   return "X4";
        case PciExpressLinkWidth::X8:   return "X8";
        case PciExpressLinkWidth::X12:  return "X12";
        case PciExpressLinkWidth::X16:  return "X16";
        case PciExpressLinkWidth::X32:  return "X32";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressLinkWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)width, enumToString(width));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKWIDTH_H
