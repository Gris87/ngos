#include "dmi.h"                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmimemorydeviceentry.h>                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/utils.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/memory/memory.h>                                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/string/utils.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/uuid/utils.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#ifdef UEFI_APPLICATION // Defined in pro file                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/uefibase/uefi/uefi.h>                                                                                                                                                          // Colorize: green
#else                                                                                                                                                                                                    // Colorize: green
#include <com/ngos/kernel/other/brk/brk.h>                                                                                                                                                               // Colorize: green
#include <com/ngos/kernel/other/ioremap/ioremap.h>                                                                                                                                                       // Colorize: green
#include <com/ngos/kernel/other/uefi/uefi.h>                                                                                                                                                             // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DmiVersion                                      DMI::sVersion;                                                                                                                                            // Colorize: green
good_U16                                        DMI::sNumberOfSmbiosStructures;                                                                                                                          // Colorize: green
good_U8                                        *DMI::sStructureTableAddress;                                                                                                                              // Colorize: green
good_U32                                        DMI::sStructureTableLength;                                                                                                                              // Colorize: green
good_U16                                        DMI::sSystemPhysicalMemoryArrayHandle;                                                                                                                   // Colorize: green
good_I64                                        DMI::sSystemPhysicalMemoryArrayCapacity;                                                                                                                 // Colorize: green
good_I64                                        DMI::sTotalAmountOfMemory;                                                                                                                                // Colorize: green
good_I64                                        DMI::sNumberOfInstalledMemoryDevices;                                                                                                                     // Colorize: green
ArrayList<DmiMemoryDeviceEntry *>               DMI::sMemoryDeviceEntries;                                                                                                                               // Colorize: green
ArrayList<DmiMemoryDeviceMappedAddressEntry *>  DMI::sMemoryDeviceMappedAddressEntries;                                                                                                                  // Colorize: green
ArrayList<DmiMemoryDevice>                      DMI::sMemoryDevices;                                                                                                                                     // Colorize: green
const good_Char8*                               DMI::sIdentities[(u64)DmiIdentity::MAXIMUM];                                                                                                             // Colorize: green
Uuid*                                           DMI::sUuids[(u64)DmiStoredUuid::MAXIMUM];                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::init()                                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Init from SMBIOS config                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        UefiSmbios3ConfigurationTable *smbios3 = UEFI::getSmbios3Config();                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (smbios3 != nullptr)                                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
#ifdef UEFI_APPLICATION // Defined in pro file                                                                                                                                                           // Colorize: green
            COMMON_ASSERT_EXECUTION(initFromSmbios3(smbios3), NgosStatus::ASSERTION);                                                                                                                    // Colorize: green
#else                                                                                                                                                                                                    // Colorize: green
            UefiSmbios3ConfigurationTable *smbios3Mapped;                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping(reinterpret_cast<address_t>(smbios3), sizeof(UefiSmbios3ConfigurationTable), reinterpret_cast<void **>(&smbios3Mapped)), NgosStatus::ASSERTION); // Colorize: green
            COMMON_ASSERT_EXECUTION(initFromSmbios3(smbios3Mapped),                                                                                                                   NgosStatus::ASSERTION); // Colorize: green
            COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping(reinterpret_cast<address_t>(smbios3Mapped), sizeof(UefiSmbios3ConfigurationTable)),                                   NgosStatus::ASSERTION); // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            UefiSmbiosConfigurationTable *smbios = UEFI::getSmbiosConfig();                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (smbios != nullptr)                                                                                                                                                                       // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
#ifdef UEFI_APPLICATION // Defined in pro file                                                                                                                                                           // Colorize: green
                COMMON_ASSERT_EXECUTION(initFromSmbios(smbios), NgosStatus::ASSERTION);                                                                                                                  // Colorize: green
#else                                                                                                                                                                                                    // Colorize: green
                UefiSmbiosConfigurationTable *smbiosMapped;                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping(reinterpret_cast<address_t>(smbios), sizeof(UefiSmbiosConfigurationTable), reinterpret_cast<void **>(&smbiosMapped)), NgosStatus::ASSERTION); // Colorize: green
                COMMON_ASSERT_EXECUTION(initFromSmbios(smbiosMapped),                                                                                                                  NgosStatus::ASSERTION); // Colorize: green
                COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping(reinterpret_cast<address_t>(smbiosMapped), sizeof(UefiSmbiosConfigurationTable)),                                  NgosStatus::ASSERTION); // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LF(("DMI not present"));                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                return NgosStatus::NOT_FOUND;                                                                                                                                                            // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Iterate DMI entries and store memory devices                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
#ifdef UEFI_APPLICATION // Defined in pro file                                                                                                                                                           // Colorize: green
        COMMON_ASSERT_EXECUTION(iterateDmiEntries(sStructureTableAddress, decodeDmiEntry), NgosStatus::ASSERTION);                                                          // Colorize: green
        COMMON_ASSERT_EXECUTION(storeDmiMemoryDevices(),                                   NgosStatus::ASSERTION);                                                          // Colorize: green
#else                                                                                                                                                                                                    // Colorize: green
        good_U8 *buf;                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping(reinterpret_cast<address_t>(sStructureTableAddress), sStructureTableLength, reinterpret_cast<void **>(&buf)), NgosStatus::ASSERTION);                                        // Colorize: green
        COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, decodeDmiEntry),                                                                   NgosStatus::ASSERTION);                                        // Colorize: green
        COMMON_ASSERT_EXECUTION(storeDmiMemoryDevices(),                                                                                  NgosStatus::ASSERTION);                                        // Colorize: green
        COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping(reinterpret_cast<address_t>(buf), sStructureTableLength),                     NgosStatus::ASSERTION);                                        // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Display DMI info                                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LV(("SMBIOS version is %u.%u",                                                                                                                                                            // Colorize: green
                    sVersion.major,                                                                                                                                                                      // Colorize: green
                    sVersion.minor                                                                                                                                                               // Colorize: green
        ));                                                                                                                                                                                              // Colorize: green
        COMMON_LV(("DMI: %s %s, BIOS %s %s %s",                                                                                                                                                          // Colorize: green
                    sIdentities[static_cast<enum_t>(DmiIdentity::SYSTEM_MANUFACTURER)],                                                                                                                  // Colorize: green
                    sIdentities[static_cast<enum_t>(DmiIdentity::SYSTEM_PRODUCT_NAME)],                                                                                                                  // Colorize: green
                    sIdentities[static_cast<enum_t>(DmiIdentity::BIOS_VENDOR)],                                                                                                                          // Colorize: green
                    sIdentities[static_cast<enum_t>(DmiIdentity::BIOS_VERSION)],                                                                                                                         // Colorize: green
                    sIdentities[static_cast<enum_t>(DmiIdentity::BIOS_RELEASE_DATE)]                                                                                                                     // Colorize: green
        ));                                                                                                                                                                                              // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVVV(("sVersion.major                     = %u",     sVersion.major));                                                                                                                    // Colorize: green
        COMMON_LVVV(("sVersion.minor                     = %u",     sVersion.minor));                                                                                                                    // Colorize: green
        COMMON_LVVV(("sVersion.doc                       = %u",     sVersion.doc));                                                                                                                      // Colorize: green
        COMMON_LVVV(("sVersion.value32                   = 0x%08X", sVersion.value32));                                                                                                                  // Colorize: green
        COMMON_LVVV(("sNumberOfSmbiosStructures          = %u",     sNumberOfSmbiosStructures));                                                                                                         // Colorize: green
        COMMON_LVVV(("sStructureTableAddress             = 0x%p",   sStructureTableAddress));                                                                                                            // Colorize: green
        COMMON_LVVV(("sStructureTableLength              = %u",     sStructureTableLength));                                                                                                             // Colorize: green
        COMMON_LVVV(("sSystemPhysicalMemoryArrayHandle   = 0x%04X", sSystemPhysicalMemoryArrayHandle));                                                                                                  // Colorize: green
        COMMON_LVVV(("sSystemPhysicalMemoryArrayCapacity = %s",     bytesToString(sSystemPhysicalMemoryArrayCapacity)));                                                                                 // Colorize: green
        COMMON_LVVV(("sTotalAmountOfMemory               = %s",     bytesToString(sTotalAmountOfMemory)));                                                                                               // Colorize: green
        COMMON_LVVV(("sNumberOfInstalledMemoryDevices    = %d",     sNumberOfInstalledMemoryDevices));                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // sMemoryDeviceEntries:                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
            COMMON_LVVV(("sMemoryDeviceEntries:"));                                                                                                                                                      // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 i = 0; i < sMemoryDeviceEntries.getSize(); ++i)                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                DmiMemoryDeviceEntry *device = sMemoryDeviceEntries.at(i);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("#%-3d: 0x%p | 0x%04X | 0x%04X", i, device, device->header.handle, device->memoryArrayHandle));                                                                             // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // sMemoryDeviceMappedAddressEntries:                                                                                                                                                            // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
            COMMON_LVVV(("sMemoryDeviceMappedAddressEntries:"));                                                                                                                                         // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 i = 0; i < sMemoryDeviceMappedAddressEntries.getSize(); ++i)                                                                                                                   // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                DmiMemoryDeviceMappedAddressEntry *device = sMemoryDeviceMappedAddressEntries.at(i);                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("#%-3d: 0x%p | 0x%04X | 0x%04X", i, device, device->header.handle, device->memoryDeviceHandle));                                                                            // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // sMemoryDevices:                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
            COMMON_LVVV(("sMemoryDevices:"));                                                                                                                                                            // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 i = 0; i < sMemoryDevices.getSize(); ++i)                                                                                                                                      // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                const DmiMemoryDevice &device = sMemoryDevices.at(i);                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                char8 startBuffer[11];                                                                                                                                                                   // Colorize: green
                char8 endBuffer[11];                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_ASSERT_EXECUTION(bytesToString(device.start, startBuffer, sizeof(startBuffer)), NgosStatus::ASSERTION);                                                                           // Colorize: green
                COMMON_ASSERT_EXECUTION(bytesToString(device.end,   endBuffer,   sizeof(endBuffer)),   NgosStatus::ASSERTION);                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("#%-3d: %s | %u MHz | %-5s | %5s - %-5s | %s | %s | %s | %s",                                                                                                               // Colorize: green
                                i,                                                                                                                                                                       // Colorize: green
                                enumToFullString(device.memoryType),                                                                                                                                     // Colorize: green
                                device.speed,                                                                                                                                                            // Colorize: green
                                bytesToString(device.size),                                                                                                                                              // Colorize: green
                                startBuffer,                                                                                                                                                             // Colorize: green
                                endBuffer,                                                                                                                                                               // Colorize: green
                                stringToString(device.deviceLocator),                                                                                                                                    // Colorize: green
                                stringToString(device.manufacturer),                                                                                                                                     // Colorize: green
                                stringToString(device.serialNumber),                                                                                                                                     // Colorize: green
                                stringToString(device.partNumber)                                                                                                                                        // Colorize: green
                ));                                                                                                                                                                                      // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // sIdentities:                                                                                                                                                                                  // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
            COMMON_LVVV(("sIdentities:"));                                                                                                                                                               // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 i = 0; i < static_cast<good_I64>(DmiIdentity::MAXIMUM); ++i)                                                                                                                   // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sIdentities[i] != nullptr)                                                                                                                                                           // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("%-36s: 0x%p | %s", enumToFullString(static_cast<DmiIdentity>(i)), sIdentities[i], sIdentities[i]));                                                                                 // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("%-36s: 0x%p", enumToFullString(static_cast<DmiIdentity>(i)), sIdentities[i]));                                                                                                      // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // sUuids:                                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
            COMMON_LVVV(("sUuids:"));                                                                                                                                                                    // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 i = 0; i < static_cast<good_I64>(DmiStoredUuid::MAXIMUM); ++i)                                                                                                                 // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("%-11s: %s", enumToFullString(static_cast<DmiStoredUuid>(i)), uuidToString(sUuids[i])));                                                                                    // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_LVVV(("-------------------------------------"));                                                                                                                                      // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(sVersion.major                                              == 2,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sVersion.minor                                              == 8,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sVersion.doc                                                == 0,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sVersion.value32                                            == 0x00020800,               NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sNumberOfSmbiosStructures                                   == 9,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sStructureTableAddress                                      != nullptr,                  NgosStatus::ASSERTION);                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(sStructureTableLength                                       == 404,                      NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sSystemPhysicalMemoryArrayHandle                            == 0x1000,                   NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sSystemPhysicalMemoryArrayCapacity                          == GB,                       NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sTotalAmountOfMemory                                        == GB,                       NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sNumberOfInstalledMemoryDevices                             == 1,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDeviceEntries.getSize()                              == 1,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDeviceEntries.at(0)                                  != nullptr,                  NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDeviceEntries.at(0)->header.handle                   == 0x1100,                   NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDeviceEntries.at(0)->memoryArrayHandle               == 0x1000,                   NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDeviceMappedAddressEntries.getSize()                 == 0,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDevices.getSize()                                    == 1,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDevices.at(0).memoryType                             == DmiMemoryDeviceType::RAM, NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDevices.at(0).speed                                  == 0,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDevices.at(0).size                                   == GB,                       NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDevices.at(0).start                                  == 0,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDevices.at(0).end                                    == GB,                       NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(strcmp(sMemoryDevices.at(0).deviceLocator, "DIMM 0")        == 0,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(strcmp(sMemoryDevices.at(0).manufacturer, "QEMU")           == 0,                        NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDevices.at(0).serialNumber                           == nullptr,                  NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sMemoryDevices.at(0).partNumber                             == nullptr,                  NgosStatus::ASSERTION);                                                                     // Colorize: green
        COMMON_TEST_ASSERT(static_cast<enum_t>(DmiIdentity::MAXIMUM)                   == 7,                        NgosStatus::ASSERTION);                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(strcmp(sIdentities[0], "EFI Development Kit II / OVMF")     == 0,                        NgosStatus::ASSERTION);                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(strcmp(sIdentities[1], "0.0.0")                             == 0,                        NgosStatus::ASSERTION);                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(strcmp(sIdentities[2], "02/06/2015")                        == 0,                        NgosStatus::ASSERTION);                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(strcmp(sIdentities[3], "QEMU")                              == 0,                        NgosStatus::ASSERTION);                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(strcmp(sIdentities[4], "Standard PC (i440FX + PIIX, 1996)") == 0,                        NgosStatus::ASSERTION);                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(sIdentities[5]                                              == nullptr,                  NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(sIdentities[6]                                              == nullptr,                  NgosStatus::ASSERTION);                                                      // Colorize: green
        COMMON_TEST_ASSERT(static_cast<enum_t>(DmiStoredUuid::MAXIMUM)                 == 1,                        NgosStatus::ASSERTION);                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(sUuids[0]                                                   != nullptr,                  NgosStatus::ASSERTION);                                                                                         // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data1                                         == 0x9FAE0773,               NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data2                                         == 0xF53F,                   NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data3                                         == 0x4A15,                   NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data4                                         == 0x8A,                     NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data5                                         == 0x11,                     NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data6[0]                                      == 0xED,                     NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data6[1]                                      == 0x76,                     NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data6[2]                                      == 0xA1,                     NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data6[3]                                      == 0x0F,                     NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data6[4]                                      == 0x4E,                     NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
        // COMMON_TEST_ASSERT(sUuids[0]->data6[5]                                      == 0x5B,                     NgosStatus::ASSERTION); // Commented because different each time                                                 // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::iterateDmiEntries(good_U8 *buf, process_dmi_entry processDmiEntry)                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | buf = 0x%p, processDmiEntry = 0x%p", buf, processDmiEntry));                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(buf             != nullptr, "buf is null",             NgosStatus::ASSERTION);                                                                                                         // Colorize: green
    COMMON_ASSERT(processDmiEntry != nullptr, "processDmiEntry is null", NgosStatus::ASSERTION);                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    good_I64  i   = 0;                                                                                                                                                                                   // Colorize: green
    good_U8  *cur = buf;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Iterate over DMI entries and process them                                                                                                                                                         // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        while (                                                                                                                                                                                          // Colorize: green
               sNumberOfSmbiosStructures == 0                                                                                                                                                            // Colorize: green
               ||                                                                                                                                                                                        // Colorize: green
               i < sNumberOfSmbiosStructures                                                                                                                                                             // Colorize: green
              )                                                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            DmiEntryHeader *dmiEntryHeader = reinterpret_cast<DmiEntryHeader *>(cur);                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Display DMI entry info                                                                                                                                                                    // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVV(("Processing DMI header at address 0x%p", dmiEntryHeader));                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("dmiEntryHeader->type   = %s",     enumToFullString(dmiEntryHeader->type)));                                                                                                // Colorize: green
                COMMON_LVVV(("dmiEntryHeader->length = %u",     dmiEntryHeader->length));                                                                                                                // Colorize: green
                COMMON_LVVV(("dmiEntryHeader->handle = 0x%04X", dmiEntryHeader->handle));                                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Jump to next entry                                                                                                                                                                        // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                cur += dmiEntryHeader->length;                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                // We are getting total DMI entry size until we met 2 zeros in buffer that let us avoid issues on decoding                                                                               // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    do                                                                                                                                                                                   // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        if (                                                                                                                                                                             // Colorize: green
                            cur[0] == 0                                                                                                                                                                  // Colorize: green
                            &&                                                                                                                                                                           // Colorize: green
                            cur[1] == 0                                                                                                                                                                  // Colorize: green
                           )                                                                                                                                                                             // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            break;                                                                                                                                                                       // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        ++cur;                                                                                                                                                                           // Colorize: green
                    } while(true);                                                                                                                                                                       // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                cur += 2;                                                                                                                                                                                // Colorize: green
                ++i;                                                                                                                                                                                     // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (dmiEntryHeader->type == DmiEntryType::END_OF_TABLE)                                                                                                                                      // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                break;                                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_ASSERT_EXECUTION(processDmiEntry(dmiEntryHeader), NgosStatus::ASSERTION);                                                                                                             // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Validation                                                                                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("sNumberOfSmbiosStructures = %d",   sNumberOfSmbiosStructures));                                                                                                                // Colorize: green
            COMMON_LVVV(("i                         = %d",   i));                                                                                                                                        // Colorize: green
            COMMON_LVVV(("buf                       = 0x%p", buf));                                                                                                                                      // Colorize: green
            COMMON_LVVV(("cur                       = 0x%p", cur));                                                                                                                                      // Colorize: green
            COMMON_LVVV(("sStructureTableLength     = %u",   sStructureTableLength));                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(sNumberOfSmbiosStructures == 0 || cur == buf + sStructureTableLength, NgosStatus::ASSERTION);                                                                             // Colorize: green
            COMMON_TEST_ASSERT(sNumberOfSmbiosStructures == 0 || i   == sNumberOfSmbiosStructures,   NgosStatus::ASSERTION);                                                                             // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
