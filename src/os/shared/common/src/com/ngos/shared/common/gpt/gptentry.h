#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTENTRY_H



#include <common/src/com/ngos/shared/common/guid/guid.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct GptEntry
{
    Guid   partitionTypeGuid;
    Guid   partitionUniqueGuid;
    u64    startLba;
    u64    endLba;
    u64    attributes;
    char16 name[36];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTENTRY_H
