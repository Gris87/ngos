#ifndef GPT_GPTDATA_H
#define GPT_GPTDATA_H



#include <gpt/gptentry.h>
#include <gpt/gptheader.h>
#include <mbr/mbr.h>



struct GptData
{
    Mbr       *protectiveMbr;
    GptHeader *header;
    GptEntry  *entries;
};



#endif // GPT_GPTDATA_H
