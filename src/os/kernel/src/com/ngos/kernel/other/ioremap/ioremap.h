#ifndef COM_NGOS_KERNEL_OTHER_IOREMAP_IOREMAP_H
#define COM_NGOS_KERNEL_OTHER_IOREMAP_IOREMAP_H



#include <com/ngos/kernel/other/ioremap/macros.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pagetable/types.h>



class IORemap
{
public:
    static NgosStatus init();
    static NgosStatus addPmdForFixmap(); // TEST: NO
    static NgosStatus addFixedMapping(address_t address, u64 size, void **res);
    static NgosStatus removeFixedMapping(address_t address, u64 size);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static u64 sSlotsAddresses[FIX_BITMAP_SLOTS];
    static u64 sSlotsSizes[FIX_BITMAP_SLOTS];
    static u8  sPoolOfSlots[FIX_BITMAP_SLOTS];
    static u8  sLastUsedSlot;
    static u8  sLastReleasedSlot;
    static u8  sSlotsAvailable;
    static PTE sFixmapPage[PTRS_PER_PTE];
};



#endif // COM_NGOS_KERNEL_OTHER_IOREMAP_IOREMAP_H
