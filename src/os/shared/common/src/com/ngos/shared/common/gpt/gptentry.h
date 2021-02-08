#ifndef COM_NGOS_SHARED_COMMON_GPT_GPTENTRY_H
#define COM_NGOS_SHARED_COMMON_GPT_GPTENTRY_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/ngos/types.h>



struct GptEntry
{
    Guid   partitionTypeGuid;
    Guid   partitionUniqueGuid;
    u64    startLba;
    u64    endLba;
    u64    attributes;
    char16 name[36];
};



#endif // COM_NGOS_SHARED_COMMON_GPT_GPTENTRY_H
