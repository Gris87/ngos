#include "setupglobalobjects.h"

#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



extern void *_ctors_begin; // _ctors_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_ctors_end;   // _ctors_end declared in linker.ld file   // Ignore CppEqualAlignmentVerifier



typedef void (*constuctor_function) ();



NgosStatus setupGlobalObjects()
{
    UEFI_LT((""));



    address_t cur = (address_t)&_ctors_begin;
    address_t end = (address_t)&_ctors_end;

    while (cur < end)
    {
        // UEFI_LVVV(("cur  = 0x%016llX", cur));               // Commented to avoid too frequent logs
        // UEFI_LVVV(("*cur = 0x%016llX", *(address_t *)cur)); // Commented to avoid too frequent logs

        constuctor_function func = (constuctor_function)(*(address_t *)cur);
        func();

        cur += sizeof(constuctor_function);
    }



    return NgosStatus::OK;
}
