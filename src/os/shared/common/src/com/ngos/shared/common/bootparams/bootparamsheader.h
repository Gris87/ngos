#ifndef COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMSHEADER_H
#define COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMSHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



#define BOOT_PARAMS_HEADER_SIGNATURE 0x5244482D534F474E // NGOS-HDR



struct BootParamsHeader
{
    u64       signature;           // Always equal to BOOT_PARAMS_HEADER_SIGNATURE
    address_t kernelLocation;      // Address of kernel image
    i64       kernelSize;          // Size of kernel image (Configure part + [De]compressed Kernel part)
    i64       allocatedKernelSize; // kernelSize aligned to page size + page table + stack ( + decompressed Kernel part if it compressed)
};



#endif // COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMSHEADER_H
