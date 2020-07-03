#include "setupglobalobjects.h"

#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>



extern void *_ctors_begin; // _ctors_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_ctors_end;   // _ctors_end declared in linker.ld file   // Ignore CppEqualAlignmentVerifier



typedef void (*constuctor_function) ();



NgosStatus setupGlobalObjects()
{
    UEFI_LT((""));



    u64 cur = (u64)&_ctors_begin;
    u64 end = (u64)&_ctors_end;

    while (cur < end)
    {
        // UEFI_LVVV(("cur  = 0x%016lX", cur));         // Commented to avoid too frequent logs
        // UEFI_LVVV(("*cur = 0x%016lX", *(u64 *)cur)); // Commented to avoid too frequent logs

        constuctor_function func = (constuctor_function)(*(u64 *)cur);
        func();

        cur += sizeof(constuctor_function);
    }



    return NgosStatus::OK;
}
