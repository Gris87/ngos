#include <bootparams/bootparams.h>
#include <buildconfig.h>
#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <ngos/linkage.h>

#include "src/bits64/b_early/main/decompressors/gzip/decompress.h"
#include "src/bits64/b_early/main/decompressors/xz/decompress.h"
#include "src/bits64/b_early/main/procesself.h"
#include "src/bits64/b_early/main/randomization.h"
#include "src/bits64/other/kerneldescriptor.h"



CPP_EXTERN_C
u64 extractKernel(KernelDescriptor *kernelDescriptor, BootParams *params, u8 *decompressedAddress, u8 *pageTable)
{
    EARLY_LT((" | kernelDescriptor = 0x%p, params = 0x%p, decompressedAddress = 0x%p, pageTable = 0x%p", kernelDescriptor, params, decompressedAddress, pageTable));

    EARLY_ASSERT(kernelDescriptor,    "kernelDescriptor is null",    0);
    EARLY_ASSERT(params,              "params is null",              0);
    EARLY_ASSERT(decompressedAddress, "decompressedAddress is null", 0);
    EARLY_ASSERT(pageTable,           "pageTable is null",           0);



    EARLY_ASSERT_EXECUTION(Assets::init(), 0);
    EARLY_LVV(("Assets initialized"));



    EARLY_ASSERT_EXECUTION(Console::init(), 0);
    EARLY_LVV(("Console initialized"));



#if NGOS_BUILD_KERNEL_COMPRESSION != OPTION_KERNEL_COMPRESSION_NONE
    if (decompress(kernelDescriptor->content, decompressedAddress, kernelDescriptor->contentSize, kernelDescriptor->imageSize) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to decompress kernel image(0x%p) to address 0x%p", kernelDescriptor->content, decompressedAddress));

        return 0;
    }

    EARLY_LI(("Kernel decompression completed"));
#endif



    ElfHeader *elfHeader = (ElfHeader *)decompressedAddress;
    EARLY_LVVV(("elfHeader = 0x%p", elfHeader));



    u64 elfMemorySize = getElfMemorySize(elfHeader);
    EARLY_LVVV(("elfMemorySize = %u", elfMemorySize));
    EARLY_TEST_ASSERT(elfMemorySize > 0, 0);



    u64 physicalAddress = 0;
    u64 virtualAddress  = 0;

    if (getRandomLocation(params, pageTable, elfMemorySize, &physicalAddress, &virtualAddress) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to find location for kernel"));

        return 0;
    }

    EARLY_LI(("Random location for kernel found"));



    EARLY_ASSERT_EXECUTION(loadElfToAddress(elfHeader, physicalAddress), 0);
    EARLY_LI(("ELF loaded"));

    EARLY_ASSERT_EXECUTION(handleRelocations(elfHeader, physicalAddress, virtualAddress), 0);
    EARLY_LI(("Relocations applied"));



    EARLY_LI(("Booting to kernel..."));
    EARLY_LV(("Random physical address: 0x%016lX", physicalAddress));
    EARLY_LV(("Random virtual address:  0x%016lX", virtualAddress));



    //
    // We don't need it anymore. Resetted for safety
    //
    params->header.kernelLocation      = 0;
    params->header.kernelSize          = 0;
    params->header.allocatedKernelSize = 0;



    return physicalAddress;
}
