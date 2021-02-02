// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA824_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA824_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice144DA824: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282040 = 0x10282040,
    SUBDEVICE_10282041 = 0x10282041,
    SUBDEVICE_10282042 = 0x10282042,
    SUBDEVICE_10282043 = 0x10282043,
    SUBDEVICE_10282044 = 0x10282044,
    SUBDEVICE_10282045 = 0x10282045,
    SUBDEVICE_10282046 = 0x10282046,
    SUBDEVICE_10282070 = 0x10282070,
    SUBDEVICE_10282071 = 0x10282071,
    SUBDEVICE_10282072 = 0x10282072,
    SUBDEVICE_10282073 = 0x10282073,
    SUBDEVICE_10282074 = 0x10282074,
    SUBDEVICE_10282075 = 0x10282075,
    SUBDEVICE_10282076 = 0x10282076,
    SUBDEVICE_10282090 = 0x10282090,
    SUBDEVICE_10282091 = 0x10282091,
    SUBDEVICE_10282092 = 0x10282092,
    SUBDEVICE_10282093 = 0x10282093,
    SUBDEVICE_10282094 = 0x10282094,
    SUBDEVICE_10282095 = 0x10282095,
    SUBDEVICE_10282096 = 0x10282096,
    SUBDEVICE_10282097 = 0x10282097,
    SUBDEVICE_10282098 = 0x10282098,
    SUBDEVICE_10282099 = 0x10282099
};



