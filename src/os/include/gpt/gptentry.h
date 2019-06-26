#ifndef GPT_GPTENTRY_H
#define GPT_GPTENTRY_H



#include <guid/guid.h>
#include <ngos/types.h>



struct GptEntry
{
    Guid   partitionTypeGuid;
    Guid   partitionUniqueGuid;
    u64    startLba;
    u64    endLba;
    u64    attributes;
    char16 name[36];
};



#endif // GPT_GPTENTRY_H
