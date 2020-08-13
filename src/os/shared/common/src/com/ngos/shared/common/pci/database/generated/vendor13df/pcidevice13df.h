// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13DF_PCIDEVICE13DF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13DF_PCIDEVICE13DF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13DF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice13DF device13DF) // TEST: NO
{
    // COMMON_LT((" | device13DF = %u", device13DF)); // Commented to avoid bad looking logs



    switch (device13DF)
    {
        case PciDevice13DF::NONE:        return "NONE";
        case PciDevice13DF::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13DF device13DF) // TEST: NO
{
    // COMMON_LT((" | device13DF = %u", device13DF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device13DF, enumToString(device13DF));

    return res;
}



inline const char8* enumToHumanString(PciDevice13DF device13DF) // TEST: NO
{
    // COMMON_LT((" | device13DF = %u", device13DF)); // Commented to avoid bad looking logs



    switch (device13DF)
    {
        case PciDevice13DF::DEVICE_0001: return "PCI56RVP Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13DF_PCIDEVICE13DF_H
