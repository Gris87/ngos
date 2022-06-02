#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERDMI_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERDMI_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrydmi.h>
#include <com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmiadditionalinformationentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmibaseboardentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmibiosentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmibioslanguageentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmibits32memoryerrorinformationentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmibits64memoryerrorinformationentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmicacheentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmichassisentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmicoolingdeviceentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmielectricalcurrentprobeentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmigroupassociationsentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmihardwaresecurityentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmiinactiveentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmimanagementdevicecomponententry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmimanagementdeviceentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmimanagementdevicethresholddataentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmimemoryarraymappedaddressentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmimemorydeviceentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmimemorydevicemappedaddressentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmioemstringsentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmionboarddevicesentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmionboarddevicesextendedentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmioutofbandremoteaccessentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmiphysicalmemoryarrayentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmiportablebatteryentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmiportconnectorentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmiprocessorentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmisystembootentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmisystemconfigurationentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmisystementry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmisystempowersupplyentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmisystemresetentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmisystemslotsentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmitemperatureprobeentry.h>
#include <com/ngos/shared/common/dmi/lib/entry/dmivoltageprobeentry.h>



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



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERDMI_H
