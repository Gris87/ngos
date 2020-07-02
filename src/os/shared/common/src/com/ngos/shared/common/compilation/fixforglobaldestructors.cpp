#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>



void *__dso_handle = 0; // Ignore CppEqualAlignmentVerifier



CPP_EXTERN_C
void __cxa_atexit()
{
    COMMON_LT((""));
}
