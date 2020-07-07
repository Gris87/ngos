#ifndef DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRY_H
#define DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRY_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentryrecord.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerimage.h>
#include <com/ngos/shared/common/containers/arraylist.h>



class DeviceManagerEntry
{
public:
    DeviceManagerEntry(DeviceManagerImage image, const char8 *name); // TEST: NO
    virtual ~DeviceManagerEntry(); // TEST: NO

    NgosStatus addRecord(const char8 *name, const char8 *value, DeviceManagerMode mode); // TEST: NO
    const ArrayList<DeviceManagerEntryRecord *>& getRecords(); // TEST: NO

    NgosStatus setImage(DeviceManagerImage image); // TEST: NO
    DeviceManagerImage getImage() const; // TEST: NO

    NgosStatus setName(const char8 *name); // TEST: NO
    const char8* getName() const; // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    DeviceManagerImage                     mImage;
    const char8                           *mName;
    ArrayList<DeviceManagerEntryRecord *>  mRecords;
};



#endif // DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRY_H
