#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H



#include <bootparams/bootparams.h>
#include <bootparams/bootparamsheader.h>
#include <bootparams/memorymapentry.h>
#include <bootparams/pciromimagewithinfo.h>
#include <bootparams/screeninfo.h>
#include <bootparams/uefiinfo.h>
#include <bootparams/uefimemorymapinfo.h>
#include <buildconfig.h>
#include <elf/class.h>
#include <elf/data.h>
#include <elf/header.h>
#include <elf/headeridentification.h>
#include <elf/programheadertableentry.h>
#include <elf/rela.h>
#include <elf/relatype.h>
#include <elf/sectionheadertableentry.h>
#include <elf/symbol.h>
#include <gdt/gdtdescriptor.h>
#include <gdt/gdtregister.h>
#include <idt/idtdescriptor.h>
#include <idt/idtregister.h>
#include <ngos/status.h>
#include <pagetable/types.h>
#include <uefi/config/uefiacpi20configurationtable.h>
#include <uefi/config/uefiacpiconfigurationtable.h>
#include <uefi/config/uefidebuginfoconfigurationtable.h>
#include <uefi/config/uefidxeservicesconfigurationtable.h>
#include <uefi/config/uefihcdpconfigurationtable.h>
#include <uefi/config/uefihoblistconfigurationtable.h>
#include <uefi/config/uefilzmadecompressconfigurationtable.h>
#include <uefi/config/uefimemoryattributesconfigurationtable.h>
#include <uefi/config/uefimemorystatuscoderecordconfigurationtable.h>
#include <uefi/config/uefimemorytypeinformationconfigurationtable.h>
#include <uefi/config/uefimpsconfigurationtable.h>
#include <uefi/config/uefipropertiesconfigurationtable.h>
#include <uefi/config/uefisalsystemconfigurationtable.h>
#include <uefi/config/uefismbios3configurationtable.h>
#include <uefi/config/uefismbiosconfigurationtable.h>
#include <uefi/config/uefisystemresourceconfigurationtable.h>
#include <uefi/config/uefiugaioconfigurationtable.h>
#include <uefi/uefibootservices.h>
#include <uefi/ueficapsuleheader.h>
#include <uefi/ueficonfigurationtable.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefigraphicsoutputbltpixel.h>
#include <uefi/uefigraphicsoutputmodeinformation.h>
#include <uefi/uefigraphicsoutputprotocol.h>
#include <uefi/uefigraphicsoutputprotocolmode.h>
#include <uefi/uefiguid.h>
#include <uefi/uefiinputkey.h>
#include <uefi/uefiloadedimageprotocol.h>
#include <uefi/uefimemorydescriptor.h>
#include <uefi/uefiopenprotocolinformationentry.h>
#include <uefi/uefipciioprotocol.h>
#include <uefi/uefipciioprotocolaccess.h>
#include <uefi/uefipciioprotocolconfigaccess.h>
#include <uefi/uefipixelbitmask.h>
#include <uefi/uefiruntimeservices.h>
#include <uefi/uefisimpleinputinterface.h>
#include <uefi/uefisimpletextoutputinterface.h>
#include <uefi/uefisimpletextoutputmode.h>
#include <uefi/uefisystemtable.h>
#include <uefi/uefitableheader.h>
#include <uefi/uefitime.h>
#include <uefi/uefitimecapabilicies.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(BootParams),                                   128);
        TEST_ASSERT_EQUALS(sizeof(BootParamsHeader),                             32);
        TEST_ASSERT_EQUALS(sizeof(ElfClass),                                     1);
        TEST_ASSERT_EQUALS(sizeof(ElfData),                                      1);
        TEST_ASSERT_EQUALS(sizeof(ElfFileVersion),                               1);
        TEST_ASSERT_EQUALS(sizeof(ElfHeader),                                    64);
        TEST_ASSERT_EQUALS(sizeof(ElfHeaderIdentification),                      16);
        TEST_ASSERT_EQUALS(sizeof(ElfMachine),                                   1);
        TEST_ASSERT_EQUALS(sizeof(ElfOsAbi),                                     1);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramFlag),                               4);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramHeaderTableEntry),                   56);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramType),                               4);
        TEST_ASSERT_EQUALS(sizeof(ElfRela),                                      24);
        TEST_ASSERT_EQUALS(sizeof(ElfRelaType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionFlag),                               8);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionHeaderTableEntry),                   64);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionType),                               4);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbol),                                    24);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolBind),                                1);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolType),                                1);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolVisibility),                          1);
        TEST_ASSERT_EQUALS(sizeof(ElfType),                                      2);
        TEST_ASSERT_EQUALS(sizeof(ElfVersion),                                   1);
        TEST_ASSERT_EQUALS(sizeof(GdtDescriptor),                                8);
        TEST_ASSERT_EQUALS(sizeof(GdtRegister),                                  10);
        TEST_ASSERT_EQUALS(sizeof(IdtDescriptor),                                16);
        TEST_ASSERT_EQUALS(sizeof(IdtRegister),                                  10);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntry),                               24);
        TEST_ASSERT_EQUALS(sizeof(NgosStatus),                                   8);
        TEST_ASSERT_EQUALS(sizeof(PGD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PMD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PTE),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PUD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PciRomImageWithInfo),                          56);
        TEST_ASSERT_EQUALS(sizeof(ScreenInfo),                                   32);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpi20ConfigurationTable),                 1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiConfigurationTable),                   1);
        TEST_ASSERT_EQUALS(sizeof(UefiBootServices),                             376);
        TEST_ASSERT_EQUALS(sizeof(UefiCapsuleHeader),                            28);
        TEST_ASSERT_EQUALS(sizeof(UefiConfigurationTable),                       24);
        TEST_ASSERT_EQUALS(sizeof(UefiDebugInfoConfigurationTable),              1);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePath),                               4);
        TEST_ASSERT_EQUALS(sizeof(UefiDxeServicesConfigurationTable),            1);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputBltPixel),                   4);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputModeInformation),            36);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputProtocol),                   32);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputProtocolMode),               40);
        TEST_ASSERT_EQUALS(sizeof(UefiGuid),                                     16);
        TEST_ASSERT_EQUALS(sizeof(UefiHcdpConfigurationTable),                   1);
        TEST_ASSERT_EQUALS(sizeof(UefiHobListConfigurationTable),                1);
        TEST_ASSERT_EQUALS(sizeof(UefiInfo),                                     40);
        TEST_ASSERT_EQUALS(sizeof(UefiInputKey),                                 4);
        TEST_ASSERT_EQUALS(sizeof(UefiLoadedImageProtocol),                      96);
        TEST_ASSERT_EQUALS(sizeof(UefiLzmaDecompressConfigurationTable),         1);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryAttributesConfigurationTable),       16);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryDescriptor),                         40);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryMapInfo),                            32);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryStatusCodeRecordConfigurationTable), 1);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryTypeInformationConfigurationTable),  1);
        TEST_ASSERT_EQUALS(sizeof(UefiMpsConfigurationTable),                    1);
        TEST_ASSERT_EQUALS(sizeof(UefiOpenProtocolInformationEntry),             24);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocol),                            160);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAccess),                      16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolConfigAccess),                16);
        TEST_ASSERT_EQUALS(sizeof(UefiPixelBitmask),                             16);
        TEST_ASSERT_EQUALS(sizeof(UefiPropertiesConfigurationTable),             1);
        TEST_ASSERT_EQUALS(sizeof(UefiRuntimeServices),                          136);
        TEST_ASSERT_EQUALS(sizeof(UefiSalSystemConfigurationTable),              1);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleInputInterface),                     24);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleTextOutputInterface),                80);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleTextOutputMode),                     24);
        TEST_ASSERT_EQUALS(sizeof(UefiSmbios3ConfigurationTable),                24);
        TEST_ASSERT_EQUALS(sizeof(UefiSmbiosConfigurationTable),                 31);
        TEST_ASSERT_EQUALS(sizeof(UefiSystemResourceConfigurationTable),         1);
        TEST_ASSERT_EQUALS(sizeof(UefiSystemTable),                              120);
        TEST_ASSERT_EQUALS(sizeof(UefiTableHeader),                              24);
        TEST_ASSERT_EQUALS(sizeof(UefiTime),                                     16);
        TEST_ASSERT_EQUALS(sizeof(UefiTimeCapabilities),                         12);
        TEST_ASSERT_EQUALS(sizeof(UefiUgaIoConfigurationTable),                  1);

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(sizeof(P4D), 8);
#endif
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H
