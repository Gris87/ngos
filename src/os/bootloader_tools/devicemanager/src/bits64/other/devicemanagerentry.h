#ifndef DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRY_H
#define DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRY_H



#include <common/src/bits64/containers/arraylist.h>

#include "src/bits64/other/devicemanagerentryrecord.h"
#include "src/bits64/other/devicemanagerimage.h"



class DeviceManagerEntry
{
public:
    DeviceManagerEntry(DeviceManagerImage image, const char8 *name); // TEST: NO
    virtual ~DeviceManagerEntry(); // TEST: NO

    NgosStatus addRecord(const char8 *name, const char8 *value); // TEST: NO
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



#endif // DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRY_H
