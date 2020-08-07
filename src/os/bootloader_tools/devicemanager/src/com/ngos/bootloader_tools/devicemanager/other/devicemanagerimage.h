#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERIMAGE_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERIMAGE_H



#include <com/ngos/shared/common/dmi/dmientrytype.h>
#include <com/ngos/shared/common/dmi/entry/dmionboarddevicesextendedentry.h>
#include <com/ngos/shared/common/dmi/entry/dmiportconnectorentry.h>
#include <com/ngos/shared/common/dmi/entry/dmisystemslotsentry.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevice.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



enum class DeviceManagerImage: u8
{
    ADDITIONAL,
    BASEBOARD,
    BIOS,
    BIOS_LANGUAGE,
    BITS32_MEMORY_ERROR,
    BITS64_MEMORY_ERROR,
    CACHE,
    CHASSIS,
    COOLING_DEVICE,
    ELECTRICAL_CURRENT_PROBE,
    GROUP_ASSOCIATIONS,
    HARDWARE_SECURITY,
    INACTIVE,
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
    OUT_OF_BAND_REMOTE_ACCESS,
    PCI,
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
    SYSTEM_RESET,
    SYSTEM_SLOT_OTHER,
    SYSTEM_SLOT_PCI,
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
        case DeviceManagerImage::BITS32_MEMORY_ERROR:              return "BITS32_MEMORY_ERROR";
        case DeviceManagerImage::BITS64_MEMORY_ERROR:              return "BITS64_MEMORY_ERROR";
        case DeviceManagerImage::CACHE:                            return "CACHE";
        case DeviceManagerImage::CHASSIS:                          return "CHASSIS";
        case DeviceManagerImage::COOLING_DEVICE:                   return "COOLING_DEVICE";
        case DeviceManagerImage::ELECTRICAL_CURRENT_PROBE:         return "ELECTRICAL_CURRENT_PROBE";
        case DeviceManagerImage::GROUP_ASSOCIATIONS:               return "GROUP_ASSOCIATIONS";
        case DeviceManagerImage::HARDWARE_SECURITY:                return "HARDWARE_SECURITY";
        case DeviceManagerImage::INACTIVE:                         return "INACTIVE";
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
        case DeviceManagerImage::OUT_OF_BAND_REMOTE_ACCESS:        return "OUT_OF_BAND_REMOTE_ACCESS";
        case DeviceManagerImage::PCI:                              return "PCI";
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
        case DeviceManagerImage::SYSTEM_RESET:                     return "SYSTEM_RESET";
        case DeviceManagerImage::SYSTEM_SLOT_OTHER:                return "SYSTEM_SLOT_OTHER";
        case DeviceManagerImage::SYSTEM_SLOT_PCI:                  return "SYSTEM_SLOT_PCI";
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

    sprintf(res, "0x%02X (%s)", (u8)image, enumToString(image));

    return res;
}



