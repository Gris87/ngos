#ifndef DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERIMAGE_H
#define DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERIMAGE_H



#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class DeviceManagerImage: u8
{
    ADDITIONAL,
    BASEBOARD,
    BIOS,
    BIOS_LANGUAGE,
    CACHE,
    CHASSIS,
    COOLING_DEVICE,
    ELECTRICAL_CURRENT_PROBE,
    GROUP_ASSOCIATIONS,
    MANAGEMENT_DEVICE,
    MANAGEMENT_DEVICE_COMPONENT,
    MANAGEMENT_DEVICE_THRESHOLD_DATA,
    MEMORY_ARRAY_MAPPED_ADDRESS,
    MEMORY_CONTROLLER,
    MEMORY_DEVICE,
    MEMORY_DEVICE_MAPPED_ADDRESS,
    MEMORY_MODULE,
    ONBOARD_DEVICES,
    ONBOARD_ETHERNET,
    ONBOARD_OTHER,
    ONBOARD_SATA,
    ONBOARD_SOUND,
    ONBOARD_VIDEO,
    OTHER,
    PHYSICAL_MEMORY_ARRAY,
    PORT_AUDIO,
    PORT_CONNECTOR,
    PORT_FAN,
    PORT_NETWORK,
    PORT_OTHER,
    PORT_PS2,
    PORT_SATA,
    PORT_USB,
    PORT_VIDEO,
    PORTABLE_BATTERY,
    PROCESSOR,
    SYSTEM,
    SYSTEM_BOOT,
    SYSTEM_POWER_SUPPLY,
    SYSTEM_SLOT_PCI_EXPRESS,
    SYSTEM_SLOTS,
    TEMPERATURE_PROBE,
    VOLTAGE_PROBE,
    MAXIMUM
};



inline const char8* enumToString(DeviceManagerImage type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DeviceManagerImage::MAXIMUM: return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DeviceManagerImage type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERIMAGE_H
