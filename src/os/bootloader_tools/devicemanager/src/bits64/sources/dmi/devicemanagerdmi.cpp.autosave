#include "devicemanagerdmi.h"

#include <common/src/bits64/dmi/dmi.h>
#include <common/src/bits64/string/utils.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uuid/utils.h>



#define DMI_CHASSIS_CONTAINED_ELEMENT(entry, i) (DmiChassisContainedElement *)((u64)(entry)->containedElements + (i) * (entry)->containedElementRecordLength)

#define VALUE_MAXIMUM_LENGTH 20



ArrayList<DeviceManagerEntryDMI *> DeviceManagerDMI::sEntries;



NgosStatus DeviceManagerDMI::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(DMI::iterateDmiEntries((u8 *)DMI::getStructureTableAddress(), decodeDmiEntry), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.sort([](DeviceManagerEntryDMI* const &first, DeviceManagerEntryDMI* const &second)
    {
        UEFI_LT((" | first = 0x%p, second = 0x%p"));

        UEFI_ASSERT(first,  "first is null",  false);
        UEFI_ASSERT(second, "second is null", false);



        return (*first) < (*second);
    }), NgosStatus::ASSERTION);



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
        case DmiEntryType::MEMORY_DEVICE:                    UEFI_ASSERT_EXECUTION(saveDmiMemoryDeviceEntry((DmiMemoryDeviceEntry *)header),                                   NgosStatus::ASSERTION); break;
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
        biosCharacteristicsExtensionBiosReserved = mprintf("0x%02X", entry->biosCharacteristicsExtension.biosReserved.flags);

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            biosCharacteristicsExtensionSystemReserved = mprintf("0x%02X", entry->biosCharacteristicsExtension.systemReserved.flags);
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

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",       mprintf("0x%04X", entry->header.handle)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor",       vendorString),                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",      biosVersionString),                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment",      mprintf("0x%04X", entry->biosSegment)),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Release date", biosReleaseDateString),                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Size",         strdup(bytesToString(entry->biosSize))),  NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics", mprintf("0x%016lX", entry->biosCharacteristics.flags)), NgosStatus::ASSERTION);

    for (i64 i = 0; i < (i64)(sizeof(entry->biosCharacteristics) * 8); ++i)
    {
        u64 flag = 1ULL << i;

        if (entry->biosCharacteristics & flag)
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Characteristics: %s", flagToString((DmiBiosCharacteristicsFlag)flag)), "Yes"), NgosStatus::ASSERTION);
        }
    }



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics (BIOS reserved)", biosCharacteristicsExtensionBiosReserved), NgosStatus::ASSERTION);

    if (DMI::getVersion() >= DMI_VERSION(2, 1))
    {
        for (i64 i = 0; i < (i64)(sizeof(entry->biosCharacteristicsExtension.biosReserved) * 8); ++i)
        {
            u64 flag = 1ULL << i;

            if (entry->biosCharacteristicsExtension.biosReserved & flag)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Characteristics (BIOS reserved): %s", flagToString((DmiBiosCharacteristicsBiosReservedFlag)flag)), "Yes"), NgosStatus::ASSERTION);
            }
        }
    }



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics (System reserved)", biosCharacteristicsExtensionSystemReserved), NgosStatus::ASSERTION);

    if (DMI::getVersion() >= DMI_VERSION(2, 3))
    {
        for (i64 i = 0; i < (i64)(sizeof(entry->biosCharacteristicsExtension.systemReserved) * 8); ++i)
        {
            u64 flag = 1ULL << i;

            if (entry->biosCharacteristicsExtension.systemReserved & flag)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Characteristics (System reserved): %s", flagToString((DmiBiosCharacteristicsSystemReservedFlag)flag)), "Yes"), NgosStatus::ASSERTION);
            }
        }
    }



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

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",  manufacturerString),                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Product",       productString),                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",       versionString),                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number", serialNumberString),                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",     assetTagString),                          NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Features", mprintf("0x%04X", entry->featureFlags.flags)), NgosStatus::ASSERTION);

    for (i64 i = 0; i < (i64)(sizeof(entry->featureFlags) * 8); ++i)
    {
        u64 flag = 1ULL << i;

        if (entry->featureFlags & flag)
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Features: %s", flagToString((DmiBaseboardFeatureFlag)flag)), "Yes"), NgosStatus::ASSERTION);
        }
    }



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
        coreCount                = mprintf("%u",     entry->coreCount);
        enabledCoreCount         = mprintf("%u",     entry->enabledCoreCount);
        threadCount              = mprintf("%u",     entry->threadCount);
        processorCharacteristics = mprintf("0x%04X", entry->processorCharacteristics.flags);

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

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",          mprintf("0x%04X", entry->header.handle)),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket",          socketString),                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",            strdup(enumToFullString(entry->processorType))),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",          strdup(enumToFullString(entry->processorFamily))),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",    processorManufactureString),                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Stepping",        mprintf("%u", entry->processorId.signature.stepping)),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Model",           mprintf("%u", entry->processorId.signature.model)),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",          mprintf("%u", entry->processorId.signature.family)),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",            mprintf("%u", entry->processorId.signature.type)),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended model",  mprintf("%u", entry->processorId.signature.extendedModel)),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended family", mprintf("%u", entry->processorId.signature.extendedFamily)), NgosStatus::ASSERTION);



    // Commented to avoid too many records
    // UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Features", mprintf("0x%08X", entry->processorId.featureFlags.flags)), NgosStatus::ASSERTION);
    //
    // for (i64 i = 0; i < (i64)(sizeof(entry->processorId.featureFlags) * 8); ++i)
    // {
    //     u64 flag = 1ULL << i;
    //
    //     if (entry->processorId.featureFlags & flag)
    //     {
    //         UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Features: %s", flagToString((DmiProcessorFeatureFlag)flag)), "Yes"), NgosStatus::ASSERTION);
    //     }
    // }



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version", processorVersionString), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Voltage", mprintf("0x%02X", entry->voltage.flags)), NgosStatus::ASSERTION);

    for (i64 i = 0; i < (i64)(sizeof(entry->voltage) * 8); ++i)
    {
        u64 flag = 1ULL << i;

        if (entry->voltage & flag)
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Voltage: %s", flagToString((DmiProcessorVoltageFlag)flag)), "Yes"), NgosStatus::ASSERTION);
        }
    }



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External clock",     mprintf("%u", entry->externalClock)),                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum speed",      mprintf("%u", entry->maxSpeed)),                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current speed",      mprintf("%u", entry->currentSpeed)),                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",             strdup(enumToFullString((DmiProcessorStatus)entry->status))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket populated",   entry->socketPopulated ? "Yes" : "No"),                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upgrade",            strdup(enumToFullString(entry->processorUpgrade))),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L1 cache handle",    mprintf("0x%04X", entry->l1CacheHandle)),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L2 cache handle",    mprintf("0x%04X", entry->l2CacheHandle)),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L3 cache handle",    mprintf("0x%04X", entry->l3CacheHandle)),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",      serialNumberString),                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",          assetTagString),                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Part number",        partNumberString),                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count",         coreCount),                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count", enabledCoreCount),                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count",       threadCount),                                                 NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics", processorCharacteristics), NgosStatus::ASSERTION);

    if (DMI::getVersion() >= DMI_VERSION(2, 5))
    {
        for (i64 i = 0; i < (i64)(sizeof(entry->processorCharacteristics) * 8); ++i)
        {
            u64 flag = 1ULL << i;

            if (entry->processorCharacteristics & flag)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Characteristics: %s", flagToString((DmiProcessorCharacteristicsFlag)flag)), "Yes"), NgosStatus::ASSERTION);
            }
        }
    }



    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family 2",             processorFamily2),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count 2",         coreCount2),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count 2", enabledCoreCount2), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count 2",       threadCount2),      NgosStatus::ASSERTION);

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



    u8 count = (entry->header.length - sizeof(entry->header)) / sizeof(entry->device[0]);

    // Validation
    {
        for (i64 i = 0; i < count; ++i)
        {
            UEFI_LVVV(("entry->device[%d].deviceType           = %s",     i, enumToFullString((DmiOnboardDevicesDeviceType)entry->device[i].deviceType)));
            UEFI_LVVV(("entry->device[%d].enabled              = %u",     i, entry->device[i].enabled));
            UEFI_LVVV(("entry->device[%d].deviceTypeAndEnabled = 0x%02X", i, entry->device[i].deviceTypeAndEnabled));
            UEFI_LVVV(("entry->device[%d].descriptionStringId  = %u",     i, entry->device[i].descriptionStringId));
        }



        UEFI_TEST_ASSERT(count                                                       >  0,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT((DmiOnboardDevicesDeviceType)entry->device[0].deviceType == DmiOnboardDevicesDeviceType::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->device[0].enabled                                 == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->device[0].deviceTypeAndEnabled                    == 0x00,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->device[0].descriptionStringId                     == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 6,                                                                NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesEntry) + sizeof(DmiOnboardDevicesDevice), NgosStatus::ASSERTION);
    }



    ArrayList<DeviceManagerEntryDMI *> onboardDevices;

    for (i64 i = 0; i < count; ++i)
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::ONBOARD_DEVICES, DeviceManagerImage::ONBOARD_DEVICES);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",      mprintf("0x%04X", entry->header.handle)),                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type", strdup(enumToFullString((DmiOnboardDevicesDeviceType)entry->device[i].deviceType))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",     entry->device[i].enabled ? "Yes" : "No"),                                            NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(onboardDevices.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    if (
        count > 0
        &&
        entry->device[0].descriptionStringId
       )
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                for (i64 i = 0; i < count; ++i)
                {
                    if (stringId == entry->device[i].descriptionStringId)
                    {
                        UEFI_ASSERT_EXECUTION(onboardDevices.at(i)->addRecord("Description", begin), NgosStatus::ASSERTION);

                        break;
                    }
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



    for (i64 i = 0; i < count; ++i)
    {
        DeviceManagerEntryDMI *deviceManagerEntry = onboardDevices.at(i);

        if (deviceManagerEntry->getRecords().getSize() < 4)
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description", "N/A"), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiOemStringsEntry(DmiOemStringsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->stringCount = %u", entry->stringCount));



        // UEFI_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 5,                          NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiOemStringsEntry), NgosStatus::ASSERTION);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::OEM_STRINGS, DeviceManagerImage::OEM_STRINGS);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle", mprintf("0x%04X", entry->header.handle)), NgosStatus::ASSERTION);



    if (entry->stringCount > 0)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM string", begin), NgosStatus::ASSERTION);



                if (!cur[1]) // cur[1] == 0
                {
                    break;
                }

                begin = cur + 1;
            }



            ++cur;
        } while(true);



        UEFI_TEST_ASSERT(stringId == entry->stringCount, NgosStatus::ASSERTION);
    }
    else
    {
        UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemConfigurationEntry(DmiSystemConfigurationEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->stringCount = %u", entry->stringCount));



        // UEFI_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 5,                                   NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemConfigurationEntry), NgosStatus::ASSERTION);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::SYSTEM_CONFIGURATION, DeviceManagerImage::SYSTEM_CONFIGURATION);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle", mprintf("0x%04X", entry->header.handle)), NgosStatus::ASSERTION);



    if (entry->stringCount > 0)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System configuration option", begin), NgosStatus::ASSERTION);



                if (!cur[1]) // cur[1] == 0
                {
                    break;
                }

                begin = cur + 1;
            }



            ++cur;
        } while(true);



        UEFI_TEST_ASSERT(stringId == entry->stringCount, NgosStatus::ASSERTION);
    }
    else
    {
        UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBiosLanguageEntry(DmiBiosLanguageEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->installableLanguages    = %u", entry->installableLanguages));
        UEFI_LVVV(("entry->flags                   = %s", flagsToFullString(entry->flags)));
        UEFI_LVVV(("entry->currentLanguageStringId = %u", entry->currentLanguageStringId));



        // UEFI_TEST_ASSERT(entry->installableLanguages    == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->flags                   == FLAGS(DmiBiosLanguageFlags::NONE), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->currentLanguageStringId == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosLanguageEntry), NgosStatus::ASSERTION);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::BIOS_LANGUAGE, DeviceManagerImage::BIOS_LANGUAGE);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                mprintf("0x%04X", entry->header.handle)),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installable languages", mprintf("%u", entry->installableLanguages)),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Flags",                 strdup(flagsToFullString(entry->flags))),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current language",      mprintf("%u", entry->currentLanguageStringId)), NgosStatus::ASSERTION);



    if (
        entry->installableLanguages
        ||
        entry->currentLanguageStringId
       )
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Language #%u", stringId), begin),NgosStatus::ASSERTION);



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



    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiGroupAssociationsEntry(DmiGroupAssociationsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    u8 count = (entry->header.length - sizeof(entry->header) - sizeof(entry->groupNameStringId)) / sizeof(entry->group[0]);

    // Validation
    {
        UEFI_LVVV(("entry->groupNameStringId = %u", entry->groupNameStringId));

        for (i64 i = 0; i < count; ++i)
        {
            UEFI_LVVV(("entry->group[%d].type   = %s",     i, enumToFullString(entry->group[i].type)));
            UEFI_LVVV(("entry->group[%d].handle = 0x%04X", i, entry->group[i].handle));
        }



        // UEFI_TEST_ASSERT(entry->groupNameStringId == 1,                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->group[0].type     == DmiEntryType::BIOS, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->group[0].handle   == 0x0000,             NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 8,                                                                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiGroupAssociationsEntry) + sizeof(DmiGroupAssociationsGroup), NgosStatus::ASSERTION);
    }



    const char8 *groupNameString = "N/A";

    if (entry->groupNameStringId)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->groupNameStringId)
                {
                    groupNameString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::GROUP_ASSOCIATIONS, DeviceManagerImage::GROUP_ASSOCIATIONS);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle", mprintf("0x%04X", entry->header.handle)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Name",   groupNameString),                         NgosStatus::ASSERTION);

    for (i64 i = 0; i < count; ++i)
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Member #%d type", i),   strdup(enumToFullString(entry->group[i].type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Member #%d handle", i), mprintf("0x%04X", entry->group[i].handle)),      NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPhysicalMemoryArrayEntry(DmiPhysicalMemoryArrayEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->location                     = %s",     enumToFullString(entry->location)));
        UEFI_LVVV(("entry->use                          = %s",     enumToFullString(entry->use)));
        UEFI_LVVV(("entry->memoryErrorCorrection        = %s",     enumToFullString(entry->memoryErrorCorrection)));
        UEFI_LVVV(("entry->maximumCapacity              = 0x%08X", entry->maximumCapacity));
        UEFI_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
        UEFI_LVVV(("entry->numberOfMemoryDevices        = %u",     entry->numberOfMemoryDevices));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->extendedMaximumCapacity = 0x%016lX", entry->extendedMaximumCapacity));
        }



        // UEFI_TEST_ASSERT(entry->location                     == DmiPhysicalMemoryArrayLocation::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->use                          == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY,             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryErrorCorrection        == DmiPhysicalMemoryArrayErrorCorrection::MULTI_BIT_ECC, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumCapacity              == 0x00100000,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->numberOfMemoryDevices        == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // UEFI_TEST_ASSERT(entry->extendedMaximumCapacity == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= 23,                                  NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 15,                                      NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntry) - 8, NgosStatus::ASSERTION);
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *extendedMaximumCapacity = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        extendedMaximumCapacity = mprintf("0x%016lX", entry->extendedMaximumCapacity);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::PHYSICAL_MEMORY_ARRAY, DeviceManagerImage::PHYSICAL_MEMORY_ARRAY);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle)),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                        strdup(enumToFullString(entry->location))),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Use",                             strdup(enumToFullString(entry->use))),                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error correction",         strdup(enumToFullString(entry->memoryErrorCorrection))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum capacity",                mprintf("0x%04X", entry->maximumCapacity)),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error information handle", mprintf("0x%04X", entry->memoryErrorInformationHandle)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of memory devices",        mprintf("%u", entry->numberOfMemoryDevices)),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended maximum capacity",       extendedMaximumCapacity),                                NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryDeviceEntry(DmiMemoryDeviceEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->memoryArrayHandle            = 0x%04X", entry->memoryArrayHandle));
        UEFI_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
        UEFI_LVVV(("entry->totalWidth                   = %u",     entry->totalWidth));
        UEFI_LVVV(("entry->dataWidth                    = %u",     entry->dataWidth));
        UEFI_LVVV(("entry->size                         = %u",     entry->size));
        UEFI_LVVV(("entry->formFactor                   = %s",     enumToFullString(entry->formFactor)));
        UEFI_LVVV(("entry->deviceSet                    = %u",     entry->deviceSet));
        UEFI_LVVV(("entry->deviceLocatorStringId        = %u",     entry->deviceLocatorStringId));
        UEFI_LVVV(("entry->bankLocatorStringId          = %u",     entry->bankLocatorStringId));
        UEFI_LVVV(("entry->memoryType                   = %s",     enumToFullString(entry->memoryType)));
        UEFI_LVVV(("entry->typeDetail                   = %s",     flagsToFullString(entry->typeDetail)));
        UEFI_LVVV(("entry->speed                        = %u",     entry->speed));
        UEFI_LVVV(("entry->manufacturerStringId         = %u",     entry->manufacturerStringId));
        UEFI_LVVV(("entry->serialNumberStringId         = %u",     entry->serialNumberStringId));
        UEFI_LVVV(("entry->assetTagStringId             = %u",     entry->assetTagStringId));
        UEFI_LVVV(("entry->partNumberStringId           = %u",     entry->partNumberStringId));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->attributes            = 0x%02X", entry->attributes));
            UEFI_LVVV(("entry->extendedSize          = %u",     entry->extendedSize));
            UEFI_LVVV(("entry->configuredMemorySpeed = %u",     entry->configuredMemorySpeed));

            if (DMI::getVersion() >= DMI_VERSION(2, 8))
            {
                UEFI_LVVV(("entry->minimumVoltage    = %u", entry->minimumVoltage));
                UEFI_LVVV(("entry->maximumVoltage    = %u", entry->maximumVoltage));
                UEFI_LVVV(("entry->configuredVoltage = %u", entry->configuredVoltage));

                if (DMI::getVersion() >= DMI_VERSION(3, 2))
                {
                    UEFI_LVVV(("entry->memoryTechnology                        = %s", enumToFullString(entry->memoryTechnology)));
                    UEFI_LVVV(("entry->memoryOperatingModeCapability           = %s", flagsToFullString(entry->memoryOperatingModeCapability)));
                    UEFI_LVVV(("entry->firmwareVersionStringId                 = %u", entry->firmwareVersionStringId));
                    UEFI_LVVV(("entry->moduleManufacturerID                    = %u", entry->moduleManufacturerID));
                    UEFI_LVVV(("entry->moduleProductID                         = %u", entry->moduleProductID));
                    UEFI_LVVV(("entry->memorySubsystemControllerManufacturerID = %u", entry->memorySubsystemControllerManufacturerID));
                    UEFI_LVVV(("entry->memorySubsystemControllerProductID      = %u", entry->memorySubsystemControllerProductID));
                    UEFI_LVVV(("entry->nonVolatileSize                         = %u", entry->nonVolatileSize));
                    UEFI_LVVV(("entry->volatileSize                            = %u", entry->volatileSize));
                    UEFI_LVVV(("entry->cacheSize                               = %u", entry->cacheSize));
                    UEFI_LVVV(("entry->logicalSize                             = %u", entry->logicalSize));
                }
            }
        }



        // UEFI_TEST_ASSERT(entry->memoryArrayHandle         == 0x1000,                                      NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                      NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->totalWidth                == 65535,                                       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->dataWidth                 == 65535,                                       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->size                      == 1024,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->formFactor                == DmiMemoryDeviceFormFactor::DIMM,             NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->deviceSet                    == 0,                                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->deviceLocatorStringId        == 1,                                           NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->bankLocatorStringId       == 2,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryType                == DmiMemoryDeviceType::RAM,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->typeDetail                == FLAGS(DmiMemoryDeviceTypeDetailFlag::OTHER), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->speed                     == 0,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->manufacturerStringId      == 3,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->serialNumberStringId      == 4,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->assetTagStringId          == 5,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->partNumberStringId        == 6,                                           NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // UEFI_TEST_ASSERT(entry->attributes            == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->extendedSize          == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->configuredMemorySpeed == 0, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 8))
            {
                // UEFI_TEST_ASSERT(entry->minimumVoltage    == 0, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->maximumVoltage    == 0, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->configuredVoltage == 0, NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(3, 2))
                {
                    UEFI_TEST_ASSERT(entry->memoryTechnology                        == DmiMemoryDeviceTechnology::NONE,                         NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->memoryOperatingModeCapability           == FLAGS(DmiMemoryDeviceOperatingModeCapabilityFlag::NONE), NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->firmwareVersionStringId                 == 7,                                                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->moduleManufacturerID                    == 0,                                                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->moduleProductID                         == 0,                                                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->memorySubsystemControllerManufacturerID == 0,                                                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->memorySubsystemControllerProductID      == 0,                                                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->nonVolatileSize                         == 0,                                                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->volatileSize                            == 0,                                                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->cacheSize                               == 0,                                                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->logicalSize                             == 0,                                                       NgosStatus::ASSERTION);

                    UEFI_TEST_ASSERT(entry->header.length >= 84,                           NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry), NgosStatus::ASSERTION);
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= 40,                                NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 44, NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 34,                                NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 50, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 27,                                NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 57, NgosStatus::ASSERTION);
        }
    }



    const char8 *deviceLocatorString   = "N/A";
    const char8 *bankLocatorString     = "N/A";
    const char8 *manufacturerString    = "N/A";
    const char8 *serialNumberString    = "N/A";
    const char8 *assetTagString        = "N/A";
    const char8 *partNumberString      = "N/A";
    const char8 *firmwareVersionString = "N/A";

    if (
        entry->deviceLocatorStringId
        ||
        entry->bankLocatorStringId
        ||
        entry->manufacturerStringId
        ||
        entry->serialNumberStringId
        ||
        entry->assetTagStringId
        ||
        entry->partNumberStringId
        ||
        (
         DMI::getVersion() >= DMI_VERSION(3, 2)
         &&
         entry->firmwareVersionStringId
        )
       )
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->deviceLocatorStringId)
                {
                    deviceLocatorString = begin;
                }
                else
                if (stringId == entry->bankLocatorStringId)
                {
                    bankLocatorString = begin;
                }
                else
                if (stringId == entry->manufacturerStringId)
                {
                    manufacturerString = begin;
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
                else
                {
                    if (DMI::getVersion() >= DMI_VERSION(3, 2))
                    {
                        if (stringId == entry->firmwareVersionStringId)
                        {
                            firmwareVersionString = begin;
                        }
                    }
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



    const char8 *attributes                              = "N/A";
    const char8 *extendedSize                            = "N/A";
    const char8 *configuredMemorySpeed                   = "N/A";
    const char8 *minimumVoltage                          = "N/A";
    const char8 *maximumVoltage                          = "N/A";
    const char8 *configuredVoltage                       = "N/A";
    const char8 *memoryTechnology                        = "N/A";
    const char8 *memoryOperatingModeCapability           = "N/A";
    const char8 *moduleManufacturerID                    = "N/A";
    const char8 *moduleProductID                         = "N/A";
    const char8 *memorySubsystemControllerManufacturerID = "N/A";
    const char8 *memorySubsystemControllerProductID      = "N/A";
    const char8 *nonVolatileSize                         = "N/A";
    const char8 *volatileSize                            = "N/A";
    const char8 *cacheSize                               = "N/A";
    const char8 *logicalSize                             = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        attributes            = mprintf("0x%02X", entry->attributes);
        extendedSize          = mprintf("%u",     entry->extendedSize);
        configuredMemorySpeed = mprintf("%u",     entry->configuredMemorySpeed);

        if (DMI::getVersion() >= DMI_VERSION(2, 8))
        {
            minimumVoltage    = mprintf("%u", entry->minimumVoltage);
            maximumVoltage    = mprintf("%u", entry->maximumVoltage);
            configuredVoltage = mprintf("%u", entry->configuredVoltage);

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                memoryTechnology                        = strdup(enumToFullString(entry->memoryTechnology));
                memoryOperatingModeCapability           = strdup(flagsToFullString(entry->memoryOperatingModeCapability));
                moduleManufacturerID                    = mprintf("%u", entry->moduleManufacturerID);
                moduleProductID                         = mprintf("%u", entry->moduleProductID);
                memorySubsystemControllerManufacturerID = mprintf("%u", entry->memorySubsystemControllerManufacturerID);
                memorySubsystemControllerProductID      = mprintf("%u", entry->memorySubsystemControllerProductID);
                nonVolatileSize                         = mprintf("%u", entry->nonVolatileSize);
                volatileSize                            = mprintf("%u", entry->volatileSize);
                cacheSize                               = mprintf("%u", entry->cacheSize);
                logicalSize                             = mprintf("%u", entry->logicalSize);
            }
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::MEMORY_DEVICE, DeviceManagerImage::MEMORY_DEVICE);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                                      mprintf("0x%04X", entry->header.handle)),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array handle",                         mprintf("0x%04X", entry->memoryArrayHandle)),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error information handle",             mprintf("0x%04X", entry->memoryErrorInformationHandle)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Total width",                                 mprintf("%u", entry->totalWidth)),                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data width",                                  mprintf("%u", entry->dataWidth)),                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Size",                                        mprintf("%u", entry->size)),                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Form factor",                                 strdup(enumToFullString(entry->formFactor))),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device set",                                  mprintf("%u", entry->deviceSet)),                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device locator",                              deviceLocatorString),                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bank locator",                                bankLocatorString),                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory type",                                 strdup(enumToFullString(entry->memoryType))),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type detail",                                 strdup(flagsToFullString(entry->typeDetail))),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Speed",                                       mprintf("%u", entry->speed)),                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",                                manufacturerString),                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",                               serialNumberString),                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",                                   assetTagString),                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Part number",                                 partNumberString),                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Attributes",                                  attributes),                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended size",                               extendedSize),                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Configured memory speed",                     configuredMemorySpeed),                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum voltage",                             minimumVoltage),                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum voltage",                             maximumVoltage),                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Configured voltage",                          configuredVoltage),                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory technology",                           memoryTechnology),                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory operating mode capability",            memoryOperatingModeCapability),                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Firmware version",                            firmwareVersionString),                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Module manufacturer ID",                      moduleManufacturerID),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Module product ID",                           moduleProductID),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory subsystem controller manufacturer ID", memorySubsystemControllerManufacturerID),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory subsystem controller product ID",      memorySubsystemControllerProductID),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("NonVolatile size",                            nonVolatileSize),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Volatile size",                               volatileSize),                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cache size",                                  cacheSize),                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Logical size",                                logicalSize),                                            NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryArrayMappedAddressEntry(DmiMemoryArrayMappedAddressEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->startingAddress   = 0x%08X", entry->startingAddress));
        UEFI_LVVV(("entry->endingAddress     = 0x%08X", entry->endingAddress));
        UEFI_LVVV(("entry->memoryArrayHandle = 0x%04X", entry->memoryArrayHandle));
        UEFI_LVVV(("entry->partitionWidth    = %u",     entry->partitionWidth));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->extendedStartingAddress = 0x%016lX", entry->extendedStartingAddress));
            UEFI_LVVV(("entry->extendedEndingAddress   = 0x%016lX", entry->extendedEndingAddress));
        }



        // UEFI_TEST_ASSERT(entry->startingAddress   == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->endingAddress     == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryArrayHandle == 0x1000,     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->partitionWidth    == 1,          NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // UEFI_TEST_ASSERT(entry->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= 31,                                       NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 15,                                            NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntry) - 16, NgosStatus::ASSERTION);
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *extendedStartingAddress = "N/A";
    const char8 *extendedEndingAddress   = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        extendedStartingAddress = mprintf("0x%016lX", entry->extendedStartingAddress);
        extendedEndingAddress   = mprintf("0x%016lX", entry->extendedEndingAddress);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS, DeviceManagerImage::MEMORY_ARRAY_MAPPED_ADDRESS);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                    mprintf("0x%04X", entry->header.handle)),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Starting address",          mprintf("0x%08X", entry->startingAddress)),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Ending address",            mprintf("0x%08X", entry->endingAddress)),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array handle",       mprintf("0x%04X", entry->memoryArrayHandle)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Partition width",           mprintf("%u", entry->partitionWidth)),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended starting address", extendedStartingAddress),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended ending address",   extendedEndingAddress),                       NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryDeviceMappedAddressEntry(DmiMemoryDeviceMappedAddressEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->startingAddress                = 0x%08X", entry->startingAddress));
        UEFI_LVVV(("entry->endingAddress                  = 0x%08X", entry->endingAddress));
        UEFI_LVVV(("entry->memoryDeviceHandle             = 0x%04X", entry->memoryDeviceHandle));
        UEFI_LVVV(("entry->memoryArrayMappedAddressHandle = 0x%04X", entry->memoryArrayMappedAddressHandle));
        UEFI_LVVV(("entry->partitionRowPosition           = %u",     entry->partitionRowPosition));
        UEFI_LVVV(("entry->interleavePosition             = %u",     entry->interleavePosition));
        UEFI_LVVV(("entry->interleavedDataDepth           = %u",     entry->interleavedDataDepth));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->extendedStartingAddress = 0x%016lX", entry->extendedStartingAddress));
            UEFI_LVVV(("entry->extendedEndingAddress   = 0x%016lX", entry->extendedEndingAddress));
        }



        // UEFI_TEST_ASSERT(entry->startingAddress                == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->endingAddress                  == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryDeviceHandle             == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryArrayMappedAddressHandle == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->partitionRowPosition           == 1,          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->interleavePosition             == 1,          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->interleavedDataDepth           == 1,          NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // UEFI_TEST_ASSERT(entry->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= 35,                                        NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 19,                                             NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntry) - 16, NgosStatus::ASSERTION);
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *extendedStartingAddress = "N/A";
    const char8 *extendedEndingAddress   = "N/A";

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        extendedStartingAddress = mprintf("0x%016lX", entry->extendedStartingAddress);
        extendedEndingAddress   = mprintf("0x%016lX", entry->extendedEndingAddress);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::MEMORY_DEVICE_MAPPED_ADDRESS, DeviceManagerImage::MEMORY_DEVICE_MAPPED_ADDRESS);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                             mprintf("0x%04X", entry->header.handle)),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Starting address",                   mprintf("0x%08X", entry->startingAddress)),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Ending address",                     mprintf("0x%08X", entry->endingAddress)),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory device handle",               mprintf("0x%04X", entry->memoryDeviceHandle)),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array mapped address handle", mprintf("0x%04X", entry->memoryArrayMappedAddressHandle)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Partition row position",             mprintf("%u", entry->partitionRowPosition)),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interleave position",                mprintf("%u", entry->interleavePosition)),                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interleaved data depth",             mprintf("%u", entry->interleavedDataDepth)),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended starting address",          extendedStartingAddress),                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended ending address",            extendedEndingAddress),                                    NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPortableBatteryEntry(DmiPortableBatteryEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->locationStringId            = %u",             entry->locationStringId));
        UEFI_LVVV(("entry->manufacturerStringId        = %u",             entry->manufacturerStringId));
        UEFI_LVVV(("entry->manufactureDateStringId     = %u",             entry->manufactureDateStringId));
        UEFI_LVVV(("entry->serialNumberStringId        = %u",             entry->serialNumberStringId));
        UEFI_LVVV(("entry->deviceNameStringId          = %u",             entry->deviceNameStringId));
        UEFI_LVVV(("entry->deviceChemistry             = %s",             enumToFullString(entry->deviceChemistry)));
        UEFI_LVVV(("entry->deviceCapacity              = %u",             entry->deviceCapacity));
        UEFI_LVVV(("entry->designVoltage               = %u",             entry->designVoltage));
        UEFI_LVVV(("entry->sbdsVersionNumberStringId   = %u",             entry->sbdsVersionNumberStringId));
        UEFI_LVVV(("entry->maximumErrorInBatteryData   = %u",             entry->maximumErrorInBatteryData));
        UEFI_LVVV(("entry->sbdsSerialNumber            = %u",             entry->sbdsSerialNumber));
        UEFI_LVVV(("entry->sbdsManufactureDate.date    = %u",             entry->sbdsManufactureDate.date));
        UEFI_LVVV(("entry->sbdsManufactureDate.month   = %u",             entry->sbdsManufactureDate.month));
        UEFI_LVVV(("entry->sbdsManufactureDate.year    = %u",             entry->sbdsManufactureDate.year));
        UEFI_LVVV(("entry->sbdsManufactureDate.value16 = 0x%04X",         entry->sbdsManufactureDate.value16));
        UEFI_LVVV(("entry->sbdsManufactureDate         = %04u-%02u-%02u", entry->sbdsManufactureDate.realYear(), entry->sbdsManufactureDate.month, entry->sbdsManufactureDate.date));
        UEFI_LVVV(("entry->sbdsDeviceChemistryStringId = %u",             entry->sbdsDeviceChemistryStringId));
        UEFI_LVVV(("entry->designCapacityMultiplier    = %u",             entry->designCapacityMultiplier));
        UEFI_LVVV(("entry->oemSpecific                 = 0x%08X",         entry->oemSpecific));



        // UEFI_TEST_ASSERT(entry->locationStringId            == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->manufacturerStringId        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->manufactureDateStringId     == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->serialNumberStringId        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceNameStringId          == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceChemistry             == DmiPortableBatteryDeviceChemistry::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceCapacity              == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->designVoltage               == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->sbdsVersionNumberStringId   == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumErrorInBatteryData   == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->sbdsSerialNumber            == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->sbdsManufactureDate.date    == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->sbdsManufactureDate.month   == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->sbdsManufactureDate.year    == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->sbdsManufactureDate.value16 == 0x0000,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->sbdsDeviceChemistryStringId == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->designCapacityMultiplier    == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->oemSpecific                 == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 26,                              NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntry), NgosStatus::ASSERTION);
    }



    const char8 *locationString            = "N/A";
    const char8 *manufacturerString        = "N/A";
    const char8 *manufactureDateString     = "N/A";
    const char8 *serialNumberString        = "N/A";
    const char8 *deviceNameString          = "N/A";
    const char8 *sbdsVersionNumberString   = "N/A";
    const char8 *sbdsDeviceChemistryString = "N/A";

    if (
        entry->locationStringId
        ||
        entry->manufacturerStringId
        ||
        entry->manufactureDateStringId
        ||
        entry->serialNumberStringId
        ||
        entry->deviceNameStringId
        ||
        entry->sbdsVersionNumberStringId
        ||
        entry->sbdsDeviceChemistryStringId
       )
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->locationStringId)
                {
                    locationString = begin;
                }
                else
                if (stringId == entry->manufacturerStringId)
                {
                    manufacturerString = begin;
                }
                else
                if (stringId == entry->manufactureDateStringId)
                {
                    manufactureDateString = begin;
                }
                else
                if (stringId == entry->serialNumberStringId)
                {
                    serialNumberString = begin;
                }
                else
                if (stringId == entry->deviceNameStringId)
                {
                    deviceNameString = begin;
                }
                else
                if (stringId == entry->sbdsVersionNumberStringId)
                {
                    sbdsVersionNumberString = begin;
                }
                else
                if (stringId == entry->sbdsDeviceChemistryStringId)
                {
                    sbdsDeviceChemistryString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::PORTABLE_BATTERY, DeviceManagerImage::PORTABLE_BATTERY);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                        mprintf("0x%04X", entry->header.handle)),                                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                      locationString),                                                                                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",                  manufacturerString),                                                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacture date",              manufactureDateString),                                                                                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",                 serialNumberString),                                                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name",                   deviceNameString),                                                                                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device chemistry",              strdup(enumToFullString(entry->deviceChemistry))),                                                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device capacity",               mprintf("%u", entry->deviceCapacity)),                                                                                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Design voltage",                mprintf("%u", entry->designVoltage)),                                                                                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS version number",           sbdsVersionNumberString),                                                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum error in battery data", mprintf("%u", entry->maximumErrorInBatteryData)),                                                                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS serial number",            mprintf("%u", entry->sbdsSerialNumber)),                                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS manufacture date",         mprintf("%04u-%02u-%02u", entry->sbdsManufactureDate.realYear(), entry->sbdsManufactureDate.month, entry->sbdsManufactureDate.date)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS device chemistry",         sbdsDeviceChemistryString),                                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Design capacity multiplier",    mprintf("%u", entry->designCapacityMultiplier)),                                                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM specific",                  mprintf("0x%08X", entry->oemSpecific)),                                                                                               NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiVoltageProbeEntry(DmiVoltageProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->descriptionStringId = %u",     entry->descriptionStringId));
        UEFI_LVVV(("entry->location            = %s",     enumToFullString((DmiVoltageProbeLocation)entry->location)));
        UEFI_LVVV(("entry->status              = %s",     enumToFullString((DmiVoltageProbeStatus)entry->status)));
        UEFI_LVVV(("entry->locationAndStatus   = 0x%02X", entry->locationAndStatus));
        UEFI_LVVV(("entry->maximumValue        = %u",     entry->maximumValue));
        UEFI_LVVV(("entry->minimumValue        = %u",     entry->minimumValue));
        UEFI_LVVV(("entry->resolution          = %u",     entry->resolution));
        UEFI_LVVV(("entry->tolerance           = %u",     entry->tolerance));
        UEFI_LVVV(("entry->accuracy            = %u",     entry->accuracy));
        UEFI_LVVV(("entry->oemDefined          = 0x%08X", entry->oemDefined));
        UEFI_LVVV(("entry->nominalValue        = %u",     entry->nominalValue));



        // UEFI_TEST_ASSERT(entry->descriptionStringId == 1,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->location            == DmiVoltageProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status              == DmiVoltageProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationAndStatus   == 0x00,                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumValue        == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->minimumValue        == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->resolution          == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->tolerance           == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->accuracy            == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->oemDefined          == 0x00000000,                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->nominalValue        == 0,                              NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiVoltageProbeEntry), NgosStatus::ASSERTION);
    }



    const char8 *descriptionString = "N/A";

    if (entry->descriptionStringId)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->descriptionStringId)
                {
                    descriptionString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::VOLTAGE_PROBE, DeviceManagerImage::VOLTAGE_PROBE);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   descriptionString),                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiVoltageProbeLocation)entry->location))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiVoltageProbeStatus)entry->status))),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", mprintf("%u", entry->maximumValue)),                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", mprintf("%u", entry->minimumValue)),                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    mprintf("%u", entry->resolution)),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     mprintf("%u", entry->tolerance)),                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      mprintf("%u", entry->accuracy)),                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined)),                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", mprintf("%u", entry->nominalValue)),                                 NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiCoolingDeviceEntry(DmiCoolingDeviceEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->temperatureProbeHandle = 0x%04X", entry->temperatureProbeHandle));
        UEFI_LVVV(("entry->deviceType             = %s",     enumToFullString((DmiCoolingDeviceType)entry->deviceType)));
        UEFI_LVVV(("entry->status                 = %s",     enumToFullString((DmiCoolingDeviceStatus)entry->status)));
        UEFI_LVVV(("entry->deviceTypeAndStatus    = 0x%02X", entry->deviceTypeAndStatus));
        UEFI_LVVV(("entry->coolingUnitGroup       = %u",     entry->coolingUnitGroup));
        UEFI_LVVV(("entry->oemDefined             = 0x%08X", entry->oemDefined));
        UEFI_LVVV(("entry->nominalSpeed           = %u",     entry->nominalSpeed));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->descriptionStringId = %u", entry->descriptionStringId));
        }



        // UEFI_TEST_ASSERT(entry->temperatureProbeHandle == 0x0000,                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceType             == DmiCoolingDeviceType::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status                 == DmiCoolingDeviceStatus::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceTypeAndStatus    == 0x00,                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->coolingUnitGroup       == 0,                             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->oemDefined             == 0x00000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->nominalSpeed           == 0,                             NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // UEFI_TEST_ASSERT(entry->descriptionStringId == 1, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= 15,                            NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 14,                                NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry) - 1, NgosStatus::ASSERTION);
        }
    }



    const char8 *descriptionString = "N/A";

    if (
        DMI::getVersion() >= DMI_VERSION(2, 7)
        &&
        entry->descriptionStringId
       )
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->descriptionStringId)
                {
                    descriptionString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::COOLING_DEVICE, DeviceManagerImage::COOLING_DEVICE);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                   mprintf("0x%04X", entry->header.handle)),                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Temperature probe handle", mprintf("0x%04X", entry->temperatureProbeHandle)),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type",              strdup(enumToFullString((DmiCoolingDeviceType)entry->deviceType))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                   strdup(enumToFullString((DmiCoolingDeviceStatus)entry->status))),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cooling unit group",       mprintf("%u", entry->coolingUnitGroup)),                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",              mprintf("0x%08X", entry->oemDefined)),                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal speed",            mprintf("%u", entry->nominalSpeed)),                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",              descriptionString),                                                 NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiTemperatureProbeEntry(DmiTemperatureProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->descriptionStringId = %u",     entry->descriptionStringId));
        UEFI_LVVV(("entry->location            = %s",     enumToFullString((DmiTemperatureProbeLocation)entry->location)));
        UEFI_LVVV(("entry->status              = %s",     enumToFullString((DmiTemperatureProbeStatus)entry->status)));
        UEFI_LVVV(("entry->locationAndStatus   = 0x%02X", entry->locationAndStatus));
        UEFI_LVVV(("entry->maximumValue        = %u",     entry->maximumValue));
        UEFI_LVVV(("entry->minimumValue        = %u",     entry->minimumValue));
        UEFI_LVVV(("entry->resolution          = %u",     entry->resolution));
        UEFI_LVVV(("entry->tolerance           = %u",     entry->tolerance));
        UEFI_LVVV(("entry->accuracy            = %u",     entry->accuracy));
        UEFI_LVVV(("entry->oemDefined          = 0x%08X", entry->oemDefined));
        UEFI_LVVV(("entry->nominalValue        = %u",     entry->nominalValue));



        // UEFI_TEST_ASSERT(entry->descriptionStringId == 1,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->location            == DmiTemperatureProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status              == DmiTemperatureProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationAndStatus   == 0x00,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumValue        == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->minimumValue        == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->resolution          == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->tolerance           == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->accuracy            == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->oemDefined          == 0x00000000,                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->nominalValue        == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                               NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiTemperatureProbeEntry), NgosStatus::ASSERTION);
    }



    const char8 *descriptionString = "N/A";

    if (entry->descriptionStringId)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->descriptionStringId)
                {
                    descriptionString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::TEMPERATURE_PROBE, DeviceManagerImage::TEMPERATURE_PROBE);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   descriptionString),                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiTemperatureProbeLocation)entry->location))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiTemperatureProbeStatus)entry->status))),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", mprintf("%u", entry->maximumValue)),                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", mprintf("%u", entry->minimumValue)),                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    mprintf("%u", entry->resolution)),                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     mprintf("%u", entry->tolerance)),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      mprintf("%u", entry->accuracy)),                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined)),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", mprintf("%u", entry->nominalValue)),                                     NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiElectricalCurrentProbeEntry(DmiElectricalCurrentProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->descriptionStringId = %u",     entry->descriptionStringId));
        UEFI_LVVV(("entry->location            = %s",     enumToFullString((DmiElectricalCurrentProbeLocation)entry->location)));
        UEFI_LVVV(("entry->status              = %s",     enumToFullString((DmiElectricalCurrentProbeStatus)entry->status)));
        UEFI_LVVV(("entry->locationAndStatus   = 0x%02X", entry->locationAndStatus));
        UEFI_LVVV(("entry->maximumValue        = %u",     entry->maximumValue));
        UEFI_LVVV(("entry->minimumValue        = %u",     entry->minimumValue));
        UEFI_LVVV(("entry->resolution          = %u",     entry->resolution));
        UEFI_LVVV(("entry->tolerance           = %u",     entry->tolerance));
        UEFI_LVVV(("entry->accuracy            = %u",     entry->accuracy));
        UEFI_LVVV(("entry->oemDefined          = 0x%08X", entry->oemDefined));
        UEFI_LVVV(("entry->nominalValue        = %u",     entry->nominalValue));



        // UEFI_TEST_ASSERT(entry->descriptionStringId == 1,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->location            == DmiElectricalCurrentProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status              == DmiElectricalCurrentProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationAndStatus   == 0x00,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumValue        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->minimumValue        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->resolution          == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->tolerance           == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->accuracy            == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->oemDefined          == 0x00000000,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->nominalValue        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiElectricalCurrentProbeEntry), NgosStatus::ASSERTION);
    }



    const char8 *descriptionString = "N/A";

    if (entry->descriptionStringId)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->descriptionStringId)
                {
                    descriptionString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::ELECTRICAL_CURRENT_PROBE, DeviceManagerImage::ELECTRICAL_CURRENT_PROBE);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   descriptionString),                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiElectricalCurrentProbeLocation)entry->location))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiElectricalCurrentProbeStatus)entry->status))),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", mprintf("%u", entry->maximumValue)),                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", mprintf("%u", entry->minimumValue)),                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    mprintf("%u", entry->resolution)),                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     mprintf("%u", entry->tolerance)),                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      mprintf("%u", entry->accuracy)),                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined)),                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", mprintf("%u", entry->nominalValue)),                                           NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemBootEntry(DmiSystemBootEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->bootStatus = %s", enumToFullString(entry->bootStatus)));

        // UEFI_TEST_ASSERT(entry->bootStatus == DmiSystemBootStatus::NO_ERROR, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 11,                         NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemBootEntry), NgosStatus::ASSERTION);
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::SYSTEM_BOOT, DeviceManagerImage::SYSTEM_BOOT);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",      mprintf("0x%04X", entry->header.handle)),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Boot status", strdup(enumToFullString(entry->bootStatus))), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiManagementDeviceEntry(DmiManagementDeviceEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->descriptionStringId = %u",     entry->descriptionStringId));
        UEFI_LVVV(("entry->type                = %s",     enumToFullString(entry->type)));
        UEFI_LVVV(("entry->address             = 0x%08X", entry->address));
        UEFI_LVVV(("entry->addressType         = %s",     enumToFullString(entry->addressType)));



        // UEFI_TEST_ASSERT(entry->descriptionStringId == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->type                == DmiManagementDeviceType::OTHER,        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->address             == 0x00000000,                            NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->addressType         == DmiManagementDeviceAddressType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 11,                               NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceEntry), NgosStatus::ASSERTION);
    }



    const char8 *descriptionString = "N/A";

    if (entry->descriptionStringId)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->descriptionStringId)
                {
                    descriptionString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::MANAGEMENT_DEVICE, DeviceManagerImage::MANAGEMENT_DEVICE);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",       mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",  descriptionString),                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",         strdup(enumToFullString(entry->type))),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Address",      mprintf("0x%08X", entry->address)),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Address type", strdup(enumToFullString(entry->addressType))), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiManagementDeviceComponentEntry(DmiManagementDeviceComponentEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->descriptionStringId    = %u",     entry->descriptionStringId));
        UEFI_LVVV(("entry->managementDeviceHandle = 0x%04X", entry->managementDeviceHandle));
        UEFI_LVVV(("entry->componentHandle        = 0x%04X", entry->componentHandle));
        UEFI_LVVV(("entry->thresholdHandle        = 0x%04X", entry->thresholdHandle));



        // UEFI_TEST_ASSERT(entry->descriptionStringId    == 1,      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->managementDeviceHandle == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->componentHandle        == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->thresholdHandle        == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 11,                                        NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceComponentEntry), NgosStatus::ASSERTION);
    }



    const char8 *descriptionString = "N/A";

    if (entry->descriptionStringId)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->descriptionStringId)
                {
                    descriptionString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::MANAGEMENT_DEVICE_COMPONENT, DeviceManagerImage::MANAGEMENT_DEVICE_COMPONENT);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                   mprintf("0x%04X", entry->header.handle)),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",              descriptionString),                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Management device handle", mprintf("0x%04X", entry->managementDeviceHandle)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Component handle",         mprintf("0x%04X", entry->componentHandle)),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Threshold handle",         mprintf("0x%04X", entry->thresholdHandle)),        NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiManagementDeviceThresholdDataEntry(DmiManagementDeviceThresholdDataEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->lowerThresholdNonCritical    = %u", entry->lowerThresholdNonCritical));
        UEFI_LVVV(("entry->upperThresholdNonCritical    = %u", entry->upperThresholdNonCritical));
        UEFI_LVVV(("entry->lowerThresholdCritical       = %u", entry->lowerThresholdCritical));
        UEFI_LVVV(("entry->upperThresholdCritical       = %u", entry->upperThresholdCritical));
        UEFI_LVVV(("entry->lowerThresholdNonRecoverable = %u", entry->lowerThresholdNonRecoverable));
        UEFI_LVVV(("entry->upperThresholdNonRecoverable = %u", entry->upperThresholdNonRecoverable));

        // UEFI_TEST_ASSERT(entry->lowerThresholdNonCritical    == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->upperThresholdNonCritical    == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->lowerThresholdCritical       == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->upperThresholdCritical       == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->lowerThresholdNonRecoverable == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->upperThresholdNonRecoverable == 0, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 16,                                            NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceThresholdDataEntry), NgosStatus::ASSERTION);
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::MANAGEMENT_DEVICE_THRESHOLD_DATA, DeviceManagerImage::MANAGEMENT_DEVICE_THRESHOLD_DATA);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle)),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold non-critical",    mprintf("%u", entry->lowerThresholdNonCritical)),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold non-critical",    mprintf("%u", entry->upperThresholdNonCritical)),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold critical",        mprintf("%u", entry->lowerThresholdCritical)),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold critical",        mprintf("%u", entry->upperThresholdCritical)),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold non-recoverable", mprintf("%u", entry->lowerThresholdNonRecoverable)), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold non-recoverable", mprintf("%u", entry->upperThresholdNonRecoverable)), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemPowerSupplyEntry(DmiSystemPowerSupplyEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->powerUnitGroup                                     = %u",     entry->powerUnitGroup));
        UEFI_LVVV(("entry->locationStringId                                   = %u",     entry->locationStringId));
        UEFI_LVVV(("entry->deviceNameStringId                                 = %u",     entry->deviceNameStringId));
        UEFI_LVVV(("entry->manufacturerStringId                               = %u",     entry->manufacturerStringId));
        UEFI_LVVV(("entry->serialNumberStringId                               = %u",     entry->serialNumberStringId));
        UEFI_LVVV(("entry->assetTagNumberStringId                             = %u",     entry->assetTagNumberStringId));
        UEFI_LVVV(("entry->modelPartNumberStringId                            = %u",     entry->modelPartNumberStringId));
        UEFI_LVVV(("entry->revisionLevelStringId                              = %u",     entry->revisionLevelStringId));
        UEFI_LVVV(("entry->maxPowerCapacity                                   = %u",     entry->maxPowerCapacity));
        UEFI_LVVV(("entry->powerSupplyCharacteristics.hotReplaceable          = %u",     entry->powerSupplyCharacteristics.hotReplaceable));
        UEFI_LVVV(("entry->powerSupplyCharacteristics.present                 = %u",     entry->powerSupplyCharacteristics.present));
        UEFI_LVVV(("entry->powerSupplyCharacteristics.unplugged               = %u",     entry->powerSupplyCharacteristics.unplugged));
        UEFI_LVVV(("entry->powerSupplyCharacteristics.inputVoltageRangeSwitch = %s",     enumToFullString((DmiSystemPowerSupplyInputVoltageRangeSwitch)entry->powerSupplyCharacteristics.inputVoltageRangeSwitch)));
        UEFI_LVVV(("entry->powerSupplyCharacteristics.status                  = %s",     enumToFullString((DmiSystemPowerSupplyStatus)entry->powerSupplyCharacteristics.status)));
        UEFI_LVVV(("entry->powerSupplyCharacteristics.type                    = %s",     enumToFullString((DmiSystemPowerSupplyType)entry->powerSupplyCharacteristics.type)));
        UEFI_LVVV(("entry->powerSupplyCharacteristics.value16                 = 0x%04X", entry->powerSupplyCharacteristics.value16));
        UEFI_LVVV(("entry->inputVoltageProbeHandle                            = 0x%04X", entry->inputVoltageProbeHandle));
        UEFI_LVVV(("entry->coolingDeviceHandle                                = 0x%04X", entry->coolingDeviceHandle));
        UEFI_LVVV(("entry->inputCurrentProbeHandle                            = 0x%04X", entry->inputCurrentProbeHandle));



        // UEFI_TEST_ASSERT(entry->powerUnitGroup                                     == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationStringId                                   == 1,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceNameStringId                                 == 2,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->manufacturerStringId                               == 3,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->serialNumberStringId                               == 4,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->assetTagNumberStringId                             == 5,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->modelPartNumberStringId                            == 6,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->revisionLevelStringId                              == 7,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maxPowerCapacity                                   == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->powerSupplyCharacteristics.hotReplaceable          == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->powerSupplyCharacteristics.present                 == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->powerSupplyCharacteristics.unplugged               == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->powerSupplyCharacteristics.inputVoltageRangeSwitch == DmiSystemPowerSupplyInputVoltageRangeSwitch::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->powerSupplyCharacteristics.status                  == DmiSystemPowerSupplyStatus::OTHER,                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->powerSupplyCharacteristics.type                    == DmiSystemPowerSupplyType::OTHER,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->powerSupplyCharacteristics.value16                 == 0x0000,                                             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->inputVoltageProbeHandle                            == 0x0000,                                             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->coolingDeviceHandle                                == 0x0000,                                             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->inputCurrentProbeHandle                            == 0x0000,                                             NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                                NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemPowerSupplyEntry), NgosStatus::ASSERTION);
    }



    const char8 *locationString        = "N/A";
    const char8 *deviceNameString      = "N/A";
    const char8 *manufacturerString    = "N/A";
    const char8 *serialNumberString    = "N/A";
    const char8 *assetTagNumberString  = "N/A";
    const char8 *modelPartNumberString = "N/A";
    const char8 *revisionLevelString   = "N/A";

    if (
        entry->locationStringId
        ||
        entry->deviceNameStringId
        ||
        entry->manufacturerStringId
        ||
        entry->serialNumberStringId
        ||
        entry->assetTagNumberStringId
        ||
        entry->modelPartNumberStringId
        ||
        entry->revisionLevelStringId
       )
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->locationStringId)
                {
                    locationString = begin;
                }
                else
                if (stringId == entry->deviceNameStringId)
                {
                    deviceNameString = begin;
                }
                else
                if (stringId == entry->manufacturerStringId)
                {
                    manufacturerString = begin;
                }
                else
                if (stringId == entry->serialNumberStringId)
                {
                    serialNumberString = begin;
                }
                else
                if (stringId == entry->assetTagNumberStringId)
                {
                    assetTagNumberString = begin;
                }
                else
                if (stringId == entry->modelPartNumberStringId)
                {
                    modelPartNumberString = begin;
                }
                else
                if (stringId == entry->revisionLevelStringId)
                {
                    revisionLevelString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::SYSTEM_POWER_SUPPLY, DeviceManagerImage::SYSTEM_POWER_SUPPLY);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                     mprintf("0x%04X", entry->header.handle)),                                                                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Power unit group",           mprintf("%u", entry->powerUnitGroup)),                                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                   locationString),                                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name",                deviceNameString),                                                                                                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",               manufacturerString),                                                                                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",              serialNumberString),                                                                                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag number",           assetTagNumberString),                                                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Model part number",          modelPartNumberString),                                                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision level",             revisionLevelString),                                                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum power capacity",     mprintf("%u", entry->maxPowerCapacity)),                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Hot replaceable",            entry->powerSupplyCharacteristics.hotReplaceable ? "Yes" : "No"),                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Present",                    entry->powerSupplyCharacteristics.present ? "Yes" : "No"),                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Unplugged",                  entry->powerSupplyCharacteristics.unplugged ? "Yes" : "No"),                                                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input voltage range switch", strdup(enumToFullString((DmiSystemPowerSupplyInputVoltageRangeSwitch)entry->powerSupplyCharacteristics.inputVoltageRangeSwitch))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                     strdup(enumToFullString((DmiSystemPowerSupplyStatus)entry->powerSupplyCharacteristics.status))),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                       strdup(enumToFullString((DmiSystemPowerSupplyType)entry->powerSupplyCharacteristics.type))),                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input voltage probe handle", mprintf("0x%04X", entry->inputVoltageProbeHandle)),                                                                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cooling device handle",      mprintf("0x%04X", entry->coolingDeviceHandle)),                                                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input current probe handle", mprintf("0x%04X", entry->inputCurrentProbeHandle)),                                                                                NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiAdditionalInformationEntry(DmiAdditionalInformationEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->numberOfAdditionalInformationEntries = %u", entry->numberOfAdditionalInformationEntries));



        DmiAdditionalInformation *curInfo = &entry->additionalInformationEntries[0];

        for (i64 i = 0; i < entry->numberOfAdditionalInformationEntries; ++i)
        {
            UEFI_LVVV(("curInfo->entryLength      = %u",     curInfo->entryLength));
            UEFI_LVVV(("curInfo->referencedHandle = 0x%04X", curInfo->referencedHandle));
            UEFI_LVVV(("curInfo->referencedOffset = %u",     curInfo->referencedOffset));
            UEFI_LVVV(("curInfo->stringStringId   = %u",     curInfo->stringStringId));
            UEFI_LVVV(("curInfo->value[0]         = %u",     curInfo->value[0]));

            curInfo = (DmiAdditionalInformation *)((u64)curInfo + curInfo->entryLength);
        }



        // UEFI_TEST_ASSERT(entry->numberOfAdditionalInformationEntries             == 1,      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].entryLength      == 6,      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].referencedHandle == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].referencedOffset == 1,      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].stringStringId   == 0,      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].value[0]         == 0,      NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 5,                                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiAdditionalInformationEntry), NgosStatus::ASSERTION);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::ADDITIONAL, DeviceManagerImage::ADDITIONAL);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                                   mprintf("0x%04X", entry->header.handle)),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of additional information entries", mprintf("%u", entry->numberOfAdditionalInformationEntries)), NgosStatus::ASSERTION);



    DmiAdditionalInformation *curInfo = &entry->additionalInformationEntries[0];

    for (i64 i = 0; i < entry->numberOfAdditionalInformationEntries; ++i)
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d length",            i), mprintf("%u",     curInfo->entryLength)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d referenced handle", i), mprintf("0x%04X", curInfo->referencedHandle)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d referenced offset", i), mprintf("%u",     curInfo->referencedOffset)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d string ID",         i), mprintf("%u",     curInfo->stringStringId)),   NgosStatus::ASSERTION);



        u8 valueSize = curInfo->entryLength - sizeof(DmiAdditionalInformation);

        if (valueSize > 0) // TODO: Move to function
        {
            const char8 *digits = "0123456789ABCDEF";



            bool cutted = false;
            u16  bufferSize;

            if (valueSize > VALUE_MAXIMUM_LENGTH / 2)
            {
                valueSize  = VALUE_MAXIMUM_LENGTH / 2;
                cutted     = true;
                bufferSize = VALUE_MAXIMUM_LENGTH + 3 + 1; // 3 == "...", 1 = zero at the end
            }
            else
            {
                bufferSize = valueSize * 2 + 1; // 1 = zero at the end
            }



            char8 *valueString = (char8 *)malloc(bufferSize);
            UEFI_TEST_ASSERT(valueString, NgosStatus::ASSERTION);

            char8 *cur = valueString;



            for (i64 j = 0; j < valueSize; ++j)
            {
                u8 valueByte = curInfo->value[j];

                *cur = digits[valueByte >> 4];
                *cur = digits[valueByte & 0x0F];

                cur += 2;
            }



            if (cutted)
            {
                cur[0] = '.';
                cur[1] = '.';
                cur[2] = '.';
                cur[3] = 0;
            }
            else
            {
                *cur = 0;
            }



            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d value", i), valueString), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d value", i), "N/A"), NgosStatus::ASSERTION);
        }



        curInfo = (DmiAdditionalInformation *)((u64)curInfo + curInfo->entryLength);
    }



    if (entry->numberOfAdditionalInformationEntries > 0)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("String #%u", stringId), begin), NgosStatus::ASSERTION);



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



    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiOnboardDevicesExtendedEntry(DmiOnboardDevicesExtendedEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->referenceDesignationStringId  = %u",     entry->referenceDesignationStringId));
        UEFI_LVVV(("entry->deviceType                    = %s",     enumToFullString((DmiOnboardDevicesExtendedDeviceType)entry->deviceType)));
        UEFI_LVVV(("entry->enabled                       = %u",     entry->enabled));
        UEFI_LVVV(("entry->deviceTypeAndEnabled          = 0x%02X", entry->deviceTypeAndEnabled));
        UEFI_LVVV(("entry->deviceTypeInstance            = %u",     entry->deviceTypeInstance));
        UEFI_LVVV(("entry->segmentGroupNumber            = %u",     entry->segmentGroupNumber));
        UEFI_LVVV(("entry->busNumber                     = %u",     entry->busNumber));
        UEFI_LVVV(("entry->functionNumber                = %u",     entry->functionNumber));
        UEFI_LVVV(("entry->deviceNumber                  = %u",     entry->deviceNumber));
        UEFI_LVVV(("entry->functionNumberAndDeviceNumber = 0x%02X", entry->functionNumberAndDeviceNumber));



        // UEFI_TEST_ASSERT(entry->referenceDesignationStringId  == 1,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceType                    == DmiOnboardDevicesExtendedDeviceType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->enabled                       == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceTypeAndEnabled          == 0x00,                                       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceTypeInstance            == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->segmentGroupNumber            == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->busNumber                     == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->functionNumber                == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceNumber                  == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->functionNumberAndDeviceNumber == 0x00,                                       NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 11,                                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesExtendedEntry), NgosStatus::ASSERTION);
    }



    const char8 *referenceDesignationString = "N/A";

    if (entry->referenceDesignationStringId)
    {
        UEFI_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                UEFI_LVVV(("String #%u: %s", stringId, begin));



                if (stringId == entry->referenceDesignationStringId)
                {
                    referenceDesignationString = begin;
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::ONBOARD_DEVICES, DeviceManagerImage::ONBOARD_DEVICES);

    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                mprintf("0x%04X", entry->header.handle)),                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Reference designation", referenceDesignationString),                                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type",           strdup(enumToFullString((DmiOnboardDevicesExtendedDeviceType)entry->deviceType))), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",               entry->enabled ? "Yes" : "No"),                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type instance",  mprintf("%u", entry->deviceTypeInstance)),                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment group number",  mprintf("%u", entry->segmentGroupNumber)),                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus number",            mprintf("%u", entry->busNumber)),                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Function number",       mprintf("%u", entry->functionNumber)),                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device number",         mprintf("%u", entry->deviceNumber)),                                               NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
