#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0_TESTCASE_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0_TESTCASE_H



#include <buildconfig.h>

#include "test/bits64/a_uefi/sections/section0/__common/bits64/cpu/cpu.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/cpu/cpufeatures.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/memory/memory.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/printf/printf.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/random/random.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/string/string.h"
#include "test/bits64/a_uefi/sections/section0/__include/elf/rela.h"
#include "test/bits64/a_uefi/sections/section0/__include/elf/symbol.h"
#include "test/bits64/a_uefi/sections/section0/__include/ngos/types.h"
#include "test/bits64/a_uefi/sections/section0/__include/ngos/utils.h"
#include "test/bits64/a_uefi/sections/section0/__include/pagetable/utils.h"
#include "test/bits64/a_uefi/sections/section0/bits64/a_uefi/uefi/uefi.h"
#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection0()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section0, __common_bits64_cpu_cpu);
    CALL_TEST_CASES(section0, __common_bits64_cpu_cpufeatures);
    CALL_TEST_CASES(section0, __common_bits64_memory_memory);
    CALL_TEST_CASES(section0, __common_bits64_printf_printf);
    CALL_TEST_CASES(section0, __common_bits64_random_random);
    CALL_TEST_CASES(section0, __common_bits64_string_string);
    CALL_TEST_CASES(section0, __include_elf_rela);
    CALL_TEST_CASES(section0, __include_elf_symbol);
    CALL_TEST_CASES(section0, __include_ngos_types);
    CALL_TEST_CASES(section0, __include_ngos_utils);
    CALL_TEST_CASES(section0, __include_pagetable_utils);
    CALL_TEST_CASES(section0, bits64_a_uefi_uefi_uefi);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0_TESTCASE_H
