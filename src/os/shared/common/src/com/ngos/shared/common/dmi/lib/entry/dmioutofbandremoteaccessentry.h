#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIOUTOFBANDREMOTEACCESSENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIOUTOFBANDREMOTEACCESSENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmioutofbandremoteaccessconnectionflags.h>



struct DmiOutOfBandRemoteAccessEntry
{
    DmiEntryHeader                          header;
    DmiStringId                             manufacturerName;
    DmiOutOfBandRemoteAccessConnectionFlags connections;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIOUTOFBANDREMOTEACCESSENTRY_H
