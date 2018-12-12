#include "setupmemorymanager.h"

#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/other/memorymanager/memorymanager.h>
#include <src/bits64/other/pagetable/addressconversion.h>



extern void *_start; // _start is declared in main.S file // Ignore CppEqualAlignmentVerifier
extern void *_end;   // _end is declared in linker.ld file // Ignore CppEqualAlignmentVerifier



NgosStatus setupMemoryManager()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(MemoryManager::init(),                                                                               NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(MemoryManager::reserve(AddressConversion::physicalAddress((u64)&_start), (u64)&_end - (u64)&_start), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
