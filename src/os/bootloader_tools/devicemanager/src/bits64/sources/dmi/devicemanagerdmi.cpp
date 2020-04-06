#include "devicemanagerdmi.h"

#include <common/src/bits64/dmi/dmi.h>
#include <common/src/bits64/string/utils.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



ArrayList<DeviceManagerEntryDMI *> DeviceManagerDMI::sEntries;



NgosStatus DeviceManagerDMI::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(DMI::iterateDmiEntries((u8 *)DMI::getStructureTableAddress(), decodeDmiEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

const ArrayList<DeviceManagerEntryDMI *>& DeviceManagerDMI::getEntries()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return sEntries;
}

NgosStatus DeviceManagerDMI::decodeDmiEntry(DmiEntryHeader *header)
{
    UEFI_LT((" | header = 0x%p", header));

    UEFI_ASSERT(header, "header is null", NgosStatus::ASSERTION);



    switch (header->type)
    {
        case DmiEntryType::BIOS:                             UEFI_ASSERT_EXECUTION(saveDmiBiosEntry((DmiBiosEntry *)header),                                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM:                           UEFI_ASSERT_EXECUTION(saveDmiSystemEntry((DmiSystemEntry *)header),                                               NgosStatus::ASSERTION); break;
        case DmiEntryType::BASEBOARD:                        UEFI_ASSERT_EXECUTION(saveDmiBaseboardEntry((DmiBaseboardEntry *)header),                                         NgosStatus::ASSERTION); break;
        case DmiEntryType::CHASSIS:                          UEFI_ASSERT_EXECUTION(saveDmiChassisEntry((DmiChassisEntry *)header),                                             NgosStatus::ASSERTION); break;
        case DmiEntryType::PROCESSOR:                        UEFI_ASSERT_EXECUTION(saveDmiProcessorEntry((DmiProcessorEntry *)header),                                         NgosStatus::ASSERTION); break;
        case DmiEntryType::CACHE:                            UEFI_ASSERT_EXECUTION(saveDmiCacheEntry((DmiCacheEntry *)header),                                                 NgosStatus::ASSERTION); break;
        case DmiEntryType::PORT_CONNECTOR:                   UEFI_ASSERT_EXECUTION(saveDmiPortConnectorEntry((DmiPortConnectorEntry *)header),                                 NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_SLOTS:                     UEFI_ASSERT_EXECUTION(saveDmiSystemSlotsEntry((DmiSystemSlotsEntry *)header),                                     NgosStatus::ASSERTION); break;
        case DmiEntryType::ONBOARD_DEVICES:                  UEFI_ASSERT_EXECUTION(saveDmiOnboardDevicesEntry((DmiOnboardDevicesEntry *)header),                               NgosStatus::ASSERTION); break;
        case DmiEntryType::OEM_STRINGS:                      UEFI_ASSERT_EXECUTION(saveDmiOemStringsEntry((DmiOemStringsEntry *)header),                                       NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_CONFIGURATION:             UEFI_ASSERT_EXECUTION(saveDmiSystemConfigurationEntry((DmiSystemConfigurationEntry *)header),                     NgosStatus::ASSERTION); break;
        case DmiEntryType::BIOS_LANGUAGE:                    UEFI_ASSERT_EXECUTION(saveDmiBiosLanguageEntry((DmiBiosLanguageEntry *)header),                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::GROUP_ASSOCIATIONS:               UEFI_ASSERT_EXECUTION(saveDmiGroupAssociationsEntry((DmiGroupAssociationsEntry *)header),                         NgosStatus::ASSERTION); break;
        case DmiEntryType::PHYSICAL_MEMORY_ARRAY:            UEFI_ASSERT_EXECUTION(saveDmiPhysicalMemoryArrayEntry((DmiPhysicalMemoryArrayEntry *)header),                     NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS:      UEFI_ASSERT_EXECUTION(saveDmiMemoryArrayMappedAddressEntry((DmiMemoryArrayMappedAddressEntry *)header),           NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_DEVICE_MAPPED_ADDRESS:     UEFI_ASSERT_EXECUTION(saveDmiMemoryDeviceMappedAddressEntry((DmiMemoryDeviceMappedAddressEntry *)header),         NgosStatus::ASSERTION); break;
        case DmiEntryType::PORTABLE_BATTERY:                 UEFI_ASSERT_EXECUTION(saveDmiPortableBatteryEntry((DmiPortableBatteryEntry *)header),                             NgosStatus::ASSERTION); break;
        case DmiEntryType::VOLTAGE_PROBE:                    UEFI_ASSERT_EXECUTION(saveDmiVoltageProbeEntry((DmiVoltageProbeEntry *)header),                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::COOLING_DEVICE:                   UEFI_ASSERT_EXECUTION(saveDmiCoolingDeviceEntry((DmiCoolingDeviceEntry *)header),                                 NgosStatus::ASSERTION); break;
        case DmiEntryType::TEMPERATURE_PROBE:                UEFI_ASSERT_EXECUTION(saveDmiTemperatureProbeEntry((DmiTemperatureProbeEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::ELECTRICAL_CURRENT_PROBE:         UEFI_ASSERT_EXECUTION(saveDmiElectricalCurrentProbeEntry((DmiElectricalCurrentProbeEntry *)header),               NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_BOOT:                      UEFI_ASSERT_EXECUTION(saveDmiSystemBootEntry((DmiSystemBootEntry *)header),                                       NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE:                UEFI_ASSERT_EXECUTION(saveDmiManagementDeviceEntry((DmiManagementDeviceEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE_COMPONENT:      UEFI_ASSERT_EXECUTION(saveDmiManagementDeviceComponentEntry((DmiManagementDeviceComponentEntry *)header),         NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE_THRESHOLD_DATA: UEFI_ASSERT_EXECUTION(saveDmiManagementDeviceThresholdDataEntry((DmiManagementDeviceThresholdDataEntry *)header), NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_POWER_SUPPLY:              UEFI_ASSERT_EXECUTION(saveDmiSystemPowerSupplyEntry((DmiSystemPowerSupplyEntry *)header),                         NgosStatus::ASSERTION); break;
        case DmiEntryType::ADDITIONAL:                       UEFI_ASSERT_EXECUTION(saveDmiAdditionalInformationEntry((DmiAdditionalInformationEntry *)header),                 NgosStatus::ASSERTION); break;
        case DmiEntryType::ONBOARD_DEVICES_EXTENDED:         UEFI_ASSERT_EXECUTION(saveDmiOnboardDevicesExtendedEntry((DmiOnboardDevicesExtendedEntry *)header),               NgosStatus::ASSERTION); break;

        default:
        {
            UEFI_LVV(("Ignoring DMI entry at address 0x%p with type %s", header, enumToFullString(header->type)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBiosEntry(DmiBiosEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->vendorStringId          = %u",     entry->vendorStringId));
        UEFI_LVVV(("entry->biosVersionStringId     = %u",     entry->biosVersionStringId));
        UEFI_LVVV(("entry->biosSegment             = 0x%04X", entry->biosSegment));
        UEFI_LVVV(("entry->biosReleaseDateStringId = %u",     entry->biosReleaseDateStringId));
        UEFI_LVVV(("entry->biosSize                = %u",     entry->biosSize));
        UEFI_LVVV(("entry->biosCharacteristics     = %s",     flagsToFullString(entry->biosCharacteristics)));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            UEFI_LVVV(("entry->biosCharacteristicsExtension.biosReserved = %s", flagsToFullString(entry->biosCharacteristicsExtension.biosReserved)));

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                UEFI_LVVV(("entry->biosCharacteristicsExtension.systemReserved = %s", flagsToFullString(entry->biosCharacteristicsExtension.systemReserved)));
                UEFI_LVVV(("entry->systemBiosMajorRelease                      = %u", entry->systemBiosMajorRelease));
                UEFI_LVVV(("entry->systemBiosMinorRelease                      = %u", entry->systemBiosMinorRelease));
                UEFI_LVVV(("entry->embeddedControllerFirmwareMajorRelease      = %u", entry->embeddedControllerFirmwareMajorRelease));
                UEFI_LVVV(("entry->embeddedControllerFirmwareMinorRelease      = %u", entry->embeddedControllerFirmwareMinorRelease));

                if (DMI::getVersion() >= DMI_VERSION(3, 1))
                {
                    UEFI_LVVV(("entry->extendedBiosSize.value   = %u",     entry->extendedBiosSize.value));
                    UEFI_LVVV(("entry->extendedBiosSize.unit    = %s",     enumToFullString((DmiBiosExtendedRomSizeUnit)entry->extendedBiosSize.unit)));
                    UEFI_LVVV(("entry->extendedBiosSize.value16 = 0x%04X", entry->extendedBiosSize.value16));
                    UEFI_LVVV(("entry->extendedBiosSize         = %s",     bytesToString(entry->extendedBiosSize.size())));
                }
            }
        }



        UEFI_TEST_ASSERT(entry->vendorStringId          == 1,                                                                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->biosVersionStringId     == 2,                                                                     NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->biosSegment          == 0xE800,                                                                NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->biosReleaseDateStringId == 3,                                                                     NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->biosSize             == 39,                                                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->biosCharacteristics  == FLAGS(DmiBiosCharacteristicsFlag::BIOS_CHARACTERISTICS_NOT_SUPPORTED), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // UEFI_TEST_ASSERT(entry->biosCharacteristicsExtension.biosReserved == FLAG(DmiBiosCharacteristicsBiosReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                // UEFI_TEST_ASSERT(entry->biosCharacteristicsExtension.systemReserved == FLAG(DmiBiosCharacteristicsSystemReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->systemBiosMajorRelease                      == 15,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->systemBiosMinorRelease                      == 103,                                                  NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->embeddedControllerFirmwareMajorRelease      == 151,                                                  NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->embeddedControllerFirmwareMinorRelease      == 78,                                                   NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(3, 1))
                {
                    // UEFI_TEST_ASSERT(entry->extendedBiosSize.value   == 0,                                     NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->extendedBiosSize.unit    == DmiBiosExtendedRomSizeUnit::MEGABYTES, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->extendedBiosSize.value16 == 0x0000,                                NgosStatus::ASSERTION); // Commented due to value variation

                    UEFI_TEST_ASSERT(entry->header.length >= 26,                   NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry), NgosStatus::ASSERTION);
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= 24,                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry) - 2, NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 19,                       NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry) - 7, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 18,                       NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry) - 8, NgosStatus::ASSERTION);
        }
    }



    const char8 *vendorString          = "N/A";
    const char8 *biosVersionString     = "N/A";
    const char8 *biosReleaseDateString = "N/A";



    if (
        entry->vendorStringId
        ||
        entry->biosVersionStringId
        ||
        entry->biosReleaseDateStringId
       )
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->vendorStringId)
                {
                    vendorString = begin;
                }
                else
                if (stringId == entry->biosVersionStringId)
                {
                    biosVersionString = begin;
                }
                else
                if (stringId == entry->biosReleaseDateStringId)
                {
                    biosReleaseDateString = begin;
                }



                if (!cur[1]) // cur[1] == 0
                {
                    break;
                }

                begin = cur + 1;
            }



            ++cur;
        } while(true);
    }
    else
    {
        UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
    }



    const char8 *biosCharacteristicsExtensionBiosReserved   = "N/A";
    const char8 *biosCharacteristicsExtensionSystemReserved = "N/A";
    const char8 *systemBiosMajorRelease                     = "N/A";
    const char8 *systemBiosMinorRelease                     = "N/A";
    const char8 *embeddedControllerFirmwareMajorRelease     = "N/A";
    const char8 *embeddedControllerFirmwareMinorRelease     = "N/A";
    const char8 *extendedBiosSize                           = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(2, 1))
    {
        biosCharacteristicsExtensionBiosReserved = strdup(flagsToFullString(entry->biosCharacteristicsExtension.biosReserved));

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            biosCharacteristicsExtensionSystemReserved = strdup(flagsToFullString(entry->biosCharacteristicsExtension.systemReserved));
            systemBiosMajorRelease                     = mprintf("%u", entry->systemBiosMajorRelease);
            systemBiosMinorRelease                     = mprintf("%u", entry->systemBiosMinorRelease);
            embeddedControllerFirmwareMajorRelease     = mprintf("%u", entry->embeddedControllerFirmwareMajorRelease);
            embeddedControllerFirmwareMinorRelease     = mprintf("%u", entry->embeddedControllerFirmwareMinorRelease);

            if (DMI::getVersion() >= DMI_VERSION(3, 1))
            {
                extendedBiosSize = strdup(bytesToString(entry->extendedBiosSize.size()));
            }
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::BIOS);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor",                                     vendorString),                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",                                    biosVersionString),                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment",                                    mprintf("0x%04X", entry->biosSegment)),                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Release date",                               biosReleaseDateString),                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Size",                                       strdup(bytesToString(entry->biosSize))),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics",                            strdup(flagsToFullString(entry->biosCharacteristics))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics (BIOS reserved)",            biosCharacteristicsExtensionBiosReserved),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics (System reserved)",          biosCharacteristicsExtensionSystemReserved),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System BIOS major release",                  systemBiosMajorRelease),                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System BIOS minor release",                  systemBiosMinorRelease),                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Embedded controller firmware major release", embeddedControllerFirmwareMajorRelease),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Embedded controller firmware minor release", embeddedControllerFirmwareMinorRelease),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended size",                              extendedBiosSize),                                      NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemEntry(DmiSystemEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBaseboardEntry(DmiBaseboardEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiChassisEntry(DmiChassisEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiProcessorEntry(DmiProcessorEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiCacheEntry(DmiCacheEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPortConnectorEntry(DmiPortConnectorEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemSlotsEntry(DmiSystemSlotsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiOnboardDevicesEntry(DmiOnboardDevicesEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiOemStringsEntry(DmiOemStringsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemConfigurationEntry(DmiSystemConfigurationEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBiosLanguageEntry(DmiBiosLanguageEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiGroupAssociationsEntry(DmiGroupAssociationsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPhysicalMemoryArrayEntry(DmiPhysicalMemoryArrayEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryArrayMappedAddressEntry(DmiMemoryArrayMappedAddressEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryDeviceMappedAddressEntry(DmiMemoryDeviceMappedAddressEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPortableBatteryEntry(DmiPortableBatteryEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiVoltageProbeEntry(DmiVoltageProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiCoolingDeviceEntry(DmiCoolingDeviceEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiTemperatureProbeEntry(DmiTemperatureProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiElectricalCurrentProbeEntry(DmiElectricalCurrentProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemBootEntry(DmiSystemBootEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiManagementDeviceEntry(DmiManagementDeviceEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiManagementDeviceComponentEntry(DmiManagementDeviceComponentEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiManagementDeviceThresholdDataEntry(DmiManagementDeviceThresholdDataEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemPowerSupplyEntry(DmiSystemPowerSupplyEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiAdditionalInformationEntry(DmiAdditionalInformationEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiOnboardDevicesExtendedEntry(DmiOnboardDevicesExtendedEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
