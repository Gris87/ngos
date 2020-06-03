#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIOUTOFBANDREMOTEACCESSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIOUTOFBANDREMOTEACCESSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmistringid.h>
#include <common/src/bits64/dmi/entry/lib/dmioutofbandremoteaccessconnectionflags.h>



struct DmiOutOfBandRemoteAccessEntry
{
    DmiEntryHeader                          header;
    DmiStringId                             manufacturerName;
    DmiOutOfBandRemoteAccessConnectionFlags connections;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIOUTOFBANDREMOTEACCESSENTRY_H
