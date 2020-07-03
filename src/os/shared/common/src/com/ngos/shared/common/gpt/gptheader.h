#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTHEADER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTHEADER_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/ngos/types.h>



#define GPT_HEADER_SIGNATURE 0x5452415020494645 // "EFI PART"
#define GPT_HEADER_REVISION  0x00010000



struct GptHeader
{
    u64  signature;
    u32  revision;
    u32  headerSize;
    u32  headerCrc32;
    u32  __reserved;
    u64  currentLba;
    u64  backupLba;
    u64  firstUsableLba;
    u64  lastUsableLba;
    Guid diskGuid;
    u64  entryLba;
    u32  entryCount;
    u32  entrySize;
    u32  entryCrc32;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTHEADER_H
