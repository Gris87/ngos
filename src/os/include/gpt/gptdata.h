#ifndef GPT_GPTDATA_H
#define GPT_GPTDATA_H



#include <mbr/mbr.h>
#include <gpt/gptheader.h>
#include <gpt/gptentry.h>



struct GptData
{
    Mbr       *protectiveMbr;
    GptHeader *header;
    GptEntry  *entries;
};



#endif // GPT_GPTDATA_H
