#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_IOREMAP_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_IOREMAP_H



#include <ngos/status.h>
#include <ngos/types.h>
#include <pagetable/types.h>
#include <src/bits64/other/ioremap/macros.h>



class IORemap
{
public:
    static NgosStatus init(); // TEST: NO
    static NgosStatus addPmdForFixmap(); // TEST: NO
    static NgosStatus addFixedMapping(u64 address, u64 size, void **res); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static u64 sVirtualSlots[FIX_BITMAP_SLOTS];
    static PTE sFixmapPage[PTRS_PER_PMD];
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_IOREMAP_H
