// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCIDEVICE3D3D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCIDEVICE3D3D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcisubdevice3d3d0002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcisubdevice3d3d0003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcisubdevice3d3d0006.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcisubdevice3d3d0008.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcisubdevice3d3d0009.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcisubdevice3d3d000a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcisubdevice3d3d000c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcisubdevice3d3d07a2.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice3D3D: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000C = 0x000C,
    DEVICE_000D = 0x000D,
    DEVICE_000E = 0x000E,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0020 = 0x0020,
    DEVICE_0022 = 0x0022,
    DEVICE_0024 = 0x0024,
    DEVICE_002C = 0x002C,
    DEVICE_0030 = 0x0030,
    DEVICE_0032 = 0x0032,
    DEVICE_0100 = 0x0100,
    DEVICE_07A1 = 0x07A1,
    DEVICE_07A2 = 0x07A2,
    DEVICE_07A3 = 0x07A3,
    DEVICE_1004 = 0x1004,
    DEVICE_3D04 = 0x3D04,
    DEVICE_FFFF = 0xFFFF
};



inline const char8* enumToString(PciDevice3D3D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice3D3D::NONE:        return "NONE";
        case PciDevice3D3D::DEVICE_0001: return "DEVICE_0001";
        case PciDevice3D3D::DEVICE_0002: return "DEVICE_0002";
        case PciDevice3D3D::DEVICE_0003: return "DEVICE_0003";
        case PciDevice3D3D::DEVICE_0004: return "DEVICE_0004";
        case PciDevice3D3D::DEVICE_0005: return "DEVICE_0005";
        case PciDevice3D3D::DEVICE_0006: return "DEVICE_0006";
        case PciDevice3D3D::DEVICE_0007: return "DEVICE_0007";
        case PciDevice3D3D::DEVICE_0008: return "DEVICE_0008";
        case PciDevice3D3D::DEVICE_0009: return "DEVICE_0009";
        case PciDevice3D3D::DEVICE_000A: return "DEVICE_000A";
        case PciDevice3D3D::DEVICE_000C: return "DEVICE_000C";
        case PciDevice3D3D::DEVICE_000D: return "DEVICE_000D";
        case PciDevice3D3D::DEVICE_000E: return "DEVICE_000E";
        case PciDevice3D3D::DEVICE_0011: return "DEVICE_0011";
        case PciDevice3D3D::DEVICE_0012: return "DEVICE_0012";
        case PciDevice3D3D::DEVICE_0013: return "DEVICE_0013";
        case PciDevice3D3D::DEVICE_0020: return "DEVICE_0020";
        case PciDevice3D3D::DEVICE_0022: return "DEVICE_0022";
        case PciDevice3D3D::DEVICE_0024: return "DEVICE_0024";
        case PciDevice3D3D::DEVICE_002C: return "DEVICE_002C";
        case PciDevice3D3D::DEVICE_0030: return "DEVICE_0030";
        case PciDevice3D3D::DEVICE_0032: return "DEVICE_0032";
        case PciDevice3D3D::DEVICE_0100: return "DEVICE_0100";
        case PciDevice3D3D::DEVICE_07A1: return "DEVICE_07A1";
        case PciDevice3D3D::DEVICE_07A2: return "DEVICE_07A2";
        case PciDevice3D3D::DEVICE_07A3: return "DEVICE_07A3";
        case PciDevice3D3D::DEVICE_1004: return "DEVICE_1004";
        case PciDevice3D3D::DEVICE_3D04: return "DEVICE_3D04";
        case PciDevice3D3D::DEVICE_FFFF: return "DEVICE_FFFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice3D3D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice3D3D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice3D3D::DEVICE_0001: return "GLINT 300SX";
        case PciDevice3D3D::DEVICE_0002: return "GLINT 500TX";
        case PciDevice3D3D::DEVICE_0003: return "GLINT Delta";
        case PciDevice3D3D::DEVICE_0004: return "Permedia";
        case PciDevice3D3D::DEVICE_0005: return "Permedia";
        case PciDevice3D3D::DEVICE_0006: return "GLINT MX";
        case PciDevice3D3D::DEVICE_0007: return "3D Extreme";
        case PciDevice3D3D::DEVICE_0008: return "GLINT Gamma G1";
        case PciDevice3D3D::DEVICE_0009: return "Permedia II 2D+3D";
        case PciDevice3D3D::DEVICE_000A: return "GLINT R3";
        case PciDevice3D3D::DEVICE_000C: return "GLINT R3 [Oxygen VX1]";
        case PciDevice3D3D::DEVICE_000D: return "GLint R4 rev A";
        case PciDevice3D3D::DEVICE_000E: return "GLINT Gamma G2";
        case PciDevice3D3D::DEVICE_0011: return "GLint R4 rev B";
        case PciDevice3D3D::DEVICE_0012: return "GLint R5 rev A";
        case PciDevice3D3D::DEVICE_0013: return "GLint R5 rev B";
        case PciDevice3D3D::DEVICE_0020: return "VP10 visual processor";
        case PciDevice3D3D::DEVICE_0022: return "VP10 visual processor";
        case PciDevice3D3D::DEVICE_0024: return "VP9 visual processor";
        case PciDevice3D3D::DEVICE_002C: return "Wildcat Realizm 100/200";
        case PciDevice3D3D::DEVICE_0030: return "Wildcat Realizm 800";
        case PciDevice3D3D::DEVICE_0032: return "Wildcat Realizm 500";
        case PciDevice3D3D::DEVICE_0100: return "Permedia II 2D+3D";
        case PciDevice3D3D::DEVICE_07A1: return "Wildcat III 6210";
        case PciDevice3D3D::DEVICE_07A2: return "Sun XVR-500 Graphics Accelerator";
        case PciDevice3D3D::DEVICE_07A3: return "Wildcat IV 7210";
        case PciDevice3D3D::DEVICE_1004: return "Permedia";
        case PciDevice3D3D::DEVICE_3D04: return "Permedia";
        case PciDevice3D3D::DEVICE_FFFF: return "Glint VGA";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice3D3D device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice3D3D::DEVICE_0001: return "Unknown device";
        case PciDevice3D3D::DEVICE_0002: return enumToHumanString((PciSubDevice3D3D0002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3D3D::DEVICE_0003: return enumToHumanString((PciSubDevice3D3D0003)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3D3D::DEVICE_0004: return "Unknown device";
        case PciDevice3D3D::DEVICE_0005: return "Unknown device";
        case PciDevice3D3D::DEVICE_0006: return enumToHumanString((PciSubDevice3D3D0006)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3D3D::DEVICE_0007: return "Unknown device";
        case PciDevice3D3D::DEVICE_0008: return enumToHumanString((PciSubDevice3D3D0008)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3D3D::DEVICE_0009: return enumToHumanString((PciSubDevice3D3D0009)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3D3D::DEVICE_000A: return enumToHumanString((PciSubDevice3D3D000A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3D3D::DEVICE_000C: return enumToHumanString((PciSubDevice3D3D000C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3D3D::DEVICE_000D: return "Unknown device";
        case PciDevice3D3D::DEVICE_000E: return "Unknown device";
        case PciDevice3D3D::DEVICE_0011: return "Unknown device";
        case PciDevice3D3D::DEVICE_0012: return "Unknown device";
        case PciDevice3D3D::DEVICE_0013: return "Unknown device";
        case PciDevice3D3D::DEVICE_0020: return "Unknown device";
        case PciDevice3D3D::DEVICE_0022: return "Unknown device";
        case PciDevice3D3D::DEVICE_0024: return "Unknown device";
        case PciDevice3D3D::DEVICE_002C: return "Unknown device";
        case PciDevice3D3D::DEVICE_0030: return "Unknown device";
        case PciDevice3D3D::DEVICE_0032: return "Unknown device";
        case PciDevice3D3D::DEVICE_0100: return "Unknown device";
        case PciDevice3D3D::DEVICE_07A1: return "Unknown device";
        case PciDevice3D3D::DEVICE_07A2: return enumToHumanString((PciSubDevice3D3D07A2)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3D3D::DEVICE_07A3: return "Unknown device";
        case PciDevice3D3D::DEVICE_1004: return "Unknown device";
        case PciDevice3D3D::DEVICE_3D04: return "Unknown device";
        case PciDevice3D3D::DEVICE_FFFF: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCIDEVICE3D3D_H
