#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/linkage.h>



void *__dso_handle = nullptr; // Ignore CppEqualAlignmentVerifier



CPP_EXTERN_C
void __cxa_atexit()
{
    COMMON_LT((""));
}
