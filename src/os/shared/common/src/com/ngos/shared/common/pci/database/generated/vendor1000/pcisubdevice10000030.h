// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000030_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000030_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000030: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100DA = 0x0E1100DA,
    SUBDEVICE_10280123 = 0x10280123,
    SUBDEVICE_1028014A = 0x1028014A,
    SUBDEVICE_1028016C = 0x1028016C,
    SUBDEVICE_10280183 = 0x10280183,
    SUBDEVICE_1028018A = 0x1028018A,
    SUBDEVICE_10281010 = 0x10281010,
    SUBDEVICE_103C12C5 = 0x103C12C5,
    SUBDEVICE_103C1323 = 0x103C1323,
    SUBDEVICE_103C3108 = 0x103C3108,
    SUBDEVICE_103C322A = 0x103C322A,
    SUBDEVICE_124B1170 = 0x124B1170,
    SUBDEVICE_15AD1976 = 0x15AD1976,
    SUBDEVICE_17341052 = 0x17341052
};



inline const char8* enumToString(PciSubDevice10000030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000030::NONE:               return "NONE";
        case PciSubDevice10000030::SUBDEVICE_0E1100DA: return "SUBDEVICE_0E1100DA";
        case PciSubDevice10000030::SUBDEVICE_10280123: return "SUBDEVICE_10280123";
        case PciSubDevice10000030::SUBDEVICE_1028014A: return "SUBDEVICE_1028014A";
        case PciSubDevice10000030::SUBDEVICE_1028016C: return "SUBDEVICE_1028016C";
        case PciSubDevice10000030::SUBDEVICE_10280183: return "SUBDEVICE_10280183";
        case PciSubDevice10000030::SUBDEVICE_1028018A: return "SUBDEVICE_1028018A";
        case PciSubDevice10000030::SUBDEVICE_10281010: return "SUBDEVICE_10281010";
        case PciSubDevice10000030::SUBDEVICE_103C12C5: return "SUBDEVICE_103C12C5";
        case PciSubDevice10000030::SUBDEVICE_103C1323: return "SUBDEVICE_103C1323";
        case PciSubDevice10000030::SUBDEVICE_103C3108: return "SUBDEVICE_103C3108";
        case PciSubDevice10000030::SUBDEVICE_103C322A: return "SUBDEVICE_103C322A";
        case PciSubDevice10000030::SUBDEVICE_124B1170: return "SUBDEVICE_124B1170";
        case PciSubDevice10000030::SUBDEVICE_15AD1976: return "SUBDEVICE_15AD1976";
        case PciSubDevice10000030::SUBDEVICE_17341052: return "SUBDEVICE_17341052";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000030::SUBDEVICE_0E1100DA: return "ProLiant ML 350";
        case PciSubDevice10000030::SUBDEVICE_10280123: return "LSI Logic 1020/1030";
        case PciSubDevice10000030::SUBDEVICE_1028014A: return "LSI Logic 1020/1030";
        case PciSubDevice10000030::SUBDEVICE_1028016C: return "PowerEdge 1850 MPT Fusion SCSI/RAID (Perc 4)";
        case PciSubDevice10000030::SUBDEVICE_10280183: return "LSI Logic 1020/1030";
        case PciSubDevice10000030::SUBDEVICE_1028018A: return "PERC 4/IM";
        case PciSubDevice10000030::SUBDEVICE_10281010: return "LSI bad_uint320 SCSI Controller";
        case PciSubDevice10000030::SUBDEVICE_103C12C5: return "Ultra320 SCSI [A7173A]";
        case PciSubDevice10000030::SUBDEVICE_103C1323: return "Core I/O LAN/SCSI Combo [AB314A]";
        case PciSubDevice10000030::SUBDEVICE_103C3108: return "Single Channel Ultra320 SCSI HBA G2";
        case PciSubDevice10000030::SUBDEVICE_103C322A: return "SC11Xe Ultra320 Single Channel PCIe x4 SCSI Host Bus Adapter (412911-B21)";
        case PciSubDevice10000030::SUBDEVICE_124B1170: return "PMC-USCSbad_int320";
        case PciSubDevice10000030::SUBDEVICE_15AD1976: return "LSI Logic Parallel SCSI Controller";
        case PciSubDevice10000030::SUBDEVICE_17341052: return "PRIMERGY BX/RX/TX S2 series onboard SCSI(IME)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000030_H
