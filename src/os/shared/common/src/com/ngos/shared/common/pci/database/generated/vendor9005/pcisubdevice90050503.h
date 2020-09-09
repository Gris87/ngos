// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050503_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050503_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050503: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101402BF = 0x101402BF,
    SUBDEVICE_101402C3 = 0x101402C3,
    SUBDEVICE_101402D5 = 0x101402D5
};



inline const char8* enumToString(PciSubDevice90050503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050503::NONE:               return "NONE";
        case PciSubDevice90050503::SUBDEVICE_101402BF: return "SUBDEVICE_101402BF";
        case PciSubDevice90050503::SUBDEVICE_101402C3: return "SUBDEVICE_101402C3";
        case PciSubDevice90050503::SUBDEVICE_101402D5: return "SUBDEVICE_101402D5";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050503::SUBDEVICE_101402BF: return "Quad Channel PCI-X DDR U320 SCSI RAID Adapter (571E)";
        case PciSubDevice90050503::SUBDEVICE_101402C3: return "PCI-X DDR 3Gb SAS RAID Adapter (572F)";
        case PciSubDevice90050503::SUBDEVICE_101402D5: return "Quad Channel PCI-X DDR U320 SCSI RAID Adapter (571F)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050503_H
