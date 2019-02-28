NGOS
====

1.7. Kernel address space layout randomization
----------------------------------------------

We have skipped explanation of [getRandomLocation()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/randomization.cpp#L593) function in the previous [chapter](../6.%20Kernel%20decompression/README.md).<br/>
But getRandomLocation() function is complex and need to be described in details.

Let's go through [getRandomLocation()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/randomization.cpp#L593) function and explain what we are doing.

```
    EARLY_LT((" | params = 0x%p, pageTable = 0x%p, imageSize = %u, physicalAddress = 0x%p, virtualAddress = 0x%p", params, pageTable, imageSize, physicalAddress, virtualAddress));

    EARLY_ASSERT(params,          "params is null",          NgosStatus::ASSERTION);
    EARLY_ASSERT(pageTable,       "pageTable is null",       NgosStatus::ASSERTION);
    EARLY_ASSERT(imageSize > 0,   "imageSize is zero",       NgosStatus::ASSERTION);
    EARLY_ASSERT(physicalAddress, "physicalAddress is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(virtualAddress,  "virtualAddress is null",  NgosStatus::ASSERTION);
```

As we already mention earlier we are providing LT logs for trace logging level at the very beginning of each function in order to provide information about currently executing function.<br/>
We are also doing basic checks for valid parameters at the beginning of function.

### Initialization of page table

Before the kernel will start to find random memory range where the kernel will be loaded, the identity mapped page tables should be initialized.

```
    EARLY_ASSERT_EXECUTION(initializeIdentityMaps(pageTable), NgosStatus::ASSERTION);
```

[initializeIdentityMaps()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/other/pagetable/pagetable.cpp#L117) function do the initial preparations for interacting with page table.

### List of unavailable memory areas

There is a set of memory ranges that allocated during UEFI booting process and still may be interesting for us in future.<br/>
For this reason we should avoid them during random address search.

```
    MemoryArea unavailableMemoryAreas[(u64)UnavailableMemoryArea::AMOUNT_OF_MEMORY_AREAS];

    EARLY_ASSERT_EXECUTION(initUnavailableMemoryAreas(params, unavailableMemoryAreas), NgosStatus::ASSERTION);
```

Let's check [initUnavailableMemoryAreas()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/randomization.cpp#L194) function.

```
    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_ZERO_PAGE,        0,                             PMD_SIZE,                                                          false), NgosStatus::ASSERTION);
```

With this memory range we are avoiding random address at zero page.

[addUnavailableMemoryArea()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/randomization.cpp#L169) function simply fills memory area with the specified range and calls [addIdentityMap()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/other/pagetable/pagetable.cpp#L152) function if needed.

```
    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_BOOT_PARAMS,      (u64)params,                   sizeof(*params),                                                   true),  NgosStatus::ASSERTION);
```

Here we are avoiding memory range for boot parameters.<br/>
We are also calling [addIdentityMap()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/other/pagetable/pagetable.cpp#L152) function in order to provide access to this memory range after calling [finalizeIdentityMaps()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/other/pagetable/pagetable.cpp#L176) function that applying new page table.

```
    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_RELOCATED_KERNEL, params->header.kernelLocation, params->header.allocatedKernelSize,                                true),  NgosStatus::ASSERTION);
```

This memory range is used for currently executed kernel image in relocated kernel space.<br/>
We should provide access to this memory range to let kernel finish with the remaining instructions before jumping to extracted kernel binary image.

```
    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_MEMORY_MAP,       (u64)params->memoryMapEntries, params->memoryMapEntriesCount * sizeof(*params->memoryMapEntries), false), NgosStatus::ASSERTION);
```

And the last one is the memory range for memory map.

```
    // We don't need to include params->pciRomImages to areas
```

We should also avoid memory ranges for PCI ROM images. But the amount of such devices may be huge.<br/>
We will directly check intersection with such ranges in [findIntersection()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/randomization.cpp#L246) function.

### Search for random address space

We are ready to search for random address space now.

```
    if (findRandomPhysicalAddress(params, unavailableMemoryAreas, imageSize, physicalAddress) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to find random physical address"));

        return NgosStatus::NOT_FOUND;
    }

#if NGOS_BUILD_RELEASE == OPTION_NO
    *physicalAddress = 0x10000000;
#endif

    EARLY_LVV(("Random physical address: 0x%016lX", *physicalAddress));
```

[findRandomPhysicalAddress()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/randomization.cpp#L461) function trying to search aligned address space for kernel binary image that didn't intersect with any of unavailable memory ranges.

```
    if (findRandomVirtualAddress(params, unavailableMemoryAreas, imageSize, virtualAddress) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to find random virtual address"));

        return NgosStatus::NOT_FOUND;
    }

#if NGOS_BUILD_RELEASE == OPTION_NO
    *virtualAddress = 0xFFFFFFFF80000000;
#endif

    EARLY_LVV(("Random virtual address: 0x%016lX", *virtualAddress));
```

We are also searching for virtual address of kernel image in range 0xFFFFFFFF80000000 - 0xFFFFFFFFC0000000 with [findRandomVirtualAddress()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/randomization.cpp#L540) function.

### Complete with page table initialization

Since we have found valid place for kernel binary image we will do the following:

```
    EARLY_ASSERT_EXECUTION(addIdentityMap(*physicalAddress, *physicalAddress + imageSize), NgosStatus::ASSERTION);



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE
    EARLY_LVV(("Page table:"));

    EARLY_ASSERT_EXECUTION(printPgd((PGD *)pageTable), NgosStatus::ASSERTION);
#endif



    EARLY_ASSERT_EXECUTION(Console::noMorePrint(), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(finalizeIdentityMaps(), NgosStatus::ASSERTION);
```

Here we are providing access for found memory range to let CPU execute NGOS kernel code with [addIdentityMap()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/other/pagetable/pagetable.cpp#L152) function.<br/>
We are also calling [finalizeIdentityMaps()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/other/pagetable/pagetable.cpp#L176) function that apply new page table.
