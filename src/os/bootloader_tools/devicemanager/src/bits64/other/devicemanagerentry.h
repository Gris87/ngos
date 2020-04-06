#ifndef DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRY_H
#define DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRY_H



#include <common/src/bits64/containers/arraylist.h>

#include "src/bits64/other/devicemanagerentryrecord.h"



class DeviceManagerEntry
{
public:
    DeviceManagerEntry(); // TEST: NO
    virtual ~DeviceManagerEntry(); // TEST: NO

    NgosStatus addRecord(const char8 *name, const char8 *value); // TEST: NO
    const ArrayList<DeviceManagerEntryRecord *>& getRecords(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    ArrayList<DeviceManagerEntryRecord *> mRecords;
};



#endif // DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRY_H
