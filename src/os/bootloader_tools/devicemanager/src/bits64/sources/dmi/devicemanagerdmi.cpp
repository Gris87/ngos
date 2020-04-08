#include "devicemanagerdmi.h"

#include <common/src/bits64/dmi/dmi.h>
#include <common/src/bits64/string/utils.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uuid/utils.h>



#define DMI_CHASSIS_CONTAINED_ELEMENT(entry, i) (DmiChassisContainedElement *)((u64)(entry)->containedElements + (i) * (entry)->containedElementRecordLength)



ArrayList<DeviceManagerEntryDMI *> DeviceManagerDMI::sEntries;



NgosStatus DeviceManagerDMI::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(DMI::iterateDmiEntries((u8 *)DMI::getStructureTableAddress(), decodeDmiEntry), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.sort(), NgosStatus::ASSERTION);



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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::BIOS, DeviceManagerImage::BIOS);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                                     mprintf("0x%04X", entry->header.handle)),               NgosStatus::ASSERTION);
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



    // Validation
    {
        UEFI_LVVV(("entry->manufacturerStringId = %u", entry->manufacturerStringId));
        UEFI_LVVV(("entry->productNameStringId  = %u", entry->productNameStringId));
        UEFI_LVVV(("entry->versionStringId      = %u", entry->versionStringId));
        UEFI_LVVV(("entry->serialNumberStringId = %u", entry->serialNumberStringId));
        UEFI_LVVV(("entry->uuid                 = %s", uuidToString(entry->uuid)));
        UEFI_LVVV(("entry->wakeUpTime           = %s", enumToFullString(entry->wakeUpTime)));
        UEFI_LVVV(("entry->skuNumberStringId    = %u", entry->skuNumberStringId));
        UEFI_LVVV(("entry->familyStringId       = %u", entry->familyStringId));



        UEFI_TEST_ASSERT(entry->manufacturerStringId     == 1,                                 NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->productNameStringId      == 2,                                 NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->versionStringId          == 3,                                 NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->serialNumberStringId  == 4,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data1            == 0x9FAE0773,                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data2            == 0xF53F,                            NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data3            == 0x4A15,                            NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data4            == 0x8A,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data5            == 0x11,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data6[0]         == 0xED,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data6[1]         == 0x76,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data6[2]         == 0xA1,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data6[3]         == 0x0F,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data6[4]         == 0x4E,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->uuid.data6[5]         == 0x5B,                              NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->wakeUpTime               == DmiSystemWakeUpTime::POWER_SWITCH, NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->skuNumberStringId     == 5,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->familyStringId        == 6,                                 NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 27,                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry), NgosStatus::ASSERTION);
    }



    const char8 *manufacturerString = "N/A";
    const char8 *productNameString  = "N/A";
    const char8 *versionString      = "N/A";
    const char8 *serialNumberString = "N/A";
    const char8 *skuNumberString    = "N/A";
    const char8 *familyString       = "N/A";

    if (
        entry->manufacturerStringId
        ||
        entry->productNameStringId
        ||
        entry->versionStringId
        ||
        entry->serialNumberStringId
        ||
        entry->skuNumberStringId
        ||
        entry->familyStringId
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



                if (stringId == entry->manufacturerStringId)
                {
                    manufacturerString = begin;
                }
                else
                if (stringId == entry->productNameStringId)
                {
                    productNameString = begin;
                }
                else
                if (stringId == entry->versionStringId)
                {
                    versionString = begin;
                }
                else
                if (stringId == entry->serialNumberStringId)
                {
                    serialNumberString = begin;
                }
                else
                if (stringId == entry->skuNumberStringId)
                {
                    skuNumberString = begin;
                }
                else
                if (stringId == entry->familyStringId)
                {
                    familyString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::SYSTEM, DeviceManagerImage::SYSTEM);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",  manufacturerString),                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Product name",  productNameString),                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",       versionString),                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number", serialNumberString),                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("UUID",          strdup(uuidToString(entry->uuid))),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Wake-Up time",  strdup(enumToFullString(entry->wakeUpTime))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SKU number",    skuNumberString),                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",        familyString),                                NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBaseboardEntry(DmiBaseboardEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->manufacturerStringId           = %u",     entry->manufacturerStringId));
        UEFI_LVVV(("entry->productStringId                = %u",     entry->productStringId));
        UEFI_LVVV(("entry->versionStringId                = %u",     entry->versionStringId));
        UEFI_LVVV(("entry->serialNumberStringId           = %u",     entry->serialNumberStringId));
        UEFI_LVVV(("entry->assetTagStringId               = %u",     entry->assetTagStringId));
        UEFI_LVVV(("entry->featureFlags                   = %s",     flagsToFullString(entry->featureFlags)));
        UEFI_LVVV(("entry->locationInChassisStringId      = %u",     entry->locationInChassisStringId));
        UEFI_LVVV(("entry->chassisHandle                  = 0x%04X", entry->chassisHandle));
        UEFI_LVVV(("entry->boardType                      = %s",     enumToFullString(entry->boardType)));
        UEFI_LVVV(("entry->numberOfContainedObjectHandles = %u",     entry->numberOfContainedObjectHandles));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            UEFI_LVVV(("entry->containedObjectHandles:"));
            UEFI_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)
            {
                UEFI_LVVV(("#%-3d: 0x%04X", i, entry->containedObjectHandles[i]));
            }

            UEFI_LVVV(("-------------------------------------"));
        }
