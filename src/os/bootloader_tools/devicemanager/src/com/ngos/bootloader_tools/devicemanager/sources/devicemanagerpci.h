#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/pci/capability/pciacceleratedgraphicsport8xcapability.h>
#include <com/ngos/shared/common/pci/capability/pciacceleratedgraphicsportcapability.h>
#include <com/ngos/shared/common/pci/capability/pcicentralresourcecontrolcapability.h>
#include <com/ngos/shared/common/pci/capability/pcidebugportcapability.h>
#include <com/ngos/shared/common/pci/capability/pciexpresscapability.h>
#include <com/ngos/shared/common/pci/capability/pciextendedbridgecapability.h>
#include <com/ngos/shared/common/pci/capability/pciextendeddevicecapability.h>
#include <com/ngos/shared/common/pci/capability/pcihotplugcapability.h>
#include <com/ngos/shared/common/pci/capability/pcihotswapcapability.h>
#include <com/ngos/shared/common/pci/capability/pcihypertransportcapability.h>
#include <com/ngos/shared/common/pci/capability/pcihypertransporthostsecondaryinterfaceblockcapability.h>
#include <com/ngos/shared/common/pci/capability/pcihypertransportslaveprimaryinterfaceblockcapability.h>
#include <com/ngos/shared/common/pci/capability/pcimessagesignaledinterrupts64capability.h>
#include <com/ngos/shared/common/pci/capability/pcimessagesignaledinterrupts64pervectormaskingcapability.h>
#include <com/ngos/shared/common/pci/capability/pcimessagesignaledinterruptscapability.h>
#include <com/ngos/shared/common/pci/capability/pcimessagesignaledinterruptsextendedcapability.h>
#include <com/ngos/shared/common/pci/capability/pcipowermanagementinterfacecapability.h>
#include <com/ngos/shared/common/pci/capability/pcisecuredevicecapability.h>
#include <com/ngos/shared/common/pci/capability/pcislotnumberingcapability.h>
#include <com/ngos/shared/common/pci/capability/pcivendorcapability.h>
#include <com/ngos/shared/common/pci/capability/pcivitalproductdatacapability.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>
#include <com/ngos/shared/common/pci/pciconfigurationspace.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>
#include <com/ngos/shared/common/pci/pciextendedconfigurationspace.h>
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
    static NgosStatus initPciWithConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function); // TEST: NO
    static NgosStatus initPciWithDeviceConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function); // TEST: NO
    static NgosStatus initPciWithBridgeConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function); // TEST: NO
    static NgosStatus initPciWithCardBusConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function); // TEST: NO
    static NgosStatus initPciWithCapabilitiesPointer(const PciConfigurationSpace &configurationSpace, u8 capabilityPointer, DeviceManagerEntry *deviceManagerEntry, PciHeaderType headerType, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function); // TEST: NO
    static NgosStatus initPciWithCapability(PciCapabilityHeader *capability, DeviceManagerEntry *deviceManagerEntry, PciHeaderType headerType, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function); // TEST: NO
    static NgosStatus initPciWithPciPowerManagementInterfaceCapability(PciPowerManagementInterfaceCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithPciAcceleratedGraphicsPortCapability(PciAcceleratedGraphicsPortCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithPciVitalProductDataCapability(PciVitalProductDataCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithPciSlotNumberingCapability(PciSlotNumberingCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciMessageSignaledInterruptsCapability(PciMessageSignaledInterruptsCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciMessageSignaledInterrupts32Capability(PciMessageSignaledInterruptsCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciMessageSignaledInterrupts64Capability(PciMessageSignaledInterrupts64Capability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciMessageSignaledInterrupts64PerVectorMaskingCapability(PciMessageSignaledInterrupts64PerVectorMaskingCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHotSwapCapability(PciHotSwapCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExtendedCapability(PciCapabilityHeader *capability, DeviceManagerEntry *deviceManagerEntry, PciHeaderType headerType); // TEST: NO
    static NgosStatus initPciExtendedDeviceCapability(PciExtendedDeviceCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExtendedBridgeCapability(PciExtendedBridgeCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHyperTransportCapability(PciHyperTransportCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHyperTransportSlavePrimaryInterfaceBlockCapability(PciHyperTransportSlavePrimaryInterfaceBlockCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHyperTransportHostSecondaryInterfaceBlockCapability(PciHyperTransportHostSecondaryInterfaceBlockCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciVendorCapability(PciVendorCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciDebugPortCapability(PciDebugPortCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciCentralResourceControlCapability(PciCentralResourceControlCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHotPlugCapability(PciHotPlugCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciAcceleratedGraphicsPort8xCapability(PciAcceleratedGraphicsPort8xCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciSecureDeviceCapability(PciSecureDeviceCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressCapability(PciExpressCapability *capability, DeviceManagerEntry *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, i64 bus, i64 device, i64 function); // TEST: NO
    static NgosStatus initPciMessageSignaledInterruptsExtendedCapability(PciMessageSignaledInterruptsExtendedCapability *capability, DeviceManagerEntry *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithExtendedConfigurationSpace(const PciExtendedConfigurationSpace &configurationSpace, DeviceManagerEntry *deviceManagerEntry); // TEST: NO

    static ArrayList<DeviceManagerEntry *> sEntries;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H
