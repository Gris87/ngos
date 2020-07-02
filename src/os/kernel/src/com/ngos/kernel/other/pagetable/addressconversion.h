#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_PAGETABLE_ADDRESSCONVERSION_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_PAGETABLE_ADDRESSCONVERSION_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/status.h>
#include <ngos/types.h>



extern void *_start; // _start declared in main.S file // Ignore CppEqualAlignmentVerifier



class AddressConversion
{
public:
    static inline u64 physicalAddress(u64 address)
    {
        COMMON_LT((" | address = 0x%p", address));



        return address + sPhysicalDelta;
    }

    static inline u64 virtualAddress(u64 address)
    {
        COMMON_LT((" | address = 0x%p", address));



        return address - sPhysicalDelta;
    }

    static inline NgosStatus setPhysicalDeltaBaseOnLocation(u64 location)
    {
        COMMON_LT((" | location = 0x%016lX", location));

        COMMON_ASSERT(location, "location is null", NgosStatus::ASSERTION);



        sPhysicalDelta = location - (u64)&_start;



        return NgosStatus::OK;
    }

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static u64 sPhysicalDelta; // Special delta value that let you convert virtual address to physical address
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_PAGETABLE_ADDRESSCONVERSION_H
