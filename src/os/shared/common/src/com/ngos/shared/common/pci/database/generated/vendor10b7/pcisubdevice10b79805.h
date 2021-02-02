// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79805_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79805_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B79805: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B71201 = 0x10B71201,
    SUBDEVICE_10B71202 = 0x10B71202,
    SUBDEVICE_10B79805 = 0x10B79805,
    SUBDEVICE_10F12462 = 0x10F12462
};



inline const char8* enumToString(PciSubDevice10B79805 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79805::NONE:               return "NONE";
        case PciSubDevice10B79805::SUBDEVICE_10B71201: return "SUBDEVICE_10B71201";
        case PciSubDevice10B79805::SUBDEVICE_10B71202: return "SUBDEVICE_10B71202";
        case PciSubDevice10B79805::SUBDEVICE_10B79805: return "SUBDEVICE_10B79805";
        case PciSubDevice10B79805::SUBDEVICE_10F12462: return "SUBDEVICE_10F12462";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B79805 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B79805 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79805::SUBDEVICE_10B71201: return "EtherLink Server 10/100 Dual Port A";
        case PciSubDevice10B79805::SUBDEVICE_10B71202: return "EtherLink Server 10/100 Dual Port B";
        case PciSubDevice10B79805::SUBDEVICE_10B79805: return "3c980 10/100baseTX NIC [Python-T]";
        case PciSubDevice10B79805::SUBDEVICE_10F12462: return "Thunder K7 S2462";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79805_H
