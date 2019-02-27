#include "randomization.h"

#include <common/src/bits64/random/random.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <pagetable/utils.h>

#include "src/bits64/b_early/early/earlyassert.h"
#include "src/bits64/b_early/early/earlylog.h"
#include "src/bits64/b_early/other/memoryarea.h"
#include "src/bits64/b_early/other/pagetable/pagetable.h"



#define UPPER_MEMORY_LIMIT     (512ULL << 20)
#define PHYSICAL_MAGIC_MASK    0x6C61636973796850 // Physical
#define VIRTUAL_MAGIC_MASK     0x006C617574726956 // Virtual
#define PRIME_NUMBER_1         0x7FFFFFFFFFFFFFE7
#define PRIME_NUMBER_2         0x7FFFFFFFFFFFFF5B
#define PRIME_NUMBER_3         0x7FFFFFFFFFFFFEFD
#define PRIME_NUMBER_4         2017



enum class UnavailableMemoryArea: u8
{
    MEMORY_AREA_ZERO_PAGE,
    MEMORY_AREA_BOOT_PARAMS,
    MEMORY_AREA_RELOCATED_KERNEL,
    MEMORY_AREA_UEFI_MEMORY_MAP,
    MEMORY_AREA_MEMORY_MAP,
    AMOUNT_OF_MEMORY_AREAS
};



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE
NgosStatus printPte(PTE *pte)
{
    EARLY_LT((" | pte = 0x%p", pte));

    EARLY_ASSERT(pte, "pte is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_PTE; ++i)
    {
        if (ptePresent(pte[i]))
        {
            EARLY_LVV(("        pte[%d] = 0x%016lX", i, pteValue(pte[i])));
        }
    }



    return NgosStatus::OK;
}

NgosStatus printPmd(PMD *pmd)
{
    EARLY_LT((" | pmd = 0x%p", pmd));

    EARLY_ASSERT(pmd, "pmd is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_PMD; ++i)
    {
        if (pmdPresent(pmd[i]))
        {
            EARLY_LVV(("      pmd[%d] = 0x%016lX", i, pmdValue(pmd[i])));

            if (!pmdExtended(pmd[i]))
            {
                EARLY_ASSERT_EXECUTION(printPte((PTE *)pmdPageVirtualAddress(pmd[i])), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus printPud(PUD *pud)
{
    EARLY_LT((" | pud = 0x%p", pud));

    EARLY_ASSERT(pud, "pud is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_PUD; ++i)
    {
        if (pudPresent(pud[i]))
        {
            EARLY_LVV(("    pud[%d] = 0x%016lX", i, pudValue(pud[i])));

            if (!pudExtended(pud[i]))
            {
                EARLY_ASSERT_EXECUTION(printPmd((PMD *)pudPageVirtualAddress(pud[i])), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
NgosStatus printP4d(P4D *p4d)
{
    EARLY_LT((" | p4d = 0x%p", p4d));

    EARLY_ASSERT(p4d, "p4d is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_P4D; ++i)
    {
        if (p4dPresent(p4d[i]))
        {
            EARLY_LVV(("  p4d[%d] = 0x%016lX", i, p4dValue(p4d[i])));

            if (!p4dExtended(p4d[i]))
            {
                EARLY_ASSERT_EXECUTION(printPud((PUD *)p4dPageVirtualAddress(p4d[i])), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}
#endif

NgosStatus printPgd(PGD *pgd)
{
    EARLY_LT((" | pgd = 0x%p", pgd));

    EARLY_ASSERT(pgd, "pgd is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_PGD; ++i)
    {
        if (pgdPresent(pgd[i]))
        {
            EARLY_LVV(("pgd[%d] = 0x%016lX", i, pgdValue(pgd[i])));

            if (!pgdExtended(pgd[i]))
            {
#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
                EARLY_ASSERT_EXECUTION(printP4d((P4D *)pgdPageVirtualAddress(pgd[i])), NgosStatus::ASSERTION);
#else
                EARLY_ASSERT_EXECUTION(printPud((PUD *)pgdPageVirtualAddress(pgd[i])), NgosStatus::ASSERTION);
#endif
            }
        }
    }



    return NgosStatus::OK;
}
#endif

inline NgosStatus addUnavailableMemoryArea(MemoryArea *areas, UnavailableMemoryArea areaId, u64 address, u64 size, bool addToIdentityMap)
{
    EARLY_LT((" | areas = 0x%p, areaId = %u, address = 0x%016lx, size = 0x%016lx, addToIdentityMap = %u", areas, areaId, address, size, addToIdentityMap));

    EARLY_ASSERT(areas,                                                            "areas is null",     NgosStatus::ASSERTION);
    EARLY_ASSERT((u64)areaId < (u64)UnavailableMemoryArea::AMOUNT_OF_MEMORY_AREAS, "areaId is invalid", NgosStatus::ASSERTION);
    EARLY_ASSERT(size > 0,                                                         "size is zero",      NgosStatus::ASSERTION);



    areas[(u64)areaId].start = address;
    areas[(u64)areaId].end   = size + areas[(u64)areaId].start;



    if (addToIdentityMap)
    {
        EARLY_ASSERT_EXECUTION(addIdentityMap(areas[(u64)areaId].start, areas[(u64)areaId].end), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus initUnavailableMemoryAreas(BootParams *params, MemoryArea *areas)
{
    EARLY_LT((" | params = 0x%p, areas = 0x%p", params, areas));

    EARLY_ASSERT(params, "params is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(areas,  "areas is null",  NgosStatus::ASSERTION);



    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_ZERO_PAGE,        0,                               PMD_SIZE,                                                          false), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_BOOT_PARAMS,      (u64)params,                     sizeof(*params),                                                   true),  NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_RELOCATED_KERNEL, params->header.kernelLocation,   params->header.allocatedKernelSize,                                true),  NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_UEFI_MEMORY_MAP,  (u64)params->uefi.memoryMap.map, params->uefi.memoryMap.size,                                       false), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(addUnavailableMemoryArea(areas, UnavailableMemoryArea::MEMORY_AREA_MEMORY_MAP,       (u64)params->memoryMapEntries,   params->memoryMapEntriesCount * sizeof(*params->memoryMapEntries), false), NgosStatus::ASSERTION);

    // We don't need to include params->pciRomImages to areas



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        EARLY_LVVV(("Unavailable memory areas:"));
        EARLY_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)UnavailableMemoryArea::AMOUNT_OF_MEMORY_AREAS; ++i)
        {
            EARLY_LVVV(("#%-3d: 0x%p-0x%p", i, areas[i].start, areas[i].end));
        }

        EARLY_LVVV(("params->pciRomImages:"));
        EARLY_LVVV(("---------------------"));

        PciRomImageWithInfo *currentPci = params->pciRomImages;

        while (currentPci)
        {
            i64 areaStart = (u64)currentPci;
            i64 areaStop  = sizeof(*currentPci) + currentPci->romSize + areaStart;

            EARLY_LVVV(("0x%p-0x%p", areaStart, areaStop));

            currentPci = currentPci->next;
        }

        EARLY_LVVV(("-------------------------------------"));
    }
#endif



    return NgosStatus::OK;
}

NgosStatus findIntersection(BootParams *params, MemoryArea *unavailableMemoryAreas, i64 start, i64 end, MemoryArea *intersectedMemoryArea)
{
    EARLY_LT((" | params = 0x%p, unavailableMemoryAreas = 0x%p, start = 0x%p, end = 0x%p, intersectedMemoryArea = 0x%p", params, unavailableMemoryAreas, start, end, intersectedMemoryArea));

    EARLY_ASSERT(params,                 "params is null",                 NgosStatus::ASSERTION);
    EARLY_ASSERT(unavailableMemoryAreas, "unavailableMemoryAreas is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(end,                    "end is null",                    NgosStatus::ASSERTION);
    EARLY_ASSERT(intersectedMemoryArea,  "intersectedMemoryArea is null",  NgosStatus::ASSERTION);



    for (i64 i = 0; i < (i64)UnavailableMemoryArea::AMOUNT_OF_MEMORY_AREAS; ++i)
    {
        if (
            end > (i64)unavailableMemoryAreas[i].start
            &&
            start < (i64)unavailableMemoryAreas[i].end
           )
        {
            intersectedMemoryArea->start = unavailableMemoryAreas[i].start;
            intersectedMemoryArea->end   = unavailableMemoryAreas[i].end;

            return NgosStatus::OK;
        }
    }



    PciRomImageWithInfo *currentPci = params->pciRomImages;

    while (currentPci)
    {
        i64 areaStart = (u64)currentPci;
        i64 areaStop  = sizeof(*currentPci) + currentPci->romSize + areaStart;

        if (
            end > areaStart
            &&
            start < areaStop
           )
        {
            intersectedMemoryArea->start = areaStart;
            intersectedMemoryArea->end   = areaStop;

            return NgosStatus::OK;
        }

        currentPci = currentPci->next;
    }



    intersectedMemoryArea->start = 0;
    intersectedMemoryArea->end   = 0;

    return NgosStatus::OK;
}

NgosStatus findRandomPhysicalAddressInMemoryMapEntry(MemoryMapEntry *memoryMapEntry, BootParams *params, MemoryArea *unavailableMemoryAreas, u64 imageSize, u64 *address)
{
    EARLY_LT((" | memoryMapEntry = 0x%p, params = 0x%p, unavailableMemoryAreas = 0x%p, imageSize = %u, address = 0x%p", memoryMapEntry, params, unavailableMemoryAreas, imageSize, address));

    EARLY_ASSERT(memoryMapEntry,         "memoryMapEntry is null",         NgosStatus::ASSERTION);
    EARLY_ASSERT(params,                 "params is null",                 NgosStatus::ASSERTION);
    EARLY_ASSERT(unavailableMemoryAreas, "unavailableMemoryAreas is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(imageSize > 0,          "imageSize is zero",              NgosStatus::ASSERTION);
    EARLY_ASSERT(address,                "address is null",                NgosStatus::ASSERTION);



    if (memoryMapEntry->type != MemoryMapEntryType::RAM)
    {
        EARLY_LVV(("Skipped memory map entry because it is not RAM entry"));

        return NgosStatus::INVALID_DATA;
    }



    u64 entryAddress = memoryMapEntry->start;
    u64 allowedSize  = memoryMapEntry->size;



    if (entryAddress >= UPPER_MEMORY_LIMIT)
    {
        EARLY_LVV(("Skipped memory map entry because it is above our upper limit"));

        return NgosStatus::INVALID_DATA;
    }



    if (entryAddress + allowedSize > UPPER_MEMORY_LIMIT)
    {
        allowedSize = UPPER_MEMORY_LIMIT - entryAddress;
    }

    EARLY_LVVV(("allowedSize = %u", allowedSize));

    if (allowedSize < imageSize)
    {
        EARLY_LVV(("Skipped memory map entry because it is too small"));

        return NgosStatus::INVALID_DATA;
    }



    u64 randomRange = allowedSize - imageSize;

    u64 randomPosition =
            simpleRandom(
                (
                    (
                        (
                            (u64)params->header.kernelLocation
                            + (u64)params->memoryMapEntries
                            + (u64)unavailableMemoryAreas
                            + (u64)address
                            + (u64)params->pciRomImages
                        ) % PRIME_NUMBER_4
                    )
                    * (u64)params->header.kernelSize
                    * (u64)params->header.allocatedKernelSize
                    * (u64)imageSize
                    * PRIME_NUMBER_2
                ) ^ PHYSICAL_MAGIC_MASK
            ) % randomRange; // Holy crap. Why are doing this? O_o



    u64 randomAddress = entryAddress + randomPosition;

    randomAddress = ROUND_DOWN(randomAddress, NGOS_BUILD_KERNEL_ALIGN);



    EARLY_LVVV(("randomRange    = %u",       randomRange));
    EARLY_LVVV(("randomPosition = %u",       randomPosition));
    EARLY_LVVV(("randomAddress  = 0x%016lX", randomAddress));



    if (randomAddress < entryAddress)
    {
        randomAddress += NGOS_BUILD_KERNEL_ALIGN;
    }

    if (randomAddress + imageSize > entryAddress + allowedSize)
    {
        EARLY_LVV(("Skipped memory map entry because there is no place applicable for the current value of NGOS_BUILD_KERNEL_ALIGN"));

        return NgosStatus::INVALID_DATA;
    }



    MemoryArea intersectedMemoryArea;



    i64 currentAddress = randomAddress;

    while (currentAddress >= (i64)entryAddress && currentAddress > 0)
    {
        EARLY_ASSERT_EXECUTION(findIntersection(params, unavailableMemoryAreas, currentAddress, currentAddress + imageSize, &intersectedMemoryArea), NgosStatus::ASSERTION);

        if (!intersectedMemoryArea.start && !intersectedMemoryArea.end) // intersectedMemoryArea.start == 0 && intersectedMemoryArea.end == 0
        {
            EARLY_LVV(("Valid place found at address 0x%p", currentAddress));

            *address = currentAddress;

            return NgosStatus::OK;
        }
        else
        {
            currentAddress = intersectedMemoryArea.start - imageSize;
            currentAddress = ROUND_DOWN(currentAddress, NGOS_BUILD_KERNEL_ALIGN);

            EARLY_LVV(("Intersection found with unavailable memory area 0x%p-0x%p. Jumping to 0x%p", intersectedMemoryArea.start, intersectedMemoryArea.end, currentAddress));
        }
    }



    while ((i64)(currentAddress + imageSize) <= (i64)(entryAddress + allowedSize) && currentAddress >= 0)
    {
        EARLY_ASSERT_EXECUTION(findIntersection(params, unavailableMemoryAreas, currentAddress, currentAddress + imageSize, &intersectedMemoryArea), NgosStatus::ASSERTION);

        if (!intersectedMemoryArea.start && !intersectedMemoryArea.end) // intersectedMemoryArea.start == 0 && intersectedMemoryArea.end == 0
        {
            EARLY_LVV(("Valid place found at address 0x%p", currentAddress));

            *address = currentAddress;

            return NgosStatus::OK;
        }
        else
        {
            currentAddress = intersectedMemoryArea.end;
            currentAddress = ROUND_UP(currentAddress, NGOS_BUILD_KERNEL_ALIGN);

            EARLY_LVV(("Intersection found with unavailable memory area 0x%p-0x%p. Jumping to 0x%p", intersectedMemoryArea.start, intersectedMemoryArea.end, currentAddress));
        }
    }



    EARLY_LVV(("Valid place not found"));

    return NgosStatus::NOT_FOUND;
}

NgosStatus findRandomPhysicalAddress(BootParams *params, MemoryArea *unavailableMemoryAreas, u64 imageSize, u64 *address)
{
    EARLY_LT((" | params = 0x%p, unavailableMemoryAreas = 0x%p, imageSize = %u, address = 0x%p", params, unavailableMemoryAreas, imageSize, address));

    EARLY_ASSERT(params,                            "params is null",                        NgosStatus::ASSERTION);
    EARLY_ASSERT(unavailableMemoryAreas,            "unavailableMemoryAreas is null",        NgosStatus::ASSERTION);
    EARLY_ASSERT(imageSize > 0,                     "imageSize is zero",                     NgosStatus::ASSERTION);
    EARLY_ASSERT(address,                           "address is null",                       NgosStatus::ASSERTION);
    EARLY_ASSERT(params->memoryMapEntriesCount > 0, "params->memoryMapEntriesCount is zero", NgosStatus::ASSERTION);
    EARLY_ASSERT(params->memoryMapEntries,          "params->memoryMapEntries is null",      NgosStatus::ASSERTION);



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        EARLY_LVVV(("Memory Map entries:"));
        EARLY_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)params->memoryMapEntriesCount; ++i)
        {
            EARLY_LVVV(("#%-3d: type = %-2u | 0x%p-0x%p", i, params->memoryMapEntries[i].type, params->memoryMapEntries[i].start, params->memoryMapEntries[i].end()));
        }

        EARLY_LVVV(("-------------------------------------"));
    }
#endif



    u64 randomId =
            simpleRandom(
                (
                    (
                        (
                            (u64)params->header.kernelLocation
                            + (u64)params->memoryMapEntries
                            + (u64)unavailableMemoryAreas
                            + (u64)address
                            + (u64)params->pciRomImages
                        ) % PRIME_NUMBER_4
                    )
                    * (u64)params->header.kernelSize
                    * (u64)params->header.allocatedKernelSize
                    * (u64)imageSize
                    * PRIME_NUMBER_1
                ) ^ PHYSICAL_MAGIC_MASK
            ) % params->memoryMapEntriesCount; // Deal with it \(J_J)/

    EARLY_LVVV(("randomId = %u", randomId));



    for (i64 i = randomId; i >= 0; --i)
    {
        EARLY_LVV(("Processing memory map entry #%d: type = %u | 0x%p-0x%p", i, params->memoryMapEntries[i].type, params->memoryMapEntries[i].start, params->memoryMapEntries[i].end()));

        if (findRandomPhysicalAddressInMemoryMapEntry(&params->memoryMapEntries[i], params, unavailableMemoryAreas, imageSize, address) == NgosStatus::OK)
        {
            return NgosStatus::OK;
        }
    }



    for (i64 i = randomId + 1; i < (i64)params->memoryMapEntriesCount; ++i)
    {
        EARLY_LVV(("Processing memory map entry #%d: type = %u | 0x%p-0x%p", i, params->memoryMapEntries[i].type, params->memoryMapEntries[i].start, params->memoryMapEntries[i].end()));

        if (findRandomPhysicalAddressInMemoryMapEntry(&params->memoryMapEntries[i], params, unavailableMemoryAreas, imageSize, address) == NgosStatus::OK)
        {
            return NgosStatus::OK;
        }
    }



    return NgosStatus::NOT_FOUND;
}

NgosStatus findRandomVirtualAddress(BootParams *params, MemoryArea *unavailableMemoryAreas, u64 imageSize, u64 *address)
{
    EARLY_LT((" | params = 0x%p, unavailableMemoryAreas = 0x%p, imageSize = %u, address = 0x%p", params, unavailableMemoryAreas, imageSize, address));

    EARLY_ASSERT(params,                            "params is null",                        NgosStatus::ASSERTION);
    EARLY_ASSERT(unavailableMemoryAreas,            "unavailableMemoryAreas is null",        NgosStatus::ASSERTION);
    EARLY_ASSERT(imageSize > 0,                     "imageSize is zero",                     NgosStatus::ASSERTION);
    EARLY_ASSERT(address,                           "address is null",                       NgosStatus::ASSERTION);
    EARLY_ASSERT(params->memoryMapEntriesCount > 0, "params->memoryMapEntriesCount is zero", NgosStatus::ASSERTION);
    EARLY_ASSERT(params->memoryMapEntries,          "params->memoryMapEntries is null",      NgosStatus::ASSERTION);



    u64 randomRange = PUD_SIZE - imageSize;

    u64 randomPosition =
            simpleRandom(
                (
                    (
                        (
                            (u64)params->header.kernelLocation
                            + (u64)params->memoryMapEntries
                            + (u64)unavailableMemoryAreas
                            + (u64)address
                            + (u64)params->pciRomImages
                        ) % PRIME_NUMBER_4
                    )
                    * (u64)params->header.kernelSize
                    * (u64)params->header.allocatedKernelSize
                    * (u64)imageSize
                    * PRIME_NUMBER_3
                ) ^ VIRTUAL_MAGIC_MASK
            ) % randomRange; // Best random ever \o/_\o/



    u64 randomAddress = 0xFFFFFFFF80000000 + randomPosition;

    randomAddress = ROUND_DOWN(randomAddress, NGOS_BUILD_KERNEL_ALIGN);



    EARLY_LVVV(("randomRange    = %u",       randomRange));
    EARLY_LVVV(("randomPosition = %u",       randomPosition));
    EARLY_LVVV(("randomAddress  = 0x%016lX", randomAddress));



    *address = randomAddress;

    return NgosStatus::OK;
}

NgosStatus getRandomLocation(BootParams *params, u8 *pageTable, u64 imageSize, u64 *physicalAddress, u64 *virtualAddress)
{
    EARLY_LT((" | params = 0x%p, pageTable = 0x%p, imageSize = %u, physicalAddress = 0x%p, virtualAddress = 0x%p", params, pageTable, imageSize, physicalAddress, virtualAddress));

    EARLY_ASSERT(params,          "params is null",          NgosStatus::ASSERTION);
    EARLY_ASSERT(pageTable,       "pageTable is null",       NgosStatus::ASSERTION);
    EARLY_ASSERT(imageSize > 0,   "imageSize is zero",       NgosStatus::ASSERTION);
    EARLY_ASSERT(physicalAddress, "physicalAddress is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(virtualAddress,  "virtualAddress is null",  NgosStatus::ASSERTION);



    EARLY_ASSERT_EXECUTION(initializeIdentityMaps(pageTable), NgosStatus::ASSERTION);



    MemoryArea unavailableMemoryAreas[(u64)UnavailableMemoryArea::AMOUNT_OF_MEMORY_AREAS];

    EARLY_ASSERT_EXECUTION(initUnavailableMemoryAreas(params, unavailableMemoryAreas), NgosStatus::ASSERTION);



    if (findRandomPhysicalAddress(params, unavailableMemoryAreas, imageSize, physicalAddress) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to find random physical address"));

        return NgosStatus::NOT_FOUND;
    }

#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
    *physicalAddress = 0x10000000;
#endif

    EARLY_LVV(("Random physical address: 0x%016lX", *physicalAddress));



    if (findRandomVirtualAddress(params, unavailableMemoryAreas, imageSize, virtualAddress) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to find random virtual address"));

        return NgosStatus::NOT_FOUND;
    }

#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
    *virtualAddress = 0xFFFFFFFF80000000;
#endif

    EARLY_LVV(("Random virtual address: 0x%016lX", *virtualAddress));



    EARLY_ASSERT_EXECUTION(addIdentityMap(*physicalAddress, *physicalAddress + imageSize), NgosStatus::ASSERTION);



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE
    EARLY_LVV(("Page table:"));

    EARLY_ASSERT_EXECUTION(printPgd((PGD *)pageTable), NgosStatus::ASSERTION);
#endif



    EARLY_ASSERT_EXECUTION(Console::noMorePrint(), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(finalizeIdentityMaps(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
