#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYDMI_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYDMI_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h>

#include <com/ngos/shared/common/dmi/dmientrytype.h>



class DeviceManagerEntryDMI: public DeviceManagerEntry
{
public:
    DeviceManagerEntryDMI(DmiEntryType type, bad_uint16 handle, DeviceManagerImage image, const char8 *name); // TEST: NO
    ~DeviceManagerEntryDMI(); // TEST: NO

    bool operator<(const DeviceManagerEntryDMI &another) const; // TEST: NO

    NgosStatus setType(DmiEntryType type); // TEST: NO
    DmiEntryType getType() const; // TEST: NO

    NgosStatus setHandle(bad_uint16 handle); // TEST: NO
    bad_uint16 getHandle() const; // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    DmiEntryType mType;
    bad_uint16          mHandle;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERENTRYDMI_H
