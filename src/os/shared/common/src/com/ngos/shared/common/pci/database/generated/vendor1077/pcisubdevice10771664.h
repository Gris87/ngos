// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771664_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771664_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10771664: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1077E4F1 = 0x1077E4F1,
    SUBDEVICE_1077E4F2 = 0x1077E4F2,
    SUBDEVICE_1077E4F3 = 0x1077E4F3,
    SUBDEVICE_1077E4F4 = 0x1077E4F4,
    SUBDEVICE_1077E4F6 = 0x1077E4F6,
    SUBDEVICE_1077E4F7 = 0x1077E4F7,
    SUBDEVICE_1077E4F8 = 0x1077E4F8,
    SUBDEVICE_15900245 = 0x15900245
};



inline const char8* enumToString(PciSubDevice10771664 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771664::NONE:               return "NONE";
        case PciSubDevice10771664::SUBDEVICE_1077E4F1: return "SUBDEVICE_1077E4F1";
        case PciSubDevice10771664::SUBDEVICE_1077E4F2: return "SUBDEVICE_1077E4F2";
        case PciSubDevice10771664::SUBDEVICE_1077E4F3: return "SUBDEVICE_1077E4F3";
        case PciSubDevice10771664::SUBDEVICE_1077E4F4: return "SUBDEVICE_1077E4F4";
        case PciSubDevice10771664::SUBDEVICE_1077E4F6: return "SUBDEVICE_1077E4F6";
        case PciSubDevice10771664::SUBDEVICE_1077E4F7: return "SUBDEVICE_1077E4F7";
        case PciSubDevice10771664::SUBDEVICE_1077E4F8: return "SUBDEVICE_1077E4F8";
        case PciSubDevice10771664::SUBDEVICE_15900245: return "SUBDEVICE_15900245";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10771664 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10771664 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771664::SUBDEVICE_1077E4F1: return "FastLinQ QL45462H 40GbE Adapter (SR-IOV VF)";
        case PciSubDevice10771664::SUBDEVICE_1077E4F2: return "FastLinQ QL45461H 40GbE Adapter (SR-IOV VF)";
        case PciSubDevice10771664::SUBDEVICE_1077E4F3: return "FastLinQ QL45412H 40GbE Adapter (SR-IOV VF)";
        case PciSubDevice10771664::SUBDEVICE_1077E4F4: return "FastLinQ QL45411H 40GbE Adapter (SR-IOV VF)";
        case PciSubDevice10771664::SUBDEVICE_1077E4F6: return "FastLinQ QL45211H 25GbE Adapter (SR-IOV VF)";
        case PciSubDevice10771664::SUBDEVICE_1077E4F7: return "FastLinQ QL45212H 25GbE Adapter (SR-IOV VF)";
        case PciSubDevice10771664::SUBDEVICE_1077E4F8: return "FastLinQ QL45611H 100GbE Adapter (SR-IOV VF)";
        case PciSubDevice10771664::SUBDEVICE_15900245: return "10/20/25GbE 2P 4820c CNA SRIOV";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771664_H
