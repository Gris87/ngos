#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_PAGETABLE_ADDRESSCONVERSION_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_PAGETABLE_ADDRESSCONVERSION_H



#include <ngos/status.h>
#include <ngos/types.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>



extern void *_start; // _start declared in main.S file // Ignore CppEqualAlignmentVerifier



class AddressConversion
{
public:
    static inline u64 physicalAddress(u64 address) // TEST: NO
    {
        EARLY_LT((" | address = 0x%p", address));



        return address + sPhysicalDelta;
    }

    static inline NgosStatus setPhysicalDeltaBaseOnLocation(u64 location) // TEST: NO
    {
        EARLY_LT((" | location = 0x%016lX", location));

        EARLY_ASSERT(location, "location is null", NgosStatus::ASSERTION);



        u64 *physicalDeltaAddress = (u64 *)(location + (u64)&sPhysicalDelta - (u64)&_start);
        *physicalDeltaAddress     = location - (u64)&_start;



        return NgosStatus::OK;
    }

private:
    static u64 sPhysicalDelta; // Special delta value that let you convert virtual address to physical address
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_PAGETABLE_ADDRESSCONVERSION_H