inline DeviceManagerImage deviceManagerImageFromDmiEntryType(DmiEntryType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid too frequent logs



    switch (type)
    {
        case DmiEntryType::BIOS:                             return DeviceManagerImage::BIOS;
        case DmiEntryType::SYSTEM:                           return DeviceManagerImage::SYSTEM;
        case DmiEntryType::BASEBOARD:                        return DeviceManagerImage::BASEBOARD;
        case DmiEntryType::CHASSIS:                          return DeviceManagerImage::CHASSIS;
        case DmiEntryType::PROCESSOR:                        return DeviceManagerImage::PROCESSOR;
        case DmiEntryType::MEMORY_CONTROLLER:                return DeviceManagerImage::MEMORY_CONTROLLER;
        case DmiEntryType::MEMORY_MODULE:                    return DeviceManagerImage::MEMORY_MODULE;
        case DmiEntryType::CACHE:                            return DeviceManagerImage::CACHE;
        case DmiEntryType::PORT_CONNECTOR:                   return DeviceManagerImage::PORT_CONNECTOR;
        case DmiEntryType::SYSTEM_SLOTS:                     return DeviceManagerImage::SYSTEM_SLOTS;
        case DmiEntryType::ONBOARD_DEVICES:                  return DeviceManagerImage::ONBOARD_DEVICES;
        case DmiEntryType::OEM_STRINGS:                      return DeviceManagerImage::OEM_STRINGS;
        case DmiEntryType::SYSTEM_CONFIGURATION:             return DeviceManagerImage::SYSTEM_CONFIGURATION;
        case DmiEntryType::BIOS_LANGUAGE:                    return DeviceManagerImage::BIOS_LANGUAGE;
        case DmiEntryType::GROUP_ASSOCIATIONS:               return DeviceManagerImage::GROUP_ASSOCIATIONS;
        case DmiEntryType::PHYSICAL_MEMORY_ARRAY:            return DeviceManagerImage::PHYSICAL_MEMORY_ARRAY;
        case DmiEntryType::MEMORY_DEVICE:                    return DeviceManagerImage::MEMORY_DEVICE;
        case DmiEntryType::BITS32_MEMORY_ERROR:              return DeviceManagerImage::BITS32_MEMORY_ERROR;
        case DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS:      return DeviceManagerImage::MEMORY_ARRAY_MAPPED_ADDRESS;
        case DmiEntryType::MEMORY_DEVICE_MAPPED_ADDRESS:     return DeviceManagerImage::MEMORY_DEVICE_MAPPED_ADDRESS;
        case DmiEntryType::PORTABLE_BATTERY:                 return DeviceManagerImage::PORTABLE_BATTERY;
        case DmiEntryType::SYSTEM_RESET:                     return DeviceManagerImage::SYSTEM_RESET;
        case DmiEntryType::HARDWARE_SECURITY:                return DeviceManagerImage::HARDWARE_SECURITY;
        case DmiEntryType::VOLTAGE_PROBE:                    return DeviceManagerImage::VOLTAGE_PROBE;
        case DmiEntryType::COOLING_DEVICE:                   return DeviceManagerImage::COOLING_DEVICE;
        case DmiEntryType::TEMPERATURE_PROBE:                return DeviceManagerImage::TEMPERATURE_PROBE;
        case DmiEntryType::ELECTRICAL_CURRENT_PROBE:         return DeviceManagerImage::ELECTRICAL_CURRENT_PROBE;
        case DmiEntryType::OUT_OF_BAND_REMOTE_ACCESS:        return DeviceManagerImage::OUT_OF_BAND_REMOTE_ACCESS;
        case DmiEntryType::SYSTEM_BOOT:                      return DeviceManagerImage::SYSTEM_BOOT;
        case DmiEntryType::BITS64_MEMORY_ERROR:              return DeviceManagerImage::BITS64_MEMORY_ERROR;
        case DmiEntryType::MANAGEMENT_DEVICE:                return DeviceManagerImage::MANAGEMENT_DEVICE;
        case DmiEntryType::MANAGEMENT_DEVICE_COMPONENT:      return DeviceManagerImage::MANAGEMENT_DEVICE_COMPONENT;
        case DmiEntryType::MANAGEMENT_DEVICE_THRESHOLD_DATA: return DeviceManagerImage::MANAGEMENT_DEVICE_THRESHOLD_DATA;
        case DmiEntryType::SYSTEM_POWER_SUPPLY:              return DeviceManagerImage::SYSTEM_POWER_SUPPLY;
        case DmiEntryType::ADDITIONAL:                       return DeviceManagerImage::ADDITIONAL;
        case DmiEntryType::ONBOARD_DEVICES_EXTENDED:         return DeviceManagerImage::ONBOARD_DEVICES;
        case DmiEntryType::INACTIVE:                         return DeviceManagerImage::INACTIVE;

        case DmiEntryType::SYSTEM_EVENT_LOG:
        case DmiEntryType::BUILTIN_POINTING_DEVICE:
        case DmiEntryType::SYSTEM_POWER_CONTROLS:
        case DmiEntryType::BOOT_INTEGRITY_SERVICES_ENTRY_POINT:
        case DmiEntryType::MEMORY_CHANNEL:
        case DmiEntryType::IPMI_DEVICE:
        case DmiEntryType::MANAGEMENT_CONTROLLER_HOST_INTERFACE:
        case DmiEntryType::TPM_DEVICE:
        case DmiEntryType::END_OF_TABLE:
        {
            UEFI_LF(("Unexpected DMI entry type %s, %s:%u", enumToFullString(type), __FILE__, __LINE__));
        }
        break;

        default:
        {
            UEFI_LF(("Unknown DMI entry type %s, %s:%u", enumToFullString(type), __FILE__, __LINE__));
        }
        break;
    }



    return DeviceManagerImage::ADDITIONAL;
}



