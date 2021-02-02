// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000411_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000411_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000411: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10001001 = 0x10001001,
    SUBDEVICE_10001002 = 0x10001002,
    SUBDEVICE_10001003 = 0x10001003,
    SUBDEVICE_10001004 = 0x10001004,
    SUBDEVICE_10001008 = 0x10001008,
    SUBDEVICE_1000100C = 0x1000100C,
    SUBDEVICE_1000100D = 0x1000100D,
    SUBDEVICE_10002004 = 0x10002004,
    SUBDEVICE_10002005 = 0x10002005,
    SUBDEVICE_10338287 = 0x10338287,
    SUBDEVICE_10543016 = 0x10543016,
    SUBDEVICE_17341081 = 0x17341081,
    SUBDEVICE_173410A3 = 0x173410A3,
    SUBDEVICE_80861001 = 0x80861001,
    SUBDEVICE_80861003 = 0x80861003,
    SUBDEVICE_80863500 = 0x80863500,
    SUBDEVICE_80863501 = 0x80863501,
    SUBDEVICE_80863504 = 0x80863504
};



inline const char8* enumToString(PciSubDevice10000411 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000411::NONE:               return "NONE";
        case PciSubDevice10000411::SUBDEVICE_10001001: return "SUBDEVICE_10001001";
        case PciSubDevice10000411::SUBDEVICE_10001002: return "SUBDEVICE_10001002";
        case PciSubDevice10000411::SUBDEVICE_10001003: return "SUBDEVICE_10001003";
        case PciSubDevice10000411::SUBDEVICE_10001004: return "SUBDEVICE_10001004";
        case PciSubDevice10000411::SUBDEVICE_10001008: return "SUBDEVICE_10001008";
        case PciSubDevice10000411::SUBDEVICE_1000100C: return "SUBDEVICE_1000100C";
        case PciSubDevice10000411::SUBDEVICE_1000100D: return "SUBDEVICE_1000100D";
        case PciSubDevice10000411::SUBDEVICE_10002004: return "SUBDEVICE_10002004";
        case PciSubDevice10000411::SUBDEVICE_10002005: return "SUBDEVICE_10002005";
        case PciSubDevice10000411::SUBDEVICE_10338287: return "SUBDEVICE_10338287";
        case PciSubDevice10000411::SUBDEVICE_10543016: return "SUBDEVICE_10543016";
        case PciSubDevice10000411::SUBDEVICE_17341081: return "SUBDEVICE_17341081";
        case PciSubDevice10000411::SUBDEVICE_173410A3: return "SUBDEVICE_173410A3";
        case PciSubDevice10000411::SUBDEVICE_80861001: return "SUBDEVICE_80861001";
        case PciSubDevice10000411::SUBDEVICE_80861003: return "SUBDEVICE_80861003";
        case PciSubDevice10000411::SUBDEVICE_80863500: return "SUBDEVICE_80863500";
        case PciSubDevice10000411::SUBDEVICE_80863501: return "SUBDEVICE_80863501";
        case PciSubDevice10000411::SUBDEVICE_80863504: return "SUBDEVICE_80863504";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000411 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000411 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000411::SUBDEVICE_10001001: return "MegaRAID SAS 8408E";
        case PciSubDevice10000411::SUBDEVICE_10001002: return "MegaRAID SAS 8480E";
        case PciSubDevice10000411::SUBDEVICE_10001003: return "MegaRAID SAS 8344ELP";
        case PciSubDevice10000411::SUBDEVICE_10001004: return "MegaRAID SAS 8308ELP";
        case PciSubDevice10000411::SUBDEVICE_10001008: return "MegaRAID SAS 84016E";
        case PciSubDevice10000411::SUBDEVICE_1000100C: return "MegaRAID SATA 300-12E";
        case PciSubDevice10000411::SUBDEVICE_1000100D: return "MegaRAID SATA 300-16E";
        case PciSubDevice10000411::SUBDEVICE_10002004: return "MegaRAID SATA 300-8ELP";
        case PciSubDevice10000411::SUBDEVICE_10002005: return "MegaRAID SATA 300-4ELP";
        case PciSubDevice10000411::SUBDEVICE_10338287: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000411::SUBDEVICE_10543016: return "MegaRAID SAS RoMB Server";
        case PciSubDevice10000411::SUBDEVICE_17341081: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000411::SUBDEVICE_173410A3: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000411::SUBDEVICE_80861001: return "RAID Controller SRCSAS18E";
        case PciSubDevice10000411::SUBDEVICE_80861003: return "RAID Controller SRCSAS144E";
        case PciSubDevice10000411::SUBDEVICE_80863500: return "SROMBSAS18E RAID Controller";
        case PciSubDevice10000411::SUBDEVICE_80863501: return "SROMBSAS18E RAID Controller";
        case PciSubDevice10000411::SUBDEVICE_80863504: return "SROMBSAS18E RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000411_H
