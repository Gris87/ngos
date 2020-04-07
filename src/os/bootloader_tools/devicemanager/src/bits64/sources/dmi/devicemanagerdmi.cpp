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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::BASEBOARD, DeviceManagerImage::BASEBOARD);

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
