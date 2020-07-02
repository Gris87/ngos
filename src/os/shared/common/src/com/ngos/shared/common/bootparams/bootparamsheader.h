#ifndef BOOTPARAMS_BOOTPARAMSHEADER_H
#define BOOTPARAMS_BOOTPARAMSHEADER_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



#define BOOT_PARAMS_HEADER_SIGNATURE 0x5244482D534F474E // NGOS-HDR



struct BootParamsHeader
{
    u64 signature;           // Always equal to BOOT_PARAMS_HEADER_SIGNATURE
    u64 kernelLocation;      // Address of kernel image
    u64 kernelSize;          // Size of kernel image (Configure part + [De]compressed Kernel part)
    u64 allocatedKernelSize; // kernelSize aligned to page size + page table + stack ( + decompressed Kernel part if it compressed)
};



#endif // BOOTPARAMS_BOOTPARAMSHEADER_H
