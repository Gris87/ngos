// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79055_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79055_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B79055: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280080 = 0x10280080,
    SUBDEVICE_10280081 = 0x10280081,
    SUBDEVICE_10280082 = 0x10280082,
    SUBDEVICE_10280083 = 0x10280083,
    SUBDEVICE_10280084 = 0x10280084,
    SUBDEVICE_10280085 = 0x10280085,
    SUBDEVICE_10280086 = 0x10280086,
    SUBDEVICE_10280087 = 0x10280087,
    SUBDEVICE_10280088 = 0x10280088,
    SUBDEVICE_10280089 = 0x10280089,
    SUBDEVICE_10280090 = 0x10280090,
    SUBDEVICE_10280091 = 0x10280091,
    SUBDEVICE_10280092 = 0x10280092,
    SUBDEVICE_10280093 = 0x10280093,
    SUBDEVICE_10280094 = 0x10280094,
    SUBDEVICE_10280095 = 0x10280095,
    SUBDEVICE_10280096 = 0x10280096,
    SUBDEVICE_10280097 = 0x10280097,
    SUBDEVICE_10280098 = 0x10280098,
    SUBDEVICE_10280099 = 0x10280099,
    SUBDEVICE_10B79055 = 0x10B79055
};



inline const char8* enumToString(PciSubDevice10B79055 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79055::NONE:               return "NONE";
        case PciSubDevice10B79055::SUBDEVICE_10280080: return "SUBDEVICE_10280080";
        case PciSubDevice10B79055::SUBDEVICE_10280081: return "SUBDEVICE_10280081";
        case PciSubDevice10B79055::SUBDEVICE_10280082: return "SUBDEVICE_10280082";
        case PciSubDevice10B79055::SUBDEVICE_10280083: return "SUBDEVICE_10280083";
        case PciSubDevice10B79055::SUBDEVICE_10280084: return "SUBDEVICE_10280084";
        case PciSubDevice10B79055::SUBDEVICE_10280085: return "SUBDEVICE_10280085";
        case PciSubDevice10B79055::SUBDEVICE_10280086: return "SUBDEVICE_10280086";
        case PciSubDevice10B79055::SUBDEVICE_10280087: return "SUBDEVICE_10280087";
        case PciSubDevice10B79055::SUBDEVICE_10280088: return "SUBDEVICE_10280088";
        case PciSubDevice10B79055::SUBDEVICE_10280089: return "SUBDEVICE_10280089";
        case PciSubDevice10B79055::SUBDEVICE_10280090: return "SUBDEVICE_10280090";
        case PciSubDevice10B79055::SUBDEVICE_10280091: return "SUBDEVICE_10280091";
        case PciSubDevice10B79055::SUBDEVICE_10280092: return "SUBDEVICE_10280092";
        case PciSubDevice10B79055::SUBDEVICE_10280093: return "SUBDEVICE_10280093";
        case PciSubDevice10B79055::SUBDEVICE_10280094: return "SUBDEVICE_10280094";
        case PciSubDevice10B79055::SUBDEVICE_10280095: return "SUBDEVICE_10280095";
        case PciSubDevice10B79055::SUBDEVICE_10280096: return "SUBDEVICE_10280096";
        case PciSubDevice10B79055::SUBDEVICE_10280097: return "SUBDEVICE_10280097";
        case PciSubDevice10B79055::SUBDEVICE_10280098: return "SUBDEVICE_10280098";
        case PciSubDevice10B79055::SUBDEVICE_10280099: return "SUBDEVICE_10280099";
        case PciSubDevice10B79055::SUBDEVICE_10B79055: return "SUBDEVICE_10B79055";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B79055 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B79055 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79055::SUBDEVICE_10280080: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280081: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280082: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280083: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280084: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280085: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280086: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280087: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280088: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280089: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280090: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280091: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280092: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280093: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280094: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280095: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280096: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280097: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280098: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10280099: return "3C905B Fast Etherlink XL 10/100";
        case PciSubDevice10B79055::SUBDEVICE_10B79055: return "3C905B Fast Etherlink XL 10/100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79055_H
