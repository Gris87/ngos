#ifndef DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYRECORD_H
#define DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYRECORD_H



#include <ngos/status.h>

#include "src/com/ngos/bootloader_tools/devicemanager/other/devicemanagermode.h"



class DeviceManagerEntryRecord
{
public:
    DeviceManagerEntryRecord(const char8 *name, const char8 *value, DeviceManagerMode mode); // TEST: NO

    NgosStatus setName(const char8 *name); // TEST: NO
    const char8* getName() const; // TEST: NO

    NgosStatus setValue(const char8 *value); // TEST: NO
    const char8* getValue() const; // TEST: NO

    NgosStatus setMode(DeviceManagerMode mode); // TEST: NO
    DeviceManagerMode getMode() const; // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    const char8       *mName;
    const char8       *mValue;
    DeviceManagerMode  mMode;
};



#endif // DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYRECORD_H