#endif



        UEFI_TEST_ASSERT(entry->manufacturerStringId           == 1,                                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->productStringId                == 2,                                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->versionStringId                == 3,                                           NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->serialNumberStringId        == 4,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->assetTagStringId            == 5,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->featureFlags                == FLAGS(DmiBaseboardFeatureFlag::MOTHERBOARD), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationInChassisStringId   == 6,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->chassisHandle               == 0x0300,                                      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->boardType                   == DmiBaseboardType::MOTHERBOARD,               NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->numberOfContainedObjectHandles == 0,                                           NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->containedObjectHandles[0]   == 0,                                           NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 15                        + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBaseboardEntry) + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);
    }



    const char8 *manufacturerString      = "N/A";
    const char8 *productString           = "N/A";
    const char8 *versionString           = "N/A";
    const char8 *serialNumberString      = "N/A";
    const char8 *assetTagString          = "N/A";
    const char8 *locationInChassisString = "N/A";

    if (
        entry->manufacturerStringId
        ||
        entry->productStringId
        ||
        entry->versionStringId
        ||
        entry->serialNumberStringId
        ||
        entry->assetTagStringId
        ||
        entry->locationInChassisStringId
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



                if (stringId == entry->manufacturerStringId)
                {
                    manufacturerString = begin;
                }
                else
                if (stringId == entry->productStringId)
                {
                    productString = begin;
                }
                else
                if (stringId == entry->versionStringId)
                {
                    versionString = begin;
                }
                else
                if (stringId == entry->serialNumberStringId)
                {
                    serialNumberString = begin;
                }
                else
                if (stringId == entry->assetTagStringId)
                {
                    assetTagString = begin;
                }
                else
                if (stringId == entry->locationInChassisStringId)
                {
                    locationInChassisString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::BASEBOARD, DeviceManagerImage::BASEBOARD);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                             mprintf("0x%04X", entry->header.handle)),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",                       manufacturerString),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Product",                            productString),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",                            versionString),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",                      serialNumberString),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",                          assetTagString),                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Features",                           strdup(flagsToFullString(entry->featureFlags))),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location in chassis",                locationInChassisString),                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Chassis handle",                     mprintf("0x%04X", entry->chassisHandle)),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Board type",                         strdup(enumToFullString(entry->boardType))),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of contained object handles", mprintf("%u", entry->numberOfContainedObjectHandles)), NgosStatus::ASSERTION);

    for (i64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained object handle #%d", i), mprintf("0x%04X", entry->containedObjectHandles[i])), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiChassisEntry(DmiChassisEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    u8 skuNumberStringId = 0;

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        skuNumberStringId = *(u8 *)DMI_CHASSIS_CONTAINED_ELEMENT(entry, entry->containedElementCount);
    }



    // Validation
    {
        UEFI_LVVV(("entry->manufacturerStringId = %u",     entry->manufacturerStringId));
        UEFI_LVVV(("entry->type                 = %s",     enumToFullString(entry->type)));
        UEFI_LVVV(("entry->versionStringId      = %u",     entry->versionStringId));
        UEFI_LVVV(("entry->serialNumberStringId = %u",     entry->serialNumberStringId));
        UEFI_LVVV(("entry->assetTagStringId     = %u",     entry->assetTagStringId));
        UEFI_LVVV(("entry->bootUpState          = %s",     enumToFullString(entry->bootUpState)));
        UEFI_LVVV(("entry->powerSupplyState     = %s",     enumToFullString(entry->powerSupplyState)));
        UEFI_LVVV(("entry->thermalState         = %s",     enumToFullString(entry->thermalState)));
        UEFI_LVVV(("entry->securityStatus       = %s",     enumToFullString(entry->securityStatus)));
        UEFI_LVVV(("entry->oemDefined[0]        = 0x%02X", entry->oemDefined[0]));
        UEFI_LVVV(("entry->oemDefined[1]        = 0x%02X", entry->oemDefined[1]));
        UEFI_LVVV(("entry->oemDefined[2]        = 0x%02X", entry->oemDefined[2]));
        UEFI_LVVV(("entry->oemDefined[3]        = 0x%02X", entry->oemDefined[3]));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->height                       = %u", entry->height));
            UEFI_LVVV(("entry->numberOfPowerCords           = %u", entry->numberOfPowerCords));
            UEFI_LVVV(("entry->containedElementCount        = %u", entry->containedElementCount));
            UEFI_LVVV(("entry->containedElementRecordLength = %u", entry->containedElementRecordLength));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            {
                UEFI_LVVV(("entry->containedElements:"));
                UEFI_LVVV(("-------------------------------------"));

                for (i64 i = 0; i < entry->containedElementCount; ++i)
                {
                    DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entry, i);

                    UEFI_LVVV(("containedElement[%-3d]->type    = %s",     i, enumToFullString(containedElement->type)));
                    UEFI_LVVV(("containedElement[%-3d]->minimum = 0x%02X", i, containedElement->minimum));
                    UEFI_LVVV(("containedElement[%-3d]->maximum = 0x%02X", i, containedElement->maximum));
                }

                UEFI_LVVV(("-------------------------------------"));
            }