inline DeviceManagerImage deviceManagerImageFromDmiEntry(DmiPortConnectorEntry *entry, const char8 *name) // TEST: NO
{
    // UEFI_LT((" | entry = 0x%p, name = 0x%p", entry, name)); // Commented to avoid too frequent logs

    UEFI_ASSERT(entry, "entry is null", DeviceManagerImage::ADDITIONAL);
    UEFI_ASSERT(name,  "name is null",  DeviceManagerImage::ADDITIONAL);



    switch (entry->portType)
    {
        case DmiPortConnectorPortType::PARALLEL_PS2:                return DeviceManagerImage::PORT_PS2;
        case DmiPortConnectorPortType::KEYBOARD:                    return DeviceManagerImage::PORT_PS2;
        case DmiPortConnectorPortType::MOUSE:                       return DeviceManagerImage::PORT_PS2;
        case DmiPortConnectorPortType::USB:                         return DeviceManagerImage::PORT_USB;
        case DmiPortConnectorPortType::VIDEO_PORT:                  return DeviceManagerImage::PORT_VIDEO;
        case DmiPortConnectorPortType::AUDIO_PORT:                  return DeviceManagerImage::PORT_AUDIO;
        case DmiPortConnectorPortType::MODEM_PORT:                  return DeviceManagerImage::PORT_NETWORK;
        case DmiPortConnectorPortType::NETWORK_PORT:                return DeviceManagerImage::PORT_NETWORK;
        case DmiPortConnectorPortType::SATA:                        return DeviceManagerImage::PORT_SATA;
        case DmiPortConnectorPortType::MULTI_FUNCTION_DISPLAY_PORT: return DeviceManagerImage::PORT_VIDEO;

        case DmiPortConnectorPortType::NONE:
        case DmiPortConnectorPortType::PARALLEL_XT_AT_COMPATIBLE:
        case DmiPortConnectorPortType::PARALLEL_ECP:
        case DmiPortConnectorPortType::PARALLEL_EPP:
        case DmiPortConnectorPortType::PARALLEL_ECP_EPP:
        case DmiPortConnectorPortType::SERIAL_XT_AT_COMPATIBLE:
        case DmiPortConnectorPortType::SERIAL_16450_COMPATIBLE:
        case DmiPortConnectorPortType::SERIAL_16550_COMPATIBLE:
        case DmiPortConnectorPortType::SERIAL_16550A_COMPATIBLE:
        case DmiPortConnectorPortType::SCSI:
        case DmiPortConnectorPortType::MIDI:
        case DmiPortConnectorPortType::JOYSTICK:
        case DmiPortConnectorPortType::SSA_SCSI:
        case DmiPortConnectorPortType::FIREWIRE:
        case DmiPortConnectorPortType::PCMCIA_TYPE_I:
        case DmiPortConnectorPortType::PCMCIA_TYPE_II:
        case DmiPortConnectorPortType::PCMCIA_TYPE_III:
        case DmiPortConnectorPortType::CARD_BUS:
        case DmiPortConnectorPortType::ACCESS_BUS_PORT:
        case DmiPortConnectorPortType::SCSI_II:
        case DmiPortConnectorPortType::SCSI_WIDE:
        case DmiPortConnectorPortType::PC98:
        case DmiPortConnectorPortType::PC98_HIRESO:
        case DmiPortConnectorPortType::PCH98:
        case DmiPortConnectorPortType::SAS:
        case DmiPortConnectorPortType::THUNDERBOLT:
        case DmiPortConnectorPortType::_8251_COMPATIBLE:
        case DmiPortConnectorPortType::_8251_FIFO_COMPATIBLE:
        case DmiPortConnectorPortType::OTHER:
        {
            // Nothing
        }
        break;

        default:
        {
            UEFI_LF(("Unknown DMI port connector port type %s, %s:%u", enumToFullString(entry->portType), __FILE__, __LINE__));
        }
        break;
    }



    if (strstr(name, "FAN") != nullptr)
    {
        return DeviceManagerImage::PORT_FAN;
    }



    return DeviceManagerImage::PORT_OTHER;
}



