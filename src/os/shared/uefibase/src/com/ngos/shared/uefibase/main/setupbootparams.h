#ifndef COM_NGOS_SHARED_UEFIBASE_MAIN_SETUPBOOTPARAMS_H
#define COM_NGOS_SHARED_UEFIBASE_MAIN_SETUPBOOTPARAMS_H



#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/ngos/status.h>



NgosStatus setupBootParams(BootParams *params, bad_uint64 kernelLocation); // TEST: NO



#endif // COM_NGOS_SHARED_UEFIBASE_MAIN_SETUPBOOTPARAMS_H