inline const char8* enumToString(PciSubDevice144DA824 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA824::NONE:               return "NONE";
        case PciSubDevice144DA824::SUBDEVICE_10282040: return "SUBDEVICE_10282040";
        case PciSubDevice144DA824::SUBDEVICE_10282041: return "SUBDEVICE_10282041";
        case PciSubDevice144DA824::SUBDEVICE_10282042: return "SUBDEVICE_10282042";
        case PciSubDevice144DA824::SUBDEVICE_10282043: return "SUBDEVICE_10282043";
        case PciSubDevice144DA824::SUBDEVICE_10282044: return "SUBDEVICE_10282044";
        case PciSubDevice144DA824::SUBDEVICE_10282045: return "SUBDEVICE_10282045";
        case PciSubDevice144DA824::SUBDEVICE_10282046: return "SUBDEVICE_10282046";
        case PciSubDevice144DA824::SUBDEVICE_10282070: return "SUBDEVICE_10282070";
        case PciSubDevice144DA824::SUBDEVICE_10282071: return "SUBDEVICE_10282071";
        case PciSubDevice144DA824::SUBDEVICE_10282072: return "SUBDEVICE_10282072";
        case PciSubDevice144DA824::SUBDEVICE_10282073: return "SUBDEVICE_10282073";
        case PciSubDevice144DA824::SUBDEVICE_10282074: return "SUBDEVICE_10282074";
        case PciSubDevice144DA824::SUBDEVICE_10282075: return "SUBDEVICE_10282075";
        case PciSubDevice144DA824::SUBDEVICE_10282076: return "SUBDEVICE_10282076";
        case PciSubDevice144DA824::SUBDEVICE_10282090: return "SUBDEVICE_10282090";
        case PciSubDevice144DA824::SUBDEVICE_10282091: return "SUBDEVICE_10282091";
        case PciSubDevice144DA824::SUBDEVICE_10282092: return "SUBDEVICE_10282092";
        case PciSubDevice144DA824::SUBDEVICE_10282093: return "SUBDEVICE_10282093";
        case PciSubDevice144DA824::SUBDEVICE_10282094: return "SUBDEVICE_10282094";
        case PciSubDevice144DA824::SUBDEVICE_10282095: return "SUBDEVICE_10282095";
        case PciSubDevice144DA824::SUBDEVICE_10282096: return "SUBDEVICE_10282096";
        case PciSubDevice144DA824::SUBDEVICE_10282097: return "SUBDEVICE_10282097";
        case PciSubDevice144DA824::SUBDEVICE_10282098: return "SUBDEVICE_10282098";
        case PciSubDevice144DA824::SUBDEVICE_10282099: return "SUBDEVICE_10282099";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice144DA824 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice144DA824 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA824::SUBDEVICE_10282040: return "EMC PowerEdge Express Flash Ent NVMe AGN MU U.2 Gen4 1.6TB";
        case PciSubDevice144DA824::SUBDEVICE_10282041: return "EMC PowerEdge Express Flash Ent NVMe AGN MU U.2 Gen4 3.2TB";
        case PciSubDevice144DA824::SUBDEVICE_10282042: return "EMC PowerEdge Express Flash Ent NVMe AGN MU U.2 Gen4 6.4TB";
        case PciSubDevice144DA824::SUBDEVICE_10282043: return "EMC PowerEdge Express Flash Ent NVMe AGN MU U.2 Gen4 12.8TB";
        case PciSubDevice144DA824::SUBDEVICE_10282044: return "EMC PowerEdge Express Flash Ent NVMe AGN MU AIC Gen4 1.6TB";
        case PciSubDevice144DA824::SUBDEVICE_10282045: return "EMC PowerEdge Express Flash Ent NVMe AGN MU AIC Gen4 3.2TB";
        case PciSubDevice144DA824::SUBDEVICE_10282046: return "EMC PowerEdge Express Flash Ent NVMe AGN MU AIC Gen4 6.4TB";
        case PciSubDevice144DA824::SUBDEVICE_10282070: return "EMC PowerEdge Express Flash Ent NVMe AGN RI U.2 Gen4 1.92TB";
        case PciSubDevice144DA824::SUBDEVICE_10282071: return "EMC PowerEdge Express Flash Ent NVMe AGN RI U.2 Gen4 3.84TB";
        case PciSubDevice144DA824::SUBDEVICE_10282072: return "EMC PowerEdge Express Flash Ent NVMe AGN RI U.2 Gen4 7.68TB";
        case PciSubDevice144DA824::SUBDEVICE_10282073: return "EMC PowerEdge Express Flash Ent NVMe AGN RI U.2 Gen4 15.36TB";
        case PciSubDevice144DA824::SUBDEVICE_10282074: return "EMC PowerEdge Express Flash Ent NVMe AGN RI AIC Gen4 1.92TB";
        case PciSubDevice144DA824::SUBDEVICE_10282075: return "EMC PowerEdge Express Flash Ent NVMe AGN RI AIC Gen4 3.84TB";
        case PciSubDevice144DA824::SUBDEVICE_10282076: return "EMC PowerEdge Express Flash Ent NVMe AGN RI AIC Gen4 7.68TB";
        case PciSubDevice144DA824::SUBDEVICE_10282090: return "EMC PowerEdge Express Flash Ent NVMe AGN SED MU U.2 Gen4 1.6TB";
        case PciSubDevice144DA824::SUBDEVICE_10282091: return "EMC PowerEdge Express Flash Ent NVMe AGN SED MU U.2 Gen4 3.2TB";
        case PciSubDevice144DA824::SUBDEVICE_10282092: return "EMC PowerEdge Express Flash Ent NVMe AGN SED MU U.2 Gen4 6.4TB";
        case PciSubDevice144DA824::SUBDEVICE_10282093: return "EMC PowerEdge Express Flash Ent NVMe AGN SED MU U.2 Gen4 12.8TB";
        case PciSubDevice144DA824::SUBDEVICE_10282094: return "EMC PowerEdge Express Flash Ent NVMe AGN SED MU AIC Gen4 1.6TB";
        case PciSubDevice144DA824::SUBDEVICE_10282095: return "EMC PowerEdge Express Flash Ent NVMe AGN SED MU AIC Gen4 3.2TB";
        case PciSubDevice144DA824::SUBDEVICE_10282096: return "EMC PowerEdge Express Flash Ent NVMe AGN SED MU AIC Gen4 6.4TB";
        case PciSubDevice144DA824::SUBDEVICE_10282097: return "EMC PowerEdge Express Flash Ent NVMe AGN SED RI U.2 Gen4 1.92TB";
        case PciSubDevice144DA824::SUBDEVICE_10282098: return "EMC PowerEdge Express Flash Ent NVMe AGN SED RI U.2 Gen4 3.84TB";
        case PciSubDevice144DA824::SUBDEVICE_10282099: return "EMC PowerEdge Express Flash Ent NVMe AGN SED RI U.2 Gen4 7.68TB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA824_H
