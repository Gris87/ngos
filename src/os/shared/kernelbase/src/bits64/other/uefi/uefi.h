#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H



#include <bootparams/uefimemorymapinfo.h>
#include <buildconfig.h>
#include <ngos/status.h>



class UEFI
{
public:
    static NgosStatus initMemoryMap(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static UefiMemoryMapInfo sMemoryMap;
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H