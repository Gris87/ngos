#include "ioremap.h"

#include <com/ngos/kernel/other/ioremap/utils.h>
#include <com/ngos/kernel/other/pagetable/addressconversion.h>
#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/pagetable/utils.h>



extern PMD fixmap_pagetable_level2[PTRS_PER_PMD]; // fixmap_pagetable_level2 declared in main.S file



u64 IORemap::sSlotsAddresses[FIX_BITMAP_SLOTS];
u64 IORemap::sSlotsSizes[FIX_BITMAP_SLOTS];
u8  IORemap::sPoolOfSlots[FIX_BITMAP_SLOTS];
u8  IORemap::sLastUsedSlot;
u8  IORemap::sLastReleasedSlot;
u8  IORemap::sSlotsAvailable;
PTE IORemap::sFixmapPage[PTRS_PER_PTE] __attribute__((aligned(PAGE_SIZE)));



NgosStatus IORemap::init()
{
    COMMON_LT((""));



    for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
    {
        sPoolOfSlots[i] = i;

        COMMON_LVVV(("sPoolOfSlots[%d] = %u", i, sPoolOfSlots[i]));
    }

    sLastUsedSlot     = FIX_BITMAP_SLOTS - 1;
    sLastReleasedSlot = FIX_BITMAP_SLOTS - 1;
    sSlotsAvailable   = FIX_BITMAP_SLOTS;



    // Validation
    {
        COMMON_LVVV(("sLastUsedSlot     = %u", sLastUsedSlot));
        COMMON_LVVV(("sLastReleasedSlot = %u", sLastReleasedSlot));
        COMMON_LVVV(("sSlotsAvailable   = %u", sSlotsAvailable));



        COMMON_TEST_ASSERT(FIX_BITMAP_SLOTS  == 8, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPoolOfSlots[0]   == 0, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPoolOfSlots[1]   == 1, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPoolOfSlots[2]   == 2, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPoolOfSlots[3]   == 3, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPoolOfSlots[4]   == 4, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPoolOfSlots[5]   == 5, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPoolOfSlots[6]   == 6, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPoolOfSlots[7]   == 7, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sLastUsedSlot     == 7, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sLastReleasedSlot == 7, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSlotsAvailable   == 8, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus IORemap::addPmdForFixmap()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN)           == 0xFFFFFFFFFF200000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(pmdIndex(FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN)) == 505,                NgosStatus::ASSERTION);



    PMD *pmd = &fixmap_pagetable_level2[pmdIndex(FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN))];

    setPmd(pmd, AddressConversion::physicalAddress((pmd_value)&sFixmapPage) | USER_PAGE_TABLE_FLAGS);



    // Validation
    {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        for (i64 i = 0; i < PTRS_PER_PMD; ++i)
        {
            if (pmdValue(fixmap_pagetable_level2[i]))
            {
                COMMON_LVVV(("pmdValue(fixmap_pagetable_level2[%d]) = 0x%016llX", i, pmdValue(fixmap_pagetable_level2[i])));
            }
        }
#endif



        COMMON_TEST_ASSERT(memempty(&fixmap_pagetable_level2[0], 504 * 8) == true, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(pmdValue(fixmap_pagetable_level2[505])         != 0,    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(pmdValue(fixmap_pagetable_level2[506])         != 0,    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(memempty(&fixmap_pagetable_level2[507], 5 * 8) == true, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus IORemap::addFixedMapping(address_t address, u64 size, void **res)
{
    COMMON_LT((" | address = 0x%016llX, size = %u, res = 0x%p", address, size, res));

    COMMON_ASSERT(address,                                   "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,                                  "size is zero",    NgosStatus::ASSERTION);
    COMMON_ASSERT(size <= NUMBER_OF_FIX_BITMAPS * PAGE_SIZE, "size is too big", NgosStatus::ASSERTION);
    COMMON_ASSERT(res,                                       "res is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(address + size > address,                  "size is invalid", NgosStatus::ASSERTION);



    if (sSlotsAvailable == 0)
    {
        COMMON_LF(("There is no free slot for fixed mapping"));

        *res = nullptr;

        return NgosStatus::FAILED;
    }



    --sSlotsAvailable;
    sLastUsedSlot = (sLastUsedSlot + 1) % FIX_BITMAP_SLOTS;

    u8 slot = sPoolOfSlots[sLastUsedSlot];



    u64 start         = ROUND_DOWN(address, PAGE_SIZE);
    u64 end           = ROUND_UP(address + size, PAGE_SIZE);
    u8  numberOfPages = (end - start) / PAGE_SIZE;

    COMMON_LVVV(("sLastUsedSlot   = %u",        sLastUsedSlot));
    COMMON_LVVV(("sSlotsAvailable = %u",        sSlotsAvailable));
    COMMON_LVVV(("slot            = %u",        slot));
    COMMON_LVVV(("start           = 0x%016llX", start));
    COMMON_LVVV(("end             = 0x%016llX", end));
    COMMON_LVVV(("numberOfPages   = %u",        numberOfPages));

    COMMON_TEST_ASSERT(sLastUsedSlot < FIX_BITMAP_SLOTS,                            NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sSlotsAvailable < FIX_BITMAP_SLOTS,                          NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(slot < FIX_BITMAP_SLOTS,                                     NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(start < end,                                                 NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(numberOfPages > 0 && numberOfPages <= NUMBER_OF_FIX_BITMAPS, NgosStatus::ASSERTION);



    u16 startPteForSlot = slot * NUMBER_OF_FIX_BITMAPS;

    for (i64 i = 0; i < numberOfPages; ++i)
    {
        COMMON_TEST_ASSERT(pteValue(sFixmapPage[startPteForSlot + i]) == 0, NgosStatus::ASSERTION);

        setPte(&sFixmapPage[startPteForSlot + i], (start + i * PAGE_SIZE) | KERNEL_PAGE_FLAGS);
    }



    u64 fixedAddress = FIX_ADDRESS_BOTTOM + startPteForSlot * PAGE_SIZE + (address & ~PAGE_MASK);

    *(u64 *)res = fixedAddress;

    COMMON_LVV(("Physical address (0x%p, %u) fixed to virtual address 0x%p", address, size, fixedAddress));



    COMMON_TEST_ASSERT(sSlotsAddresses[slot] == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sSlotsSizes[slot]     == 0, NgosStatus::ASSERTION);

    sSlotsAddresses[slot] = fixedAddress;
    sSlotsSizes[slot]     = size;



    return NgosStatus::OK;
}

NgosStatus IORemap::removeFixedMapping(address_t address, u64 size)
{
    COMMON_LT((" | address = 0x%016llX, size = %u", address, size));

    COMMON_ASSERT(address,                                                                "address is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(address >= FIX_ADDRESS_BOTTOM && address < FIX_ADDRESS_TOP + PAGE_SIZE, "address is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,                                                               "size is zero",       NgosStatus::ASSERTION);
    COMMON_ASSERT(address + size > address,                                               "size is invalid",    NgosStatus::ASSERTION);



    if (sSlotsAvailable >= NUMBER_OF_FIX_BITMAPS)
    {
        COMMON_LE(("There is nothing to remove"));

        return NgosStatus::NOT_FOUND;
    }



    u8 slot = (address - FIX_ADDRESS_BOTTOM) / (NUMBER_OF_FIX_BITMAPS * PAGE_SIZE);

    if (sSlotsAddresses[slot] != address || sSlotsSizes[slot] != size)
    {
        COMMON_LE(("Fixed mapping for address (0x%p, %u) not found", address, size));

        return NgosStatus::NOT_FOUND;
    }



    ++sSlotsAvailable;
    sLastReleasedSlot = (sLastReleasedSlot + 1) % FIX_BITMAP_SLOTS;

    sSlotsAddresses[slot]           = 0;
    sSlotsSizes[slot]               = 0;
    sPoolOfSlots[sLastReleasedSlot] = slot;



    u64 start         = ROUND_DOWN(address, PAGE_SIZE);
    u64 end           = ROUND_UP(address + size, PAGE_SIZE);
    u8  numberOfPages = (end - start) / PAGE_SIZE;

    COMMON_LVVV(("sLastReleasedSlot = %u",        sLastReleasedSlot));
    COMMON_LVVV(("sSlotsAvailable   = %u",        sSlotsAvailable));
    COMMON_LVVV(("slot              = %u",        slot));
    COMMON_LVVV(("start             = 0x%016llX", start));
    COMMON_LVVV(("end               = 0x%016llX", end));
    COMMON_LVVV(("numberOfPages     = %u",        numberOfPages));

    COMMON_TEST_ASSERT(sLastReleasedSlot < FIX_BITMAP_SLOTS,                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sSlotsAvailable > 0 && sSlotsAvailable <= FIX_BITMAP_SLOTS,  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(slot < FIX_BITMAP_SLOTS,                                     NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(start < end,                                                 NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(numberOfPages > 0 && numberOfPages <= NUMBER_OF_FIX_BITMAPS, NgosStatus::ASSERTION);



    u16 startPteForSlot = slot * NUMBER_OF_FIX_BITMAPS;

    for (i64 i = 0; i < numberOfPages; ++i)
    {
        COMMON_TEST_ASSERT(pteValue(sFixmapPage[startPteForSlot + i]) != 0, NgosStatus::ASSERTION);

        setPte(&sFixmapPage[startPteForSlot + i], 0);

        COMMON_ASSERT_EXECUTION(AsmUtils::invlpg((u8 *)(start + i * PAGE_SIZE)), NgosStatus::ASSERTION);
    }



    COMMON_LVV(("Removed fixed mapping for address (0x%p, %u)", address, size));



    return NgosStatus::OK;
}
