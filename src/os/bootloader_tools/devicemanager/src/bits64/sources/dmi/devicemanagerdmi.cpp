#include "devicemanagerdmi.h"

#include <common/src/bits64/dmi/dmi.h>
#include <common/src/bits64/string/utils.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uuid/utils.h>


#define ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, name, flagsVar, format, flagType) \
    { \
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(name, mprintf(format, flagsVar.flags)), NgosStatus::ASSERTION); \
        \
        for (i64 i = 0; i < (i64)(sizeof(flagsVar) * 8); ++i) \
        { \
            u64 flag = (1ULL << i); \
            \
            if (flagsVar.flags & flag) \
            { \
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf(name ": %s", flagToString((flagType)flag)), "Yes"), NgosStatus::ASSERTION); \
            } \
        } \
    }



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
        UEFI_LVVV(("entry->vendor.id                  = %u",     entry->vendor.id));
        UEFI_LVVV(("entry->biosVersion.id             = %u",     entry->biosVersion.id));
        UEFI_LVVV(("entry->biosStartingAddressSegment = 0x%04X", entry->biosStartingAddressSegment));
        UEFI_LVVV(("entry->biosReleaseDate.id         = %u",     entry->biosReleaseDate.id));
        UEFI_LVVV(("entry->biosRomSize.value          = 0x%02X", entry->biosRomSize.value));
        UEFI_LVVV(("entry->biosRomSize                = %s",     bytesToString(entry->biosRomSize.size())));
        UEFI_LVVV(("entry->biosCharacteristics        = %s",     flagsToFullString(entry->biosCharacteristics)));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            UEFI_LVVV(("entry->biosCharacteristicsExtension.biosReserved = %s", flagsToFullString(entry->biosCharacteristicsExtension.biosReserved)));

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                UEFI_LVVV(("entry->biosCharacteristicsExtension.systemReserved = %s", flagsToFullString(entry->biosCharacteristicsExtension.systemReserved)));

                if (DMI::getVersion() >= DMI_VERSION(2, 4))
                {
                    UEFI_LVVV(("entry->systemBiosMajorRelease                 = %u", entry->systemBiosMajorRelease));
                    UEFI_LVVV(("entry->systemBiosMinorRelease                 = %u", entry->systemBiosMinorRelease));
                    UEFI_LVVV(("entry->embeddedControllerFirmwareMajorRelease = %u", entry->embeddedControllerFirmwareMajorRelease));
                    UEFI_LVVV(("entry->embeddedControllerFirmwareMinorRelease = %u", entry->embeddedControllerFirmwareMinorRelease));

                    if (DMI::getVersion() >= DMI_VERSION(3, 1))
                    {
                        UEFI_LVVV(("entry->extendedBiosRomSize.value   = %u",     entry->extendedBiosRomSize.value));
                        UEFI_LVVV(("entry->extendedBiosRomSize.unit    = %s",     enumToFullString((DmiBiosExtendedRomSizeUnit)entry->extendedBiosRomSize.unit)));
                        UEFI_LVVV(("entry->extendedBiosRomSize.value16 = 0x%04X", entry->extendedBiosRomSize.value16));
                        UEFI_LVVV(("entry->extendedBiosRomSize         = %s",     bytesToString(entry->extendedBiosRomSize.size())));
                    }
                }
            }
        }



        UEFI_TEST_ASSERT(entry->vendor.id                     == 1,                                                                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->biosVersion.id                == 2,                                                                     NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->biosStartingAddressSegment == 0xE800,                                                                NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->biosReleaseDate.id            == 3,                                                                     NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->biosRomSize.value          == 0xFF,                                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->biosCharacteristics        == FLAGS(DmiBiosCharacteristicsFlag::BIOS_CHARACTERISTICS_NOT_SUPPORTED), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // UEFI_TEST_ASSERT(entry->biosCharacteristicsExtension.biosReserved == FLAG(DmiBiosCharacteristicsBiosReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                // UEFI_TEST_ASSERT(entry->biosCharacteristicsExtension.systemReserved == FLAG(DmiBiosCharacteristicsSystemReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(2, 4))
                {
                    // UEFI_TEST_ASSERT(entry->systemBiosMajorRelease                 == 15,  NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->systemBiosMinorRelease                 == 103, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->embeddedControllerFirmwareMajorRelease == 151, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->embeddedControllerFirmwareMinorRelease == 78,  NgosStatus::ASSERTION); // Commented due to value variation

                    if (DMI::getVersion() >= DMI_VERSION(3, 1))
                    {
                        // UEFI_TEST_ASSERT(entry->extendedBiosRomSize.value   == 0,                                     NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entry->extendedBiosRomSize.unit    == DmiBiosExtendedRomSizeUnit::MEGABYTES, NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entry->extendedBiosRomSize.value16 == 0x0000,                                NgosStatus::ASSERTION); // Commented due to value variation

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
                    UEFI_TEST_ASSERT(entry->header.length >= 20,                       NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry) - 6, NgosStatus::ASSERTION);
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



    const char8 *vendor          = "N/A";
    const char8 *biosVersion     = "N/A";
    const char8 *biosReleaseDate = "N/A";

    // Get strings
    {
        if (
            entry->vendor.id
            ||
            entry->biosVersion.id
            ||
            entry->biosReleaseDate.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->vendor)
                    {
                        vendor = begin;
                    }
                    else
                    if (stringId == entry->biosVersion)
                    {
                        biosVersion = begin;
                    }
                    else
                    if (stringId == entry->biosReleaseDate)
                    {
                        biosReleaseDate = begin;
                    }



                    if (cur[1] == 0)
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
    }



    const char8 *systemBiosMajorRelease                     = "N/A";
    const char8 *systemBiosMinorRelease                     = "N/A";
    const char8 *embeddedControllerFirmwareMajorRelease     = "N/A";
    const char8 *embeddedControllerFirmwareMinorRelease     = "N/A";
    const char8 *extendedBiosRomSize                        = "N/A";

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 4))
        {
            // Get string for System BIOS major release
            {
                if (entry->systemBiosMajorRelease != DMI_BIOS_SYSTEM_BIOS_MAJOR_RELEASE_NOT_AVAILABLE)
                {
                    systemBiosMajorRelease = mprintf("%u", entry->systemBiosMajorRelease);
                }
            }



            // Get string for System BIOS minor release
            {
                if (entry->systemBiosMinorRelease != DMI_BIOS_SYSTEM_BIOS_MINOR_RELEASE_NOT_AVAILABLE)
                {
                    systemBiosMinorRelease = mprintf("%u", entry->systemBiosMinorRelease);
                }
            }



            // Get string for Embedded controller firmware major release
            {
                if (entry->embeddedControllerFirmwareMajorRelease != DMI_BIOS_EMBEDDED_CONTROLLER_FIRMWARE_MAJOR_RELEASE_NOT_AVAILABLE)
                {
                    embeddedControllerFirmwareMajorRelease = mprintf("%u", entry->embeddedControllerFirmwareMajorRelease);
                }
            }



            // Get string for Embedded controller firmware minor release
            {
                if (entry->embeddedControllerFirmwareMinorRelease != DMI_BIOS_EMBEDDED_CONTROLLER_FIRMWARE_MINOR_RELEASE_NOT_AVAILABLE)
                {
                    embeddedControllerFirmwareMinorRelease = mprintf("%u", entry->embeddedControllerFirmwareMinorRelease);
                }
            }



            if (DMI::getVersion() >= DMI_VERSION(3, 1))
            {
                extendedBiosRomSize = mprintf("0x%04X", entry->extendedBiosRomSize.value16);
            }
        }
    }



    const char8 *biosRomSize;

    // Get other strings
    {
        // Get string for ROM size
        {
            if (
                entry->biosRomSize.value == DMI_BIOS_BIOS_ROM_SIZE_NEED_TO_EXTEND
                &&
                DMI::getVersion() >= DMI_VERSION(3, 1)
               )
            {
                biosRomSize = strdup(bytesToString(entry->extendedBiosRomSize.size()));
            }
            else
            {
                biosRomSize = strdup(bytesToString(entry->biosRomSize.size()));
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",               strdup(enumToFullString(entry->header.type))),         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                   mprintf("0x%04X", entry->header.handle)),              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor",                   vendor),                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",                  biosVersion),                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Starting address segment", mprintf("0x%04X", entry->biosStartingAddressSegment)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Release date",             biosReleaseDate),                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("ROM size",                 biosRomSize),                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("ROM size",                 mprintf("0x%02X", entry->biosRomSize.value)),          NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics", entry->biosCharacteristics, "0x%016lX", DmiBiosCharacteristicsFlag);



        // Add records for Characteristics (BIOS reserved)
        {
            if (DMI::getVersion() >= DMI_VERSION(2, 1))
            {
                ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics (BIOS reserved)", entry->biosCharacteristicsExtension.biosReserved, "0x%02X", DmiBiosCharacteristicsBiosReservedFlag);
            }
            else
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics (BIOS reserved)", "N/A"), NgosStatus::ASSERTION);
            }
        }



        // Add records for Characteristics (System reserved)
        {
            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics (System reserved)", entry->biosCharacteristicsExtension.systemReserved, "0x%02X", DmiBiosCharacteristicsSystemReservedFlag);
            }
            else
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics (System reserved)", "N/A"), NgosStatus::ASSERTION);
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System BIOS major release",                  systemBiosMajorRelease),                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System BIOS minor release",                  systemBiosMinorRelease),                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Embedded controller firmware major release", embeddedControllerFirmwareMajorRelease), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Embedded controller firmware minor release", embeddedControllerFirmwareMinorRelease), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended ROM size",                          extendedBiosRomSize),                    NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemEntry(DmiSystemEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->manufacturer.id = %u", entry->manufacturer.id));
        UEFI_LVVV(("entry->productName.id  = %u", entry->productName.id));
        UEFI_LVVV(("entry->version.id      = %u", entry->version.id));
        UEFI_LVVV(("entry->serialNumber.id = %u", entry->serialNumber.id));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            UEFI_LVVV(("entry->uuid       = %s", uuidToString(entry->uuid)));
            UEFI_LVVV(("entry->wakeUpType = %s", enumToFullString(entry->wakeUpType)));

            if (DMI::getVersion() >= DMI_VERSION(2, 4))
            {
                UEFI_LVVV(("entry->skuNumber.id = %u", entry->skuNumber.id));
                UEFI_LVVV(("entry->family.id    = %u", entry->family.id));
            }
        }



        UEFI_TEST_ASSERT(entry->manufacturer.id    == 1, NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->productName.id     == 2, NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->version.id         == 3, NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->serialNumber.id == 4, NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // UEFI_TEST_ASSERT(entry->uuid.data1    == 0x9FAE0773,                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data2    == 0xF53F,                            NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data3    == 0x4A15,                            NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data4    == 0x8A,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data5    == 0x11,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data6[0] == 0xED,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data6[1] == 0x76,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data6[2] == 0xA1,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data6[3] == 0x0F,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data6[4] == 0x4E,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->uuid.data6[5] == 0x5B,                              NgosStatus::ASSERTION); // Commented due to value variation
            UEFI_TEST_ASSERT(entry->wakeUpType       == DmiSystemWakeUpType::POWER_SWITCH, NgosStatus::ASSERTION);

            if (DMI::getVersion() >= DMI_VERSION(2, 4))
            {
                // UEFI_TEST_ASSERT(entry->skuNumber.id == 5, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->family.id    == 6, NgosStatus::ASSERTION); // Commented due to value variation

                UEFI_TEST_ASSERT(entry->header.length >= 27,                     NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry), NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 25,                         NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry) - 2, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 8,                           NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry) - 19, NgosStatus::ASSERTION);
        }
    }



    const char8 *manufacturer = "N/A";
    const char8 *productName  = "N/A";
    const char8 *version      = "N/A";
    const char8 *serialNumber = "N/A";
    const char8 *skuNumber    = "N/A";
    const char8 *family       = "N/A";

    // Get strings
    {
        DmiStringId skuNumberStringId;
        DmiStringId familyStringId;

        if (DMI::getVersion() >= DMI_VERSION(2, 4))
        {
            skuNumberStringId = entry->skuNumber;
            familyStringId    = entry->family;
        }



        if (
            entry->manufacturer.id
            ||
            entry->productName.id
            ||
            entry->version.id
            ||
            entry->serialNumber.id
            ||
            skuNumberStringId.id
            ||
            familyStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->manufacturer)
                    {
                        manufacturer = begin;
                    }
                    else
                    if (stringId == entry->productName)
                    {
                        productName = begin;
                    }
                    else
                    if (stringId == entry->version)
                    {
                        version = begin;
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        serialNumber = begin;
                    }
                    else
                    if (stringId == skuNumberStringId)
                    {
                        skuNumber = begin;
                    }
                    else
                    if (stringId == familyStringId)
                    {
                        family = begin;
                    }



                    if (cur[1] == 0)
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
    }



    const char8 *uuid       = "N/A";
    const char8 *wakeUpType = "N/A";

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            uuid       = strdup(uuidToString(entry->uuid));
            wakeUpType = strdup(enumToFullString(entry->wakeUpType));
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",  manufacturer),                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Product name",  productName),                                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",       version),                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number", serialNumber),                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("UUID",          uuid),                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Wake-Up type",  wakeUpType),                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SKU number",    skuNumber),                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",        family),                                       NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBaseboardEntry(DmiBaseboardEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->manufacturer.id                = %u",     entry->manufacturer.id));
        UEFI_LVVV(("entry->product.id                     = %u",     entry->product.id));
        UEFI_LVVV(("entry->version.id                     = %u",     entry->version.id));
        UEFI_LVVV(("entry->serialNumber.id                = %u",     entry->serialNumber.id));
        UEFI_LVVV(("entry->assetTag.id                    = %u",     entry->assetTag.id));
        UEFI_LVVV(("entry->featureFlags                   = %s",     flagsToFullString(entry->featureFlags)));
        UEFI_LVVV(("entry->locationInChassis.id           = %u",     entry->locationInChassis.id));
        UEFI_LVVV(("entry->chassisHandle                  = 0x%04X", entry->chassisHandle));
        UEFI_LVVV(("entry->boardType                      = %s",     enumToFullString(entry->boardType)));
        UEFI_LVVV(("entry->numberOfContainedObjectHandles = %u",     entry->numberOfContainedObjectHandles));



        // entry->containedObjectHandles:
        {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            UEFI_LVVV(("entry->containedObjectHandles:"));
            UEFI_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)
            {
                UEFI_LVVV(("#%-3d: 0x%04X", i, entry->containedObjectHandles[i]));
            }

            UEFI_LVVV(("-------------------------------------"));
