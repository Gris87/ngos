#ifndef DEVICEMANAGERMEMORYMAP_H
#define DEVICEMANAGERMEMORYMAP_H



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



#endif // DEVICEMANAGERMEMORYMAP_H
