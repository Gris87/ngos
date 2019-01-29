#include "fpu.h"

#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/cpu/cpu.h>
#include <src/bits64/cpu/flags.h>
#include <src/bits64/other/cpu/percpu.h>
#include <asm/instructions.h>



NgosStatus FPU::init()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(initCpu(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus FPU::initCpu()
{
    COMMON_LT((""));



    fninit();



    return NgosStatus::OK;
}
