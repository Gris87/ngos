#ifndef GPT_GPTHEADER_H
#define GPT_GPTHEADER_H



#include <guid/guid.h>
#include <ngos/types.h>



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
   u8   __reserved2[420];
};



#endif // GPT_GPTHEADER_H
