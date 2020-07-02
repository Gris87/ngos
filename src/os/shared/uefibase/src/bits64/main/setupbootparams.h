#ifndef OS_SHARED_UEFIBASE_SRC_BITS64_MAIN_SETUPBOOTPARAMS_H
#define OS_SHARED_UEFIBASE_SRC_BITS64_MAIN_SETUPBOOTPARAMS_H



#include <common/src/com/ngos/shared/common/bootparams/bootparams.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>



NgosStatus setupBootParams(BootParams *params, u64 kernelLocation); // TEST: NO



#endif // OS_SHARED_UEFIBASE_SRC_BITS64_MAIN_SETUPBOOTPARAMS_H
