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
#include <idt/idtgatetype.h>
#include <idt/idtregister.h>
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
#include <uefi/uefiabsolutepointermode.h>
#include <uefi/uefiabsolutepointermodeattributeflags.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefiabsolutepointerstate.h>
#include <uefi/uefiabsolutepointerstateactivebuttonflags.h>
#include <uefi/uefiallocatetype.h>
#include <uefi/uefiblockiomedia.h>
#include <uefi/uefiblockioprotocol.h>
#include <uefi/uefibootservices.h>
#include <uefi/ueficapsuleheader.h>
#include <uefi/ueficonfigurationtable.h>
#include <uefi/ueficonsolecontrolprotocol.h>
#include <uefi/ueficonsolecontrolscreenmode.h>
#include <uefi/ueficpuphysicallocation.h>
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
#include <uefi/uefiinputkeyscancode.h>
#include <uefi/uefiinterfacetype.h>
#include <uefi/uefiloadedimageprotocol.h>
#include <uefi/uefilocatesearchtype.h>
#include <uefi/uefimemorydescriptor.h>
#include <uefi/uefimemorytype.h>
#include <uefi/uefimpservicesprotocol.h>
#include <uefi/uefiopenprotocolinformationentry.h>
#include <uefi/uefipciioprotocol.h>
#include <uefi/uefipciioprotocolaccess.h>
#include <uefi/uefipciioprotocolattributeoperation.h>
#include <uefi/uefipciioprotocolconfigaccess.h>
#include <uefi/uefipciioprotocoloperation.h>
#include <uefi/uefipciioprotocolwidth.h>
#include <uefi/uefipixelbitmask.h>
#include <uefi/uefiprocessorinformation.h>
#include <uefi/uefiprocessorinformationstatusflags.h>
#include <uefi/uefiresettype.h>
#include <uefi/uefiruntimeservices.h>
#include <uefi/uefisimplefilesystemprotocol.h>
#include <uefi/uefisimpleinputinterface.h>
#include <uefi/uefisimplepointermode.h>
#include <uefi/uefisimplepointerprotocol.h>
#include <uefi/uefisimplepointerstate.h>
#include <uefi/uefisimpletextoutputinterface.h>
#include <uefi/uefisimpletextoutputmode.h>
#include <uefi/uefistatus.h>
#include <uefi/uefisystemtable.h>
#include <uefi/uefitableheader.h>
#include <uefi/uefitime.h>
#include <uefi/uefitimecapabilicies.h>
#include <uefi/uefitimerdelay.h>
#include <uefi/uefitpl.h>
#include <uefi/uefivariableattributeflags.h>
#include <uefibase/test/bits64/testengine.h>
#include <uuid/uuid.h>



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
        // ======================================================
        // |  p : 1  |  dpl : 2  |  __pad : 1  |  gateType : 4  |
        // ======================================================



        temp.type = 0xAA;       // ||  1  |  01  |  0  |  1010  ||

        TEST_ASSERT_EQUALS(temp.gateType, 10);
        TEST_ASSERT_EQUALS(temp.__pad,    0);
        TEST_ASSERT_EQUALS(temp.dpl,      1);
        TEST_ASSERT_EQUALS(temp.p,        1);



        temp.gateType = 5;      // ||  1  |  01  |  0  |  0101  ||

        TEST_ASSERT_EQUALS(temp.type, 0xA5);



        temp.__pad = 1;         // ||  1  |  01  |  1  |  0101  ||

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
