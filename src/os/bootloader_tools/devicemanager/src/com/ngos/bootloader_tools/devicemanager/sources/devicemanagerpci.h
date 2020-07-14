#ifndef DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H
#define DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h>
#include <com/ngos/shared/common/ngos/status.h>
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

    static ArrayList<DeviceManagerEntry *> sEntries;
};



#endif // DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERPCI_H
