#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_IOREMAP_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_IOREMAP_H



#include <kernelbase/src/bits64/other/ioremap/macros.h>
#include <ngos/status.h>
#include <ngos/types.h>
#include <pagetable/types.h>



class IORemap
{
public:
    static NgosStatus init(); // TEST: NO
    static NgosStatus addPmdForFixmap(); // TEST: NO
    static NgosStatus addFixedMapping(u64 address, u64 size, void **res); // TEST: NO
    static NgosStatus removeFixedMapping(u64 address, u64 size); // TEST: NO

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



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_IOREMAP_H
