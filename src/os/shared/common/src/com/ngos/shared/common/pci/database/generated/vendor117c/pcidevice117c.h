// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCIDEVICE117C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCIDEVICE117C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice117C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_002C = 0x002C,
    DEVICE_002D = 0x002D,
    DEVICE_0030 = 0x0030,
    DEVICE_0033 = 0x0033,
    DEVICE_0041 = 0x0041,
    DEVICE_0042 = 0x0042,
    DEVICE_0049 = 0x0049,
    DEVICE_0064 = 0x0064,
    DEVICE_0094 = 0x0094,
    DEVICE_8013 = 0x8013,
    DEVICE_8014 = 0x8014,
    DEVICE_8027 = 0x8027,
    DEVICE_8070 = 0x8070,
    DEVICE_8072 = 0x8072
};



inline const char8* enumToString(PciDevice117C device117C) // TEST: NO
{
    // COMMON_LT((" | device117C = %u", device117C)); // Commented to avoid bad looking logs



    switch (device117C)
    {
        case PciDevice117C::NONE:        return "NONE";
        case PciDevice117C::DEVICE_002C: return "DEVICE_002C";
        case PciDevice117C::DEVICE_002D: return "DEVICE_002D";
        case PciDevice117C::DEVICE_0030: return "DEVICE_0030";
        case PciDevice117C::DEVICE_0033: return "DEVICE_0033";
        case PciDevice117C::DEVICE_0041: return "DEVICE_0041";
        case PciDevice117C::DEVICE_0042: return "DEVICE_0042";
        case PciDevice117C::DEVICE_0049: return "DEVICE_0049";
        case PciDevice117C::DEVICE_0064: return "DEVICE_0064";
        case PciDevice117C::DEVICE_0094: return "DEVICE_0094";
        case PciDevice117C::DEVICE_8013: return "DEVICE_8013";
        case PciDevice117C::DEVICE_8014: return "DEVICE_8014";
        case PciDevice117C::DEVICE_8027: return "DEVICE_8027";
        case PciDevice117C::DEVICE_8070: return "DEVICE_8070";
        case PciDevice117C::DEVICE_8072: return "DEVICE_8072";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice117C device117C) // TEST: NO
{
    // COMMON_LT((" | device117C = %u", device117C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device117C, enumToString(device117C));

    return res;
}



inline const char8* enumToHumanString(PciDevice117C device117C) // TEST: NO
{
    // COMMON_LT((" | device117C = %u", device117C)); // Commented to avoid bad looking logs



    switch (device117C)
    {
        case PciDevice117C::DEVICE_002C: return "ExpressSAS R380";
        case PciDevice117C::DEVICE_002D: return "ExpressSAS R348";
        case PciDevice117C::DEVICE_0030: return "Ultra320 SCSI Host Adapter";
        case PciDevice117C::DEVICE_0033: return "SAS Adapter";
        case PciDevice117C::DEVICE_0041: return "ExpressSAS R30F";
        case PciDevice117C::DEVICE_0042: return "ExpressSAS 6Gb/s SAS/SATA HBA";
        case PciDevice117C::DEVICE_0049: return "ExpressSAS 6Gb SAS/SATA RAID Adapter";
        case PciDevice117C::DEVICE_0064: return "Celerity FC 16Gb/s Gen 5 Fibre Channel HBA";
        case PciDevice117C::DEVICE_0094: return "Celerity FC 16/32Gb/s Gen 6 Fibre Channel HBA";
        case PciDevice117C::DEVICE_8013: return "ExpressPCI UL4D";
        case PciDevice117C::DEVICE_8014: return "ExpressPCI UL4S";
        case PciDevice117C::DEVICE_8027: return "ExpressPCI UL5D";
        case PciDevice117C::DEVICE_8070: return "ExpressSAS 12Gb/s SAS/SATA HBA";
        case PciDevice117C::DEVICE_8072: return "ExpressSAS 12Gb/s SAS/SATA HBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCIDEVICE117C_H
