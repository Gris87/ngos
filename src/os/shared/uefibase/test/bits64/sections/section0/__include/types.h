#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H



#include <asm/bitutils.h>
#include <bootparams/bootparams.h>
#include <bootparams/bootparamsheader.h>
#include <bootparams/memorymapentry.h>
#include <bootparams/memorymapentrytype.h>
#include <bootparams/pciromimagewithinfo.h>
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
#include <gpt/gptdata.h>
#include <gpt/gptentry.h>
#include <gpt/gptheader.h>
#include <guid/guid.h>
#include <idt/idtdescriptor.h>
#include <idt/idtregister.h>
#include <idt/type.h>
#include <mbr/mbr.h>
#include <mbr/mbrpartition.h>
#include <mbr/mbrpartitiontype.h>
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
#include <uefi/uefiallocatetype.h>
#include <uefi/uefiblockiomedia.h>
#include <uefi/uefiblockioprotocol.h>
#include <uefi/uefibootservices.h>
#include <uefi/ueficapsuleheader.h>
#include <uefi/ueficonfigurationtable.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefidevicepathtotextprotocol.h>
#include <uefi/uefieventtype.h>
#include <uefi/uefifileattributeflags.h>
#include <uefi/uefifileinfo.h>
#include <uefi/uefifileiotoken.h>
#include <uefi/uefifilemodeflags.h>
#include <uefi/uefifilepath.h>
#include <uefi/uefifileprotocol.h>
#include <uefi/uefigraphicsoutputbltoperation.h>
#include <uefi/uefigraphicsoutputbltpixel.h>
#include <uefi/uefigraphicsoutputmodeinformation.h>
#include <uefi/uefigraphicsoutputprotocol.h>
#include <uefi/uefigraphicsoutputprotocolmode.h>
#include <uefi/uefigraphicspixelformat.h>
#include <uefi/uefiharddrivedevicepath.h>
#include <uefi/uefiharddrivedevicepathmbrtype.h>
#include <uefi/uefiharddrivedevicepathsignaturetype.h>
#include <uefi/uefiinputkey.h>
#include <uefi/uefiinterfacetype.h>
#include <uefi/uefiloadedimageprotocol.h>
#include <uefi/uefilocatesearchtype.h>
#include <uefi/uefimemorydescriptor.h>
#include <uefi/uefimemorytype.h>
#include <uefi/uefiopenprotocolinformationentry.h>
#include <uefi/uefipciioprotocol.h>
#include <uefi/uefipciioprotocolaccess.h>
#include <uefi/uefipciioprotocolattributeoperation.h>
#include <uefi/uefipciioprotocolconfigaccess.h>
#include <uefi/uefipciioprotocoloperation.h>
#include <uefi/uefipciioprotocolwidth.h>
#include <uefi/uefipixelbitmask.h>
#include <uefi/uefiresettype.h>
#include <uefi/uefiruntimeservices.h>
#include <uefi/uefisimplefilesystemprotocol.h>
#include <uefi/uefisimpleinputinterface.h>
#include <uefi/uefisimpletextoutputinterface.h>
#include <uefi/uefisimpletextoutputmode.h>
#include <uefi/uefistatus.h>
#include <uefi/uefisystemtable.h>
#include <uefi/uefitableheader.h>
#include <uefi/uefitime.h>
#include <uefi/uefitimecapabilicies.h>
#include <uefi/uefitimerdelay.h>
#include <uefibase/test/bits64/testengine.h>
#include <uuid/uuid.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(BitUtils),                                     1);
        TEST_ASSERT_EQUALS(sizeof(BootParams),                                   112);
        TEST_ASSERT_EQUALS(sizeof(BootParamsHeader),                             32);
        TEST_ASSERT_EQUALS(sizeof(ElfClass),                                     1);
        TEST_ASSERT_EQUALS(sizeof(ElfData),                                      1);
        TEST_ASSERT_EQUALS(sizeof(ElfFileVersion),                               1);
        TEST_ASSERT_EQUALS(sizeof(ElfHeader),                                    64);
        TEST_ASSERT_EQUALS(sizeof(ElfHeaderIdentification),                      16);
        TEST_ASSERT_EQUALS(sizeof(ElfMachine),                                   2);
        TEST_ASSERT_EQUALS(sizeof(ElfOsAbi),                                     1);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramFlag),                               4);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramHeaderTableEntry),                   56);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramType),                               4);
        TEST_ASSERT_EQUALS(sizeof(ElfRela),                                      24);
        TEST_ASSERT_EQUALS(sizeof(ElfRelaType),                                  4);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionFlag),                               8);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionHeaderTableEntry),                   64);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionType),                               4);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbol),                                    24);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolBind),                                1);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolType),                                1);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolVisibility),                          1);
        TEST_ASSERT_EQUALS(sizeof(ElfType),                                      2);
        TEST_ASSERT_EQUALS(sizeof(ElfVersion),                                   4);
        TEST_ASSERT_EQUALS(sizeof(GdtDescriptor),                                8);
        TEST_ASSERT_EQUALS(sizeof(GdtRegister),                                  10);
        TEST_ASSERT_EQUALS(sizeof(GptData),                                      24);
        TEST_ASSERT_EQUALS(sizeof(GptEntry),                                     128);
        TEST_ASSERT_EQUALS(sizeof(GptHeader),                                    512);
        TEST_ASSERT_EQUALS(sizeof(Guid),                                         16);
        TEST_ASSERT_EQUALS(sizeof(IdtDescriptor),                                16);
        TEST_ASSERT_EQUALS(sizeof(IdtRegister),                                  10);
        TEST_ASSERT_EQUALS(sizeof(IdtType),                                      1);
        TEST_ASSERT_EQUALS(sizeof(Mbr),                                          512);
        TEST_ASSERT_EQUALS(sizeof(MbrPartition),                                 16);
        TEST_ASSERT_EQUALS(sizeof(MbrPartitionType),                             1);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntry),                               24);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntryType),                           1);
        TEST_ASSERT_EQUALS(sizeof(NgosStatus),                                   8);
        TEST_ASSERT_EQUALS(sizeof(PGD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PMD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PTE),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PUD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PciRomImageWithInfo),                          56);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpi20ConfigurationTable),                 1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiConfigurationTable),                   1);
        TEST_ASSERT_EQUALS(sizeof(UefiAllocateType),                             4);
        TEST_ASSERT_EQUALS(sizeof(UefiBlockIoMedia),                             48);
        TEST_ASSERT_EQUALS(sizeof(UefiBlockIoProtocol),                          48);
        TEST_ASSERT_EQUALS(sizeof(UefiBootServices),                             376);
        TEST_ASSERT_EQUALS(sizeof(UefiCapsuleHeader),                            28);
        TEST_ASSERT_EQUALS(sizeof(UefiConfigurationTable),                       24);
        TEST_ASSERT_EQUALS(sizeof(UefiDebugInfoConfigurationTable),              1);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePath),                               4);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathSubType),                        1);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathToTextProtocol),                 16);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathType),                           1);
        TEST_ASSERT_EQUALS(sizeof(UefiDxeServicesConfigurationTable),            1);
        TEST_ASSERT_EQUALS(sizeof(UefiEventType),                                4);
        TEST_ASSERT_EQUALS(sizeof(UefiFileAttributeFlag),                        8);
        TEST_ASSERT_EQUALS(sizeof(UefiFileInfo),                                 80);
        TEST_ASSERT_EQUALS(sizeof(UefiFileIoToken),                              32);
        TEST_ASSERT_EQUALS(sizeof(UefiFileModeFlag),                             8);
        TEST_ASSERT_EQUALS(sizeof(UefiFilePath),                                 4);
        TEST_ASSERT_EQUALS(sizeof(UefiFileProtocol),                             120);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputBltOperation),               4);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputBltPixel),                   4);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputModeInformation),            36);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputProtocol),                   32);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputProtocolMode),               40);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsPixelFormat),                      4);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePath),                      48);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePathMbrType),               1);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePathSignatureType),         1);
        TEST_ASSERT_EQUALS(sizeof(UefiHcdpConfigurationTable),                   1);
        TEST_ASSERT_EQUALS(sizeof(UefiHobListConfigurationTable),                1);
        TEST_ASSERT_EQUALS(sizeof(UefiInfo),                                     40);
        TEST_ASSERT_EQUALS(sizeof(UefiInputKey),                                 4);
        TEST_ASSERT_EQUALS(sizeof(UefiInterfaceType),                            4);
        TEST_ASSERT_EQUALS(sizeof(UefiLoadedImageProtocol),                      96);
        TEST_ASSERT_EQUALS(sizeof(UefiLocateSearchType),                         4);
        TEST_ASSERT_EQUALS(sizeof(UefiLzmaDecompressConfigurationTable),         1);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryAttributesConfigurationTable),       16);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryDescriptor),                         40);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryMapInfo),                            32);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryStatusCodeRecordConfigurationTable), 1);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryType),                               4);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryTypeInformationConfigurationTable),  1);
        TEST_ASSERT_EQUALS(sizeof(UefiMpsConfigurationTable),                    1);
        TEST_ASSERT_EQUALS(sizeof(UefiOpenProtocolInformationEntry),             24);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocol),                            160);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAccess),                      16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAttributeOperation),          4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolConfigAccess),                16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolOperation),                   4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolWidth),                       4);
        TEST_ASSERT_EQUALS(sizeof(UefiPixelBitmask),                             16);
        TEST_ASSERT_EQUALS(sizeof(UefiPropertiesConfigurationTable),             1);
        TEST_ASSERT_EQUALS(sizeof(UefiResetType),                                4);
        TEST_ASSERT_EQUALS(sizeof(UefiRuntimeServices),                          136);
        TEST_ASSERT_EQUALS(sizeof(UefiSalSystemConfigurationTable),              1);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleFileSystemProtocol),                 16);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleInputInterface),                     24);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleTextOutputInterface),                80);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleTextOutputMode),                     24);
        TEST_ASSERT_EQUALS(sizeof(UefiSmbios3ConfigurationTable),                24);
        TEST_ASSERT_EQUALS(sizeof(UefiSmbiosConfigurationTable),                 31);
        TEST_ASSERT_EQUALS(sizeof(UefiStatus),                                   8);
        TEST_ASSERT_EQUALS(sizeof(UefiSystemResourceConfigurationTable),         1);
        TEST_ASSERT_EQUALS(sizeof(UefiSystemTable),                              120);
        TEST_ASSERT_EQUALS(sizeof(UefiTableHeader),                              24);
        TEST_ASSERT_EQUALS(sizeof(UefiTime),                                     16);
        TEST_ASSERT_EQUALS(sizeof(UefiTimeCapabilities),                         12);
        TEST_ASSERT_EQUALS(sizeof(UefiTimerDelay),                               4);
        TEST_ASSERT_EQUALS(sizeof(UefiUgaIoConfigurationTable),                  1);
        TEST_ASSERT_EQUALS(sizeof(Uuid),                                         16);

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(sizeof(P4D), 8);
#endif
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H
