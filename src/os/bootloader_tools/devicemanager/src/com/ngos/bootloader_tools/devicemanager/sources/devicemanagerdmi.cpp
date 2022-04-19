#include "devicemanagerdmi.h"

#include <com/ngos/shared/common/dmi/dmi.h>
#include <com/ngos/shared/common/hex/hex.h>
#include <com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/common/uuid/utils.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, name, flagsVar, format, flagType, mode) \
    { \
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(name, mprintf(format, flagsVar.flags), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION); \
        \
        for (good_i64 _ = 0; _ < (i64)(sizeof(flagsVar) * 8); ++_) \
        { \
            u64 flag = (1ULL << _); \
            \
            if (flagsVar.flags & flag) \
            { \
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf(name ": %s", flagToString((flagType)flag)), "Yes", mode), NgosStatus::ASSERTION); \
            } \
        } \
    }



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
        case DmiEntryType::BITS32_MEMORY_ERROR:              UEFI_ASSERT_EXECUTION(saveDmiBits32MemoryErrorInformationEntry((DmiBits32MemoryErrorInformationEntry *)header),   NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS:      UEFI_ASSERT_EXECUTION(saveDmiMemoryArrayMappedAddressEntry((DmiMemoryArrayMappedAddressEntry *)header),           NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_DEVICE_MAPPED_ADDRESS:     UEFI_ASSERT_EXECUTION(saveDmiMemoryDeviceMappedAddressEntry((DmiMemoryDeviceMappedAddressEntry *)header),         NgosStatus::ASSERTION); break;
        case DmiEntryType::PORTABLE_BATTERY:                 UEFI_ASSERT_EXECUTION(saveDmiPortableBatteryEntry((DmiPortableBatteryEntry *)header),                             NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_RESET:                     UEFI_ASSERT_EXECUTION(saveDmiSystemResetEntry((DmiSystemResetEntry *)header),                                     NgosStatus::ASSERTION); break;
        case DmiEntryType::HARDWARE_SECURITY:                UEFI_ASSERT_EXECUTION(saveDmiHardwareSecurityEntry((DmiHardwareSecurityEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::VOLTAGE_PROBE:                    UEFI_ASSERT_EXECUTION(saveDmiVoltageProbeEntry((DmiVoltageProbeEntry *)header),                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::COOLING_DEVICE:                   UEFI_ASSERT_EXECUTION(saveDmiCoolingDeviceEntry((DmiCoolingDeviceEntry *)header),                                 NgosStatus::ASSERTION); break;
        case DmiEntryType::TEMPERATURE_PROBE:                UEFI_ASSERT_EXECUTION(saveDmiTemperatureProbeEntry((DmiTemperatureProbeEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::ELECTRICAL_CURRENT_PROBE:         UEFI_ASSERT_EXECUTION(saveDmiElectricalCurrentProbeEntry((DmiElectricalCurrentProbeEntry *)header),               NgosStatus::ASSERTION); break;
        case DmiEntryType::OUT_OF_BAND_REMOTE_ACCESS:        UEFI_ASSERT_EXECUTION(saveDmiOutOfBandRemoteAccessEntry((DmiOutOfBandRemoteAccessEntry *)header),                 NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_BOOT:                      UEFI_ASSERT_EXECUTION(saveDmiSystemBootEntry((DmiSystemBootEntry *)header),                                       NgosStatus::ASSERTION); break;
        case DmiEntryType::BITS64_MEMORY_ERROR:              UEFI_ASSERT_EXECUTION(saveDmiBits64MemoryErrorInformationEntry((DmiBits64MemoryErrorInformationEntry *)header),   NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE:                UEFI_ASSERT_EXECUTION(saveDmiManagementDeviceEntry((DmiManagementDeviceEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE_COMPONENT:      UEFI_ASSERT_EXECUTION(saveDmiManagementDeviceComponentEntry((DmiManagementDeviceComponentEntry *)header),         NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE_THRESHOLD_DATA: UEFI_ASSERT_EXECUTION(saveDmiManagementDeviceThresholdDataEntry((DmiManagementDeviceThresholdDataEntry *)header), NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_POWER_SUPPLY:              UEFI_ASSERT_EXECUTION(saveDmiSystemPowerSupplyEntry((DmiSystemPowerSupplyEntry *)header),                         NgosStatus::ASSERTION); break;
        case DmiEntryType::ADDITIONAL:                       UEFI_ASSERT_EXECUTION(saveDmiAdditionalInformationEntry((DmiAdditionalInformationEntry *)header),                 NgosStatus::ASSERTION); break;
        case DmiEntryType::ONBOARD_DEVICES_EXTENDED:         UEFI_ASSERT_EXECUTION(saveDmiOnboardDevicesExtendedEntry((DmiOnboardDevicesExtendedEntry *)header),               NgosStatus::ASSERTION); break;
        case DmiEntryType::INACTIVE:                         UEFI_ASSERT_EXECUTION(saveDmiInactiveEntry((DmiInactiveEntry *)header),                                           NgosStatus::ASSERTION); break;

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



    DmiBiosEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiBiosEntryV21) ? (DmiBiosEntryV21 *)entry : nullptr;
    DmiBiosEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiBiosEntryV23) ? (DmiBiosEntryV23 *)entry : nullptr;
    DmiBiosEntryV24 *entryV24 = DMI::getVersion() >= DMI_VERSION(2, 4) && entry->header.length >= sizeof(DmiBiosEntryV24) ? (DmiBiosEntryV24 *)entry : nullptr;
    DmiBiosEntryV31 *entryV31 = DMI::getVersion() >= DMI_VERSION(3, 1) && entry->header.length >= sizeof(DmiBiosEntryV31) ? (DmiBiosEntryV31 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->vendor.id                  = %u",     entry->vendor.id));
            UEFI_LVVV(("entry->biosVersion.id             = %u",     entry->biosVersion.id));
            UEFI_LVVV(("entry->biosStartingAddressSegment = 0x%04X", entry->biosStartingAddressSegment));
            UEFI_LVVV(("entry->biosReleaseDate.id         = %u",     entry->biosReleaseDate.id));
            UEFI_LVVV(("entry->biosRomSize.value          = 0x%02X", entry->biosRomSize.value));
            UEFI_LVVV(("entry->biosRomSize                = %s",     bytesToString(entry->biosRomSize.size())));
            UEFI_LVVV(("entry->biosCharacteristics        = %s",     flagsToFullString(entry->biosCharacteristics)));

            if (entryV21)
            {
                UEFI_LVVV(("entryV21->biosCharacteristicsExtensionBiosReserved = %s", flagsToFullString(entryV21->biosCharacteristicsExtensionBiosReserved)));

                if (entryV23)
                {
                    UEFI_LVVV(("entryV23->biosCharacteristicsExtensionSystemReserved = %s", flagsToFullString(entryV23->biosCharacteristicsExtensionSystemReserved)));

                    if (entryV24)
                    {
                        UEFI_LVVV(("entryV24->systemBiosMajorRelease                 = %u", entryV24->systemBiosMajorRelease));
                        UEFI_LVVV(("entryV24->systemBiosMinorRelease                 = %u", entryV24->systemBiosMinorRelease));
                        UEFI_LVVV(("entryV24->embeddedControllerFirmwareMajorRelease = %u", entryV24->embeddedControllerFirmwareMajorRelease));
                        UEFI_LVVV(("entryV24->embeddedControllerFirmwareMinorRelease = %u", entryV24->embeddedControllerFirmwareMinorRelease));

                        if (entryV31)
                        {
                            UEFI_LVVV(("entryV31->extendedBiosRomSize.value   = %u",     entryV31->extendedBiosRomSize.value));
                            UEFI_LVVV(("entryV31->extendedBiosRomSize.unit    = %s",     enumToFullString((DmiBiosExtendedRomSizeUnit)entryV31->extendedBiosRomSize.unit)));
                            UEFI_LVVV(("entryV31->extendedBiosRomSize.value16 = 0x%04X", entryV31->extendedBiosRomSize.value16));
                            UEFI_LVVV(("entryV31->extendedBiosRomSize         = %s",     bytesToString(entryV31->extendedBiosRomSize.size())));
                        }
                    }
                }
            }
        }



        // Check variables
        {
            UEFI_TEST_ASSERT(entry->vendor.id                     == 1,                                                                     NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->biosVersion.id                == 2,                                                                     NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->biosStartingAddressSegment == 0xE800,                                                                NgosStatus::ASSERTION); // Commented due to value variation
            UEFI_TEST_ASSERT(entry->biosReleaseDate.id            == 3,                                                                     NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->biosRomSize.value          == 0xFF,                                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->biosCharacteristics        == FLAGS(DmiBiosCharacteristicsFlag::BIOS_CHARACTERISTICS_NOT_SUPPORTED), NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV21)
            {
                // UEFI_TEST_ASSERT(entryV21->biosCharacteristicsExtensionBiosReserved == FLAGS(DmiBiosCharacteristicsBiosReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV23)
                {
                    // UEFI_TEST_ASSERT(entryV23->biosCharacteristicsExtensionSystemReserved == FLAGS(DmiBiosCharacteristicsSystemReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

                    if (entryV24)
                    {
                        // UEFI_TEST_ASSERT(entryV24->systemBiosMajorRelease                 == 15,  NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entryV24->systemBiosMinorRelease                 == 103, NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entryV24->embeddedControllerFirmwareMajorRelease == 151, NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entryV24->embeddedControllerFirmwareMinorRelease == 78,  NgosStatus::ASSERTION); // Commented due to value variation

                        if (entryV31)
                        {
                            // UEFI_TEST_ASSERT(entryV31->extendedBiosRomSize.value   == 0,                                     NgosStatus::ASSERTION); // Commented due to value variation
                            // UEFI_TEST_ASSERT(entryV31->extendedBiosRomSize.unit    == DmiBiosExtendedRomSizeUnit::MEGABYTES, NgosStatus::ASSERTION); // Commented due to value variation
                            // UEFI_TEST_ASSERT(entryV31->extendedBiosRomSize.value16 == 0x0000,                                NgosStatus::ASSERTION); // Commented due to value variation

                            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV31), NgosStatus::ASSERTION);
                        }
                        else
                        {
                            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV24), NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV23), NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry), NgosStatus::ASSERTION);
            }
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



    const char8 *systemBiosMajorRelease                 = "N/A";
    const char8 *systemBiosMinorRelease                 = "N/A";
    const char8 *embeddedControllerFirmwareMajorRelease = "N/A";
    const char8 *embeddedControllerFirmwareMinorRelease = "N/A";
    const char8 *extendedBiosRomSize                    = "N/A";

    // Get strings base on version
    {
        if (entryV24)
        {
            // Get string for System BIOS major release
            {
                if (entryV24->systemBiosMajorRelease != DMI_BIOS_SYSTEM_BIOS_MAJOR_RELEASE_NOT_AVAILABLE)
                {
                    systemBiosMajorRelease = mprintf("%u", entryV24->systemBiosMajorRelease);
                }
            }



            // Get string for System BIOS minor release
            {
                if (entryV24->systemBiosMinorRelease != DMI_BIOS_SYSTEM_BIOS_MINOR_RELEASE_NOT_AVAILABLE)
                {
                    systemBiosMinorRelease = mprintf("%u", entryV24->systemBiosMinorRelease);
                }
            }



            // Get string for Embedded controller firmware major release
            {
                if (entryV24->embeddedControllerFirmwareMajorRelease != DMI_BIOS_EMBEDDED_CONTROLLER_FIRMWARE_MAJOR_RELEASE_NOT_AVAILABLE)
                {
                    embeddedControllerFirmwareMajorRelease = mprintf("%u", entryV24->embeddedControllerFirmwareMajorRelease);
                }
            }



            // Get string for Embedded controller firmware minor release
            {
                if (entryV24->embeddedControllerFirmwareMinorRelease != DMI_BIOS_EMBEDDED_CONTROLLER_FIRMWARE_MINOR_RELEASE_NOT_AVAILABLE)
                {
                    embeddedControllerFirmwareMinorRelease = mprintf("%u", entryV24->embeddedControllerFirmwareMinorRelease);
                }
            }



            if (entryV31)
            {
                extendedBiosRomSize = mprintf("0x%04X", entryV31->extendedBiosRomSize.value16);
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
                entryV31
               )
            {
                biosRomSize = strdup(bytesToString(entryV31->extendedBiosRomSize.size()));
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",               strdup(enumToFullString(entry->header.type)),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                   mprintf("0x%04X", entry->header.handle),              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor",                   vendor,                                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",                  biosVersion,                                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Starting address segment", mprintf("0x%04X", entry->biosStartingAddressSegment), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Release date",             biosReleaseDate,                                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("ROM size",                 biosRomSize,                                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("ROM size",                 mprintf("0x%02X", entry->biosRomSize.value),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics", entry->biosCharacteristics, "0x%016llX", DmiBiosCharacteristicsFlag, DeviceManagerMode::EXPERT);



        // Add records for Characteristics (BIOS reserved)
        {
            if (entryV21)
            {
                ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics (BIOS reserved)", entryV21->biosCharacteristicsExtensionBiosReserved, "0x%02X", DmiBiosCharacteristicsBiosReservedFlag, DeviceManagerMode::EXPERT);
            }
            else
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics (BIOS reserved)", "N/A", DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            }
        }



        // Add records for Characteristics (System reserved)
        {
            if (entryV23)
            {
                ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics (System reserved)", entryV23->biosCharacteristicsExtensionSystemReserved, "0x%02X", DmiBiosCharacteristicsSystemReservedFlag, DeviceManagerMode::EXPERT);
            }
            else
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics (System reserved)", "N/A", DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System BIOS major release",                  systemBiosMajorRelease,                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System BIOS minor release",                  systemBiosMinorRelease,                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Embedded controller firmware major release", embeddedControllerFirmwareMajorRelease, DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Embedded controller firmware minor release", embeddedControllerFirmwareMinorRelease, DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended ROM size",                          extendedBiosRomSize,                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemEntry(DmiSystemEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiSystemEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiSystemEntryV21) ? (DmiSystemEntryV21 *)entry : nullptr;
    DmiSystemEntryV24 *entryV24 = DMI::getVersion() >= DMI_VERSION(2, 4) && entry->header.length >= sizeof(DmiSystemEntryV24) ? (DmiSystemEntryV24 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->manufacturer.id = %u", entry->manufacturer.id));
            UEFI_LVVV(("entry->productName.id  = %u", entry->productName.id));
            UEFI_LVVV(("entry->version.id      = %u", entry->version.id));
            UEFI_LVVV(("entry->serialNumber.id = %u", entry->serialNumber.id));

            if (entryV21)
            {
                UEFI_LVVV(("entryV21->uuid       = %s", uuidToString(entryV21->uuid)));
                UEFI_LVVV(("entryV21->wakeUpType = %s", enumToFullString(entryV21->wakeUpType)));

                if (entryV24)
                {
                    UEFI_LVVV(("entryV24->skuNumber.id = %u", entryV24->skuNumber.id));
                    UEFI_LVVV(("entryV24->family.id    = %u", entryV24->family.id));
                }
            }
        }



        // Check variables
        {
            UEFI_TEST_ASSERT(entry->manufacturer.id    == 1, NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->productName.id  == 2, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->version.id      == 3, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->serialNumber.id == 4, NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV21)
            {
                // UEFI_TEST_ASSERT(entryV21->uuid.data1    == 0x9FAE0773,                        NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data2    == 0xF53F,                            NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data3    == 0x4A15,                            NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data4    == 0x8A,                              NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data5    == 0x11,                              NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data6[0] == 0xED,                              NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data6[1] == 0x76,                              NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data6[2] == 0xA1,                              NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data6[3] == 0x0F,                              NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data6[4] == 0x4E,                              NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->uuid.data6[5] == 0x5B,                              NgosStatus::ASSERTION); // Commented due to value variation
                UEFI_TEST_ASSERT(entryV21->wakeUpType       == DmiSystemWakeUpType::POWER_SWITCH, NgosStatus::ASSERTION);

                if (entryV24)
                {
                    // UEFI_TEST_ASSERT(entryV24->skuNumber.id == 5, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV24->family.id    == 6, NgosStatus::ASSERTION); // Commented due to value variation

                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntryV24), NgosStatus::ASSERTION);
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry), NgosStatus::ASSERTION);
            }
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

        if (entryV24)
        {
            skuNumberStringId = entryV24->skuNumber;
            familyStringId    = entryV24->family;
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
        if (entryV21)
        {
            uuid       = strdup(uuidToString(entryV21->uuid));
            wakeUpType = strdup(enumToFullString(entryV21->wakeUpType));
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",  manufacturer,                                 DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Product name",  productName,                                  DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",       version,                                      DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number", serialNumber,                                 DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("UUID",          uuid,                                         DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Wake-Up type",  wakeUpType,                                   DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SKU number",    skuNumber,                                    DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",        family,                                       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

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
        // Output variables
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

                for (good_i64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)
                {
                    UEFI_LVVV(("#%-3d: 0x%04X", i, entry->containedObjectHandles[i]));
                }

                UEFI_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
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

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBaseboardEntry) + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);
        }
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",  manufacturer,                                 DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Product",       product,                                      DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",       version,                                      DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number", serialNumber,                                 DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",     assetTag,                                     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Features", entry->featureFlags, "0x%04X", DmiBaseboardFeatureFlag, DeviceManagerMode::EXPERT);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location in chassis",                locationInChassis,                                    DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Chassis handle",                     mprintf("0x%04X", entry->chassisHandle),              DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Board type",                         strdup(enumToFullString(entry->boardType)),           DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of contained object handles", mprintf("%u", entry->numberOfContainedObjectHandles), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        // Add records for Contained object handles
        {
            for (good_i64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained object handle #%d", i), mprintf("0x%04X", entry->containedObjectHandles[i]), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
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



    DmiChassisEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1)                        && entry->header.length >= sizeof(DmiChassisEntryV21)                                                                                                         ? (DmiChassisEntryV21 *)entry                                                                    : nullptr;
    DmiChassisEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3)                        && entry->header.length >= sizeof(DmiChassisEntryV23)                                                                                                         ? (DmiChassisEntryV23 *)entry                                                                    : nullptr;
    DmiChassisEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entryV23 != nullptr && entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength + sizeof(DmiChassisEntryV27) ? (DmiChassisEntryV27 *)DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, entryV23->containedElementCount) : nullptr;



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->manufacturer.id      = %u",     entry->manufacturer.id));
            UEFI_LVVV(("entry->typeAndLocked.type   = %s",     enumToFullString((DmiChassisType)entry->typeAndLocked.type)));
            UEFI_LVVV(("entry->typeAndLocked.locked = %u",     entry->typeAndLocked.locked));
            UEFI_LVVV(("entry->typeAndLocked.value8 = 0x%02X", entry->typeAndLocked.value8));
            UEFI_LVVV(("entry->version.id           = %u",     entry->version.id));
            UEFI_LVVV(("entry->serialNumber.id      = %u",     entry->serialNumber.id));
            UEFI_LVVV(("entry->assetTag.id          = %u",     entry->assetTag.id));

            if (entryV21)
            {
                UEFI_LVVV(("entryV21->bootUpState      = %s", enumToFullString(entryV21->bootUpState)));
                UEFI_LVVV(("entryV21->powerSupplyState = %s", enumToFullString(entryV21->powerSupplyState)));
                UEFI_LVVV(("entryV21->thermalState     = %s", enumToFullString(entryV21->thermalState)));
                UEFI_LVVV(("entryV21->securityStatus   = %s", enumToFullString(entryV21->securityStatus)));

                if (entryV23)
                {
                    UEFI_LVVV(("entryV23->oemDefined                   = 0x%08X", entryV23->oemDefined));
                    UEFI_LVVV(("entryV23->height                       = %u",     entryV23->height));
                    UEFI_LVVV(("entryV23->numberOfPowerCords           = %u",     entryV23->numberOfPowerCords));
                    UEFI_LVVV(("entryV23->containedElementCount        = %u",     entryV23->containedElementCount));
                    UEFI_LVVV(("entryV23->containedElementRecordLength = %u",     entryV23->containedElementRecordLength));



                    // entryV23->containedElements:
                    {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                        UEFI_LVVV(("entryV23->containedElements:"));
                        UEFI_LVVV(("-------------------------------------"));

                        for (good_i64 i = 0; i < entryV23->containedElementCount; ++i)
                        {
                            DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, i);

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



                    if (entryV27)
                    {
                        UEFI_LVVV(("entryV27->skuNumber.id = %u", entryV27->skuNumber.id));
                    }
                }
            }
        }



        // Check variables
        {
            UEFI_TEST_ASSERT(entry->manufacturer.id         == 1,                       NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->typeAndLocked.type   == DmiChassisType::DESKTOP, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->typeAndLocked.locked == 0,                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->typeAndLocked.value8 == 0x03,                    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->version.id           == 2,                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->serialNumber.id      == 3,                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->assetTag.id          == 4,                       NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV21)
            {
                UEFI_TEST_ASSERT(entryV21->bootUpState       == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
                UEFI_TEST_ASSERT(entryV21->powerSupplyState  == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
                // UEFI_TEST_ASSERT(entryV21->thermalState   == DmiChassisState::SAFE,             NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->securityStatus == DmiChassisSecurityStatus::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV23)
                {
                    UEFI_TEST_ASSERT(entryV23->oemDefined                                             == 0x00000000,                                           NgosStatus::ASSERTION);
                    // UEFI_TEST_ASSERT(entryV23->height                                              == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV23->numberOfPowerCords                                  == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV23->containedElementCount                               == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV23->containedElementRecordLength                        == 3,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->type.typeSelect   == DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->type.dmiEntryType == DmiEntryType::SYSTEM_POWER_SUPPLY,                    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->type.value8       == 0xA7,                                                 NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->minimum           == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->maximum           == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation

                    if (entryV27)
                    {
                        // UEFI_TEST_ASSERT(entryV27->skuNumber.id == 5, NgosStatus::ASSERTION); // Commented due to value variation

                        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength + sizeof(DmiChassisEntryV27), NgosStatus::ASSERTION);
                    }
                    else
                    {
                        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength, NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry), NgosStatus::ASSERTION);
            }
        }
    }



    const char8 *manufacturer = "N/A";
    const char8 *version      = "N/A";
    const char8 *serialNumber = "N/A";
    const char8 *assetTag     = "N/A";
    const char8 *skuNumber    = "N/A";

    // Get strings
    {
        DmiStringId skuNumberStringId;

        if (entryV27)
        {
            skuNumberStringId = entryV27->skuNumber;
        }



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
        if (entryV21)
        {
            bootUpState      = strdup(enumToFullString(entryV21->bootUpState));
            powerSupplyState = strdup(enumToFullString(entryV21->powerSupplyState));
            thermalState     = strdup(enumToFullString(entryV21->thermalState));
            securityStatus   = strdup(enumToFullString(entryV21->securityStatus));

            if (entryV23)
            {
                oemDefined = mprintf("0x%08X", entryV23->oemDefined);



                // Get string for Height
                {
                    if (entryV23->height != DMI_CHASSIS_HEIGHT_NOT_AVAILABLE)
                    {
                        height = mprintf("%u U", entryV23->height);
                    }
                }



                // Get string for Number of power cords
                {
                    if (entryV23->numberOfPowerCords != DMI_CHASSIS_NUMBER_OF_POWER_CORDS_NOT_AVAILABLE)
                    {
                        numberOfPowerCords = mprintf("%u", entryV23->numberOfPowerCords);
                    }
                }



                // Get strings for Contained element count and Contained element record length
                {
                    if (
                        entryV23->containedElementCount != DMI_CHASSIS_CONTAINED_ELEMENT_COUNT_NOT_AVAILABLE
                        &&
                        entryV23->containedElementRecordLength != DMI_CHASSIS_CONTAINED_ELEMENT_RECORD_LENGTH_NOT_AVAILABLE
                       )
                    {
                        containedElementCount        = mprintf("%u", entryV23->containedElementCount);
                        containedElementRecordLength = mprintf("%u", entryV23->containedElementRecordLength);
                    }
                }
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                      strdup(enumToFullString(entry->header.type)),                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle),                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",                    manufacturer,                                                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                            strdup(enumToFullString((DmiChassisType)entry->typeAndLocked.type)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Locked",                          entry->typeAndLocked.locked ? "Yes" : "No",                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version",                         version,                                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",                   serialNumber,                                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",                       assetTag,                                                            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Boot up state",                   bootUpState,                                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Power supply state",              powerSupplyState,                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thermal state",                   thermalState,                                                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Security status",                 securityStatus,                                                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",                     oemDefined,                                                          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Height",                          height,                                                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of power cords",           numberOfPowerCords,                                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Contained element count",         containedElementCount,                                               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Contained element record length", containedElementRecordLength,                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        // Add records for Contained elements
        {
            if (entryV23)
            {
                for (good_i64 i = 0; i < entryV23->containedElementCount; ++i)
                {
                    DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, i);

                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d type select", i), strdup(enumToFullString((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

                    switch ((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect)
                    {
                        case DmiChassisContainedElementTypeSelect::BASEBOARD_TYPE: UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d type", i), strdup(enumToFullString((DmiBaseboardType)containedElement->type.baseboardType)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION); break;
                        case DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE: UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d type", i), strdup(enumToFullString((DmiEntryType)containedElement->type.dmiEntryType)),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION); break;

                        default:
                        {
                            UEFI_LF(("Unknown DMI chassis contained element type select %s, %s:%u", enumToFullString((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect), __FILE__, __LINE__));

                            return NgosStatus::UNEXPECTED_BEHAVIOUR;
                        }
                        break;
                    }

                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d minimum", i), mprintf("%u", containedElement->minimum), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Contained element #%d maximum", i), mprintf("%u", containedElement->maximum), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                }
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SKU number", skuNumber, DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiProcessorEntry(DmiProcessorEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiProcessorEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiProcessorEntryV21) ? (DmiProcessorEntryV21 *)entry : nullptr;
    DmiProcessorEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiProcessorEntryV23) ? (DmiProcessorEntryV23 *)entry : nullptr;
    DmiProcessorEntryV25 *entryV25 = DMI::getVersion() >= DMI_VERSION(2, 5) && entry->header.length >= sizeof(DmiProcessorEntryV25) ? (DmiProcessorEntryV25 *)entry : nullptr;
    DmiProcessorEntryV26 *entryV26 = DMI::getVersion() >= DMI_VERSION(2, 6) && entry->header.length >= sizeof(DmiProcessorEntryV26) ? (DmiProcessorEntryV26 *)entry : nullptr;
    DmiProcessorEntryV30 *entryV30 = DMI::getVersion() >= DMI_VERSION(3, 0) && entry->header.length >= sizeof(DmiProcessorEntryV30) ? (DmiProcessorEntryV30 *)entry : nullptr;



    // Validation
    {
        // Output variables
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

            // entry->voltage
            {
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
            }

            UEFI_LVVV(("entry->voltage.value8                                    = 0x%02X", entry->voltage.value8));
            UEFI_LVVV(("entry->externalClock                                     = %u",     entry->externalClock));
            UEFI_LVVV(("entry->maxSpeed                                          = %u",     entry->maxSpeed));
            UEFI_LVVV(("entry->currentSpeed                                      = %u",     entry->currentSpeed));
            UEFI_LVVV(("entry->processorStatusAndSocketPopulated.status          = %s",     enumToFullString((DmiProcessorStatus)entry->processorStatusAndSocketPopulated.status)));
            UEFI_LVVV(("entry->processorStatusAndSocketPopulated.socketPopulated = %u",     entry->processorStatusAndSocketPopulated.socketPopulated));
            UEFI_LVVV(("entry->processorStatusAndSocketPopulated.value8          = 0x%02X", entry->processorStatusAndSocketPopulated.value8));
            UEFI_LVVV(("entry->processorUpgrade                                  = %s",     enumToFullString(entry->processorUpgrade)));

            if (entryV21)
            {
                UEFI_LVVV(("entryV21->l1CacheHandle = 0x%04X", entryV21->l1CacheHandle));
                UEFI_LVVV(("entryV21->l2CacheHandle = 0x%04X", entryV21->l2CacheHandle));
                UEFI_LVVV(("entryV21->l3CacheHandle = 0x%04X", entryV21->l3CacheHandle));

                if (entryV23)
                {
                    UEFI_LVVV(("entryV23->serialNumber.id = %u", entryV23->serialNumber.id));
                    UEFI_LVVV(("entryV23->assetTag.id     = %u", entryV23->assetTag.id));
                    UEFI_LVVV(("entryV23->partNumber.id   = %u", entryV23->partNumber.id));

                    if (entryV25)
                    {
                        UEFI_LVVV(("entryV25->coreCount                = 0x%02X", entryV25->coreCount));
                        UEFI_LVVV(("entryV25->enabledCoreCount         = 0x%02X", entryV25->enabledCoreCount));
                        UEFI_LVVV(("entryV25->threadCount              = 0x%02X", entryV25->threadCount));
                        UEFI_LVVV(("entryV25->processorCharacteristics = %s",     flagsToFullString(entryV25->processorCharacteristics)));

                        if (entryV26)
                        {
                            UEFI_LVVV(("entryV26->processorFamily2 = %s", enumToFullString(entryV26->processorFamily2)));

                            if (entryV30)
                            {
                                UEFI_LVVV(("entryV30->coreCount2        = 0x%04X", entryV30->coreCount2));
                                UEFI_LVVV(("entryV30->enabledCoreCount2 = 0x%04X", entryV30->enabledCoreCount2));
                                UEFI_LVVV(("entryV30->threadCount2      = 0x%04X", entryV30->threadCount2));
                            }
                        }
                    }
                }
            }
        }



        // Check variables
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            // UEFI_TEST_ASSERT(entry->socketDesignation.id                              == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            UEFI_TEST_ASSERT(entry->processorType                                        == DmiProcessorType::CENTRAL_PROCESSOR,               NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->processorFamily                                   == DmiProcessorFamily::OTHER,                         NgosStatus::ASSERTION); // Commented due to value variation
            UEFI_TEST_ASSERT(entry->processorManufacturer.id                             == 2,                                                 NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->processorId.signature.stepping                    == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorId.signature.model                       == 12,                                                NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorId.signature.family                      == 6,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            UEFI_TEST_ASSERT(entry->processorId.signature.type                           == 0,                                                 NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->processorId.signature.extendedModel               == 3,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorId.signature.extendedFamily              == 0,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorId.signature.value32                     == 0x00000000,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorId.featureFlags                          == FLAGS(DmiProcessorFeatureFlag::FPU                                         // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::VME                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::DE                                        // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::PSE                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::TSC                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::MSR                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::PAE                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::MCE                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::CX8                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::APIC                                      // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::SEP                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::MTRR                                      // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::PGE                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::MCA                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::CMOV                                      // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::PAT                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::PSE36                                     // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::CLFSH                                     // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::MMX                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::FXSR                                      // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::SSE                                       // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::SSE2                                      // Commented due to value variation
            //                                                                                    , DmiProcessorFeatureFlag::SS),              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorVersion.id                               == 3,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->voltage.modeType                                  == DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->voltage.value                                     == 18,                                                NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->voltage.value8                                    == 0x92,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->externalClock                                     == 100,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->maxSpeed                                          == 2000,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->currentSpeed                                      == 2000,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorStatusAndSocketPopulated.status          == DmiProcessorStatus::ENABLED,                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorStatusAndSocketPopulated.socketPopulated == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorStatusAndSocketPopulated.value8          == 0x41,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->processorUpgrade                                  == DmiProcessorUpgrade::OTHER,                        NgosStatus::ASSERTION); // Commented due to value variation
            // Ignore CppAlignmentVerifier [END]

            if (entryV21)
            {
                // UEFI_TEST_ASSERT(entryV21->l1CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->l2CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->l3CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV23)
                {
                    // UEFI_TEST_ASSERT(entryV23->serialNumber.id == 4, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV23->assetTag.id     == 5, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV23->partNumber.id   == 6, NgosStatus::ASSERTION); // Commented due to value variation

                    if (entryV25)
                    {
                        // UEFI_TEST_ASSERT(entryV25->coreCount                == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entryV25->enabledCoreCount         == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entryV25->threadCount              == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entryV25->processorCharacteristics == FLAGS(DmiProcessorCharacteristicsFlag::SUPPORT_64_BIT), NgosStatus::ASSERTION); // Commented due to value variation

                        if (entryV26)
                        {
                            // UEFI_TEST_ASSERT(entryV26->processorFamily2 == DmiProcessorFamily2::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

                            if (entryV30)
                            {
                                // UEFI_TEST_ASSERT(entryV30->coreCount2        == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation
                                // UEFI_TEST_ASSERT(entryV30->enabledCoreCount2 == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation
                                // UEFI_TEST_ASSERT(entryV30->threadCount2      == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation

                                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV30), NgosStatus::ASSERTION);
                            }
                            else
                            {
                                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV26), NgosStatus::ASSERTION);
                            }
                        }
                        else
                        {
                            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV25), NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV23), NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry), NgosStatus::ASSERTION);
            }
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

        if (entryV23)
        {
            serialNumberStringId = entryV23->serialNumber;
            assetTagStringId     = entryV23->assetTag;
            partNumberStringId   = entryV23->partNumber;
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
        if (entryV21)
        {
            // Get string for L1 cache handle
            {
                if (entryV21->l1CacheHandle != DMI_PROCESSOR_L1_CACHE_HANDLE_NOT_AVAILABLE)
                {
                    l1CacheHandle = mprintf("0x%04X", entryV21->l1CacheHandle);
                }
            }



            // Get string for L2 cache handle
            {
                if (entryV21->l2CacheHandle != DMI_PROCESSOR_L2_CACHE_HANDLE_NOT_AVAILABLE)
                {
                    l2CacheHandle = mprintf("0x%04X", entryV21->l2CacheHandle);
                }
            }



            // Get string for L3 cache handle
            {
                if (entryV21->l3CacheHandle != DMI_PROCESSOR_L3_CACHE_HANDLE_NOT_AVAILABLE)
                {
                    l3CacheHandle = mprintf("0x%04X", entryV21->l3CacheHandle);
                }
            }



            if (entryV25)
            {
                // Get string for Core count
                {
                    if (entryV25->coreCount == DMI_PROCESSOR_CORE_COUNT_UNKNOWN)
                    {
                        coreCountReal = "Unknown";
                    }
                    else
                    if (
                        entryV25->coreCount == DMI_PROCESSOR_CORE_COUNT_NEED_TO_EXTEND
                        &&
                        entryV30
                       )
                    {
                        coreCountReal = mprintf("%u", entryV30->coreCount2);
                    }
                    else
                    {
                        coreCountReal = mprintf("%u", entryV25->coreCount);
                    }



                    coreCount = mprintf("0x%02X", entryV25->coreCount);
                }



                // Get string for Enabled core count
                {
                    if (entryV25->enabledCoreCount == DMI_PROCESSOR_ENABLED_CORE_COUNT_UNKNOWN)
                    {
                        enabledCoreCountReal = "Unknown";
                    }
                    else
                    if (
                        entryV25->enabledCoreCount == DMI_PROCESSOR_ENABLED_CORE_COUNT_NEED_TO_EXTEND
                        &&
                        entryV30
                       )
                    {
                        enabledCoreCountReal = mprintf("%u", entryV30->enabledCoreCount2);
                    }
                    else
                    {
                        enabledCoreCountReal = mprintf("%u", entryV25->enabledCoreCount);
                    }



                    enabledCoreCount = mprintf("0x%02X", entryV25->enabledCoreCount);
                }



                // Get string for Thread count
                {
                    if (entryV25->threadCount == DMI_PROCESSOR_THREAD_COUNT_UNKNOWN)
                    {
                        threadCountReal = "Unknown";
                    }
                    else
                    if (
                        entryV25->threadCount == DMI_PROCESSOR_THREAD_COUNT_NEED_TO_EXTEND
                        &&
                        entryV30
                       )
                    {
                        threadCountReal = mprintf("%u", entryV30->threadCount2);
                    }
                    else
                    {
                        threadCountReal = mprintf("%u", entryV25->threadCount);
                    }



                    threadCount = mprintf("0x%02X", entryV25->threadCount);
                }



                if (entryV26)
                {
                    processorFamily2 = mprintf("0x%04X", entryV26->processorFamily2);

                    if (entryV30)
                    {
                        coreCount2        = mprintf("0x%04X", entryV30->coreCount2);
                        enabledCoreCount2 = mprintf("0x%04X", entryV30->enabledCoreCount2);
                        threadCount2      = mprintf("0x%04X", entryV30->threadCount2);
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
                entryV26
               )
            {
                processorFamily = enumToString(entryV26->processorFamily2);
            }
            else
            {
                processorFamily = enumToString(entry->processorFamily);
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",         strdup(enumToFullString(entry->header.type)),               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",             mprintf("0x%04X", entry->header.handle),                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket designation", socketDesignation,                                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Processor type",     strdup(enumToFullString(entry->processorType)),             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",             processorFamily,                                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",             mprintf("0x%02X", entry->processorFamily),                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",       processorManufacturer,                                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Stepping",           mprintf("%u", entry->processorId.signature.stepping),       DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Model",              mprintf("%u", entry->processorId.signature.model),          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family",             mprintf("%u", entry->processorId.signature.family),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",               mprintf("%u", entry->processorId.signature.type),           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended model",     mprintf("%u", entry->processorId.signature.extendedModel),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended family",    mprintf("%u", entry->processorId.signature.extendedFamily), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Features", entry->processorId.featureFlags, "0x%08X", DmiProcessorFeatureFlag, DeviceManagerMode::TECHNICAL);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Version", processorVersion, DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



        // Add records for Voltage
        {
            switch ((DmiProcessorVoltageModeType)entry->voltage.modeType)
            {
                case DmiProcessorVoltageModeType::LEGACY_MODE:
                {
                    ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Voltage", entry->voltage, "0x%02X", DmiProcessorVoltageFlag, DeviceManagerMode::BASIC);
                }
                break;

                case DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE:
                {
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Voltage", mprintf("%u.%u V", entry->voltage.value / 10, entry->voltage.value % 10), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
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



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External clock",     externalClock,                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum speed",      maxSpeed,                                                                                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current speed",      currentSpeed,                                                                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",             strdup(enumToFullString((DmiProcessorStatus)entry->processorStatusAndSocketPopulated.status)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket populated",   entry->processorStatusAndSocketPopulated.socketPopulated ? "Yes" : "No",                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upgrade",            strdup(enumToFullString(entry->processorUpgrade)),                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L1 cache handle",    l1CacheHandle,                                                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L2 cache handle",    l2CacheHandle,                                                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("L3 cache handle",    l3CacheHandle,                                                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",      serialNumber,                                                                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",          assetTag,                                                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Part number",        partNumber,                                                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count",         coreCountReal,                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count", enabledCoreCountReal,                                                                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count",       threadCountReal,                                                                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count",         coreCount,                                                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count", enabledCoreCount,                                                                              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count",       threadCount,                                                                                   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        // Add records for Characteristics
        {
            if (entryV25)
            {
                ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics", entryV25->processorCharacteristics, "0x%04X", DmiProcessorCharacteristicsFlag, DeviceManagerMode::BASIC);
            }
            else
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Characteristics", "N/A", DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Family 2",             processorFamily2,  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Core count 2",         coreCount2,        DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled core count 2", enabledCoreCount2, DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Thread count 2",       threadCount2,      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiCacheEntry(DmiCacheEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiCacheEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiCacheEntryV21) ? (DmiCacheEntryV21 *)entry : nullptr;
    DmiCacheEntryV31 *entryV31 = DMI::getVersion() >= DMI_VERSION(3, 1) && entry->header.length >= sizeof(DmiCacheEntryV31) ? (DmiCacheEntryV31 *)entry : nullptr;



    // Validation
    {
        // Output variables
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

            if (entryV21)
            {
                UEFI_LVVV(("entryV21->cacheSpeed          = %u", entryV21->cacheSpeed));
                UEFI_LVVV(("entryV21->errorCorrectionType = %s", enumToFullString(entryV21->errorCorrectionType)));
                UEFI_LVVV(("entryV21->systemCacheType     = %s", enumToFullString(entryV21->systemCacheType)));
                UEFI_LVVV(("entryV21->associativity       = %s", enumToFullString(entryV21->associativity)));

                if (entryV31)
                {
                    UEFI_LVVV(("entryV31->maximumCacheSize2.value       = %u",     entryV31->maximumCacheSize2.value));
                    UEFI_LVVV(("entryV31->maximumCacheSize2.granularity = %s",     enumToFullString((DmiCacheSizeGranularity)entryV31->maximumCacheSize2.granularity)));
                    UEFI_LVVV(("entryV31->maximumCacheSize2.value32     = 0x%08X", entryV31->maximumCacheSize2.value32));
                    UEFI_LVVV(("entryV31->maximumCacheSize2             = %s",     bytesToString(entryV31->maximumCacheSize2.size())));
                    UEFI_LVVV(("entryV31->installedSize2.value          = %u",     entryV31->installedSize2.value));
                    UEFI_LVVV(("entryV31->installedSize2.granularity    = %s",     enumToFullString((DmiCacheSizeGranularity)entryV31->installedSize2.granularity)));
                    UEFI_LVVV(("entryV31->installedSize2.value32        = 0x%08X", entryV31->installedSize2.value32));
                    UEFI_LVVV(("entryV31->installedSize2                = %s",     bytesToString(entryV31->installedSize2.size())));
                }
            }
        }



        // Check variables
        {
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

            if (entryV21)
            {
                // UEFI_TEST_ASSERT(entryV21->cacheSpeed          == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->errorCorrectionType == DmiCacheErrorCorrectionType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->systemCacheType     == DmiCacheType::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV21->associativity       == DmiCacheAssociativity::OTHER,       NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV31)
                {
                    // UEFI_TEST_ASSERT(entryV31->maximumCacheSize2.value       == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV31->maximumCacheSize2.granularity == DmiCacheSizeGranularity::_1_KILOBYTE, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV31->maximumCacheSize2.value32     == 0x00000000,                           NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV31->installedSize2.value          == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV31->installedSize2.granularity    == DmiCacheSizeGranularity::_1_KILOBYTE, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV31->installedSize2.value32        == 0x00000000,                           NgosStatus::ASSERTION); // Commented due to value variation

                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntryV31), NgosStatus::ASSERTION);
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry), NgosStatus::ASSERTION);
            }
        }
    }



    const char8 *entryName         = mprintf("L%u Cache", entry->cacheConfiguration.levelReal());
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



    const char8 *cacheSpeed          = "N/A";
    const char8 *errorCorrectionType = "N/A";
    const char8 *systemCacheType     = "N/A";
    const char8 *associativity       = "N/A";
    const char8 *maximumCacheSize2   = "N/A";
    const char8 *installedSize2      = "N/A";

    // Get strings base on version
    {
        if (entryV21)
        {
            // Get string for Speed
            {
                if (entryV21->cacheSpeed == DMI_CACHE_CACHE_SPEED_UNKNOWN)
                {
                    cacheSpeed = "Unknown";
                }
                else
                {
                    cacheSpeed = mprintf("%u ns", entryV21->cacheSpeed);
                }
            }



            errorCorrectionType = strdup(enumToFullString(entryV21->errorCorrectionType));
            systemCacheType     = strdup(enumToFullString(entryV21->systemCacheType));
            associativity       = strdup(enumToFullString(entryV21->associativity));

            if (entryV31)
            {
                maximumCacheSize2 = mprintf("0x%08X", entryV31->maximumCacheSize2.value32);
                installedSize2    = mprintf("0x%08X", entryV31->installedSize2.value32);
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
                entryV31
               )
            {
                maximumCacheSize = strdup(bytesToString(entryV31->maximumCacheSize2.size()));
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
                entryV31
               )
            {
                installedSize = strdup(bytesToString(entryV31->installedSize2.size()));
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",         strdup(enumToFullString(entry->header.type)),                                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",             mprintf("0x%04X", entry->header.handle),                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socket designation", socketDesignation,                                                                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Level",              mprintf("%u", entry->cacheConfiguration.levelReal()),                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Socketed",           entry->cacheConfiguration.socketed ? "Yes" : "No",                                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",           strdup(enumToFullString((DmiCacheLocation)entry->cacheConfiguration.location)),               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",            entry->cacheConfiguration.enabled ? "Yes" : "No",                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Operational mode",   strdup(enumToFullString((DmiCacheOperationalMode)entry->cacheConfiguration.operationalMode)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum cache size", maximumCacheSize,                                                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installed size",     installedSize,                                                                                DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum cache size", mprintf("0x%04X", entry->maximumCacheSize.value16),                                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installed size",     mprintf("0x%04X", entry->installedSize.value16),                                              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Supported SRAM type", entry->supportedSramType, "0x%04X", DmiCacheSramTypeFlag, DeviceManagerMode::BASIC);
        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Current SRAM type",   entry->currentSramType,   "0x%04X", DmiCacheSramTypeFlag, DeviceManagerMode::BASIC);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Speed",                 cacheSpeed,          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error correction type", errorCorrectionType, DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System cache type",     systemCacheType,     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Associativity",         associativity,       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum cache size 2",  maximumCacheSize2,   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installed size 2",      installedSize2,      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->internalReferenceDesignator.id = %u", entry->internalReferenceDesignator.id));
            UEFI_LVVV(("entry->internalConnectorType          = %s", enumToFullString(entry->internalConnectorType)));
            UEFI_LVVV(("entry->externalReferenceDesignator.id = %u", entry->externalReferenceDesignator.id));
            UEFI_LVVV(("entry->externalConnectorType          = %s", enumToFullString(entry->externalConnectorType)));
            UEFI_LVVV(("entry->portType                       = %s", enumToFullString(entry->portType)));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->internalReferenceDesignator.id == 1,                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->internalConnectorType          == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->externalReferenceDesignator.id == 2,                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->externalConnectorType          == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->portType                       == DmiPortConnectorPortType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPortConnectorEntry), NgosStatus::ASSERTION);
        }
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                    strdup(enumToFullString(entry->header.type)),           DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                        mprintf("0x%04X", entry->header.handle),                DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Internal reference designator", internalReferenceDesignator,                            DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Internal connector type",       strdup(enumToFullString(entry->internalConnectorType)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External reference designator", externalReferenceDesignator,                            DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("External connector type",       strdup(enumToFullString(entry->externalConnectorType)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Port type",                     strdup(enumToFullString(entry->portType)),              DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemSlotsEntry(DmiSystemSlotsEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiSystemSlotsEntryV26 *entryV26 = DMI::getVersion() >= DMI_VERSION(2, 6) && entry->header.length >= sizeof(DmiSystemSlotsEntryV26) ? (DmiSystemSlotsEntryV26 *)entry : nullptr;
    DmiSystemSlotsEntryV32 *entryV32 = DMI::getVersion() >= DMI_VERSION(3, 2) && entry->header.length >= sizeof(DmiSystemSlotsEntryV32) ? (DmiSystemSlotsEntryV32 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->slotDesignation.id  = %u",     entry->slotDesignation.id));
            UEFI_LVVV(("entry->slotType            = %s",     enumToFullString(entry->slotType)));
            UEFI_LVVV(("entry->slotDataBusWidth    = %s",     enumToFullString(entry->slotDataBusWidth)));
            UEFI_LVVV(("entry->currentUsage        = %s",     enumToFullString(entry->currentUsage)));
            UEFI_LVVV(("entry->slotLength          = %s",     enumToFullString(entry->slotLength)));
            UEFI_LVVV(("entry->slotID              = 0x%04X", entry->slotID));
            UEFI_LVVV(("entry->slotCharacteristics = %s",     flagsToFullString(entry->slotCharacteristics)));

            if (entryV26)
            {
                UEFI_LVVV(("entryV26->segmentGroupNumber                           = %u",     entryV26->segmentGroupNumber));
                UEFI_LVVV(("entryV26->busNumber                                    = %u",     entryV26->busNumber));
                UEFI_LVVV(("entryV26->functionNumberAndDeviceNumber.functionNumber = %u",     entryV26->functionNumberAndDeviceNumber.functionNumber));
                UEFI_LVVV(("entryV26->functionNumberAndDeviceNumber.deviceNumber   = %u",     entryV26->functionNumberAndDeviceNumber.deviceNumber));
                UEFI_LVVV(("entryV26->functionNumberAndDeviceNumber.value8         = 0x%02X", entryV26->functionNumberAndDeviceNumber.value8));

                if (entryV32)
                {
                    UEFI_LVVV(("entryV32->dataBusWidth      = %u", entryV32->dataBusWidth));
                    UEFI_LVVV(("entryV32->peerGroupingCount = %u", entryV32->peerGroupingCount));



                    // entryV32->peerGroups:
                    {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                        UEFI_LVVV(("entryV32->peerGroups:"));
                        UEFI_LVVV(("-------------------------------------"));

                        for (good_i64 i = 0; i < entryV32->peerGroupingCount; ++i)
                        {
                            UEFI_LVVV(("entryV32->peerGroups[%d].segmentGroupNumber                           = %u",     i, entryV32->peerGroups[i].segmentGroupNumber));
                            UEFI_LVVV(("entryV32->peerGroups[%d].busNumber                                    = %u",     i, entryV32->peerGroups[i].busNumber));
                            UEFI_LVVV(("entryV32->peerGroups[%d].functionNumberAndDeviceNumber.functionNumber = %u",     i, entryV32->peerGroups[i].functionNumberAndDeviceNumber.functionNumber));
                            UEFI_LVVV(("entryV32->peerGroups[%d].functionNumberAndDeviceNumber.deviceNumber   = %u",     i, entryV32->peerGroups[i].functionNumberAndDeviceNumber.deviceNumber));
                            UEFI_LVVV(("entryV32->peerGroups[%d].functionNumberAndDeviceNumber.value8         = 0x%02X", i, entryV32->peerGroups[i].functionNumberAndDeviceNumber.value8));
                            UEFI_LVVV(("entryV32->peerGroups[%d].dataBusWidth                                 = %u",     i, entryV32->peerGroups[i].dataBusWidth));
                        }

                        UEFI_LVVV(("-------------------------------------"));
#endif
                    }
                }
            }
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->slotDesignation.id  == 1,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->slotType            == DmiSystemSlotsType::UNKNOWN,                    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->slotDataBusWidth    == DmiSystemSlotsDataBusWidth::UNKNOWN,            NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->currentUsage        == DmiSystemSlotsUsage::AVAILABLE,                 NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->slotLength          == DmiSystemSlotsLength::UNKNOWN,                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->slotID              == 0x0001,                                         NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->slotCharacteristics == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV26)
            {
                // UEFI_TEST_ASSERT(entryV26->segmentGroupNumber                           == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV26->busNumber                                    == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV26->functionNumberAndDeviceNumber.functionNumber == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV26->functionNumberAndDeviceNumber.deviceNumber   == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV26->functionNumberAndDeviceNumber.value8         == 0x00, NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV32)
                {
                    // UEFI_TEST_ASSERT(entryV32->dataBusWidth                                               == 0,    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV32->peerGroupingCount                                          == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV32->peerGroups[0].segmentGroupNumber                           == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV32->peerGroups[0].busNumber                                    == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV32->peerGroups[0].functionNumberAndDeviceNumber.functionNumber == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV32->peerGroups[0].functionNumberAndDeviceNumber.deviceNumber   == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV32->peerGroups[0].functionNumberAndDeviceNumber.value8         == 0x00, NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV32->peerGroups[0].dataBusWidth                                 == 0,    NgosStatus::ASSERTION); // Commented due to value variation

                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntryV32) + entryV32->peerGroupingCount * sizeof(DmiSystemSlotsPeerGroup), NgosStatus::ASSERTION);
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntryV26), NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry), NgosStatus::ASSERTION);
            }
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
        if (entryV26)
        {
            segmentGroupNumber = mprintf("%u", entryV26->segmentGroupNumber);
            busNumber          = mprintf("%u", entryV26->busNumber);
            functionNumber     = mprintf("%u", entryV26->functionNumberAndDeviceNumber.functionNumber);
            deviceNumber       = mprintf("%u", entryV26->functionNumberAndDeviceNumber.deviceNumber);

            if (entryV32)
            {
                dataBusWidth      = mprintf("%u", entryV32->dataBusWidth);
                peerGroupingCount = mprintf("%u", entryV32->peerGroupingCount);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntry(entry, entryName), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",     strdup(enumToFullString(entry->header.type)),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",         mprintf("0x%04X", entry->header.handle),           DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Designation",    slotDesignation,                                   DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",           strdup(enumToFullString(entry->slotType)),         DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data bus width", strdup(enumToFullString(entry->slotDataBusWidth)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current usage",  strdup(enumToFullString(entry->currentUsage)),     DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Length",         strdup(enumToFullString(entry->slotLength)),       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("ID",             mprintf("0x%04X", entry->slotID),                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Characteristics", entry->slotCharacteristics, "0x%04X", DmiSystemSlotsCharacteristicsFlag, DeviceManagerMode::BASIC);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment group number", segmentGroupNumber, DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus number",           busNumber,          DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Function number",      functionNumber,     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device number",        deviceNumber,       DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data bus width",       dataBusWidth,       DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Peer grouping count",  peerGroupingCount,  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



        // Add records for Peer groups
        {
            if (entryV32)
            {
                for (good_i64 i = 0; i < entryV32->peerGroupingCount; ++i)
                {
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d segment group number", i), mprintf("%u", entryV32->peerGroups[i].segmentGroupNumber),                               DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d bus number",           i), mprintf("%u", entryV32->peerGroups[i].busNumber),                                        DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d function number",      i), mprintf("%u", entryV32->peerGroups[i].functionNumberAndDeviceNumber.functionNumber),     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d device number",        i), mprintf("%u", entryV32->peerGroups[i].functionNumberAndDeviceNumber.deviceNumber),       DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Peer group #%d data bus width",       i), mprintf("%u", entryV32->peerGroups[i].dataBusWidth),                                     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
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
        // Output variables
        {
            UEFI_LVVV(("count = %u", count));

            // entry->devices:
            {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                UEFI_LVVV(("entry->devices:"));
                UEFI_LVVV(("-------------------------------------"));

                for (good_i64 i = 0; i < count; ++i)
                {
                    UEFI_LVVV(("entry->devices[%d].deviceTypeAndEnabled.deviceType = %s",     i, enumToFullString((DmiOnboardDevicesDeviceType)entry->devices[i].deviceTypeAndEnabled.deviceType)));
                    UEFI_LVVV(("entry->devices[%d].deviceTypeAndEnabled.enabled    = %u",     i, entry->devices[i].deviceTypeAndEnabled.enabled));
                    UEFI_LVVV(("entry->devices[%d].deviceTypeAndEnabled.value8     = 0x%02X", i, entry->devices[i].deviceTypeAndEnabled.value8));
                    UEFI_LVVV(("entry->devices[%d].description.id                  = %u",     i, entry->devices[i].description.id));
                }

                UEFI_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
            UEFI_TEST_ASSERT(count                                                                             >  0,                                    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT((DmiOnboardDevicesDeviceType)entry->devices[0].deviceTypeAndEnabled.deviceType == DmiOnboardDevicesDeviceType::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->devices[0].deviceTypeAndEnabled.enabled                                 == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->devices[0].deviceTypeAndEnabled.deviceTypeAndEnabled.value8             == 0x00,                                 NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->devices[0].description.id                                               == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesEntry) + sizeof(DmiOnboardDevicesDevice), NgosStatus::ASSERTION);
        }
    }



    ArrayList<DeviceManagerEntryDMI *> onboardDevices;

    // Add Device Manager entries
    {
        for (good_i64 i = 0; i < count; ++i)
        {
            DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiOnboardDevice(&entry->devices[i]), enumToHumanString(entry->header.type));

            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",  strdup(enumToFullString(entry->header.type)),                                                             DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",      mprintf("0x%04X", entry->header.handle),                                                                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type", strdup(enumToFullString((DmiOnboardDevicesDeviceType)entry->devices[i].deviceTypeAndEnabled.deviceType)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",     entry->devices[i].deviceTypeAndEnabled.enabled ? "Yes" : "No",                                            DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

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



                    for (good_i64 i = 0; i < count; ++i)
                    {
                        if (stringId == entry->devices[i].description)
                        {
                            UEFI_ASSERT_EXECUTION(onboardDevices.at(i)->setName(begin),                                            NgosStatus::ASSERTION);
                            UEFI_ASSERT_EXECUTION(onboardDevices.at(i)->addRecord("Description", begin, DeviceManagerMode::BASIC), NgosStatus::ASSERTION);

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
        for (good_i64 i = 0; i < count; ++i)
        {
            DeviceManagerEntryDMI *deviceManagerEntry = onboardDevices.at(i);

            if (deviceManagerEntry->getRecords().getSize() < 5)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description", "N/A", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
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
        // Output variables
        {
            UEFI_LVVV(("entry->stringCount = %u", entry->stringCount));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiOemStringsEntry), NgosStatus::ASSERTION);
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type", strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",     mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

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



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM string", begin, DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



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
        // Output variables
        {
            UEFI_LVVV(("entry->stringCount = %u", entry->stringCount));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemConfigurationEntry), NgosStatus::ASSERTION);
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type", strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",     mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

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



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("System configuration option", begin, DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



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
        // Output variables
        {
            UEFI_LVVV(("entry->installableLanguages = %u", entry->installableLanguages));
            UEFI_LVVV(("entry->flags                = %s", flagsToFullString(entry->flags)));
            UEFI_LVVV(("entry->currentLanguage.id   = %u", entry->currentLanguage.id));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->installableLanguages == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->flags                == FLAGS(DmiBiosLanguageFlags::NONE), NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->currentLanguage.id   == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosLanguageEntry), NgosStatus::ASSERTION);
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",            strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Installable languages", mprintf("%u", entry->installableLanguages),   DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Flags", entry->flags, "0x%02X", DmiBiosLanguageFlag, DeviceManagerMode::BASIC);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Current language ID", mprintf("%u", entry->currentLanguage.id), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);

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



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Language #%u", stringId.id), begin, DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



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
        // Output variables
        {
            UEFI_LVVV(("entry->groupName.id = %u", entry->groupName.id));
            UEFI_LVVV(("count               = %u", count));

            // entry->items:
            {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                UEFI_LVVV(("entry->items:"));
                UEFI_LVVV(("-------------------------------------"));

                for (good_i64 i = 0; i < count; ++i)
                {
                    UEFI_LVVV(("entry->items[%d].type   = %s",     i, enumToFullString(entry->items[i].type)));
                    UEFI_LVVV(("entry->items[%d].handle = 0x%04X", i, entry->items[i].handle));
                }

                UEFI_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->groupName.id    == 1,                  NgosStatus::ASSERTION); // Commented due to value variation
            UEFI_TEST_ASSERT(count                     >  0,                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->items[0].type   == DmiEntryType::BIOS, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->items[0].handle == 0x0000,             NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiGroupAssociationsEntry) + sizeof(DmiGroupAssociationsItem), NgosStatus::ASSERTION);
        }
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type", strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",     mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Name",       groupName,                                    DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);



        // Add records for Items
        {
            for (good_i64 i = 0; i < count; ++i)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Item #%d type",   i), strdup(enumToFullString(entry->items[i].type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Item #%d handle", i), mprintf("0x%04X", entry->items[i].handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
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



    DmiPhysicalMemoryArrayEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntryV27) ? (DmiPhysicalMemoryArrayEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->location                     = %s",     enumToFullString(entry->location)));
            UEFI_LVVV(("entry->use                          = %s",     enumToFullString(entry->use)));
            UEFI_LVVV(("entry->memoryErrorCorrection        = %s",     enumToFullString(entry->memoryErrorCorrection)));
            UEFI_LVVV(("entry->maximumCapacity.value        = 0x%08X", entry->maximumCapacity.value));
            UEFI_LVVV(("entry->maximumCapacity              = %s",     bytesToString(entry->maximumCapacity.size())));
            UEFI_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
            UEFI_LVVV(("entry->numberOfMemoryDevices        = %u",     entry->numberOfMemoryDevices));

            if (entryV27)
            {
                UEFI_LVVV(("entryV27->extendedMaximumCapacity = 0x%016llX", entryV27->extendedMaximumCapacity));
            }
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->location                     == DmiPhysicalMemoryArrayLocation::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->use                          == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY,             NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryErrorCorrection        == DmiPhysicalMemoryArrayErrorCorrection::MULTI_BIT_ECC, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->maximumCapacity.value        == 0x00100000,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->numberOfMemoryDevices        == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV27)
            {
                // UEFI_TEST_ASSERT(entryV27->extendedMaximumCapacity == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntry), NgosStatus::ASSERTION);
            }
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *extendedMaximumCapacity = "N/A";

    // Get strings base on version
    {
        if (entryV27)
        {
            extendedMaximumCapacity = mprintf("0x%016llX", entryV27->extendedMaximumCapacity);
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
                entryV27
               )
            {
                maximumCapacity = strdup(bytesToString(entryV27->extendedMaximumCapacity));
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                      strdup(enumToFullString(entry->header.type)),           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle),                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                        strdup(enumToFullString(entry->location)),              DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Use",                             strdup(enumToFullString(entry->use)),                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error correction",         strdup(enumToFullString(entry->memoryErrorCorrection)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum capacity",                maximumCapacity,                                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum capacity",                mprintf("0x%08X", entry->maximumCapacity.value),        DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error information handle", memoryErrorInformationHandle,                           DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of memory devices",        mprintf("%u", entry->numberOfMemoryDevices),            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended maximum capacity",       extendedMaximumCapacity,                                DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryDeviceEntry(DmiMemoryDeviceEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiMemoryDeviceEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV23) ? (DmiMemoryDeviceEntryV23 *)entry : nullptr;
    DmiMemoryDeviceEntryV26 *entryV26 = DMI::getVersion() >= DMI_VERSION(2, 6) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV26) ? (DmiMemoryDeviceEntryV26 *)entry : nullptr;
    DmiMemoryDeviceEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV27) ? (DmiMemoryDeviceEntryV27 *)entry : nullptr;
    DmiMemoryDeviceEntryV28 *entryV28 = DMI::getVersion() >= DMI_VERSION(2, 8) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV28) ? (DmiMemoryDeviceEntryV28 *)entry : nullptr;
    DmiMemoryDeviceEntryV32 *entryV32 = DMI::getVersion() >= DMI_VERSION(3, 2) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV32) ? (DmiMemoryDeviceEntryV32 *)entry : nullptr;
    DmiMemoryDeviceEntryV33 *entryV33 = DMI::getVersion() >= DMI_VERSION(3, 3) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV33) ? (DmiMemoryDeviceEntryV33 *)entry : nullptr;



    // Validation
    {
        // Output variables
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

            if (entryV23)
            {
                UEFI_LVVV(("entryV23->speed           = %u", entryV23->speed));
                UEFI_LVVV(("entryV23->manufacturer.id = %u", entryV23->manufacturer.id));
                UEFI_LVVV(("entryV23->serialNumber.id = %u", entryV23->serialNumber.id));
                UEFI_LVVV(("entryV23->assetTag.id     = %u", entryV23->assetTag.id));
                UEFI_LVVV(("entryV23->partNumber.id   = %u", entryV23->partNumber.id));

                if (entryV26)
                {
                    UEFI_LVVV(("entryV26->attributes.rank   = %u",     entryV26->attributes.rank));
                    UEFI_LVVV(("entryV26->attributes.value8 = 0x%02X", entryV26->attributes.value8));

                    if (entryV27)
                    {
                        UEFI_LVVV(("entryV27->extendedSize.value    = %u",     entryV27->extendedSize.value));
                        UEFI_LVVV(("entryV27->extendedSize.value32  = 0x%08X", entryV27->extendedSize.value32));
                        UEFI_LVVV(("entryV27->extendedSize          = %s",     bytesToString(entryV27->extendedSize.size())));
                        UEFI_LVVV(("entryV27->configuredMemorySpeed = %u",     entryV27->configuredMemorySpeed));

                        if (entryV28)
                        {
                            UEFI_LVVV(("entryV28->minimumVoltage    = %u", entryV28->minimumVoltage));
                            UEFI_LVVV(("entryV28->maximumVoltage    = %u", entryV28->maximumVoltage));
                            UEFI_LVVV(("entryV28->configuredVoltage = %u", entryV28->configuredVoltage));

                            if (entryV32)
                            {
                                UEFI_LVVV(("entryV32->memoryTechnology                        = %s", enumToFullString(entryV32->memoryTechnology)));
                                UEFI_LVVV(("entryV32->memoryOperatingModeCapability           = %s", flagsToFullString(entryV32->memoryOperatingModeCapability)));
                                UEFI_LVVV(("entryV32->firmwareVersion.id                      = %u", entryV32->firmwareVersion.id));
                                UEFI_LVVV(("entryV32->moduleManufacturerID                    = %u", entryV32->moduleManufacturerID));
                                UEFI_LVVV(("entryV32->moduleProductID                         = %u", entryV32->moduleProductID));
                                UEFI_LVVV(("entryV32->memorySubsystemControllerManufacturerID = %u", entryV32->memorySubsystemControllerManufacturerID));
                                UEFI_LVVV(("entryV32->memorySubsystemControllerProductID      = %u", entryV32->memorySubsystemControllerProductID));
                                UEFI_LVVV(("entryV32->nonVolatileSize                         = %u", entryV32->nonVolatileSize));
                                UEFI_LVVV(("entryV32->volatileSize                            = %u", entryV32->volatileSize));
                                UEFI_LVVV(("entryV32->cacheSize                               = %u", entryV32->cacheSize));
                                UEFI_LVVV(("entryV32->logicalSize                             = %u", entryV32->logicalSize));

                                if (entryV33)
                                {
                                    UEFI_LVVV(("entryV33->extendedSpeed                 = %u", entryV33->extendedSpeed));
                                    UEFI_LVVV(("entryV33->extendedConfiguredMemorySpeed = %u", entryV33->extendedConfiguredMemorySpeed));
                                }
                            }
                        }
                    }
                }
            }
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->memoryArrayHandle            == 0x1000,                                      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->totalWidth                   == 64,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->dataWidth                    == 64,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->size.value                   == 1024,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->size.granularity             == DmiMemoryDeviceSizeGranularity::_1_MEGABYTE, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->size.value16                 == 0x0400,                                      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->formFactor                   == DmiMemoryDeviceFormFactor::DIMM,             NgosStatus::ASSERTION); // Commented due to value variation
            UEFI_TEST_ASSERT(entry->deviceSet                       == 0,                                           NgosStatus::ASSERTION);
            // UEFI_TEST_ASSERT(entry->deviceLocator.id             == 1,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->bankLocator.id               == 2,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryType                   == DmiMemoryDeviceType::RAM,                    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->typeDetail                   == FLAGS(DmiMemoryDeviceTypeDetailFlag::OTHER), NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV23)
            {
                // UEFI_TEST_ASSERT(entryV23->speed           == 2133, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV23->manufacturer.id == 3,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV23->serialNumber.id == 4,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV23->assetTag.id     == 5,    NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV23->partNumber.id   == 6,    NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV26)
                {
                    // UEFI_TEST_ASSERT(entryV26->attributes.rank   == 2,    NgosStatus::ASSERTION); // Commented due to value variation
                    // UEFI_TEST_ASSERT(entryV26->attributes.value8 == 0x02, NgosStatus::ASSERTION); // Commented due to value variation

                    if (entryV27)
                    {
                        // UEFI_TEST_ASSERT(entryV27->extendedSize.value    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entryV27->extendedSize.value32  == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
                        // UEFI_TEST_ASSERT(entryV27->configuredMemorySpeed == 2133,       NgosStatus::ASSERTION); // Commented due to value variation

                        if (entryV28)
                        {
                            // UEFI_TEST_ASSERT(entryV28->minimumVoltage    == 1200, NgosStatus::ASSERTION); // Commented due to value variation
                            // UEFI_TEST_ASSERT(entryV28->maximumVoltage    == 1200, NgosStatus::ASSERTION); // Commented due to value variation
                            // UEFI_TEST_ASSERT(entryV28->configuredVoltage == 1200, NgosStatus::ASSERTION); // Commented due to value variation

                            if (entryV32)
                            {
                                UEFI_TEST_ASSERT(entryV32->memoryTechnology                        == DmiMemoryDeviceTechnology::NONE,                         NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->memoryOperatingModeCapability           == FLAGS(DmiMemoryDeviceOperatingModeCapabilityFlag::NONE), NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->firmwareVersion.id                      == 7,                                                       NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->moduleManufacturerID                    == 0,                                                       NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->moduleProductID                         == 0,                                                       NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->memorySubsystemControllerManufacturerID == 0,                                                       NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->memorySubsystemControllerProductID      == 0,                                                       NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->nonVolatileSize                         == 0,                                                       NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->volatileSize                            == 0,                                                       NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->cacheSize                               == 0,                                                       NgosStatus::ASSERTION);
                                UEFI_TEST_ASSERT(entryV32->logicalSize                             == 0,                                                       NgosStatus::ASSERTION);

                                if (entryV33)
                                {
                                    // UEFI_TEST_ASSERT(entryV33->extendedSpeed                 == 0, NgosStatus::ASSERTION); // Commented due to value variation
                                    // UEFI_TEST_ASSERT(entryV33->extendedConfiguredMemorySpeed == 0, NgosStatus::ASSERTION); // Commented due to value variation

                                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV33), NgosStatus::ASSERTION);
                                }
                                else
                                {
                                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV32), NgosStatus::ASSERTION);
                                }
                            }
                            else
                            {
                                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV28), NgosStatus::ASSERTION);
                            }
                        }
                        else
                        {
                            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV27), NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV26), NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV23), NgosStatus::ASSERTION);
                }
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry), NgosStatus::ASSERTION);
            }
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

        if (entryV23)
        {
            manufacturerStringId = entryV23->manufacturer;
            serialNumberStringId = entryV23->serialNumber;
            assetTagStringId     = entryV23->assetTag;
            partNumberStringId   = entryV23->partNumber;

            if (entryV32)
            {
                firmwareVersionStringId = entryV32->firmwareVersion;
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
        if (entryV23)
        {
            // Get string for Speed
            {
                if (entryV23->speed == DMI_MEMORY_DEVICE_SPEED_UNKNOWN)
                {
                    speedReal = "Unknown";
                }
                else
                if (
                    entryV23->speed == DMI_MEMORY_DEVICE_SPEED_NEED_TO_EXTEND
                    &&
                    entryV33
                   )
                {
                    speedReal = mprintf("%u MHz", entryV33->extendedSpeed);
                }
                else
                {
                    speedReal = mprintf("%u MHz", entryV23->speed);
                }



                speed = mprintf("0x%04X", entryV23->speed);
            }



            if (entryV26)
            {
                // Get string for Rank
                {
                    if (entryV26->attributes.rank == DMI_MEMORY_DEVICE_RANK_UNKNOWN)
                    {
                        rank = "Unknown";
                    }
                    else
                    {
                        rank = mprintf("%u", entryV26->attributes.rank);
                    }
                }



                if (entryV27)
                {
                    extendedSize = mprintf("0x%08X", entryV27->extendedSize.value32);



                    // Get string for Configured memory speed
                    {
                        if (entryV27->configuredMemorySpeed == DMI_MEMORY_DEVICE_CONFIGURED_MEMORY_SPEED_UNKNOWN)
                        {
                            configuredMemorySpeedReal = "Unknown";
                        }
                        else
                        if (
                            entryV27->configuredMemorySpeed == DMI_MEMORY_DEVICE_CONFIGURED_MEMORY_SPEED_NEED_TO_EXTEND
                            &&
                            entryV33
                           )
                        {
                            configuredMemorySpeedReal = mprintf("%u MHz", entryV33->extendedConfiguredMemorySpeed);
                        }
                        else
                        {
                            configuredMemorySpeedReal = mprintf("%u MHz", entryV27->configuredMemorySpeed);
                        }



                        configuredMemorySpeed = mprintf("0x%04X", entryV27->configuredMemorySpeed);
                    }



                    if (entryV28)
                    {
                        // Get string for Minimum voltage
                        {
                            if (entryV28->minimumVoltage == DMI_MEMORY_DEVICE_MINIMUM_VOLTAGE_UNKNOWN)
                            {
                                minimumVoltage = "Unknown";
                            }
                            else
                            {
                                minimumVoltage = mprintf("%u.%03u V", entryV28->minimumVoltage / 1000, entryV28->minimumVoltage % 1000);
                            }
                        }



                        // Get string for Maximum voltage
                        {
                            if (entryV28->maximumVoltage == DMI_MEMORY_DEVICE_MAXIMUM_VOLTAGE_UNKNOWN)
                            {
                                maximumVoltage = "Unknown";
                            }
                            else
                            {
                                maximumVoltage = mprintf("%u.%03u V", entryV28->maximumVoltage / 1000, entryV28->maximumVoltage % 1000);
                            }
                        }



                        // Get string for Configured voltage
                        {
                            if (entryV28->configuredVoltage == DMI_MEMORY_DEVICE_CONFIGURED_VOLTAGE_UNKNOWN)
                            {
                                configuredVoltage = "Unknown";
                            }
                            else
                            {
                                configuredVoltage = mprintf("%u.%03u V", entryV28->configuredVoltage / 1000, entryV28->configuredVoltage % 1000);
                            }
                        }



                        if (entryV32)
                        {
                            memoryTechnology                        = strdup(enumToFullString(entryV32->memoryTechnology));
                            moduleManufacturerID                    = mprintf("%u", entryV32->moduleManufacturerID);
                            moduleProductID                         = mprintf("%u", entryV32->moduleProductID);
                            memorySubsystemControllerManufacturerID = mprintf("%u", entryV32->memorySubsystemControllerManufacturerID);
                            memorySubsystemControllerProductID      = mprintf("%u", entryV32->memorySubsystemControllerProductID);



                            // Get string for Non-volatile size
                            {
                                if (entryV32->nonVolatileSize != DMI_MEMORY_DEVICE_NON_VOLATILE_SIZE_NOT_AVAILABLE)
                                {
                                    if (entryV32->nonVolatileSize == DMI_MEMORY_DEVICE_NON_VOLATILE_SIZE_UNKNOWN)
                                    {
                                        nonVolatileSize = "Unknown";
                                    }
                                    else
                                    {
                                        nonVolatileSize = mprintf("%u", entryV32->nonVolatileSize);
                                    }
                                }
                            }



                            // Get string for Volatile size
                            {
                                if (entryV32->volatileSize != DMI_MEMORY_DEVICE_VOLATILE_SIZE_NOT_AVAILABLE)
                                {
                                    if (entryV32->volatileSize == DMI_MEMORY_DEVICE_VOLATILE_SIZE_UNKNOWN)
                                    {
                                        volatileSize = "Unknown";
                                    }
                                    else
                                    {
                                        volatileSize = mprintf("%u", entryV32->volatileSize);
                                    }
                                }
                            }



                            // Get string for Cache size
                            {
                                if (entryV32->cacheSize != DMI_MEMORY_DEVICE_CACHE_SIZE_NOT_AVAILABLE)
                                {
                                    if (entryV32->cacheSize == DMI_MEMORY_DEVICE_CACHE_SIZE_UNKNOWN)
                                    {
                                        cacheSize = "Unknown";
                                    }
                                    else
                                    {
                                        cacheSize = mprintf("%u", entryV32->cacheSize);
                                    }
                                }
                            }



                            // Get string for Logical size
                            {
                                if (entryV32->logicalSize == DMI_MEMORY_DEVICE_LOGICAL_SIZE_UNKNOWN)
                                {
                                    logicalSize = "Unknown";
                                }
                                else
                                {
                                    logicalSize = mprintf("%u", entryV32->logicalSize);
                                }
                            }



                            if (entryV33)
                            {
                                extendedSpeed                 = mprintf("0x%08X", entryV33->extendedSpeed);
                                extendedConfiguredMemorySpeed = mprintf("0x%08X", entryV33->extendedConfiguredMemorySpeed);
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
                entryV27
               )
            {
                size = strdup(bytesToString(entryV27->extendedSize.size()));
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                      strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array handle",             mprintf("0x%04X", entry->memoryArrayHandle),  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory error information handle", memoryErrorInformationHandle,                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Total width",                     totalWidth,                                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Data width",                      dataWidth,                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Size",                            size,                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Size",                            mprintf("0x%04X", entry->size.value16),       DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Form factor",                     strdup(enumToFullString(entry->formFactor)),  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device set",                      deviceSet,                                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device locator",                  deviceLocator,                                DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bank locator",                    bankLocator,                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory type",                     strdup(enumToFullString(entry->memoryType)),  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Type detail", entry->typeDetail, "0x%04X", DmiMemoryDeviceTypeDetailFlag, DeviceManagerMode::BASIC);



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Speed",                   speedReal,                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Speed",                   speed,                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",            manufacturer,              DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",           serialNumber,              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag",               assetTag,                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Part number",             partNumber,                DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Rank",                    rank,                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended size",           extendedSize,              DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Configured memory speed", configuredMemorySpeedReal, DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Configured memory speed", configuredMemorySpeed,     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum voltage",         minimumVoltage,            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum voltage",         maximumVoltage,            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Configured voltage",      configuredVoltage,         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory technology",       memoryTechnology,          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);



        // Add records for Memory operating mode capability
        {
            if (entryV32)
            {
                ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Memory operating mode capability", entryV32->memoryOperatingModeCapability, "0x%04X", DmiMemoryDeviceOperatingModeCapabilityFlag, DeviceManagerMode::EXPERT);
            }
            else
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory operating mode capability", "N/A", DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
            }
        }



        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Firmware version",                            firmwareVersion,                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Module manufacturer ID",                      moduleManufacturerID,                    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Module product ID",                           moduleProductID,                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory subsystem controller manufacturer ID", memorySubsystemControllerManufacturerID, DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory subsystem controller product ID",      memorySubsystemControllerProductID,      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Non-volatile size",                           nonVolatileSize,                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Volatile size",                               volatileSize,                            DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cache size",                                  cacheSize,                               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Logical size",                                logicalSize,                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended speed",                              extendedSpeed,                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended configured memory speed",            extendedConfiguredMemorySpeed,           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBits32MemoryErrorInformationEntry(DmiBits32MemoryErrorInformationEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->errorType               = %s",     enumToFullString(entry->errorType)));
            UEFI_LVVV(("entry->errorGranularity        = %s",     enumToFullString(entry->errorGranularity)));
            UEFI_LVVV(("entry->errorOperation          = %s",     enumToFullString(entry->errorOperation)));
            UEFI_LVVV(("entry->vendorSyndrome          = 0x%08X", entry->vendorSyndrome));
            UEFI_LVVV(("entry->memoryArrayErrorAddress = 0x%08X", entry->memoryArrayErrorAddress));
            UEFI_LVVV(("entry->deviceErrorAddress      = 0x%08X", entry->deviceErrorAddress));
            UEFI_LVVV(("entry->errorResolution         = 0x%08X", entry->errorResolution));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->errorType               == DmiBits32MemoryErrorInformationErrorType::OK,             NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->errorGranularity        == DmiBits32MemoryErrorInformationErrorGranularity::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->errorOperation          == DmiBits32MemoryErrorInformationErrorOperation::UNKNOWN,   NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->vendorSyndrome          == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryArrayErrorAddress == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceErrorAddress      == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->errorResolution         == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBits32MemoryErrorInformationEntry), NgosStatus::ASSERTION);
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *vendorSyndrome;
    const char8 *memoryArrayErrorAddress;
    const char8 *deviceErrorAddress;
    const char8 *errorResolution;

    // Get other strings
    {
        // Get string for Vendor syndrome
        {
            if (entry->vendorSyndrome == DMI_BITS32_MEMORY_ERROR_INFORMATION_VENDOR_SYNDROME_UNKNOWN)
            {
                vendorSyndrome = "Unknown";
            }
            else
            {
                vendorSyndrome = mprintf("0x%08X", entry->vendorSyndrome);
            }
        }



        // Get string for Memory array error address
        {
            if (entry->memoryArrayErrorAddress == DMI_BITS32_MEMORY_ERROR_INFORMATION_MEMORY_ARRAY_ERROR_ADDRESS_UNKNOWN)
            {
                memoryArrayErrorAddress = "Unknown";
            }
            else
            {
                memoryArrayErrorAddress = mprintf("0x%08X", entry->memoryArrayErrorAddress);
            }
        }



        // Get string for Device error address
        {
            if (entry->deviceErrorAddress == DMI_BITS32_MEMORY_ERROR_INFORMATION_DEVICE_ERROR_ADDRESS_UNKNOWN)
            {
                deviceErrorAddress = "Unknown";
            }
            else
            {
                deviceErrorAddress = mprintf("0x%08X", entry->deviceErrorAddress);
            }
        }



        // Get string for Error resolution
        {
            if (entry->errorResolution == DMI_BITS32_MEMORY_ERROR_INFORMATION_ERROR_RESOLUTION_UNKNOWN)
            {
                errorResolution = "Unknown";
            }
            else
            {
                errorResolution = mprintf("0x%08X", entry->errorResolution);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                 strdup(enumToFullString(entry->header.type)),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                     mprintf("0x%04X", entry->header.handle),           DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error type",                 strdup(enumToFullString(entry->errorType)),        DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error granularity",          strdup(enumToFullString(entry->errorGranularity)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error operation",            strdup(enumToFullString(entry->errorOperation)),   DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor syndrome",            vendorSyndrome,                                    DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array error address", memoryArrayErrorAddress,                           DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device error address",       deviceErrorAddress,                                DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error resolution",           errorResolution,                                   DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryArrayMappedAddressEntry(DmiMemoryArrayMappedAddressEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiMemoryArrayMappedAddressEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntryV27) ? (DmiMemoryArrayMappedAddressEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->startingAddress.value = 0x%08X", entry->startingAddress.value));
            UEFI_LVVV(("entry->startingAddress       = %s",     bytesToString(entry->startingAddress.address())));
            UEFI_LVVV(("entry->endingAddress.value   = 0x%08X", entry->endingAddress.value));
            UEFI_LVVV(("entry->endingAddress         = %s",     bytesToString(entry->endingAddress.address())));
            UEFI_LVVV(("entry->memoryArrayHandle     = 0x%04X", entry->memoryArrayHandle));
            UEFI_LVVV(("entry->partitionWidth        = %u",     entry->partitionWidth));

            if (entryV27)
            {
                UEFI_LVVV(("entryV27->extendedStartingAddress = 0x%016llX", entryV27->extendedStartingAddress));
                UEFI_LVVV(("entryV27->extendedEndingAddress   = 0x%016llX", entryV27->extendedEndingAddress));
            }
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->startingAddress.value == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->endingAddress.value   == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryArrayHandle     == 0x1000,     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->partitionWidth        == 1,          NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV27)
            {
                // UEFI_TEST_ASSERT(entryV27->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV27->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntry), NgosStatus::ASSERTION);
            }
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *extendedStartingAddress = "N/A";
    const char8 *extendedEndingAddress   = "N/A";

    // Get strings base on version
    {
        if (entryV27)
        {
            extendedStartingAddress = mprintf("0x%016llX", entryV27->extendedStartingAddress);
            extendedEndingAddress   = mprintf("0x%016llX", entryV27->extendedEndingAddress);
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
                entryV27
               )
            {
                start = entryV27->extendedStartingAddress;
                end   = entryV27->extendedEndingAddress;
            }
            else
            {
                start = entry->startingAddress.address();
                end   = entry->endingAddress.address(1);
            }



            char8 startBuffer[11];
            char8 endBuffer[11];

            UEFI_ASSERT_EXECUTION(bytesToString(start, startBuffer, sizeof(startBuffer)), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(bytesToString(end,   endBuffer,   sizeof(endBuffer)),   NgosStatus::ASSERTION);

            range  = mprintf("%s - %s",               startBuffer, endBuffer);
            range2 = mprintf("0x%016llX - 0x%016llX", start, end);
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                strdup(enumToFullString(entry->header.type)),    DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                    mprintf("0x%04X", entry->header.handle),         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Range",                     range,                                           DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Range",                     range2,                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Starting address",          mprintf("0x%08X", entry->startingAddress.value), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Ending address",            mprintf("0x%08X", entry->endingAddress.value),   DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array handle",       mprintf("0x%04X", entry->memoryArrayHandle),     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Partition width",           mprintf("%u", entry->partitionWidth),            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended starting address", extendedStartingAddress,                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended ending address",   extendedEndingAddress,                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiMemoryDeviceMappedAddressEntry(DmiMemoryDeviceMappedAddressEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiMemoryDeviceMappedAddressEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntryV27) ? (DmiMemoryDeviceMappedAddressEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
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

            if (entryV27)
            {
                UEFI_LVVV(("entryV27->extendedStartingAddress = 0x%016llX", entryV27->extendedStartingAddress));
                UEFI_LVVV(("entryV27->extendedEndingAddress   = 0x%016llX", entryV27->extendedEndingAddress));
            }
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->startingAddress.value          == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->endingAddress.value            == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryDeviceHandle             == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryArrayMappedAddressHandle == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->partitionRowPosition           == 1,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->interleavePosition             == 1,          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->interleavedDataDepth           == 1,          NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV27)
            {
                // UEFI_TEST_ASSERT(entryV27->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV27->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntry), NgosStatus::ASSERTION);
            }
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *extendedStartingAddress = "N/A";
    const char8 *extendedEndingAddress   = "N/A";

    // Get strings base on version
    {
        if (entryV27)
        {
            extendedStartingAddress = mprintf("0x%016llX", entryV27->extendedStartingAddress);
            extendedEndingAddress   = mprintf("0x%016llX", entryV27->extendedEndingAddress);
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
                entryV27
               )
            {
                start = entryV27->extendedStartingAddress;
                end   = entryV27->extendedEndingAddress;
            }
            else
            {
                start = entry->startingAddress.address();
                end   = entry->endingAddress.address(1);
            }



            char8 startBuffer[11];
            char8 endBuffer[11];

            UEFI_ASSERT_EXECUTION(bytesToString(start, startBuffer, sizeof(startBuffer)), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(bytesToString(end,   endBuffer,   sizeof(endBuffer)),   NgosStatus::ASSERTION);

            range  = mprintf("%s - %s",               startBuffer, endBuffer);
            range2 = mprintf("0x%016llX - 0x%016llX", start, end);
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                         strdup(enumToFullString(entry->header.type)),             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                             mprintf("0x%04X", entry->header.handle),                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Range",                              range,                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Range",                              range2,                                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Starting address",                   mprintf("0x%08X", entry->startingAddress.value),          DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Ending address",                     mprintf("0x%08X", entry->endingAddress.value),            DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory device handle",               mprintf("0x%04X", entry->memoryDeviceHandle),             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array mapped address handle", mprintf("0x%04X", entry->memoryArrayMappedAddressHandle), DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Partition row position",             partitionRowPosition,                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interleave position",                interleavePosition,                                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Interleaved data depth",             interleavedDataDepth,                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended starting address",          extendedStartingAddress,                                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Extended ending address",            extendedEndingAddress,                                    DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiPortableBatteryEntry(DmiPortableBatteryEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiPortableBatteryEntryV22 *entryV22 = DMI::getVersion() >= DMI_VERSION(2, 2) && entry->header.length >= sizeof(DmiPortableBatteryEntryV22) ? (DmiPortableBatteryEntryV22 *)entry : nullptr;



    // Validation
    {
        // Output variables
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

            if (entryV22)
            {
                UEFI_LVVV(("entryV22->sbdsSerialNumber            = %u",             entryV22->sbdsSerialNumber));
                UEFI_LVVV(("entryV22->sbdsManufactureDate.date    = %u",             entryV22->sbdsManufactureDate.date));
                UEFI_LVVV(("entryV22->sbdsManufactureDate.month   = %u",             entryV22->sbdsManufactureDate.month));
                UEFI_LVVV(("entryV22->sbdsManufactureDate.year    = %u",             entryV22->sbdsManufactureDate.year));
                UEFI_LVVV(("entryV22->sbdsManufactureDate.value16 = 0x%04X",         entryV22->sbdsManufactureDate.value16));
                UEFI_LVVV(("entryV22->sbdsManufactureDate         = %04u-%02u-%02u", entryV22->sbdsManufactureDate.yearReal(), entryV22->sbdsManufactureDate.month, entryV22->sbdsManufactureDate.date));
                UEFI_LVVV(("entryV22->sbdsDeviceChemistry.id      = %u",             entryV22->sbdsDeviceChemistry.id));
                UEFI_LVVV(("entryV22->designCapacityMultiplier    = %u",             entryV22->designCapacityMultiplier));
                UEFI_LVVV(("entryV22->oemSpecific                 = 0x%08X",         entryV22->oemSpecific));
            }
        }



        // Check variables
        {
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

            if (entryV22)
            {
                // UEFI_TEST_ASSERT(entryV22->sbdsSerialNumber            == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV22->sbdsManufactureDate.date    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV22->sbdsManufactureDate.month   == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV22->sbdsManufactureDate.year    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV22->sbdsManufactureDate.value16 == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV22->sbdsDeviceChemistry.id      == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV22->designCapacityMultiplier    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // UEFI_TEST_ASSERT(entryV22->oemSpecific                 == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation

                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntryV22), NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntry), NgosStatus::ASSERTION);
            }
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

        if (entryV22)
        {
            sbdsDeviceChemistryStringId = entryV22->sbdsDeviceChemistry;
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
        if (entryV22)
        {
            sbdsSerialNumber         = mprintf("%u",             entryV22->sbdsSerialNumber);
            sbdsManufactureDate      = mprintf("%04u-%02u-%02u", entryV22->sbdsManufactureDate.yearReal(), entryV22->sbdsManufactureDate.month, entryV22->sbdsManufactureDate.date);
            designCapacityMultiplier = mprintf("%u",             entryV22->designCapacityMultiplier);
            oemSpecific              = mprintf("0x%08X",         entryV22->oemSpecific);
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

                if (entryV22)
                {
                    capacity = entry->designCapacity * entryV22->designCapacityMultiplier;
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                    strdup(enumToFullString(entry->header.type)),     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                        mprintf("0x%04X", entry->header.handle),          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                      location,                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",                  manufacturer,                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacture date",              manufactureDate,                                  DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",                 serialNumber,                                     DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name",                   deviceName,                                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device chemistry",              strdup(enumToFullString(entry->deviceChemistry)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Design capacity",               designCapacity,                                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Design voltage",                designVoltage,                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS version number",           sbdsVersionNumber,                                DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum error in battery data", maximumErrorInBatteryData,                        DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS serial number",            sbdsSerialNumber,                                 DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS manufacture date",         sbdsManufactureDate,                              DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("SBDS device chemistry",         sbdsDeviceChemistry,                              DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Design capacity multiplier",    designCapacityMultiplier,                         DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM specific",                  oemSpecific,                                      DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiSystemResetEntry(DmiSystemResetEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->capabilities.enabled           = %s",     boolToString(entry->capabilities.enabled)));
            UEFI_LVVV(("entry->capabilities.bootOption        = %s",     enumToFullString((DmiSystemResetBootOption)entry->capabilities.bootOption)));
            UEFI_LVVV(("entry->capabilities.bootOptionOnLimit = %s",     enumToFullString((DmiSystemResetBootOption)entry->capabilities.bootOptionOnLimit)));
            UEFI_LVVV(("entry->capabilities.watchdogEnabled   = %s",     boolToString(entry->capabilities.watchdogEnabled)));
            UEFI_LVVV(("entry->capabilities.value8            = 0x%02X", entry->capabilities.value8));
            UEFI_LVVV(("entry->resetCount                     = %u",     entry->resetCount));
            UEFI_LVVV(("entry->resetLimit                     = %u",     entry->resetLimit));
            UEFI_LVVV(("entry->timerInterval                  = %u",     entry->timerInterval));
            UEFI_LVVV(("entry->timeout                        = %u",     entry->timeout));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->capabilities.enabled           == 1,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->capabilities.bootOption        == DmiSystemResetBootOption::DO_NOT_REBOOT, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->capabilities.bootOptionOnLimit == DmiSystemResetBootOption::DO_NOT_REBOOT, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->capabilities.watchdogEnabled   == 1,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->capabilities.value8            == 0x3F,                                    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->resetCount                     == 0xFFFF,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->resetLimit                     == 0xFFFF,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->timerInterval                  == 0xFFFF,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->timeout                        == 0xFFFF,                                  NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemResetEntry), NgosStatus::ASSERTION);
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *resetCount;
    const char8 *resetLimit;
    const char8 *timerInterval;
    const char8 *timeout;

    // Get other strings
    {
        // Get string for Reset count
        {
            if (entry->resetCount == DMI_SYSTEM_RESET_RESET_COUNT_UNKNOWN)
            {
                resetCount = "Unknown";
            }
            else
            {
                resetCount = mprintf("%u", entry->resetCount);
            }
        }



        // Get string for Reset limit
        {
            if (entry->resetLimit == DMI_SYSTEM_RESET_RESET_LIMIT_UNKNOWN)
            {
                resetLimit = "Unknown";
            }
            else
            {
                resetLimit = mprintf("%u", entry->resetLimit);
            }
        }



        // Get string for Timer interval
        {
            if (entry->timerInterval == DMI_SYSTEM_RESET_TIMER_INTERVAL_UNKNOWN)
            {
                timerInterval = "Unknown";
            }
            else
            {
                timerInterval = mprintf("%u minute(s)", entry->timerInterval);
            }
        }



        // Get string for Timeout
        {
            if (entry->timeout == DMI_SYSTEM_RESET_TIMEOUT_UNKNOWN)
            {
                timeout = "Unknown";
            }
            else
            {
                timeout = mprintf("%u minute(s)", entry->timeout);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",           strdup(enumToFullString(entry->header.type)),                                              DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",               mprintf("0x%04X", entry->header.handle),                                                   DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",              entry->capabilities.enabled ? "Yes" : "No",                                                DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Boot option",          strdup(enumToFullString((DmiSystemResetBootOption)entry->capabilities.bootOption)),        DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Boot option on limit", strdup(enumToFullString((DmiSystemResetBootOption)entry->capabilities.bootOptionOnLimit)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Watchdog enabled",     entry->capabilities.watchdogEnabled ? "Yes" : "No",                                        DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Reset count",          resetCount,                                                                                DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Reset limit",          resetLimit,                                                                                DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Timer interval",       timerInterval,                                                                             DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Timeout",              timeout,                                                                                   DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiHardwareSecurityEntry(DmiHardwareSecurityEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->settings.frontPanelResetStatus       = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.frontPanelResetStatus)));
            UEFI_LVVV(("entry->settings.administratorPasswordStatus = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.administratorPasswordStatus)));
            UEFI_LVVV(("entry->settings.keyboardPasswordStatus      = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.keyboardPasswordStatus)));
            UEFI_LVVV(("entry->settings.powerOnPasswordStatus       = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.powerOnPasswordStatus)));
            UEFI_LVVV(("entry->settings.value8                      = 0x%02X", entry->settings.value8));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->settings.frontPanelResetStatus       == DmiHardwareSecurityStatus::UNKNOWN,  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->settings.administratorPasswordStatus == DmiHardwareSecurityStatus::ENABLED,  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->settings.keyboardPasswordStatus      == DmiHardwareSecurityStatus::UNKNOWN,  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->settings.powerOnPasswordStatus       == DmiHardwareSecurityStatus::DISABLED, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->settings.value8                      == 0x37,                                NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiHardwareSecurityEntry), NgosStatus::ASSERTION);
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                    strdup(enumToFullString(entry->header.type)),                                                     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                        mprintf("0x%04X", entry->header.handle),                                                          DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Front panel reset status",      strdup(enumToFullString((DmiHardwareSecurityStatus)entry->settings.frontPanelResetStatus)),       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Administrator password status", strdup(enumToFullString((DmiHardwareSecurityStatus)entry->settings.administratorPasswordStatus)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Keyboard password status",      strdup(enumToFullString((DmiHardwareSecurityStatus)entry->settings.keyboardPasswordStatus)),      DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Power-on password status",      strdup(enumToFullString((DmiHardwareSecurityStatus)entry->settings.powerOnPasswordStatus)),       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->description.id             = %u",     entry->description.id));
            UEFI_LVVV(("entry->locationAndStatus.location = %s",     enumToFullString((DmiVoltageProbeLocation)entry->locationAndStatus.location)));
            UEFI_LVVV(("entry->locationAndStatus.status   = %s",     enumToFullString((DmiVoltageProbeStatus)entry->locationAndStatus.status)));
            UEFI_LVVV(("entry->locationAndStatus.value8   = 0x%02X", entry->locationAndStatus.value8));
            UEFI_LVVV(("entry->maximumValue               = %u",     entry->maximumValue));
            UEFI_LVVV(("entry->minimumValue               = %u",     entry->minimumValue));
            UEFI_LVVV(("entry->resolution                 = %u",     entry->resolution));
            UEFI_LVVV(("entry->tolerance                  = %u",     entry->tolerance));
            UEFI_LVVV(("entry->accuracy                   = %u",     entry->accuracy));
            UEFI_LVVV(("entry->oemDefined                 = 0x%08X", entry->oemDefined));
            UEFI_LVVV(("entry->nominalValue               = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->description.id             == 1,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.location == DmiVoltageProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.status   == DmiVoltageProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.value8   == 0x00,                           NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->maximumValue               == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->minimumValue               == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->resolution                 == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->tolerance                  == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->accuracy                   == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->oemDefined                 == 0x00000000,                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->nominalValue               == 0,                              NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiVoltageProbeEntry), NgosStatus::ASSERTION);
        }
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type)),                                         DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle),                                              DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   description,                                                                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiVoltageProbeLocation)entry->locationAndStatus.location)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiVoltageProbeStatus)entry->locationAndStatus.status)),     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", maximumValue,                                                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", minimumValue,                                                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    resolution,                                                                           DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     tolerance,                                                                            DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      accuracy,                                                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined),                                                 DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", nominalValue,                                                                         DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiCoolingDeviceEntry(DmiCoolingDeviceEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiCoolingDeviceEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiCoolingDeviceEntryV27) ? (DmiCoolingDeviceEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->temperatureProbeHandle         = 0x%04X", entry->temperatureProbeHandle));
            UEFI_LVVV(("entry->deviceTypeAndStatus.deviceType = %s",     enumToFullString((DmiCoolingDeviceType)entry->deviceTypeAndStatus.deviceType)));
            UEFI_LVVV(("entry->deviceTypeAndStatus.status     = %s",     enumToFullString((DmiCoolingDeviceStatus)entry->deviceTypeAndStatus.status)));
            UEFI_LVVV(("entry->deviceTypeAndStatus.value8     = 0x%02X", entry->deviceTypeAndStatus.value8));
            UEFI_LVVV(("entry->coolingUnitGroup               = %u",     entry->coolingUnitGroup));
            UEFI_LVVV(("entry->oemDefined                     = 0x%08X", entry->oemDefined));
            UEFI_LVVV(("entry->nominalSpeed                   = %u",     entry->nominalSpeed));

            if (entryV27)
            {
                UEFI_LVVV(("entryV27->description.id = %u", entryV27->description.id));
            }
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->temperatureProbeHandle         == 0x0000,                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceTypeAndStatus.deviceType == DmiCoolingDeviceType::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceTypeAndStatus.status     == DmiCoolingDeviceStatus::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceTypeAndStatus.value8     == 0x00,                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->coolingUnitGroup               == 0,                             NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->oemDefined                     == 0x00000000,                    NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->nominalSpeed                   == 0,                             NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV27)
            {
                // UEFI_TEST_ASSERT(entryV27->description.id == 1, NgosStatus::ASSERTION); // Commented due to value variation

                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry), NgosStatus::ASSERTION);
            }
        }
    }



    const char8 *entryName   = nullptr;
    const char8 *description = "N/A";

    // Get strings
    {
        DmiStringId descriptionStringId;

        if (entryV27)
        {
            descriptionStringId = entryV27->description;
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",               strdup(enumToFullString(entry->header.type)),                                          DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                   mprintf("0x%04X", entry->header.handle),                                               DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Temperature probe handle", temperatureProbeHandle,                                                                DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type",              strdup(enumToFullString((DmiCoolingDeviceType)entry->deviceTypeAndStatus.deviceType)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                   strdup(enumToFullString((DmiCoolingDeviceStatus)entry->deviceTypeAndStatus.status)),   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cooling unit group",       coolingUnitGroup,                                                                      DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",              mprintf("0x%08X", entry->oemDefined),                                                  DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal speed",            nominalSpeed,                                                                          DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",              description,                                                                           DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->description.id             = %u",     entry->description.id));
            UEFI_LVVV(("entry->locationAndStatus.location = %s",     enumToFullString((DmiTemperatureProbeLocation)entry->locationAndStatus.location)));
            UEFI_LVVV(("entry->locationAndStatus.status   = %s",     enumToFullString((DmiTemperatureProbeStatus)entry->locationAndStatus.status)));
            UEFI_LVVV(("entry->locationAndStatus.value8   = 0x%02X", entry->locationAndStatus.value8));
            UEFI_LVVV(("entry->maximumValue               = %u",     entry->maximumValue));
            UEFI_LVVV(("entry->minimumValue               = %u",     entry->minimumValue));
            UEFI_LVVV(("entry->resolution                 = %u",     entry->resolution));
            UEFI_LVVV(("entry->tolerance                  = %u",     entry->tolerance));
            UEFI_LVVV(("entry->accuracy                   = %u",     entry->accuracy));
            UEFI_LVVV(("entry->oemDefined                 = 0x%08X", entry->oemDefined));
            UEFI_LVVV(("entry->nominalValue               = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->description.id             == 1,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.location == DmiTemperatureProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.status   == DmiTemperatureProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.value8   == 0x00,                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->maximumValue               == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->minimumValue               == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->resolution                 == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->tolerance                  == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->accuracy                   == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->oemDefined                 == 0x00000000,                         NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->nominalValue               == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiTemperatureProbeEntry), NgosStatus::ASSERTION);
        }
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type)),                                             DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle),                                                  DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   description,                                                                              DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiTemperatureProbeLocation)entry->locationAndStatus.location)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiTemperatureProbeStatus)entry->locationAndStatus.status)),     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", maximumValue,                                                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", minimumValue,                                                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    resolution,                                                                               DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     tolerance,                                                                                DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      accuracy,                                                                                 DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined),                                                     DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", nominalValue,                                                                             DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->description.id             = %u",     entry->description.id));
            UEFI_LVVV(("entry->locationAndStatus.location = %s",     enumToFullString((DmiElectricalCurrentProbeLocation)entry->locationAndStatus.location)));
            UEFI_LVVV(("entry->locationAndStatus.status   = %s",     enumToFullString((DmiElectricalCurrentProbeStatus)entry->locationAndStatus.status)));
            UEFI_LVVV(("entry->locationAndStatus.value8   = 0x%02X", entry->locationAndStatus.value8));
            UEFI_LVVV(("entry->maximumValue               = %u",     entry->maximumValue));
            UEFI_LVVV(("entry->minimumValue               = %u",     entry->minimumValue));
            UEFI_LVVV(("entry->resolution                 = %u",     entry->resolution));
            UEFI_LVVV(("entry->tolerance                  = %u",     entry->tolerance));
            UEFI_LVVV(("entry->accuracy                   = %u",     entry->accuracy));
            UEFI_LVVV(("entry->oemDefined                 = 0x%08X", entry->oemDefined));
            UEFI_LVVV(("entry->nominalValue               = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->description.id             == 1,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.location == DmiElectricalCurrentProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.status   == DmiElectricalCurrentProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->locationAndStatus.value8   == 0x00,                                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->maximumValue               == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->minimumValue               == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->resolution                 == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->tolerance                  == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->accuracy                   == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->oemDefined                 == 0x00000000,                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->nominalValue               == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiElectricalCurrentProbeEntry), NgosStatus::ASSERTION);
        }
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",    strdup(enumToFullString(entry->header.type)),                                                   DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",        mprintf("0x%04X", entry->header.handle),                                                        DeviceManagerMode::EXPERT),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",   description,                                                                                    DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",      strdup(enumToFullString((DmiElectricalCurrentProbeLocation)entry->locationAndStatus.location)), DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",        strdup(enumToFullString((DmiElectricalCurrentProbeStatus)entry->locationAndStatus.status)),     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum value", maximumValue,                                                                                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Minimum value", minimumValue,                                                                                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Resolution",    resolution,                                                                                     DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Tolerance",     tolerance,                                                                                      DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Accuracy",      accuracy,                                                                                       DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("OEM defined",   mprintf("0x%08X", entry->oemDefined),                                                           DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Nominal value", nominalValue,                                                                                   DeviceManagerMode::BASIC),     NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiOutOfBandRemoteAccessEntry(DmiOutOfBandRemoteAccessEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->manufacturerName.id = %u", entry->manufacturerName.id));
            UEFI_LVVV(("entry->connections         = %s", flagsToFullString(entry->connections)));
        }



        // Check variables
        {
            UEFI_TEST_ASSERT(entry->manufacturerName.id == 1,                                                      NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(entry->connections         == FLAGS(DmiOutOfBandRemoteAccessConnectionFlag::INBOUND), NgosStatus::ASSERTION);

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiOutOfBandRemoteAccessEntry), NgosStatus::ASSERTION);
        }
    }



    const char8 *manufacturerName = "N/A";

    // Get strings
    {
        if (entry->manufacturerName.id)
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



                    if (stringId == entry->manufacturerName)
                    {
                        manufacturerName = begin;
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",        strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",            mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer name", manufacturerName,                             DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);



        ADD_RECORDS_FOR_FLAGS(deviceManagerEntry, "Connections", entry->connections, "0x%02X", DmiOutOfBandRemoteAccessConnectionFlag, DeviceManagerMode::BASIC);



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
        // Output variables
        {
            UEFI_LVVV(("entry->bootStatus = %s", enumToFullString(entry->bootStatus)));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->bootStatus == DmiSystemBootStatus::NO_ERROR, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemBootEntry), NgosStatus::ASSERTION);
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",  strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",      mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Boot status", strdup(enumToFullString(entry->bootStatus)),  DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiBits64MemoryErrorInformationEntry(DmiBits64MemoryErrorInformationEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            UEFI_LVVV(("entry->errorType               = %s",        enumToFullString(entry->errorType)));
            UEFI_LVVV(("entry->errorGranularity        = %s",        enumToFullString(entry->errorGranularity)));
            UEFI_LVVV(("entry->errorOperation          = %s",        enumToFullString(entry->errorOperation)));
            UEFI_LVVV(("entry->vendorSyndrome          = 0x%08X",    entry->vendorSyndrome));
            UEFI_LVVV(("entry->memoryArrayErrorAddress = 0x%016llX", entry->memoryArrayErrorAddress));
            UEFI_LVVV(("entry->deviceErrorAddress      = 0x%016llX", entry->deviceErrorAddress));
            UEFI_LVVV(("entry->errorResolution         = 0x%08X",    entry->errorResolution));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->errorType               == DmiBits64MemoryErrorInformationErrorType::OK,             NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->errorGranularity        == DmiBits64MemoryErrorInformationErrorGranularity::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->errorOperation          == DmiBits64MemoryErrorInformationErrorOperation::UNKNOWN,   NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->vendorSyndrome          == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->memoryArrayErrorAddress == 0x8000000000000000,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceErrorAddress      == 0x8000000000000000,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->errorResolution         == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiBits64MemoryErrorInformationEntry), NgosStatus::ASSERTION);
        }
    }



    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    const char8 *vendorSyndrome;
    const char8 *memoryArrayErrorAddress;
    const char8 *deviceErrorAddress;
    const char8 *errorResolution;

    // Get other strings
    {
        // Get string for Vendor syndrome
        {
            if (entry->vendorSyndrome == DMI_BITS64_MEMORY_ERROR_INFORMATION_VENDOR_SYNDROME_UNKNOWN)
            {
                vendorSyndrome = "Unknown";
            }
            else
            {
                vendorSyndrome = mprintf("0x%08X", entry->vendorSyndrome);
            }
        }



        // Get string for Memory array error address
        {
            if (entry->memoryArrayErrorAddress == DMI_BITS64_MEMORY_ERROR_INFORMATION_MEMORY_ARRAY_ERROR_ADDRESS_UNKNOWN)
            {
                memoryArrayErrorAddress = "Unknown";
            }
            else
            {
                memoryArrayErrorAddress = mprintf("0x%016llX", entry->memoryArrayErrorAddress);
            }
        }



        // Get string for Device error address
        {
            if (entry->deviceErrorAddress == DMI_BITS64_MEMORY_ERROR_INFORMATION_DEVICE_ERROR_ADDRESS_UNKNOWN)
            {
                deviceErrorAddress = "Unknown";
            }
            else
            {
                deviceErrorAddress = mprintf("0x%016llX", entry->deviceErrorAddress);
            }
        }



        // Get string for Error resolution
        {
            if (entry->errorResolution == DMI_BITS64_MEMORY_ERROR_INFORMATION_ERROR_RESOLUTION_UNKNOWN)
            {
                errorResolution = "Unknown";
            }
            else
            {
                errorResolution = mprintf("0x%08X", entry->errorResolution);
            }
        }
    }



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                 strdup(enumToFullString(entry->header.type)),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                     mprintf("0x%04X", entry->header.handle),           DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error type",                 strdup(enumToFullString(entry->errorType)),        DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error granularity",          strdup(enumToFullString(entry->errorGranularity)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error operation",            strdup(enumToFullString(entry->errorOperation)),   DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Vendor syndrome",            vendorSyndrome,                                    DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Memory array error address", memoryArrayErrorAddress,                           DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device error address",       deviceErrorAddress,                                DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Error resolution",           errorResolution,                                   DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->description.id = %u",     entry->description.id));
            UEFI_LVVV(("entry->type           = %s",     enumToFullString(entry->type)));
            UEFI_LVVV(("entry->address        = 0x%08X", entry->address));
            UEFI_LVVV(("entry->addressType    = %s",     enumToFullString(entry->addressType)));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->description.id == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->type           == DmiManagementDeviceType::OTHER,        NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->address        == 0x00000000,                            NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->addressType    == DmiManagementDeviceAddressType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceEntry), NgosStatus::ASSERTION);
        }
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



    // Add Device Manager entry
    {
        DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), entryName);

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",   strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",       mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",  description,                                  DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",         strdup(enumToFullString(entry->type)),        DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Address",      mprintf("0x%08X", entry->address),            DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Address type", strdup(enumToFullString(entry->addressType)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->description.id         = %u",     entry->description.id));
            UEFI_LVVV(("entry->managementDeviceHandle = 0x%04X", entry->managementDeviceHandle));
            UEFI_LVVV(("entry->componentHandle        = 0x%04X", entry->componentHandle));
            UEFI_LVVV(("entry->thresholdHandle        = 0x%04X", entry->thresholdHandle));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->description.id         == 1,      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->managementDeviceHandle == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->componentHandle        == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->thresholdHandle        == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceComponentEntry), NgosStatus::ASSERTION);
        }
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",               strdup(enumToFullString(entry->header.type)),     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                   mprintf("0x%04X", entry->header.handle),          DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Description",              description,                                      DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Management device handle", mprintf("0x%04X", entry->managementDeviceHandle), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Component handle",         mprintf("0x%04X", entry->componentHandle),        DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Threshold handle",         thresholdHandle,                                  DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->lowerThresholdNonCritical    = %u", entry->lowerThresholdNonCritical));
            UEFI_LVVV(("entry->upperThresholdNonCritical    = %u", entry->upperThresholdNonCritical));
            UEFI_LVVV(("entry->lowerThresholdCritical       = %u", entry->lowerThresholdCritical));
            UEFI_LVVV(("entry->upperThresholdCritical       = %u", entry->upperThresholdCritical));
            UEFI_LVVV(("entry->lowerThresholdNonRecoverable = %u", entry->lowerThresholdNonRecoverable));
            UEFI_LVVV(("entry->upperThresholdNonRecoverable = %u", entry->upperThresholdNonRecoverable));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->lowerThresholdNonCritical    == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->upperThresholdNonCritical    == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->lowerThresholdCritical       == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->upperThresholdCritical       == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->lowerThresholdNonRecoverable == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->upperThresholdNonRecoverable == 0, NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceThresholdDataEntry), NgosStatus::ASSERTION);
        }
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                      strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                          mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold non-critical",    lowerThresholdNonCritical,                    DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold non-critical",    upperThresholdNonCritical,                    DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold critical",        lowerThresholdCritical,                       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold critical",        upperThresholdCritical,                       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Lower threshold non-recoverable", lowerThresholdNonRecoverable,                 DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Upper threshold non-recoverable", upperThresholdNonRecoverable,                 DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->powerUnitGroup                                     = %u",     entry->powerUnitGroup));
            UEFI_LVVV(("entry->location.id                                        = %u",     entry->location.id));
            UEFI_LVVV(("entry->deviceName.id                                      = %u",     entry->deviceName.id));
            UEFI_LVVV(("entry->manufacturer.id                                    = %u",     entry->manufacturer.id));
            UEFI_LVVV(("entry->serialNumber.id                                    = %u",     entry->serialNumber.id));
            UEFI_LVVV(("entry->assetTagNumber.id                                  = %u",     entry->assetTagNumber.id));
            UEFI_LVVV(("entry->modelPartNumber.id                                 = %u",     entry->modelPartNumber.id));
            UEFI_LVVV(("entry->revisionLevel.id                                   = %u",     entry->revisionLevel.id));
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
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->powerUnitGroup                                     == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->location.id                                        == 1,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceName.id                                      == 2,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->manufacturer.id                                    == 3,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->serialNumber.id                                    == 4,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->assetTagNumber.id                                  == 5,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->modelPartNumber.id                                 == 6,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->revisionLevel.id                                   == 7,                                                  NgosStatus::ASSERTION); // Commented due to value variation
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

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemPowerSupplyEntry), NgosStatus::ASSERTION);
        }
    }



    const char8 *entryName       = nullptr;
    const char8 *location        = "N/A";
    const char8 *deviceName      = "N/A";
    const char8 *manufacturer    = "N/A";
    const char8 *serialNumber    = "N/A";
    const char8 *assetTagNumber  = "N/A";
    const char8 *modelPartNumber = "N/A";
    const char8 *revisionLevel   = "N/A";

    // Get strings
    {
        if (
            entry->location.id
            ||
            entry->deviceName.id
            ||
            entry->manufacturer.id
            ||
            entry->serialNumber.id
            ||
            entry->assetTagNumber.id
            ||
            entry->modelPartNumber.id
            ||
            entry->revisionLevel.id
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
                    if (stringId == entry->deviceName)
                    {
                        deviceName = begin;
                        entryName  = deviceName;
                    }
                    else
                    if (stringId == entry->manufacturer)
                    {
                        manufacturer = begin;
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        serialNumber = begin;
                    }
                    else
                    if (stringId == entry->assetTagNumber)
                    {
                        assetTagNumber = begin;
                    }
                    else
                    if (stringId == entry->modelPartNumber)
                    {
                        modelPartNumber = begin;
                    }
                    else
                    if (stringId == entry->revisionLevel)
                    {
                        revisionLevel = begin;
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                 strdup(enumToFullString(entry->header.type)),                                                                                     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                     mprintf("0x%04X", entry->header.handle),                                                                                          DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Power unit group",           powerUnitGroup,                                                                                                                   DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Location",                   location,                                                                                                                         DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device name",                deviceName,                                                                                                                       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Manufacturer",               manufacturer,                                                                                                                     DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Serial number",              serialNumber,                                                                                                                     DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Asset tag number",           assetTagNumber,                                                                                                                   DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Model part number",          modelPartNumber,                                                                                                                  DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Revision level",             revisionLevel,                                                                                                                    DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Maximum power capacity",     maxPowerCapacity,                                                                                                                 DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Hot replaceable",            entry->powerSupplyCharacteristics.hotReplaceable ? "Yes" : "No",                                                                  DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Present",                    entry->powerSupplyCharacteristics.present ? "Yes" : "No",                                                                         DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Unplugged",                  entry->powerSupplyCharacteristics.unplugged ? "Yes" : "No",                                                                       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input voltage range switch", strdup(enumToFullString((DmiSystemPowerSupplyInputVoltageRangeSwitch)entry->powerSupplyCharacteristics.inputVoltageRangeSwitch)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Status",                     strdup(enumToFullString((DmiSystemPowerSupplyStatus)entry->powerSupplyCharacteristics.status)),                                   DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Type",                       strdup(enumToFullString((DmiSystemPowerSupplyType)entry->powerSupplyCharacteristics.type)),                                       DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input voltage probe handle", inputVoltageProbeHandle,                                                                                                          DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Cooling device handle",      coolingDeviceHandle,                                                                                                              DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Input current probe handle", inputCurrentProbeHandle,                                                                                                          DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

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
        // Output variables
        {
            UEFI_LVVV(("entry->numberOfAdditionalInformationEntries = %u", entry->numberOfAdditionalInformationEntries));



            // entry->additionalInformationEntries:
            {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                UEFI_LVVV(("entry->additionalInformationEntries:"));
                UEFI_LVVV(("-------------------------------------"));

                DmiAdditionalInformation *curInfo = &entry->additionalInformationEntries[0];

                for (good_i64 i = 0; i < entry->numberOfAdditionalInformationEntries; ++i)
                {
                    UEFI_LVVV(("curInfo->entryLength      = %u",     curInfo->entryLength));
                    UEFI_LVVV(("curInfo->referencedHandle = 0x%04X", curInfo->referencedHandle));
                    UEFI_LVVV(("curInfo->referencedOffset = %u",     curInfo->referencedOffset));
                    UEFI_LVVV(("curInfo->string.id        = %u",     curInfo->string.id));
                    UEFI_LVVV(("curInfo->value[0]         = 0x%02X", curInfo->value[0]));

                    curInfo = (DmiAdditionalInformation *)((u64)curInfo + curInfo->entryLength);
                }

                UEFI_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->numberOfAdditionalInformationEntries             == 1,      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].entryLength      == 6,      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].referencedHandle == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].referencedOffset == 1,      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].string.id        == 0,      NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->additionalInformationEntries[0].value[0]         == 0x00,   NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiAdditionalInformationEntry) + sizeof(DmiAdditionalInformation), NgosStatus::ASSERTION);
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",                               strdup(enumToFullString(entry->header.type)),               DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                                   mprintf("0x%04X", entry->header.handle),                    DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Number of additional information entries", mprintf("%u", entry->numberOfAdditionalInformationEntries), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);



        // Add records for Entries
        {
            DmiAdditionalInformation *curInfo = &entry->additionalInformationEntries[0];

            for (good_i64 i = 0; i < entry->numberOfAdditionalInformationEntries; ++i)
            {
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d length",            i), mprintf("%u",     curInfo->entryLength),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d referenced handle", i), mprintf("0x%04X", curInfo->referencedHandle), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d referenced offset", i), mprintf("%u",     curInfo->referencedOffset), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d string ID",         i), mprintf("%u",     curInfo->string.id),        DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



                // Add records for Entry value
                {
                    u8 valueSize = curInfo->entryLength - sizeof(DmiAdditionalInformation);

                    if (valueSize > 0)
                    {
                        char8 *valueString;

                        UEFI_ASSERT_EXECUTION(Hex::toString(curInfo->value, valueSize, &valueString, VALUE_MAXIMUM_LENGTH + 1, true), NgosStatus::ASSERTION);

                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d value", i), valueString, DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                    }
                    else
                    {
                        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("Entry #%d value", i), "N/A", DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
                    }
                }



                curInfo = (DmiAdditionalInformation *)((u64)curInfo + curInfo->entryLength);
            }
        }



        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (entry->numberOfAdditionalInformationEntries > 0)
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



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("String #%u", stringId.id), begin, DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



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
        // Output variables
        {
            UEFI_LVVV(("entry->referenceDesignation.id                      = %u",     entry->referenceDesignation.id));
            UEFI_LVVV(("entry->deviceTypeAndEnabled.deviceType              = %s",     enumToFullString((DmiOnboardDevicesExtendedDeviceType)entry->deviceTypeAndEnabled.deviceType)));
            UEFI_LVVV(("entry->deviceTypeAndEnabled.enabled                 = %u",     entry->deviceTypeAndEnabled.enabled));
            UEFI_LVVV(("entry->deviceTypeAndEnabled.value8                  = 0x%02X", entry->deviceTypeAndEnabled.value8));
            UEFI_LVVV(("entry->deviceTypeInstance                           = %u",     entry->deviceTypeInstance));
            UEFI_LVVV(("entry->segmentGroupNumber                           = %u",     entry->segmentGroupNumber));
            UEFI_LVVV(("entry->busNumber                                    = %u",     entry->busNumber));
            UEFI_LVVV(("entry->functionNumberAndDeviceNumber.functionNumber = %u",     entry->functionNumberAndDeviceNumber.functionNumber));
            UEFI_LVVV(("entry->functionNumberAndDeviceNumber.deviceNumber   = %u",     entry->functionNumberAndDeviceNumber.deviceNumber));
            UEFI_LVVV(("entry->functionNumberAndDeviceNumber.value8         = 0x%02X", entry->functionNumberAndDeviceNumber.value8));
        }



        // Check variables
        {
            // UEFI_TEST_ASSERT(entry->referenceDesignation.id                      == 1,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceTypeAndEnabled.deviceType              == DmiOnboardDevicesExtendedDeviceType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceTypeAndEnabled.enabled                 == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceTypeAndEnabled.value8                  == 0x00,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->deviceTypeInstance                           == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->segmentGroupNumber                           == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->busNumber                                    == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->functionNumberAndDeviceNumber.functionNumber == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->functionNumberAndDeviceNumber.deviceNumber   == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(entry->functionNumberAndDeviceNumber.value8         == 0x00,                                       NgosStatus::ASSERTION); // Commented due to value variation

            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesExtendedEntry), NgosStatus::ASSERTION);
        }
    }



    const char8 *entryName            = nullptr;
    const char8 *referenceDesignation = "N/A";

    // Get strings
    {
        if (entry->referenceDesignation.id)
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



                    if (stringId == entry->referenceDesignation)
                    {
                        referenceDesignation = begin;
                        entryName            = referenceDesignation;
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

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type",            strdup(enumToFullString(entry->header.type)),                                                          DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",                mprintf("0x%04X", entry->header.handle),                                                               DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Reference designation", referenceDesignation,                                                                                  DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type",           strdup(enumToFullString((DmiOnboardDevicesExtendedDeviceType)entry->deviceTypeAndEnabled.deviceType)), DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Enabled",               entry->deviceTypeAndEnabled.enabled ? "Yes" : "No",                                                    DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device type instance",  mprintf("%u", entry->deviceTypeInstance),                                                              DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Segment group number",  mprintf("%u", entry->segmentGroupNumber),                                                              DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Bus number",            mprintf("%u", entry->busNumber),                                                                       DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Function number",       mprintf("%u", entry->functionNumberAndDeviceNumber.functionNumber),                                    DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Device number",         mprintf("%u", entry->functionNumberAndDeviceNumber.deviceNumber),                                      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DeviceManagerDMI::saveDmiInactiveEntry(DmiInactiveEntry *entry)
{
    UEFI_LT((" | entry = 0x%p", entry));

    UEFI_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            // Nothing
        }



        // Check variables
        {
            UEFI_TEST_ASSERT(entry->header.length >= sizeof(DmiInactiveEntry), NgosStatus::ASSERTION);
        }
    }



    DeviceManagerEntryDMI *deviceManagerEntry = new DeviceManagerEntryDMI(entry->header.type, entry->header.handle, deviceManagerImageFromDmiEntryType(entry->header.type), enumToHumanString(entry->header.type));

    // Add Device Manager entry
    {
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Entry type", strdup(enumToFullString(entry->header.type)), DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Handle",     mprintf("0x%04X", entry->header.handle),      DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("No data",    "",                                           DeviceManagerMode::BASIC),  NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (
            ((u8 *)entry)[entry->header.length]     != 0
            ||
            ((u8 *)entry)[entry->header.length + 1] != 0
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



                    UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord(mprintf("String #%u", stringId.id), begin, DeviceManagerMode::EXPERT), NgosStatus::ASSERTION);



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
    }



    return NgosStatus::OK;
}
