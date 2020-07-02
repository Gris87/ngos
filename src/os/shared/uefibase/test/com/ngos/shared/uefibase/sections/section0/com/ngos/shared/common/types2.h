#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H



#include <common/src/com/ngos/shared/common/asm/bitutils.h>
#include <common/src/com/ngos/shared/common/bootparams/bootparams.h>
#include <common/src/com/ngos/shared/common/bootparams/bootparamsheader.h>
#include <common/src/com/ngos/shared/common/bootparams/memorymapentry.h>
#include <common/src/com/ngos/shared/common/bootparams/memorymapentrytype.h>
#include <common/src/com/ngos/shared/common/bootparams/pciromimagewithinfo.h>
#include <common/src/com/ngos/shared/common/bootparams/uefiinfo.h>
#include <common/src/com/ngos/shared/common/bootparams/uefimemorymapinfo.h>
#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/elf/class.h>
#include <common/src/com/ngos/shared/common/elf/data.h>
#include <common/src/com/ngos/shared/common/elf/header.h>
#include <common/src/com/ngos/shared/common/elf/headeridentification.h>
#include <common/src/com/ngos/shared/common/elf/programheadertableentry.h>
#include <common/src/com/ngos/shared/common/elf/rela.h>
#include <common/src/com/ngos/shared/common/elf/relatype.h>
#include <common/src/com/ngos/shared/common/elf/sectionheadertableentry.h>
#include <common/src/com/ngos/shared/common/elf/symbol.h>
#include <common/src/com/ngos/shared/common/gdt/gdtdescriptor.h>
#include <common/src/com/ngos/shared/common/gdt/gdtregister.h>
#include <common/src/com/ngos/shared/common/gpt/gptdata.h>
#include <common/src/com/ngos/shared/common/gpt/gptentry.h>
#include <common/src/com/ngos/shared/common/gpt/gptheader.h>
#include <common/src/com/ngos/shared/common/guid/guid.h>
#include <common/src/com/ngos/shared/common/idt/idtdescriptor.h>
#include <common/src/com/ngos/shared/common/idt/idtgatetype.h>
#include <common/src/com/ngos/shared/common/idt/idtregister.h>
#include <common/src/com/ngos/shared/common/mbr/mbr.h>
#include <common/src/com/ngos/shared/common/mbr/mbrpartition.h>
#include <common/src/com/ngos/shared/common/mbr/mbrpartitiontype.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>
#include <common/src/com/ngos/shared/common/pagetable/types.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefiacpi20configurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefiacpiconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefidebuginfoconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefidxeservicesconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefihcdpconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefihoblistconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefilzmadecompressconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefimemoryattributesconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefimemorystatuscoderecordconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefimemorytypeinformationconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefimpsconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefipropertiesconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefisalsystemconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefismbios3configurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefismbiosconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefisystemresourceconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/config/uefiugaioconfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointermode.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointermodeattributeflags.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointerprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointerstate.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointerstateactivebuttonflags.h>
#include <common/src/com/ngos/shared/common/uefi/uefiallocatetype.h>
#include <common/src/com/ngos/shared/common/uefi/uefiblockiomedia.h>
#include <common/src/com/ngos/shared/common/uefi/uefiblockioprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefibootservices.h>
#include <common/src/com/ngos/shared/common/uefi/ueficapsuleheader.h>
#include <common/src/com/ngos/shared/common/uefi/ueficonfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/ueficonsolecontrolprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/ueficonsolecontrolscreenmode.h>
#include <common/src/com/ngos/shared/common/uefi/ueficpuphysicallocation.h>
#include <common/src/com/ngos/shared/common/uefi/uefidevicepath.h>
#include <common/src/com/ngos/shared/common/uefi/uefidevicepathtotextprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefieventtype.h>
#include <common/src/com/ngos/shared/common/uefi/uefifileattributeflags.h>
#include <common/src/com/ngos/shared/common/uefi/uefifileinfo.h>
#include <common/src/com/ngos/shared/common/uefi/uefifileiotoken.h>
#include <common/src/com/ngos/shared/common/uefi/uefifilemodeflags.h>
#include <common/src/com/ngos/shared/common/uefi/uefifilepath.h>
#include <common/src/com/ngos/shared/common/uefi/uefifileprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicsoutputbltoperation.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicsoutputbltpixel.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicsoutputmodeinformation.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicsoutputprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicsoutputprotocolmode.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicspixelformat.h>
#include <common/src/com/ngos/shared/common/uefi/uefiharddrivedevicepath.h>
#include <common/src/com/ngos/shared/common/uefi/uefiharddrivedevicepathmbrtype.h>
#include <common/src/com/ngos/shared/common/uefi/uefiharddrivedevicepathsignaturetype.h>
#include <common/src/com/ngos/shared/common/uefi/uefiinputkey.h>
#include <common/src/com/ngos/shared/common/uefi/uefiinputkeyscancode.h>
#include <common/src/com/ngos/shared/common/uefi/uefiinterfacetype.h>
#include <common/src/com/ngos/shared/common/uefi/uefiloadedimageprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefilocatesearchtype.h>
#include <common/src/com/ngos/shared/common/uefi/uefimemorydescriptor.h>
#include <common/src/com/ngos/shared/common/uefi/uefimemorytype.h>
#include <common/src/com/ngos/shared/common/uefi/uefimpservicesprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefiopenprotocolinformationentry.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocolaccess.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocolattributeoperation.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocolconfigaccess.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocoloperation.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocolwidth.h>
#include <common/src/com/ngos/shared/common/uefi/uefipixelbitmask.h>
#include <common/src/com/ngos/shared/common/uefi/uefiprocessorinformation.h>
#include <common/src/com/ngos/shared/common/uefi/uefiprocessorinformationstatusflags.h>
#include <common/src/com/ngos/shared/common/uefi/uefiresettype.h>
#include <common/src/com/ngos/shared/common/uefi/uefiruntimeservices.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimplefilesystemprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimpleinputinterface.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimplepointermode.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimplepointerprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimplepointerstate.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimpletextoutputinterface.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimpletextoutputmode.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>
#include <common/src/com/ngos/shared/common/uefi/uefisystemtable.h>
#include <common/src/com/ngos/shared/common/uefi/uefitableheader.h>
#include <common/src/com/ngos/shared/common/uefi/uefitime.h>
#include <common/src/com/ngos/shared/common/uefi/uefitimecapabilicies.h>
#include <common/src/com/ngos/shared/common/uefi/uefitimerdelay.h>
#include <common/src/com/ngos/shared/common/uefi/uefitpl.h>
#include <common/src/com/ngos/shared/common/uefi/uefivariableattributeflags.h>
#include <uefibase/test/bits64/testengine.h>
#include <common/src/com/ngos/shared/common/uuid/uuid.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(BitUtils),                                     1);
        TEST_ASSERT_EQUALS(sizeof(BootParams),                                   624);
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
        TEST_ASSERT_EQUALS(sizeof(GptHeader),                                    96);
        TEST_ASSERT_EQUALS(sizeof(Guid),                                         16);
        TEST_ASSERT_EQUALS(sizeof(IdtDescriptor),                                16);
        TEST_ASSERT_EQUALS(sizeof(IdtGateType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(IdtRegister),                                  10);
        TEST_ASSERT_EQUALS(sizeof(Mbr),                                          512);
        TEST_ASSERT_EQUALS(sizeof(MbrPartition),                                 16);
        TEST_ASSERT_EQUALS(sizeof(MbrPartitionType),                             1);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntry),                               24);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntryType),                           1);
        TEST_ASSERT_EQUALS(sizeof(NgosStatus),                                   8);
        TEST_ASSERT_EQUALS(sizeof(PciRomImageWithInfo),                          56);
        TEST_ASSERT_EQUALS(sizeof(PGD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PMD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PTE),                                          8);
        TEST_ASSERT_EQUALS(sizeof(PUD),                                          8);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerMode),                      56);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerModeAttributeFlag),         4);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerProtocol),                  32);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerState),                     32);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerStateActiveButtonFlag),     4);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpi20ConfigurationTable),                 1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiConfigurationTable),                   1);
        TEST_ASSERT_EQUALS(sizeof(UefiAllocateType),                             4);
        TEST_ASSERT_EQUALS(sizeof(UefiBlockIoMedia),                             48);
        TEST_ASSERT_EQUALS(sizeof(UefiBlockIoProtocol),                          48);
        TEST_ASSERT_EQUALS(sizeof(UefiBootServices),                             376);
        TEST_ASSERT_EQUALS(sizeof(UefiCapsuleHeader),                            28);
        TEST_ASSERT_EQUALS(sizeof(UefiConfigurationTable),                       24);
        TEST_ASSERT_EQUALS(sizeof(UefiConsoleControlProtocol),                   24);
        TEST_ASSERT_EQUALS(sizeof(UefiConsoleControlScreenMode),                 4);
        TEST_ASSERT_EQUALS(sizeof(UefiCpuPhysicalLocation),                      12);
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
        TEST_ASSERT_EQUALS(sizeof(UefiInputKeyScanCode),                         2);
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
        TEST_ASSERT_EQUALS(sizeof(UefiMpServicesProtocol),                       56);
        TEST_ASSERT_EQUALS(sizeof(UefiOpenProtocolInformationEntry),             24);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocol),                            160);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAccess),                      16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAttributeOperation),          4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolConfigAccess),                16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolOperation),                   4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolWidth),                       4);
        TEST_ASSERT_EQUALS(sizeof(UefiPixelBitmask),                             16);
        TEST_ASSERT_EQUALS(sizeof(UefiProcessorInformation),                     24);
        TEST_ASSERT_EQUALS(sizeof(UefiProcessorInformationStatusFlag),           4);
        TEST_ASSERT_EQUALS(sizeof(UefiPropertiesConfigurationTable),             1);
        TEST_ASSERT_EQUALS(sizeof(UefiResetType),                                4);
        TEST_ASSERT_EQUALS(sizeof(UefiRuntimeServices),                          136);
        TEST_ASSERT_EQUALS(sizeof(UefiSalSystemConfigurationTable),              1);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleFileSystemProtocol),                 16);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleInputInterface),                     24);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerMode),                        32);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerProtocol),                    32);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerState),                       16);
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
        TEST_ASSERT_EQUALS(sizeof(UefiTpl),                                      8);
        TEST_ASSERT_EQUALS(sizeof(UefiUgaIoConfigurationTable),                  1);
        TEST_ASSERT_EQUALS(sizeof(UefiVariableAttributeFlag),                    4);
        TEST_ASSERT_EQUALS(sizeof(Uuid),                                         16);

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(sizeof(P4D), 8);
#endif
    }
    TEST_CASE_END();



    TEST_CASE("ElfSymbol");
    {
        ElfSymbol temp;



        // ElfSymbol - info:
        // ===========================
        // |  type : 4  |  bind : 4  |
        // ===========================



        temp.info = 0x12;       // ||  0001  |  0010  ||

        TEST_ASSERT_EQUALS(temp.bind, 2);
        TEST_ASSERT_EQUALS(temp.type, 1);



        temp.bind = 3;          // ||  0001  |  0011  ||

        TEST_ASSERT_EQUALS(temp.info, 0x13);



        temp.type = 4;          // ||  0100  |  0011  ||

        TEST_ASSERT_EQUALS(temp.info, 0x43);



        // ElfSymbol - other:
        // =======================================
        // |  visibility : 3  |  __reserved : 5  |
        // =======================================



        temp.other = 0x12;      // ||  000  |  10010  ||

        TEST_ASSERT_EQUALS(temp.__reserved, 18);
        TEST_ASSERT_EQUALS(temp.visibility, 0);



        temp.__reserved = 3;    // ||  000  |  00011  ||

        TEST_ASSERT_EQUALS(temp.other, 0x03);



        temp.visibility = 4;    // ||  100  |  00011  ||

        TEST_ASSERT_EQUALS(temp.other, 0x83);
    }
    TEST_CASE_END();



    TEST_CASE("GdtDescriptor");
    {
        GdtDescriptor temp;



        // GdtDescriptor - b:
        // ==========================================================
        // |                       base2 : 8                        |
        // |  g : 1  |  d : 1  |  l : 1  |  avl : 1  |  limit1 : 4  |
        // |  p : 1  |      dpl : 2      |   s : 1   |   type : 4   |
        // |                       base1 : 8                        |
        // ==========================================================



        temp.b = 0x0855AA20;    // ||  00001000  ||  0  |  1  |  0  |  1  |  0101  ||  1  |  01  |  0  |  1010  ||  00100000  ||

        TEST_ASSERT_EQUALS(temp.base1,  32);
        TEST_ASSERT_EQUALS(temp.type,   10);
        TEST_ASSERT_EQUALS(temp.s,      0);
        TEST_ASSERT_EQUALS(temp.dpl,    1);
        TEST_ASSERT_EQUALS(temp.p,      1);
        TEST_ASSERT_EQUALS(temp.limit1, 5);
        TEST_ASSERT_EQUALS(temp.avl,    1);
        TEST_ASSERT_EQUALS(temp.l,      0);
        TEST_ASSERT_EQUALS(temp.d,      1);
        TEST_ASSERT_EQUALS(temp.g,      0);
        TEST_ASSERT_EQUALS(temp.base2,  8);



        temp.base1 = 3;         // ||  00001000  ||  0  |  1  |  0  |  1  |  0101  ||  1  |  01  |  0  |  1010  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x0855AA03);



        temp.type = 5;          // ||  00001000  ||  0  |  1  |  0  |  1  |  0101  ||  1  |  01  |  0  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x0855A503);



        temp.s = 1;             // ||  00001000  ||  0  |  1  |  0  |  1  |  0101  ||  1  |  01  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x0855B503);



        temp.dpl = 3;           // ||  00001000  ||  0  |  1  |  0  |  1  |  0101  ||  1  |  11  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x0855F503);



        temp.p = 0;             // ||  00001000  ||  0  |  1  |  0  |  1  |  0101  ||  0  |  11  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x08557503);



        temp.limit1 = 3;        // ||  00001000  ||  0  |  1  |  0  |  1  |  0011  ||  0  |  11  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x08537503);



        temp.avl = 0;           // ||  00001000  ||  0  |  1  |  0  |  0  |  0011  ||  0  |  11  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x08437503);



        temp.l = 1;             // ||  00001000  ||  0  |  1  |  1  |  0  |  0011  ||  0  |  11  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x08637503);



        temp.d = 0;             // ||  00001000  ||  0  |  0  |  1  |  0  |  0011  ||  0  |  11  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x08237503);



        temp.g = 1;             // ||  00001000  ||  1  |  0  |  1  |  0  |  0011  ||  0  |  11  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x08A37503);



        temp.base2 = 7;         // ||  00000111  ||  1  |  0  |  1  |  0  |  0011  ||  0  |  11  |  1  |  0101  ||  00000011  ||

        TEST_ASSERT_EQUALS(temp.b, 0x07A37503);
    }
    TEST_CASE_END();



    TEST_CASE("IdtDescriptor");
    {
        IdtDescriptor temp;



        //  IdtDescriptor - type:
        // ===========================================================
        // |  p : 1  |  dpl : 2  |  __reserved : 1  |  gateType : 4  |
        // ===========================================================



        temp.type = 0xAA;       // ||  1  |  01  |  0  |  1010  ||

        TEST_ASSERT_EQUALS(temp.gateType,   10);
        TEST_ASSERT_EQUALS(temp.__reserved, 0);
        TEST_ASSERT_EQUALS(temp.dpl,        1);
        TEST_ASSERT_EQUALS(temp.p,          1);



        temp.gateType = 5;      // ||  1  |  01  |  0  |  0101  ||

        TEST_ASSERT_EQUALS(temp.type, 0xA5);



        temp.__reserved = 1;    // ||  1  |  01  |  1  |  0101  ||

        TEST_ASSERT_EQUALS(temp.type, 0xB5);



        temp.dpl = 3;           // ||  1  |  11  |  1  |  0101  ||

        TEST_ASSERT_EQUALS(temp.type, 0xF5);



        temp.p = 0;             // ||  0  |  11  |  1  |  0101  ||

        TEST_ASSERT_EQUALS(temp.type, 0x75);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_TYPES_H
