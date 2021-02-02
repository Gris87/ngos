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
    static NgosStatus addFixedMapping(bad_uint64 address, bad_uint64 size, void **res);
    static NgosStatus removeFixedMapping(bad_uint64 address, bad_uint64 size);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static bad_uint64 sSlotsAddresses[FIX_BITMAP_SLOTS];
    static bad_uint64 sSlotsSizes[FIX_BITMAP_SLOTS];
    static bad_uint8  sPoolOfSlots[FIX_BITMAP_SLOTS];
    static bad_uint8  sLastUsedSlot;
    static bad_uint8  sLastReleasedSlot;
    static bad_uint8  sSlotsAvailable;
    static PTE sFixmapPage[PTRS_PER_PTE];
};



#endif // COM_NGOS_KERNEL_OTHER_IOREMAP_IOREMAP_H
