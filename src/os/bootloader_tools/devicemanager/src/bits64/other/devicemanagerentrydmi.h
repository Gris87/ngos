#ifndef DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRYDMI_H
#define DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRYDMI_H



#include "src/bits64/other/devicemanagerentry.h"

#include <common/src/bits64/dmi/dmientrytype.h>



class DeviceManagerEntryDMI: public DeviceManagerEntry
{
public:
    DeviceManagerEntryDMI(DmiEntryType type, u16 handle, DeviceManagerImage image, const char8 *name); // TEST: NO
    ~DeviceManagerEntryDMI(); // TEST: NO

    bool operator<(const DeviceManagerEntryDMI &another) const; // TEST: NO

    NgosStatus setType(DmiEntryType type); // TEST: NO
    DmiEntryType getType() const; // TEST: NO

    NgosStatus setHandle(u16 handle); // TEST: NO
    u16 getHandle() const; // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    DmiEntryType mType;
    u16          mHandle;
};



#endif // DEVICEMANAGER_SRC_BITS64_OTHER_DEVICEMANAGERENTRYDMI_H