#endif
        }



        UEFI_TEST_ASSERT(entry->manufacturer.id                == 1,                                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->product.id                     == 2,                                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->version.id                     == 3,                                           NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->serialNumber.id             == 4,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->assetTag.id                 == 5,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->featureFlags                == FLAGS(DmiBaseboardFeatureFlag::MOTHERBOARD), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationInChassis.id        == 6,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->chassisHandle               == 0x0300,                                      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->boardType                   == DmiBaseboardType::MOTHERBOARD,               NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->numberOfContainedObjectHandles == 0,                                           NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->containedObjectHandles[0]   == 0,                                           NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 15                        + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBaseboardEntry) + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);
    }



    const char8 *manufacturer      = "N/A";
    const char8 *product           = "N/A";
    const char8 *version           = "N/A";
    const char8 *serialNumber      = "N/A";
    const char8 *assetTag          = "N/A";
    const char8 *locationInChassis = "N/A";

    // Get strings
    {
        if (
            entry->manufacturer.id
            ||
            entry->product.id
            ||
            entry->version.id
            ||
            entry->serialNumber.id
            ||
            entry->assetTag.id
            ||
            entry->locationInChassis.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->manufacturer)
                    {
                        manufacturer = begin;
                    }
                    else
                    if (stringId == entry->product)
                    {
                        product = begin;
                    }
                    else
                    if (stringId == entry->version)
                    {
                        version = begin;
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        serialNumber = begin;
                    }
                    else
                    if (stringId == entry->assetTag)
                    {
                        assetTag = begin;
                    }
                    else
                    if (stringId == entry->locationInChassis)
                    {
                        locationInChassis = begin;
                    }



                    if (cur[1] == 0)
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
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",  manufacturer),                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Product",       product),                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",       version),                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number", serialNumber),                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",     assetTag),                                     NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Features", entry->featureFlags, "0x%04X", DmiBaseboardFeatureFlag);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location in chassis",                locationInChassis),                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Chassis handle",                     mprintf("0x%04X", entry->chassisHandle)),              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Board type",                         strdup(enumToFullString(entry->boardType))),           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of contained object handles", mprintf("%u", entry->numberOfContainedObjectHandles)), NgosStatus::ASSERTION);



        // Add records for Contained object handles
        {
            for (i64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained object handle #%d", i), mprintf("0x%04X", entry->containedObjectHandles[i])), NgosStatus::ASSERTION);
            }
        }



        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiChassisEntry(DmiChassisEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiStringId skuNumberStringId;

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        skuNumberStringId = *(DmiStringId *)DMI_CHASSIS_CONTAINED_ELEMENT(entry, entry->containedElementCount);
    }



    // Validation
    {
        UEFI_LVVV(("entry->manufacturer.id = %u",     entry->manufacturer.id));
        UEFI_LVVV(("entry->type            = %s",     enumToFullString((DmiChassisType)entry->type)));
        UEFI_LVVV(("entry->locked          = %u",     entry->locked));
        UEFI_LVVV(("entry->typeAndLocked   = 0x%02X", entry->typeAndLocked));
        UEFI_LVVV(("entry->version.id      = %u",     entry->version.id));
        UEFI_LVVV(("entry->serialNumber.id = %u",     entry->serialNumber.id));
        UEFI_LVVV(("entry->assetTag.id     = %u",     entry->assetTag.id));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            UEFI_LVVV(("entry->bootUpState      = %s", enumToFullString(entry->bootUpState)));
            UEFI_LVVV(("entry->powerSupplyState = %s", enumToFullString(entry->powerSupplyState)));
            UEFI_LVVV(("entry->thermalState     = %s", enumToFullString(entry->thermalState)));
            UEFI_LVVV(("entry->securityStatus   = %s", enumToFullString(entry->securityStatus)));

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                UEFI_LVVV(("entry->oemDefined                   = 0x%08X", entry->oemDefined));
                UEFI_LVVV(("entry->height                       = %u",     entry->height));
                UEFI_LVVV(("entry->numberOfPowerCords           = %u",     entry->numberOfPowerCords));
                UEFI_LVVV(("entry->containedElementCount        = %u",     entry->containedElementCount));
                UEFI_LVVV(("entry->containedElementRecordLength = %u",     entry->containedElementRecordLength));



                // entry->containedElements:
                {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                    UEFI_LVVV(("entry->containedElements:"));
                    UEFI_LVVV(("-------------------------------------"));

                    for (i64 i = 0; i < entry->containedElementCount; ++i)
                    {
                        DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entry, i);

                        UEFI_LVVV(("containedElement[%-3d]->type.typeSelect = %s", i, enumToFullString((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect)));

                        switch ((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect)
                        {
                            case DmiChassisContainedElementTypeSelect::BASEBOARD_TYPE: UEFI_LVVV(("containedElement[%-3d]->type.baseboardType = %s", i, enumToFullString((DmiBaseboardType)containedElement->type.baseboardType))); break;
                            case DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE: UEFI_LVVV(("containedElement[%-3d]->type.dmiEntryType  = %s", i, enumToFullString((DmiEntryType)containedElement->type.dmiEntryType)));      break;

                            default:
                            {
                                UEFI_LF(("Unknown DMI chassis contained element type select %s, %s:%u", enumToFullString((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect), __FILE__, __LINE__));

                                return NgosStatus::UNEXPECTED_BEHAVIOUR;
                            }
                            break;
                        }

                        UEFI_LVVV(("containedElement[%-3d]->type.value8 = 0x%02X", i, containedElement->type.value8));
                        UEFI_LVVV(("containedElement[%-3d]->minimum     = %u",     i, containedElement->minimum));
                        UEFI_LVVV(("containedElement[%-3d]->maximum     = %u",     i, containedElement->maximum));
                    }

                    UEFI_LVVV(("-------------------------------------"));
#endif
                }



                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    UEFI_LVVV(("skuNumberStringId.id = %u", skuNumberStringId.id));
                }
            }
        }



        UEFI_TEST_ASSERT(entry->manufacturer.id    == 1,                       NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->type            == DmiChassisType::DESKTOP, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locked          == 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->typeAndLocked   == 0x03,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->version.id      == 2,                       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->serialNumber.id == 3,                       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->assetTag.id     == 4,                       NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            UEFI_TEST_ASSERT(entry->bootUpState       == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->powerSupplyState  == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->thermalState   == DmiChassisState::SAFE,             NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->securityStatus == DmiChassisSecurityStatus::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                UEFI_TEST_ASSERT(entry->oemDefined                                             == 0x00000000,                                           NgosStatus::ASSERTION);
                // UEFI_TEST_ASSERT(entry->height                                              == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->numberOfPowerCords                                  == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->containedElementCount                               == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->containedElementRecordLength                        == 3,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->type.typeSelect   == DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->type.dmiEntryType == DmiEntryType::SYSTEM_POWER_SUPPLY,                    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->type.value8       == 0xA7,                                                 NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->minimum           == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->maximum           == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    // UEFI_TEST_ASSERT(skuNumberStringId.id == 5, NgosStatus::ASSERTION); // Commented due to value variation

                    UEFI_TEST_ASSERT(entry->header.length >= 21                      + entry->containedElementCount * entry->containedElementRecordLength + 1, NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) + entry->containedElementCount * entry->containedElementRecordLength + 1, NgosStatus::ASSERTION);
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= 21                      + entry->containedElementCount * entry->containedElementRecordLength, NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) + entry->containedElementCount * entry->containedElementRecordLength, NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 13,                          NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) - 8, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 9,                            NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) - 12, NgosStatus::ASSERTION);
        }
    }



    const char8 *manufacturer = "N/A";
    const char8 *version      = "N/A";
    const char8 *serialNumber = "N/A";
    const char8 *assetTag     = "N/A";
    const char8 *skuNumber    = "N/A";

    // Get strings
    {
        if (
            entry->manufacturer.id
            ||
            entry->version.id
            ||
            entry->serialNumber.id
            ||
            entry->assetTag.id
            ||
            skuNumberStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->manufacturer)
                    {
                        manufacturer = begin;
                    }
                    else
                    if (stringId == entry->version)
                    {
                        version = begin;
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        serialNumber = begin;
                    }
                    else
                    if (stringId == entry->assetTag)
                    {
                        assetTag = begin;
                    }
                    else
                    if (stringId == skuNumberStringId)
                    {
                        skuNumber = begin;
                    }



                    if (cur[1] == 0)
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
    }



    const char8 *bootUpState                  = "N/A";
    const char8 *powerSupplyState             = "N/A";
    const char8 *thermalState                 = "N/A";
    const char8 *securityStatus               = "N/A";
    const char8 *oemDefined                   = "N/A";
    const char8 *height                       = "N/A";
    const char8 *numberOfPowerCords           = "N/A";
    const char8 *containedElementCount        = "N/A";
    const char8 *containedElementRecordLength = "N/A";

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            bootUpState      = strdup(enumToFullString(entry->bootUpState));
            powerSupplyState = strdup(enumToFullString(entry->powerSupplyState));
            thermalState     = strdup(enumToFullString(entry->thermalState));
            securityStatus   = strdup(enumToFullString(entry->securityStatus));

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                oemDefined = mprintf("0x%08X", entry->oemDefined);

                if (entry->height != DMI_CHASSIS_HEIGHT_NOT_AVAILABLE)
                {
                    height = mprintf("%u U", entry->height);
                }

                if (entry->numberOfPowerCords != DMI_CHASSIS_NUMBER_OF_POWER_CORDS_NOT_AVAILABLE)
                {
                    numberOfPowerCords = mprintf("%u", entry->numberOfPowerCords);
                }

                if (
                    entry->containedElementCount != DMI_CHASSIS_CONTAINED_ELEMENT_COUNT_NOT_AVAILABLE
                    &&
                    entry->containedElementRecordLength != DMI_CHASSIS_CONTAINED_ELEMENT_RECORD_LENGTH_NOT_AVAILABLE
                   )
                {
                    containedElementCount        = mprintf("%u", entry->containedElementCount);
                    containedElementRecordLength = mprintf("%u", entry->containedElementRecordLength);
                }
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                      strdup(enumToFullString(entry->header.type))),          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle)),               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",                    manufacturer),                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                            strdup(enumToFullString((DmiChassisType)entry->type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Locked",                          entry->locked ? "Yes" : "No"),                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",                         version),                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",                   serialNumber),                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",                       assetTag),                                              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Boot up state",                   bootUpState),                                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Power supply state",              powerSupplyState),                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thermal state",                   thermalState),                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Security status",                 securityStatus),                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",                     oemDefined),                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Height",                          height),                                                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of power cords",           numberOfPowerCords),                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Contained element count",         containedElementCount),                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Contained element record length", containedElementRecordLength),                          NgosStatus::ASSERTION);



        // Add records for Contained elements
        {
            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                for (i64 i = 0; i < entry->containedElementCount; ++i)
                {
                    DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entry, i);

                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d type select"), strdup(enumToFullString((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect))), NgosStatus::ASSERTION);

                    switch ((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect)
                    {
                        case DmiChassisContainedElementTypeSelect::BASEBOARD_TYPE: UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d type"), strdup(enumToFullString((DmiBaseboardType)containedElement->type.baseboardtype))), NgosStatus::ASSERTION); break;
                        case DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE: UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d type"), strdup(enumToFullString((DmiEntryType)containedElement->type.dmiEntrytype))),      NgosStatus::ASSERTION); break;

                        default:
                        {
                            UEFI_LF(("Unknown DMI chassis contained element type select %s, %s:%u", enumToFullString((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect), __FILE__, __LINE__));

                            return NgosStatus::UNEXPECTED_BEHAVIOUR;
                        }
                        break;
                    }

                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d minimum"), mprintf("%u", containedElement->minimum)), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d maximum"), mprintf("%u", containedElement->maximum)), NgosStatus::ASSERTION);
                }
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SKU number", skuNumber), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiProcessorEntry(DmiProcessorEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->socketDesignation.id                 = %u",     entry->socketDesignation.id));
        UEFI_LVVV(("entry->processorType                        = %s",     enumToFullString(entry->processorType)));
        UEFI_LVVV(("entry->processorFamily                      = %s",     enumToFullString(entry->processorFamily)));
        UEFI_LVVV(("entry->processorManufacturer.id             = %u",     entry->processorManufacturer.id));
        UEFI_LVVV(("entry->processorId.signature.stepping       = %u",     entry->processorId.signature.stepping));
        UEFI_LVVV(("entry->processorId.signature.model          = %u",     entry->processorId.signature.model));
        UEFI_LVVV(("entry->processorId.signature.family         = %u",     entry->processorId.signature.family));
        UEFI_LVVV(("entry->processorId.signature.type           = %u",     entry->processorId.signature.type));
        UEFI_LVVV(("entry->processorId.signature.extendedModel  = %u",     entry->processorId.signature.extendedModel));
        UEFI_LVVV(("entry->processorId.signature.extendedFamily = %u",     entry->processorId.signature.extendedFamily));
        UEFI_LVVV(("entry->processorId.signature.value32        = 0x%08X", entry->processorId.signature.value32));
        UEFI_LVVV(("entry->processorId.featureFlags             = %s",     flagsToFullString(entry->processorId.featureFlags)));
        UEFI_LVVV(("entry->processorVersion.id                  = %u",     entry->processorVersion.id));
        UEFI_LVVV(("entry->voltage.modeType                     = %s",     enumToFullString((DmiProcessorVoltageModeType)entry->voltage.modeType)));

        switch ((DmiProcessorVoltageModeType)entry->voltage.modeType)
        {
            case DmiProcessorVoltageModeType::LEGACY_MODE:          UEFI_LVVV(("entry->voltage.flags = %s", flagsToFullString((DmiProcessorVoltageFlags)entry->voltage.flags))); break;
            case DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE: UEFI_LVVV(("entry->voltage.value = %u", entry->voltage.value));                                              break;

            default:
            {
                UEFI_LF(("Unknown DMI processor voltage mode type %s, %s:%u", enumToFullString((DmiProcessorVoltageModeType)entry->voltage.modeType), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }

        UEFI_LVVV(("entry->voltage.value8   = 0x%02X", entry->voltage.value8));
        UEFI_LVVV(("entry->externalClock    = %u",     entry->externalClock));
        UEFI_LVVV(("entry->maxSpeed         = %u",     entry->maxSpeed));
        UEFI_LVVV(("entry->currentSpeed     = %u",     entry->currentSpeed));
        UEFI_LVVV(("entry->status           = %s",     enumToFullString((DmiProcessorStatus)entry->status)));
        UEFI_LVVV(("entry->socketPopulated  = %u",     entry->socketPopulated));
        UEFI_LVVV(("entry->processorStatus  = 0x%02X", entry->processorStatus));
        UEFI_LVVV(("entry->processorUpgrade = %s",     enumToFullString(entry->processorUpgrade)));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            UEFI_LVVV(("entry->l1CacheHandle = 0x%04X", entry->l1CacheHandle));
            UEFI_LVVV(("entry->l2CacheHandle = 0x%04X", entry->l2CacheHandle));
            UEFI_LVVV(("entry->l3CacheHandle = 0x%04X", entry->l3CacheHandle));

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                UEFI_LVVV(("entry->serialNumber.id = %u", entry->serialNumber.id));
                UEFI_LVVV(("entry->assetTag.id     = %u", entry->assetTag.id));
                UEFI_LVVV(("entry->partNumber.id   = %u", entry->partNumber.id));

                if (DMI::getVersion() >= DMI_VERSION(2, 5))
                {
                    UEFI_LVVV(("entry->coreCount                = 0x%02X", entry->coreCount));
                    UEFI_LVVV(("entry->enabledCoreCount         = 0x%02X", entry->enabledCoreCount));
                    UEFI_LVVV(("entry->threadCount              = 0x%02X", entry->threadCount));
                    UEFI_LVVV(("entry->processorCharacteristics = %s",     flagsToFullString(entry->processorCharacteristics)));

                    if (DMI::getVersion() >= DMI_VERSION(2, 6))
                    {
                        UEFI_LVVV(("entry->processorFamily2 = %s", enumToFullString(entry->processorFamily2)));

                        if (DMI::getVersion() >= DMI_VERSION(3, 0))
                        {
                            UEFI_LVVV(("entry->coreCount2        = 0x%04X", entry->coreCount2));
                            UEFI_LVVV(("entry->enabledCoreCount2 = 0x%04X", entry->enabledCoreCount2));
                            UEFI_LVVV(("entry->threadCount2      = 0x%04X", entry->threadCount2));
                        }
                    }
                }
            }
        }



        // Ignore CppAlignmentVerifier [BEGIN]
        // UEFI_TEST_ASSERT(entry->socketDesignation.id                 == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->processorType                           == DmiProcessorType::CENTRAL_PROCESSOR,               NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->processorFamily                      == DmiProcessorFamily::OTHER,                         NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->processorManufacturer.id                == 2,                                                 NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->processorId.signature.stepping       == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.signature.model          == 12,                                                NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.signature.family         == 6,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->processorId.signature.type              == 0,                                                 NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->processorId.signature.extendedModel  == 3,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.signature.extendedFamily == 0,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.signature.value32        == 0x00000000,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorId.featureFlags             == FLAGS(DmiProcessorFeatureFlag::FPU                                         // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::VME                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::DE                                        // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PSE                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::TSC                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MSR                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PAE                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MCE                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::CX8                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::APIC                                      // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::SEP                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MTRR                                      // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PGE                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MCA                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::CMOV                                      // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PAT                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::PSE36                                     // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::CLFSH                                     // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::MMX                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::FXSR                                      // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::SSE                                       // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::SSE2                                      // Commented due to value variation
        //                                                                       , DmiProcessorFeatureFlag::SS),              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorVersion.id                  == 3,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->voltage.modeType                     == DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->voltage.value                        == 18,                                                NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->voltage.value8                       == 0x92,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->externalClock                        == 100,                                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maxSpeed                             == 2000,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->currentSpeed                         == 2000,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status                               == DmiProcessorStatus::ENABLED,                       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->socketPopulated                      == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorStatus                      == 0x41,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->processorUpgrade                     == DmiProcessorUpgrade::OTHER,                        NgosStatus::ASSERTION); // Commented due to value variation
        // Ignore CppAlignmentVerifier [END]

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // UEFI_TEST_ASSERT(entry->l1CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->l2CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->l3CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                // UEFI_TEST_ASSERT(entry->serialNumber.id == 4, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->assetTag.id     == 5, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->partNumber.id   == 6, NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(2, 5))
                {
                    // UEFI_TEST_ASSERT(entry->coreCount                == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->enabledCoreCount         == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->threadCount              == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->processorCharacteristics == FLAGS(DmiProcessorCharacteristicsFlag::SUPPORT_64_BIT), NgosStatus::ASSERTION); // Commented due to value variation

                    if (DMI::getVersion() >= DMI_VERSION(2, 6))
                    {
                        // UEFI_TEST_ASSERT(entry->processorFamily2 == DmiProcessorFamily2::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

                        if (DMI::getVersion() >= DMI_VERSION(3, 0))
                        {
                            // UEFI_TEST_ASSERT(entry->coreCount2        == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation
                            // UEFI_TEST_ASSERT(entry->enabledCoreCount2 == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation
                            // UEFI_TEST_ASSERT(entry->threadCount2      == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation

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
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 32,                             NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 16, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 26,                             NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 22, NgosStatus::ASSERTION);
        }
    }



    const char8 *entryName             = nullptr;
    const char8 *socketDesignation     = "N/A";
    const char8 *processorManufacturer = "N/A";
    const char8 *processorVersion      = "N/A";
    const char8 *serialNumber          = "N/A";
    const char8 *assetTag              = "N/A";
    const char8 *partNumber            = "N/A";

    // Get strings
    {
        DmiStringId serialNumberStringId;
        DmiStringId assetTagStringId;
        DmiStringId partNumberStringId;

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            serialNumberStringId = entry->serialNumber;
            assetTagStringId     = entry->assetTag;
            partNumberStringId   = entry->partNumber;
        }



        if (
            entry->socketDesignation.id
            ||
            entry->processorManufacturer.id
            ||
            entry->processorVersion.id
            ||
            serialNumberStringId.id
            ||
            assetTagStringId.id
            ||
            partNumberStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->socketDesignation)
                    {
                        socketDesignation = begin;
                    }
                    else
                    if (stringId == entry->processorManufacturer)
                    {
                        processorManufacturer = begin;
                    }
                    else
                    if (stringId == entry->processorVersion)
                    {
                        processorVersion = begin;
                        entryName        = processorVersion;
                    }
                    else
                    if (stringId == serialNumberStringId)
                    {
                        serialNumber = begin;
                    }
                    else
                    if (stringId == assetTagStringId)
                    {
                        assetTag = begin;
                    }
                    else
                    if (stringId == partNumberStringId)
                    {
                        partNumber = begin;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *l1CacheHandle        = "N/A";
    const char8 *l2CacheHandle        = "N/A";
    const char8 *l3CacheHandle        = "N/A";
    const char8 *coreCountReal        = "N/A";
    const char8 *enabledCoreCountReal = "N/A";
    const char8 *threadCountReal      = "N/A";
    const char8 *coreCount            = "N/A";
    const char8 *enabledCoreCount     = "N/A";
    const char8 *threadCount          = "N/A";
    const char8 *processorFamily2     = "N/A";
    const char8 *coreCount2           = "N/A";
    const char8 *enabledCoreCount2    = "N/A";
    const char8 *threadCount2         = "N/A";

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // Get string for L1 cache handle
            {
                if (entry->l1CacheHandle != DMI_PROCESSOR_L1_CACHE_HANDLE_NOT_AVAILABLE)
                {
                    l1CacheHandle = mprintf("0x%04X", entry->l1CacheHandle);
                }
            }



            // Get string for L2 cache handle
            {
                if (entry->l2CacheHandle != DMI_PROCESSOR_L2_CACHE_HANDLE_NOT_AVAILABLE)
                {
                    l2CacheHandle = mprintf("0x%04X", entry->l2CacheHandle);
                }
            }



            // Get string for L3 cache handle
            {
                if (entry->l3CacheHandle != DMI_PROCESSOR_L3_CACHE_HANDLE_NOT_AVAILABLE)
                {
                    l3CacheHandle = mprintf("0x%04X", entry->l3CacheHandle);
                }
            }



            if (DMI::getVersion() >= DMI_VERSION(2, 5))
            {
                // Get string for Core count
                {
                    if (entry->coreCount == DMI_PROCESSOR_CORE_COUNT_UNKNOWN)
                    {
                        coreCountReal = "Unknown";
                    }
                    else
                    if (
                        entry->coreCount == DMI_PROCESSOR_CORE_COUNT_NEED_TO_EXTEND
                        &&
                        DMI::getVersion() >= DMI_VERSION(3, 0)
                       )
                    {
                        coreCountReal = mprintf("%u", entry->coreCount2);
                    }
                    else
                    {
                        coreCountReal = mprintf("%u", entry->coreCount);
                    }



                    coreCount = mprintf("0x%02X", entry->coreCount);
                }



                // Get string for Enabled core count
                {
                    if (entry->enabledCoreCount == DMI_PROCESSOR_ENABLED_CORE_COUNT_UNKNOWN)
                    {
                        enabledCoreCountReal = "Unknown";
                    }
                    else
                    if (
                        entry->enabledCoreCount == DMI_PROCESSOR_ENABLED_CORE_COUNT_NEED_TO_EXTEND
                        &&
                        DMI::getVersion() >= DMI_VERSION(3, 0)
                       )
                    {
                        enabledCoreCountReal = mprintf("%u", entry->enabledCoreCount2);
                    }
                    else
                    {
                        enabledCoreCountReal = mprintf("%u", entry->enabledCoreCount);
                    }



                    enabledCoreCount = mprintf("0x%02X", entry->enabledCoreCount);
                }



                // Get string for Thread count
                {
                    if (entry->threadCount == DMI_PROCESSOR_THREAD_COUNT_UNKNOWN)
                    {
                        threadCountReal = "Unknown";
                    }
                    else
                    if (
                        entry->threadCount == DMI_PROCESSOR_THREAD_COUNT_NEED_TO_EXTEND
                        &&
                        DMI::getVersion() >= DMI_VERSION(3, 0)
                       )
                    {
                        threadCountReal = mprintf("%u", entry->threadCount2);
                    }
                    else
                    {
                        threadCountReal = mprintf("%u", entry->threadCount);
                    }



                    threadCount = mprintf("0x%02X", entry->threadCount);
                }



                if (DMI::getVersion() >= DMI_VERSION(2, 6))
                {
                    processorFamily2 = mprintf("0x%04X", entry->processorFamily2);

                    if (DMI::getVersion() >= DMI_VERSION(3, 0))
                    {
                        coreCount2        = mprintf("0x%04X", entry->coreCount2);
                        enabledCoreCount2 = mprintf("0x%04X", entry->enabledCoreCount2);
                        threadCount2      = mprintf("0x%04X", entry->threadCount2);
                    }
                }
            }
        }
    }



    const char8 *processorFamily;
    const char8 *externalClock;
    const char8 *maxSpeed;
    const char8 *currentSpeed;

    // Get other strings
    {
        // Get string for Family
        {
            if (
                entry->processorFamily == DmiProcessorFamily::INDICATOR_FAMILY_2
                &&
                DMI::getVersion() >= DMI_VERSION(2, 6)
               )
            {
                processorFamily = strdup(enumToString(entry->processorFamily2));
            }
            else
            {
                processorFamily = strdup(enumToString(entry->processorFamily));
            }
        }



        // Get string for External clock
        {
            if (entry->externalClock == DMI_PROCESSOR_EXTERNAL_CLOCK_UNKNOWN)
            {
                externalClock = "Unknown";
            }
            else
            {
                externalClock = mprintf("%u MHz", entry->externalClock);
            }
        }



        // Get string for Maximum speed
        {
            if (entry->maxSpeed == DMI_PROCESSOR_MAX_SPEED_UNKNOWN)
            {
                maxSpeed = "Unknown";
            }
            else
            {
                maxSpeed = mprintf("%u MHz", entry->maxSpeed);
            }
        }



        // Get string for Current speed
        {
            if (entry->currentSpeed == DMI_PROCESSOR_CURRENT_SPEED_UNKNOWN)
            {
                currentSpeed = "Unknown";
            }
            else
            {
                currentSpeed = mprintf("%u MHz", entry->currentSpeed);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",         strdup(enumToFullString(entry->header.type))),               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",             mprintf("0x%04X", entry->header.handle)),                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket designation", socketDesignation),                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Processor type",     strdup(enumToFullString(entry->processorType))),             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",             processorFamily),                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",             mprintf("0x%02X", entry->processorFamily)),                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",       processorManufacturer),                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Stepping",           mprintf("%u", entry->processorId.signature.stepping)),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Model",              mprintf("%u", entry->processorId.signature.model)),          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",             mprintf("%u", entry->processorId.signature.family)),         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",               mprintf("%u", entry->processorId.signature.type)),           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended model",     mprintf("%u", entry->processorId.signature.extendedModel)),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended family",    mprintf("%u", entry->processorId.signature.extendedFamily)), NgosStatus::ASSERTION);



        // Add records for Features
        {
            // Commented to avoid too many records
            // ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Features", entry->processorId.featureFlags, "0x%08X", DmiProcessorFeatureFlag);
            // Use record below instead:
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Features", mprintf("0x%08X", entry->processorId.featureFlags.flags)), NgosStatus::ASSERTION);
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version", processorVersion), NgosStatus::ASSERTION);



        // Add records for Voltage
        {
            switch ((DmiProcessorVoltageModeType)entry->voltage.modeType)
            {
                case DmiProcessorVoltageModeType::LEGACY_MODE:
                {
                    ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Voltage", entry->voltage, "0x%02X", DmiProcessorVoltageFlag);
                }
                break;

                case DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE:
                {
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Voltage", mprintf("%u.%u V", entry->voltage.value / 10, entry->voltage.value % 10)), NgosStatus::ASSERTION);
                }
                break;

                default:
                {
                    UEFI_LF(("Unknown DMI processor voltage mode type %s, %s:%u", enumToFullString((DmiProcessorVoltageModeType)entry->voltage.modeType), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External clock",     externalClock),                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum speed",      maxSpeed),                                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current speed",      currentSpeed),                                                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",             strdup(enumToFullString((DmiProcessorStatus)entry->status))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket populated",   entry->socketPopulated ? "Yes" : "No"),                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upgrade",            strdup(enumToFullString(entry->processorUpgrade))),           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L1 cache handle",    l1CacheHandle),                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L2 cache handle",    l2CacheHandle),                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L3 cache handle",    l3CacheHandle),                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",      serialNumber),                                                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",          assetTag),                                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Part number",        partNumber),                                                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count",         coreCountReal),                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count", enabledCoreCountReal),                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count",       threadCountReal),                                             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count",         coreCount),                                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count", enabledCoreCount),                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count",       threadCount),                                                 NgosStatus::ASSERTION);



        // Add records for Characteristics
        {
            if (DMI::getVersion() >= DMI_VERSION(2, 5))
            {
                ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics", entry->processorCharacteristics, "0x%04X", DmiProcessorCharacteristicsFlag);
            }
            else
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics", "N/A"), NgosStatus::ASSERTION);
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family 2",             processorFamily2),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count 2",         coreCount2),        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count 2", enabledCoreCount2), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count 2",       threadCount2),      NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiCacheEntry(DmiCacheEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->socketDesignation.id               = %u",     entry->socketDesignation.id));
        UEFI_LVVV(("entry->cacheConfiguration.level           = %u",     entry->cacheConfiguration.level));
        UEFI_LVVV(("entry->cacheConfiguration.socketed        = %u",     entry->cacheConfiguration.socketed));
        UEFI_LVVV(("entry->cacheConfiguration.location        = %s",     enumToFullString((DmiCacheLocation)entry->cacheConfiguration.location)));
        UEFI_LVVV(("entry->cacheConfiguration.enabled         = %u",     entry->cacheConfiguration.enabled));
        UEFI_LVVV(("entry->cacheConfiguration.operationalMode = %s",     enumToFullString((DmiCacheOperationalMode)entry->cacheConfiguration.operationalMode)));
        UEFI_LVVV(("entry->cacheConfiguration.value16         = 0x%04X", entry->cacheConfiguration.value16));
        UEFI_LVVV(("entry->maximumCacheSize.value             = %u",     entry->maximumCacheSize.value));
        UEFI_LVVV(("entry->maximumCacheSize.granularity       = %s",     enumToFullString((DmiCacheSizeGranularity)entry->maximumCacheSize.granularity)));
        UEFI_LVVV(("entry->maximumCacheSize.value16           = 0x%04X", entry->maximumCacheSize.value16));
        UEFI_LVVV(("entry->maximumCacheSize                   = %s",     bytesToString(entry->maximumCacheSize.size())));
        UEFI_LVVV(("entry->installedSize.value                = %u",     entry->installedSize.value));
        UEFI_LVVV(("entry->installedSize.granularity          = %s",     enumToFullString((DmiCacheSizeGranularity)entry->installedSize.granularity)));
        UEFI_LVVV(("entry->installedSize.value16              = 0x%04X", entry->installedSize.value16));
        UEFI_LVVV(("entry->installedSize                      = %s",     bytesToString(entry->installedSize.size())));
        UEFI_LVVV(("entry->supportedSramType                  = %s",     flagsToFullString(entry->supportedSramType)));
        UEFI_LVVV(("entry->currentSramType                    = %s",     flagsToFullString(entry->currentSramType)));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            UEFI_LVVV(("entry->cacheSpeed          = %u", entry->cacheSpeed));
            UEFI_LVVV(("entry->errorCorrectionType = %s", enumToFullString(entry->errorCorrectionType)));
            UEFI_LVVV(("entry->systemCacheType     = %s", enumToFullString(entry->systemCacheType)));
            UEFI_LVVV(("entry->associativity       = %s", enumToFullString(entry->associativity)));

            if (DMI::getVersion() >= DMI_VERSION(3, 1))
            {
                UEFI_LVVV(("entry->maximumCacheSize2.value       = %u",     entry->maximumCacheSize2.value));
                UEFI_LVVV(("entry->maximumCacheSize2.granularity = %s",     enumToFullString((DmiCacheSizeGranularity)entry->maximumCacheSize2.granularity)));
                UEFI_LVVV(("entry->maximumCacheSize2.value32     = 0x%08X", entry->maximumCacheSize2.value32));
                UEFI_LVVV(("entry->maximumCacheSize2             = %s",     bytesToString(entry->maximumCacheSize2.size())));
                UEFI_LVVV(("entry->installedSize2.value          = %u",     entry->installedSize2.value));
                UEFI_LVVV(("entry->installedSize2.granularity    = %s",     enumToFullString((DmiCacheSizeGranularity)entry->installedSize2.granularity)));
                UEFI_LVVV(("entry->installedSize2.value32        = 0x%08X", entry->installedSize2.value32));
                UEFI_LVVV(("entry->installedSize2                = %s",     bytesToString(entry->installedSize2.size())));
            }
        }



        // UEFI_TEST_ASSERT(entry->socketDesignation.id               == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.level           == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.socketed        == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.location        == DmiCacheLocation::UNKNOWN,                      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.enabled         == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.operationalMode == DmiCacheOperationalMode::UNKNOWN,               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->cacheConfiguration.value16         == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumCacheSize.value             == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumCacheSize.granularity       == DmiCacheSizeGranularity::_1_KILOBYTE,           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumCacheSize.value16           == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->installedSize.value                == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->installedSize.granularity          == DmiCacheSizeGranularity::_1_KILOBYTE,           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->installedSize.value16              == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->supportedSramType                  == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->currentSramType                    == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // UEFI_TEST_ASSERT(entry->cacheSpeed          == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->errorCorrectionType == DmiCacheErrorCorrectionType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->systemCacheType     == DmiCacheType::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->associativity       == DmiCacheAssociativity::OTHER,       NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(3, 1))
            {
                // UEFI_TEST_ASSERT(entry->maximumCacheSize2.value       == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->maximumCacheSize2.granularity == DmiCacheSizeGranularity::_1_KILOBYTE, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->maximumCacheSize2.value32     == 0x00000000,                           NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->installedSize2.value          == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->installedSize2.granularity    == DmiCacheSizeGranularity::_1_KILOBYTE, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->installedSize2.value32        == 0x00000000,                           NgosStatus::ASSERTION); // Commented due to value variation

                UEFI_TEST_ASSERT(entry->header.length >= 27,                    NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry), NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 19,                        NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry) - 8, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 15,                         NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry) - 12, NgosStatus::ASSERTION);
        }
    }



    const char8 *entryName         = nullptr;
    const char8 *socketDesignation = "N/A";

    // Get strings
    {
        if (entry->socketDesignation.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->socketDesignation)
                    {
                        socketDesignation = begin;
                        entryName         = socketDesignation;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *cacheSpeed          = "N/A";
    const char8 *errorCorrectionType = "N/A";
    const char8 *systemCacheType     = "N/A";
    const char8 *associativity       = "N/A";
    const char8 *maximumCacheSize2   = "N/A";
    const char8 *installedSize2      = "N/A";

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // Get string for Speed
            {
                if (entry->cacheSpeed == DMI_CACHE_CACHE_SPEED_UNKNOWN)
                {
                    cacheSpeed = "Unknown";
                }
                else
                {
                    cacheSpeed = mprintf("%u ns", entry->cacheSpeed);
                }
            }



            errorCorrectionType = strdup(enumToFullString(entry->errorCorrectionType));
            systemCacheType     = strdup(enumToFullString(entry->systemCacheType));
            associativity       = strdup(enumToFullString(entry->associativity));

            if (DMI::getVersion() >= DMI_VERSION(3, 1))
            {
                maximumCacheSize2 = mprintf("0x%08X", entry->maximumCacheSize2.value32);
                installedSize2    = mprintf("0x%08X", entry->installedSize2.value32);
            }
        }
    }



    const char8 *maximumCacheSize;
    const char8 *installedSize;

    // Get other strings
    {
        // Get string for Maximum cache size
        {
            if (
                entry->maximumCacheSize.value16 == DMI_CACHE_MAXIMUM_CACHE_SIZE_NEED_TO_EXTEND
                &&
                DMI::getVersion() >= DMI_VERSION(3, 1)
               )
            {
                maximumCacheSize = strdup(bytesToString(entry->maximumCacheSize2.size()));
            }
            else
            {
                maximumCacheSize = strdup(bytesToString(entry->maximumCacheSize.size()));
            }
        }



        // Get string for Installed size
        {
            if (entry->installedSize.value16 == DMI_CACHE_INSTALLED_SIZE_NO_CACHE)
            {
                installedSize = "No cache";
            }
            else
            if (
                entry->installedSize.value16 == DMI_CACHE_INSTALLED_SIZE_NEED_TO_EXTEND
                &&
                DMI::getVersion() >= DMI_VERSION(3, 1)
               )
            {
                installedSize = strdup(bytesToString(entry->installedSize2.size()));
            }
            else
            {
                installedSize = strdup(bytesToString(entry->installedSize.size()));
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",         strdup(enumToFullString(entry->header.type))),                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",             mprintf("0x%04X", entry->header.handle)),                                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket designation", socketDesignation),                                                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Level",              mprintf("%u", entry->cacheConfiguration.levelReal())),                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socketed",           entry->cacheConfiguration.socketed ? "Yes" : "No"),                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",           strdup(enumToFullString((DmiCacheLocation)entry->cacheConfiguration.location))),               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",            entry->cacheConfiguration.enabled ? "Yes" : "No"),                                             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Operational mode",   strdup(enumToFullString((DmiCacheOperationalMode)entry->cacheConfiguration.operationalMode))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum cache size", maximumCacheSize),                                                                             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installed size",     installedSize),                                                                                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum cache size", mprintf("0x%04X", entry->maximumCacheSize.value16)),                                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installed size",     mprintf("0x%04X", entry->installedSize.value16)),                                              NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Supported SRAM type", entry->supportedSramType, "0x%04X", DmiCacheSramTypeFlag);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Current SRAM type",   entry->currentSramType,   "0x%04X", DmiCacheSramTypeFlag);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Speed",                 cacheSpeed),          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error correction type", errorCorrectionType), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System cache type",     systemCacheType),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Associativity",         associativity),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum cache size 2",  maximumCacheSize2),   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installed size 2",      installedSize2),      NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPortConnectorEntry(DmiPortConnectorEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->internalReferenceDesignator.id = %u", entry->internalReferenceDesignator.id));
        UEFI_LVVV(("entry->internalConnectorType          = %s", enumToFullString(entry->internalConnectorType)));
        UEFI_LVVV(("entry->externalReferenceDesignator.id = %u", entry->externalReferenceDesignator.id));
        UEFI_LVVV(("entry->externalConnectorType          = %s", enumToFullString(entry->externalConnectorType)));
        UEFI_LVVV(("entry->portType                       = %s", enumToFullString(entry->portType)));



        // UEFI_TEST_ASSERT(entry->internalReferenceDesignator.id == 1,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->internalConnectorType          == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->externalReferenceDesignator.id == 2,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->externalConnectorType          == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->portType                       == DmiPortConnectorPortType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 9,                             NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPortConnectorEntry), NgosStatus::ASSERTION);
    }



    const char8 *entryName                   = nullptr;
    const char8 *internalReferenceDesignator = "N/A";
    const char8 *externalReferenceDesignator = "N/A";

    // Get strings
    {
        if (
            entry->internalReferenceDesignator.id
            ||
            entry->externalReferenceDesignator.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->internalReferenceDesignator)
                    {
                        internalReferenceDesignator = begin;
                        entryName                   = internalReferenceDesignator;
                    }
                    else
                    if (stringId == entry->externalReferenceDesignator)
                    {
                        externalReferenceDesignator = begin;
                        entryName                   = externalReferenceDesignator;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntry(entry, entryName), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                    strdup(enumToFullString(entry->header.type))),           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                        mprintf("0x%04X", entry->header.handle)),                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Internal reference designator", internalReferenceDesignator),                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Internal connector type",       strdup(enumToFullString(entry->internalConnectorType))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External reference designator", externalReferenceDesignator),                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External connector type",       strdup(enumToFullString(entry->externalConnectorType))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port type",                     strdup(enumToFullString(entry->portType))),              NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemSlotsEntry(DmiSystemSlotsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->slotDesignation.id  = %u",     entry->slotDesignation.id));
        UEFI_LVVV(("entry->slotType            = %s",     enumToFullString(entry->slotType)));
        UEFI_LVVV(("entry->slotDataBusWidth    = %s",     enumToFullString(entry->slotDataBusWidth)));
        UEFI_LVVV(("entry->currentUsage        = %s",     enumToFullString(entry->currentUsage)));
        UEFI_LVVV(("entry->slotLength          = %s",     enumToFullString(entry->slotLength)));
        UEFI_LVVV(("entry->slotID              = 0x%04X", entry->slotID));
        UEFI_LVVV(("entry->slotCharacteristics = %s",     flagsToFullString(entry->slotCharacteristics)));

        if (DMI::getVersion() >= DMI_VERSION(2, 6))
        {
            UEFI_LVVV(("entry->segmentGroupNumber            = %u",     entry->segmentGroupNumber));
            UEFI_LVVV(("entry->busNumber                     = %u",     entry->busNumber));
            UEFI_LVVV(("entry->functionNumber                = %u",     entry->functionNumber));
            UEFI_LVVV(("entry->deviceNumber                  = %u",     entry->deviceNumber));
            UEFI_LVVV(("entry->functionNumberAndDeviceNumber = 0x%02X", entry->functionNumberAndDeviceNumber));

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                UEFI_LVVV(("entry->dataBusWidth      = %u", entry->dataBusWidth));
                UEFI_LVVV(("entry->peerGroupingCount = %u", entry->peerGroupingCount));



                // entry->peerGroups:
                {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                    UEFI_LVVV(("entry->peerGroups:"));
                    UEFI_LVVV(("-------------------------------------"));

                    for (i64 i = 0; i < entry->peerGroupingCount; ++i)
                    {
                        UEFI_LVVV(("entry->peerGroups[%d].segmentGroupNumber            = %u",     i, entry->peerGroups[i].segmentGroupNumber));
                        UEFI_LVVV(("entry->peerGroups[%d].busNumber                     = %u",     i, entry->peerGroups[i].busNumber));
                        UEFI_LVVV(("entry->peerGroups[%d].functionNumber                = %u",     i, entry->peerGroups[i].functionNumber));
                        UEFI_LVVV(("entry->peerGroups[%d].deviceNumber                  = %u",     i, entry->peerGroups[i].deviceNumber));
                        UEFI_LVVV(("entry->peerGroups[%d].functionNumberAndDeviceNumber = 0x%02X", i, entry->peerGroups[i].functionNumberAndDeviceNumber));
                        UEFI_LVVV(("entry->peerGroups[%d].dataBusWidth                  = %u",     i, entry->peerGroups[i].dataBusWidth));
                    }

                    UEFI_LVVV(("-------------------------------------"));
#endif
                }
            }
        }



        // UEFI_TEST_ASSERT(entry->slotDesignation.id  == 1,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotType            == DmiSystemSlotsType::UNKNOWN,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotDataBusWidth    == DmiSystemSlotsDataBusWidth::UNKNOWN,            NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->currentUsage        == DmiSystemSlotsUsage::AVAILABLE,                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotLength          == DmiSystemSlotsLength::UNKNOWN,                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotID              == 0x0001,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->slotCharacteristics == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 6))
        {
            // UEFI_TEST_ASSERT(entry->segmentGroupNumber            == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->busNumber                     == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->functionNumber                == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceNumber                  == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->functionNumberAndDeviceNumber == 0x00, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                // UEFI_TEST_ASSERT(entry->dataBusWidth                                == 0,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroupingCount                           == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].segmentGroupNumber            == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].busNumber                     == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].functionNumber                == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].deviceNumber                  == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].functionNumberAndDeviceNumber == 0x00, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->peerGroups[0].dataBusWidth                  == 0,    NgosStatus::ASSERTION); // Commented due to value variation

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



    const char8 *entryName       = nullptr;
    const char8 *slotDesignation = "N/A";

    // Get strings
    {
        if (entry->slotDesignation.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->slotDesignation)
                    {
                        slotDesignation = begin;
                        entryName       = slotDesignation;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *segmentGroupNumber = "N/A";
    const char8 *busNumber          = "N/A";
    const char8 *functionNumber     = "N/A";
    const char8 *deviceNumber       = "N/A";
    const char8 *dataBusWidth       = "N/A";
    const char8 *peerGroupingCount  = "N/A";

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 6))
        {
            segmentGroupNumber = mprintf("%u", entry->segmentGroupNumber);
            busNumber          = mprintf("%u", entry->busNumber);
            functionNumber     = mprintf("%u", entry->functionNumber);
            deviceNumber       = mprintf("%u", entry->deviceNumber);

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                dataBusWidth      = mprintf("%u", entry->dataBusWidth);
                peerGroupingCount = mprintf("%u", entry->peerGroupingCount);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntry(entry, entryName), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",     strdup(enumToFullString(entry->header.type))),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",         mprintf("0x%04X", entry->header.handle)),           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Designation",    slotDesignation),                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",           strdup(enumToFullString(entry->slotType))),         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data bus width", strdup(enumToFullString(entry->slotDataBusWidth))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current usage",  strdup(enumToFullString(entry->currentUsage))),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Length",         strdup(enumToFullString(entry->slotLength))),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("ID",             mprintf("0x%04X", entry->slotID)),                  NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics", entry->slotCharacteristics, "0x%04X", DmiSystemSlotsCharacteristicsFlag);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment group number", segmentGroupNumber), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus number",           busNumber),          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Function number",      functionNumber),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device number",        deviceNumber),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data bus width",       dataBusWidth),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Peer grouping count",  peerGroupingCount),  NgosStatus::ASSERTION);



        // Add records for Peer groups
        {
            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                for (i64 i = 0; i < entry->peerGroupingCount; ++i)
                {
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d segment group number", i), mprintf("%u", entry->peerGroups[i].segmentGroupNumber)), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d bus number",           i), mprintf("%u", entry->peerGroups[i].busNumber)),          NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d function number",      i), mprintf("%u", entry->peerGroups[i].functionNumber)),     NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d device number",        i), mprintf("%u", entry->peerGroups[i].deviceNumber)),       NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d data bus width",       i), mprintf("%u", entry->peerGroups[i].dataBusWidth)),       NgosStatus::ASSERTION);
                }
            }
        }



        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiOnboardDevicesEntry(DmiOnboardDevicesEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    u8 count = (entry->header.length - sizeof(entry->header)) / sizeof(entry->devices[0]);

    // Validation
    {
        UEFI_LVVV(("count = %u", count));

        // entry->devices:
        {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            UEFI_LVVV(("entry->devices:"));
            UEFI_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < count; ++i)
            {
                UEFI_LVVV(("entry->devices[%d].deviceType           = %s",     i, enumToFullString((DmiOnboardDevicesDeviceType)entry->devices[i].deviceType)));
                UEFI_LVVV(("entry->devices[%d].enabled              = %u",     i, entry->devices[i].enabled));
                UEFI_LVVV(("entry->devices[%d].deviceTypeAndEnabled = 0x%02X", i, entry->devices[i].deviceTypeAndEnabled));
                UEFI_LVVV(("entry->devices[%d].description.id       = %u",     i, entry->devices[i].description.id));
            }

            UEFI_LVVV(("-------------------------------------"));
#endif
        }



        UEFI_TEST_ASSERT(count                                                        >  0,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT((DmiOnboardDevicesDeviceType)entry->devices[0].deviceType == DmiOnboardDevicesDeviceType::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->devices[0].enabled                                 == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->devices[0].deviceTypeAndEnabled                    == 0x00,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->devices[0].description.id                          == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 6,                                                                NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesEntry) + sizeof(DmiOnboardDevicesDevice), NgosStatus::ASSERTION);
    }



    ArrayList<DeviceManagerEntryDMI *> onboardDevices;

    // Add Device Manager entries
    {
        for (i64 i = 0; i < count; ++i)
        {
            DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiOnboardDevice(&entry->devices[i]), enumToHumanString(entry->header.type));

            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",  strdup(enumToFullString(entry->header.type))),                                        NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",      mprintf("0x%04X", entry->header.handle)),                                             NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type", strdup(enumToFullString((DmiOnboardDevicesDeviceType)entry->devices[i].deviceType))), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",     entry->devices[i].enabled ? "Yes" : "No"),                                            NgosStatus::ASSERTION);

            UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry),       NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(onboardDevices.append(deviceManagerEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            count > 0
            &&
            entry->devices[0].description.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    for (i64 i = 0; i < count; ++i)
                    {
                        if (stringId == entry->devices[i].description)
                        {
                            UEFI_ASSERT_EXECUTION(onboardDevices.at(i)->setName(begin),                  NgosStatus::ASSERTION);
                            UEFI_ASSERT_EXECUTION(onboardDevices.at(i)->addRecord("Description", begin), NgosStatus::ASSERTION);

                            break;
                        }
                    }



                    if (cur[1] == 0)
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
    }



    // Add description for entries without decription
    {
        for (i64 i = 0; i < count; ++i)
        {
            DeviceManagerEntryDMI *deviceManagerEntry = onboardDevices.at(i);

            if (deviceManagerEntry->getRecords().getSize() < 5)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description", "N/A"), NgosStatus::ASSERTION);
            }
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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type", strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",     mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (entry->stringCount > 0)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM string", begin), NgosStatus::ASSERTION);



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);



            UEFI_TEST_ASSERT(stringId.id == entry->stringCount, NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type", strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",     mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (entry->stringCount > 0)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System configuration option", begin), NgosStatus::ASSERTION);



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);



            UEFI_TEST_ASSERT(stringId.id == entry->stringCount, NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBiosLanguageEntry(DmiBiosLanguageEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->installableLanguages = %u", entry->installableLanguages));
        UEFI_LVVV(("entry->flags                = %s", flagsToFullString(entry->flags)));
        UEFI_LVVV(("entry->currentLanguage.id   = %u", entry->currentLanguage.id));



        // UEFI_TEST_ASSERT(entry->installableLanguages == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->flags                == FLAGS(DmiBiosLanguageFlags::NONE), NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->currentLanguage.id   == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosLanguageEntry), NgosStatus::ASSERTION);
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",            strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installable languages", mprintf("%u", entry->installableLanguages)),   NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Flags", entry->flags, "0x%02X", DmiBiosLanguageFlag);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current language ID", mprintf("%u", entry->currentLanguage.id)), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (
            entry->installableLanguages
            ||
            entry->currentLanguage.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Language #%u", stringId.id), begin),NgosStatus::ASSERTION);



                    if (cur[1] == 0)
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
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiGroupAssociationsEntry(DmiGroupAssociationsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    u8 count = (entry->header.length - sizeof(entry->header) - sizeof(entry->groupName)) / sizeof(entry->items[0]);

    // Validation
    {
        UEFI_LVVV(("entry->groupName.id = %u", entry->groupName.id));
        UEFI_LVVV(("count               = %u", count));

        // entry->items:
        {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            UEFI_LVVV(("entry->items:"));
            UEFI_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < count; ++i)
            {
                UEFI_LVVV(("entry->items[%d].type   = %s",     i, enumToFullString(entry->items[i].type)));
                UEFI_LVVV(("entry->items[%d].handle = 0x%04X", i, entry->items[i].handle));
            }

            UEFI_LVVV(("-------------------------------------"));
#endif
        }



        // UEFI_TEST_ASSERT(entry->groupName.id    == 1,                  NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(count                     >  0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->items[0].type   == DmiEntryType::BIOS, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->items[0].handle == 0x0000,             NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 8,                                                                    NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiGroupAssociationsEntry) + sizeof(DmiGroupAssociationsItem), NgosStatus::ASSERTION);
    }



    const char8 *entryName = nullptr;
    const char8 *groupName = "N/A";

    // Get strings
    {
        if (entry->groupName.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->groupName)
                    {
                        groupName = begin;
                        entryName = groupName;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type", strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",     mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Name",       groupName),                                    NgosStatus::ASSERTION);



        // Add records for Items
        {
            for (i64 i = 0; i < count; ++i)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Item #%d type", i),   strdup(enumToFullString(entry->items[i].type))), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Item #%d handle", i), mprintf("0x%04X", entry->items[i].handle)),      NgosStatus::ASSERTION);
            }
        }



        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPhysicalMemoryArrayEntry(DmiPhysicalMemoryArrayEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        UEFI_LVVV(("entry->location                     = %s",     enumToFullString(entry->location)));
        UEFI_LVVV(("entry->use                          = %s",     enumToFullString(entry->use)));
        UEFI_LVVV(("entry->memoryErrorCorrection        = %s",     enumToFullString(entry->memoryErrorCorrection)));
        UEFI_LVVV(("entry->maximumCapacity.value        = 0x%08X", entry->maximumCapacity.value));
        UEFI_LVVV(("entry->maximumCapacity              = %s",     bytesToString(entry->maximumCapacity.size())));
        UEFI_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
        UEFI_LVVV(("entry->numberOfMemoryDevices        = %u",     entry->numberOfMemoryDevices));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->extendedMaximumCapacity = 0x%016lX", entry->extendedMaximumCapacity));
        }



        // UEFI_TEST_ASSERT(entry->location                     == DmiPhysicalMemoryArrayLocation::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->use                          == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY,             NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryErrorCorrection        == DmiPhysicalMemoryArrayErrorCorrection::MULTI_BIT_ECC, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumCapacity.value        == 0x00100000,                                           NgosStatus::ASSERTION); // Commented due to value variation
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

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            extendedMaximumCapacity = mprintf("0x%016lX", entry->extendedMaximumCapacity);
        }
    }



    const char8 *maximumCapacity;
    const char8 *memoryErrorInformationHandle;

    // Get other strings
    {
        // Get string for Maximum capacity
        {
            if (
                entry->maximumCapacity.value == DMI_PHYSICAL_MEMORY_ARRAY_MAXIMUM_CAPACITY_NEED_TO_EXTEND
                &&
                DMI::getVersion() >= DMI_VERSION(2, 7)
               )
            {
                maximumCapacity = strdup(bytesToString(entry->extendedMaximumCapacity));
            }
            else
            {
                maximumCapacity = strdup(bytesToString(entry->maximumCapacity.size()));
            }
        }



        // Get string for Memory error information handle
        {
            if (entry->memoryErrorInformationHandle == DMI_PHYSICAL_MEMORY_ARRAY_MEMORY_ERROR_INFORMATION_HANDLE_NOT_AVAILABLE)
            {
                memoryErrorInformationHandle = "N/A";
            }
            else
            if (entry->memoryErrorInformationHandle == DMI_PHYSICAL_MEMORY_ARRAY_MEMORY_ERROR_INFORMATION_HANDLE_NO_ERROR)
            {
                memoryErrorInformationHandle = "No error";
            }
            else
            {
                memoryErrorInformationHandle = mprintf("0x%04X", entry->memoryErrorInformationHandle);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                      strdup(enumToFullString(entry->header.type))),           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle)),                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                        strdup(enumToFullString(entry->location))),              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Use",                             strdup(enumToFullString(entry->use))),                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error correction",         strdup(enumToFullString(entry->memoryErrorCorrection))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum capacity",                maximumCapacity),                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum capacity",                mprintf("0x%08X", entry->maximumCapacity.value)),        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error information handle", memoryErrorInformationHandle),                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of memory devices",        mprintf("%u", entry->numberOfMemoryDevices)),            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended maximum capacity",       extendedMaximumCapacity),                                NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



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
        UEFI_LVVV(("entry->size.value                   = %u",     entry->size.value));
        UEFI_LVVV(("entry->size.granularity             = %s",     enumToFullString((DmiMemoryDeviceSizeGranularity)entry->size.granularity)));
        UEFI_LVVV(("entry->size.value16                 = 0x%04X", entry->size.value16));
        UEFI_LVVV(("entry->size                         = %s",     bytesToString(entry->size.size())));
        UEFI_LVVV(("entry->formFactor                   = %s",     enumToFullString(entry->formFactor)));
        UEFI_LVVV(("entry->deviceSet                    = %u",     entry->deviceSet));
        UEFI_LVVV(("entry->deviceLocator.id             = %u",     entry->deviceLocator.id));
        UEFI_LVVV(("entry->bankLocator.id               = %u",     entry->bankLocator.id));
        UEFI_LVVV(("entry->memoryType                   = %s",     enumToFullString(entry->memoryType)));
        UEFI_LVVV(("entry->typeDetail                   = %s",     flagsToFullString(entry->typeDetail)));

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            UEFI_LVVV(("entry->speed           = %u", entry->speed));
            UEFI_LVVV(("entry->manufacturer.id = %u", entry->manufacturer.id));
            UEFI_LVVV(("entry->serialNumber.id = %u", entry->serialNumber.id));
            UEFI_LVVV(("entry->assetTag.id     = %u", entry->assetTag.id));
            UEFI_LVVV(("entry->partNumber.id   = %u", entry->partNumber.id));

            if (DMI::getVersion() >= DMI_VERSION(2, 6))
            {
                UEFI_LVVV(("entry->attributes.rank   = %u",     entry->attributes.rank));
                UEFI_LVVV(("entry->attributes.value8 = 0x%02X", entry->attributes.value8));

                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    UEFI_LVVV(("entry->extendedSize.value    = %u",     entry->extendedSize.value));
                    UEFI_LVVV(("entry->extendedSize.value32  = 0x%08X", entry->extendedSize.value32));
                    UEFI_LVVV(("entry->extendedSize          = %s",     bytesToString(entry->extendedSize.size())));
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
                            UEFI_LVVV(("entry->firmwareVersion.id                      = %u", entry->firmwareVersion.id));
                            UEFI_LVVV(("entry->moduleManufacturerID                    = %u", entry->moduleManufacturerID));
                            UEFI_LVVV(("entry->moduleProductID                         = %u", entry->moduleProductID));
                            UEFI_LVVV(("entry->memorySubsystemControllerManufacturerID = %u", entry->memorySubsystemControllerManufacturerID));
                            UEFI_LVVV(("entry->memorySubsystemControllerProductID      = %u", entry->memorySubsystemControllerProductID));
                            UEFI_LVVV(("entry->nonVolatileSize                         = %u", entry->nonVolatileSize));
                            UEFI_LVVV(("entry->volatileSize                            = %u", entry->volatileSize));
                            UEFI_LVVV(("entry->cacheSize                               = %u", entry->cacheSize));
                            UEFI_LVVV(("entry->logicalSize                             = %u", entry->logicalSize));

                            if (DMI::getVersion() >= DMI_VERSION(3, 3))
                            {
                                UEFI_LVVV(("entry->extendedSpeed                 = %u", entry->extendedSpeed));
                                UEFI_LVVV(("entry->extendedConfiguredMemorySpeed = %u", entry->extendedConfiguredMemorySpeed));
                            }
                        }
                    }
                }
            }
        }



        // UEFI_TEST_ASSERT(entry->memoryArrayHandle         == 0x1000,                                      NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                      NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->totalWidth                == 64,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->dataWidth                 == 64,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->size.value                == 1024,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->size.granularity          == DmiMemoryDeviceSizeGranularity::_1_MEGABYTE, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->size.value16              == 0x0400,                                      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->formFactor                == DmiMemoryDeviceFormFactor::DIMM,             NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(entry->deviceSet                    == 0,                                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->deviceLocator.id             == 1,                                           NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(entry->bankLocator.id            == 2,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryType                == DmiMemoryDeviceType::RAM,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->typeDetail                == FLAGS(DmiMemoryDeviceTypeDetailFlag::OTHER), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            // UEFI_TEST_ASSERT(entry->speed           == 2133, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->manufacturer.id == 3,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->serialNumber.id == 4,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->assetTag.id     == 5,    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->partNumber.id   == 6,    NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 6))
            {
                // UEFI_TEST_ASSERT(entry->attributes.rank   == 2,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entry->attributes.value8 == 0x02, NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    // UEFI_TEST_ASSERT(entry->extendedSize.value    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->extendedSize.value32  == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entry->configuredMemorySpeed == 2133,       NgosStatus::ASSERTION); // Commented due to value variation

                    if (DMI::getVersion() >= DMI_VERSION(2, 8))
                    {
                        // UEFI_TEST_ASSERT(entry->minimumVoltage    == 1200, NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entry->maximumVoltage    == 1200, NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entry->configuredVoltage == 1200, NgosStatus::ASSERTION); // Commented due to value variation

                        if (DMI::getVersion() >= DMI_VERSION(3, 2))
                        {
                            UEFI_TEST_ASSERT(entry->memoryTechnology                        == DmiMemoryDeviceTechnology::NONE,                         NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->memoryOperatingModeCapability           == FLAGS(DmiMemoryDeviceOperatingModeCapabilityFlag::NONE), NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->firmwareVersion.id                      == 7,                                                       NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->moduleManufacturerID                    == 0,                                                       NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->moduleProductID                         == 0,                                                       NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->memorySubsystemControllerManufacturerID == 0,                                                       NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->memorySubsystemControllerProductID      == 0,                                                       NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->nonVolatileSize                         == 0,                                                       NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->volatileSize                            == 0,                                                       NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->cacheSize                               == 0,                                                       NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->logicalSize                             == 0,                                                       NgosStatus::ASSERTION);

                            if (DMI::getVersion() >= DMI_VERSION(3, 3))
                            {
                                // UEFI_TEST_ASSERT(entry->extendedSpeed                 == 0, NgosStatus::ASSERTION); // Commented due to value variation
                                // UEFI_TEST_ASSERT(entry->extendedConfiguredMemorySpeed == 0, NgosStatus::ASSERTION); // Commented due to value variation

                                UEFI_TEST_ASSERT(entry->header.length >= 92,                           NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry), NgosStatus::ASSERTION);
                            }
                            else
                            {
                                UEFI_TEST_ASSERT(entry->header.length >= 84,                               NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 8, NgosStatus::ASSERTION);
                            }
                        }
                        else
                        {
                            UEFI_TEST_ASSERT(entry->header.length >= 40,                                NgosStatus::ASSERTION);
                            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 52, NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        UEFI_TEST_ASSERT(entry->header.length >= 34,                                NgosStatus::ASSERTION);
                        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 58, NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= 33,                                NgosStatus::ASSERTION);
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 59, NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= 27,                                NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 65, NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 21,                                NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 71, NgosStatus::ASSERTION);
        }
    }



    const char8 *entryName       = nullptr;
    const char8 *deviceLocator   = "N/A";
    const char8 *bankLocator     = "N/A";
    const char8 *manufacturer    = "N/A";
    const char8 *serialNumber    = "N/A";
    const char8 *assetTag        = "N/A";
    const char8 *partNumber      = "N/A";
    const char8 *firmwareVersion = "N/A";

    // Get strings
    {
        DmiStringId manufacturerStringId;
        DmiStringId serialNumberStringId;
        DmiStringId assetTagStringId;
        DmiStringId partNumberStringId;
        DmiStringId firmwareVersionStringId;

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            manufacturerStringId = entry->manufacturer;
            serialNumberStringId = entry->serialNumber;
            assetTagStringId     = entry->assetTag;
            partNumberStringId   = entry->partNumber;

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                firmwareVersionStringId = entry->firmwareVersion;
            }
        }



        if (
            entry->deviceLocator.id
            ||
            entry->bankLocator.id
            ||
            manufacturerStringId.id
            ||
            serialNumberStringId.id
            ||
            assetTagStringId.id
            ||
            partNumberStringId.id
            ||
            firmwareVersionStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->deviceLocator)
                    {
                        deviceLocator = begin;
                        entryName     = deviceLocator;
                    }
                    else
                    if (stringId == entry->bankLocator)
                    {
                        bankLocator = begin;
                    }
                    else
                    if (stringId == manufacturerStringId)
                    {
                        manufacturer = begin;
                    }
                    else
                    if (stringId == serialNumberStringId)
                    {
                        serialNumber = begin;
                    }
                    else
                    if (stringId == assetTagStringId)
                    {
                        assetTag = begin;
                    }
                    else
                    if (stringId == partNumberStringId)
                    {
                        partNumber = begin;
                    }
                    else
                    if (stringId == firmwareVersionStringId)
                    {
                        firmwareVersion = begin;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *speedReal                               = "N/A";
    const char8 *speed                                   = "N/A";
    const char8 *rank                                    = "N/A";
    const char8 *extendedSize                            = "N/A";
    const char8 *configuredMemorySpeedReal               = "N/A";
    const char8 *configuredMemorySpeed                   = "N/A";
    const char8 *minimumVoltage                          = "N/A";
    const char8 *maximumVoltage                          = "N/A";
    const char8 *configuredVoltage                       = "N/A";
    const char8 *memoryTechnology                        = "N/A";
    const char8 *moduleManufacturerID                    = "N/A";
    const char8 *moduleProductID                         = "N/A";
    const char8 *memorySubsystemControllerManufacturerID = "N/A";
    const char8 *memorySubsystemControllerProductID      = "N/A";
    const char8 *nonVolatileSize                         = "N/A";
    const char8 *volatileSize                            = "N/A";
    const char8 *cacheSize                               = "N/A";
    const char8 *logicalSize                             = "N/A";
    const char8 *extendedSpeed                           = "N/A";
    const char8 *extendedConfiguredMemorySpeed           = "N/A";

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            // Get string for Speed
            {
                if (entry->speed == DMI_MEMORY_DEVICE_SPEED_UNKNOWN)
                {
                    speedReal = "Unknown";
                }
                else
                if (
                    entry->speed == DMI_MEMORY_DEVICE_SPEED_NEED_TO_EXTEND
                    &&
                    DMI::getVersion() >= DMI_VERSION(3, 3)
                   )
                {
                    speedReal = mprintf("%u MHz", entry->extendedSpeed);
                }
                else
                {
                    speedReal = mprintf("%u MHz", entry->speed);
                }



                speed = mprintf("0x%04X", entry->speed);
            }



            if (DMI::getVersion() >= DMI_VERSION(2, 6))
            {
                // Get string for Rank
                {
                    if (entry->attributes.rank == DMI_MEMORY_DEVICE_RANK_UNKNOWN)
                    {
                        rank = "Unknown";
                    }
                    else
                    {
                        rank = mprintf("%u", entry->attributes.rank);
                    }
                }



                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    extendedSize = mprintf("0x%08X", entry->extendedSize.value32);



                    // Get string for Configured memory speed
                    {
                        if (entry->configuredMemorySpeed == DMI_MEMORY_DEVICE_CONFIGURED_MEMORY_SPEED_UNKNOWN)
                        {
                            configuredMemorySpeedReal = "Unknown";
                        }
                        else
                        if (
                            entry->configuredMemorySpeed == DMI_MEMORY_DEVICE_CONFIGURED_MEMORY_SPEED_NEED_TO_EXTEND
                            &&
                            DMI::getVersion() >= DMI_VERSION(3, 3)
                           )
                        {
                            configuredMemorySpeedReal = mprintf("%u MHz", entry->extendedConfiguredMemorySpeed);
                        }
                        else
                        {
                            configuredMemorySpeedReal = mprintf("%u MHz", entry->configuredMemorySpeed);
                        }



                        configuredMemorySpeed = mprintf("0x%04X", entry->configuredMemorySpeed);
                    }



                    if (DMI::getVersion() >= DMI_VERSION(2, 8))
                    {
                        // Get string for Minimum voltage
                        {
                            if (entry->minimumVoltage == DMI_MEMORY_DEVICE_MINIMUM_VOLTAGE_UNKNOWN)
                            {
                                minimumVoltage = "Unknown";
                            }
                            else
                            {
                                minimumVoltage = mprintf("%u.%03u V", entry->minimumVoltage / 1000, entry->minimumVoltage % 1000);
                            }
                        }



                        // Get string for Maximum voltage
                        {
                            if (entry->maximumVoltage == DMI_MEMORY_DEVICE_MAXIMUM_VOLTAGE_UNKNOWN)
                            {
                                maximumVoltage = "Unknown";
                            }
                            else
                            {
                                maximumVoltage = mprintf("%u.%03u V", entry->maximumVoltage / 1000, entry->maximumVoltage % 1000);
                            }
                        }



                        // Get string for Configured voltage
                        {
                            if (entry->configuredVoltage == DMI_MEMORY_DEVICE_CONFIGURED_VOLTAGE_UNKNOWN)
                            {
                                configuredVoltage = "Unknown";
                            }
                            else
                            {
                                configuredVoltage = mprintf("%u.%03u V", entry->configuredVoltage / 1000, entry->configuredVoltage % 1000);
                            }
                        }



                        if (DMI::getVersion() >= DMI_VERSION(3, 2))
                        {
                            memoryTechnology                        = strdup(enumToFullString(entry->memoryTechnology));
                            moduleManufacturerID                    = mprintf("%u", entry->moduleManufacturerID);
                            moduleProductID                         = mprintf("%u", entry->moduleProductID);
                            memorySubsystemControllerManufacturerID = mprintf("%u", entry->memorySubsystemControllerManufacturerID);
                            memorySubsystemControllerProductID      = mprintf("%u", entry->memorySubsystemControllerProductID);



                            // Get string for Non-volatile size
                            {
                                if (entry->nonVolatileSize != DMI_MEMORY_DEVICE_NON_VOLATILE_SIZE_NOT_AVAILABLE)
                                {
                                    if (entry->nonVolatileSize == DMI_MEMORY_DEVICE_NON_VOLATILE_SIZE_UNKNOWN)
                                    {
                                        nonVolatileSize = "Unknown";
                                    }
                                    else
                                    {
                                        nonVolatileSize = mprintf("%u", entry->nonVolatileSize);
                                    }
                                }
                            }



                            // Get string for Volatile size
                            {
                                if (entry->volatileSize != DMI_MEMORY_DEVICE_VOLATILE_SIZE_NOT_AVAILABLE)
                                {
                                    if (entry->volatileSize == DMI_MEMORY_DEVICE_VOLATILE_SIZE_UNKNOWN)
                                    {
                                        volatileSize = "Unknown";
                                    }
                                    else
                                    {
                                        volatileSize = mprintf("%u", entry->volatileSize);
                                    }
                                }
                            }



                            // Get string for Cache size
                            {
                                if (entry->cacheSize != DMI_MEMORY_DEVICE_CACHE_SIZE_NOT_AVAILABLE)
                                {
                                    if (entry->cacheSize == DMI_MEMORY_DEVICE_CACHE_SIZE_UNKNOWN)
                                    {
                                        cacheSize = "Unknown";
                                    }
                                    else
                                    {
                                        cacheSize = mprintf("%u", entry->cacheSize);
                                    }
                                }
                            }



                            // Get string for Logical size
                            {
                                if (entry->logicalSize == DMI_MEMORY_DEVICE_LOGICAL_SIZE_UNKNOWN)
                                {
                                    logicalSize = "Unknown";
                                }
                                else
                                {
                                    logicalSize = mprintf("%u", entry->logicalSize);
                                }
                            }



                            if (DMI::getVersion() >= DMI_VERSION(3, 3))
                            {
                                extendedSpeed                 = mprintf("0x%08X", entry->extendedSpeed);
                                extendedConfiguredMemorySpeed = mprintf("0x%08X", entry->extendedConfiguredMemorySpeed);
                            }
                        }
                    }
                }
            }
        }
    }



    const char8 *memoryErrorInformationHandle;
    const char8 *totalWidth;
    const char8 *dataWidth;
    const char8 *size;
    const char8 *deviceSet;

    // Get other strings
    {
        // Get string for Memory error information handle
        {
            if (entry->memoryErrorInformationHandle == DMI_MEMORY_DEVICE_MEMORY_ERROR_INFORMATION_HANDLE_NOT_AVAILABLE)
            {
                memoryErrorInformationHandle = "N/A";
            }
            else
            if (entry->memoryErrorInformationHandle == DMI_MEMORY_DEVICE_MEMORY_ERROR_INFORMATION_HANDLE_NO_ERROR)
            {
                memoryErrorInformationHandle = "No error";
            }
            else
            {
                memoryErrorInformationHandle = mprintf("0x%04X", entry->memoryErrorInformationHandle);
            }
        }



        // Get string for Total width
        {
            if (entry->totalWidth == DMI_MEMORY_DEVICE_TOTAL_WIDTH_UNKNOWN)
            {
                totalWidth = "Unknown";
            }
            else
            {
                totalWidth = mprintf("%u bits", entry->totalWidth);
            }
        }



        // Get string for Data width
        {
            if (entry->dataWidth == DMI_MEMORY_DEVICE_DATA_WIDTH_UNKNOWN)
            {
                dataWidth = "Unknown";
            }
            else
            {
                dataWidth = mprintf("%u bits", entry->dataWidth);
            }
        }



        // Get string for Size
        {
            if (entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_NOT_INSTALLED)
            {
                size = "Not installed";
            }
            else
            if (entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_UNKNOWN)
            {
                size = "Unknown";
            }
            else
            if (
                entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_NEED_TO_EXTEND
                &&
                DMI::getVersion() >= DMI_VERSION(2, 7)
               )
            {
                size = strdup(bytesToString(entry->extendedSize.size()));
            }
            else
            {
                size = strdup(bytesToString(entry->size.size()));
            }
        }



        // Get string for Device set
        {
            if (entry->deviceSet == DMI_MEMORY_DEVICE_DEVICE_SET_NO_SET)
            {
                deviceSet = "No set";
            }
            else
            if (entry->deviceSet == DMI_MEMORY_DEVICE_DEVICE_SET_UNKNOWN)
            {
                deviceSet = "Unknown";
            }
            else
            {
                deviceSet = mprintf("%u", entry->deviceSet);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                      strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array handle",             mprintf("0x%04X", entry->memoryArrayHandle)),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error information handle", memoryErrorInformationHandle),                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Total width",                     totalWidth),                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data width",                      dataWidth),                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Size",                            size),                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Size",                            mprintf("0x%04X", entry->size.value16)),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Form factor",                     strdup(enumToFullString(entry->formFactor))),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device set",                      deviceSet),                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device locator",                  deviceLocator),                                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bank locator",                    bankLocator),                                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory type",                     strdup(enumToFullString(entry->memoryType))),  NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Type detail", entry->typeDetail, "0x%04X", DmiMemoryDeviceTypeDetailFlag);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Speed",                   speedReal),                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Speed",                   speed),                     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",            manufacturer),              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",           serialNumber),              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",               assetTag),                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Part number",             partNumber),                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Rank",                    rank),                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended size",           extendedSize),              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Configured memory speed", configuredMemorySpeedReal), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Configured memory speed", configuredMemorySpeed),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum voltage",         minimumVoltage),            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum voltage",         maximumVoltage),            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Configured voltage",      configuredVoltage),         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory technology",       memoryTechnology),          NgosStatus::ASSERTION);



        // Add records for Memory operating mode capability
        {
            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Memory operating mode capability", entry->memoryOperatingModeCapability, "0x%04X", DmiMemoryDeviceOperatingModeCapabilityFlag);
            }
            else
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory operating mode capability", "N/A"), NgosStatus::ASSERTION);
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Firmware version",                            firmwareVersion),                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Module manufacturer ID",                      moduleManufacturerID),                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Module product ID",                           moduleProductID),                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory subsystem controller manufacturer ID", memorySubsystemControllerManufacturerID), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory subsystem controller product ID",      memorySubsystemControllerProductID),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Non-volatile size",                           nonVolatileSize),                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Volatile size",                               volatileSize),                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cache size",                                  cacheSize),                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Logical size",                                logicalSize),                             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended speed",                              extendedSpeed),                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended configured memory speed",            extendedConfiguredMemorySpeed),           NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryArrayMappedAddressEntry(DmiMemoryArrayMappedAddressEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        UEFI_LVVV(("entry->startingAddress.value = 0x%08X", entry->startingAddress.value));
        UEFI_LVVV(("entry->startingAddress       = %s",     bytesToString(entry->startingAddress.address())));
        UEFI_LVVV(("entry->endingAddress.value   = 0x%08X", entry->endingAddress.value));
        UEFI_LVVV(("entry->endingAddress         = %s",     bytesToString(entry->endingAddress.address())));
        UEFI_LVVV(("entry->memoryArrayHandle     = 0x%04X", entry->memoryArrayHandle));
        UEFI_LVVV(("entry->partitionWidth        = %u",     entry->partitionWidth));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            UEFI_LVVV(("entry->extendedStartingAddress = 0x%016lX", entry->extendedStartingAddress));
            UEFI_LVVV(("entry->extendedEndingAddress   = 0x%016lX", entry->extendedEndingAddress));
        }



        // UEFI_TEST_ASSERT(entry->startingAddress.value == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->endingAddress.value   == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->memoryArrayHandle     == 0x1000,     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->partitionWidth        == 1,          NgosStatus::ASSERTION); // Commented due to value variation

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

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            extendedStartingAddress = mprintf("0x%016lX", entry->extendedStartingAddress);
            extendedEndingAddress   = mprintf("0x%016lX", entry->extendedEndingAddress);
        }
    }



    const char8 *range;
    const char8 *range2;

    // Get other strings
    {
        // Get string for Range
        {
            u64 start;
            u64 end;

            if (
                entry->startingAddress.value == DMI_MEMORY_ARRAY_MAPPED_ADDRESS_STARTING_ADDRESS_NEED_TO_EXTEND
                &&
                entry->endingAddress.value == DMI_MEMORY_ARRAY_MAPPED_ADDRESS_ENDING_ADDRESS_NEED_TO_EXTEND
                &&
                DMI::getVersion() >= DMI_VERSION(2, 7)
               )
            {
                start = entry->extendedStartingAddress;
                end   = entry->extendedEndingAddress;
            }
            else
            {
                start = entry->startingAddress.address();
                end   = entry->endingAddress.address(1);
            }

            range  = mprintf("%s - %s", strdup(bytesToString(start)), strdup(bytesToString(end)));
            range2 = mprintf("0x%016lX - 0x%016lX", start, end);
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                strdup(enumToFullString(entry->header.type))),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                    mprintf("0x%04X", entry->header.handle)),         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Range",                     range),                                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Range",                     range2),                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Starting address",          mprintf("0x%08X", entry->startingAddress.value)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Ending address",            mprintf("0x%08X", entry->endingAddress.value)),   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array handle",       mprintf("0x%04X", entry->memoryArrayHandle)),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Partition width",           mprintf("%u", entry->partitionWidth)),            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended starting address", extendedStartingAddress),                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended ending address",   extendedEndingAddress),                           NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryDeviceMappedAddressEntry(DmiMemoryDeviceMappedAddressEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        UEFI_LVVV(("entry->startingAddress.value          = 0x%08X", entry->startingAddress.value));
        UEFI_LVVV(("entry->startingAddress                = %s",     bytesToString(entry->startingAddress.address())));
        UEFI_LVVV(("entry->endingAddress.value            = 0x%08X", entry->endingAddress.value));
        UEFI_LVVV(("entry->endingAddress                  = %s",     bytesToString(entry->endingAddress.address())));
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



        // UEFI_TEST_ASSERT(entry->startingAddress.value          == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->endingAddress.value            == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
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

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            extendedStartingAddress = mprintf("0x%016lX", entry->extendedStartingAddress);
            extendedEndingAddress   = mprintf("0x%016lX", entry->extendedEndingAddress);
        }
    }



    const char8 *range;
    const char8 *range2;
    const char8 *partitionRowPosition;
    const char8 *interleavePosition;
    const char8 *interleavedDataDepth;

    // Get other strings
    {
        // Get string for Range
        {
            u64 start;
            u64 end;

            if (
                entry->startingAddress.value == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_STARTING_ADDRESS_NEED_TO_EXTEND
                &&
                entry->endingAddress.value == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_ENDING_ADDRESS_NEED_TO_EXTEND
                &&
                DMI::getVersion() >= DMI_VERSION(2, 7)
               )
            {
                start = entry->extendedStartingAddress;
                end   = entry->extendedEndingAddress;
            }
            else
            {
                start = entry->startingAddress.address();
                end   = entry->endingAddress.address(1);
            }

            range  = mprintf("%s - %s", strdup(bytesToString(start)), strdup(bytesToString(end)));
            range2 = mprintf("0x%016lX - 0x%016lX", start, end);
        }



        // Get string for Partition row position
        {
            if (entry->partitionRowPosition == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_PARTITION_ROW_POSITION_UNKNOWN)
            {
                partitionRowPosition = "Unknown";
            }
            else
            {
                partitionRowPosition = mprintf("%u", entry->partitionRowPosition);
            }
        }



        // Get string for Interleave position
        {
            if (entry->interleavePosition == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_INTERLEAVE_POSITION_NON_INTERLEAVED)
            {
                interleavePosition = "Non-interleaved";
            }
            else
            if (entry->interleavePosition == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_INTERLEAVE_POSITION_UNKNOWN)
            {
                interleavePosition = "Unknown";
            }
            else
            {
                interleavePosition = mprintf("%u", entry->interleavePosition);
            }
        }



        // Get string for Interleaved data depth
        {
            if (entry->interleavedDataDepth == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_INTERLEAVED_DATA_DEPTH_NON_INTERLEAVED)
            {
                interleavedDataDepth = "Non-interleaved";
            }
            else
            if (entry->interleavedDataDepth == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_INTERLEAVED_DATA_DEPTH_UNKNOWN)
            {
                interleavedDataDepth = "Unknown";
            }
            else
            {
                interleavedDataDepth = mprintf("%u", entry->interleavedDataDepth);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                         strdup(enumToFullString(entry->header.type))),             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                             mprintf("0x%04X", entry->header.handle)),                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Range",                              range),                                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Range",                              range2),                                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Starting address",                   mprintf("0x%08X", entry->startingAddress.value)),          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Ending address",                     mprintf("0x%08X", entry->endingAddress.value)),            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory device handle",               mprintf("0x%04X", entry->memoryDeviceHandle)),             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array mapped address handle", mprintf("0x%04X", entry->memoryArrayMappedAddressHandle)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Partition row position",             partitionRowPosition),                                     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interleave position",                interleavePosition),                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interleaved data depth",             interleavedDataDepth),                                     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended starting address",          extendedStartingAddress),                                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended ending address",            extendedEndingAddress),                                    NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPortableBatteryEntry(DmiPortableBatteryEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->location.id               = %u", entry->location.id));
        UEFI_LVVV(("entry->manufacturer.id           = %u", entry->manufacturer.id));
        UEFI_LVVV(("entry->manufactureDate.id        = %u", entry->manufactureDate.id));
        UEFI_LVVV(("entry->serialNumber.id           = %u", entry->serialNumber.id));
        UEFI_LVVV(("entry->deviceName.id             = %u", entry->deviceName.id));
        UEFI_LVVV(("entry->deviceChemistry           = %s", enumToFullString(entry->deviceChemistry)));
        UEFI_LVVV(("entry->designCapacity            = %u", entry->designCapacity));
        UEFI_LVVV(("entry->designVoltage             = %u", entry->designVoltage));
        UEFI_LVVV(("entry->sbdsVersionNumber.id      = %u", entry->sbdsVersionNumber.id));
        UEFI_LVVV(("entry->maximumErrorInBatteryData = %u", entry->maximumErrorInBatteryData));

        if (DMI::getVersion() >= DMI_VERSION(2, 2))
        {
            UEFI_LVVV(("entry->sbdsSerialNumber            = %u",             entry->sbdsSerialNumber));
            UEFI_LVVV(("entry->sbdsManufactureDate.date    = %u",             entry->sbdsManufactureDate.date));
            UEFI_LVVV(("entry->sbdsManufactureDate.month   = %u",             entry->sbdsManufactureDate.month));
            UEFI_LVVV(("entry->sbdsManufactureDate.year    = %u",             entry->sbdsManufactureDate.year));
            UEFI_LVVV(("entry->sbdsManufactureDate.value16 = 0x%04X",         entry->sbdsManufactureDate.value16));
            UEFI_LVVV(("entry->sbdsManufactureDate         = %04u-%02u-%02u", entry->sbdsManufactureDate.realYear(), entry->sbdsManufactureDate.month, entry->sbdsManufactureDate.date));
            UEFI_LVVV(("entry->sbdsDeviceChemistry.id      = %u",             entry->sbdsDeviceChemistry.id));
            UEFI_LVVV(("entry->designCapacityMultiplier    = %u",             entry->designCapacityMultiplier));
            UEFI_LVVV(("entry->oemSpecific                 = 0x%08X",         entry->oemSpecific));
        }



        // UEFI_TEST_ASSERT(entry->location.id               == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->manufacturer.id           == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->manufactureDate.id        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->serialNumber.id           == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceName.id             == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->deviceChemistry           == DmiPortableBatteryDeviceChemistry::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->designCapacity            == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->designVoltage             == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->sbdsVersionNumber.id      == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumErrorInBatteryData == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 2))
        {
            // UEFI_TEST_ASSERT(entry->sbdsSerialNumber            == 0,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->sbdsManufactureDate.date    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->sbdsManufactureDate.month   == 0,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->sbdsManufactureDate.year    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->sbdsManufactureDate.value16 == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->sbdsDeviceChemistry.id      == 0,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->designCapacityMultiplier    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->oemSpecific                 == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= 26,                              NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 16,                                   NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntry) - 10, NgosStatus::ASSERTION);
        }
    }



    const char8 *location            = "N/A";
    const char8 *manufacturer        = "N/A";
    const char8 *manufactureDate     = "N/A";
    const char8 *serialNumber        = "N/A";
    const char8 *deviceName          = "N/A";
    const char8 *sbdsVersionNumber   = "N/A";
    const char8 *sbdsDeviceChemistry = "N/A";

    // Get strings
    {
        DmiStringId sbdsDeviceChemistryStringId;

        if (DMI::getVersion() >= DMI_VERSION(2, 2))
        {
            sbdsDeviceChemistryStringId = entry->sbdsDeviceChemistry;
        }



        if (
            entry->location.id
            ||
            entry->manufacturer.id
            ||
            entry->manufactureDate.id
            ||
            entry->serialNumber.id
            ||
            entry->deviceName.id
            ||
            entry->sbdsVersionNumber.id
            ||
            sbdsDeviceChemistryStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->location)
                    {
                        location = begin;
                    }
                    else
                    if (stringId == entry->manufacturer)
                    {
                        manufacturer = begin;
                    }
                    else
                    if (stringId == entry->manufactureDate)
                    {
                        manufactureDate = begin;
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        serialNumber = begin;
                    }
                    else
                    if (stringId == entry->deviceName)
                    {
                        deviceName = begin;
                    }
                    else
                    if (stringId == entry->sbdsVersionNumber)
                    {
                        sbdsVersionNumber = begin;
                    }
                    else
                    if (stringId == sbdsDeviceChemistryStringId)
                    {
                        sbdsDeviceChemistry = begin;
                    }



                    if (cur[1] == 0)
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
    }



    const char8 *sbdsSerialNumber         = "N/A";
    const char8 *sbdsManufactureDate      = "N/A";
    const char8 *designCapacityMultiplier = "N/A";
    const char8 *oemSpecific              = "N/A";

    // Get strings base on version
    {
        if (DMI::getVersion() >= DMI_VERSION(2, 2))
        {
            sbdsSerialNumber         = mprintf("%u", entry->sbdsSerialNumber);
            sbdsManufactureDate      = mprintf("%04u-%02u-%02u", entry->sbdsManufactureDate.realYear(), entry->sbdsManufactureDate.month, entry->sbdsManufactureDate.date);
            designCapacityMultiplier = mprintf("%u", entry->designCapacityMultiplier);
            oemSpecific              = mprintf("0x%08X", entry->oemSpecific);
        }
    }



    const char8 *designCapacity;
    const char8 *designVoltage;
    const char8 *maximumErrorInBatteryData;

    // Get other strings
    {
        // Get string for Design capacity
        {
            if (entry->designCapacity == DMI_PORTABLE_BATTERY_DESIGN_CAPACITY_UNKNOWN)
            {
                designCapacity = "Unknown";
            }
            else
            {
                u64 capacity;

                if (DMI::getVersion() >= DMI_VERSION(2, 2))
                {
                    capacity = entry->designCapacity * entry->designCapacityMultiplier;
                }
                else
                {
                    capacity = entry->designCapacity;
                }

                designCapacity = mprintf("%u.%03u W*h", capacity / 1000, capacity % 1000);
            }
        }



        // Get string for Design voltage
        {
            if (entry->designVoltage == DMI_PORTABLE_BATTERY_DESIGN_VOLTAGE_UNKNOWN)
            {
                designVoltage = "Unknown";
            }
            else
            {
                designVoltage = mprintf("%u.%03u V", entry->designVoltage / 1000, entry->designVoltage % 1000);
            }
        }



        // Get string for Maximum error in battery data
        {
            if (entry->maximumErrorInBatteryData == DMI_PORTABLE_BATTERY_MAXIMUM_ERROR_IN_BATTERY_DATA_UNKNOWN)
            {
                maximumErrorInBatteryData = "Unknown";
            }
            else
            {
                maximumErrorInBatteryData = mprintf("%u %", entry->maximumErrorInBatteryData);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                    strdup(enumToFullString(entry->header.type))),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                        mprintf("0x%04X", entry->header.handle)),          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                      location),                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",                  manufacturer),                                     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacture date",              manufactureDate),                                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",                 serialNumber),                                     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name",                   deviceName),                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device chemistry",              strdup(enumToFullString(entry->deviceChemistry))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Design capacity",               designCapacity),                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Design voltage",                designVoltage),                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS version number",           sbdsVersionNumber),                                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum error in battery data", maximumErrorInBatteryData),                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS serial number",            sbdsSerialNumber),                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS manufacture date",         sbdsManufactureDate),                              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS device chemistry",         sbdsDeviceChemistry),                              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Design capacity multiplier",    designCapacityMultiplier),                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM specific",                  oemSpecific),                                      NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiVoltageProbeEntry(DmiVoltageProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->description.id    = %u",     entry->description.id));
        UEFI_LVVV(("entry->location          = %s",     enumToFullString((DmiVoltageProbeLocation)entry->location)));
        UEFI_LVVV(("entry->status            = %s",     enumToFullString((DmiVoltageProbeStatus)entry->status)));
        UEFI_LVVV(("entry->locationAndStatus = 0x%02X", entry->locationAndStatus));
        UEFI_LVVV(("entry->maximumValue      = %u",     entry->maximumValue));
        UEFI_LVVV(("entry->minimumValue      = %u",     entry->minimumValue));
        UEFI_LVVV(("entry->resolution        = %u",     entry->resolution));
        UEFI_LVVV(("entry->tolerance         = %u",     entry->tolerance));
        UEFI_LVVV(("entry->accuracy          = %u",     entry->accuracy));
        UEFI_LVVV(("entry->oemDefined        = 0x%08X", entry->oemDefined));
        UEFI_LVVV(("entry->nominalValue      = %u",     entry->nominalValue));



        // UEFI_TEST_ASSERT(entry->description.id    == 1,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->location          == DmiVoltageProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status            == DmiVoltageProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationAndStatus == 0x00,                           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumValue      == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->minimumValue      == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->resolution        == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->tolerance         == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->accuracy          == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->oemDefined        == 0x00000000,                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->nominalValue      == 0,                              NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                           NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiVoltageProbeEntry), NgosStatus::ASSERTION);
    }



    const char8 *entryName   = nullptr;
    const char8 *description = "N/A";

    // Get strings
    {
        if (entry->description.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        description = begin;
                        entryName   = description;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *maximumValue;
    const char8 *minimumValue;
    const char8 *resolution;
    const char8 *tolerance;
    const char8 *accuracy;
    const char8 *nominalValue;

    // Get other strings
    {
        // Get string for Maximum value
        {
            if (entry->maximumValue == DMI_VOLTAGE_PROBE_MAXIMUM_VALUE_UNKNOWN)
            {
                maximumValue = "Unknown";
            }
            else
            {
                maximumValue = mprintf("%u.%03u V", entry->maximumValue / 1000, entry->maximumValue % 1000);
            }
        }



        // Get string for Minimum value
        {
            if (entry->minimumValue == DMI_VOLTAGE_PROBE_MINIMUM_VALUE_UNKNOWN)
            {
                minimumValue = "Unknown";
            }
            else
            {
                minimumValue = mprintf("%u.%03u V", entry->minimumValue / 1000, entry->minimumValue % 1000);
            }
        }



        // Get string for Resolution
        {
            if (entry->resolution == DMI_VOLTAGE_PROBE_RESOLUTION_UNKNOWN)
            {
                resolution = "Unknown";
            }
            else
            {
                resolution = mprintf("%u.%04u V", entry->resolution / 10000, entry->resolution % 10000);
            }
        }



        // Get string for Tolerance
        {
            if (entry->tolerance == DMI_VOLTAGE_PROBE_TOLERANCE_UNKNOWN)
            {
                tolerance = "Unknown";
            }
            else
            {
                tolerance = mprintf("%u.%03u V", entry->tolerance / 1000, entry->tolerance % 1000);
            }
        }



        // Get string for Accuracy
        {
            if (entry->accuracy == DMI_VOLTAGE_PROBE_ACCURACY_UNKNOWN)
            {
                accuracy = "Unknown";
            }
            else
            {
                accuracy = mprintf("%u.%02u %", entry->accuracy / 100, entry->accuracy % 100);
            }
        }



        // Get string for Nominal value
        {
            if (entry->nominalValue == DMI_VOLTAGE_PROBE_NOMINAL_VALUE_UNKNOWN)
            {
                nominalValue = "Unknown";
            }
            else
            {
                nominalValue = mprintf("%u.%03u V", entry->nominalValue / 1000, entry->nominalValue % 1000);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type))),                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   description),                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiVoltageProbeLocation)entry->location))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiVoltageProbeStatus)entry->status))),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", maximumValue),                                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", minimumValue),                                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    resolution),                                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     tolerance),                                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      accuracy),                                                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined)),                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", nominalValue),                                                       NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



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
            UEFI_LVVV(("entry->description.id = %u", entry->description.id));
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
            // UEFI_TEST_ASSERT(entry->description.id == 1, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= 15,                            NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(entry->header.length >= 14,                                NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry) - 1, NgosStatus::ASSERTION);
        }
    }



    const char8 *entryName   = nullptr;
    const char8 *description = "N/A";

    // Get strings
    {
        DmiStringId descriptionStringId;

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            descriptionStringId = entry->description;
        }



        if (descriptionStringId.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == descriptionStringId)
                    {
                        description = begin;
                        entryName   = description;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *temperatureProbeHandle;
    const char8 *coolingUnitGroup;
    const char8 *nominalSpeed;

    // Get other strings
    {
        // Get string for Temperature probe handle
        {
            if (entry->temperatureProbeHandle == DMI_COOLING_DEVICE_TEMPERATURE_PROBE_HANDLE_NOT_AVAILABLE)
            {
                temperatureProbeHandle = "N/A";
            }
            else
            {
                temperatureProbeHandle = mprintf("0x%04X", entry->temperatureProbeHandle);
            }
        }



        // Get string for Cooling unit group
        {
            if (entry->coolingUnitGroup == DMI_COOLING_DEVICE_COOLING_UNIT_GROUP_NO_GROUP)
            {
                coolingUnitGroup = "No group";
            }
            else
            {
                coolingUnitGroup = mprintf("%u", entry->coolingUnitGroup);
            }
        }



        // Get string for Nominal speed
        {
            if (entry->nominalSpeed == DMI_COOLING_DEVICE_NOMINAL_SPEED_UNKNOWN)
            {
                nominalSpeed = "Unknown";
            }
            else
            {
                nominalSpeed = mprintf("%u rpm", entry->nominalSpeed);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",               strdup(enumToFullString(entry->header.type))),                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                   mprintf("0x%04X", entry->header.handle)),                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Temperature probe handle", temperatureProbeHandle),                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type",              strdup(enumToFullString((DmiCoolingDeviceType)entry->deviceType))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                   strdup(enumToFullString((DmiCoolingDeviceStatus)entry->status))),   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cooling unit group",       coolingUnitGroup),                                                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",              mprintf("0x%08X", entry->oemDefined)),                              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal speed",            nominalSpeed),                                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",              description),                                                       NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiTemperatureProbeEntry(DmiTemperatureProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->description.id    = %u",     entry->description.id));
        UEFI_LVVV(("entry->location          = %s",     enumToFullString((DmiTemperatureProbeLocation)entry->location)));
        UEFI_LVVV(("entry->status            = %s",     enumToFullString((DmiTemperatureProbeStatus)entry->status)));
        UEFI_LVVV(("entry->locationAndStatus = 0x%02X", entry->locationAndStatus));
        UEFI_LVVV(("entry->maximumValue      = %u",     entry->maximumValue));
        UEFI_LVVV(("entry->minimumValue      = %u",     entry->minimumValue));
        UEFI_LVVV(("entry->resolution        = %u",     entry->resolution));
        UEFI_LVVV(("entry->tolerance         = %u",     entry->tolerance));
        UEFI_LVVV(("entry->accuracy          = %u",     entry->accuracy));
        UEFI_LVVV(("entry->oemDefined        = 0x%08X", entry->oemDefined));
        UEFI_LVVV(("entry->nominalValue      = %u",     entry->nominalValue));



        // UEFI_TEST_ASSERT(entry->description.id    == 1,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->location          == DmiTemperatureProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status            == DmiTemperatureProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationAndStatus == 0x00,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumValue      == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->minimumValue      == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->resolution        == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->tolerance         == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->accuracy          == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->oemDefined        == 0x00000000,                         NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->nominalValue      == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                               NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiTemperatureProbeEntry), NgosStatus::ASSERTION);
    }



    const char8 *entryName   = nullptr;
    const char8 *description = "N/A";

    // Get strings
    {
        if (entry->description.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        description = begin;
                        entryName   = description;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *maximumValue;
    const char8 *minimumValue;
    const char8 *resolution;
    const char8 *tolerance;
    const char8 *accuracy;
    const char8 *nominalValue;

    // Get other strings
    {
        // Get string for Maximum value
        {
            if (entry->maximumValue == DMI_TEMPERATURE_PROBE_MAXIMUM_VALUE_UNKNOWN)
            {
                maximumValue = "Unknown";
            }
            else
            {
                maximumValue = mprintf("%u.%u C", entry->maximumValue / 10, entry->maximumValue % 10);
            }
        }



        // Get string for Minimum value
        {
            if (entry->minimumValue == DMI_TEMPERATURE_PROBE_MINIMUM_VALUE_UNKNOWN)
            {
                minimumValue = "Unknown";
            }
            else
            {
                minimumValue = mprintf("%u.%u C", entry->minimumValue / 10, entry->minimumValue % 10);
            }
        }



        // Get string for Resolution
        {
            if (entry->resolution == DMI_TEMPERATURE_PROBE_RESOLUTION_UNKNOWN)
            {
                resolution = "Unknown";
            }
            else
            {
                resolution = mprintf("%u.%03u C", entry->resolution / 1000, entry->resolution % 1000);
            }
        }



        // Get string for Tolerance
        {
            if (entry->tolerance == DMI_TEMPERATURE_PROBE_TOLERANCE_UNKNOWN)
            {
                tolerance = "Unknown";
            }
            else
            {
                tolerance = mprintf("%u.%u C", entry->tolerance / 10, entry->tolerance % 10);
            }
        }



        // Get string for Accuracy
        {
            if (entry->accuracy == DMI_TEMPERATURE_PROBE_ACCURACY_UNKNOWN)
            {
                accuracy = "Unknown";
            }
            else
            {
                accuracy = mprintf("%u.%02u %", entry->accuracy / 100, entry->accuracy % 100);
            }
        }



        // Get string for Nominal value
        {
            if (entry->nominalValue == DMI_TEMPERATURE_PROBE_NOMINAL_VALUE_UNKNOWN)
            {
                nominalValue = "Unknown";
            }
            else
            {
                nominalValue = mprintf("%u.%u C", entry->nominalValue / 10, entry->nominalValue % 10);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type))),                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),                                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   description),                                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiTemperatureProbeLocation)entry->location))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiTemperatureProbeStatus)entry->status))),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", maximumValue),                                                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", minimumValue),                                                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    resolution),                                                             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     tolerance),                                                              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      accuracy),                                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined)),                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", nominalValue),                                                           NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiElectricalCurrentProbeEntry(DmiElectricalCurrentProbeEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        UEFI_LVVV(("entry->description.id    = %u",     entry->description.id));
        UEFI_LVVV(("entry->location          = %s",     enumToFullString((DmiElectricalCurrentProbeLocation)entry->location)));
        UEFI_LVVV(("entry->status            = %s",     enumToFullString((DmiElectricalCurrentProbeStatus)entry->status)));
        UEFI_LVVV(("entry->locationAndStatus = 0x%02X", entry->locationAndStatus));
        UEFI_LVVV(("entry->maximumValue      = %u",     entry->maximumValue));
        UEFI_LVVV(("entry->minimumValue      = %u",     entry->minimumValue));
        UEFI_LVVV(("entry->resolution        = %u",     entry->resolution));
        UEFI_LVVV(("entry->tolerance         = %u",     entry->tolerance));
        UEFI_LVVV(("entry->accuracy          = %u",     entry->accuracy));
        UEFI_LVVV(("entry->oemDefined        = 0x%08X", entry->oemDefined));
        UEFI_LVVV(("entry->nominalValue      = %u",     entry->nominalValue));



        // UEFI_TEST_ASSERT(entry->description.id    == 1,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->location          == DmiElectricalCurrentProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->status            == DmiElectricalCurrentProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->locationAndStatus == 0x00,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->maximumValue      == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->minimumValue      == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->resolution        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->tolerance         == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->accuracy          == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->oemDefined        == 0x00000000,                               NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(entry->nominalValue      == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 22,                                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiElectricalCurrentProbeEntry), NgosStatus::ASSERTION);
    }



    const char8 *entryName   = nullptr;
    const char8 *description = "N/A";

    // Get strings
    {
        if (entry->description.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        description = begin;
                        entryName   = description;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *maximumValue;
    const char8 *minimumValue;
    const char8 *resolution;
    const char8 *tolerance;
    const char8 *accuracy;
    const char8 *nominalValue;

    // Get other strings
    {
        // Get string for Maximum value
        {
            if (entry->maximumValue == DMI_ELECTRICAL_CURRENT_PROBE_MAXIMUM_VALUE_UNKNOWN)
            {
                maximumValue = "Unknown";
            }
            else
            {
                maximumValue = mprintf("%u.%03u A", entry->maximumValue / 1000, entry->maximumValue % 1000);
            }
        }



        // Get string for Minimum value
        {
            if (entry->minimumValue == DMI_ELECTRICAL_CURRENT_PROBE_MINIMUM_VALUE_UNKNOWN)
            {
                minimumValue = "Unknown";
            }
            else
            {
                minimumValue = mprintf("%u.%03u A", entry->minimumValue / 1000, entry->minimumValue % 1000);
            }
        }



        // Get string for Resolution
        {
            if (entry->resolution == DMI_ELECTRICAL_CURRENT_PROBE_RESOLUTION_UNKNOWN)
            {
                resolution = "Unknown";
            }
            else
            {
                resolution = mprintf("%u.%04u A", entry->resolution / 10000, entry->resolution % 10000);
            }
        }



        // Get string for Tolerance
        {
            if (entry->tolerance == DMI_ELECTRICAL_CURRENT_PROBE_TOLERANCE_UNKNOWN)
            {
                tolerance = "Unknown";
            }
            else
            {
                tolerance = mprintf("%u.%03u A", entry->tolerance / 1000, entry->tolerance % 1000);
            }
        }



        // Get string for Accuracy
        {
            if (entry->accuracy == DMI_ELECTRICAL_CURRENT_PROBE_ACCURACY_UNKNOWN)
            {
                accuracy = "Unknown";
            }
            else
            {
                accuracy = mprintf("%u.%02u %", entry->accuracy / 100, entry->accuracy % 100);
            }
        }



        // Get string for Nominal value
        {
            if (entry->nominalValue == DMI_ELECTRICAL_CURRENT_PROBE_NOMINAL_VALUE_UNKNOWN)
            {
                nominalValue = "Unknown";
            }
            else
            {
                nominalValue = mprintf("%u.%03u A", entry->nominalValue / 1000, entry->nominalValue % 1000);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type))),                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle)),                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   description),                                                                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiElectricalCurrentProbeLocation)entry->location))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiElectricalCurrentProbeStatus)entry->status))),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", maximumValue),                                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", minimumValue),                                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    resolution),                                                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     tolerance),                                                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      accuracy),                                                                     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined)),                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", nominalValue),                                                                 NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemBootEntry(DmiSystemBootEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        UEFI_LVVV(("entry->bootStatus = %s", enumToFullString(entry->bootStatus)));

        // UEFI_TEST_ASSERT(entry->bootStatus == DmiSystemBootStatus::NO_ERROR, NgosStatus::ASSERTION); // Commented due to value variation

        UEFI_TEST_ASSERT(entry->header.length >= 11,                         NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemBootEntry), NgosStatus::ASSERTION);
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",  strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",      mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Boot status", strdup(enumToFullString(entry->bootStatus))),  NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



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



    const char8 *entryName         = nullptr;
    const char8 *descriptionString = "N/A";

    // Get strings
    {
        if (entry->descriptionStringId)
        {
            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->descriptionStringId)
                    {
                        descriptionString = begin;
                        entryName         = descriptionString;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",   strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",       mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",  descriptionString),                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",         strdup(enumToFullString(entry->type))),        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Address",      mprintf("0x%08X", entry->address)),            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Address type", strdup(enumToFullString(entry->addressType))), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



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



    const char8 *entryName         = nullptr;
    const char8 *descriptionString = "N/A";

    // Get strings
    {
        if (entry->descriptionStringId)
        {
            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->descriptionStringId)
                    {
                        descriptionString = begin;
                        entryName         = descriptionString;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *thresholdHandle;

    // Get other strings
    {
        // Get string for Threshold handle
        {
            if (entry->thresholdHandle == DMI_MANAGEMENT_DEVICE_COMPONENT_THRESHOLD_HANDLE_NOT_AVAILABLE)
            {
                thresholdHandle = "N/A";
            }
            else
            {
                thresholdHandle = mprintf("0x%04X", entry->thresholdHandle);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",               strdup(enumToFullString(entry->header.type))),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                   mprintf("0x%04X", entry->header.handle)),          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",              descriptionString),                                NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Management device handle", mprintf("0x%04X", entry->managementDeviceHandle)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Component handle",         mprintf("0x%04X", entry->componentHandle)),        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Threshold handle",         thresholdHandle),                                  NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiManagementDeviceThresholdDataEntry(DmiManagementDeviceThresholdDataEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



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



    const char8 *lowerThresholdNonCritical;
    const char8 *upperThresholdNonCritical;
    const char8 *lowerThresholdCritical;
    const char8 *upperThresholdCritical;
    const char8 *lowerThresholdNonRecoverable;
    const char8 *upperThresholdNonRecoverable;

    // Get other strings
    {
        // Get string for Lower threshold non-critical
        {
            if (entry->lowerThresholdNonCritical == DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_LOWER_THRESHOLD_NON_CRITICAL_NOT_AVAILABLE)
            {
                lowerThresholdNonCritical = "N/A";
            }
            else
            {
                lowerThresholdNonCritical = mprintf("%u", entry->lowerThresholdNonCritical);
            }
        }



        // Get string for Upper threshold non-critical
        {
            if (entry->upperThresholdNonCritical == DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_UPPER_THRESHOLD_NON_CRITICAL_NOT_AVAILABLE)
            {
                upperThresholdNonCritical = "N/A";
            }
            else
            {
                upperThresholdNonCritical = mprintf("%u", entry->upperThresholdNonCritical);
            }
        }



        // Get string for Lower threshold critical
        {
            if (entry->lowerThresholdCritical == DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_LOWER_THRESHOLD_CRITICAL_NOT_AVAILABLE)
            {
                lowerThresholdCritical = "N/A";
            }
            else
            {
                lowerThresholdCritical = mprintf("%u", entry->lowerThresholdCritical);
            }
        }



        // Get string for Upper threshold critical
        {
            if (entry->upperThresholdCritical == DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_UPPER_THRESHOLD_CRITICAL_NOT_AVAILABLE)
            {
                upperThresholdCritical = "N/A";
            }
            else
            {
                upperThresholdCritical = mprintf("%u", entry->upperThresholdCritical);
            }
        }



        // Get string for Lower threshold non-recoverable
        {
            if (entry->lowerThresholdNonRecoverable == DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_LOWER_THRESHOLD_NON_RECOVERABLE_NOT_AVAILABLE)
            {
                lowerThresholdNonRecoverable = "N/A";
            }
            else
            {
                lowerThresholdNonRecoverable = mprintf("%u", entry->lowerThresholdNonRecoverable);
            }
        }



        // Get string for Upper threshold non-recoverable
        {
            if (entry->upperThresholdNonRecoverable == DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_UPPER_THRESHOLD_NON_RECOVERABLE_NOT_AVAILABLE)
            {
                upperThresholdNonRecoverable = "N/A";
            }
            else
            {
                upperThresholdNonRecoverable = mprintf("%u", entry->upperThresholdNonRecoverable);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                      strdup(enumToFullString(entry->header.type))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold non-critical",    lowerThresholdNonCritical),                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold non-critical",    upperThresholdNonCritical),                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold critical",        lowerThresholdCritical),                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold critical",        upperThresholdCritical),                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold non-recoverable", lowerThresholdNonRecoverable),                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold non-recoverable", upperThresholdNonRecoverable),                 NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



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



    const char8 *entryName             = nullptr;
    const char8 *locationString        = "N/A";
    const char8 *deviceNameString      = "N/A";
    const char8 *manufacturerString    = "N/A";
    const char8 *serialNumberString    = "N/A";
    const char8 *assetTagNumberString  = "N/A";
    const char8 *modelPartNumberString = "N/A";
    const char8 *revisionLevelString   = "N/A";

    // Get strings
    {
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
            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->locationStringId)
                    {
                        locationString = begin;
                    }
                    else
                    if (stringId == entry->deviceNameStringId)
                    {
                        deviceNameString = begin;
                        entryName        = deviceNameString;
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



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(entry->header.type);
        }
    }



    const char8 *powerUnitGroup;
    const char8 *maxPowerCapacity;
    const char8 *inputVoltageProbeHandle;
    const char8 *coolingDeviceHandle;
    const char8 *inputCurrentProbeHandle;

    // Get other strings
    {
        // Get string for Power unit group
        {
            if (entry->powerUnitGroup == DMI_SYSTEM_POWER_SUPPLY_POWER_UNIT_GROUP_NO_GROUP)
            {
                powerUnitGroup = "No group";
            }
            else
            {
                powerUnitGroup = mprintf("%u", entry->powerUnitGroup);
            }
        }



        // Get string for Maximum power capacity
        {
            if (entry->maxPowerCapacity == DMI_SYSTEM_POWER_SUPPLY_MAX_POWER_CAPACITY_UNKNOWN)
            {
                maxPowerCapacity = "Unknown";
            }
            else
            {
                maxPowerCapacity = mprintf("%u.%03u W", entry->maxPowerCapacity / 1000, entry->maxPowerCapacity % 1000);
            }
        }



        // Get string for Input voltage probe handle
        {
            if (entry->inputVoltageProbeHandle == DMI_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_PROBE_HANDLE_NOT_AVAILABLE)
            {
                inputVoltageProbeHandle = "N/A";
            }
            else
            {
                inputVoltageProbeHandle = mprintf("0x%04X", entry->inputVoltageProbeHandle);
            }
        }



        // Get string for Cooling device handle
        {
            if (entry->coolingDeviceHandle == DMI_SYSTEM_POWER_SUPPLY_COOLING_DEVICE_HANDLE_NOT_AVAILABLE)
            {
                coolingDeviceHandle = "N/A";
            }
            else
            {
                coolingDeviceHandle = mprintf("0x%04X", entry->coolingDeviceHandle);
            }
        }



        // Get string for Input current probe handle
        {
            if (entry->inputCurrentProbeHandle == DMI_SYSTEM_POWER_SUPPLY_INPUT_CURRENT_PROBE_HANDLE_NOT_AVAILABLE)
            {
                inputCurrentProbeHandle = "N/A";
            }
            else
            {
                inputCurrentProbeHandle = mprintf("0x%04X", entry->inputCurrentProbeHandle);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                 strdup(enumToFullString(entry->header.type))),                                                                                     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                     mprintf("0x%04X", entry->header.handle)),                                                                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Power unit group",           powerUnitGroup),                                                                                                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                   locationString),                                                                                                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name",                deviceNameString),                                                                                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",               manufacturerString),                                                                                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",              serialNumberString),                                                                                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag number",           assetTagNumberString),                                                                                                             NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Model part number",          modelPartNumberString),                                                                                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision level",             revisionLevelString),                                                                                                              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum power capacity",     maxPowerCapacity),                                                                                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Hot replaceable",            entry->powerSupplyCharacteristics.hotReplaceable ? "Yes" : "No"),                                                                  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Present",                    entry->powerSupplyCharacteristics.present ? "Yes" : "No"),                                                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Unplugged",                  entry->powerSupplyCharacteristics.unplugged ? "Yes" : "No"),                                                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input voltage range switch", strdup(enumToFullString((DmiSystemPowerSupplyInputVoltageRangeSwitch)entry->powerSupplyCharacteristics.inputVoltageRangeSwitch))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                     strdup(enumToFullString((DmiSystemPowerSupplyStatus)entry->powerSupplyCharacteristics.status))),                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                       strdup(enumToFullString((DmiSystemPowerSupplyType)entry->powerSupplyCharacteristics.type))),                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input voltage probe handle", inputVoltageProbeHandle),                                                                                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cooling device handle",      coolingDeviceHandle),                                                                                                              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input current probe handle", inputCurrentProbeHandle),                                                                                                          NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



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



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                               strdup(enumToFullString(entry->header.type))),               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                                   mprintf("0x%04X", entry->header.handle)),                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of additional information entries", mprintf("%u", entry->numberOfAdditionalInformationEntries)), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    DmiAdditionalInformation *curInfo = &entry->additionalInformationEntries[0];

    for (i64 i = 0; i < entry->numberOfAdditionalInformationEntries; ++i)
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d length",            i), mprintf("%u",     curInfo->entryLength)),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d referenced handle", i), mprintf("0x%04X", curInfo->referencedHandle)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d referenced offset", i), mprintf("%u",     curInfo->referencedOffset)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d string ID",         i), mprintf("%u",     curInfo->stringStringId)),   NgosStatus::ASSERTION);



        // Add records for Entry value
        {
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
        }



        curInfo = (DmiAdditionalInformation *)((u64)curInfo + curInfo->entryLength);
    }


    // Get strings
    {
        if (entry->numberOfAdditionalInformationEntries > 0)
        {
            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("String #%u", stringId), begin), NgosStatus::ASSERTION); // TODO: stringId.id



                    if (cur[1] == 0)
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
    }



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



    const char8 *entryName                  = nullptr;
    const char8 *referenceDesignationString = "N/A";

    // Get strings
    {
        if (entry->referenceDesignationStringId)
        {
            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            UEFI_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    UEFI_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->referenceDesignationStringId)
                    {
                        referenceDesignationString = begin;
                        entryName                  = referenceDesignationString;
                    }



                    if (cur[1] == 0)
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



        if (!entryName)
        {
            entryName = enumToHumanString(DmiEntryType::ONBOARD_DEVICES);
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(DmiEntryType::ONBOARD_DEVICES, entry->header.handle, deviceManagerImageFromDmiEntry(entry, entryName), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",            strdup(enumToFullString(entry->header.type))),                                     NgosStatus::ASSERTION);
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
    }



    return NgosStatus::OK;
}
