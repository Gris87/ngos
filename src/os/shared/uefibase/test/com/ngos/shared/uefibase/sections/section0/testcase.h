#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_TESTCASE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_TESTCASE_H



#include <buildconfig.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/asm/bitutils.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/bootparams/memorymapentry.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/checksum/adler.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/checksum/crc.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/checksum/lib/md5hash.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/checksum/md5.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/containers/lib/listelement.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/containers/lib/mapelement.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/containers/list.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/containers/map.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/cryptography/aes.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/dmi.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/dmichassisentry.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmibiosextendedromsize.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmibiosromsize.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmicacheconfiguration.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmicachesize.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmicachesize2.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmimemoryarraymappedaddressrange.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceextendedsize.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicemappedaddressrange.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicesize.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarraymaximumcapacity.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/dmi/entry/lib/dmiportablebatterymanufacturedate.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx/avx.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx2/avx2.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512bw/avx512bw.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512cd/avx512cd.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512dq/avx512dq.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/avx512f.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/avx512vl.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/fma3/fma3.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/sse.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse2/sse2.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse3/sse3.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/sse41.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse42/sse42.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/graphics/ninepatch.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/graphics/png/png.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/graphics/stretchrange.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/gui/widgets/widget.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/guid/utils.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/hex/hex.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/macro/utils.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pagetable/utils.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pciexpressaccesscontrolservicesacscapability.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pciexpressmulticastcapabilityregister.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pciexpressmulticastcontrolregister.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pciexpressresizablebaseaddresscontrol.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkaddresslinkconfigurationspace.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pciexpressvirtualchannelvirtualchannelresourcecapability.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pciextendeddevicecommand.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pciextendeddevicestatus.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsextendedmessagecontrol.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessagecontrol.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/random/random.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/string/string.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/time/time.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/types.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/uefi/uefipcirootbridgeioprotocol.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/uuid/utils.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/uefibase/other/uefibootmemorymap.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/uefibase/types.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/uefibase/uefi/uefi.h>
#include <com/ngos/shared/uefibase/sections/section0/generated/com/ngos/shared/common/types.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection0()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section0, com_ngos_shared_common_asm_bitutils);
    CALL_TEST_CASES(section0, com_ngos_shared_common_asm_instructions);
    CALL_TEST_CASES(section0, com_ngos_shared_common_bootparams_memorymapentry);
    CALL_TEST_CASES(section0, com_ngos_shared_common_checksum_adler);
    CALL_TEST_CASES(section0, com_ngos_shared_common_checksum_crc);
    CALL_TEST_CASES(section0, com_ngos_shared_common_checksum_lib_md5hash);
    CALL_TEST_CASES(section0, com_ngos_shared_common_checksum_md5);
    CALL_TEST_CASES(section0, com_ngos_shared_common_containers_arraylist);
    CALL_TEST_CASES(section0, com_ngos_shared_common_containers_lib_listelement);
    CALL_TEST_CASES(section0, com_ngos_shared_common_containers_lib_mapelement);
    CALL_TEST_CASES(section0, com_ngos_shared_common_containers_list);
    CALL_TEST_CASES(section0, com_ngos_shared_common_containers_map);
    CALL_TEST_CASES(section0, com_ngos_shared_common_cpu_cpu);
    CALL_TEST_CASES(section0, com_ngos_shared_common_cryptography_aes);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_dmi);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_dmistringid);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_dmichassisentry);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmibiosextendedromsize);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmibiosromsize);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmicacheconfiguration);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmicachesize);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmicachesize2);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmimemoryarraymappedaddressrange);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmimemorydeviceextendedsize);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmimemorydevicemappedaddressrange);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmimemorydevicesize);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmiphysicalmemoryarraymaximumcapacity);
    CALL_TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmiportablebatterymanufacturedate);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_avx2_avx2);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_avx512bw_avx512bw);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_avx512cd_avx512cd);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_avx512dq_avx512dq);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_avx512f_avx512f);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_avx512vl_avx512vl);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_avx_avx);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_fma3_fma3);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_fpu);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_sse2_sse2);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_sse3_sse3);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_sse41_sse41);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_sse42_sse42);
    CALL_TEST_CASES(section0, com_ngos_shared_common_fpu_sse_sse);
    CALL_TEST_CASES(section0, com_ngos_shared_common_graphics_image);
    CALL_TEST_CASES(section0, com_ngos_shared_common_graphics_ninepatch);
    CALL_TEST_CASES(section0, com_ngos_shared_common_graphics_png_png);
    CALL_TEST_CASES(section0, com_ngos_shared_common_graphics_rgbapixel);
    CALL_TEST_CASES(section0, com_ngos_shared_common_graphics_stretchrange);
    CALL_TEST_CASES(section0, com_ngos_shared_common_gui_widgets_widget);
    CALL_TEST_CASES(section0, com_ngos_shared_common_guid_utils);
    CALL_TEST_CASES(section0, com_ngos_shared_common_hex_hex);
    CALL_TEST_CASES(section0, com_ngos_shared_common_macro_utils);
    CALL_TEST_CASES(section0, com_ngos_shared_common_memory_memory);
    CALL_TEST_CASES(section0, com_ngos_shared_common_ngos_linkage);
    CALL_TEST_CASES(section0, com_ngos_shared_common_ngos_types);
    CALL_TEST_CASES(section0, com_ngos_shared_common_ngos_utils);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pagetable_utils);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressaccesscontrolservicesacscapability);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressmulticastcapabilityregister);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressmulticastcontrolregister);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressresizablebaseaddresscontrol);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressrootcomplexlinkdeclarationlinkaddresslinkconfigurationspace);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressvirtualchannelvirtualchannelresourcecapability);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciextendeddevicecommand);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciextendeddevicestatus);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pcimessagesignaledinterruptsextendedmessagecontrol);
    CALL_TEST_CASES(section0, com_ngos_shared_common_pci_lib_pcimessagesignaledinterruptsmessagecontrol);
    CALL_TEST_CASES(section0, com_ngos_shared_common_printf_printf);
    CALL_TEST_CASES(section0, com_ngos_shared_common_random_random);
    CALL_TEST_CASES(section0, com_ngos_shared_common_string_string);
    CALL_TEST_CASES(section0, com_ngos_shared_common_string_utils);
    CALL_TEST_CASES(section0, com_ngos_shared_common_time_time);
    CALL_TEST_CASES(section0, com_ngos_shared_common_types);
    CALL_TEST_CASES(section0, com_ngos_shared_common_uefi_uefipcirootbridgeioprotocol);
    CALL_TEST_CASES(section0, com_ngos_shared_common_uuid_utils);
    CALL_TEST_CASES(section0, com_ngos_shared_uefibase_other_uefibootmemorymap);
    CALL_TEST_CASES(section0, com_ngos_shared_uefibase_types);
    CALL_TEST_CASES(section0, com_ngos_shared_uefibase_uefi_uefi);
    CALL_TEST_CASES(section0, generated_com_ngos_shared_common_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_TESTCASE_H
