#ifndef DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRYRECORD_H
#define DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRYRECORD_H



#include <ngos/status.h>



class DeviceManagerEntryRecord
{
public:
    DeviceManagerEntryRecord(const char8 *name, const char8 *value); // TEST: NO

    NgosStatus setName(const char8 *name); // TEST: NO
    const char8* getName() const; // TEST: NO

    NgosStatus setValue(const char8 *value); // TEST: NO
    const char8* getValue() const; // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    const char8 *mName;
    const char8 *mValue;
};



#endif // DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRYRECORD_H
