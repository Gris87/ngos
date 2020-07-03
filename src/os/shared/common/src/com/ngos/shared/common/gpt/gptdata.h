#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTDATA_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTDATA_H



#include <com/ngos/shared/common/gpt/gptentry.h>
#include <com/ngos/shared/common/gpt/gptheader.h>
#include <com/ngos/shared/common/mbr/mbr.h>



struct GptData
{
    Mbr       *protectiveMbr;
    GptHeader *header;
    GptEntry  *entries;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GPT_GPTDATA_H
