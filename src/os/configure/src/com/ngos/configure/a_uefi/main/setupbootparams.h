#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H



#include <common/src/com/ngos/shared/common/bootparams/bootparams.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>



NgosStatus setupBootParams(BootParams **params, u64 kernelLocation); // TEST: NO



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H
