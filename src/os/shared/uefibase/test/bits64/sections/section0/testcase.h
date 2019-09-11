#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0_TESTCASE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0_TESTCASE_H



#include <buildconfig.h>
#include <uefibase/test/bits64/sections/section0/__include/asm/bitutils.h>
#include <uefibase/test/bits64/sections/section0/__include/asm/instructions.h>
#include <uefibase/test/bits64/sections/section0/__include/bootparams/memorymapentry.h>
#include <uefibase/test/bits64/sections/section0/__include/guid/utils.h>
#include <uefibase/test/bits64/sections/section0/__include/macro/utils.h>
#include <uefibase/test/bits64/sections/section0/__include/ngos/linkage.h>
#include <uefibase/test/bits64/sections/section0/__include/ngos/types.h>
#include <uefibase/test/bits64/sections/section0/__include/ngos/utils.h>
#include <uefibase/test/bits64/sections/section0/__include/pagetable/utils.h>
#include <uefibase/test/bits64/sections/section0/__include/types.h>
#include <uefibase/test/bits64/sections/section0/__include/uuid/utils.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/checksum/adler.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/checksum/crc.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/containers/lib/listelement.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/containers/list.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/cpu/cpu.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx/avx.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx2/avx2.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx512bw/avx512bw.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx512cd/avx512cd.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx512dq/avx512dq.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx512f/avx512f.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx512vl/avx512vl.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/fma3/fma3.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/fpu.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/sse/sse.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/sse2/sse2.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/sse3/sse3.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/sse41/sse41.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/sse42/sse42.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/graphics/image.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/graphics/ninepatch.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/graphics/png/png.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/graphics/stretchrange.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/gui/widgets/widget.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/memory/memory.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/printf/printf.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/random/random.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/string/string.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/types.h>
#include <uefibase/test/bits64/sections/section0/__shared/uefibase/bits64/other/uefibootmemorymap.h>
#include <uefibase/test/bits64/sections/section0/__shared/uefibase/bits64/types.h>
#include <uefibase/test/bits64/sections/section0/__shared/uefibase/bits64/uefi/uefi.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection0()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section0, __include_asm_bitutils);
    CALL_TEST_CASES(section0, __include_asm_instructions);
    CALL_TEST_CASES(section0, __include_bootparams_memorymapentry);
    CALL_TEST_CASES(section0, __include_guid_utils);
    CALL_TEST_CASES(section0, __include_macro_utils);
    CALL_TEST_CASES(section0, __include_ngos_linkage);
    CALL_TEST_CASES(section0, __include_ngos_types);
    CALL_TEST_CASES(section0, __include_ngos_utils);
    CALL_TEST_CASES(section0, __include_pagetable_utils);
    CALL_TEST_CASES(section0, __include_types);
    CALL_TEST_CASES(section0, __include_uuid_utils);
    CALL_TEST_CASES(section0, __shared_common_bits64_checksum_adler);
    CALL_TEST_CASES(section0, __shared_common_bits64_checksum_crc);
    CALL_TEST_CASES(section0, __shared_common_bits64_containers_lib_listelement);
    CALL_TEST_CASES(section0, __shared_common_bits64_containers_list);
    CALL_TEST_CASES(section0, __shared_common_bits64_cpu_cpu);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_avx2_avx2);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_avx512bw_avx512bw);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_avx512cd_avx512cd);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_avx512dq_avx512dq);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_avx512f_avx512f);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_avx512vl_avx512vl);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_avx_avx);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_fma3_fma3);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_fpu);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_sse2_sse2);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_sse3_sse3);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_sse41_sse41);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_sse42_sse42);
    CALL_TEST_CASES(section0, __shared_common_bits64_fpu_sse_sse);
    CALL_TEST_CASES(section0, __shared_common_bits64_graphics_image);
    CALL_TEST_CASES(section0, __shared_common_bits64_graphics_ninepatch);
    CALL_TEST_CASES(section0, __shared_common_bits64_graphics_png_png);
    CALL_TEST_CASES(section0, __shared_common_bits64_graphics_stretchrange);
    CALL_TEST_CASES(section0, __shared_common_bits64_gui_widgets_widget);
    CALL_TEST_CASES(section0, __shared_common_bits64_memory_memory);
    CALL_TEST_CASES(section0, __shared_common_bits64_printf_printf);
    CALL_TEST_CASES(section0, __shared_common_bits64_random_random);
    CALL_TEST_CASES(section0, __shared_common_bits64_string_string);
    CALL_TEST_CASES(section0, __shared_common_bits64_types);
    CALL_TEST_CASES(section0, __shared_uefibase_bits64_other_uefibootmemorymap);
    CALL_TEST_CASES(section0, __shared_uefibase_bits64_types);
    CALL_TEST_CASES(section0, __shared_uefibase_bits64_uefi_uefi);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0_TESTCASE_H
