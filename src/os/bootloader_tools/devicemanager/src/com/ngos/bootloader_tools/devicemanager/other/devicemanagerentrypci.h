#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYPCI_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYPCI_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h>

#include <com/ngos/shared/common/containers/arraylist.h>



class DeviceManagerEntryPCI: public DeviceManagerEntry
{
public:
    DeviceManagerEntryPCI(DeviceManagerEntryPCI *parent, DeviceManagerImage image, const char8 *name); // TEST: NO
    ~DeviceManagerEntryPCI(); // TEST: NO

    const ArrayList<DeviceManagerEntryPCI *>& getChildren() const; // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    ArrayList<DeviceManagerEntryPCI *> mChildren;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYPCI_H
