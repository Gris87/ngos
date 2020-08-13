// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C8_PCIDEVICE11C8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C8_PCIDEVICE11C8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11C8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0658 = 0x0658,
    DEVICE_D665 = 0xD665,
    DEVICE_D667 = 0xD667
};



inline const char8* enumToString(PciDevice11C8 device11C8) // TEST: NO
{
    // COMMON_LT((" | device11C8 = %u", device11C8)); // Commented to avoid bad looking logs



    switch (device11C8)
    {
        case PciDevice11C8::NONE:        return "NONE";
        case PciDevice11C8::DEVICE_0658: return "DEVICE_0658";
        case PciDevice11C8::DEVICE_D665: return "DEVICE_D665";
        case PciDevice11C8::DEVICE_D667: return "DEVICE_D667";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11C8 device11C8) // TEST: NO
{
    // COMMON_LT((" | device11C8 = %u", device11C8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11C8, enumToString(device11C8));

    return res;
}



inline const char8* enumToHumanString(PciDevice11C8 device11C8) // TEST: NO
{
    // COMMON_LT((" | device11C8 = %u", device11C8)); // Commented to avoid bad looking logs



    switch (device11C8)
    {
        case PciDevice11C8::DEVICE_0658: return "PSB32 SCI-Adapter D31x";
        case PciDevice11C8::DEVICE_D665: return "PSB64 SCI-Adapter D32x";
        case PciDevice11C8::DEVICE_D667: return "PSB66 SCI-Adapter D33x";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C8_PCIDEVICE11C8_H
