#ifndef COM_NGOS_SHARED_COMMON_DMI_DMI_H                                                                                                                                                                 // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_DMI_H                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/containers/arraylist.h>                                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmiidentity.h>                                                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmimemorydevice.h>                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmistoreduuid.h>                                                                                                                                                // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmiversion.h>                                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmiadditionalinformationentry.h>                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmibaseboardentry.h>                                                                                                                                      // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmibiosentry.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmibioslanguageentry.h>                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmibits32memoryerrorinformationentry.h>                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmibits64memoryerrorinformationentry.h>                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmicacheentry.h>                                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmichassisentry.h>                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmicoolingdeviceentry.h>                                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmielectricalcurrentprobeentry.h>                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmigroupassociationsentry.h>                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmihardwaresecurityentry.h>                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmiinactiveentry.h>                                                                                                                                       // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmimanagementdevicecomponententry.h>                                                                                                                      // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmimanagementdeviceentry.h>                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmimanagementdevicethresholddataentry.h>                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmimemoryarraymappedaddressentry.h>                                                                                                                       // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmimemorydeviceentry.h>                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmimemorydevicemappedaddressentry.h>                                                                                                                      // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmioemstringsentry.h>                                                                                                                                     // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmionboarddevicesentry.h>                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmionboarddevicesextendedentry.h>                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmioutofbandremoteaccessentry.h>                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmiphysicalmemoryarrayentry.h>                                                                                                                            // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmiportablebatteryentry.h>                                                                                                                                // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmiportconnectorentry.h>                                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmiprocessorentry.h>                                                                                                                                      // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmisystembootentry.h>                                                                                                                                     // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmisystemconfigurationentry.h>                                                                                                                            // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmisystementry.h>                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmisystempowersupplyentry.h>                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmisystemresetentry.h>                                                                                                                                    // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmisystemslotsentry.h>                                                                                                                                    // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmitemperatureprobeentry.h>                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/dmivoltageprobeentry.h>                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/ngos/status.h>                                                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/uefi/config/uefismbios3configurationtable.h>                                                                                                                            // Colorize: green
#include <com/ngos/shared/common/uefi/config/uefismbiosconfigurationtable.h>                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
typedef NgosStatus (*process_dmi_entry) (DmiEntryHeader *header);                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class DMI                                                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    static NgosStatus init(); // TEST: NO                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static NgosStatus iterateDmiEntries(good_U8 *buf, process_dmi_entry processDmiEntry);                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static const DmiVersion& getVersion(); // TEST: NO                                                                                                                                                   // Colorize: green
    static good_U8* getStructureTableAddress(); // TEST: NO                                                                                                                                        // Colorize: green
    static good_I64 getSystemPhysicalMemoryArrayCapacity(); // TEST: NO                                                                                                                                  // Colorize: green
    static good_I64 getTotalAmountOfMemory(); // TEST: NO                                                                                                                                                // Colorize: green
    static good_I64 getNumberOfInstalledMemoryDevices(); // TEST: NO                                                                                                                                     // Colorize: green
    static const ArrayList<DmiMemoryDevice>& getMemoryDevices(); // TEST: NO                                                                                                                             // Colorize: green
    static const good_Char8* getIdentity(DmiIdentity id); // TEST: NO                                                                                                                                    // Colorize: green
    static Uuid* getUuid(DmiStoredUuid id); // TEST: NO                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_TEST_MODE == OPTION_YES                                                                                                                                                                   // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
