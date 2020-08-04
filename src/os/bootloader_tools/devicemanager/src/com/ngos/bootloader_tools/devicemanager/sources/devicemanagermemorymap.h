#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERMEMORYMAP_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERMEMORYMAP_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h>
#include <com/ngos/shared/common/ngos/status.h>



class DeviceManagerMemoryMap
{
public:
    static NgosStatus init(); // TEST: NO

    static DeviceManagerEntry* getEntry(); // TEST: NO

private:
    static DeviceManagerEntry *sEntry;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SOURCES_DEVICEMANAGERMEMORYMAP_H
