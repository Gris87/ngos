#ifndef GPT_GPTDATA_H
#define GPT_GPTDATA_H



#include <common/src/com/ngos/shared/common/gpt/gptentry.h>
#include <common/src/com/ngos/shared/common/gpt/gptheader.h>
#include <common/src/com/ngos/shared/common/mbr/mbr.h>



struct GptData
{
    Mbr       *protectiveMbr;
    GptHeader *header;
    GptEntry  *entries;
};



#endif // GPT_GPTDATA_H