#else                                                                                                                                                                                                    // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
    static NgosStatus initFromSmbios3(UefiSmbios3ConfigurationTable *smbios3); // TEST: NO                                                                                                               // Colorize: green
    static NgosStatus initFromSmbios(UefiSmbiosConfigurationTable *smbios); // TEST: NO                                                                                                                  // Colorize: green
    static NgosStatus decodeDmiEntry(DmiEntryHeader *header); // TEST: NO                                                                                                                                // Colorize: green
    static NgosStatus saveDmiBiosEntry(DmiBiosEntry *entry); // TEST: NO                                                                                                                                 // Colorize: green
    static NgosStatus saveDmiSystemEntry(DmiSystemEntry *entry); // TEST: NO                                                                                                                             // Colorize: green
    static NgosStatus saveDmiBaseboardEntry(DmiBaseboardEntry *entry); // TEST: NO                                                                                                                       // Colorize: green
    static NgosStatus saveDmiChassisEntry(DmiChassisEntry *entry); // TEST: NO                                                                                                                           // Colorize: green
    static NgosStatus saveDmiProcessorEntry(DmiProcessorEntry *entry); // TEST: NO                                                                                                                       // Colorize: green
    static NgosStatus saveDmiCacheEntry(DmiCacheEntry *entry); // TEST: NO                                                                                                                               // Colorize: green
    static NgosStatus saveDmiPortConnectorEntry(DmiPortConnectorEntry *entry); // TEST: NO                                                                                                               // Colorize: green
    static NgosStatus saveDmiSystemSlotsEntry(DmiSystemSlotsEntry *entry); // TEST: NO                                                                                                                   // Colorize: green
    static NgosStatus saveDmiOnboardDevicesEntry(DmiOnboardDevicesEntry *entry); // TEST: NO                                                                                                             // Colorize: green
    static NgosStatus saveDmiOemStringsEntry(DmiOemStringsEntry *entry); // TEST: NO                                                                                                                     // Colorize: green
    static NgosStatus saveDmiSystemConfigurationEntry(DmiSystemConfigurationEntry *entry); // TEST: NO                                                                                                   // Colorize: green
    static NgosStatus saveDmiBiosLanguageEntry(DmiBiosLanguageEntry *entry); // TEST: NO                                                                                                                 // Colorize: green
    static NgosStatus saveDmiGroupAssociationsEntry(DmiGroupAssociationsEntry *entry); // TEST: NO                                                                                                       // Colorize: green
    static NgosStatus saveDmiPhysicalMemoryArrayEntry(DmiPhysicalMemoryArrayEntry *entry); // TEST: NO
    static NgosStatus saveDmiMemoryDeviceEntry(DmiMemoryDeviceEntry *entry); // TEST: NO
    static NgosStatus saveDmiBits32MemoryErrorInformationEntry(DmiBits32MemoryErrorInformationEntry *entry); // TEST: NO
    static NgosStatus saveDmiMemoryArrayMappedAddressEntry(DmiMemoryArrayMappedAddressEntry *entry); // TEST: NO
    static NgosStatus saveDmiMemoryDeviceMappedAddressEntry(DmiMemoryDeviceMappedAddressEntry *entry); // TEST: NO
    static NgosStatus saveDmiPortableBatteryEntry(DmiPortableBatteryEntry *entry); // TEST: NO
    static NgosStatus saveDmiSystemResetEntry(DmiSystemResetEntry *entry); // TEST: NO
    static NgosStatus saveDmiHardwareSecurityEntry(DmiHardwareSecurityEntry *entry); // TEST: NO
    static NgosStatus saveDmiVoltageProbeEntry(DmiVoltageProbeEntry *entry); // TEST: NO
    static NgosStatus saveDmiCoolingDeviceEntry(DmiCoolingDeviceEntry *entry); // TEST: NO
    static NgosStatus saveDmiTemperatureProbeEntry(DmiTemperatureProbeEntry *entry); // TEST: NO
    static NgosStatus saveDmiElectricalCurrentProbeEntry(DmiElectricalCurrentProbeEntry *entry); // TEST: NO
    static NgosStatus saveDmiOutOfBandRemoteAccessEntry(DmiOutOfBandRemoteAccessEntry *entry); // TEST: NO
    static NgosStatus saveDmiSystemBootEntry(DmiSystemBootEntry *entry); // TEST: NO
    static NgosStatus saveDmiBits64MemoryErrorInformationEntry(DmiBits64MemoryErrorInformationEntry *entry); // TEST: NO
    static NgosStatus saveDmiManagementDeviceEntry(DmiManagementDeviceEntry *entry); // TEST: NO
    static NgosStatus saveDmiManagementDeviceComponentEntry(DmiManagementDeviceComponentEntry *entry); // TEST: NO
    static NgosStatus saveDmiManagementDeviceThresholdDataEntry(DmiManagementDeviceThresholdDataEntry *entry); // TEST: NO
    static NgosStatus saveDmiSystemPowerSupplyEntry(DmiSystemPowerSupplyEntry *entry); // TEST: NO
    static NgosStatus saveDmiAdditionalInformationEntry(DmiAdditionalInformationEntry *entry); // TEST: NO
    static NgosStatus saveDmiOnboardDevicesExtendedEntry(DmiOnboardDevicesExtendedEntry *entry); // TEST: NO
    static NgosStatus saveDmiInactiveEntry(DmiInactiveEntry *entry); // TEST: NO
    static NgosStatus storeDmiMemoryDevices(); // TEST: NO
    static NgosStatus storeIdentity(DmiIdentity id, const char8 *address, u64 size); // TEST: NO
    static NgosStatus storeUuid(DmiStoredUuid id, Uuid *uuid); // TEST: NO
    static NgosStatus storeString(const char8 *address, u64 size, const char8 **destination); // TEST: NO
    static good_U8 checksum(void *address, good_I64 size, good_U8 checksumValue);                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static DmiVersion                                      sVersion;                                                                                                                                     // Colorize: green
    static good_U16                                        sNumberOfSmbiosStructures;                                                                                                                    // Colorize: green
    static good_U8                                        *sStructureTableAddress;                                                                                                                        // Colorize: green
    static good_U32                                        sStructureTableLength;                                                                                                                        // Colorize: green
    static good_U16                                        sSystemPhysicalMemoryArrayHandle;                                                                                                             // Colorize: green
    static good_I64                                        sSystemPhysicalMemoryArrayCapacity;                                                                                                           // Colorize: green
    static good_I64                                        sTotalAmountOfMemory;                                                                                                                          // Colorize: green
    static good_I64                                        sNumberOfInstalledMemoryDevices;                                                                                                               // Colorize: green
    static ArrayList<DmiMemoryDeviceEntry *>               sMemoryDeviceEntries;                                                                                                                         // Colorize: green
    static ArrayList<DmiMemoryDeviceMappedAddressEntry *>  sMemoryDeviceMappedAddressEntries;                                                                                                            // Colorize: green
    static ArrayList<DmiMemoryDevice>                      sMemoryDevices;                                                                                                                               // Colorize: green
    static const good_Char8*                               sIdentities[(u64)DmiIdentity::MAXIMUM];                                                                                                       // Colorize: green
    static Uuid*                                           sUuids[(u64)DmiStoredUuid::MAXIMUM];                                                                                                          // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_DMI_H                                                                                                                                                               // Colorize: green