#endif

            UEFI_LVVV(("skuNumberStringId = %u", skuNumberStringId));
        }



        UEFI_TEST_ASSERT(entry->manufacturerStringId    == 1,                                 NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->type                 == DmiChassisType::DESKTOP,           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->versionStringId      == 2,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->serialNumberStringId == 3,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->assetTagStringId     == 4,                                 NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->bootUpState             == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->powerSupplyState        == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->thermalState         == DmiChassisState::SAFE,             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->securityStatus       == DmiChassisSecurityStatus::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->oemDefined[0]           == 0,                                 NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->oemDefined[1]           == 0,                                 NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->oemDefined[2]           == 0,                                 NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->oemDefined[3]           == 0,                                 NgosStatus::ASSERTION);

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // UEFI_TEST_ASSERT(entry->height                                    == 0,                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->numberOfPowerCords                        == 1,                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->containedElementCount                     == 0,                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->containedElementRecordLength              == 3,                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->type    == DmiChassisType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->minimum == 0,                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->maximum == 0,                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(skuNumberStringId                                == 5,                     NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= 21                      + entry->containedElementCount * entry->containedElementRecordLength + 1, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) + entry->containedElementCount * entry->containedElementRecordLength + 1, NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 17,                          NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) - 4, NgosStatus::ASSERTION);
        }
    }



    const char8 *manufacturerString = "N/A";
    const char8 *versionString      = "N/A";
    const char8 *serialNumberString = "N/A";
    const char8 *assetTagString     = "N/A";
    const char8 *skuNumberString    = "N/A";

    if (
        entry->manufacturerStringId
        ||
        entry->versionStringId
        ||
        entry->serialNumberStringId
        ||
        entry->assetTagStringId
        ||
        skuNumberStringId
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



                if (stringId == entry->manufacturerStringId)
                {
                    manufacturerString = begin;
                }
                else
                if (stringId == entry->versionStringId)
                {
                    versionString = begin;
                }
                else
                if (stringId == entry->serialNumberStringId)
                {
                    serialNumberString = begin;
                }
                else
                if (stringId == entry->assetTagStringId)
                {
                    assetTagString = begin;
                }
                else
                if (stringId == skuNumberStringId)
                {
                    skuNumberString = begin;
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



    const char8 *height                       = "N/A";
    const char8 *numberOfPowerCords           = "N/A";
    const char8 *containedElementCount        = "N/A";
    const char8 *containedElementRecordLength = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        height                       = mprintf("%u", entry->height);
        numberOfPowerCords           = mprintf("%u", entry->numberOfPowerCords);
        containedElementCount        = mprintf("%u", entry->containedElementCount);
        containedElementRecordLength = mprintf("%u", entry->containedElementRecordLength);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::CHASSIS, DeviceManagerImage::CHASSIS);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle)),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",                    manufacturerString),                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                            strdup(enumToFullString(entry->type))),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",                         versionString),                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",                   serialNumberString),                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",                       assetTagString),                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Boot up state",                   strdup(enumToFullString(entry->bootUpState))),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Power supply state",              strdup(enumToFullString(entry->powerSupplyState))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thermal state",                   strdup(enumToFullString(entry->thermalState))),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Security status",                 strdup(enumToFullString(entry->securityStatus))),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined #0",                  mprintf("0x%02X", entry->oemDefined[0])),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined #1",                  mprintf("0x%02X", entry->oemDefined[1])),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined #2",                  mprintf("0x%02X", entry->oemDefined[2])),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined #3",                  mprintf("0x%02X", entry->oemDefined[3])),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Height",                          height),                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of power cords",           numberOfPowerCords),                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Contained element count",         containedElementCount),                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Contained element record length", containedElementRecordLength),                      NgosStatus::ASSERTION);

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        for (i64 i = 0; i < entry->containedElementCount; ++i)
        {
            DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entry, i);

            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d type"),    strdup(enumToFullString(containedElement->type))), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d minimum"), mprintf("0x%02X",  containedElement->minimum)),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d maximum"), mprintf("0x%02X",  containedElement->maximum)),    NgosStatus::ASSERTION);
        }
    }

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SKU number", skuNumberString), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiProcessorEntry(DmiProcessorEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->socketStringId                       = %u",     entry->socketStringId));
        UEFI_LVVV(("entry->processorType                        = %s",     enumToFullString(entry->processorType)));
        UEFI_LVVV(("entry->processorFamily                      = %s",     enumToFullString(entry->processorFamily)));
        UEFI_LVVV(("entry->processorManufactureStringId         = %u",     entry->processorManufactureStringId));
        UEFI_LVVV(("entry->processorId.signature.stepping       = %u",     entry->processorId.signature.stepping));
        UEFI_LVVV(("entry->processorId.signature.model          = %u",     entry->processorId.signature.model));
        UEFI_LVVV(("entry->processorId.signature.family         = %u",     entry->processorId.signature.family));
        UEFI_LVVV(("entry->processorId.signature.type           = %u",     entry->processorId.signature.type));
        UEFI_LVVV(("entry->processorId.signature.extendedModel  = %u",     entry->processorId.signature.extendedModel));
        UEFI_LVVV(("entry->processorId.signature.extendedFamily = %u",     entry->processorId.signature.extendedFamily));
        UEFI_LVVV(("entry->processorId.signature.value32        = 0x%08X", entry->processorId.signature.value32));
        UEFI_LVVV(("entry->processorId.featureFlags             = %s",     flagsToFullString(entry->processorId.featureFlags)));
        UEFI_LVVV(("entry->processorVersionStringId             = %u",     entry->processorVersionStringId));
        UEFI_LVVV(("entry->voltage                              = %s",     flagsToFullString(entry->voltage)));
        UEFI_LVVV(("entry->externalClock                        = %u",     entry->externalClock));
        UEFI_LVVV(("entry->maxSpeed                             = %u",     entry->maxSpeed));
        UEFI_LVVV(("entry->currentSpeed                         = %u",     entry->currentSpeed));
        UEFI_LVVV(("entry->status                               = %s",     enumToFullString((DmiProcessorStatus)entry->status)));
        UEFI_LVVV(("entry->socketPopulated                      = %u",     entry->socketPopulated));
        UEFI_LVVV(("entry->processorStatus                      = 0x%02X", entry->processorStatus));
        UEFI_LVVV(("entry->processorUpgrade                     = %s",     enumToFullString(entry->processorUpgrade)));
        UEFI_LVVV(("entry->l1CacheHandle                        = 0x%04X", entry->l1CacheHandle));
        UEFI_LVVV(("entry->l2CacheHandle                        = 0x%04X", entry->l2CacheHandle));
        UEFI_LVVV(("entry->l3CacheHandle                        = 0x%04X", entry->l3CacheHandle));
        UEFI_LVVV(("entry->serialNumberStringId                 = %u",     entry->serialNumberStringId));
        UEFI_LVVV(("entry->assetTagStringId                     = %u",     entry->assetTagStringId));
        UEFI_LVVV(("entry->partNumberStringId                   = %u",     entry->partNumberStringId));

        if (DMI::getVersion() >= DMI_VERSION(2, 5))
        {
            UEFI_LVVV(("entry->coreCount                = %u", entry->coreCount));
            UEFI_LVVV(("entry->enabledCoreCount         = %u", entry->enabledCoreCount));
            UEFI_LVVV(("entry->threadCount              = %u", entry->threadCount));
            UEFI_LVVV(("entry->processorCharacteristics = %s", flagsToFullString(entry->processorCharacteristics)));

            if (DMI::getVersion() >= DMI_VERSION(2, 6))
            {
                UEFI_LVVV(("entry->processorFamily2 = %s", enumToFullString(entry->processorFamily2)));

                if (DMI::getVersion() >= DMI_VERSION(3, 0))
                {
                    UEFI_LVVV(("entry->coreCount2        = %u", entry->coreCount2));
                    UEFI_LVVV(("entry->enabledCoreCount2 = %u", entry->enabledCoreCount2));
                    UEFI_LVVV(("entry->threadCount2      = %u", entry->threadCount2));
                }
            }
        }



        // Ignore CppAlignmentVerifier [BEGIN]
        // UEFI_TEST_ASSERT(entry->socketStringId                       == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->processorType                           == DmiProcessorType::CENTRAL_PROCESSOR,  NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->processorFamily                      == DmiProcessorFamily::OTHER,            NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->processorManufactureStringId            == 2,                                    NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->processorId.signature.stepping       == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.signature.model          == 12,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.signature.family         == 6,                                    NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->processorId.signature.type              == 0,                                    NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->processorId.signature.extendedModel  == 3,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.signature.extendedFamily == 0,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.signature.value32        == 0x00000000,                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.featureFlags             == FLAGS(DmiProcessorFeatureFlag::FPU                            // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::VME                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::DE                           // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PSE                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::TSC                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MSR                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PAE                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MCE                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::CX8                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::APIC                         // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::SEP                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MTRR                         // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PGE                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MCA                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::CMOV                         // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PAT                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PSE36                        // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::CLFSH                        // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MMX                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::FXSR                         // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::SSE                          // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::SSE2                         // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::SS), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorVersionStringId             == 3,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->voltage                              == FLAG(DmiProcessorVoltageFlag::NONE),  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->externalClock                        == 100,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maxSpeed                             == 2000,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->currentSpeed                         == 2000,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status                               == DmiProcessorStatus::ENABLED,          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->socketPopulated                      == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorStatus                      == 0x41,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorUpgrade                     == DmiProcessorUpgrade::OTHER,           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->l1CacheHandle                        == 0xFFFF,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->l2CacheHandle                        == 0xFFFF,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->l3CacheHandle                        == 0xFFFF,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->serialNumberStringId                 == 4,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->assetTagStringId                     == 5,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->partNumberStringId                   == 6,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // Ignore CppAlignmentVerifier [END]

        if (DMI::getVersion() >= DMI_VERSION(2, 5))
        {
            // UEFI_TEST_ASSERT(entry->coreCount                == 2,                                                      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->enabledCoreCount         == 2,                                                      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->threadCount              == 2,                                                      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorCharacteristics == FLAGS(DmiProcessorCharacteristicsFlag::SUPPORT_64_BIT), NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 6))
            {
                // UEFI_TEST_ASSERT(entry->processorFamily2 == DmiProcessorFamily2::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(3, 0))
                {
                    // UEFI_TEST_ASSERT(entry->coreCount2        == 2, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->enabledCoreCount2 == 2, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->threadCount2      == 2, NgosStatus::ASSERTION); // Commented due to value variation

                    UEFI_TEST_ASSERT(entry->header.length >= 48,                        NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry), NgosStatus::ASSERTION);
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= 42,                            NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 6, NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 40,                            NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 8, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 35,                             NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 13, NgosStatus::ASSERTION);
        }
    }



    const char8 *socketString               = "N/A";
    const char8 *processorManufactureString = "N/A";
    const char8 *processorVersionString     = "N/A";
    const char8 *serialNumberString         = "N/A";
    const char8 *assetTagString             = "N/A";
    const char8 *partNumberString           = "N/A";

    if (
        entry->socketStringId
        ||
        entry->processorManufactureStringId
        ||
        entry->processorVersionStringId
        ||
        entry->serialNumberStringId
        ||
        entry->assetTagStringId
        ||
        entry->partNumberStringId
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



                if (stringId == entry->socketStringId)
                {
                    socketString = begin;
                }
                else
                if (stringId == entry->processorManufactureStringId)
                {
                    processorManufactureString = begin;
                }
                else
                if (stringId == entry->processorVersionStringId)
                {
                    processorVersionString = begin;
                }
                else
                if (stringId == entry->serialNumberStringId)
                {
                    serialNumberString = begin;
                }
                else
                if (stringId == entry->assetTagStringId)
                {
                    assetTagString = begin;
                }
                else
                if (stringId == entry->partNumberStringId)
                {
                    partNumberString = begin;
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



    const char8 *coreCount                = "N/A";
    const char8 *enabledCoreCount         = "N/A";
    const char8 *threadCount              = "N/A";
    const char8 *processorCharacteristics = "N/A";
    const char8 *processorFamily2         = "N/A";
    const char8 *coreCount2               = "N/A";
    const char8 *enabledCoreCount2        = "N/A";
    const char8 *threadCount2             = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(2, 5))
    {
        coreCount                = mprintf("%u", entry->coreCount);
        enabledCoreCount         = mprintf("%u", entry->enabledCoreCount);
        threadCount              = mprintf("%u", entry->threadCount);
        processorCharacteristics = strdup(flagsToFullString(entry->processorCharacteristics));

        if (DMI::getVersion() >= DMI_VERSION(2, 6))
        {
            processorFamily2 = strdup(enumToFullString(entry->processorFamily2));

            if (DMI::getVersion() >= DMI_VERSION(3, 0))
            {
                coreCount2        = mprintf("%u", entry->coreCount2);
                enabledCoreCount2 = mprintf("%u", entry->enabledCoreCount2);
                threadCount2      = mprintf("%u", entry->threadCount2);
            }
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::PROCESSOR, DeviceManagerImage::PROCESSOR);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",               mprintf("0x%04X", entry->header.handle)),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket",               socketString),                                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                 strdup(enumToFullString(entry->processorType))),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",               strdup(enumToFullString(entry->processorFamily))),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",         processorManufactureString),                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Stepping",             mprintf("%u", entry->processorId.signature.stepping)),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Model",                mprintf("%u", entry->processorId.signature.model)),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",               mprintf("%u", entry->processorId.signature.family)),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                 mprintf("%u", entry->processorId.signature.type)),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended model",       mprintf("%u", entry->processorId.signature.extendedModel)),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended family",      mprintf("%u", entry->processorId.signature.extendedFamily)),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Features",             strdup(flagsToFullString(entry->processorId.featureFlags))),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",              processorVersionString),                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Voltage",              strdup(flagsToFullString(entry->voltage))),                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External clock",       mprintf("%u", entry->externalClock)),                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum speed",        mprintf("%u", entry->maxSpeed)),                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current speed",        mprintf("%u", entry->currentSpeed)),                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",               strdup(enumToFullString((DmiProcessorStatus)entry->status))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket populated",     entry->socketPopulated ? "Yes" : "No"),                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upgrade",              strdup(enumToFullString(entry->processorUpgrade))),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L1 cache handle",      mprintf("0x%04X", entry->l1CacheHandle)),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L2 cache handle",      mprintf("0x%04X", entry->l2CacheHandle)),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L3 cache handle",      mprintf("0x%04X", entry->l3CacheHandle)),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",        serialNumberString),                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",            assetTagString),                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Part number",          partNumberString),                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count",           coreCount),                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count",   enabledCoreCount),                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count",         threadCount),                                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics",      processorCharacteristics),                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family 2",             processorFamily2),                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count 2",         coreCount2),                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count 2", enabledCoreCount2),                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count 2",       threadCount2),                                                NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiCacheEntry(DmiCacheEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->socketDesignationStringId          = %u",     entry->socketDesignationStringId));
        UEFI_LVVV(("entry->cacheConfiguration.level           = %u",     entry->cacheConfiguration.level));
        UEFI_LVVV(("entry->cacheConfiguration.socketed        = %u",     entry->cacheConfiguration.socketed));
        UEFI_LVVV(("entry->cacheConfiguration.location        = %s",     enumToFullString((DmiCacheLocation)entry->cacheConfiguration.location)));
        UEFI_LVVV(("entry->cacheConfiguration.enabled         = %u",     entry->cacheConfiguration.enabled));
        UEFI_LVVV(("entry->cacheConfiguration.operationalMode = %s",     enumToFullString((DmiCacheOperationalMode)entry->cacheConfiguration.operationalMode)));
        UEFI_LVVV(("entry->cacheConfiguration.value16         = 0x%04X", entry->cacheConfiguration.value16));
        UEFI_LVVV(("entry->maximumCacheSize.value             = %u",     entry->maximumCacheSize.value));
        UEFI_LVVV(("entry->maximumCacheSize.granularity       = %u",     entry->maximumCacheSize.granularity));
        UEFI_LVVV(("entry->maximumCacheSize.value16           = 0x%04X", entry->maximumCacheSize.value16));
        UEFI_LVVV(("entry->maximumCacheSize                   = %s",     bytesToString(entry->maximumCacheSize.size())));
        UEFI_LVVV(("entry->installedSize.value                = %u",     entry->installedSize.value));
        UEFI_LVVV(("entry->installedSize.granularity          = %u",     entry->installedSize.granularity));
        UEFI_LVVV(("entry->installedSize.value16              = 0x%04X", entry->installedSize.value16));
        UEFI_LVVV(("entry->installedSize                      = %s",     bytesToString(entry->installedSize.size())));
        UEFI_LVVV(("entry->supportedSramType                  = %s",     flagsToFullString(entry->supportedSramType)));
        UEFI_LVVV(("entry->currentSramType                    = %s",     flagsToFullString(entry->currentSramType)));
        UEFI_LVVV(("entry->cacheSpeed                         = %u",     entry->cacheSpeed));
        UEFI_LVVV(("entry->errorCorrectionType                = %s",     enumToFullString(entry->errorCorrectionType)));
        UEFI_LVVV(("entry->systemCacheType                    = %s",     enumToFullString(entry->systemCacheType)));
        UEFI_LVVV(("entry->associativity                      = %s",     enumToFullString(entry->associativity)));

        if (DMI::getVersion() >= DMI_VERSION(3, 1))
        {
            UEFI_LVVV(("entry->maximumCacheSize2.value       = %u",     entry->maximumCacheSize2.value));
            UEFI_LVVV(("entry->maximumCacheSize2.granularity = %u",     entry->maximumCacheSize2.granularity));
            UEFI_LVVV(("entry->maximumCacheSize2.value32     = 0x%08X", entry->maximumCacheSize2.value32));
            UEFI_LVVV(("entry->maximumCacheSize2             = %s",     bytesToString(entry->maximumCacheSize2.size())));
            UEFI_LVVV(("entry->installedSize2.value          = %u",     entry->installedSize2.value));
            UEFI_LVVV(("entry->installedSize2.granularity    = %u",     entry->installedSize2.granularity));
            UEFI_LVVV(("entry->installedSize2.value32        = 0x%08X", entry->installedSize2.value32));
            UEFI_LVVV(("entry->installedSize2                = %s",     bytesToString(entry->installedSize2.size())));
        }



        // UEFI_TEST_ASSERT(entry->socketDesignationStringId          == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.level           == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.socketed        == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.location        == DmiCacheLocation::UNKNOWN,                      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.enabled         == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.operationalMode == DmiCacheOperationalMode::UNKNOWN,               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.value16         == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumCacheSize.value             == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumCacheSize.granularity       == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumCacheSize.value16           == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->installedSize.value                == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->installedSize.granularity          == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->installedSize.value16              == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->supportedSramType                  == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->currentSramType                    == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheSpeed                         == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->errorCorrectionType                == DmiCacheErrorCorrectionType::OTHER,             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->systemCacheType                    == DmiCacheType::OTHER,                            NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->associativity                      == DmiCacheAssociativity::OTHER,                   NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(3, 1))
        {
            // UEFI_TEST_ASSERT(entry->maximumCacheSize2.value       == 1,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->maximumCacheSize2.granularity == 1,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->maximumCacheSize2.value32     == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->installedSize2.value          == 1,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->installedSize2.granularity    == 1,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->installedSize2.value32        == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= 27,                    NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 19,                        NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry) - 8, NgosStatus::ASSERTION);
        }
    }



    const char8 *socketDesignationString = "N/A";

    if (entry->socketDesignationStringId)
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



                if (stringId == entry->socketDesignationStringId)
                {
                    socketDesignationString = begin;
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



    const char8 *maximumCacheSize2 = "N/A";
    const char8 *installedSize2    = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(3, 1))
    {
        maximumCacheSize2 = strdup(bytesToString(entry->maximumCacheSize2.size()));
        installedSize2    = strdup(bytesToString(entry->installedSize2.size()));
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::CACHE, DeviceManagerImage::CACHE);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                mprintf("0x%04X", entry->header.handle)),                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket designation",    socketDesignationString),                                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Level",                 mprintf("%u", entry->cacheConfiguration.level)),                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socketed",              entry->cacheConfiguration.socketed ? "Yes" : "No"),                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",              strdup(enumToFullString((DmiCacheLocation)entry->cacheConfiguration.location))),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",               entry->cacheConfiguration.enabled ? "Yes" : "No"),                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Operational mode",      strdup(enumToFullString((DmiCacheOperationalMode)entry->cacheConfiguration.operationalMode))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum cache size",    strdup(bytesToString(entry->maximumCacheSize.size()))),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installed size",        strdup(bytesToString(entry->installedSize.size()))),                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Supported SRAM type",   strdup(flagsToFullString(entry->supportedSramType))),                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current SRAM type",     strdup(flagsToFullString(entry->currentSramType))),                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Speed",                 mprintf("%u", entry->cacheSpeed)),                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error correction type", strdup(enumToFullString(entry->errorCorrectionType))),                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System cache type",     strdup(enumToFullString(entry->systemCacheType))),                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Associativity",         strdup(enumToFullString(entry->associativity))),                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum cache size 2",  maximumCacheSize2),                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installed size 2",      installedSize2),                                                                               NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPortConnectorEntry(DmiPortConnectorEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->internalReferenceDesignatorStringId = %u", entry->internalReferenceDesignatorStringId));
        UEFI_LVVV(("entry->internalConnectorType               = %s", enumToFullString(entry->internalConnectorType)));
        UEFI_LVVV(("entry->externalReferenceDesignatorStringId = %u", entry->externalReferenceDesignatorStringId));
        UEFI_LVVV(("entry->externalConnectorType               = %s", enumToFullString(entry->externalConnectorType)));
        UEFI_LVVV(("entry->portType                            = %s", enumToFullString(entry->portType)));



        // UEFI_TEST_ASSERT(entry->internalReferenceDesignatorStringId == 1,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->internalConnectorType               == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->externalReferenceDesignatorStringId == 2,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->externalConnectorType               == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->portType                            == DmiPortConnectorPortType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 9,                             NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPortConnectorEntry), NgosStatus::ASSERTION);
    }



    const char8 *internalReferenceDesignatorString = "N/A";
    const char8 *externalReferenceDesignatorString = "N/A";

    if (
        entry->internalReferenceDesignatorStringId
        ||
        entry->externalReferenceDesignatorStringId
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



                if (stringId == entry->internalReferenceDesignatorStringId)
                {
                    internalReferenceDesignatorString = begin;
                }
                else
                if (stringId == entry->externalReferenceDesignatorStringId)
                {
                    externalReferenceDesignatorString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::PORT_CONNECTOR, DeviceManagerImage::PORT_CONNECTOR);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                        mprintf("0x%04X", entry->header.handle)),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Internal reference designator", internalReferenceDesignatorString),                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Internal connector type",       strdup(enumToFullString(entry->internalConnectorType))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External reference designator", externalReferenceDesignatorString),                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External connector type",       strdup(enumToFullString(entry->externalConnectorType))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port type",                     strdup(enumToFullString(entry->portType))),              NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemSlotsEntry(DmiSystemSlotsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->slotDesignationStringId = %u", entry->slotDesignationStringId));
        UEFI_LVVV(("entry->slotType                = %s", enumToFullString(entry->slotType)));
        UEFI_LVVV(("entry->slotDataBusWidth        = %s", enumToFullString(entry->slotDataBusWidth)));
        UEFI_LVVV(("entry->currentUsage            = %s", enumToFullString(entry->currentUsage)));
        UEFI_LVVV(("entry->slotLength              = %s", enumToFullString(entry->slotLength)));
        UEFI_LVVV(("entry->slotID                  = %u", entry->slotID));
        UEFI_LVVV(("entry->slotCharacteristics     = %s", flagsToFullString(entry->slotCharacteristics)));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->segmentGroupNumber            = %u",     entry->segmentGroupNumber));
            UEFI_LVVV(("entry->busNumber                     = %u",     entry->busNumber));
            UEFI_LVVV(("entry->functionNumber                = %u",     entry->functionNumber));
            UEFI_LVVV(("entry->deviceNumber                  = %u",     entry->deviceNumber));
            UEFI_LVVV(("entry->functionNumberAndDeviceNumber = 0x%02X", entry->functionNumberAndDeviceNumber));

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                UEFI_LVVV(("entry->dataBusWidth      = %s", enumToFullString(entry->dataBusWidth)));
                UEFI_LVVV(("entry->peerGroupingCount = %u", entry->peerGroupingCount));

                for (i64 i = 0; i < entry->peerGroupingCount; ++i)
                {
                    UEFI_LVVV(("entry->peerGroups[%d].segmentGroupNumber            = %u",     i, entry->peerGroups[i].segmentGroupNumber));
                    UEFI_LVVV(("entry->peerGroups[%d].busNumber                     = %u",     i, entry->peerGroups[i].busNumber));
                    UEFI_LVVV(("entry->peerGroups[%d].functionNumber                = %u",     i, entry->peerGroups[i].functionNumber));
                    UEFI_LVVV(("entry->peerGroups[%d].deviceNumber                  = %u",     i, entry->peerGroups[i].deviceNumber));
                    UEFI_LVVV(("entry->peerGroups[%d].functionNumberAndDeviceNumber = 0x%02X", i, entry->peerGroups[i].functionNumberAndDeviceNumber));
                    UEFI_LVVV(("entry->peerGroups[%d].dataBusWidth                  = %s",     i, enumToFullString(entry->peerGroups[i].dataBusWidth)));
                }
            }
        }



        // UEFI_TEST_ASSERT(entry->slotDesignationStringId == 1,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotType                == DmiSystemSlotsType::UNKNOWN,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotDataBusWidth        == DmiSystemSlotsDataBusWidth::UNKNOWN,            NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->currentUsage            == DmiSystemSlotsUsage::AVAILABLE,                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotLength              == DmiSystemSlotsLength::UNKNOWN,                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotID                  == 1,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotCharacteristics     == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // UEFI_TEST_ASSERT(entry->segmentGroupNumber            == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->busNumber                     == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->functionNumber                == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceNumber                  == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->functionNumberAndDeviceNumber == 0x00, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                // UEFI_TEST_ASSERT(entry->dataBusWidth                                == DmiSystemSlotsDataBusWidth::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroupingCount                           == 1,                                   NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].segmentGroupNumber            == 1,                                   NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].busNumber                     == 1,                                   NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].functionNumber                == 1,                                   NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].deviceNumber                  == 1,                                   NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].functionNumberAndDeviceNumber == 0x00,                                NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].dataBusWidth                  == DmiSystemSlotsDataBusWidth::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation

                UEFI_TEST_ASSERT(entry->header.length >= 19 + entry->peerGroupingCount * 5,                          NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry) + entry->peerGroupingCount * 5, NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 17,                              NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry) - 2, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 13,                              NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry) - 6, NgosStatus::ASSERTION);
        }
    }



    const char8 *slotDesignationString = "N/A";

    if (entry->slotDesignationStringId)
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



                if (stringId == entry->slotDesignationStringId)
                {
                    slotDesignationString = begin;
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



    const char8 *segmentGroupNumber = "N/A";
    const char8 *busNumber          = "N/A";
    const char8 *functionNumber     = "N/A";
    const char8 *deviceNumber       = "N/A";
    const char8 *dataBusWidth       = "N/A";
    const char8 *peerGroupingCount  = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        segmentGroupNumber = mprintf("%u", entry->segmentGroupNumber);
        busNumber          = mprintf("%u", entry->busNumber);
        functionNumber     = mprintf("%u", entry->functionNumber);
        deviceNumber       = mprintf("%u", entry->deviceNumber);

        if (DMI::getVersion() >= DMI_VERSION(3, 2))
        {
            dataBusWidth      = strdup(enumToFullString(entry->dataBusWidth));
            peerGroupingCount = mprintf("%u", entry->peerGroupingCount);
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::SYSTEM_SLOTS, DeviceManagerImage::SYSTEM_SLOTS);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",               mprintf("0x%04X", entry->header.handle)),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Designation",          slotDesignationString),                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                 strdup(enumToFullString(entry->slotType))),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data bus width",       strdup(enumToFullString(entry->slotDataBusWidth))),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current usage",        strdup(enumToFullString(entry->currentUsage))),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Length",               strdup(enumToFullString(entry->slotLength))),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("ID",                   mprintf("%u", entry->slotID)),                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics",      strdup(flagsToFullString(entry->slotCharacteristics))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment group number", segmentGroupNumber),                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus number",           busNumber),                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Function number",      functionNumber),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device number",        deviceNumber),                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data bus width",       dataBusWidth),                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Peer grouping count",  peerGroupingCount),                                     NgosStatus::ASSERTION);

    if (DMI::getVersion() >= DMI_VERSION(3, 2))
    {
        for (i64 i = 0; i < entry->peerGroupingCount; ++i)
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d segment group number", i), mprintf("%u", entry->peerGroups[i].segmentGroupNumber)),      NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d bus number",           i), mprintf("%u", entry->peerGroups[i].busNumber)),               NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d function number",      i), mprintf("%u", entry->peerGroups[i].functionNumber)),          NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d device number",        i), mprintf("%u", entry->peerGroups[i].deviceNumber)),            NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d data bus width",       i), strdup(enumToFullString(entry->peerGroups[i].dataBusWidth))), NgosStatus::ASSERTION);
        }
    }

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



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