inline DeviceManagerImage deviceManagerImageFromDmiEntry(DmiSystemSlotsEntry *entry, const char8 *name) // TEST: NO
{
    // UEFI_LT((" | entry = 0x%p, name = 0x%p", entry, name)); // Commented to avoid too frequent logs

    UEFI_ASSERT(entry, "entry is null", DeviceManagerImage::ADDITIONAL);
    UEFI_ASSERT(name,  "name is null",  DeviceManagerImage::ADDITIONAL);



    AVOID_UNUSED(name);



    switch (entry->slotType)
    {
        case DmiSystemSlotsType::PCI:                                  return DeviceManagerImage::SYSTEM_SLOT_PCI;
        case DmiSystemSlotsType::PCI_66_MHZ_CAPABLE:                   return DeviceManagerImage::SYSTEM_SLOT_PCI;
        case DmiSystemSlotsType::PCI_X:                                return DeviceManagerImage::SYSTEM_SLOT_PCI;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_SFF_8639:           return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_SFF_8639:           return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_MINI_52_PIN_WITH_BSKO:    return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_MINI_52_PIN_WITHOUT_BSKO: return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_MINI_76_PIN:              return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS:                          return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_X1:                       return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_X2:                       return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_X4:                       return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_X8:                       return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_X16:                      return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2:                    return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X1:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X2:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X4:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X8:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X16:                return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3:                    return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X1:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X2:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X4:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X8:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X16:                return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4:                    return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X1:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X2:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X4:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X8:                 return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X16:                return DeviceManagerImage::SYSTEM_SLOT_PCI_EXPRESS;

        case DmiSystemSlotsType::NONE:
        case DmiSystemSlotsType::OTHER:
        case DmiSystemSlotsType::UNKNOWN:
        case DmiSystemSlotsType::ISA:
        case DmiSystemSlotsType::MCA:
        case DmiSystemSlotsType::EISA:
        case DmiSystemSlotsType::PCMCIA:
        case DmiSystemSlotsType::VL_VESA:
        case DmiSystemSlotsType::PROPRIETARY:
        case DmiSystemSlotsType::PROCESSOR_CARD_SLOT:
        case DmiSystemSlotsType::PROPRIETARY_MEMORY_CARD_SLOT:
        case DmiSystemSlotsType::IO_RISER_CARD_SLOT:
        case DmiSystemSlotsType::NU_BUS:
        case DmiSystemSlotsType::AGP:
        case DmiSystemSlotsType::APG_2X:
        case DmiSystemSlotsType::AGP_4X:
        case DmiSystemSlotsType::AGP_8X:
        case DmiSystemSlotsType::M2_SOCKET_1_DP:
        case DmiSystemSlotsType::M2_SOCKET_1_SD:
        case DmiSystemSlotsType::M2_SOCKET_2:
        case DmiSystemSlotsType::M2_SOCKET_3:
        case DmiSystemSlotsType::MXM_TYPE_I:
        case DmiSystemSlotsType::MXM_TYPE_II:
        case DmiSystemSlotsType::MXM_TYPE_III_STANDARD:
        case DmiSystemSlotsType::MXM_TYPE_III_HE:
        case DmiSystemSlotsType::MXM_TYPE_IV:
        case DmiSystemSlotsType::MXM_3_0_TYPE_A:
        case DmiSystemSlotsType::MXM_3_0_TYPE_B:
        case DmiSystemSlotsType::CXL_FLEXBUS_1_0:
        case DmiSystemSlotsType::PC_98_C20:
        case DmiSystemSlotsType::PC_98_C24:
        case DmiSystemSlotsType::PC_98_E:
        case DmiSystemSlotsType::PC_98_LOCAL_BUS:
        case DmiSystemSlotsType::PC_98_CARD:
        {
            // Nothing
        }
        break;

        default:
        {
            UEFI_LF(("Unknown DMI system slot type %s, %s:%u", enumToFullString(entry->slotType), __FILE__, __LINE__));
        }
        break;
    }



    return DeviceManagerImage::SYSTEM_SLOT_OTHER;
}



