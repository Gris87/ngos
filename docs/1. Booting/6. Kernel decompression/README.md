NGOS
====

1.6. Kernel decompression
-------------------------

As we already know from the previous [chapter](../2.%20First%20steps%20in%20the%20kernel/README.md) we jump to the C++ code after registers initialization with the instructions below:

```
    pushq   %rsi                                                                # Push address of boot parameters (RSI) to the stack
    call    extractKernel                                                       # Call extractKernel function
    popq    %rsi                                                                # Restore address of boot parameters back to RSI from the stack
                                                                                #
    cmpq    $0, %rax                                                            # IF result == 0
    je      fail                                                                #   THEN jump to fail
                                                                                #
    jmp     *%rax                                                               # Jump to decompressed kernel
```

Let's go through [extractKernel()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/kernelextraction.cpp#L16) function and explain what we are doing.

```
    EARLY_LT((" | kernelDescriptor = 0x%p, params = 0x%p, decompressedAddress = 0x%p, pageTable = 0x%p", kernelDescriptor, params, decompressedAddress, pageTable));

    EARLY_ASSERT(kernelDescriptor,    "kernelDescriptor is null",    0);
    EARLY_ASSERT(params,              "params is null",              0);
    EARLY_ASSERT(decompressedAddress, "decompressedAddress is null", 0);
    EARLY_ASSERT(pageTable,           "pageTable is null",           0);
```

As we already mention earlier we are providing LT logs for trace logging level at the very beginning of each function in order to provide information about currently executing function.<br/>
We are also doing basic checks for valid parameters at the beginning of function.

```
#if NGOS_BUILD_KERNEL_COMPRESSION != OPTION_KERNEL_COMPRESSION_NONE
    if (decompress(kernelDescriptor->content, decompressedAddress, kernelDescriptor->contentSize, kernelDescriptor->imageSize) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to decompress kernel image(0x%p) to address 0x%p", kernelDescriptor->content, decompressedAddress));

        return 0;
    }

    EARLY_LI(("Kernel decompression completed"));
#endif
```

If the kernel image was compressed we have to decompress it with the selected [compression method](../../0.%20Intro/3.%20Configuration/README.md#-----------ngos_build_kernel_compression-----------).<br/>
Decompressed image should be placed in decompressedAddress space.

Decompression algorithms implemented in [src/os/configure/src/bits64/b_early/main/decompressors](../../../src/os/configure/src/bits64/b_early/main/decompressors) folder.<br/>
Here is the list of included headers:

```
#include "bits64/b_early/main/decompressors/gzip/decompress.h"
#include "bits64/b_early/main/decompressors/xz/decompress.h"
```

### Extracting ELF image

Included kernel image is actually a ELF file and its decompression is not enough yet.<br/>
We have to load it and place kernel binary image in some random place in the memory.

```
    ElfHeader *elfHeader = (ElfHeader *)decompressedAddress;
    EARLY_LVVV(("elfHeader = 0x%p", elfHeader));
```

decompressedAddress points to address where we do the decompression of included kernel image. But it is also points to ELF Header of decompressed ELF file.

```
    u64 elfMemorySize = getElfMemorySize(elfHeader);
    EARLY_LVVV(("elfMemorySize = %u", elfMemorySize));
    EARLY_TEST_ASSERT(elfMemorySize > 0, 0);
```

Here we are calculating amount of memory required for extracted kernel binary image.

```
    u64 physicalAddress = 0;
    u64 virtualAddress  = 0;

    if (getRandomLocation(params, pageTable, elfMemorySize, &physicalAddress, &virtualAddress) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to find location for kernel"));

        return 0;
    }

    EARLY_LI(("Random location for kernel found"));
```

We need to choose random location for kernel binary image for security reasons. This can be done with [getRandomLocation()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/randomization.cpp#L593) function.<br/>
Detailed explanation for this function can be found at the next [chapter](../7.%20Kernel%20address%20space%20layout%20randomization/README.md).

```
    EARLY_ASSERT_EXECUTION(loadElfToAddress(elfHeader, physicalAddress), 0);
    EARLY_LI(("ELF loaded"));
```

Since we have found a random location for kernel we can put it there.

```
    EARLY_ASSERT_EXECUTION(handleRelocations(elfHeader, physicalAddress, virtualAddress), 0);
    EARLY_LI(("Relocations applied"));
```

Kernel image compiled to be loaded at 0xFFFFFFFF80000000 virtual address.<br/>
But we are choosing random virtual address in range 0xFFFFFFFF80000000 - 0xFFFFFFFFC0000000.<br/>
We should iterate all RELA entries in order to make them valid for the chosen virtual address.

We are ready now to perform jump to the extracted kernel binary image.<br/>
It is expected that the entry point for kernel is located at the first byte.
