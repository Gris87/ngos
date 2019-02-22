#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIFUNCTORS_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIFUNCTORS_H



#include "src/bits64/a_uefi/uefi/lib/efidefines.h"
#include "src/bits64/a_uefi/uefi/lib/efievent.h"



typedef void (EFIAPI *efi_event_notify) (EfiEvent event, void *context);



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIFUNCTORS_H
