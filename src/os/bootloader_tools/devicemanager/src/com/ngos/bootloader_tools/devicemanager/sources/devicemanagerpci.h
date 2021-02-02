#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrypci.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressaccesscontrolservicescapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressadvancederrorreportingcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressaricapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressdeviceserialnumbercapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressdynamicpowerallocationcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpresslatencytolerancereportingcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressmulticastcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpresspowerbudgetingcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressrcrbheadercapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressresizablebaseaddresscapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressrootcomplexeventcollectorendpointassociationcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressrootcomplexinternallinkcontrolcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressrootcomplexlinkdeclarationcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpresstphrequestercapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressvendorspecificcapability.h>
#include <com/ngos/shared/common/pci/capability/extended/pciexpressvirtualchannelcapability.h>
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

    static const ArrayList<DeviceManagerEntryPCI *>& getEntries(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initPciRootBridgeIoProtocols(); // TEST: NO
    static NgosStatus initPciRootBridgeIoProtocols(Guid *protocol, bad_uint64 size); // TEST: NO
    static NgosStatus initPciRootBridgeIoProtocols(Guid *protocol, bad_uint64 size, uefi_handle *handles); // TEST: NO
    static NgosStatus initPciRootBridgeIoProtocol(UefiPciRootBridgeIoProtocol *pci, UefiAcpiAddressSpaceDescriptor *resources); // TEST: NO
    static NgosStatus initPcisInBusRange(UefiPciRootBridgeIoProtocol *pci, bad_int64 minimumBus, bad_int64 maximumBus); // TEST: NO
    static NgosStatus initPciWithConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, bad_int64 bus, bad_int64 device, bad_int64 function); // TEST: NO
    static NgosStatus initPciWithDeviceConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, bad_int64 bus, bad_int64 device, bad_int64 function); // TEST: NO
    static NgosStatus initPciWithBridgeConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, bad_int64 bus, bad_int64 device, bad_int64 function); // TEST: NO
    static NgosStatus initPciWithCardBusConfigurationSpace(const PciConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, bad_int64 bus, bad_int64 device, bad_int64 function); // TEST: NO
    static NgosStatus initPciWithCapabilitiesPointer(const PciConfigurationSpace &configurationSpace, bad_uint8 capabilityPointer, DeviceManagerEntryPCI *deviceManagerEntry, PciHeaderType headerType, UefiPciRootBridgeIoProtocol *pci, bad_int64 bus, bad_int64 device, bad_int64 function); // TEST: NO
    static NgosStatus initPciWithCapability(PciCapabilityHeader *capability, DeviceManagerEntryPCI *deviceManagerEntry, PciHeaderType headerType, UefiPciRootBridgeIoProtocol *pci, bad_int64 bus, bad_int64 device, bad_int64 function); // TEST: NO
    static NgosStatus initPciPowerManagementInterfaceCapability(PciPowerManagementInterfaceCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciAcceleratedGraphicsPortCapability(PciAcceleratedGraphicsPortCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciVitalProductDataCapability(PciVitalProductDataCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciSlotNumberingCapability(PciSlotNumberingCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciMessageSignaledInterruptsCapability(PciMessageSignaledInterruptsCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciMessageSignaledInterrupts32Capability(PciMessageSignaledInterruptsCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciMessageSignaledInterrupts64Capability(PciMessageSignaledInterrupts64Capability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciMessageSignaledInterrupts64PerVectorMaskingCapability(PciMessageSignaledInterrupts64PerVectorMaskingCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHotSwapCapability(PciHotSwapCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExtendedCapability(PciCapabilityHeader *capability, DeviceManagerEntryPCI *deviceManagerEntry, PciHeaderType headerType); // TEST: NO
    static NgosStatus initPciExtendedDeviceCapability(PciExtendedDeviceCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExtendedBridgeCapability(PciExtendedBridgeCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHyperTransportCapability(PciHyperTransportCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHyperTransportSlavePrimaryInterfaceBlockCapability(PciHyperTransportSlavePrimaryInterfaceBlockCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHyperTransportHostSecondaryInterfaceBlockCapability(PciHyperTransportHostSecondaryInterfaceBlockCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciVendorCapability(PciVendorCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciDebugPortCapability(PciDebugPortCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciCentralResourceControlCapability(PciCentralResourceControlCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciHotPlugCapability(PciHotPlugCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciAcceleratedGraphicsPort8xCapability(PciAcceleratedGraphicsPort8xCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciSecureDeviceCapability(PciSecureDeviceCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressCapability(PciExpressCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry, UefiPciRootBridgeIoProtocol *pci, bad_int64 bus, bad_int64 device, bad_int64 function); // TEST: NO
    static NgosStatus initPciMessageSignaledInterruptsExtendedCapability(PciMessageSignaledInterruptsExtendedCapability *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithExtendedConfigurationSpace(const PciExtendedConfigurationSpace &configurationSpace, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciWithExtendedCapability(PciExtendedCapabilityHeader *capability, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressAdvancedErrorReportingCapability(PciExpressAdvancedErrorReportingCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressVirtualChannelCapability(PciExpressVirtualChannelCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressDeviceSerialNumberCapability(PciExpressDeviceSerialNumberCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressPowerBudgetingCapability(PciExpressPowerBudgetingCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressRootComplexLinkDeclarationCapability(PciExpressRootComplexLinkDeclarationCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressRootComplexInternalLinkControlCapability(PciExpressRootComplexInternalLinkControlCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressRootComplexEventCollectorEndpointAssociationCapability(PciExpressRootComplexEventCollectorEndpointAssociationCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressRcrbHeaderCapability(PciExpressRcrbHeaderCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressVendorSpecificCapability(PciExpressVendorSpecificCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressAccessControlServicesCapability(PciExpressAccessControlServicesCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressAriCapability(PciExpressAriCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressMulticastCapability(PciExpressMulticastCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressResizableBaseAddressCapability(PciExpressResizableBaseAddressCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressDynamicPowerAllocationCapability(PciExpressDynamicPowerAllocationCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressTphRequesterCapability(PciExpressTphRequesterCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO
    static NgosStatus initPciExpressLatencyToleranceReportingCapability(PciExpressLatencyToleranceReportingCapability *capability, bad_uint8 capabilityVersion, DeviceManagerEntryPCI *deviceManagerEntry); // TEST: NO

    static ArrayList<DeviceManagerEntryPCI *> sEntries;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H
