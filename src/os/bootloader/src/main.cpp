#include <ngos/linkage.h>
#include <uefi/uefisystemtable.h>



// DO NOT DELETE IT!!!
// We are putting this variable to .noinit section in order to convert .noinit section type from NOBITS to PROGBITS
u8 __reserved_for_bss __attribute__ ((section (".noinit")));



CPP_EXTERN_C
i64 uefiMain(uefi_handle /*imageHandle*/, UefiSystemTable * /*systemTable*/, u64 /*kernelLocation*/)
{
    return 0;
}
