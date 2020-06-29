#ifndef DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DMI_DEVICEMANAGERDMI_H
#define DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DMI_DEVICEMANAGERDMI_H



#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/dmiadditionalinformationentry.h>
#include <common/src/bits64/dmi/entry/dmibaseboardentry.h>
#include <common/src/bits64/dmi/entry/dmibiosentry.h>
#include <common/src/bits64/dmi/entry/dmibioslanguageentry.h>
#include <common/src/bits64/dmi/entry/dmibits32memoryerrorinformationentry.h>
#include <common/src/bits64/dmi/entry/dmibits64memoryerrorinformationentry.h>
#include <common/src/bits64/dmi/entry/dmicacheentry.h>
#include <common/src/bits64/dmi/entry/dmichassisentry.h>
#include <common/src/bits64/dmi/entry/dmicoolingdeviceentry.h>
#include <common/src/bits64/dmi/entry/dmielectricalcurrentprobeentry.h>
#include <common/src/bits64/dmi/entry/dmigroupassociationsentry.h>
#include <common/src/bits64/dmi/entry/dmihardwaresecurityentry.h>
#include <common/src/bits64/dmi/entry/dmiinactiveentry.h>
#include <common/src/bits64/dmi/entry/dmimanagementdevicecomponententry.h>
#include <common/src/bits64/dmi/entry/dmimanagementdeviceentry.h>
#include <common/src/bits64/dmi/entry/dmimanagementdevicethresholddataentry.h>
#include <common/src/bits64/dmi/entry/dmimemoryarraymappedaddressentry.h>
#include <common/src/bits64/dmi/entry/dmimemorydeviceentry.h>
#include <common/src/bits64/dmi/entry/dmimemorydevicemappedaddressentry.h>
#include <common/src/bits64/dmi/entry/dmioemstringsentry.h>
#include <common/src/bits64/dmi/entry/dmionboarddevicesentry.h>
#include <common/src/bits64/dmi/entry/dmionboarddevicesextendedentry.h>
#include <common/src/bits64/dmi/entry/dmioutofbandremoteaccessentry.h>
#include <common/src/bits64/dmi/entry/dmiphysicalmemoryarrayentry.h>
#include <common/src/bits64/dmi/entry/dmiportablebatteryentry.h>
#include <common/src/bits64/dmi/entry/dmiportconnectorentry.h>
#include <common/src/bits64/dmi/entry/dmiprocessorentry.h>
#include <common/src/bits64/dmi/entry/dmisystembootentry.h>
#include <common/src/bits64/dmi/entry/dmisystemconfigurationentry.h>
#include <common/src/bits64/dmi/entry/dmisystementry.h>
#include <common/src/bits64/dmi/entry/dmisystempowersupplyentry.h>
#include <common/src/bits64/dmi/entry/dmisystemresetentry.h>
#include <common/src/bits64/dmi/entry/dmisystemslotsentry.h>
#include <common/src/bits64/dmi/entry/dmitemperatureprobeentry.h>
#include <common/src/bits64/dmi/entry/dmivoltageprobeentry.h>

#include "src/com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrydmi.h"



class DeviceManagerDMI
{
public:
    static NgosStatus init(); // TEST: NO

    static const ArrayList<DeviceManagerEntryDMI *>& getEntries(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus decodeDmiEntry(DmiEntryHeader *header); // TEST: NO
    static NgosStatus saveDmiBiosEntry(DmiBiosEntry *entry); // TEST: NO
    static NgosStatus saveDmiSystemEntry(DmiSystemEntry *entry); // TEST: NO
    static NgosStatus saveDmiBaseboardEntry(DmiBaseboardEntry *entry); // TEST: NO
    static NgosStatus saveDmiChassisEntry(DmiChassisEntry *entry); // TEST: NO
    static NgosStatus saveDmiProcessorEntry(DmiProcessorEntry *entry); // TEST: NO
    static NgosStatus saveDmiCacheEntry(DmiCacheEntry *entry); // TEST: NO
    static NgosStatus saveDmiPortConnectorEntry(DmiPortConnectorEntry *entry); // TEST: NO
    static NgosStatus saveDmiSystemSlotsEntry(DmiSystemSlotsEntry *entry); // TEST: NO
    static NgosStatus saveDmiOnboardDevicesEntry(DmiOnboardDevicesEntry *entry); // TEST: NO
    static NgosStatus saveDmiOemStringsEntry(DmiOemStringsEntry *entry); // TEST: NO
    static NgosStatus saveDmiSystemConfigurationEntry(DmiSystemConfigurationEntry *entry); // TEST: NO
    static NgosStatus saveDmiBiosLanguageEntry(DmiBiosLanguageEntry *entry); // TEST: NO
    static NgosStatus saveDmiGroupAssociationsEntry(DmiGroupAssociationsEntry *entry); // TEST: NO
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

    static ArrayList<DeviceManagerEntryDMI *> sEntries;
};



#endif // DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DMI_DEVICEMANAGERDMI_H