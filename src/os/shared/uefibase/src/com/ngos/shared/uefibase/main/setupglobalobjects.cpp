#include "setupglobalobjects.h"

#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



typedef void (*constuctor_function) ();



extern constuctor_function _ctors_begin; // _ctors_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern constuctor_function _ctors_end;   // _ctors_end declared in linker.ld file   // Ignore CppEqualAlignmentVerifier



NgosStatus setupGlobalObjects()
{
    UEFI_LT((""));



    constuctor_function *cur = &_ctors_begin;
    constuctor_function *end = &_ctors_end;

    while (cur < end)
    {
        // UEFI_LVVV(("cur  = 0x%p", cur));  // Commented to avoid too frequent logs
        // UEFI_LVVV(("*cur = 0x%p", *cur)); // Commented to avoid too frequent logs

        constuctor_function func = *cur;
        func();

        ++cur;
    }



    return NgosStatus::OK;
}
