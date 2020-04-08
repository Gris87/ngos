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
    OEM_STRINGS,
    ONBOARD_DEVICES,
    ONBOARD_ETHERNET,
    ONBOARD_OTHER,
    ONBOARD_SATA,
    ONBOARD_SOUND,
    ONBOARD_VIDEO,
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
    SYSTEM_CONFIGURATION,
    SYSTEM_POWER_SUPPLY,
    SYSTEM_SLOT_OTHER,
    SYSTEM_SLOT_PCI_EXPRESS,
    SYSTEM_SLOTS,
    TEMPERATURE_PROBE,
    VOLTAGE_PROBE,
    MAXIMUM
};



inline const char8* enumToString(DeviceManagerImage image) // TEST: NO
{
    // UEFI_LT((" | image = %u", image)); // Commented to avoid bad looking logs



    switch (image)
    {
        case DeviceManagerImage::ADDITIONAL:                       return "ADDITIONAL";
        case DeviceManagerImage::BASEBOARD:                        return "BASEBOARD";
        case DeviceManagerImage::BIOS:                             return "BIOS";
        case DeviceManagerImage::BIOS_LANGUAGE:                    return "BIOS_LANGUAGE";
        case DeviceManagerImage::CACHE:                            return "CACHE";
        case DeviceManagerImage::CHASSIS:                          return "CHASSIS";
        case DeviceManagerImage::COOLING_DEVICE:                   return "COOLING_DEVICE";
        case DeviceManagerImage::ELECTRICAL_CURRENT_PROBE:         return "ELECTRICAL_CURRENT_PROBE";
        case DeviceManagerImage::GROUP_ASSOCIATIONS:               return "GROUP_ASSOCIATIONS";
        case DeviceManagerImage::MANAGEMENT_DEVICE:                return "MANAGEMENT_DEVICE";
        case DeviceManagerImage::MANAGEMENT_DEVICE_COMPONENT:      return "MANAGEMENT_DEVICE_COMPONENT";
        case DeviceManagerImage::MANAGEMENT_DEVICE_THRESHOLD_DATA: return "MANAGEMENT_DEVICE_THRESHOLD_DATA";
        case DeviceManagerImage::MEMORY_ARRAY_MAPPED_ADDRESS:      return "MEMORY_ARRAY_MAPPED_ADDRESS";
        case DeviceManagerImage::MEMORY_CONTROLLER:                return "MEMORY_CONTROLLER";
        case DeviceManagerImage::MEMORY_DEVICE:                    return "MEMORY_DEVICE";
        case DeviceManagerImage::MEMORY_DEVICE_MAPPED_ADDRESS:     return "MEMORY_DEVICE_MAPPED_ADDRESS";
        case DeviceManagerImage::MEMORY_MODULE:                    return "MEMORY_MODULE";
        case DeviceManagerImage::OEM_STRINGS:                      return "OEM_STRINGS";
        case DeviceManagerImage::ONBOARD_DEVICES:                  return "ONBOARD_DEVICES";
        case DeviceManagerImage::ONBOARD_ETHERNET:                 return "ONBOARD_ETHERNET";
        case DeviceManagerImage::ONBOARD_OTHER:                    return "ONBOARD_OTHER";
        case DeviceManagerImage::ONBOARD_SATA:                     return "ONBOARD_SATA";
        case DeviceManagerImage::ONBOARD_SOUND:                    return "ONBOARD_SOUND";
        case DeviceManagerImage::ONBOARD_VIDEO:                    return "ONBOARD_VIDEO";
        case DeviceManagerImage::PHYSICAL_MEMORY_ARRAY:            return "PHYSICAL_MEMORY_ARRAY";
        case DeviceManagerImage::PORT_AUDIO:                       return "PORT_AUDIO";
        case DeviceManagerImage::PORT_CONNECTOR:                   return "PORT_CONNECTOR";
        case DeviceManagerImage::PORT_FAN:                         return "PORT_FAN";
        case DeviceManagerImage::PORT_NETWORK:                     return "PORT_NETWORK";
        case DeviceManagerImage::PORT_OTHER:                       return "PORT_OTHER";
        case DeviceManagerImage::PORT_PS2:                         return "PORT_PS2";
        case DeviceManagerImage::PORT_SATA:                        return "PORT_SATA";
        case DeviceManagerImage::PORT_USB:                         return "PORT_USB";
        case DeviceManagerImage::PORT_VIDEO:                       return "PORT_VIDEO";
        case DeviceManagerImage::PORTABLE_BATTERY:                 return "PORTABLE_BATTERY";
        case DeviceManagerImage::PROCESSOR:                        return "PROCESSOR";
        case DeviceManagerImage::SYSTEM:                           return "SYSTEM";
        case DeviceManagerImage::SYSTEM_BOOT:                      return "SYSTEM_BOOT";
        case DeviceManagerImage::SYSTEM_CONFIGURATION:             return "SYSTEM_CONFIGURATION";
        case DeviceManagerImage::SYSTEM_POWER_SUPPLY:              return "SYSTEM_POWER_SUPPLY";
        case DeviceManagerImage::SYSTEM_SLOT_OTHER:                return "SYSTEM_SLOT_OTHER";
        case DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS:          return "SYSTEM_SLOT_PCI_EXPRESS";
        case DeviceManagerImage::SYSTEM_SLOTS:                     return "SYSTEM_SLOTS";
        case DeviceManagerImage::TEMPERATURE_PROBE:                return "TEMPERATURE_PROBE";
        case DeviceManagerImage::VOLTAGE_PROBE:                    return "VOLTAGE_PROBE";
        case DeviceManagerImage::MAXIMUM:                          return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DeviceManagerImage image) // TEST: NO
{
    // UEFI_LT((" | image = %u", image)); // Commented to avoid bad looking logs



    static char8 res[40];

    sprintf(res, "0x%02X (%s)", image, enumToString(image));

    return res;
}



#endif // DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERIMAGE_H
