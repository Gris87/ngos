#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H



#include <ngos/status.h>
#include <src/bits64/other/fpu/fpustate.h>



class FPU
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initState(); // TEST: NO
    static NgosStatus initXState(); // TEST: NO
    static NgosStatus initFXState(); // TEST: NO
    static NgosStatus initMxcsrMask(); // TEST: NO

    static FpuState sState;
    static u32      sMxcsrMask;
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H