const DmiVersion& DMI::getVersion()                                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sVersion;                                                                                                                                                                                     // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_U8* DMI::getStructureTableAddress()                                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sStructureTableAddress;                                                                                                                                                                       // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_I64 DMI::getSystemPhysicalMemoryArrayCapacity()                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sSystemPhysicalMemoryArrayCapacity;                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_I64 DMI::getTotalAmountOfMemory()                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sTotalAmountOfMemory;                                                                                                                                                                         // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_I64 DMI::getNumberOfInstalledMemoryDevices()                                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sNumberOfInstalledMemoryDevices;                                                                                                                                                              // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
const ArrayList<DmiMemoryDevice>& DMI::getMemoryDevices()                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sMemoryDevices;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
const good_Char8* DMI::getIdentity(DmiIdentity id)                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | id = %u", id)); // Commented to avoid too frequent logs                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sIdentities[static_cast<enum_t>(id)];                                                                                                                                                         // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
Uuid* DMI::getUuid(DmiStoredUuid id)                                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | id = %u", id)); // Commented to avoid too frequent logs                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sUuids[static_cast<enum_t>(id)];                                                                                                                                                              // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::initFromSmbios3(UefiSmbios3ConfigurationTable *smbios3)                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | smbios3 = 0x%p", smbios3));                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(smbios3 != nullptr, "smbios3 is null", NgosStatus::ASSERTION);                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVVV(("smbios3->anchor                      = %.5s", smbios3->anchor));                                                                                                                   // Colorize: green
        COMMON_LVVV(("smbios3->entryPointStructureChecksum = %u",   smbios3->entryPointStructureChecksum));                                                                                              // Colorize: green
        COMMON_LVVV(("smbios3->entryPointLength            = %u",   smbios3->entryPointLength));                                                                                                         // Colorize: green
        COMMON_LVVV(("smbios3->majorVersion                = %u",   smbios3->majorVersion));                                                                                                             // Colorize: green
        COMMON_LVVV(("smbios3->minorVersion                = %u",   smbios3->minorVersion));                                                                                                             // Colorize: green
        COMMON_LVVV(("smbios3->docRevision                 = %u",   smbios3->docRevision));                                                                                                              // Colorize: green
        COMMON_LVVV(("smbios3->entryPointRevision          = %u",   smbios3->entryPointRevision));                                                                                                       // Colorize: green
        COMMON_LVVV(("smbios3->structureTableMaximumSize   = %u",   smbios3->structureTableMaximumSize));                                                                                                // Colorize: green
        COMMON_LVVV(("smbios3->structureTableAddress       = 0x%p", smbios3->structureTableAddress));                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_TEST_ASSERT((*reinterpret_cast<good_U64 *>(smbios3->anchor) & 0x000000FFFFFFFFFF) == SMBIOS_3_ANCHOR,                                                                    NgosStatus::ASSERTION);                 // Colorize: green
        COMMON_TEST_ASSERT(smbios3->entryPointStructureChecksum                                  == checksum(smbios3, smbios3->entryPointLength, smbios3->entryPointStructureChecksum), NgosStatus::ASSERTION);                 // Colorize: green
        COMMON_TEST_ASSERT(smbios3->entryPointLength                                             == 24,                                                                                 NgosStatus::ASSERTION);                 // Colorize: green
        COMMON_TEST_ASSERT(smbios3->majorVersion                                                 == 3,                                                                                  NgosStatus::ASSERTION);                 // Colorize: green
        COMMON_TEST_ASSERT(smbios3->minorVersion                                                 == 3,                                                                                  NgosStatus::ASSERTION);                 // Colorize: green
        COMMON_TEST_ASSERT(smbios3->docRevision                                                  == 0,                                                                                  NgosStatus::ASSERTION);                 // Colorize: green
        COMMON_TEST_ASSERT(smbios3->entryPointRevision                                           == 1,                                                                                  NgosStatus::ASSERTION);                 // Colorize: green
        COMMON_TEST_ASSERT(smbios3->structureTableMaximumSize                                    == 4070,                                                                               NgosStatus::ASSERTION);                 // Colorize: green
        COMMON_TEST_ASSERT(smbios3->structureTableAddress                                        != 0,                                                                                  NgosStatus::ASSERTION);                 // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sVersion.value32       = DMI_VERSION_3(smbios3->majorVersion, smbios3->minorVersion, smbios3->docRevision);                                                                                          // Colorize: green
    sStructureTableAddress = reinterpret_cast<good_U8 *>(smbios3->structureTableAddress);                                                                                                                // Colorize: green
    sStructureTableLength  = smbios3->structureTableMaximumSize;                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::initFromSmbios(UefiSmbiosConfigurationTable *smbios)                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | smbios = 0x%p", smbios));                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(smbios != nullptr, "smbios is null", NgosStatus::ASSERTION);                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVVV(("smbios->anchor                      = %.4s",   &smbios->anchor));                                                                                                                  // Colorize: green
        COMMON_LVVV(("smbios->entryPointStructureChecksum = %u",      smbios->entryPointStructureChecksum));                                                                                             // Colorize: green
        COMMON_LVVV(("smbios->entryPointLength            = %u",      smbios->entryPointLength));                                                                                                        // Colorize: green
        COMMON_LVVV(("smbios->majorVersion                = %u",      smbios->majorVersion));                                                                                                            // Colorize: green
        COMMON_LVVV(("smbios->minorVersion                = %u",      smbios->minorVersion));                                                                                                            // Colorize: green
        COMMON_LVVV(("smbios->maximumStructureSize        = %u",      smbios->maximumStructureSize));                                                                                                    // Colorize: green
        COMMON_LVVV(("smbios->entryPointRevision          = %u",      smbios->entryPointRevision));                                                                                                      // Colorize: green
        COMMON_LVVV(("smbios->formattedArea[0]            = %u",      smbios->formattedArea[0]));                                                                                                        // Colorize: green
        COMMON_LVVV(("smbios->formattedArea[1]            = %u",      smbios->formattedArea[1]));                                                                                                        // Colorize: green
        COMMON_LVVV(("smbios->formattedArea[2]            = %u",      smbios->formattedArea[2]));                                                                                                        // Colorize: green
        COMMON_LVVV(("smbios->formattedArea[3]            = %u",      smbios->formattedArea[3]));                                                                                                        // Colorize: green
        COMMON_LVVV(("smbios->formattedArea[4]            = %u",      smbios->formattedArea[4]));                                                                                                        // Colorize: green
        COMMON_LVVV(("smbios->intermediateAnchor          = %.5s",    smbios->intermediateAnchor));                                                                                                      // Colorize: green
        COMMON_LVVV(("smbios->intermediateChecksum        = %u",      smbios->intermediateChecksum));                                                                                                    // Colorize: green
        COMMON_LVVV(("smbios->structureTableLength        = %u",      smbios->structureTableLength));                                                                                                    // Colorize: green
        COMMON_LVVV(("smbios->structureTableAddress       = 0x%p",    smbios->structureTableAddress));                                                                                                   // Colorize: green
        COMMON_LVVV(("smbios->numberOfSmbiosStructures    = %u",      smbios->numberOfSmbiosStructures));                                                                                                // Colorize: green
        COMMON_LVVV(("smbios->bcdRevision                 = 0x%02X",  smbios->bcdRevision));                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(smbios->anchor                                                                   == SMBIOS_ANCHOR,                                                                                                                                                           NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->entryPointStructureChecksum                                              == checksum(smbios, smbios->entryPointLength, smbios->entryPointStructureChecksum),                                                                                         NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->entryPointLength                                                         == 31,                                                                                                                                                                      NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->majorVersion                                                             == 2,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->minorVersion                                                             == 8,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->maximumStructureSize                                                     == 84,                                                                                                                                                                      NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->entryPointRevision                                                       == 0,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->formattedArea[0]                                                         == 0,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->formattedArea[1]                                                         == 0,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->formattedArea[2]                                                         == 0,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->formattedArea[3]                                                         == 0,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->formattedArea[4]                                                         == 0,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT((*reinterpret_cast<good_U64 *>(smbios->intermediateAnchor) & 0x000000FFFFFFFFFF) == SMBIOS_INTERMEDIATE_ANCHOR,                                                                                                                                              NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->intermediateChecksum                                                     == checksum(&smbios->intermediateAnchor, sizeof(UefiSmbiosConfigurationTable) - OFFSET_OF(UefiSmbiosConfigurationTable, intermediateAnchor), smbios->intermediateChecksum), NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->structureTableLength                                                     == 404,                                                                                                                                                                     NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->structureTableAddress                                                    != 0,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->numberOfSmbiosStructures                                                 == 9,                                                                                                                                                                       NgosStatus::ASSERTION); // Colorize: green
        COMMON_TEST_ASSERT(smbios->bcdRevision                                                              == 0x28,                                                                                                                                                                    NgosStatus::ASSERTION); // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sVersion.value32          = DMI_VERSION(smbios->majorVersion, smbios->minorVersion);                                                                                                                 // Colorize: green
    sNumberOfSmbiosStructures = smbios->numberOfSmbiosStructures;                                                                                                                                        // Colorize: green
    sStructureTableAddress    = reinterpret_cast<good_U8 *>(smbios->structureTableAddress);                                                                                                              // Colorize: green
    sStructureTableLength     = smbios->structureTableLength;                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::decodeDmiEntry(DmiEntryHeader *header)                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | header = 0x%p", header));                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(header != nullptr, "header is null", NgosStatus::ASSERTION);                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (header->type)                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiEntryType::BIOS:                             COMMON_ASSERT_EXECUTION(saveDmiBiosEntry((DmiBiosEntry *)header),                                                   NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::SYSTEM:                           COMMON_ASSERT_EXECUTION(saveDmiSystemEntry((DmiSystemEntry *)header),                                               NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::BASEBOARD:                        COMMON_ASSERT_EXECUTION(saveDmiBaseboardEntry((DmiBaseboardEntry *)header),                                         NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::CHASSIS:                          COMMON_ASSERT_EXECUTION(saveDmiChassisEntry((DmiChassisEntry *)header),                                             NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::PROCESSOR:                        COMMON_ASSERT_EXECUTION(saveDmiProcessorEntry((DmiProcessorEntry *)header),                                         NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::CACHE:                            COMMON_ASSERT_EXECUTION(saveDmiCacheEntry((DmiCacheEntry *)header),                                                 NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::PORT_CONNECTOR:                   COMMON_ASSERT_EXECUTION(saveDmiPortConnectorEntry((DmiPortConnectorEntry *)header),                                 NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::SYSTEM_SLOTS:                     COMMON_ASSERT_EXECUTION(saveDmiSystemSlotsEntry((DmiSystemSlotsEntry *)header),                                     NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::ONBOARD_DEVICES:                  COMMON_ASSERT_EXECUTION(saveDmiOnboardDevicesEntry((DmiOnboardDevicesEntry *)header),                               NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::OEM_STRINGS:                      COMMON_ASSERT_EXECUTION(saveDmiOemStringsEntry((DmiOemStringsEntry *)header),                                       NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::SYSTEM_CONFIGURATION:             COMMON_ASSERT_EXECUTION(saveDmiSystemConfigurationEntry((DmiSystemConfigurationEntry *)header),                     NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::BIOS_LANGUAGE:                    COMMON_ASSERT_EXECUTION(saveDmiBiosLanguageEntry((DmiBiosLanguageEntry *)header),                                   NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::GROUP_ASSOCIATIONS:               COMMON_ASSERT_EXECUTION(saveDmiGroupAssociationsEntry((DmiGroupAssociationsEntry *)header),                         NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::PHYSICAL_MEMORY_ARRAY:            COMMON_ASSERT_EXECUTION(saveDmiPhysicalMemoryArrayEntry((DmiPhysicalMemoryArrayEntry *)header),                     NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::MEMORY_DEVICE:                    COMMON_ASSERT_EXECUTION(saveDmiMemoryDeviceEntry((DmiMemoryDeviceEntry *)header),                                   NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::BITS32_MEMORY_ERROR:              COMMON_ASSERT_EXECUTION(saveDmiBits32MemoryErrorInformationEntry((DmiBits32MemoryErrorInformationEntry *)header),   NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS:      COMMON_ASSERT_EXECUTION(saveDmiMemoryArrayMappedAddressEntry((DmiMemoryArrayMappedAddressEntry *)header),           NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::MEMORY_DEVICE_MAPPED_ADDRESS:     COMMON_ASSERT_EXECUTION(saveDmiMemoryDeviceMappedAddressEntry((DmiMemoryDeviceMappedAddressEntry *)header),         NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::PORTABLE_BATTERY:                 COMMON_ASSERT_EXECUTION(saveDmiPortableBatteryEntry((DmiPortableBatteryEntry *)header),                             NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::SYSTEM_RESET:                     COMMON_ASSERT_EXECUTION(saveDmiSystemResetEntry((DmiSystemResetEntry *)header),                                     NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::HARDWARE_SECURITY:                COMMON_ASSERT_EXECUTION(saveDmiHardwareSecurityEntry((DmiHardwareSecurityEntry *)header),                           NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::VOLTAGE_PROBE:                    COMMON_ASSERT_EXECUTION(saveDmiVoltageProbeEntry((DmiVoltageProbeEntry *)header),                                   NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::COOLING_DEVICE:                   COMMON_ASSERT_EXECUTION(saveDmiCoolingDeviceEntry((DmiCoolingDeviceEntry *)header),                                 NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::TEMPERATURE_PROBE:                COMMON_ASSERT_EXECUTION(saveDmiTemperatureProbeEntry((DmiTemperatureProbeEntry *)header),                           NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::ELECTRICAL_CURRENT_PROBE:         COMMON_ASSERT_EXECUTION(saveDmiElectricalCurrentProbeEntry((DmiElectricalCurrentProbeEntry *)header),               NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::OUT_OF_BAND_REMOTE_ACCESS:        COMMON_ASSERT_EXECUTION(saveDmiOutOfBandRemoteAccessEntry((DmiOutOfBandRemoteAccessEntry *)header),                 NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::SYSTEM_BOOT:                      COMMON_ASSERT_EXECUTION(saveDmiSystemBootEntry((DmiSystemBootEntry *)header),                                       NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::BITS64_MEMORY_ERROR:              COMMON_ASSERT_EXECUTION(saveDmiBits64MemoryErrorInformationEntry((DmiBits64MemoryErrorInformationEntry *)header),   NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::MANAGEMENT_DEVICE:                COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceEntry((DmiManagementDeviceEntry *)header),                           NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::MANAGEMENT_DEVICE_COMPONENT:      COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceComponentEntry((DmiManagementDeviceComponentEntry *)header),         NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::MANAGEMENT_DEVICE_THRESHOLD_DATA: COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceThresholdDataEntry((DmiManagementDeviceThresholdDataEntry *)header), NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::SYSTEM_POWER_SUPPLY:              COMMON_ASSERT_EXECUTION(saveDmiSystemPowerSupplyEntry((DmiSystemPowerSupplyEntry *)header),                         NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::ADDITIONAL:                       COMMON_ASSERT_EXECUTION(saveDmiAdditionalInformationEntry((DmiAdditionalInformationEntry *)header),                 NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::ONBOARD_DEVICES_EXTENDED:         COMMON_ASSERT_EXECUTION(saveDmiOnboardDevicesExtendedEntry((DmiOnboardDevicesExtendedEntry *)header),               NgosStatus::ASSERTION); break; // Colorize: green
        case DmiEntryType::INACTIVE:                         COMMON_ASSERT_EXECUTION(saveDmiInactiveEntry((DmiInactiveEntry *)header),                                           NgosStatus::ASSERTION); break; // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default:                                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVV(("Ignoring DMI entry at address 0x%p with type %s", header, enumToFullString(header->type)));                                                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiBiosEntry(DmiBiosEntry *entry)                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    DmiBiosEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiBiosEntryV21) ? (DmiBiosEntryV21 *)entry : nullptr;                                          // Colorize: green
    DmiBiosEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiBiosEntryV23) ? (DmiBiosEntryV23 *)entry : nullptr;                                          // Colorize: green
    DmiBiosEntryV24 *entryV24 = DMI::getVersion() >= DMI_VERSION(2, 4) && entry->header.length >= sizeof(DmiBiosEntryV24) ? (DmiBiosEntryV24 *)entry : nullptr;                                          // Colorize: green
    DmiBiosEntryV31 *entryV31 = DMI::getVersion() >= DMI_VERSION(3, 1) && entry->header.length >= sizeof(DmiBiosEntryV31) ? (DmiBiosEntryV31 *)entry : nullptr;                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->vendor.id                  = %u",     entry->vendor.id));                                                                                                               // Colorize: green
            COMMON_LVVV(("entry->biosVersion.id             = %u",     entry->biosVersion.id));                                                                                                          // Colorize: green
            COMMON_LVVV(("entry->biosStartingAddressSegment = 0x%04X", entry->biosStartingAddressSegment));                                                                                              // Colorize: green
            COMMON_LVVV(("entry->biosReleaseDate.id         = %u",     entry->biosReleaseDate.id));                                                                                                      // Colorize: green
            COMMON_LVVV(("entry->biosRomSize.value          = 0x%02X", entry->biosRomSize.value));                                                                                                       // Colorize: green
            COMMON_LVVV(("entry->biosRomSize.size()         = %s",     bytesToString(entry->biosRomSize.size())));                                                                                       // Colorize: green
            COMMON_LVVV(("entry->biosCharacteristics        = %s",     flagsToFullString(entry->biosCharacteristics)));                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("entryV21->biosCharacteristicsExtensionBiosReserved = %s", flagsToFullString(entryV21->biosCharacteristicsExtensionBiosReserved)));                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV23 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("entryV23->biosCharacteristicsExtensionSystemReserved = %s", flagsToFullString(entryV23->biosCharacteristicsExtensionSystemReserved)));                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (entryV24 != nullptr)                                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("entryV24->systemBiosMajorRelease                 = %u", entryV24->systemBiosMajorRelease));                                                                        // Colorize: green
                        COMMON_LVVV(("entryV24->systemBiosMinorRelease                 = %u", entryV24->systemBiosMinorRelease));                                                                        // Colorize: green
                        COMMON_LVVV(("entryV24->embeddedControllerFirmwareMajorRelease = %u", entryV24->embeddedControllerFirmwareMajorRelease));                                                        // Colorize: green
                        COMMON_LVVV(("entryV24->embeddedControllerFirmwareMinorRelease = %u", entryV24->embeddedControllerFirmwareMinorRelease));                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        if (entryV31 != nullptr)                                                                                                                                                         // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("entryV31->extendedBiosRomSize.value   = %u",     entryV31->extendedBiosRomSize.value));                                                                        // Colorize: green
                            COMMON_LVVV(("entryV31->extendedBiosRomSize.unit    = %s",     enumToFullString((DmiBiosExtendedRomSizeUnit)entryV31->extendedBiosRomSize.unit)));                           // Colorize: green
                            COMMON_LVVV(("entryV31->extendedBiosRomSize.value16 = 0x%04X", entryV31->extendedBiosRomSize.value16));                                                                      // Colorize: green
                            COMMON_LVVV(("entryV31->extendedBiosRomSize.size()  = %s",     bytesToString(entryV31->extendedBiosRomSize.size())));                                                        // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->vendor.id                  == 1,                                                                     NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->biosVersion.id             == 2,                                                                     NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->biosStartingAddressSegment == 0xE800,                                                                NgosStatus::ASSERTION);  // Colorize: green
            COMMON_TEST_ASSERT(entry->biosReleaseDate.id         == 3,                                                                     NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->biosRomSize.value          == 0,                                                                     NgosStatus::ASSERTION);  // Colorize: green
            COMMON_TEST_ASSERT(entry->biosRomSize.size()         == 64 * KB,                                                               NgosStatus::ASSERTION);  // Colorize: green
            COMMON_TEST_ASSERT(entry->biosCharacteristics        == FLAGS(DmiBiosCharacteristicsFlag::BIOS_CHARACTERISTICS_NOT_SUPPORTED), NgosStatus::ASSERTION);  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entryV21->biosCharacteristicsExtensionBiosReserved == FLAGS(DmiBiosCharacteristicsBiosReservedFlag::NONE), NgosStatus::ASSERTION);  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV23 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->biosCharacteristicsExtensionSystemReserved == FLAGS(                                                                                                    // Colorize: green
                                            DmiBiosCharacteristicsSystemReservedFlag::TARGET_CONTENT_DISTRIBUTION_ENABLED,                                                                               // Colorize: green
                                            DmiBiosCharacteristicsSystemReservedFlag::UEFI_SPECIFICATION_SUPPORTED,                                                                                      // Colorize: green
                                            DmiBiosCharacteristicsSystemReservedFlag::VIRTUAL_MACHINE_SUPPORTED                                                                                          // Colorize: green
                                        ), NgosStatus::ASSERTION);                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (entryV24 != nullptr)                                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_TEST_ASSERT(entryV24->systemBiosMajorRelease                 == 0,                                                                 NgosStatus::ASSERTION);                // Colorize: green
                        COMMON_TEST_ASSERT(entryV24->systemBiosMinorRelease                 == 0,                                                                 NgosStatus::ASSERTION);                // Colorize: green
                        COMMON_TEST_ASSERT(entryV24->embeddedControllerFirmwareMajorRelease == DMI_BIOS_EMBEDDED_CONTROLLER_FIRMWARE_MAJOR_RELEASE_NOT_AVAILABLE, NgosStatus::ASSERTION);                // Colorize: green
                        COMMON_TEST_ASSERT(entryV24->embeddedControllerFirmwareMinorRelease == DMI_BIOS_EMBEDDED_CONTROLLER_FIRMWARE_MINOR_RELEASE_NOT_AVAILABLE, NgosStatus::ASSERTION);                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        if (entryV31 != nullptr)                                                                                                                                                         // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_TEST_ASSERT(entryV31->extendedBiosRomSize.value   == 0,                                     NgosStatus::ASSERTION);             // Colorize: green
                            COMMON_TEST_ASSERT(entryV31->extendedBiosRomSize.unit    == DmiBiosExtendedRomSizeUnit::MEGABYTES, NgosStatus::ASSERTION);             // Colorize: green
                            COMMON_TEST_ASSERT(entryV31->extendedBiosRomSize.value16 == 0x0000,                                NgosStatus::ASSERTION);             // Colorize: green
                            COMMON_TEST_ASSERT(entryV31->extendedBiosRomSize.size()  == 0,                                     NgosStatus::ASSERTION);             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV31), NgosStatus::ASSERTION);                                                                                  // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                        else                                                                                                                                                                             // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV24), NgosStatus::ASSERTION);                                                                                  // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV23), NgosStatus::ASSERTION);                                                                                      // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV21), NgosStatus::ASSERTION);                                                                                          // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry), NgosStatus::ASSERTION);                                                                                                 // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            entry->vendor.id > 0                                                                                                                                                                         // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->biosVersion.id > 0                                                                                                                                                                    // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->biosReleaseDate.id > 0                                                                                                                                                                // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->vendor)                                                                                                                                                       // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("vendor = %s", begin));                                                                                                                                             // Colorize: green
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BIOS_VENDOR, begin, cur - begin + 1), NgosStatus::ASSERTION);                                                                 // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->biosVersion)                                                                                                                                                  // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("biosVersion = %s", begin));                                                                                                                                        // Colorize: green
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BIOS_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->biosReleaseDate)                                                                                                                                              // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("biosReleaseDate = %s", begin));                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BIOS_RELEASE_DATE, begin, cur - begin + 1), NgosStatus::ASSERTION);                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiSystemEntry(DmiSystemEntry *entry)                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    DmiSystemEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiSystemEntryV21) ? reinterpret_cast<DmiSystemEntryV21 *>(entry) : nullptr;                  // Colorize: green
    DmiSystemEntryV24 *entryV24 = DMI::getVersion() >= DMI_VERSION(2, 4) && entry->header.length >= sizeof(DmiSystemEntryV24) ? reinterpret_cast<DmiSystemEntryV24 *>(entry) : nullptr;                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->manufacturer.id = %u", entry->manufacturer.id));                                                                                                                        // Colorize: green
            COMMON_LVVV(("entry->productName.id  = %u", entry->productName.id));                                                                                                                         // Colorize: green
            COMMON_LVVV(("entry->version.id      = %u", entry->version.id));                                                                                                                             // Colorize: green
            COMMON_LVVV(("entry->serialNumber.id = %u", entry->serialNumber.id));                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("entryV21->uuid       = %s", uuidToString(entryV21->uuid)));                                                                                                                // Colorize: green
                COMMON_LVVV(("entryV21->wakeUpType = %s", enumToFullString(entryV21->wakeUpType)));                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV24 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("entryV24->skuNumber.id = %u", entryV24->skuNumber.id));                                                                                                                // Colorize: green
                    COMMON_LVVV(("entryV24->family.id    = %u", entryV24->family.id));                                                                                                                   // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->manufacturer.id == 1, NgosStatus::ASSERTION);                                                                                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->productName.id  == 2, NgosStatus::ASSERTION);                                                                                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->version.id      == 3, NgosStatus::ASSERTION);                                                                                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->serialNumber.id == 0, NgosStatus::ASSERTION);                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data1    == 0x9FAE0773,                        NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data2    == 0xF53F,                            NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data3    == 0x4A15,                            NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data4    == 0x8A,                              NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data5    == 0x11,                              NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[0] == 0xED,                              NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[1] == 0x76,                              NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[2] == 0xA1,                              NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[3] == 0x0F,                              NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[4] == 0x4E,                              NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[5] == 0x5B,                              NgosStatus::ASSERTION); // Commented because different each time                                     // Colorize: green
                COMMON_TEST_ASSERT(entryV21->wakeUpType       == DmiSystemWakeUpType::POWER_SWITCH, NgosStatus::ASSERTION);                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV24 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entryV24->skuNumber.id == 0, NgosStatus::ASSERTION);                                                                                                              // Colorize: green
                    COMMON_TEST_ASSERT(entryV24->family.id    == 0, NgosStatus::ASSERTION);                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntryV24), NgosStatus::ASSERTION);                                                                                        // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntryV21), NgosStatus::ASSERTION);                                                                                        // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry), NgosStatus::ASSERTION);                                                                                               // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiStringId skuNumberStringId;                                                                                                                                                                   // Colorize: green
        DmiStringId familyStringId;                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (entryV24 != nullptr)                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            skuNumberStringId = entryV24->skuNumber;                                                                                                                                                     // Colorize: green
            familyStringId    = entryV24->family;                                                                                                                                                        // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            entry->manufacturer.id > 0                                                                                                                                                                   // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->productName.id > 0                                                                                                                                                                    // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->version.id > 0                                                                                                                                                                        // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->serialNumber.id > 0                                                                                                                                                                   // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            skuNumberStringId.id > 0                                                                                                                                                                     // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            familyStringId.id > 0                                                                                                                                                                        // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->manufacturer)                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("manufacturer = %s", begin));                                                                                                                                       // Colorize: green
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::SYSTEM_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);                                                         // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->productName)                                                                                                                                                  // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("productName = %s", begin));                                                                                                                                        // Colorize: green
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::SYSTEM_PRODUCT_NAME, begin, cur - begin + 1), NgosStatus::ASSERTION);                                                         // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->version)                                                                                                                                                      // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("version = %s", begin));                                                                                                                                            // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->serialNumber)                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("serialNumber = %s", begin));                                                                                                                                       // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == skuNumberStringId)                                                                                                                                                   // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("skuNumber = %s", begin));                                                                                                                                          // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == familyStringId)                                                                                                                                                      // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("family = %s", begin));                                                                                                                                             // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (entryV21 != nullptr)                                                                                                                                                                             // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_ASSERT_EXECUTION(storeUuid(DmiStoredUuid::SYSTEM_UUID, &entryV21->uuid), NgosStatus::ASSERTION);                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiBaseboardEntry(DmiBaseboardEntry *entry)                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->manufacturer.id                = %u",     entry->manufacturer.id));                                                                                                     // Colorize: green
            COMMON_LVVV(("entry->product.id                     = %u",     entry->product.id));                                                                                                          // Colorize: green
            COMMON_LVVV(("entry->version.id                     = %u",     entry->version.id));                                                                                                          // Colorize: green
            COMMON_LVVV(("entry->serialNumber.id                = %u",     entry->serialNumber.id));                                                                                                     // Colorize: green
            COMMON_LVVV(("entry->assetTag.id                    = %u",     entry->assetTag.id));                                                                                                         // Colorize: green
            COMMON_LVVV(("entry->featureFlags                   = %s",     flagsToFullString(entry->featureFlags)));                                                                                     // Colorize: green
            COMMON_LVVV(("entry->locationInChassis.id           = %u",     entry->locationInChassis.id));                                                                                                // Colorize: green
            COMMON_LVVV(("entry->chassisHandle                  = 0x%04X", entry->chassisHandle));                                                                                                       // Colorize: green
            COMMON_LVVV(("entry->boardType                      = %s",     enumToFullString(entry->boardType)));                                                                                         // Colorize: green
            COMMON_LVVV(("entry->numberOfContainedObjectHandles = %u",     entry->numberOfContainedObjectHandles));                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // entry->containedObjectHandles:                                                                                                                                                            // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
                COMMON_LVVV(("entry->containedObjectHandles:"));                                                                                                                                         // Colorize: green
                COMMON_LVVV(("-------------------------------------"));                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                for (good_I64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("#%-3d: 0x%04X", i, entry->containedObjectHandles[i]));                                                                                                                 // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("-------------------------------------"));                                                                                                                                  // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->manufacturer.id                == 1,                                           NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->product.id                     == 2,                                           NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->version.id                     == 3,                                           NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->serialNumber.id                == 4,                                           NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->assetTag.id                    == 5,                                           NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->featureFlags                   == FLAGS(DmiBaseboardFeatureFlag::MOTHERBOARD), NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->locationInChassis.id           == 6,                                           NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->chassisHandle                  == 0x0300,                                      NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->boardType                      == DmiBaseboardType::MOTHERBOARD,               NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->numberOfContainedObjectHandles == 0,                                           NgosStatus::ASSERTION);                                                             // Colorize: green
            COMMON_TEST_ASSERT(entry->containedObjectHandles[0]      == 0,                                           NgosStatus::ASSERTION);                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBaseboardEntry) + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);             // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            entry->manufacturer.id > 0                                                                                                                                                                   // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->product.id > 0                                                                                                                                                                        // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->version.id > 0                                                                                                                                                                        // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->serialNumber.id > 0                                                                                                                                                                   // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->assetTag.id > 0                                                                                                                                                                       // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->locationInChassis.id > 0                                                                                                                                                              // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->manufacturer)                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("manufacturer = %s", begin));                                                                                                                                       // Colorize: green
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BASEBOARD_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);                                                      // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->product)                                                                                                                                                      // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("product = %s", begin));                                                                                                                                            // Colorize: green
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BASEBOARD_PRODUCT, begin, cur - begin + 1), NgosStatus::ASSERTION);                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->version)                                                                                                                                                      // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("version = %s", begin));                                                                                                                                            // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->serialNumber)                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("serialNumber = %s", begin));                                                                                                                                       // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->assetTag)                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("assetTag = %s", begin));                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->locationInChassis)                                                                                                                                            // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("locationInChassis = %s", begin));                                                                                                                                  // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiChassisEntry(DmiChassisEntry *entry)                                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    DmiChassisEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiChassisEntryV21)                                                                                                         ? reinterpret_cast<DmiChassisEntryV21 *>(entry)                                                                    : nullptr; // Colorize: green
    DmiChassisEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiChassisEntryV23)                                                                                                         ? reinterpret_cast<DmiChassisEntryV23 *>(entry)                                                                    : nullptr; // Colorize: green
    DmiChassisEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength + sizeof(DmiChassisEntryV27) ? reinterpret_cast<DmiChassisEntryV27 *>(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, entryV23->containedElementCount)) : nullptr; // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->manufacturer.id      = %u",     entry->manufacturer.id));                                                                                                               // Colorize: green
            COMMON_LVVV(("entry->typeAndLocked.type   = %s",     enumToFullString((DmiChassisType)entry->typeAndLocked.type)));                                                                          // Colorize: green
            COMMON_LVVV(("entry->typeAndLocked.locked = %u",     entry->typeAndLocked.locked));                                                                                                          // Colorize: green
            COMMON_LVVV(("entry->typeAndLocked.value8 = 0x%02X", entry->typeAndLocked.value8));                                                                                                          // Colorize: green
            COMMON_LVVV(("entry->version.id           = %u",     entry->version.id));                                                                                                                    // Colorize: green
            COMMON_LVVV(("entry->serialNumber.id      = %u",     entry->serialNumber.id));                                                                                                               // Colorize: green
            COMMON_LVVV(("entry->assetTag.id          = %u",     entry->assetTag.id));                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("entryV21->bootUpState      = %s", enumToFullString(entryV21->bootUpState)));                                                                                               // Colorize: green
                COMMON_LVVV(("entryV21->powerSupplyState = %s", enumToFullString(entryV21->powerSupplyState)));                                                                                          // Colorize: green
                COMMON_LVVV(("entryV21->thermalState     = %s", enumToFullString(entryV21->thermalState)));                                                                                              // Colorize: green
                COMMON_LVVV(("entryV21->securityStatus   = %s", enumToFullString(entryV21->securityStatus)));                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV23 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("entryV23->oemDefined                   = 0x%08X", entryV23->oemDefined));                                                                                              // Colorize: green
                    COMMON_LVVV(("entryV23->height                       = %u",     entryV23->height));                                                                                                  // Colorize: green
                    COMMON_LVVV(("entryV23->numberOfPowerCords           = %u",     entryV23->numberOfPowerCords));                                                                                      // Colorize: green
                    COMMON_LVVV(("entryV23->containedElementCount        = %u",     entryV23->containedElementCount));                                                                                   // Colorize: green
                    COMMON_LVVV(("entryV23->containedElementRecordLength = %u",     entryV23->containedElementRecordLength));                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // entryV23->containedElements:                                                                                                                                                      // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
                        COMMON_LVVV(("entryV23->containedElements:"));                                                                                                                                   // Colorize: green
                        COMMON_LVVV(("-------------------------------------"));                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        for (good_I64 i = 0; i < entryV23->containedElementCount; ++i)                                                                                                                   // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, i);                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_LVVV(("containedElement[%-3d]->type.typeSelect = %s", i, enumToFullString(containedElement->type.typeSelect)));                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            switch (containedElement->type.typeSelect)                                                                                                                                   // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                case DmiChassisContainedElementTypeSelect::BASEBOARD_TYPE: COMMON_LVVV(("containedElement[%-3d]->type.baseboardType = %s", i, enumToFullString(containedElement->type.baseboardType))); break; // Colorize: green
                                case DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE: COMMON_LVVV(("containedElement[%-3d]->type.dmiEntryType  = %s", i, enumToFullString(containedElement->type.dmiEntryType)));  break; // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                default:                                                                                                                                                                 // Colorize: green
                                {                                                                                                                                                                        // Colorize: green
                                    COMMON_LF(("Unknown DMI chassis contained element type select %s, %s:%u", enumToFullString(containedElement->type.typeSelect), __FILE__, __LINE__));                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                    return NgosStatus::UNEXPECTED_BEHAVIOUR;                                                                                                                             // Colorize: green
                                }                                                                                                                                                                        // Colorize: green
                                break;                                                                                                                                                                   // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_LVVV(("containedElement[%-3d]->type.value8 = 0x%02X", i, containedElement->type.value8));                                                                             // Colorize: green
                            COMMON_LVVV(("containedElement[%-3d]->minimum     = %u",     i, containedElement->minimum));                                                                                 // Colorize: green
                            COMMON_LVVV(("containedElement[%-3d]->maximum     = %u",     i, containedElement->maximum));                                                                                 // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        COMMON_LVVV(("-------------------------------------"));                                                                                                                          // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (entryV27 != nullptr)                                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("entryV27->skuNumber.id = %u", entryV27->skuNumber.id));                                                                                                            // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->manufacturer.id      == 1,                     NgosStatus::ASSERTION);                                                                                           // Colorize: green
            COMMON_TEST_ASSERT(entry->typeAndLocked.type   == DmiChassisType::OTHER, NgosStatus::ASSERTION);                                                                                           // Colorize: green
            COMMON_TEST_ASSERT(entry->typeAndLocked.locked == 0,                     NgosStatus::ASSERTION);                                                                                           // Colorize: green
            COMMON_TEST_ASSERT(entry->typeAndLocked.value8 == 0x01,                  NgosStatus::ASSERTION);                                                                                           // Colorize: green
            COMMON_TEST_ASSERT(entry->version.id           == 2,                     NgosStatus::ASSERTION);                                                                                           // Colorize: green
            COMMON_TEST_ASSERT(entry->serialNumber.id      == 0,                     NgosStatus::ASSERTION);                                                                                           // Colorize: green
            COMMON_TEST_ASSERT(entry->assetTag.id          == 0,                     NgosStatus::ASSERTION);                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entryV21->bootUpState      == DmiChassisState::SAFE,             NgosStatus::ASSERTION);                                                                              // Colorize: green
                COMMON_TEST_ASSERT(entryV21->powerSupplyState == DmiChassisState::SAFE,             NgosStatus::ASSERTION);                                                                              // Colorize: green
                COMMON_TEST_ASSERT(entryV21->thermalState     == DmiChassisState::SAFE,             NgosStatus::ASSERTION);                                                                              // Colorize: green
                COMMON_TEST_ASSERT(entryV21->securityStatus   == DmiChassisSecurityStatus::UNKNOWN, NgosStatus::ASSERTION);                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV23 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->oemDefined                   == 0x00000000, NgosStatus::ASSERTION);                                                                                     // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->height                       == 0,          NgosStatus::ASSERTION);                                                                                     // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->numberOfPowerCords           == 0,          NgosStatus::ASSERTION);                                                                                     // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->containedElementCount        == 0,          NgosStatus::ASSERTION);                                                                                     // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->containedElementRecordLength == 0,          NgosStatus::ASSERTION);                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (entryV27 != nullptr)                                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_TEST_ASSERT(entryV27->skuNumber.id == 0, NgosStatus::ASSERTION);                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength + sizeof(DmiChassisEntryV27), NgosStatus::ASSERTION); // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength, NgosStatus::ASSERTION);        // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV21), NgosStatus::ASSERTION);                                                                                       // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry), NgosStatus::ASSERTION);                                                                                              // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiStringId skuNumberStringId;                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (entryV27 != nullptr)                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            skuNumberStringId = entryV27->skuNumber;                                                                                                                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            entry->manufacturer.id > 0                                                                                                                                                                   // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->version.id > 0                                                                                                                                                                        // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->serialNumber.id > 0                                                                                                                                                                   // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->assetTag.id > 0                                                                                                                                                                       // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            skuNumberStringId.id > 0                                                                                                                                                                     // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->manufacturer)                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("manufacturer = %s", begin));                                                                                                                                       // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->version)                                                                                                                                                      // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("version = %s", begin));                                                                                                                                            // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->serialNumber)                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("serialNumber = %s", begin));                                                                                                                                       // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->assetTag)                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("assetTag = %s", begin));                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == skuNumberStringId)                                                                                                                                                   // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("skuNumber = %s", begin));                                                                                                                                          // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiProcessorEntry(DmiProcessorEntry *entry)                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    DmiProcessorEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiProcessorEntryV21) ? reinterpret_cast<DmiProcessorEntryV21 *>(entry) : nullptr;         // Colorize: green
    DmiProcessorEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiProcessorEntryV23) ? reinterpret_cast<DmiProcessorEntryV23 *>(entry) : nullptr;         // Colorize: green
    DmiProcessorEntryV25 *entryV25 = DMI::getVersion() >= DMI_VERSION(2, 5) && entry->header.length >= sizeof(DmiProcessorEntryV25) ? reinterpret_cast<DmiProcessorEntryV25 *>(entry) : nullptr;         // Colorize: green
    DmiProcessorEntryV26 *entryV26 = DMI::getVersion() >= DMI_VERSION(2, 6) && entry->header.length >= sizeof(DmiProcessorEntryV26) ? reinterpret_cast<DmiProcessorEntryV26 *>(entry) : nullptr;         // Colorize: green
    DmiProcessorEntryV30 *entryV30 = DMI::getVersion() >= DMI_VERSION(3, 0) && entry->header.length >= sizeof(DmiProcessorEntryV30) ? reinterpret_cast<DmiProcessorEntryV30 *>(entry) : nullptr;         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->socketDesignation.id                 = %u",     entry->socketDesignation.id));                                                                                          // Colorize: green
            COMMON_LVVV(("entry->processorType                        = %s",     enumToFullString(entry->processorType)));                                                                               // Colorize: green
            COMMON_LVVV(("entry->processorFamily                      = %s",     enumToFullString(entry->processorFamily)));                                                                             // Colorize: green
            COMMON_LVVV(("entry->processorManufacturer.id             = %u",     entry->processorManufacturer.id));                                                                                      // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.stepping       = %u",     entry->processorId.signature.stepping));                                                                                // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.model          = %u",     entry->processorId.signature.model));                                                                                   // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.family         = %u",     entry->processorId.signature.family));                                                                                  // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.type           = %u",     entry->processorId.signature.type));                                                                                    // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.__reserved     = %u",     entry->processorId.signature.__reserved));                                                                              // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.extendedModel  = %u",     entry->processorId.signature.extendedModel));                                                                           // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.extendedFamily = %u",     entry->processorId.signature.extendedFamily));                                                                          // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.__reserved2    = %u",     entry->processorId.signature.__reserved2));                                                                             // Colorize: green
            COMMON_LVVV(("entry->processorId.signature.value32        = 0x%08X", entry->processorId.signature.value32));                                                                                 // Colorize: green
            COMMON_LVVV(("entry->processorId.featureFlags             = %s",     flagsToFullString(entry->processorId.featureFlags)));                                                                   // Colorize: green
            COMMON_LVVV(("entry->processorVersion.id                  = %u",     entry->processorVersion.id));                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // entry->voltage                                                                                                                                                                            // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("entry->voltage.modeType = %s", enumToFullString(entry->voltage.modeType)));                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                switch (entry->voltage.modeType)                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    case DmiProcessorVoltageModeType::LEGACY_MODE:          COMMON_LVVV(("entry->voltage.flags = %s", flagsToFullString(static_cast<DmiProcessorVoltageFlags>(entry->voltage.flags)))); break; // Colorize: green
                    case DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE: COMMON_LVVV(("entry->voltage.value = %u", entry->voltage.value));                                                           break; // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    default:                                                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LF(("Unknown DMI processor voltage mode type %s, %s:%u", enumToFullString(entry->voltage.modeType), __FILE__, __LINE__));                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        return NgosStatus::UNEXPECTED_BEHAVIOUR;                                                                                                                                         // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("entry->voltage.value8 = 0x%02X", entry->voltage.value8));                                                                                                                  // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_LVVV(("entry->externalClock                                      = %u",     entry->externalClock));                                                                                   // Colorize: green
            COMMON_LVVV(("entry->maxSpeed                                           = %u",     entry->maxSpeed));                                                                                        // Colorize: green
            COMMON_LVVV(("entry->currentSpeed                                       = %u",     entry->currentSpeed));                                                                                    // Colorize: green
            COMMON_LVVV(("entry->processorStatusAndSocketPopulated.status           = %s",     enumToFullString(entry->processorStatusAndSocketPopulated.status)));                                      // Colorize: green
            COMMON_LVVV(("entry->processorStatusAndSocketPopulated.socketPopulated  = %u",     entry->processorStatusAndSocketPopulated.socketPopulated));                                               // Colorize: green
            COMMON_LVVV(("entry->processorStatusAndSocketPopulated.value8           = 0x%02X", entry->processorStatusAndSocketPopulated.value8));                                                        // Colorize: green
            COMMON_LVVV(("entry->processorUpgrade                                   = %s",     enumToFullString(entry->processorUpgrade)));                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("entryV21->l1CacheHandle = 0x%04X", entryV21->l1CacheHandle));                                                                                                              // Colorize: green
                COMMON_LVVV(("entryV21->l2CacheHandle = 0x%04X", entryV21->l2CacheHandle));                                                                                                              // Colorize: green
                COMMON_LVVV(("entryV21->l3CacheHandle = 0x%04X", entryV21->l3CacheHandle));                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV23 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("entryV23->serialNumber.id = %u", entryV23->serialNumber.id));                                                                                                          // Colorize: green
                    COMMON_LVVV(("entryV23->assetTag.id     = %u", entryV23->assetTag.id));                                                                                                              // Colorize: green
                    COMMON_LVVV(("entryV23->partNumber.id   = %u", entryV23->partNumber.id));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (entryV25 != nullptr)                                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("entryV25->coreCount                = 0x%02X", entryV25->coreCount));                                                                                               // Colorize: green
                        COMMON_LVVV(("entryV25->enabledCoreCount         = 0x%02X", entryV25->enabledCoreCount));                                                                                        // Colorize: green
                        COMMON_LVVV(("entryV25->threadCount              = 0x%02X", entryV25->threadCount));                                                                                             // Colorize: green
                        COMMON_LVVV(("entryV25->processorCharacteristics = %s",     flagsToFullString(entryV25->processorCharacteristics)));                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        if (entryV26 != nullptr)                                                                                                                                                         // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("entryV26->processorFamily2 = %s", enumToFullString(entryV26->processorFamily2)));                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            if (entryV30 != nullptr)                                                                                                                                                     // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_LVVV(("entryV30->coreCount2        = 0x%04X", entryV30->coreCount2));                                                                                             // Colorize: green
                                COMMON_LVVV(("entryV30->enabledCoreCount2 = 0x%04X", entryV30->enabledCoreCount2));                                                                                      // Colorize: green
                                COMMON_LVVV(("entryV30->threadCount2      = 0x%04X", entryV30->threadCount2));                                                                                           // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            // Ignore CppAlignmentVerifier [BEGIN]                                                                                                                                                       // Colorize: green
            COMMON_TEST_ASSERT(entry->socketDesignation.id                              == 1,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorType                                     == DmiProcessorType::CENTRAL_PROCESSOR,               NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorFamily                                   == DmiProcessorFamily::OTHER,                         NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorManufacturer.id                          == 2,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.stepping                    == 3,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.model                       == 14,                                                NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.family                      == 6,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.type                        == 0,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.__reserved                  == 0,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.extendedModel               == 5,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.extendedFamily              == 0,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.__reserved2                 == 0,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.signature.value32                     == 0x000506E3,                                        NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorId.featureFlags                          == FLAGS(DmiProcessorFeatureFlag::FPU,                                                                           // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::VME,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::DE,                                                                         // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::PSE,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::TSC,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::MSR,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::PAE,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::MCE,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::CX8,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::APIC,                                                                       // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::SEP,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::MTRR,                                                                       // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::PGE,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::MCA,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::CMOV,                                                                       // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::PAT,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::PSE_36,                                                                     // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::CLFSH,                                                                      // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::MMX,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::FXSR,                                                                       // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::SSE,                                                                        // Colorize: green
                                                                                                    DmiProcessorFeatureFlag::SSE2),           NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorVersion.id                               == 3,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->voltage.modeType                                  == DmiProcessorVoltageModeType::LEGACY_MODE,          NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->voltage.flags                                     == FLAGS(DmiProcessorVoltageFlag::NONE),              NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->voltage.value8                                    == 0x00,                                              NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->externalClock                                     == 0,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->maxSpeed                                          == 2000,                                              NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->currentSpeed                                      == 2000,                                              NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorStatusAndSocketPopulated.status          == DmiProcessorStatus::ENABLED,                       NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorStatusAndSocketPopulated.socketPopulated == 1,                                                 NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorStatusAndSocketPopulated.value8          == 0x41,                                              NgosStatus::ASSERTION);                                    // Colorize: green
            COMMON_TEST_ASSERT(entry->processorUpgrade                                  == DmiProcessorUpgrade::OTHER,                        NgosStatus::ASSERTION);                                    // Colorize: green
            // Ignore CppAlignmentVerifier [END]                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entryV21->l1CacheHandle == 0xFFFF, NgosStatus::ASSERTION);                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entryV21->l2CacheHandle == 0xFFFF, NgosStatus::ASSERTION);                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entryV21->l3CacheHandle == 0xFFFF, NgosStatus::ASSERTION);                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV23 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->serialNumber.id == 0, NgosStatus::ASSERTION);                                                                                                           // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->assetTag.id     == 0, NgosStatus::ASSERTION);                                                                                                           // Colorize: green
                    COMMON_TEST_ASSERT(entryV23->partNumber.id   == 0, NgosStatus::ASSERTION);                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (entryV25 != nullptr)                                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_TEST_ASSERT(entryV25->coreCount                == 0x02,                                            NgosStatus::ASSERTION);                                         // Colorize: green
                        COMMON_TEST_ASSERT(entryV25->enabledCoreCount         == 0x02,                                            NgosStatus::ASSERTION);                                         // Colorize: green
                        COMMON_TEST_ASSERT(entryV25->threadCount              == 0x02,                                            NgosStatus::ASSERTION);                                         // Colorize: green
                        COMMON_TEST_ASSERT(entryV25->processorCharacteristics == FLAGS(DmiProcessorCharacteristicsFlag::UNKNOWN), NgosStatus::ASSERTION);                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        if (entryV26 != nullptr)                                                                                                                                                         // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_TEST_ASSERT(entryV26->processorFamily2 == DmiProcessorFamily2::OTHER, NgosStatus::ASSERTION);                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            if (entryV30 != nullptr)                                                                                                                                                     // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_TEST_ASSERT(entryV30->coreCount2        == 0x0002, NgosStatus::ASSERTION);                                                                                        // Colorize: green
                                COMMON_TEST_ASSERT(entryV30->enabledCoreCount2 == 0x0002, NgosStatus::ASSERTION);                                                                                        // Colorize: green
                                COMMON_TEST_ASSERT(entryV30->threadCount2      == 0x0002, NgosStatus::ASSERTION);                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV30), NgosStatus::ASSERTION);                                                                         // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                            else                                                                                                                                                                         // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV26), NgosStatus::ASSERTION);                                                                         // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                        else                                                                                                                                                                             // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV25), NgosStatus::ASSERTION);                                                                             // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV23), NgosStatus::ASSERTION);                                                                                 // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV21), NgosStatus::ASSERTION);                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry), NgosStatus::ASSERTION);                                                                                            // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiStringId serialNumberStringId;                                                                                                                                                                // Colorize: green
        DmiStringId assetTagStringId;                                                                                                                                                                    // Colorize: green
        DmiStringId partNumberStringId;                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (entryV23 != nullptr)                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            serialNumberStringId = entryV23->serialNumber;                                                                                                                                               // Colorize: green
            assetTagStringId     = entryV23->assetTag;                                                                                                                                                   // Colorize: green
            partNumberStringId   = entryV23->partNumber;                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            entry->socketDesignation.id > 0                                                                                                                                                              // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->processorManufacturer.id > 0                                                                                                                                                          // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->processorVersion.id > 0                                                                                                                                                               // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            serialNumberStringId.id > 0                                                                                                                                                                  // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            assetTagStringId.id > 0                                                                                                                                                                      // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            partNumberStringId.id > 0                                                                                                                                                                    // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->socketDesignation)                                                                                                                                            // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("socketDesignation = %s", begin));                                                                                                                                  // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->processorManufacturer)                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("processorManufacturer = %s", begin));                                                                                                                              // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->processorVersion)                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("processorVersion = %s", begin));                                                                                                                                   // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == serialNumberStringId)                                                                                                                                                // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("serialNumber = %s", begin));                                                                                                                                       // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == assetTagStringId)                                                                                                                                                    // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("assetTag = %s", begin));                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == partNumberStringId)                                                                                                                                                  // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("partNumber = %s", begin));                                                                                                                                         // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiCacheEntry(DmiCacheEntry *entry)                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    DmiCacheEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiCacheEntryV21) ? reinterpret_cast<DmiCacheEntryV21 *>(entry) : nullptr;                     // Colorize: green
    DmiCacheEntryV31 *entryV31 = DMI::getVersion() >= DMI_VERSION(3, 1) && entry->header.length >= sizeof(DmiCacheEntryV31) ? reinterpret_cast<DmiCacheEntryV31 *>(entry) : nullptr;                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->socketDesignation.id               = %u",     entry->socketDesignation.id));                                                                                            // Colorize: green
            COMMON_LVVV(("entry->cacheConfiguration.level           = %u",     entry->cacheConfiguration.level));                                                                                        // Colorize: green
            COMMON_LVVV(("entry->cacheConfiguration.socketed        = %u",     entry->cacheConfiguration.socketed));                                                                                     // Colorize: green
            COMMON_LVVV(("entry->cacheConfiguration.__reserved      = %u",     entry->cacheConfiguration.__reserved));                                                                                   // Colorize: green
            COMMON_LVVV(("entry->cacheConfiguration.location        = %s",     enumToFullString(entry->cacheConfiguration.location)));                                                                   // Colorize: green
            COMMON_LVVV(("entry->cacheConfiguration.enabled         = %u",     entry->cacheConfiguration.enabled));                                                                                      // Colorize: green
            COMMON_LVVV(("entry->cacheConfiguration.operationalMode = %s",     enumToFullString(entry->cacheConfiguration.operationalMode)));                                                            // Colorize: green
            COMMON_LVVV(("entry->cacheConfiguration.__reserved2     = %u",     entry->cacheConfiguration.__reserved2));                                                                                  // Colorize: green
            COMMON_LVVV(("entry->cacheConfiguration.value16         = 0x%04X", entry->cacheConfiguration.value16));                                                                                      // Colorize: green
            COMMON_LVVV(("entry->maximumCacheSize.value             = %u",     entry->maximumCacheSize.value));                                                                                          // Colorize: green
            COMMON_LVVV(("entry->maximumCacheSize.granularity       = %s",     enumToFullString(entry->maximumCacheSize.granularity)));                                                                  // Colorize: green
            COMMON_LVVV(("entry->maximumCacheSize.value16           = 0x%04X", entry->maximumCacheSize.value16));                                                                                        // Colorize: green
            COMMON_LVVV(("entry->maximumCacheSize.size()            = %s",     bytesToString(entry->maximumCacheSize.size())));                                                                          // Colorize: green
            COMMON_LVVV(("entry->installedSize.value                = %u",     entry->installedSize.value));                                                                                             // Colorize: green
            COMMON_LVVV(("entry->installedSize.granularity          = %s",     enumToFullString(entry->installedSize.granularity)));                                                                     // Colorize: green
            COMMON_LVVV(("entry->installedSize.value16              = 0x%04X", entry->installedSize.value16));                                                                                           // Colorize: green
            COMMON_LVVV(("entry->installedSize.size()               = %s",     bytesToString(entry->installedSize.size())));                                                                             // Colorize: green
            COMMON_LVVV(("entry->supportedSramType                  = %s",     flagsToFullString(entry->supportedSramType)));                                                                            // Colorize: green
            COMMON_LVVV(("entry->currentSramType                    = %s",     flagsToFullString(entry->currentSramType)));                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("entryV21->cacheSpeed          = %u", entryV21->cacheSpeed));                                                                                                               // Colorize: green
                COMMON_LVVV(("entryV21->errorCorrectionType = %s", enumToFullString(entryV21->errorCorrectionType)));                                                                                    // Colorize: green
                COMMON_LVVV(("entryV21->systemCacheType     = %s", enumToFullString(entryV21->systemCacheType)));                                                                                        // Colorize: green
                COMMON_LVVV(("entryV21->associativity       = %s", enumToFullString(entryV21->associativity)));                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV31 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("entryV31->maximumCacheSize2.value       = %u",     entryV31->maximumCacheSize2.value));                                                                                // Colorize: green
                    COMMON_LVVV(("entryV31->maximumCacheSize2.granularity = %s",     enumToFullString(entryV31->maximumCacheSize2.granularity)));                                                        // Colorize: green
                    COMMON_LVVV(("entryV31->maximumCacheSize2.value32     = 0x%08X", entryV31->maximumCacheSize2.value32));                                                                              // Colorize: green
                    COMMON_LVVV(("entryV31->maximumCacheSize2.size()      = %s",     bytesToString(entryV31->maximumCacheSize2.size())));                                                                // Colorize: green
                    COMMON_LVVV(("entryV31->installedSize2.value          = %u",     entryV31->installedSize2.value));                                                                                   // Colorize: green
                    COMMON_LVVV(("entryV31->installedSize2.granularity    = %s",     enumToFullString(entryV31->installedSize2.granularity)));                                                           // Colorize: green
                    COMMON_LVVV(("entryV31->installedSize2.value32        = 0x%08X", entryV31->installedSize2.value32));                                                                                 // Colorize: green
                    COMMON_LVVV(("entryV31->installedSize2.size()         = %s",     bytesToString(entryV31->installedSize2.size())));                                                                   // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->socketDesignation.id               == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->cacheConfiguration.level           == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->cacheConfiguration.socketed        == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->cacheConfiguration.__reserved      == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->cacheConfiguration.location        == DmiCacheLocation::UNKNOWN,                      NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->cacheConfiguration.enabled         == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->cacheConfiguration.operationalMode == DmiCacheOperationalMode::UNKNOWN,               NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->cacheConfiguration.__reserved2     == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->cacheConfiguration.value16         == 0x0000,                                         NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->maximumCacheSize.value             == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->maximumCacheSize.granularity       == DmiCacheSizeGranularity::_1_KILOBYTE,           NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->maximumCacheSize.value16           == 0x0000,                                         NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->maximumCacheSize.size()            == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->installedSize.value                == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->installedSize.granularity          == DmiCacheSizeGranularity::_1_KILOBYTE,           NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->installedSize.value16              == 0x0000,                                         NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->installedSize.size()               == 0,                                              NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->supportedSramType                  == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION);                                                      // Colorize: green
            COMMON_TEST_ASSERT(entry->currentSramType                    == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION);                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV21 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entryV21->cacheSpeed          == 0,                                  NgosStatus::ASSERTION);                                                                          // Colorize: green
                COMMON_TEST_ASSERT(entryV21->errorCorrectionType == DmiCacheErrorCorrectionType::OTHER, NgosStatus::ASSERTION);                                                                          // Colorize: green
                COMMON_TEST_ASSERT(entryV21->systemCacheType     == DmiCacheType::OTHER,                NgosStatus::ASSERTION);                                                                          // Colorize: green
                COMMON_TEST_ASSERT(entryV21->associativity       == DmiCacheAssociativity::OTHER,       NgosStatus::ASSERTION);                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV31 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entryV31->maximumCacheSize2.value       == 1,                                    NgosStatus::ASSERTION);                                                          // Colorize: green
                    COMMON_TEST_ASSERT(entryV31->maximumCacheSize2.granularity == DmiCacheSizeGranularity::_1_KILOBYTE, NgosStatus::ASSERTION);                                                          // Colorize: green
                    COMMON_TEST_ASSERT(entryV31->maximumCacheSize2.value32     == 0x00000000,                           NgosStatus::ASSERTION);                                                          // Colorize: green
                    COMMON_TEST_ASSERT(entryV31->maximumCacheSize2.size()      == 1,                                    NgosStatus::ASSERTION);                                                          // Colorize: green
                    COMMON_TEST_ASSERT(entryV31->installedSize2.value          == 1,                                    NgosStatus::ASSERTION);                                                          // Colorize: green
                    COMMON_TEST_ASSERT(entryV31->installedSize2.granularity    == DmiCacheSizeGranularity::_1_KILOBYTE, NgosStatus::ASSERTION);                                                          // Colorize: green
                    COMMON_TEST_ASSERT(entryV31->installedSize2.value32        == 0x00000000,                           NgosStatus::ASSERTION);                                                          // Colorize: green
                    COMMON_TEST_ASSERT(entryV31->installedSize2.size()         == 1,                                    NgosStatus::ASSERTION);                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntryV31), NgosStatus::ASSERTION);                                                                                         // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntryV21), NgosStatus::ASSERTION);                                                                                         // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry), NgosStatus::ASSERTION);                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (entry->socketDesignation.id)                                                                                                                                                                 // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->socketDesignation)                                                                                                                                            // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("socketDesignation = %s", begin));                                                                                                                                  // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiPortConnectorEntry(DmiPortConnectorEntry *entry)                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->internalReferenceDesignator.id = %u", entry->internalReferenceDesignator.id));                                                                                          // Colorize: green
            COMMON_LVVV(("entry->internalConnectorType          = %s", enumToFullString(entry->internalConnectorType)));                                                                                 // Colorize: green
            COMMON_LVVV(("entry->externalReferenceDesignator.id = %u", entry->externalReferenceDesignator.id));                                                                                          // Colorize: green
            COMMON_LVVV(("entry->externalConnectorType          = %s", enumToFullString(entry->externalConnectorType)));                                                                                 // Colorize: green
            COMMON_LVVV(("entry->portType                       = %s", enumToFullString(entry->portType)));                                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->internalReferenceDesignator.id == 1,                               NgosStatus::ASSERTION);                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->internalConnectorType          == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION);                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->externalReferenceDesignator.id == 2,                               NgosStatus::ASSERTION);                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->externalConnectorType          == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION);                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->portType                       == DmiPortConnectorPortType::OTHER, NgosStatus::ASSERTION);                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPortConnectorEntry), NgosStatus::ASSERTION);                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            entry->internalReferenceDesignator.id > 0                                                                                                                                                    // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->externalReferenceDesignator.id > 0                                                                                                                                                    // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->internalReferenceDesignator)                                                                                                                                  // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("internalReferenceDesignator = %s", begin));                                                                                                                        // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    if (stringId == entry->externalReferenceDesignator)                                                                                                                                  // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("externalReferenceDesignator = %s", begin));                                                                                                                        // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiSystemSlotsEntry(DmiSystemSlotsEntry *entry)                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    DmiSystemSlotsEntryV26 *entryV26 = DMI::getVersion() >= DMI_VERSION(2, 6) && entry->header.length >= sizeof(DmiSystemSlotsEntryV26) ? reinterpret_cast<DmiSystemSlotsEntryV26 *>(entry) : nullptr;   // Colorize: green
    DmiSystemSlotsEntryV32 *entryV32 = DMI::getVersion() >= DMI_VERSION(3, 2) && entry->header.length >= sizeof(DmiSystemSlotsEntryV32) ? reinterpret_cast<DmiSystemSlotsEntryV32 *>(entry) : nullptr;   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->slotDesignation.id  = %u",     entry->slotDesignation.id));                                                                                                             // Colorize: green
            COMMON_LVVV(("entry->slotType            = %s",     enumToFullString(entry->slotType)));                                                                                                     // Colorize: green
            COMMON_LVVV(("entry->slotDataBusWidth    = %s",     enumToFullString(entry->slotDataBusWidth)));                                                                                             // Colorize: green
            COMMON_LVVV(("entry->currentUsage        = %s",     enumToFullString(entry->currentUsage)));                                                                                                 // Colorize: green
            COMMON_LVVV(("entry->slotLength          = %s",     enumToFullString(entry->slotLength)));                                                                                                   // Colorize: green
            COMMON_LVVV(("entry->slotID              = 0x%04X", entry->slotID));                                                                                                                         // Colorize: green
            COMMON_LVVV(("entry->slotCharacteristics = %s",     flagsToFullString(entry->slotCharacteristics)));                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV26 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("entryV26->segmentGroupNumber                           = %u",     entryV26->segmentGroupNumber));                                                                          // Colorize: green
                COMMON_LVVV(("entryV26->busNumber                                    = %u",     entryV26->busNumber));                                                                                   // Colorize: green
                COMMON_LVVV(("entryV26->functionNumberAndDeviceNumber.functionNumber = %u",     entryV26->functionNumberAndDeviceNumber.functionNumber));                                                // Colorize: green
                COMMON_LVVV(("entryV26->functionNumberAndDeviceNumber.deviceNumber   = %u",     entryV26->functionNumberAndDeviceNumber.deviceNumber));                                                  // Colorize: green
                COMMON_LVVV(("entryV26->functionNumberAndDeviceNumber.value8         = 0x%02X", entryV26->functionNumberAndDeviceNumber.value8));                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV32 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("entryV32->dataBusWidth      = %u", entryV32->dataBusWidth));                                                                                                           // Colorize: green
                    COMMON_LVVV(("entryV32->peerGroupingCount = %u", entryV32->peerGroupingCount));                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // entryV32->peerGroups:                                                                                                                                                             // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
                        COMMON_LVVV(("entryV32->peerGroups:"));                                                                                                                                          // Colorize: green
                        COMMON_LVVV(("-------------------------------------"));                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        for (good_I64 i = 0; i < entryV32->peerGroupingCount; ++i)                                                                                                                       // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("entryV32->peerGroups[%d].segmentGroupNumber                           = %u",     i, entryV32->peerGroups[i].segmentGroupNumber));                              // Colorize: green
                            COMMON_LVVV(("entryV32->peerGroups[%d].busNumber                                    = %u",     i, entryV32->peerGroups[i].busNumber));                                       // Colorize: green
                            COMMON_LVVV(("entryV32->peerGroups[%d].functionNumberAndDeviceNumber.functionNumber = %u",     i, entryV32->peerGroups[i].functionNumberAndDeviceNumber.functionNumber));    // Colorize: green
                            COMMON_LVVV(("entryV32->peerGroups[%d].functionNumberAndDeviceNumber.deviceNumber   = %u",     i, entryV32->peerGroups[i].functionNumberAndDeviceNumber.deviceNumber));      // Colorize: green
                            COMMON_LVVV(("entryV32->peerGroups[%d].functionNumberAndDeviceNumber.value8         = 0x%02X", i, entryV32->peerGroups[i].functionNumberAndDeviceNumber.value8));            // Colorize: green
                            COMMON_LVVV(("entryV32->peerGroups[%d].dataBusWidth                                 = %u",     i, entryV32->peerGroups[i].dataBusWidth));                                    // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        COMMON_LVVV(("-------------------------------------"));                                                                                                                          // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->slotDesignation.id  == 1,                                              NgosStatus::ASSERTION);                                                                     // Colorize: green
            COMMON_TEST_ASSERT(entry->slotType            == DmiSystemSlotsType::UNKNOWN,                    NgosStatus::ASSERTION);                                                                     // Colorize: green
            COMMON_TEST_ASSERT(entry->slotDataBusWidth    == DmiSystemSlotsDataBusWidth::UNKNOWN,            NgosStatus::ASSERTION);                                                                     // Colorize: green
            COMMON_TEST_ASSERT(entry->currentUsage        == DmiSystemSlotsUsage::AVAILABLE,                 NgosStatus::ASSERTION);                                                                     // Colorize: green
            COMMON_TEST_ASSERT(entry->slotLength          == DmiSystemSlotsLength::UNKNOWN,                  NgosStatus::ASSERTION);                                                                     // Colorize: green
            COMMON_TEST_ASSERT(entry->slotID              == 0x0001,                                         NgosStatus::ASSERTION);                                                                     // Colorize: green
            COMMON_TEST_ASSERT(entry->slotCharacteristics == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION);                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (entryV26 != nullptr)                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entryV26->segmentGroupNumber                           == 1,    NgosStatus::ASSERTION);                                                                               // Colorize: green
                COMMON_TEST_ASSERT(entryV26->busNumber                                    == 1,    NgosStatus::ASSERTION);                                                                               // Colorize: green
                COMMON_TEST_ASSERT(entryV26->functionNumberAndDeviceNumber.functionNumber == 1,    NgosStatus::ASSERTION);                                                                               // Colorize: green
                COMMON_TEST_ASSERT(entryV26->functionNumberAndDeviceNumber.deviceNumber   == 1,    NgosStatus::ASSERTION);                                                                               // Colorize: green
                COMMON_TEST_ASSERT(entryV26->functionNumberAndDeviceNumber.value8         == 0x00, NgosStatus::ASSERTION);                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (entryV32 != nullptr)                                                                                                                                                                 // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entryV32->dataBusWidth                                               == 0,    NgosStatus::ASSERTION);                                                             // Colorize: green
                    COMMON_TEST_ASSERT(entryV32->peerGroupingCount                                          == 1,    NgosStatus::ASSERTION);                                                             // Colorize: green
                    COMMON_TEST_ASSERT(entryV32->peerGroups[0].segmentGroupNumber                           == 1,    NgosStatus::ASSERTION);                                                             // Colorize: green
                    COMMON_TEST_ASSERT(entryV32->peerGroups[0].busNumber                                    == 1,    NgosStatus::ASSERTION);                                                             // Colorize: green
                    COMMON_TEST_ASSERT(entryV32->peerGroups[0].functionNumberAndDeviceNumber.functionNumber == 1,    NgosStatus::ASSERTION);                                                             // Colorize: green
                    COMMON_TEST_ASSERT(entryV32->peerGroups[0].functionNumberAndDeviceNumber.deviceNumber   == 1,    NgosStatus::ASSERTION);                                                             // Colorize: green
                    COMMON_TEST_ASSERT(entryV32->peerGroups[0].functionNumberAndDeviceNumber.value8         == 0x00, NgosStatus::ASSERTION);                                                             // Colorize: green
                    COMMON_TEST_ASSERT(entryV32->peerGroups[0].dataBusWidth                                 == 0,    NgosStatus::ASSERTION);                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntryV32) + entryV32->peerGroupingCount * sizeof(DmiSystemSlotsPeerGroup), NgosStatus::ASSERTION);                   // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntryV26), NgosStatus::ASSERTION);                                                                                   // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry), NgosStatus::ASSERTION);                                                                                          // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (entry->slotDesignation.id > 0)                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->slotDesignation)                                                                                                                                              // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("slotDesignation = %s", begin));                                                                                                                                    // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiOnboardDevicesEntry(DmiOnboardDevicesEntry *entry)                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    u8 count = (entry->header.length - sizeof(entry->header)) / sizeof(entry->devices[0]);                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("count = %u", count));                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // entry->devices:                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
                COMMON_LVVV(("entry->devices:"));                                                                                                                                                        // Colorize: green
                COMMON_LVVV(("-------------------------------------"));                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                for (good_I64 i = 0; i < count; ++i)                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("entry->devices[%d].deviceTypeAndEnabled.deviceType = %s",     i, enumToFullString(entry->devices[i].deviceTypeAndEnabled.deviceType)));                                // Colorize: green
                    COMMON_LVVV(("entry->devices[%d].deviceTypeAndEnabled.enabled    = %u",     i, entry->devices[i].deviceTypeAndEnabled.enabled));                                                     // Colorize: green
                    COMMON_LVVV(("entry->devices[%d].deviceTypeAndEnabled.value8     = 0x%02X", i, entry->devices[i].deviceTypeAndEnabled.value8));                                                      // Colorize: green
                    COMMON_LVVV(("entry->devices[%d].description.id                  = %u",     i, entry->devices[i].description.id));                                                                   // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("-------------------------------------"));                                                                                                                                  // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(count                                             == 1,                                    NgosStatus::ASSERTION);                                                        // Colorize: green
            COMMON_TEST_ASSERT(entry->devices[0].deviceTypeAndEnabled.deviceType == DmiOnboardDevicesDeviceType::UNKNOWN, NgosStatus::ASSERTION);                                                        // Colorize: green
            COMMON_TEST_ASSERT(entry->devices[0].deviceTypeAndEnabled.enabled    == 1,                                    NgosStatus::ASSERTION);                                                        // Colorize: green
            COMMON_TEST_ASSERT(entry->devices[0].deviceTypeAndEnabled.value8     == 0x00,                                 NgosStatus::ASSERTION);                                                        // Colorize: green
            COMMON_TEST_ASSERT(entry->devices[0].description.id                  == 1,                                    NgosStatus::ASSERTION);                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesEntry) + sizeof(DmiOnboardDevicesDevice), NgosStatus::ASSERTION);                                                         // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            count > 0                                                                                                                                                                                    // Colorize: green
            &&                                                                                                                                                                                           // Colorize: green
            entry->devices[0].description.id > 0                                                                                                                                                         // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiOemStringsEntry(DmiOemStringsEntry *entry)                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->stringCount = %u", entry->stringCount));                                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION);                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOemStringsEntry), NgosStatus::ASSERTION);                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (entry->stringCount > 0)                                                                                                                                                                      // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(stringId.id == entry->stringCount, NgosStatus::ASSERTION);                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiSystemConfigurationEntry(DmiSystemConfigurationEntry *entry)                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->stringCount = %u", entry->stringCount));                                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION);                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemConfigurationEntry), NgosStatus::ASSERTION);                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (entry->stringCount > 0)                                                                                                                                                                      // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(stringId.id == entry->stringCount, NgosStatus::ASSERTION);                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiBiosLanguageEntry(DmiBiosLanguageEntry *entry)                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->installableLanguages = %u", entry->installableLanguages));                                                                                                              // Colorize: green
            COMMON_LVVV(("entry->flags                = %s", flagsToFullString(entry->flags)));                                                                                                          // Colorize: green
            COMMON_LVVV(("entry->currentLanguage.id   = %u", entry->currentLanguage.id));                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->installableLanguages == 1,                                NgosStatus::ASSERTION);                                                                                  // Colorize: green
            COMMON_TEST_ASSERT(entry->flags                == FLAGS(DmiBiosLanguageFlag::NONE), NgosStatus::ASSERTION);                                                                                  // Colorize: green
            COMMON_TEST_ASSERT(entry->currentLanguage.id   == 1,                                NgosStatus::ASSERTION);                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosLanguageEntry), NgosStatus::ASSERTION);                                                                                             // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            entry->installableLanguages > 0                                                                                                                                                              // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            entry->currentLanguage.id > 0                                                                                                                                                                // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiGroupAssociationsEntry(DmiGroupAssociationsEntry *entry)                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | entry = 0x%p", entry));                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    u8 count = (entry->header.length - sizeof(entry->header) - sizeof(entry->groupName)) / sizeof(entry->items[0]);                                                                                      // Colorize: green
    AVOID_UNUSED(count);                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Output variables                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("entry->groupName.id = %u", entry->groupName.id));                                                                                                                              // Colorize: green
            COMMON_LVVV(("count               = %u", count));                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // entry->items:                                                                                                                                                                             // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
                COMMON_LVVV(("entry->items:"));                                                                                                                                                          // Colorize: green
                COMMON_LVVV(("-------------------------------------"));                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                for (good_I64 i = 0; i < count; ++i)                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_LVVV(("entry->items[%d].type   = %s",     i, enumToFullString(entry->items[i].type)));                                                                                        // Colorize: green
                    COMMON_LVVV(("entry->items[%d].handle = 0x%04X", i, entry->items[i].handle));                                                                                                        // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("-------------------------------------"));                                                                                                                                  // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Check variables                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT(entry->groupName.id    == 1,                  NgosStatus::ASSERTION);                                                                                                     // Colorize: green
            COMMON_TEST_ASSERT(count                  == 1,                  NgosStatus::ASSERTION);                                                                                                     // Colorize: green
            COMMON_TEST_ASSERT(entry->items[0].type   == DmiEntryType::BIOS, NgosStatus::ASSERTION);                                                                                                     // Colorize: green
            COMMON_TEST_ASSERT(entry->items[0].handle == 0x0000,             NgosStatus::ASSERTION);                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiGroupAssociationsEntry) + sizeof(DmiGroupAssociationsItem), NgosStatus::ASSERTION);                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get strings                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (entry->groupName.id > 0)                                                                                                                                                                     // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;                                                                                                            // Colorize: green
            good_Char8 *begin = cur;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            AVOID_UNUSED(begin);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            DmiStringId stringId;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            do                                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (cur[0] == 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    ++stringId;                                                                                                                                                                          // Colorize: green
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (stringId == entry->groupName)                                                                                                                                                    // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("groupName = %s", begin));                                                                                                                                          // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (cur[1] == 0)                                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        break;                                                                                                                                                                           // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    begin = cur + 1;                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                ++cur;                                                                                                                                                                                   // Colorize: green
            } while(true);                                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus DMI::saveDmiPhysicalMemoryArrayEntry(DmiPhysicalMemoryArrayEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    DmiPhysicalMemoryArrayEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntryV27) ? (DmiPhysicalMemoryArrayEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->location                     = %s",     enumToFullString(entry->location)));
            COMMON_LVVV(("entry->use                          = %s",     enumToFullString(entry->use)));
            COMMON_LVVV(("entry->memoryErrorCorrection        = %s",     enumToFullString(entry->memoryErrorCorrection)));
            COMMON_LVVV(("entry->maximumCapacity.value        = 0x%08X", entry->maximumCapacity.value));
            COMMON_LVVV(("entry->maximumCapacity              = %s",     bytesToString(entry->maximumCapacity.size())));
            COMMON_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
            COMMON_LVVV(("entry->numberOfMemoryDevices        = %u",     entry->numberOfMemoryDevices));

            if (entryV27 != nullptr)
            {
                COMMON_LVVV(("entryV27->extendedMaximumCapacity = 0x%016llX", entryV27->extendedMaximumCapacity));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->location                     == DmiPhysicalMemoryArrayLocation::OTHER,                NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->use                          == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY,             NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryErrorCorrection        == DmiPhysicalMemoryArrayErrorCorrection::MULTI_BIT_ECC, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->maximumCapacity.value        == 0x00100000,                                           NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                               NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->numberOfMemoryDevices        == 1,                                                    NgosStatus::ASSERTION);

            if (entryV27 != nullptr)
            {
                // COMMON_TEST_ASSERT(entryV27->extendedMaximumCapacity == 0x0000000000000000, NgosStatus::ASSERTION);

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntry), NgosStatus::ASSERTION);
            }
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    if (entry->use == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY)
    {
        // Set sSystemPhysicalMemoryArrayHandle
        {
            if (sSystemPhysicalMemoryArrayHandle != 0)
            {
                COMMON_LW(("Found 2 or more PHYSICAL_MEMORY_ARRAY entries with SYSTEM_MEMORY use"));
            }

            sSystemPhysicalMemoryArrayHandle = entry->header.handle;
        }



        // Set sSystemPhysicalMemoryArrayCapacity
        {
            if (
                entry->maximumCapacity.value == DMI_PHYSICAL_MEMORY_ARRAY_MAXIMUM_CAPACITY_NEED_TO_EXTEND
                &&
                entryV27
               )
            {
                sSystemPhysicalMemoryArrayCapacity = entryV27->extendedMaximumCapacity;
            }
            else
            {
                sSystemPhysicalMemoryArrayCapacity = entry->maximumCapacity.size();
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiMemoryDeviceEntry(DmiMemoryDeviceEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



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
            COMMON_LVVV(("entry->memoryArrayHandle            = 0x%04X", entry->memoryArrayHandle));
            COMMON_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
            COMMON_LVVV(("entry->totalWidth                   = %u",     entry->totalWidth));
            COMMON_LVVV(("entry->dataWidth                    = %u",     entry->dataWidth));
            COMMON_LVVV(("entry->size.value                   = %u",     entry->size.value));
            COMMON_LVVV(("entry->size.granularity             = %s",     enumToFullString((DmiMemoryDeviceSizeGranularity)entry->size.granularity)));
            COMMON_LVVV(("entry->size.value16                 = 0x%04X", entry->size.value16));
            COMMON_LVVV(("entry->size                         = %s",     bytesToString(entry->size.size())));
            COMMON_LVVV(("entry->formFactor                   = %s",     enumToFullString(entry->formFactor)));
            COMMON_LVVV(("entry->deviceSet                    = %u",     entry->deviceSet));
            COMMON_LVVV(("entry->deviceLocator.id             = %u",     entry->deviceLocator.id));
            COMMON_LVVV(("entry->bankLocator.id               = %u",     entry->bankLocator.id));
            COMMON_LVVV(("entry->memoryType                   = %s",     enumToFullString(entry->memoryType)));
            COMMON_LVVV(("entry->typeDetail                   = %s",     flagsToFullString(entry->typeDetail)));

            if (entryV23 != nullptr)
            {
                COMMON_LVVV(("entryV23->speed           = %u", entryV23->speed));
                COMMON_LVVV(("entryV23->manufacturer.id = %u", entryV23->manufacturer.id));
                COMMON_LVVV(("entryV23->serialNumber.id = %u", entryV23->serialNumber.id));
                COMMON_LVVV(("entryV23->assetTag.id     = %u", entryV23->assetTag.id));
                COMMON_LVVV(("entryV23->partNumber.id   = %u", entryV23->partNumber.id));

                if (entryV26 != nullptr)
                {
                    COMMON_LVVV(("entryV26->attributes.rank   = %u",     entryV26->attributes.rank));
                    COMMON_LVVV(("entryV26->attributes.value8 = 0x%02X", entryV26->attributes.value8));

                    if (entryV27 != nullptr)
                    {
                        COMMON_LVVV(("entryV27->extendedSize.value    = %u",     entryV27->extendedSize.value));
                        COMMON_LVVV(("entryV27->extendedSize.value32  = 0x%08X", entryV27->extendedSize.value32));
                        COMMON_LVVV(("entryV27->extendedSize          = %s",     bytesToString(entryV27->extendedSize.size())));
                        COMMON_LVVV(("entryV27->configuredMemorySpeed = %u",     entryV27->configuredMemorySpeed));

                        if (entryV28 != nullptr)
                        {
                            COMMON_LVVV(("entryV28->minimumVoltage    = %u", entryV28->minimumVoltage));
                            COMMON_LVVV(("entryV28->maximumVoltage    = %u", entryV28->maximumVoltage));
                            COMMON_LVVV(("entryV28->configuredVoltage = %u", entryV28->configuredVoltage));

                            if (entryV32 != nullptr)
                            {
                                COMMON_LVVV(("entryV32->memoryTechnology                        = %s", enumToFullString(entryV32->memoryTechnology)));
                                COMMON_LVVV(("entryV32->memoryOperatingModeCapability           = %s", flagsToFullString(entryV32->memoryOperatingModeCapability)));
                                COMMON_LVVV(("entryV32->firmwareVersion.id                      = %u", entryV32->firmwareVersion.id));
                                COMMON_LVVV(("entryV32->moduleManufacturerID                    = %u", entryV32->moduleManufacturerID));
                                COMMON_LVVV(("entryV32->moduleProductID                         = %u", entryV32->moduleProductID));
                                COMMON_LVVV(("entryV32->memorySubsystemControllerManufacturerID = %u", entryV32->memorySubsystemControllerManufacturerID));
                                COMMON_LVVV(("entryV32->memorySubsystemControllerProductID      = %u", entryV32->memorySubsystemControllerProductID));
                                COMMON_LVVV(("entryV32->nonVolatileSize                         = %u", entryV32->nonVolatileSize));
                                COMMON_LVVV(("entryV32->volatileSize                            = %u", entryV32->volatileSize));
                                COMMON_LVVV(("entryV32->cacheSize                               = %u", entryV32->cacheSize));
                                COMMON_LVVV(("entryV32->logicalSize                             = %u", entryV32->logicalSize));

                                if (entryV33 != nullptr)
                                {
                                    COMMON_LVVV(("entryV33->extendedSpeed                 = %u", entryV33->extendedSpeed));
                                    COMMON_LVVV(("entryV33->extendedConfiguredMemorySpeed = %u", entryV33->extendedConfiguredMemorySpeed));
                                }
                            }
                        }
                    }
                }
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->memoryArrayHandle            == 0x1000,                                      NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                      NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->totalWidth                   == 64,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->dataWidth                    == 64,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->size.value                   == 1024,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->size.granularity             == DmiMemoryDeviceSizeGranularity::_1_MEGABYTE, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->size.value16                 == 0x0400,                                      NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->formFactor                   == DmiMemoryDeviceFormFactor::DIMM,             NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->deviceSet                       == 0,                                           NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceLocator.id             == 1,                                           NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->bankLocator.id               == 2,                                           NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryType                   == DmiMemoryDeviceType::RAM,                    NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->typeDetail                   == FLAGS(DmiMemoryDeviceTypeDetailFlag::OTHER), NgosStatus::ASSERTION);

            if (entryV23 != nullptr)
            {
                // COMMON_TEST_ASSERT(entryV23->speed           == 2133, NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV23->manufacturer.id == 3,    NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV23->serialNumber.id == 4,    NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV23->assetTag.id     == 5,    NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV23->partNumber.id   == 6,    NgosStatus::ASSERTION);

                if (entryV26 != nullptr)
                {
                    // COMMON_TEST_ASSERT(entryV26->attributes.rank   == 2,    NgosStatus::ASSERTION);
                    // COMMON_TEST_ASSERT(entryV26->attributes.value8 == 0x02, NgosStatus::ASSERTION);

                    if (entryV27 != nullptr)
                    {
                        // COMMON_TEST_ASSERT(entryV27->extendedSize.value    == 0,          NgosStatus::ASSERTION);
                        // COMMON_TEST_ASSERT(entryV27->extendedSize.value32  == 0x00000000, NgosStatus::ASSERTION);
                        // COMMON_TEST_ASSERT(entryV27->configuredMemorySpeed == 2133,       NgosStatus::ASSERTION);

                        if (entryV28 != nullptr)
                        {
                            // COMMON_TEST_ASSERT(entryV28->minimumVoltage    == 1200, NgosStatus::ASSERTION);
                            // COMMON_TEST_ASSERT(entryV28->maximumVoltage    == 1200, NgosStatus::ASSERTION);
                            // COMMON_TEST_ASSERT(entryV28->configuredVoltage == 1200, NgosStatus::ASSERTION);

                            if (entryV32 != nullptr)
                            {
                                COMMON_TEST_ASSERT(entryV32->memoryTechnology                        == DmiMemoryDeviceTechnology::NONE,                         NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->memoryOperatingModeCapability           == FLAGS(DmiMemoryDeviceOperatingModeCapabilityFlag::NONE), NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->firmwareVersion.id                      == 7,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->moduleManufacturerID                    == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->moduleProductID                         == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->memorySubsystemControllerManufacturerID == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->memorySubsystemControllerProductID      == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->nonVolatileSize                         == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->volatileSize                            == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->cacheSize                               == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->logicalSize                             == 0,                                                       NgosStatus::ASSERTION);

                                if (entryV33 != nullptr)
                                {
                                    // COMMON_TEST_ASSERT(entryV33->extendedSpeed                 == 0, NgosStatus::ASSERTION);
                                    // COMMON_TEST_ASSERT(entryV33->extendedConfiguredMemorySpeed == 0, NgosStatus::ASSERTION);

                                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV33), NgosStatus::ASSERTION);
                                }
                                else
                                {
                                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV32), NgosStatus::ASSERTION);
                                }
                            }
                            else
                            {
                                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV28), NgosStatus::ASSERTION);
                            }
                        }
                        else
                        {
                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV27), NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV26), NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV23), NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId manufacturerStringId;
        DmiStringId serialNumberStringId;
        DmiStringId assetTagStringId;
        DmiStringId partNumberStringId;
        DmiStringId firmwareVersionStringId;

        if (entryV23 != nullptr)
        {
            manufacturerStringId = entryV23->manufacturer;
            serialNumberStringId = entryV23->serialNumber;
            assetTagStringId     = entryV23->assetTag;
            partNumberStringId   = entryV23->partNumber;

            if (entryV32 != nullptr)
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
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->deviceLocator)
                    {
                        COMMON_LVVV(("deviceLocator = %s", begin));
                    }
                    else
                    if (stringId == entry->bankLocator)
                    {
                        COMMON_LVVV(("bankLocator = %s", begin));
                    }
                    else
                    if (stringId == manufacturerStringId)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                    }
                    else
                    if (stringId == serialNumberStringId)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == assetTagStringId)
                    {
                        COMMON_LVVV(("assetTag = %s", begin));
                    }
                    else
                    if (stringId == partNumberStringId)
                    {
                        COMMON_LVVV(("partNumber = %s", begin));
                    }
                    else
                    if (stringId == firmwareVersionStringId)
                    {
                        COMMON_LVVV(("firmwareVersion = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    COMMON_ASSERT_EXECUTION(sMemoryDeviceEntries.append(entry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiBits32MemoryErrorInformationEntry(DmiBits32MemoryErrorInformationEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->errorType               = %s",     enumToFullString(entry->errorType)));
            COMMON_LVVV(("entry->errorGranularity        = %s",     enumToFullString(entry->errorGranularity)));
            COMMON_LVVV(("entry->errorOperation          = %s",     enumToFullString(entry->errorOperation)));
            COMMON_LVVV(("entry->vendorSyndrome          = 0x%08X", entry->vendorSyndrome));
            COMMON_LVVV(("entry->memoryArrayErrorAddress = 0x%08X", entry->memoryArrayErrorAddress));
            COMMON_LVVV(("entry->deviceErrorAddress      = 0x%08X", entry->deviceErrorAddress));
            COMMON_LVVV(("entry->errorResolution         = 0x%08X", entry->errorResolution));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->errorType               == DmiBits32MemoryErrorInformationErrorType::OK,             NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->errorGranularity        == DmiBits32MemoryErrorInformationErrorGranularity::UNKNOWN, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->errorOperation          == DmiBits32MemoryErrorInformationErrorOperation::UNKNOWN,   NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->vendorSyndrome          == 0x80000000,                                               NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryArrayErrorAddress == 0x80000000,                                               NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceErrorAddress      == 0x80000000,                                               NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->errorResolution         == 0x80000000,                                               NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBits32MemoryErrorInformationEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiMemoryArrayMappedAddressEntry(DmiMemoryArrayMappedAddressEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    DmiMemoryArrayMappedAddressEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntryV27) ? (DmiMemoryArrayMappedAddressEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->startingAddress.value = 0x%08X", entry->startingAddress.value));
            COMMON_LVVV(("entry->startingAddress       = %s",     bytesToString(entry->startingAddress.address())));
            COMMON_LVVV(("entry->endingAddress.value   = 0x%08X", entry->endingAddress.value));
            COMMON_LVVV(("entry->endingAddress         = %s",     bytesToString(entry->endingAddress.address())));
            COMMON_LVVV(("entry->memoryArrayHandle     = 0x%04X", entry->memoryArrayHandle));
            COMMON_LVVV(("entry->partitionWidth        = %u",     entry->partitionWidth));

            if (entryV27 != nullptr)
            {
                COMMON_LVVV(("entryV27->extendedStartingAddress = 0x%016llX", entryV27->extendedStartingAddress));
                COMMON_LVVV(("entryV27->extendedEndingAddress   = 0x%016llX", entryV27->extendedEndingAddress));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->startingAddress.value == 0x00000000, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->endingAddress.value   == 0x000FFFFF, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryArrayHandle     == 0x1000,     NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->partitionWidth        == 1,          NgosStatus::ASSERTION);

            if (entryV27 != nullptr)
            {
                // COMMON_TEST_ASSERT(entryV27->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV27->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION);

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntry), NgosStatus::ASSERTION);
            }
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiMemoryDeviceMappedAddressEntry(DmiMemoryDeviceMappedAddressEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    DmiMemoryDeviceMappedAddressEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntryV27) ? (DmiMemoryDeviceMappedAddressEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->startingAddress.value          = 0x%08X", entry->startingAddress.value));
            COMMON_LVVV(("entry->startingAddress                = %s",     bytesToString(entry->startingAddress.address())));
            COMMON_LVVV(("entry->endingAddress.value            = 0x%08X", entry->endingAddress.value));
            COMMON_LVVV(("entry->endingAddress                  = %s",     bytesToString(entry->endingAddress.address())));
            COMMON_LVVV(("entry->memoryDeviceHandle             = 0x%04X", entry->memoryDeviceHandle));
            COMMON_LVVV(("entry->memoryArrayMappedAddressHandle = 0x%04X", entry->memoryArrayMappedAddressHandle));
            COMMON_LVVV(("entry->partitionRowPosition           = %u",     entry->partitionRowPosition));
            COMMON_LVVV(("entry->interleavePosition             = %u",     entry->interleavePosition));
            COMMON_LVVV(("entry->interleavedDataDepth           = %u",     entry->interleavedDataDepth));

            if (entryV27 != nullptr)
            {
                COMMON_LVVV(("entryV27->extendedStartingAddress = 0x%016llX", entryV27->extendedStartingAddress));
                COMMON_LVVV(("entryV27->extendedEndingAddress   = 0x%016llX", entryV27->extendedEndingAddress));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->startingAddress.value          == 0x00000000, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->endingAddress.value            == 0x000FFFFF, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryDeviceHandle             == 0x0000,     NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryArrayMappedAddressHandle == 0x0000,     NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->partitionRowPosition           == 1,          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->interleavePosition             == 1,          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->interleavedDataDepth           == 1,          NgosStatus::ASSERTION);

            if (entryV27 != nullptr)
            {
                // COMMON_TEST_ASSERT(entryV27->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV27->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION);

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntry), NgosStatus::ASSERTION);
            }
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(sMemoryDeviceMappedAddressEntries.append(entry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiPortableBatteryEntry(DmiPortableBatteryEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    DmiPortableBatteryEntryV22 *entryV22 = DMI::getVersion() >= DMI_VERSION(2, 2) && entry->header.length >= sizeof(DmiPortableBatteryEntryV22) ? (DmiPortableBatteryEntryV22 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->location.id               = %u", entry->location.id));
            COMMON_LVVV(("entry->manufacturer.id           = %u", entry->manufacturer.id));
            COMMON_LVVV(("entry->manufactureDate.id        = %u", entry->manufactureDate.id));
            COMMON_LVVV(("entry->serialNumber.id           = %u", entry->serialNumber.id));
            COMMON_LVVV(("entry->deviceName.id             = %u", entry->deviceName.id));
            COMMON_LVVV(("entry->deviceChemistry           = %s", enumToFullString(entry->deviceChemistry)));
            COMMON_LVVV(("entry->designCapacity            = %u", entry->designCapacity));
            COMMON_LVVV(("entry->designVoltage             = %u", entry->designVoltage));
            COMMON_LVVV(("entry->sbdsVersionNumber.id      = %u", entry->sbdsVersionNumber.id));
            COMMON_LVVV(("entry->maximumErrorInBatteryData = %u", entry->maximumErrorInBatteryData));

            if (entryV22 != nullptr)
            {
                COMMON_LVVV(("entryV22->sbdsSerialNumber            = %u",             entryV22->sbdsSerialNumber));
                COMMON_LVVV(("entryV22->sbdsManufactureDate.date    = %u",             entryV22->sbdsManufactureDate.date));
                COMMON_LVVV(("entryV22->sbdsManufactureDate.month   = %u",             entryV22->sbdsManufactureDate.month));
                COMMON_LVVV(("entryV22->sbdsManufactureDate.year    = %u",             entryV22->sbdsManufactureDate.year));
                COMMON_LVVV(("entryV22->sbdsManufactureDate.value16 = 0x%04X",         entryV22->sbdsManufactureDate.value16));
                COMMON_LVVV(("entryV22->sbdsManufactureDate         = %04u-%02u-%02u", entryV22->sbdsManufactureDate.yearReal(), entryV22->sbdsManufactureDate.month, entryV22->sbdsManufactureDate.date));
                COMMON_LVVV(("entryV22->sbdsDeviceChemistry.id      = %u",             entryV22->sbdsDeviceChemistry.id));
                COMMON_LVVV(("entryV22->designCapacityMultiplier    = %u",             entryV22->designCapacityMultiplier));
                COMMON_LVVV(("entryV22->oemSpecific                 = 0x%08X",         entryV22->oemSpecific));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->location.id               == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->manufacturer.id           == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->manufactureDate.id        == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->serialNumber.id           == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceName.id             == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceChemistry           == DmiPortableBatteryDeviceChemistry::OTHER, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->designCapacity            == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->designVoltage             == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->sbdsVersionNumber.id      == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->maximumErrorInBatteryData == 0,                                        NgosStatus::ASSERTION);

            if (entryV22 != nullptr)
            {
                // COMMON_TEST_ASSERT(entryV22->sbdsSerialNumber            == 0,          NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV22->sbdsManufactureDate.date    == 0,          NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV22->sbdsManufactureDate.month   == 0,          NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV22->sbdsManufactureDate.year    == 0,          NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV22->sbdsManufactureDate.value16 == 0x0000,     NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV22->sbdsDeviceChemistry.id      == 0,          NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV22->designCapacityMultiplier    == 0,          NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV22->oemSpecific                 == 0x00000000, NgosStatus::ASSERTION);

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntryV22), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId sbdsDeviceChemistryStringId;

        if (entryV22 != nullptr)
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
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->location)
                    {
                        COMMON_LVVV(("location = %s", begin));
                    }
                    else
                    if (stringId == entry->manufacturer)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                    }
                    else
                    if (stringId == entry->manufactureDate)
                    {
                        COMMON_LVVV(("manufactureDate = %s", begin));
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->deviceName)
                    {
                        COMMON_LVVV(("deviceName = %s", begin));
                    }
                    else
                    if (stringId == entry->sbdsVersionNumber)
                    {
                        COMMON_LVVV(("sbdsVersionNumber = %s", begin));
                    }
                    else
                    if (stringId == sbdsDeviceChemistryStringId)
                    {
                        COMMON_LVVV(("sbdsDeviceChemistry = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemResetEntry(DmiSystemResetEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->capabilities.enabled           = %s",     boolToString(entry->capabilities.enabled)));
            COMMON_LVVV(("entry->capabilities.bootOption        = %s",     enumToFullString((DmiSystemResetBootOption)entry->capabilities.bootOption)));
            COMMON_LVVV(("entry->capabilities.bootOptionOnLimit = %s",     enumToFullString((DmiSystemResetBootOption)entry->capabilities.bootOptionOnLimit)));
            COMMON_LVVV(("entry->capabilities.watchdogEnabled   = %s",     boolToString(entry->capabilities.watchdogEnabled)));
            COMMON_LVVV(("entry->capabilities.value8            = 0x%02X", entry->capabilities.value8));
            COMMON_LVVV(("entry->resetCount                     = %u",     entry->resetCount));
            COMMON_LVVV(("entry->resetLimit                     = %u",     entry->resetLimit));
            COMMON_LVVV(("entry->timerInterval                  = %u",     entry->timerInterval));
            COMMON_LVVV(("entry->timeout                        = %u",     entry->timeout));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->capabilities.enabled           == 1,                                       NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->capabilities.bootOption        == DmiSystemResetBootOption::DO_NOT_REBOOT, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->capabilities.bootOptionOnLimit == DmiSystemResetBootOption::DO_NOT_REBOOT, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->capabilities.watchdogEnabled   == 1,                                       NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->capabilities.value8            == 0x3F,                                    NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->resetCount                     == 0xFFFF,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->resetLimit                     == 0xFFFF,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->timerInterval                  == 0xFFFF,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->timeout                        == 0xFFFF,                                  NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemResetEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiHardwareSecurityEntry(DmiHardwareSecurityEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->settings.frontPanelResetStatus       = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.frontPanelResetStatus)));
            COMMON_LVVV(("entry->settings.administratorPasswordStatus = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.administratorPasswordStatus)));
            COMMON_LVVV(("entry->settings.keyboardPasswordStatus      = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.keyboardPasswordStatus)));
            COMMON_LVVV(("entry->settings.powerOnPasswordStatus       = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.powerOnPasswordStatus)));
            COMMON_LVVV(("entry->settings.value8                      = 0x%02X", entry->settings.value8));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->settings.frontPanelResetStatus       == DmiHardwareSecurityStatus::UNKNOWN,  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->settings.administratorPasswordStatus == DmiHardwareSecurityStatus::ENABLED,  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->settings.keyboardPasswordStatus      == DmiHardwareSecurityStatus::UNKNOWN,  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->settings.powerOnPasswordStatus       == DmiHardwareSecurityStatus::DISABLED, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->settings.value8                      == 0x37,                                NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiHardwareSecurityEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiVoltageProbeEntry(DmiVoltageProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id             = %u",     entry->description.id));
            COMMON_LVVV(("entry->locationAndStatus.location = %s",     enumToFullString((DmiVoltageProbeLocation)entry->locationAndStatus.location)));
            COMMON_LVVV(("entry->locationAndStatus.status   = %s",     enumToFullString((DmiVoltageProbeStatus)entry->locationAndStatus.status)));
            COMMON_LVVV(("entry->locationAndStatus.value8   = 0x%02X", entry->locationAndStatus.value8));
            COMMON_LVVV(("entry->maximumValue               = %u",     entry->maximumValue));
            COMMON_LVVV(("entry->minimumValue               = %u",     entry->minimumValue));
            COMMON_LVVV(("entry->resolution                 = %u",     entry->resolution));
            COMMON_LVVV(("entry->tolerance                  = %u",     entry->tolerance));
            COMMON_LVVV(("entry->accuracy                   = %u",     entry->accuracy));
            COMMON_LVVV(("entry->oemDefined                 = 0x%08X", entry->oemDefined));
            COMMON_LVVV(("entry->nominalValue               = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id             == 1,                              NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.location == DmiVoltageProbeLocation::OTHER, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.status   == DmiVoltageProbeStatus::OTHER,   NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.value8   == 0x00,                           NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->maximumValue               == 0,                              NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->minimumValue               == 0,                              NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->resolution                 == 0,                              NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->tolerance                  == 0,                              NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->accuracy                   == 0,                              NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->oemDefined                 == 0x00000000,                     NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->nominalValue               == 0,                              NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiVoltageProbeEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiCoolingDeviceEntry(DmiCoolingDeviceEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    DmiCoolingDeviceEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiCoolingDeviceEntryV27) ? (DmiCoolingDeviceEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->temperatureProbeHandle         = 0x%04X", entry->temperatureProbeHandle));
            COMMON_LVVV(("entry->deviceTypeAndStatus.deviceType = %s",     enumToFullString((DmiCoolingDeviceType)entry->deviceTypeAndStatus.deviceType)));
            COMMON_LVVV(("entry->deviceTypeAndStatus.status     = %s",     enumToFullString((DmiCoolingDeviceStatus)entry->deviceTypeAndStatus.status)));
            COMMON_LVVV(("entry->deviceTypeAndStatus.value8     = 0x%02X", entry->deviceTypeAndStatus.value8));
            COMMON_LVVV(("entry->coolingUnitGroup               = %u",     entry->coolingUnitGroup));
            COMMON_LVVV(("entry->oemDefined                     = 0x%08X", entry->oemDefined));
            COMMON_LVVV(("entry->nominalSpeed                   = %u",     entry->nominalSpeed));

            if (entryV27 != nullptr)
            {
                COMMON_LVVV(("entryV27->description.id = %u", entryV27->description.id));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->temperatureProbeHandle         == 0x0000,                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceTypeAndStatus.deviceType == DmiCoolingDeviceType::OTHER,   NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceTypeAndStatus.status     == DmiCoolingDeviceStatus::OTHER, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceTypeAndStatus.value8     == 0x00,                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->coolingUnitGroup               == 0,                             NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->oemDefined                     == 0x00000000,                    NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->nominalSpeed                   == 0,                             NgosStatus::ASSERTION);

            if (entryV27 != nullptr)
            {
                // COMMON_TEST_ASSERT(entryV27->description.id == 1, NgosStatus::ASSERTION);

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId descriptionStringId;

        if (entryV27 != nullptr)
        {
            descriptionStringId = entryV27->description;
        }



        if (descriptionStringId.id)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == descriptionStringId)
                    {
                        COMMON_LVVV(("description = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiTemperatureProbeEntry(DmiTemperatureProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id             = %u",     entry->description.id));
            COMMON_LVVV(("entry->locationAndStatus.location = %s",     enumToFullString((DmiTemperatureProbeLocation)entry->locationAndStatus.location)));
            COMMON_LVVV(("entry->locationAndStatus.status   = %s",     enumToFullString((DmiTemperatureProbeStatus)entry->locationAndStatus.status)));
            COMMON_LVVV(("entry->locationAndStatus.value8   = 0x%02X", entry->locationAndStatus.value8));
            COMMON_LVVV(("entry->maximumValue               = %u",     entry->maximumValue));
            COMMON_LVVV(("entry->minimumValue               = %u",     entry->minimumValue));
            COMMON_LVVV(("entry->resolution                 = %u",     entry->resolution));
            COMMON_LVVV(("entry->tolerance                  = %u",     entry->tolerance));
            COMMON_LVVV(("entry->accuracy                   = %u",     entry->accuracy));
            COMMON_LVVV(("entry->oemDefined                 = 0x%08X", entry->oemDefined));
            COMMON_LVVV(("entry->nominalValue               = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id             == 1,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.location == DmiTemperatureProbeLocation::OTHER, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.status   == DmiTemperatureProbeStatus::OTHER,   NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.value8   == 0x00,                               NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->maximumValue               == 0,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->minimumValue               == 0,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->resolution                 == 0,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->tolerance                  == 0,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->accuracy                   == 0,                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->oemDefined                 == 0x00000000,                         NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->nominalValue               == 0,                                  NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiTemperatureProbeEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiElectricalCurrentProbeEntry(DmiElectricalCurrentProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id             = %u",     entry->description.id));
            COMMON_LVVV(("entry->locationAndStatus.location = %s",     enumToFullString((DmiElectricalCurrentProbeLocation)entry->locationAndStatus.location)));
            COMMON_LVVV(("entry->locationAndStatus.status   = %s",     enumToFullString((DmiElectricalCurrentProbeStatus)entry->locationAndStatus.status)));
            COMMON_LVVV(("entry->locationAndStatus.value8   = 0x%02X", entry->locationAndStatus.value8));
            COMMON_LVVV(("entry->maximumValue               = %u",     entry->maximumValue));
            COMMON_LVVV(("entry->minimumValue               = %u",     entry->minimumValue));
            COMMON_LVVV(("entry->resolution                 = %u",     entry->resolution));
            COMMON_LVVV(("entry->tolerance                  = %u",     entry->tolerance));
            COMMON_LVVV(("entry->accuracy                   = %u",     entry->accuracy));
            COMMON_LVVV(("entry->oemDefined                 = 0x%08X", entry->oemDefined));
            COMMON_LVVV(("entry->nominalValue               = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id             == 1,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.location == DmiElectricalCurrentProbeLocation::OTHER, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.status   == DmiElectricalCurrentProbeStatus::OTHER,   NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->locationAndStatus.value8   == 0x00,                                     NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->maximumValue               == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->minimumValue               == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->resolution                 == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->tolerance                  == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->accuracy                   == 0,                                        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->oemDefined                 == 0x00000000,                               NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->nominalValue               == 0,                                        NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiElectricalCurrentProbeEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiOutOfBandRemoteAccessEntry(DmiOutOfBandRemoteAccessEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->manufacturerName.id = %u", entry->manufacturerName.id));
            COMMON_LVVV(("entry->connections         = %s", flagsToFullString(entry->connections)));
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(entry->manufacturerName.id == 1,                                                      NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->connections         == FLAGS(DmiOutOfBandRemoteAccessConnectionFlag::INBOUND), NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOutOfBandRemoteAccessEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->manufacturerName.id)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->manufacturerName)
                    {
                        COMMON_LVVV(("manufacturerName = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemBootEntry(DmiSystemBootEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->bootStatus = %s", enumToFullString(entry->bootStatus)));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->bootStatus == DmiSystemBootStatus::NO_ERROR, NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemBootEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiBits64MemoryErrorInformationEntry(DmiBits64MemoryErrorInformationEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->errorType               = %s",        enumToFullString(entry->errorType)));
            COMMON_LVVV(("entry->errorGranularity        = %s",        enumToFullString(entry->errorGranularity)));
            COMMON_LVVV(("entry->errorOperation          = %s",        enumToFullString(entry->errorOperation)));
            COMMON_LVVV(("entry->vendorSyndrome          = 0x%08X",    entry->vendorSyndrome));
            COMMON_LVVV(("entry->memoryArrayErrorAddress = 0x%016llX", entry->memoryArrayErrorAddress));
            COMMON_LVVV(("entry->deviceErrorAddress      = 0x%016llX", entry->deviceErrorAddress));
            COMMON_LVVV(("entry->errorResolution         = 0x%08X",    entry->errorResolution));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->errorType               == DmiBits64MemoryErrorInformationErrorType::OK,             NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->errorGranularity        == DmiBits64MemoryErrorInformationErrorGranularity::UNKNOWN, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->errorOperation          == DmiBits64MemoryErrorInformationErrorOperation::UNKNOWN,   NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->vendorSyndrome          == 0x80000000,                                               NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->memoryArrayErrorAddress == 0x8000000000000000,                                       NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceErrorAddress      == 0x8000000000000000,                                       NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->errorResolution         == 0x80000000,                                               NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBits64MemoryErrorInformationEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiManagementDeviceEntry(DmiManagementDeviceEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id = %u",     entry->description.id));
            COMMON_LVVV(("entry->type           = %s",     enumToFullString(entry->type)));
            COMMON_LVVV(("entry->address        = 0x%08X", entry->address));
            COMMON_LVVV(("entry->addressType    = %s",     enumToFullString(entry->addressType)));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id == 1,                                     NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->type           == DmiManagementDeviceType::OTHER,        NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->address        == 0x00000000,                            NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->addressType    == DmiManagementDeviceAddressType::OTHER, NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiManagementDeviceComponentEntry(DmiManagementDeviceComponentEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id         = %u",     entry->description.id));
            COMMON_LVVV(("entry->managementDeviceHandle = 0x%04X", entry->managementDeviceHandle));
            COMMON_LVVV(("entry->componentHandle        = 0x%04X", entry->componentHandle));
            COMMON_LVVV(("entry->thresholdHandle        = 0x%04X", entry->thresholdHandle));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id         == 1,      NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->managementDeviceHandle == 0x0000, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->componentHandle        == 0x0000, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->thresholdHandle        == 0x0000, NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceComponentEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiManagementDeviceThresholdDataEntry(DmiManagementDeviceThresholdDataEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->lowerThresholdNonCritical    = %u", entry->lowerThresholdNonCritical));
            COMMON_LVVV(("entry->upperThresholdNonCritical    = %u", entry->upperThresholdNonCritical));
            COMMON_LVVV(("entry->lowerThresholdCritical       = %u", entry->lowerThresholdCritical));
            COMMON_LVVV(("entry->upperThresholdCritical       = %u", entry->upperThresholdCritical));
            COMMON_LVVV(("entry->lowerThresholdNonRecoverable = %u", entry->lowerThresholdNonRecoverable));
            COMMON_LVVV(("entry->upperThresholdNonRecoverable = %u", entry->upperThresholdNonRecoverable));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->lowerThresholdNonCritical    == 0, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->upperThresholdNonCritical    == 0, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->lowerThresholdCritical       == 0, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->upperThresholdCritical       == 0, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->lowerThresholdNonRecoverable == 0, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->upperThresholdNonRecoverable == 0, NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceThresholdDataEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemPowerSupplyEntry(DmiSystemPowerSupplyEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->powerUnitGroup                                     = %u",     entry->powerUnitGroup));
            COMMON_LVVV(("entry->location.id                                        = %u",     entry->location.id));
            COMMON_LVVV(("entry->deviceName.id                                      = %u",     entry->deviceName.id));
            COMMON_LVVV(("entry->manufacturer.id                                    = %u",     entry->manufacturer.id));
            COMMON_LVVV(("entry->serialNumber.id                                    = %u",     entry->serialNumber.id));
            COMMON_LVVV(("entry->assetTagNumber.id                                  = %u",     entry->assetTagNumber.id));
            COMMON_LVVV(("entry->modelPartNumber.id                                 = %u",     entry->modelPartNumber.id));
            COMMON_LVVV(("entry->revisionLevel.id                                   = %u",     entry->revisionLevel.id));
            COMMON_LVVV(("entry->maxPowerCapacity                                   = %u",     entry->maxPowerCapacity));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.hotReplaceable          = %u",     entry->powerSupplyCharacteristics.hotReplaceable));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.present                 = %u",     entry->powerSupplyCharacteristics.present));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.unplugged               = %u",     entry->powerSupplyCharacteristics.unplugged));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.inputVoltageRangeSwitch = %s",     enumToFullString((DmiSystemPowerSupplyInputVoltageRangeSwitch)entry->powerSupplyCharacteristics.inputVoltageRangeSwitch)));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.status                  = %s",     enumToFullString((DmiSystemPowerSupplyStatus)entry->powerSupplyCharacteristics.status)));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.type                    = %s",     enumToFullString((DmiSystemPowerSupplyType)entry->powerSupplyCharacteristics.type)));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.value16                 = 0x%04X", entry->powerSupplyCharacteristics.value16));
            COMMON_LVVV(("entry->inputVoltageProbeHandle                            = 0x%04X", entry->inputVoltageProbeHandle));
            COMMON_LVVV(("entry->coolingDeviceHandle                                = 0x%04X", entry->coolingDeviceHandle));
            COMMON_LVVV(("entry->inputCurrentProbeHandle                            = 0x%04X", entry->inputCurrentProbeHandle));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->powerUnitGroup                                     == 0,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->location.id                                        == 1,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceName.id                                      == 2,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->manufacturer.id                                    == 3,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->serialNumber.id                                    == 4,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->assetTagNumber.id                                  == 5,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->modelPartNumber.id                                 == 6,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->revisionLevel.id                                   == 7,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->maxPowerCapacity                                   == 0,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.hotReplaceable          == 0,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.present                 == 0,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.unplugged               == 0,                                                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.inputVoltageRangeSwitch == DmiSystemPowerSupplyInputVoltageRangeSwitch::OTHER, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.status                  == DmiSystemPowerSupplyStatus::OTHER,                  NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.type                    == DmiSystemPowerSupplyType::OTHER,                    NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.value16                 == 0x0000,                                             NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->inputVoltageProbeHandle                            == 0x0000,                                             NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->coolingDeviceHandle                                == 0x0000,                                             NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->inputCurrentProbeHandle                            == 0x0000,                                             NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemPowerSupplyEntry), NgosStatus::ASSERTION);
        }
    }



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
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->location)
                    {
                        COMMON_LVVV(("location = %s", begin));
                    }
                    else
                    if (stringId == entry->deviceName)
                    {
                        COMMON_LVVV(("deviceName = %s", begin));
                    }
                    else
                    if (stringId == entry->manufacturer)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->assetTagNumber)
                    {
                        COMMON_LVVV(("assetTagNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->modelPartNumber)
                    {
                        COMMON_LVVV(("modelPartNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->revisionLevel)
                    {
                        COMMON_LVVV(("revisionLevel = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiAdditionalInformationEntry(DmiAdditionalInformationEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->numberOfAdditionalInformationEntries = %u", entry->numberOfAdditionalInformationEntries));



            // entry->additionalInformationEntries:
            {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                COMMON_LVVV(("entry->additionalInformationEntries:"));
                COMMON_LVVV(("-------------------------------------"));

                DmiAdditionalInformation *curInfo = &entry->additionalInformationEntries[0];

                for (good_I64 i = 0; i < entry->numberOfAdditionalInformationEntries; ++i)
                {
                    COMMON_LVVV(("curInfo->entryLength      = %u",     curInfo->entryLength));
                    COMMON_LVVV(("curInfo->referencedHandle = 0x%04X", curInfo->referencedHandle));
                    COMMON_LVVV(("curInfo->referencedOffset = %u",     curInfo->referencedOffset));
                    COMMON_LVVV(("curInfo->string.id        = %u",     curInfo->string.id));
                    COMMON_LVVV(("curInfo->value[0]         = 0x%02X", curInfo->value[0]));

                    curInfo = (DmiAdditionalInformation *)((u64)curInfo + curInfo->entryLength);
                }

                COMMON_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->numberOfAdditionalInformationEntries             == 1,      NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].entryLength      == 6,      NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].referencedHandle == 0x0000, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].referencedOffset == 1,      NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].string.id        == 0,      NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].value[0]         == 0x00,   NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiAdditionalInformationEntry) + sizeof(DmiAdditionalInformation), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->numberOfAdditionalInformationEntries > 0)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiOnboardDevicesExtendedEntry(DmiOnboardDevicesExtendedEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->referenceDesignation.id                      = %u",     entry->referenceDesignation.id));
            COMMON_LVVV(("entry->deviceTypeAndEnabled.deviceType              = %s",     enumToFullString((DmiOnboardDevicesExtendedDeviceType)entry->deviceTypeAndEnabled.deviceType)));
            COMMON_LVVV(("entry->deviceTypeAndEnabled.enabled                 = %u",     entry->deviceTypeAndEnabled.enabled));
            COMMON_LVVV(("entry->deviceTypeAndEnabled.value8                  = 0x%02X", entry->deviceTypeAndEnabled.value8));
            COMMON_LVVV(("entry->deviceTypeInstance                           = %u",     entry->deviceTypeInstance));
            COMMON_LVVV(("entry->segmentGroupNumber                           = %u",     entry->segmentGroupNumber));
            COMMON_LVVV(("entry->busNumber                                    = %u",     entry->busNumber));
            COMMON_LVVV(("entry->functionNumberAndDeviceNumber.functionNumber = %u",     entry->functionNumberAndDeviceNumber.functionNumber));
            COMMON_LVVV(("entry->functionNumberAndDeviceNumber.deviceNumber   = %u",     entry->functionNumberAndDeviceNumber.deviceNumber));
            COMMON_LVVV(("entry->functionNumberAndDeviceNumber.value8         = 0x%02X", entry->functionNumberAndDeviceNumber.value8));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->referenceDesignation.id                      == 1,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceTypeAndEnabled.deviceType              == DmiOnboardDevicesExtendedDeviceType::OTHER, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceTypeAndEnabled.enabled                 == 0,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceTypeAndEnabled.value8                  == 0x00,                                       NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceTypeInstance                           == 0,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->segmentGroupNumber                           == 0,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->busNumber                                    == 0,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->functionNumberAndDeviceNumber.functionNumber == 0,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->functionNumberAndDeviceNumber.deviceNumber   == 0,                                          NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->functionNumberAndDeviceNumber.value8         == 0x00,                                       NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesExtendedEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->referenceDesignation.id)
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->referenceDesignation)
                    {
                        COMMON_LVVV(("referenceDesignation = %s", begin));
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
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiInactiveEntry(DmiInactiveEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry != nullptr, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            // Nothing
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiInactiveEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            ((u8 *)entry)[entry->header.length]     != 0
            ||
            ((u8 *)entry)[entry->header.length + 1] != 0
           )
        {
            good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
            good_Char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



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

NgosStatus DMI::storeDmiMemoryDevices()
{
    COMMON_LT((""));



    u64 position = 0;



    for (good_I64 i = 0; i < sMemoryDeviceEntries.getSize(); ++i)
    {
        DmiMemoryDeviceEntry *entry = sMemoryDeviceEntries.at(i);

        DmiMemoryDeviceEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV23) ? (DmiMemoryDeviceEntryV23 *)entry : nullptr;
        DmiMemoryDeviceEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV27) ? (DmiMemoryDeviceEntryV27 *)entry : nullptr;
        DmiMemoryDeviceEntryV32 *entryV32 = DMI::getVersion() >= DMI_VERSION(3, 2) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV32) ? (DmiMemoryDeviceEntryV32 *)entry : nullptr;
        DmiMemoryDeviceEntryV33 *entryV33 = DMI::getVersion() >= DMI_VERSION(3, 3) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV33) ? (DmiMemoryDeviceEntryV33 *)entry : nullptr;



        if (entry->memoryArrayHandle == sSystemPhysicalMemoryArrayHandle)
        {
            DmiMemoryDevice device;



            // Init memory device
            {
                device.memoryType = entry->memoryType;



                // Set speed
                {
                    if (entryV23 != nullptr)
                    {
                        if (entryV23->speed == DMI_MEMORY_DEVICE_SPEED_UNKNOWN)
                        {
                            device.speed = 0;
                        }
                        else
                        if (
                            entryV23->speed == DMI_MEMORY_DEVICE_SPEED_NEED_TO_EXTEND
                            &&
                            entryV33
                           )
                        {
                            device.speed = entryV33->extendedSpeed;
                        }
                        else
                        {
                            device.speed = entryV23->speed;
                        }
                    }
                    else
                    {
                        device.speed = 0;
                    }
                }



                // Set size
                {
                    if (entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_NOT_INSTALLED)
                    {
                        device.size = 0;
                    }
                    else
                    if (entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_UNKNOWN)
                    {
                        device.size = MEMORY_DEVICE_SIZE_UNKNOWN;
                    }
                    else
                    if (
                        entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_NEED_TO_EXTEND
                        &&
                        entryV27
                       )
                    {
                        device.size = entryV27->extendedSize.size();
                    }
                    else
                    {
                        device.size = entry->size.size();
                    }



                    if (
                        device.size != 0
                        &&
                        device.size != MEMORY_DEVICE_SIZE_UNKNOWN
                       )
                    {
                        sTotalAmountOfMemory += device.size;
                    }
                }



                // Set range
                {
                    u64 start = 0xFFFFFFFFFFFFFFFF;
                    u64 end   = 0;

                    for (good_I64 j = 0; j < sMemoryDeviceMappedAddressEntries.getSize(); ++j)
                    {
                        DmiMemoryDeviceMappedAddressEntry *deviceMappedAddress = sMemoryDeviceMappedAddressEntries.at(j);

                        if (deviceMappedAddress->memoryDeviceHandle == entry->header.handle)
                        {
                            DmiMemoryDeviceMappedAddressEntryV27 *deviceMappedAddressV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && deviceMappedAddress->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntryV27) ? (DmiMemoryDeviceMappedAddressEntryV27 *)deviceMappedAddress : nullptr;



                            u64 newStart;
                            u64 newEnd;

                            if (
                                deviceMappedAddress->startingAddress.value == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_STARTING_ADDRESS_NEED_TO_EXTEND
                                &&
                                deviceMappedAddress->endingAddress.value == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_ENDING_ADDRESS_NEED_TO_EXTEND
                                &&
                                deviceMappedAddressV27
                               )
                            {
                                newStart = deviceMappedAddressV27->extendedStartingAddress;
                                newEnd   = deviceMappedAddressV27->extendedEndingAddress;
                            }
                            else
                            {
                                newStart = deviceMappedAddress->startingAddress.address();
                                newEnd   = deviceMappedAddress->endingAddress.address(1);
                            }



                            if (newStart < start)
                            {
                                start = newStart;
                            }

                            if (newEnd > end)
                            {
                                end = newEnd;
                            }
                        }
                    }



                    if (end != 0)
                    {
                        COMMON_TEST_ASSERT(start != 0xFFFFFFFFFFFFFFFF, NgosStatus::ASSERTION);
                        COMMON_TEST_ASSERT(start < end,                 NgosStatus::ASSERTION);

                        device.start = start;
                        device.end   = end;
                    }
                    else
                    {
                        COMMON_TEST_ASSERT(start == 0xFFFFFFFFFFFFFFFF, NgosStatus::ASSERTION);

                        if (!sMemoryDeviceMappedAddressEntries.isEmpty())
                        {
                            device.start = 0;
                            device.end   = 0;
                        }
                        else
                        {
                            if (
                                device.size != 0
                                &&
                                device.size != MEMORY_DEVICE_SIZE_UNKNOWN
                               )
                            {
                                device.start =  position;
                                position     += device.size;
                                device.end   =  position;
                            }
                            else
                            {
                                device.start = 0;
                                device.end   = 0;
                            }
                        }
                    }
                }



                device.deviceLocator = nullptr;
                device.manufacturer  = nullptr;
                device.serialNumber  = nullptr;
                device.partNumber    = nullptr;
            }



            // Get strings
            {
                DmiStringId manufacturerStringId;
                DmiStringId serialNumberStringId;
                DmiStringId assetTagStringId;
                DmiStringId partNumberStringId;
                DmiStringId firmwareVersionStringId;

                if (entryV23 != nullptr)
                {
                    manufacturerStringId = entryV23->manufacturer;
                    serialNumberStringId = entryV23->serialNumber;
                    assetTagStringId     = entryV23->assetTag;
                    partNumberStringId   = entryV23->partNumber;

                    if (entryV32 != nullptr)
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
                    good_Char8 *cur   = reinterpret_cast<good_Char8 *>(entry) + entry->header.length;
                    good_Char8 *begin = cur;

                    AVOID_UNUSED(begin);

                    COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



                    DmiStringId stringId;

                    do
                    {
                        if (cur[0] == 0)
                        {
                            ++stringId;
                            COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                            if (stringId == entry->deviceLocator)
                            {
                                COMMON_ASSERT_EXECUTION(storeString(begin, cur - begin + 1, &device.deviceLocator), NgosStatus::ASSERTION);
                            }
                            else
                            if (stringId == manufacturerStringId)
                            {
                                COMMON_ASSERT_EXECUTION(storeString(begin, cur - begin + 1, &device.manufacturer), NgosStatus::ASSERTION);
                            }
                            else
                            if (stringId == serialNumberStringId)
                            {
                                COMMON_ASSERT_EXECUTION(storeString(begin, cur - begin + 1, &device.serialNumber), NgosStatus::ASSERTION);
                            }
                            else
                            if (stringId == partNumberStringId)
                            {
                                COMMON_ASSERT_EXECUTION(storeString(begin, cur - begin + 1, &device.partNumber), NgosStatus::ASSERTION);
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
                    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length]     == 0, NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT((reinterpret_cast<good_U8 *>(entry))[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
                }
            }



            if (device.size > 0)
            {
                COMMON_ASSERT_EXECUTION(sMemoryDevices.insert(sNumberOfInstalledMemoryDevices, device), NgosStatus::ASSERTION);

                ++sNumberOfInstalledMemoryDevices;
            }
            else
            {
                COMMON_ASSERT_EXECUTION(sMemoryDevices.append(device), NgosStatus::ASSERTION);
            }
        }
    }



    if (sMemoryDevices.isEmpty())
    {
        COMMON_LC(("Failed to get information about memory devices"));

        return NgosStatus::NOT_FOUND;
    }



    return NgosStatus::OK;
}

NgosStatus DMI::storeIdentity(DmiIdentity id, const char8 *address, u64 size)
{
    COMMON_LT((" | id = %u, address = 0x%p, size = %u", id, address, size));

    COMMON_ASSERT(address,  "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is invalid", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(sIdentities[(u64)id] == nullptr, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(storeString(address, size, &sIdentities[(u64)id]), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::storeUuid(DmiStoredUuid id, Uuid *uuid)
{ // Ignore CppNgosTraceVerifier
    COMMON_LT((" | id = %u, uuid = %s", id, uuidToString(uuid)));



    COMMON_TEST_ASSERT(sUuids[(u64)id] == nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sizeof(Uuid)    == 16,      NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in pro file
    sUuids[(u64)id] = uuid;
#else
    u8 *brkAddress;

    COMMON_ASSERT_EXECUTION(BRK::allocate(sizeof(Uuid), 1, &brkAddress), NgosStatus::ASSERTION);
    ((u64 *)brkAddress)[0] = ((u64 *)uuid)[0];
    ((u64 *)brkAddress)[1] = ((u64 *)uuid)[1];

    sUuids[(u64)id] = (Uuid *)brkAddress;
#endif



    return NgosStatus::OK;
}

NgosStatus DMI::storeString(const char8 *address, u64 size, const char8 **destination)
{
    COMMON_LT((" | address = 0x%p, size = %u, destination = 0x%p", address, size, destination));

    COMMON_ASSERT(address,     "address is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,    "size is invalid",     NgosStatus::ASSERTION);
    COMMON_ASSERT(destination, "destination is null", NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in pro file
    *destination = address;

    AVOID_UNUSED(size);
#else
    COMMON_ASSERT_EXECUTION(BRK::allocate(size, 1, (u8 **)destination), NgosStatus::ASSERTION);
    memcpy((char8 *)*destination, address, size);
#endif



    return NgosStatus::OK;
}

good_U8 DMI::checksum(void *address, good_I64 size, good_U8 checksumValue)                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | address = 0x%p, size = %d, checksumValue = %u", address, size, checksumValue));                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(address != nullptr, "address is null", 0);                                                                                                                                             // Colorize: green
    COMMON_ASSERT(size > 0,           "size is invalid", 0);                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    good_U8 *cur = reinterpret_cast<good_U8 *>(address);                                                                                                                                                 // Colorize: green
    good_U8  res = checksumValue;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    while (size > 0)                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        res -= *cur;                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        ++cur;                                                                                                                                                                                           // Colorize: green
        --size;                                                                                                                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