inline DeviceManagerImage deviceManagerImageFromDmiOnboardDevice(DmiOnboardDevicesDevice *device) // TEST: NO
{
    // UEFI_LT((" | device = 0x%p", device)); // Commented to avoid too frequent logs

    UEFI_ASSERT(device, "device is null", DeviceManagerImage::ADDITIONAL);



    switch ((DmiOnboardDevicesDeviceType)device->deviceType)
    {
        case DmiOnboardDevicesDeviceType::VIDEO:           return DeviceManagerImage::ONBOARD_VIDEO;
        case DmiOnboardDevicesDeviceType::ETHERNET:        return DeviceManagerImage::ONBOARD_ETHERNET;
        case DmiOnboardDevicesDeviceType::SOUND:           return DeviceManagerImage::ONBOARD_SOUND;
        case DmiOnboardDevicesDeviceType::SATA_CONTROLLER: return DeviceManagerImage::ONBOARD_SATA;

        case DmiOnboardDevicesDeviceType::NONE:
        case DmiOnboardDevicesDeviceType::OTHER:
        case DmiOnboardDevicesDeviceType::UNKNOWN:
        case DmiOnboardDevicesDeviceType::SCSI_CONTROLLER:
        case DmiOnboardDevicesDeviceType::TOKEN_RING:
        case DmiOnboardDevicesDeviceType::PATA_CONTROLLER:
        case DmiOnboardDevicesDeviceType::SAS_CONTROLLER:
        {
            // Nothing
        }
        break;

        default:
        {
            UEFI_LF(("Unknown DMI onboard device type %s, %s:%u", enumToFullString((DmiOnboardDevicesDeviceType)device->deviceType), __FILE__, __LINE__));
        }
        break;
    }



    return DeviceManagerImage::ONBOARD_OTHER;
}



inline DeviceManagerImage deviceManagerImageFromDmiEntry(DmiOnboardDevicesExtendedEntry *entry, const char8 *name) // TEST: NO
{
    // UEFI_LT((" | entry = 0x%p, name = 0x%p", entry, name)); // Commented to avoid too frequent logs

    UEFI_ASSERT(entry, "entry is null", DeviceManagerImage::ADDITIONAL);
    UEFI_ASSERT(name,  "name is null",  DeviceManagerImage::ADDITIONAL);



    AVOID_UNUSED(name);



    switch ((DmiOnboardDevicesExtendedDeviceType)entry->deviceType)
    {
        case DmiOnboardDevicesExtendedDeviceType::VIDEO:           return DeviceManagerImage::ONBOARD_VIDEO;
        case DmiOnboardDevicesExtendedDeviceType::ETHERNET:        return DeviceManagerImage::ONBOARD_ETHERNET;
        case DmiOnboardDevicesExtendedDeviceType::SOUND:           return DeviceManagerImage::ONBOARD_SOUND;
        case DmiOnboardDevicesExtendedDeviceType::SATA_CONTROLLER: return DeviceManagerImage::ONBOARD_SATA;

        case DmiOnboardDevicesExtendedDeviceType::NONE:
        case DmiOnboardDevicesExtendedDeviceType::OTHER:
        case DmiOnboardDevicesExtendedDeviceType::UNKNOWN:
        case DmiOnboardDevicesExtendedDeviceType::SCSI_CONTROLLER:
        case DmiOnboardDevicesExtendedDeviceType::TOKEN_RING:
        case DmiOnboardDevicesExtendedDeviceType::PATA_CONTROLLER:
        case DmiOnboardDevicesExtendedDeviceType::SAS_CONTROLLER:
        {
            // Nothing
        }
        break;

        default:
        {
            UEFI_LF(("Unknown DMI onboard device type %s, %s:%u", enumToFullString((DmiOnboardDevicesExtendedDeviceType)entry->deviceType), __FILE__, __LINE__));
        }
        break;
    }



    return DeviceManagerImage::ONBOARD_OTHER;
}



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERIMAGE_H
