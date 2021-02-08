#ifndef COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H
#define COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H



#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/ngos/status.h>



NgosStatus setupBootParams(BootParams **params, u64 kernelLocation); // TEST: NO



#endif // COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H
