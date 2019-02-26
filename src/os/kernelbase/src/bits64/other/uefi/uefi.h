#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H



#include <buildconfig.h>
#include <ngos/status.h>
#include <bootparams/uefimemorymapinfo.h>



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



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_UEFI_UEFI_H
