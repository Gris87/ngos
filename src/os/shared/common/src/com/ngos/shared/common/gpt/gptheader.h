#ifndef COM_NGOS_SHARED_COMMON_GPT_GPTHEADER_H
#define COM_NGOS_SHARED_COMMON_GPT_GPTHEADER_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/ngos/types.h>



#define GPT_HEADER_SIGNATURE 0x5452415020494645 // "EFI PART"
#define GPT_HEADER_REVISION  0x00010000



struct GptHeader
{
    bad_uint64  signature;
    bad_uint32  revision;
    bad_uint32  headerSize;
    bad_uint32  headerCrc32;
    bad_uint32  __reserved;
    bad_uint64  currentLba;
    bad_uint64  backupLba;
    bad_uint64  firstUsableLba;
    bad_uint64  lastUsableLba;
    Guid diskGuid;
    bad_uint64  entryLba;
    bad_uint32  entryCount;
    bad_uint32  entrySize;
    bad_uint32  entryCrc32;
};



#endif // COM_NGOS_SHARED_COMMON_GPT_GPTHEADER_H
