#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H



#include <bootparams/bootparams.h>
#include <ngos/status.h>



NgosStatus setupBootParams(BootParams **params, u64 kernelLocation); // TEST: NO



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPBOOTPARAMS_H
