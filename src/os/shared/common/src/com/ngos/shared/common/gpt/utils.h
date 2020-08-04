#ifndef COM_NGOS_SHARED_COMMON_GPT_UTILS_H
#define COM_NGOS_SHARED_COMMON_GPT_UTILS_H



#include <com/ngos/shared/common/checksum/crc.h>
#include <com/ngos/shared/common/gpt/gptdata.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



inline bool isGptValid(const GptData &data) // TEST: NO
{
    COMMON_LT((" | data = ..."));



    if (
        !data.protectiveMbr // data.protectiveMbr == 0
        ||
        !data.header // data.header == 0
       )
    {
        return false;
    }



    if (
        data.protectiveMbr->bootSignature != MBR_BOOT_SIGNATURE
        ||
        (
         data.protectiveMbr->partitions[0].type != MbrPartitionType::GPT_PROTECTIVE_MBR
         &&
         data.protectiveMbr->partitions[1].type != MbrPartitionType::GPT_PROTECTIVE_MBR
         &&
         data.protectiveMbr->partitions[2].type != MbrPartitionType::GPT_PROTECTIVE_MBR
         &&
         data.protectiveMbr->partitions[3].type != MbrPartitionType::GPT_PROTECTIVE_MBR
        )
       )
    {
        return false;
    }



    if (
        data.header->signature != GPT_HEADER_SIGNATURE
        ||
        data.header->revision != GPT_HEADER_REVISION
        ||
        data.header->entrySize != sizeof(GptEntry)
       )
    {
        return false;
    }



    u32 crc                  = data.header->headerCrc32;
    data.header->headerCrc32 = 0;

    u32 calculatedCrc        = Crc::crc32((u8 *)data.header, data.header->headerSize);
    data.header->headerCrc32 = crc;



    return calculatedCrc == crc;
}



#endif // COM_NGOS_SHARED_COMMON_GPT_UTILS_H
