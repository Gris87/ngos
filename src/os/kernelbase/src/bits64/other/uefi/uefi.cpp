#include "uefi.h"

#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>



UefiMemoryDescriptor *UEFI::sMemoryMap;



NgosStatus UEFI::initMemoryMap()
{
    COMMON_LT((""));



    return NgosStatus::OK;
}
