#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/pci/capability/pciacceleratedgraphicsportcapability.h>
#include <com/ngos/shared/common/pci/capability/pcipowermanagementinterfacecapability.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>
#include <com/ngos/shared/common/pci/pciconfigurationspace.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocol.h>



class DeviceManagerPci
{
public:
    static NgosStatus init(); // TEST: NO

    static const ArrayList<DeviceManagerEntry *>& getEntries(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initPciRootBridgeIoProtocols(); // TEST: NO
    static NgosStatus initPciRootBridgeIoProtocols(Guid *protocol, u64 size); // TEST: NO
    static NgosStatus initPciRootBridgeIoProtocols(Guid *protocol, u64 size, uefi_handle *handles); // TEST: NO
    static NgosStatus initPciRootBridgeIoProtocol(UefiPciRootBridgeIoProtocol *pci, UefiAcpiAddressSpaceDescriptor *resources); // TEST: NO
    static NgosStatus initPcisInBusRange(UefiPciRootBridgeIoProtocol *pci, i64 minimumBus, i64 maximumBus); // TEST: NO
    static NgosStatus initPciWithConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithDeviceConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithBridgeConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithCardBusConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithCapabilitiesPointer(const PciConfigurationSpace &configurationSpace, u8 capabilityPointer, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithCapability(PciCapabilityHeader *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithPciPowerManagementInterfaceCapability(PciPowerManagementInterfaceCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithPciAcceleratedGraphicsPortCapability(PciAcceleratedGraphicsPortCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO

    static ArrayList<DeviceManagerEntry *> sEntries;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H
