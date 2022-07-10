// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_GENERATED_COM_NGOS_SHARED_COMMON_TYPES_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_GENERATED_COM_NGOS_SHARED_COMMON_TYPES_H



#include <buildconfig.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid00000001eax.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid00000001ebx.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid00000004eax.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid0000000bebx0.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid0000000bebx1.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid80000008eax.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid80000008ecx.h>
#include <com/ngos/shared/common/cpu/lib/registers/x86cr8.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibiosextendedromsize.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicacheconfiguration.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicachesize.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicachesize2.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmichassistypeandlockpresent.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicoolingdevicetypeandstatus.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmielectricalcurrentprobelocationandstatus.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmifunctionnumberanddevicenumber.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmihardwaresecuritysettings.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmimemorydeviceattributes.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmimemorydeviceextendedsize.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmimemorydevicesize.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmionboarddevicesdevicetypeandenabled.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmionboarddevicesextendeddevicetypeandenabled.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiportablebatterymanufacturedate.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorstatusandsocketpopulated.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystempowersupplycharacteristics.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemresetcapabilities.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmitemperatureprobelocationandstatus.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmivoltageprobelocationandstatus.h>
#include <com/ngos/shared/common/elf/symbolinfo.h>
#include <com/ngos/shared/common/elf/symbolother.h>
#include <com/ngos/shared/common/fpu/registers/fpucwr.h>
#include <com/ngos/shared/common/fpu/registers/fpuswr.h>
#include <com/ngos/shared/common/gdt/gdtdescriptor.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantableidandtype.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegquantizationtableidandprecision.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofframecomponentsamplingfactor.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscancomponenthuffmantableids.h>
#include <com/ngos/shared/common/idt/idtdescriptortype.h>
#include <com/ngos/shared/common/msr/lib/registers/msria32biossignid.h>
#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportcommand.h>
#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportstatus.h>
#include <com/ngos/shared/common/pci/lib/pcibuiltinselftest.h>
#include <com/ngos/shared/common/pci/lib/pciexpressaccesscontrolservicesacscapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressadvancederrorcapabilitiesandcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressaricapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressaricontrolregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresscapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecapability2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecontrol2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationcapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationcontrolregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationstatusregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslatencytolerancereportingmaxnosnooplatencyregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslatencytolerancereportingmaxsnooplatencyregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcapability2.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcontrol2.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkstatus.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkstatus2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastbaseaddressregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastcapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastcontrolregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastoverlaybaseaddressregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspowerbudgetingdata.h>
#include <com/ngos/shared/common/pci/lib/pciexpressresizablebaseaddresscontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexinternallinkcontrollinkcapabilities.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexinternallinkcontrollinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexinternallinkcontrollinkstatus.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationelementselfdescription.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkaddresslinkconfigurationspace.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkdescription.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrooterrorstatus.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootstatus.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotcapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestercapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestercontrolregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvendorspecificheader.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportvirtualchannelcapability1.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportvirtualchannelcapability2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportvirtualchannelcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelvirtualchannelresourcecapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelvirtualchannelresourcecontrol.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgesecondarystatus.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgestatus.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicecommand.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicestatus.h>
#include <com/ngos/shared/common/pci/lib/pciheadertypeunion.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportcommand.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransporthostsecondaryinterfacecommand.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkconfig.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkerrorandfrequencyunion.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportslaveprimaryinterfacecommand.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsextendedmessagecontrol.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsextendedtableoffsetbirunion.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessageaddress.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessagecontrol.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementbridgesupportextensions.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementcapabilities.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementcontrolstatus.h>
#include <com/ngos/shared/common/pci/lib/pcislotnumberingexpansionslot.h>
#include <com/ngos/shared/common/pci/lib/pcistatus.h>
#include <com/ngos/shared/common/pci/lib/pcivitalproductdataaddressunion.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>
#include <com/ngos/shared/common/zlib/zlibheader.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, generated_com_ngos_shared_common_types);
{
    TEST_CASE("Cpuid00000001Eax");
    {
        Cpuid00000001Eax temp;



        // Cpuid00000001Eax:
        //
        // |     HHHH      |     GGGG      |
        // |     GGGG      |     FFFF      |
        // |  EE   |  DD   |     CCCC      |
        // |     BBBB      |     AAAA      |
        //
        // stepping       : 4  'A'
        // model          : 4  'B'
        // family         : 4  'C'
        // processorType  : 2  'D'
        // _reserved      : 2  'E'
        // extendedModel  : 4  'F'
        // extendedFamily : 8  'G'
        // _reserved2     : 4  'H'



        // |     0100      |     1100      |
        // |     0101      |     0110      |
        // |  01   |  00   |     0010      |
        // |     0000      |     1000      |
        temp.value32 = 0x4C564208;

        TEST_ASSERT_EQUALS(temp.stepping,       static_cast<good_U32>(8));
        TEST_ASSERT_EQUALS(temp.model,          static_cast<good_U32>(0));
        TEST_ASSERT_EQUALS(temp.family,         static_cast<good_U32>(2));
        TEST_ASSERT_EQUALS(temp.processorType,  static_cast<CpuidProcessorType>(0));
        TEST_ASSERT_EQUALS(temp._reserved,      static_cast<good_U32>(1));
        TEST_ASSERT_EQUALS(temp.extendedModel,  static_cast<good_U32>(6));
        TEST_ASSERT_EQUALS(temp.extendedFamily, static_cast<good_U32>(197));
        TEST_ASSERT_EQUALS(temp._reserved2,     static_cast<good_U32>(4));



        // |     0100      |     1100      |
        // |     0101      |     0110      |
        // |  01   |  00   |     0010      |
        // |     0000      |     0111      |
        temp.stepping = static_cast<good_U32>(7);

        TEST_ASSERT_EQUALS(temp.value32, 0x4C564207);



        // |     0100      |     1100      |
        // |     0101      |     0110      |
        // |  01   |  00   |     0010      |
        // |     1111      |     0111      |
        temp.model = static_cast<good_U32>(15);

        TEST_ASSERT_EQUALS(temp.value32, 0x4C5642F7);



        // |     0100      |     1100      |
        // |     0101      |     0110      |
        // |  01   |  00   |     1101      |
        // |     1111      |     0111      |
        temp.family = static_cast<good_U32>(13);

        TEST_ASSERT_EQUALS(temp.value32, 0x4C564DF7);



        // |     0100      |     1100      |
        // |     0101      |     0110      |
        // |  01   |  11   |     1101      |
        // |     1111      |     0111      |
        temp.processorType = static_cast<CpuidProcessorType>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x4C567DF7);



        // |     0100      |     1100      |
        // |     0101      |     0110      |
        // |  10   |  11   |     1101      |
        // |     1111      |     0111      |
        temp._reserved = static_cast<good_U32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x4C56BDF7);



        // |     0100      |     1100      |
        // |     0101      |     1001      |
        // |  10   |  11   |     1101      |
        // |     1111      |     0111      |
        temp.extendedModel = static_cast<good_U32>(9);

        TEST_ASSERT_EQUALS(temp.value32, 0x4C59BDF7);



        // |     0100      |     0011      |
        // |     1010      |     1001      |
        // |  10   |  11   |     1101      |
        // |     1111      |     0111      |
        temp.extendedFamily = static_cast<good_U32>(58);

        TEST_ASSERT_EQUALS(temp.value32, 0x43A9BDF7);



        // |     1011      |     0011      |
        // |     1010      |     1001      |
        // |  10   |  11   |     1101      |
        // |     1111      |     0111      |
        temp._reserved2 = static_cast<good_U32>(11);

        TEST_ASSERT_EQUALS(temp.value32, 0xB3A9BDF7);
    }
    TEST_CASE_END();



    TEST_CASE("Cpuid00000001Ebx");
    {
        Cpuid00000001Ebx temp;



        // Cpuid00000001Ebx:
        //
        // |           DDDDDDDD            |
        // |           CCCCCCCC            |
        // |           BBBBBBBB            |
        // |           AAAAAAAA            |
        //
        // brandIndex                : 8  'A'
        // cacheLineFlushSize        : 8  'B'
        // numberOfApicIdsPerPackage : 8  'C'
        // localApicId               : 8  'D'



        // |           00111110            |
        // |           00000011            |
        // |           00111100            |
        // |           11100101            |
        temp.value32 = 0x3E033CE5;

        TEST_ASSERT_EQUALS(temp.brandIndex,                static_cast<good_U32>(229));
        TEST_ASSERT_EQUALS(temp.cacheLineFlushSize,        static_cast<good_U32>(60));
        TEST_ASSERT_EQUALS(temp.numberOfApicIdsPerPackage, static_cast<good_U32>(3));
        TEST_ASSERT_EQUALS(temp.localApicId,               static_cast<good_U32>(62));



        // |           00111110            |
        // |           00000011            |
        // |           00111100            |
        // |           00011010            |
        temp.brandIndex = static_cast<good_U32>(26);

        TEST_ASSERT_EQUALS(temp.value32, 0x3E033C1A);



        // |           00111110            |
        // |           00000011            |
        // |           11000011            |
        // |           00011010            |
        temp.cacheLineFlushSize = static_cast<good_U32>(195);

        TEST_ASSERT_EQUALS(temp.value32, 0x3E03C31A);



        // |           00111110            |
        // |           11111100            |
        // |           11000011            |
        // |           00011010            |
        temp.numberOfApicIdsPerPackage = static_cast<good_U32>(252);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EFCC31A);



        // |           11000001            |
        // |           11111100            |
        // |           11000011            |
        // |           00011010            |
        temp.localApicId = static_cast<good_U32>(193);

        TEST_ASSERT_EQUALS(temp.value32, 0xC1FCC31A);
    }
    TEST_CASE_END();



    TEST_CASE("Cpuid00000004Eax");
    {
        Cpuid00000004Eax temp;



        // Cpuid00000004Eax:
        //
        // |        GGGGGG         |  FF   |
        // |           FFFFFFFF            |
        // |  FF   |     EEEE      | D | C |
        // |    BBB    |       AAAAA       |
        //
        // cacheType                  : 5  'A'
        // cacheLevel                 : 3  'B'
        // selfInitializingCacheLevel : 1  'C'
        // fullyAssociativeCache      : 1  'D'
        // _reserved                  : 4  'E'
        // maximumNumberOfThreads     : 12 'F'
        // maximumNumberOfCores       : 6  'G'



        // |        010000         |  01   |
        // |           00010010            |
        // |  00   |     0111      | 1 | 0 |
        // |    101    |       01101       |
        temp.value32 = 0x41121EAD;

        TEST_ASSERT_EQUALS(temp.cacheType,                  static_cast<CpuidCacheType>(13));
        TEST_ASSERT_EQUALS(temp.cacheLevel,                 static_cast<good_U32>(5));
        TEST_ASSERT_EQUALS(temp.selfInitializingCacheLevel, static_cast<BitYesNo>(0));
        TEST_ASSERT_EQUALS(temp.fullyAssociativeCache,      static_cast<BitYesNo>(1));
        TEST_ASSERT_EQUALS(temp._reserved,                  static_cast<good_U32>(7));
        TEST_ASSERT_EQUALS(temp.maximumNumberOfThreads,     static_cast<good_U32>(1096));
        TEST_ASSERT_EQUALS(temp.maximumNumberOfCores,       static_cast<good_U32>(16));



        // |        010000         |  01   |
        // |           00010010            |
        // |  00   |     0111      | 1 | 0 |
        // |    101    |       10010       |
        temp.cacheType = static_cast<CpuidCacheType>(18);

        TEST_ASSERT_EQUALS(temp.value32, 0x41121EB2);



        // |        010000         |  01   |
        // |           00010010            |
        // |  00   |     0111      | 1 | 0 |
        // |    010    |       10010       |
        temp.cacheLevel = static_cast<good_U32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x41121E52);



        // |        010000         |  01   |
        // |           00010010            |
        // |  00   |     0111      | 1 | 1 |
        // |    010    |       10010       |
        temp.selfInitializingCacheLevel = static_cast<BitYesNo>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x41121F52);



        // |        010000         |  01   |
        // |           00010010            |
        // |  00   |     0111      | 0 | 1 |
        // |    010    |       10010       |
        temp.fullyAssociativeCache = static_cast<BitYesNo>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x41121D52);



        // |        010000         |  01   |
        // |           00010010            |
        // |  00   |     1000      | 0 | 1 |
        // |    010    |       10010       |
        temp._reserved = static_cast<good_U32>(8);

        TEST_ASSERT_EQUALS(temp.value32, 0x41122152);



        // |        010000         |  10   |
        // |           11101101            |
        // |  11   |     1000      | 0 | 1 |
        // |    010    |       10010       |
        temp.maximumNumberOfThreads = static_cast<good_U32>(2999);

        TEST_ASSERT_EQUALS(temp.value32, 0x42EDE152);



        // |        101111         |  10   |
        // |           11101101            |
        // |  11   |     1000      | 0 | 1 |
        // |    010    |       10010       |
        temp.maximumNumberOfCores = static_cast<good_U32>(47);

        TEST_ASSERT_EQUALS(temp.value32, 0xBEEDE152);
    }
    TEST_CASE_END();



    TEST_CASE("Cpuid0000000BEbx0");
    {
        Cpuid0000000BEbx0 temp;



        // Cpuid0000000BEbx0:
        //
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // numberOfThreadsPerCore : 16 'A'
        // _reserved              : 16 'B'



        // |           11101010            |
        // |           01101111            |
        // |           10010001            |
        // |           11001001            |
        temp.value32 = 0xEA6F91C9;

        TEST_ASSERT_EQUALS(temp.numberOfThreadsPerCore, static_cast<good_U32>(37321));
        TEST_ASSERT_EQUALS(temp._reserved,              static_cast<good_U32>(60015));



        // |           11101010            |
        // |           01101111            |
        // |           01101110            |
        // |           00110110            |
        temp.numberOfThreadsPerCore = static_cast<good_U32>(28214);

        TEST_ASSERT_EQUALS(temp.value32, 0xEA6F6E36);



        // |           00010101            |
        // |           10010000            |
        // |           01101110            |
        // |           00110110            |
        temp._reserved = static_cast<good_U32>(5520);

        TEST_ASSERT_EQUALS(temp.value32, 0x15906E36);
    }
    TEST_CASE_END();



    TEST_CASE("Cpuid0000000BEbx1");
    {
        Cpuid0000000BEbx1 temp;



        // Cpuid0000000BEbx1:
        //
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // numberOfThreads : 16 'A'
        // _reserved       : 16 'B'



        // |           10101001            |
        // |           01101110            |
        // |           00100100            |
        // |           00111010            |
        temp.value32 = 0xA96E243A;

        TEST_ASSERT_EQUALS(temp.numberOfThreads, static_cast<good_U32>(9274));
        TEST_ASSERT_EQUALS(temp._reserved,       static_cast<good_U32>(43374));



        // |           10101001            |
        // |           01101110            |
        // |           11011011            |
        // |           11000101            |
        temp.numberOfThreads = static_cast<good_U32>(56261);

        TEST_ASSERT_EQUALS(temp.value32, 0xA96EDBC5);



        // |           01010110            |
        // |           10010001            |
        // |           11011011            |
        // |           11000101            |
        temp._reserved = static_cast<good_U32>(22161);

        TEST_ASSERT_EQUALS(temp.value32, 0x5691DBC5);
    }
    TEST_CASE_END();



    TEST_CASE("Cpuid80000008Eax");
    {
        Cpuid80000008Eax temp;



        // Cpuid80000008Eax:
        //
        // |           DDDDDDDD            |
        // |           CCCCCCCC            |
        // |           BBBBBBBB            |
        // |           AAAAAAAA            |
        //
        // physicalAddressBits      : 8  'A'
        // virtualAddressBits       : 8  'B'
        // guestPhysicalAddressBits : 8  'C'
        // _reserved                : 8  'D'



        // |           01101110            |
        // |           00000111            |
        // |           01110110            |
        // |           01111001            |
        temp.value32 = 0x6E077679;

        TEST_ASSERT_EQUALS(temp.physicalAddressBits,      static_cast<good_U32>(121));
        TEST_ASSERT_EQUALS(temp.virtualAddressBits,       static_cast<good_U32>(118));
        TEST_ASSERT_EQUALS(temp.guestPhysicalAddressBits, static_cast<good_U32>(7));
        TEST_ASSERT_EQUALS(temp._reserved,                static_cast<good_U32>(110));



        // |           01101110            |
        // |           00000111            |
        // |           01110110            |
        // |           10000110            |
        temp.physicalAddressBits = static_cast<good_U32>(134);

        TEST_ASSERT_EQUALS(temp.value32, 0x6E077686);



        // |           01101110            |
        // |           00000111            |
        // |           10001001            |
        // |           10000110            |
        temp.virtualAddressBits = static_cast<good_U32>(137);

        TEST_ASSERT_EQUALS(temp.value32, 0x6E078986);



        // |           01101110            |
        // |           11111000            |
        // |           10001001            |
        // |           10000110            |
        temp.guestPhysicalAddressBits = static_cast<good_U32>(248);

        TEST_ASSERT_EQUALS(temp.value32, 0x6EF88986);



        // |           10010001            |
        // |           11111000            |
        // |           10001001            |
        // |           10000110            |
        temp._reserved = static_cast<good_U32>(145);

        TEST_ASSERT_EQUALS(temp.value32, 0x91F88986);
    }
    TEST_CASE_END();



    TEST_CASE("Cpuid80000008Ecx");
    {
        Cpuid80000008Ecx temp;



        // Cpuid80000008Ecx:
        //
        // |           EEEEEEEE            |
        // |        EEEEEE         |  DD   |
        // |     CCCC      |     BBBB      |
        // |           AAAAAAAA            |
        //
        // physicalCores      : 8  'A'
        // _reserved          : 4  'B'
        // apicIdBits         : 4  'C'
        // performanceTscSize : 2  'D'
        // _reserved2         : 14 'E'



        // |           10011111            |
        // |        011110         |  10   |
        // |     1011      |     0000      |
        // |           10000101            |
        temp.value32 = 0x9F7AB085;

        TEST_ASSERT_EQUALS(temp.physicalCores,      static_cast<good_U32>(133));
        TEST_ASSERT_EQUALS(temp._reserved,          static_cast<good_U32>(0));
        TEST_ASSERT_EQUALS(temp.apicIdBits,         static_cast<good_U32>(11));
        TEST_ASSERT_EQUALS(temp.performanceTscSize, static_cast<CpuidPerformanceTscSize>(2));
        TEST_ASSERT_EQUALS(temp._reserved2,         static_cast<good_U32>(10206));



        // |           10011111            |
        // |        011110         |  10   |
        // |     1011      |     0000      |
        // |           01111010            |
        temp.physicalCores = static_cast<good_U32>(122);

        TEST_ASSERT_EQUALS(temp.value32, 0x9F7AB07A);



        // |           10011111            |
        // |        011110         |  10   |
        // |     1011      |     1111      |
        // |           01111010            |
        temp._reserved = static_cast<good_U32>(15);

        TEST_ASSERT_EQUALS(temp.value32, 0x9F7ABF7A);



        // |           10011111            |
        // |        011110         |  10   |
        // |     0100      |     1111      |
        // |           01111010            |
        temp.apicIdBits = static_cast<good_U32>(4);

        TEST_ASSERT_EQUALS(temp.value32, 0x9F7A4F7A);



        // |           10011111            |
        // |        011110         |  01   |
        // |     0100      |     1111      |
        // |           01111010            |
        temp.performanceTscSize = static_cast<CpuidPerformanceTscSize>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x9F794F7A);



        // |           01100000            |
        // |        100001         |  01   |
        // |     0100      |     1111      |
        // |           01111010            |
        temp._reserved2 = static_cast<good_U32>(6177);

        TEST_ASSERT_EQUALS(temp.value32, 0x60854F7A);
    }
    TEST_CASE_END();



    TEST_CASE("X86Cr8");
    {
        X86Cr8 temp;



        // X86Cr8:
        //
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |     BBBB      |     AAAA      |
        //
        // taskPriorityLevel : 4  'A'
        // _reserved         : 60 'B'



        // |           00010001            |
        // |           11110110            |
        // |           11110000            |
        // |           11011010            |
        // |           00111111            |
        // |           01000011            |
        // |           10110000            |
        // |     1000      |     0001      |
        temp.value64 = 0x11F6F0DA3F43B081;

        TEST_ASSERT_EQUALS(temp.taskPriorityLevel, static_cast<good_U64>(1));
        TEST_ASSERT_EQUALS(temp._reserved,         static_cast<good_U64>(80905422691908360));



        // |           00010001            |
        // |           11110110            |
        // |           11110000            |
        // |           11011010            |
        // |           00111111            |
        // |           01000011            |
        // |           10110000            |
        // |     1000      |     1110      |
        temp.taskPriorityLevel = static_cast<good_U64>(14);

        TEST_ASSERT_EQUALS(temp.value64, 0x11F6F0DA3F43B08E);



        // |           11101110            |
        // |           00001001            |
        // |           00001111            |
        // |           00100101            |
        // |           11000000            |
        // |           10111100            |
        // |           01001111            |
        // |     0111      |     1110      |
        temp._reserved = static_cast<good_U64>(1072016081914938615);

        TEST_ASSERT_EQUALS(temp.value64, 0xEE090F25C0BC4F7E);
    }
    TEST_CASE_END();



    TEST_CASE("DmiBiosExtendedRomSize");
    {
        DmiBiosExtendedRomSize temp;



        // DmiBiosExtendedRomSize:
        //
        // |  BB   |        AAAAAA         |
        // |           AAAAAAAA            |
        //
        // value : 14 'A'
        // unit  : 2  'B'



        // |  01   |        100101         |
        // |           01100111            |
        temp.value16 = 0x6567;

        TEST_ASSERT_EQUALS(temp.value, static_cast<u16>(9575));
        TEST_ASSERT_EQUALS(temp.unit,  static_cast<DmiBiosExtendedRomSizeUnit>(1));



        // |  01   |        011010         |
        // |           10011000            |
        temp.value = static_cast<u16>(6808);

        TEST_ASSERT_EQUALS(temp.value16, 0x5A98);



        // |  10   |        011010         |
        // |           10011000            |
        temp.unit = static_cast<DmiBiosExtendedRomSizeUnit>(2);

        TEST_ASSERT_EQUALS(temp.value16, 0x9A98);
    }
    TEST_CASE_END();



    TEST_CASE("DmiCacheConfiguration");
    {
        DmiCacheConfiguration temp;



        // DmiCacheConfiguration:
        //
        // |        GGGGGG         |  FF   |
        // | E |  DD   | C | B |    AAA    |
        //
        // level           : 3  'A'
        // socketed        : 1  'B'
        // __reserved      : 1  'C'
        // location        : 2  'D'
        // enabled         : 1  'E'
        // operationalMode : 2  'F'
        // __reserved2     : 6  'G'



        // |        101001         |  10   |
        // | 0 |  11   | 0 | 0 |    100    |
        temp.value16 = 0xA664;

        TEST_ASSERT_EQUALS(temp.level,           static_cast<u16>(4));
        TEST_ASSERT_EQUALS(temp.socketed,        static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,      static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.location,        static_cast<DmiCacheLocation>(3));
        TEST_ASSERT_EQUALS(temp.enabled,         static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.operationalMode, static_cast<DmiCacheOperationalMode>(2));
        TEST_ASSERT_EQUALS(temp.__reserved2,     static_cast<u16>(41));



        // |        101001         |  10   |
        // | 0 |  11   | 0 | 0 |    011    |
        temp.level = static_cast<u16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0xA663);



        // |        101001         |  10   |
        // | 0 |  11   | 0 | 1 |    011    |
        temp.socketed = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xA66B);



        // |        101001         |  10   |
        // | 0 |  11   | 1 | 1 |    011    |
        temp.__reserved = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xA67B);



        // |        101001         |  10   |
        // | 0 |  00   | 1 | 1 |    011    |
        temp.location = static_cast<DmiCacheLocation>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xA61B);



        // |        101001         |  10   |
        // | 1 |  00   | 1 | 1 |    011    |
        temp.enabled = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xA69B);



        // |        101001         |  01   |
        // | 1 |  00   | 1 | 1 |    011    |
        temp.operationalMode = static_cast<DmiCacheOperationalMode>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xA59B);



        // |        010110         |  01   |
        // | 1 |  00   | 1 | 1 |    011    |
        temp.__reserved2 = static_cast<u16>(22);

        TEST_ASSERT_EQUALS(temp.value16, 0x599B);
    }
    TEST_CASE_END();



    TEST_CASE("DmiCacheSize");
    {
        DmiCacheSize temp;



        // DmiCacheSize:
        //
        // | B |          AAAAAAA          |
        // |           AAAAAAAA            |
        //
        // value       : 15 'A'
        // granularity : 1  'B'



        // | 1 |          0100001          |
        // |           10001010            |
        temp.value16 = 0xA18A;

        TEST_ASSERT_EQUALS(temp.value,       static_cast<u16>(8586));
        TEST_ASSERT_EQUALS(temp.granularity, static_cast<DmiCacheSizeGranularity>(1));



        // | 1 |          1011110          |
        // |           01110101            |
        temp.value = static_cast<u16>(24181);

        TEST_ASSERT_EQUALS(temp.value16, 0xDE75);



        // | 0 |          1011110          |
        // |           01110101            |
        temp.granularity = static_cast<DmiCacheSizeGranularity>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x5E75);
    }
    TEST_CASE_END();



    TEST_CASE("DmiCacheSize2");
    {
        DmiCacheSize2 temp;



        // DmiCacheSize2:
        //
        // | B |          AAAAAAA          |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // value       : 31 'A'
        // granularity : 1  'B'



        // | 0 |          1110111          |
        // |           11100011            |
        // |           11101011            |
        // |           00101000            |
        temp.value32 = 0x77E3EB28;

        TEST_ASSERT_EQUALS(temp.value,       static_cast<u32>(2011425576));
        TEST_ASSERT_EQUALS(temp.granularity, static_cast<DmiCacheSizeGranularity>(0));



        // | 0 |          0001000          |
        // |           00011100            |
        // |           00010100            |
        // |           11010111            |
        temp.value = static_cast<u32>(136058071);

        TEST_ASSERT_EQUALS(temp.value32, 0x081C14D7);



        // | 1 |          0001000          |
        // |           00011100            |
        // |           00010100            |
        // |           11010111            |
        temp.granularity = static_cast<DmiCacheSizeGranularity>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x881C14D7);
    }
    TEST_CASE_END();



    TEST_CASE("DmiChassisTypeAndLockPresent");
    {
        DmiChassisTypeAndLockPresent temp;



        // DmiChassisTypeAndLockPresent:
        //
        // | B | AAAAAAA |
        //
        // type        : 7  'A'
        // lockPresent : 1  'B'



        // | 1 | 1000000 |
        temp.value8 = 0xC0;

        TEST_ASSERT_EQUALS(temp.type,        static_cast<DmiChassisType>(64));
        TEST_ASSERT_EQUALS(temp.lockPresent, static_cast<BitYesNoUnknown>(1));



        // | 1 | 0111111 |
        temp.type = static_cast<DmiChassisType>(63);

        TEST_ASSERT_EQUALS(temp.value8, 0xBF);



        // | 0 | 0111111 |
        temp.lockPresent = static_cast<BitYesNoUnknown>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x3F);
    }
    TEST_CASE_END();



    TEST_CASE("DmiCoolingDeviceTypeAndStatus");
    {
        DmiCoolingDeviceTypeAndStatus temp;



        // DmiCoolingDeviceTypeAndStatus:
        //
        // | BBB | AAAAA |
        //
        // deviceType : 5  'A'
        // status     : 3  'B'



        // | 110 | 01100 |
        temp.value8 = 0xCC;

        TEST_ASSERT_EQUALS(temp.deviceType, static_cast<DmiCoolingDeviceType>(12));
        TEST_ASSERT_EQUALS(temp.status,     static_cast<DmiCoolingDeviceStatus>(6));



        // | 110 | 10011 |
        temp.deviceType = static_cast<DmiCoolingDeviceType>(19);

        TEST_ASSERT_EQUALS(temp.value8, 0xD3);



        // | 001 | 10011 |
        temp.status = static_cast<DmiCoolingDeviceStatus>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0x33);
    }
    TEST_CASE_END();



    TEST_CASE("DmiElectricalCurrentProbeLocationAndStatus");
    {
        DmiElectricalCurrentProbeLocationAndStatus temp;



        // DmiElectricalCurrentProbeLocationAndStatus:
        //
        // | BBB | AAAAA |
        //
        // location : 5  'A'
        // status   : 3  'B'



        // | 101 | 01100 |
        temp.value8 = 0xAC;

        TEST_ASSERT_EQUALS(temp.location, static_cast<DmiElectricalCurrentProbeLocation>(12));
        TEST_ASSERT_EQUALS(temp.status,   static_cast<DmiElectricalCurrentProbeStatus>(5));



        // | 101 | 10011 |
        temp.location = static_cast<DmiElectricalCurrentProbeLocation>(19);

        TEST_ASSERT_EQUALS(temp.value8, 0xB3);



        // | 010 | 10011 |
        temp.status = static_cast<DmiElectricalCurrentProbeStatus>(2);

        TEST_ASSERT_EQUALS(temp.value8, 0x53);
    }
    TEST_CASE_END();



    TEST_CASE("DmiFunctionNumberAndDeviceNumber");
    {
        DmiFunctionNumberAndDeviceNumber temp;



        // DmiFunctionNumberAndDeviceNumber:
        //
        // | BBBBB | AAA |
        //
        // functionNumber : 3  'A'
        // deviceNumber   : 5  'B'



        // | 11011 | 000 |
        temp.value8 = 0xD8;

        TEST_ASSERT_EQUALS(temp.functionNumber, static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.deviceNumber,   static_cast<u8>(27));



        // | 11011 | 111 |
        temp.functionNumber = static_cast<u8>(7);

        TEST_ASSERT_EQUALS(temp.value8, 0xDF);



        // | 00100 | 111 |
        temp.deviceNumber = static_cast<u8>(4);

        TEST_ASSERT_EQUALS(temp.value8, 0x27);
    }
    TEST_CASE_END();



    TEST_CASE("DmiHardwareSecuritySettings");
    {
        DmiHardwareSecuritySettings temp;



        // DmiHardwareSecuritySettings:
        //
        // | DD | CC | BB | AA |
        //
        // frontPanelResetStatus       : 2  'A'
        // administratorPasswordStatus : 2  'B'
        // keyboardPasswordStatus      : 2  'C'
        // powerOnPasswordStatus       : 2  'D'



        // | 00 | 00 | 00 | 11 |
        temp.value8 = 0x03;

        TEST_ASSERT_EQUALS(temp.frontPanelResetStatus,       static_cast<DmiHardwareSecurityStatus>(3));
        TEST_ASSERT_EQUALS(temp.administratorPasswordStatus, static_cast<DmiHardwareSecurityStatus>(0));
        TEST_ASSERT_EQUALS(temp.keyboardPasswordStatus,      static_cast<DmiHardwareSecurityStatus>(0));
        TEST_ASSERT_EQUALS(temp.powerOnPasswordStatus,       static_cast<DmiHardwareSecurityStatus>(0));



        // | 00 | 00 | 00 | 00 |
        temp.frontPanelResetStatus = static_cast<DmiHardwareSecurityStatus>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x00);



        // | 00 | 00 | 11 | 00 |
        temp.administratorPasswordStatus = static_cast<DmiHardwareSecurityStatus>(3);

        TEST_ASSERT_EQUALS(temp.value8, 0x0C);



        // | 00 | 11 | 11 | 00 |
        temp.keyboardPasswordStatus = static_cast<DmiHardwareSecurityStatus>(3);

        TEST_ASSERT_EQUALS(temp.value8, 0x3C);



        // | 11 | 11 | 11 | 00 |
        temp.powerOnPasswordStatus = static_cast<DmiHardwareSecurityStatus>(3);

        TEST_ASSERT_EQUALS(temp.value8, 0xFC);
    }
    TEST_CASE_END();



    TEST_CASE("DmiMemoryDeviceAttributes");
    {
        DmiMemoryDeviceAttributes temp;



        // DmiMemoryDeviceAttributes:
        //
        // | BBBB | AAAA |
        //
        // rank       : 4  'A'
        // __reserved : 4  'B'



        // | 0111 | 1101 |
        temp.value8 = 0x7D;

        TEST_ASSERT_EQUALS(temp.rank,       static_cast<u8>(13));
        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u8>(7));



        // | 0111 | 0010 |
        temp.rank = static_cast<u8>(2);

        TEST_ASSERT_EQUALS(temp.value8, 0x72);



        // | 1000 | 0010 |
        temp.__reserved = static_cast<u8>(8);

        TEST_ASSERT_EQUALS(temp.value8, 0x82);
    }
    TEST_CASE_END();



    TEST_CASE("DmiMemoryDeviceExtendedSize");
    {
        DmiMemoryDeviceExtendedSize temp;



        // DmiMemoryDeviceExtendedSize:
        //
        // | B |          AAAAAAA          |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // value      : 31 'A'
        // __reserved : 1  'B'



        // | 0 |          0011010          |
        // |           11100110            |
        // |           10111101            |
        // |           00110001            |
        temp.value32 = 0x1AE6BD31;

        TEST_ASSERT_EQUALS(temp.value,      static_cast<u32>(451329329));
        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u32>(0));



        // | 0 |          1100101          |
        // |           00011001            |
        // |           01000010            |
        // |           11001110            |
        temp.value = static_cast<u32>(1696154318);

        TEST_ASSERT_EQUALS(temp.value32, 0x651942CE);



        // | 1 |          1100101          |
        // |           00011001            |
        // |           01000010            |
        // |           11001110            |
        temp.__reserved = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xE51942CE);
    }
    TEST_CASE_END();



    TEST_CASE("DmiMemoryDeviceSize");
    {
        DmiMemoryDeviceSize temp;



        // DmiMemoryDeviceSize:
        //
        // | B |          AAAAAAA          |
        // |           AAAAAAAA            |
        //
        // value       : 15 'A'
        // granularity : 1  'B'



        // | 1 |          1110000          |
        // |           00101101            |
        temp.value16 = 0xF02D;

        TEST_ASSERT_EQUALS(temp.value,       static_cast<u16>(28717));
        TEST_ASSERT_EQUALS(temp.granularity, static_cast<DmiMemoryDeviceSizeGranularity>(1));



        // | 1 |          0001111          |
        // |           11010010            |
        temp.value = static_cast<u16>(4050);

        TEST_ASSERT_EQUALS(temp.value16, 0x8FD2);



        // | 0 |          0001111          |
        // |           11010010            |
        temp.granularity = static_cast<DmiMemoryDeviceSizeGranularity>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x0FD2);
    }
    TEST_CASE_END();



    TEST_CASE("DmiOnboardDevicesDeviceTypeAndEnabled");
    {
        DmiOnboardDevicesDeviceTypeAndEnabled temp;



        // DmiOnboardDevicesDeviceTypeAndEnabled:
        //
        // | B | AAAAAAA |
        //
        // deviceType : 7  'A'
        // enabled    : 1  'B'



        // | 1 | 0001000 |
        temp.value8 = 0x88;

        TEST_ASSERT_EQUALS(temp.deviceType, static_cast<DmiOnboardDevicesDeviceType>(8));
        TEST_ASSERT_EQUALS(temp.enabled,    static_cast<u8>(1));



        // | 1 | 1110111 |
        temp.deviceType = static_cast<DmiOnboardDevicesDeviceType>(119);

        TEST_ASSERT_EQUALS(temp.value8, 0xF7);



        // | 0 | 1110111 |
        temp.enabled = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x77);
    }
    TEST_CASE_END();



    TEST_CASE("DmiOnboardDevicesExtendedDeviceTypeAndEnabled");
    {
        DmiOnboardDevicesExtendedDeviceTypeAndEnabled temp;



        // DmiOnboardDevicesExtendedDeviceTypeAndEnabled:
        //
        // | B | AAAAAAA |
        //
        // deviceType : 7  'A'
        // enabled    : 1  'B'



        // | 0 | 0111111 |
        temp.value8 = 0x3F;

        TEST_ASSERT_EQUALS(temp.deviceType, static_cast<DmiOnboardDevicesExtendedDeviceType>(63));
        TEST_ASSERT_EQUALS(temp.enabled,    static_cast<u8>(0));



        // | 0 | 1000000 |
        temp.deviceType = static_cast<DmiOnboardDevicesExtendedDeviceType>(64);

        TEST_ASSERT_EQUALS(temp.value8, 0x40);



        // | 1 | 1000000 |
        temp.enabled = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0xC0);
    }
    TEST_CASE_END();



    TEST_CASE("DmiPortableBatteryManufactureDate");
    {
        DmiPortableBatteryManufactureDate temp;



        // DmiPortableBatteryManufactureDate:
        //
        // |          CCCCCCC          | B |
        // |    BBB    |       AAAAA       |
        //
        // date  : 5  'A'
        // month : 4  'B'
        // year  : 7  'C'



        // |          0100001          | 0 |
        // |    001    |       00011       |
        temp.value16 = 0x4223;

        TEST_ASSERT_EQUALS(temp.date,  static_cast<u16>(3));
        TEST_ASSERT_EQUALS(temp.month, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.year,  static_cast<u16>(33));



        // |          0100001          | 0 |
        // |    001    |       11100       |
        temp.date = static_cast<u16>(28);

        TEST_ASSERT_EQUALS(temp.value16, 0x423C);



        // |          0100001          | 1 |
        // |    110    |       11100       |
        temp.month = static_cast<u16>(14);

        TEST_ASSERT_EQUALS(temp.value16, 0x43DC);



        // |          1011110          | 1 |
        // |    110    |       11100       |
        temp.year = static_cast<u16>(94);

        TEST_ASSERT_EQUALS(temp.value16, 0xBDDC);
    }
    TEST_CASE_END();



    TEST_CASE("DmiProcessorStatusAndSocketPopulated");
    {
        DmiProcessorStatusAndSocketPopulated temp;



        // DmiProcessorStatusAndSocketPopulated:
        //
        // | D | C | BBB | AAA |
        //
        // status          : 3  'A'
        // __reserved      : 3  'B'
        // socketPopulated : 1  'C'
        // __reserved2     : 1  'D'



        // | 1 | 0 | 101 | 010 |
        temp.value8 = 0xAA;

        TEST_ASSERT_EQUALS(temp.status,          static_cast<DmiProcessorStatus>(2));
        TEST_ASSERT_EQUALS(temp.__reserved,      static_cast<u8>(5));
        TEST_ASSERT_EQUALS(temp.socketPopulated, static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.__reserved2,     static_cast<u8>(1));



        // | 1 | 0 | 101 | 101 |
        temp.status = static_cast<DmiProcessorStatus>(5);

        TEST_ASSERT_EQUALS(temp.value8, 0xAD);



        // | 1 | 0 | 010 | 101 |
        temp.__reserved = static_cast<u8>(2);

        TEST_ASSERT_EQUALS(temp.value8, 0x95);



        // | 1 | 1 | 010 | 101 |
        temp.socketPopulated = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0xD5);



        // | 0 | 1 | 010 | 101 |
        temp.__reserved2 = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x55);
    }
    TEST_CASE_END();



    TEST_CASE("DmiSystemPowerSupplyCharacteristics");
    {
        DmiSystemPowerSupplyCharacteristics temp;



        // DmiSystemPowerSupplyCharacteristics:
        //
        // |  GG   |     FFFF      |  EE   |
        // | E |     DDDD      | C | B | A |
        //
        // hotReplaceable          : 1  'A'
        // present                 : 1  'B'
        // unplugged               : 1  'C'
        // inputVoltageRangeSwitch : 4  'D'
        // status                  : 3  'E'
        // type                    : 4  'F'
        // __reserved              : 2  'G'



        // |  01   |     0101      |  10   |
        // | 0 |     0000      | 1 | 0 | 0 |
        temp.value16 = 0x5604;

        TEST_ASSERT_EQUALS(temp.hotReplaceable,          static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.present,                 static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.unplugged,               static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.inputVoltageRangeSwitch, static_cast<DmiSystemPowerSupplyInputVoltageRangeSwitch>(0));
        TEST_ASSERT_EQUALS(temp.status,                  static_cast<DmiSystemPowerSupplyStatus>(4));
        TEST_ASSERT_EQUALS(temp.type,                    static_cast<DmiSystemPowerSupplyType>(5));
        TEST_ASSERT_EQUALS(temp.__reserved,              static_cast<u16>(1));



        // |  01   |     0101      |  10   |
        // | 0 |     0000      | 1 | 0 | 1 |
        temp.hotReplaceable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x5605);



        // |  01   |     0101      |  10   |
        // | 0 |     0000      | 1 | 1 | 1 |
        temp.present = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x5607);



        // |  01   |     0101      |  10   |
        // | 0 |     0000      | 0 | 1 | 1 |
        temp.unplugged = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x5603);



        // |  01   |     0101      |  10   |
        // | 0 |     1111      | 0 | 1 | 1 |
        temp.inputVoltageRangeSwitch = static_cast<DmiSystemPowerSupplyInputVoltageRangeSwitch>(15);

        TEST_ASSERT_EQUALS(temp.value16, 0x567B);



        // |  01   |     0101      |  01   |
        // | 1 |     1111      | 0 | 1 | 1 |
        temp.status = static_cast<DmiSystemPowerSupplyStatus>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x55FB);



        // |  01   |     1010      |  01   |
        // | 1 |     1111      | 0 | 1 | 1 |
        temp.type = static_cast<DmiSystemPowerSupplyType>(10);

        TEST_ASSERT_EQUALS(temp.value16, 0x69FB);



        // |  10   |     1010      |  01   |
        // | 1 |     1111      | 0 | 1 | 1 |
        temp.__reserved = static_cast<u16>(2);

        TEST_ASSERT_EQUALS(temp.value16, 0xA9FB);
    }
    TEST_CASE_END();



    TEST_CASE("DmiSystemResetCapabilities");
    {
        DmiSystemResetCapabilities temp;



        // DmiSystemResetCapabilities:
        //
        // | EE | D | CC | BB | A |
        //
        // enabled           : 1  'A'
        // bootOption        : 2  'B'
        // bootOptionOnLimit : 2  'C'
        // watchdogEnabled   : 1  'D'
        // __reserved        : 2  'E'



        // | 10 | 0 | 11 | 11 | 1 |
        temp.value8 = 0x9F;

        TEST_ASSERT_EQUALS(temp.enabled,           static_cast<u8>(1));
        TEST_ASSERT_EQUALS(temp.bootOption,        static_cast<DmiSystemResetBootOption>(3));
        TEST_ASSERT_EQUALS(temp.bootOptionOnLimit, static_cast<DmiSystemResetBootOption>(3));
        TEST_ASSERT_EQUALS(temp.watchdogEnabled,   static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,        static_cast<u8>(2));



        // | 10 | 0 | 11 | 11 | 0 |
        temp.enabled = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x9E);



        // | 10 | 0 | 11 | 00 | 0 |
        temp.bootOption = static_cast<DmiSystemResetBootOption>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x98);



        // | 10 | 0 | 00 | 00 | 0 |
        temp.bootOptionOnLimit = static_cast<DmiSystemResetBootOption>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x80);



        // | 10 | 1 | 00 | 00 | 0 |
        temp.watchdogEnabled = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0xA0);



        // | 01 | 1 | 00 | 00 | 0 |
        temp.__reserved = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0x60);
    }
    TEST_CASE_END();



    TEST_CASE("DmiTemperatureProbeLocationAndStatus");
    {
        DmiTemperatureProbeLocationAndStatus temp;



        // DmiTemperatureProbeLocationAndStatus:
        //
        // | BBB | AAAAA |
        //
        // location : 5  'A'
        // status   : 3  'B'



        // | 001 | 00100 |
        temp.value8 = 0x24;

        TEST_ASSERT_EQUALS(temp.location, static_cast<DmiTemperatureProbeLocation>(4));
        TEST_ASSERT_EQUALS(temp.status,   static_cast<DmiTemperatureProbeStatus>(1));



        // | 001 | 11011 |
        temp.location = static_cast<DmiTemperatureProbeLocation>(27);

        TEST_ASSERT_EQUALS(temp.value8, 0x3B);



        // | 110 | 11011 |
        temp.status = static_cast<DmiTemperatureProbeStatus>(6);

        TEST_ASSERT_EQUALS(temp.value8, 0xDB);
    }
    TEST_CASE_END();



    TEST_CASE("DmiVoltageProbeLocationAndStatus");
    {
        DmiVoltageProbeLocationAndStatus temp;



        // DmiVoltageProbeLocationAndStatus:
        //
        // | BBB | AAAAA |
        //
        // location : 5  'A'
        // status   : 3  'B'



        // | 000 | 10000 |
        temp.value8 = 0x10;

        TEST_ASSERT_EQUALS(temp.location, static_cast<DmiVoltageProbeLocation>(16));
        TEST_ASSERT_EQUALS(temp.status,   static_cast<DmiVoltageProbeStatus>(0));



        // | 000 | 01111 |
        temp.location = static_cast<DmiVoltageProbeLocation>(15);

        TEST_ASSERT_EQUALS(temp.value8, 0x0F);



        // | 111 | 01111 |
        temp.status = static_cast<DmiVoltageProbeStatus>(7);

        TEST_ASSERT_EQUALS(temp.value8, 0xEF);
    }
    TEST_CASE_END();



    TEST_CASE("ElfSymbolInfo");
    {
        ElfSymbolInfo temp;



        // ElfSymbolInfo:
        //
        // | BBBB | AAAA |
        //
        // bind : 4  'A'
        // type : 4  'B'



        // | 1100 | 0110 |
        temp.value8 = 0xC6;

        TEST_ASSERT_EQUALS(temp.bind, static_cast<u8>(6));
        TEST_ASSERT_EQUALS(temp.type, static_cast<u8>(12));



        // | 1100 | 1001 |
        temp.bind = static_cast<u8>(9);

        TEST_ASSERT_EQUALS(temp.value8, 0xC9);



        // | 0011 | 1001 |
        temp.type = static_cast<u8>(3);

        TEST_ASSERT_EQUALS(temp.value8, 0x39);
    }
    TEST_CASE_END();



    TEST_CASE("ElfSymbolOther");
    {
        ElfSymbolOther temp;



        // ElfSymbolOther:
        //
        // | BBB | AAAAA |
        //
        // __reserved : 5  'A'
        // visibility : 3  'B'



        // | 111 | 00100 |
        temp.value8 = 0xE4;

        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u8>(4));
        TEST_ASSERT_EQUALS(temp.visibility, static_cast<u8>(7));



        // | 111 | 11011 |
        temp.__reserved = static_cast<u8>(27);

        TEST_ASSERT_EQUALS(temp.value8, 0xFB);



        // | 000 | 11011 |
        temp.visibility = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x1B);
    }
    TEST_CASE_END();



    TEST_CASE("FpuCwr");
    {
        FpuCwr temp;



        // FpuCwr:
        //
        // |    KKK    | J |  II   |  HH   |
        // |  GG   | F | E | D | C | B | A |
        //
        // invalidOperationErrorMask    : 1  'A'
        // denormalizedOperandErrorMask : 1  'B'
        // divideByZeroErrorMask        : 1  'C'
        // overflowErrorMask            : 1  'D'
        // underflowErrorMask           : 1  'E'
        // precisionErrorMask           : 1  'F'
        // _reserved                    : 2  'G'
        // precisionControl             : 2  'H'
        // roundingControl              : 2  'I'
        // infinityControl              : 1  'J'
        // _reserved2                   : 3  'K'



        // |    001    | 0 |  11   |  11   |
        // |  10   | 1 | 1 | 1 | 0 | 0 | 0 |
        temp.value16 = 0x2FB8;

        TEST_ASSERT_EQUALS(temp.invalidOperationErrorMask,    static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.denormalizedOperandErrorMask, static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.divideByZeroErrorMask,        static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.overflowErrorMask,            static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp.underflowErrorMask,           static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp.precisionErrorMask,           static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp._reserved,                    static_cast<good_U16>(2));
        TEST_ASSERT_EQUALS(temp.precisionControl,             static_cast<good_U16>(3));
        TEST_ASSERT_EQUALS(temp.roundingControl,              static_cast<good_U16>(3));
        TEST_ASSERT_EQUALS(temp.infinityControl,              static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp._reserved2,                   static_cast<good_U16>(1));



        // |    001    | 0 |  11   |  11   |
        // |  10   | 1 | 1 | 1 | 0 | 0 | 1 |
        temp.invalidOperationErrorMask = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2FB9);



        // |    001    | 0 |  11   |  11   |
        // |  10   | 1 | 1 | 1 | 0 | 1 | 1 |
        temp.denormalizedOperandErrorMask = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2FBB);



        // |    001    | 0 |  11   |  11   |
        // |  10   | 1 | 1 | 1 | 1 | 1 | 1 |
        temp.divideByZeroErrorMask = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2FBF);



        // |    001    | 0 |  11   |  11   |
        // |  10   | 1 | 1 | 0 | 1 | 1 | 1 |
        temp.overflowErrorMask = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2FB7);



        // |    001    | 0 |  11   |  11   |
        // |  10   | 1 | 0 | 0 | 1 | 1 | 1 |
        temp.underflowErrorMask = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2FA7);



        // |    001    | 0 |  11   |  11   |
        // |  10   | 0 | 0 | 0 | 1 | 1 | 1 |
        temp.precisionErrorMask = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2F87);



        // |    001    | 0 |  11   |  11   |
        // |  01   | 0 | 0 | 0 | 1 | 1 | 1 |
        temp._reserved = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2F47);



        // |    001    | 0 |  11   |  00   |
        // |  01   | 0 | 0 | 0 | 1 | 1 | 1 |
        temp.precisionControl = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2C47);



        // |    001    | 0 |  00   |  00   |
        // |  01   | 0 | 0 | 0 | 1 | 1 | 1 |
        temp.roundingControl = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2047);



        // |    001    | 1 |  00   |  00   |
        // |  01   | 0 | 0 | 0 | 1 | 1 | 1 |
        temp.infinityControl = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3047);



        // |    110    | 1 |  00   |  00   |
        // |  01   | 0 | 0 | 0 | 1 | 1 | 1 |
        temp._reserved2 = static_cast<good_U16>(6);

        TEST_ASSERT_EQUALS(temp.value16, 0xD047);
    }
    TEST_CASE_END();



    TEST_CASE("FpuSwr");
    {
        FpuSwr temp;



        // FpuSwr:
        //
        // | N | M |    LLL    | K | J | I |
        // | H | G | F | E | D | C | B | A |
        //
        // invalidOperationError    : 1  'A'
        // denormalizedOperandError : 1  'B'
        // divideByZeroError        : 1  'C'
        // overflowError            : 1  'D'
        // underflowError           : 1  'E'
        // precisionError           : 1  'F'
        // stackFault               : 1  'G'
        // errorSummaryStatus       : 1  'H'
        // c0                       : 1  'I'
        // c1                       : 1  'J'
        // c2                       : 1  'K'
        // top                      : 3  'L'
        // c3                       : 1  'M'
        // busy                     : 1  'N'



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 0 | 1 | 0 | 1 | 1 | 1 | 0 | 1 |
        temp.value16 = 0x605D;

        TEST_ASSERT_EQUALS(temp.invalidOperationError,    static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp.denormalizedOperandError, static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.divideByZeroError,        static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp.overflowError,            static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp.underflowError,           static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp.precisionError,           static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.stackFault,               static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp.errorSummaryStatus,       static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.c0,                       static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.c1,                       static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.c2,                       static_cast<good_U16>(0));
        TEST_ASSERT_EQUALS(temp.top,                      static_cast<good_U16>(4));
        TEST_ASSERT_EQUALS(temp.c3,                       static_cast<good_U16>(1));
        TEST_ASSERT_EQUALS(temp.busy,                     static_cast<good_U16>(0));



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 0 | 1 | 0 | 1 | 1 | 1 | 0 | 0 |
        temp.invalidOperationError = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x605C);



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 0 | 1 | 0 | 1 | 1 | 1 | 1 | 0 |
        temp.denormalizedOperandError = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x605E);



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 0 | 1 | 0 | 1 | 1 | 0 | 1 | 0 |
        temp.divideByZeroError = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x605A);



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 0 |
        temp.overflowError = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x6052);



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 0 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
        temp.underflowError = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x6042);



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 0 | 1 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.precisionError = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x6062);



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.stackFault = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x6022);



        // | 0 | 1 |    100    | 0 | 0 | 0 |
        // | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.errorSummaryStatus = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x60A2);



        // | 0 | 1 |    100    | 0 | 0 | 1 |
        // | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.c0 = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x61A2);



        // | 0 | 1 |    100    | 0 | 1 | 1 |
        // | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.c1 = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x63A2);



        // | 0 | 1 |    100    | 1 | 1 | 1 |
        // | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.c2 = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x67A2);



        // | 0 | 1 |    011    | 1 | 1 | 1 |
        // | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.top = static_cast<good_U16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x5FA2);



        // | 0 | 0 |    011    | 1 | 1 | 1 |
        // | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.c3 = static_cast<good_U16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x1FA2);



        // | 1 | 0 |    011    | 1 | 1 | 1 |
        // | 1 | 0 | 1 | 0 | 0 | 0 | 1 | 0 |
        temp.busy = static_cast<good_U16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x9FA2);
    }
    TEST_CASE_END();



    TEST_CASE("GdtDescriptor");
    {
        GdtDescriptor temp;



        // GdtDescriptor:
        //
        // |           MMMMMMMM            |
        // | L | K | J | I |     HHHH      |
        // | G |  FF   | E |     DDDD      |
        // |           CCCCCCCC            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // limit0 : 16 'A'
        // base0  : 16 'B'
        // base1  : 8  'C'
        // type   : 4  'D'
        // s      : 1  'E'
        // dpl    : 2  'F'
        // p      : 1  'G'
        // limit1 : 4  'H'
        // avl    : 1  'I'
        // l      : 1  'J'
        // d      : 1  'K'
        // g      : 1  'L'
        // base2  : 8  'M'



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     1010      |
        // | 1 |  10   | 1 |     1001      |
        // |           10011010            |
        // |           00000101            |
        // |           10000100            |
        // |           01011010            |
        // |           11001010            |
        temp.value64 = 0x620AD99A05845ACA;

        TEST_ASSERT_EQUALS(temp.limit0, static_cast<u64>(23242));
        TEST_ASSERT_EQUALS(temp.base0,  static_cast<u64>(1412));
        TEST_ASSERT_EQUALS(temp.base1,  static_cast<u64>(154));
        TEST_ASSERT_EQUALS(temp.type,   static_cast<u64>(9));
        TEST_ASSERT_EQUALS(temp.s,      static_cast<u64>(1));
        TEST_ASSERT_EQUALS(temp.dpl,    static_cast<u64>(2));
        TEST_ASSERT_EQUALS(temp.p,      static_cast<u64>(1));
        TEST_ASSERT_EQUALS(temp.limit1, static_cast<u64>(10));
        TEST_ASSERT_EQUALS(temp.avl,    static_cast<u64>(0));
        TEST_ASSERT_EQUALS(temp.l,      static_cast<u64>(0));
        TEST_ASSERT_EQUALS(temp.d,      static_cast<u64>(0));
        TEST_ASSERT_EQUALS(temp.g,      static_cast<u64>(0));
        TEST_ASSERT_EQUALS(temp.base2,  static_cast<u64>(98));



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     1010      |
        // | 1 |  10   | 1 |     1001      |
        // |           10011010            |
        // |           00000101            |
        // |           10000100            |
        // |           10100101            |
        // |           00110101            |
        temp.limit0 = static_cast<u64>(42293);

        TEST_ASSERT_EQUALS(temp.value64, 0x620AD99A0584A535);



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     1010      |
        // | 1 |  10   | 1 |     1001      |
        // |           10011010            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.base0 = static_cast<u64>(64123);

        TEST_ASSERT_EQUALS(temp.value64, 0x620AD99AFA7BA535);



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     1010      |
        // | 1 |  10   | 1 |     1001      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.base1 = static_cast<u64>(101);

        TEST_ASSERT_EQUALS(temp.value64, 0x620AD965FA7BA535);



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     1010      |
        // | 1 |  10   | 1 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.type = static_cast<u64>(6);

        TEST_ASSERT_EQUALS(temp.value64, 0x620AD665FA7BA535);



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     1010      |
        // | 1 |  10   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.s = static_cast<u64>(0);

        TEST_ASSERT_EQUALS(temp.value64, 0x620AC665FA7BA535);



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     1010      |
        // | 1 |  01   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.dpl = static_cast<u64>(1);

        TEST_ASSERT_EQUALS(temp.value64, 0x620AA665FA7BA535);



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     1010      |
        // | 0 |  01   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.p = static_cast<u64>(0);

        TEST_ASSERT_EQUALS(temp.value64, 0x620A2665FA7BA535);



        // |           01100010            |
        // | 0 | 0 | 0 | 0 |     0101      |
        // | 0 |  01   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.limit1 = static_cast<u64>(5);

        TEST_ASSERT_EQUALS(temp.value64, 0x62052665FA7BA535);



        // |           01100010            |
        // | 0 | 0 | 0 | 1 |     0101      |
        // | 0 |  01   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.avl = static_cast<u64>(1);

        TEST_ASSERT_EQUALS(temp.value64, 0x62152665FA7BA535);



        // |           01100010            |
        // | 0 | 0 | 1 | 1 |     0101      |
        // | 0 |  01   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.l = static_cast<u64>(1);

        TEST_ASSERT_EQUALS(temp.value64, 0x62352665FA7BA535);



        // |           01100010            |
        // | 0 | 1 | 1 | 1 |     0101      |
        // | 0 |  01   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.d = static_cast<u64>(1);

        TEST_ASSERT_EQUALS(temp.value64, 0x62752665FA7BA535);



        // |           01100010            |
        // | 1 | 1 | 1 | 1 |     0101      |
        // | 0 |  01   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.g = static_cast<u64>(1);

        TEST_ASSERT_EQUALS(temp.value64, 0x62F52665FA7BA535);



        // |           10011101            |
        // | 1 | 1 | 1 | 1 |     0101      |
        // | 0 |  01   | 0 |     0110      |
        // |           01100101            |
        // |           11111010            |
        // |           01111011            |
        // |           10100101            |
        // |           00110101            |
        temp.base2 = static_cast<u64>(157);

        TEST_ASSERT_EQUALS(temp.value64, 0x9DF52665FA7BA535);
    }
    TEST_CASE_END();



    TEST_CASE("JpegHuffmanTableIdAndType");
    {
        JpegHuffmanTableIdAndType temp;



        // JpegHuffmanTableIdAndType:
        //
        // | CCC | B | AAAA |
        //
        // id         : 4  'A'
        // type       : 1  'B'
        // __reserved : 3  'C'



        // | 111 | 0 | 1000 |
        temp.value8 = 0xE8;

        TEST_ASSERT_EQUALS(temp.id,         static_cast<u8>(8));
        TEST_ASSERT_EQUALS(temp.type,       static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u8>(7));



        // | 111 | 0 | 0111 |
        temp.id = static_cast<u8>(7);

        TEST_ASSERT_EQUALS(temp.value8, 0xE7);



        // | 111 | 1 | 0111 |
        temp.type = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0xF7);



        // | 000 | 1 | 0111 |
        temp.__reserved = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x17);
    }
    TEST_CASE_END();



    TEST_CASE("JpegQuantizationTableIdAndPrecision");
    {
        JpegQuantizationTableIdAndPrecision temp;



        // JpegQuantizationTableIdAndPrecision:
        //
        // | BBBB | AAAA |
        //
        // id        : 4  'A'
        // precision : 4  'B'



        // | 1011 | 0111 |
        temp.value8 = 0xB7;

        TEST_ASSERT_EQUALS(temp.id,        static_cast<u8>(7));
        TEST_ASSERT_EQUALS(temp.precision, static_cast<u8>(11));



        // | 1011 | 1000 |
        temp.id = static_cast<u8>(8);

        TEST_ASSERT_EQUALS(temp.value8, 0xB8);



        // | 0100 | 1000 |
        temp.precision = static_cast<u8>(4);

        TEST_ASSERT_EQUALS(temp.value8, 0x48);
    }
    TEST_CASE_END();



    TEST_CASE("JpegStartOfFrameComponentSamplingFactor");
    {
        JpegStartOfFrameComponentSamplingFactor temp;



        // JpegStartOfFrameComponentSamplingFactor:
        //
        // | BBBB | AAAA |
        //
        // y : 4  'A'
        // x : 4  'B'



        // | 0100 | 0000 |
        temp.value8 = 0x40;

        TEST_ASSERT_EQUALS(temp.y, static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.x, static_cast<u8>(4));



        // | 0100 | 1111 |
        temp.y = static_cast<u8>(15);

        TEST_ASSERT_EQUALS(temp.value8, 0x4F);



        // | 1011 | 1111 |
        temp.x = static_cast<u8>(11);

        TEST_ASSERT_EQUALS(temp.value8, 0xBF);
    }
    TEST_CASE_END();



    TEST_CASE("JpegStartOfScanComponentHuffmanTableIds");
    {
        JpegStartOfScanComponentHuffmanTableIds temp;



        // JpegStartOfScanComponentHuffmanTableIds:
        //
        // | BBBB | AAAA |
        //
        // ac : 4  'A'
        // dc : 4  'B'



        // | 0010 | 1110 |
        temp.value8 = 0x2E;

        TEST_ASSERT_EQUALS(temp.ac, static_cast<u8>(14));
        TEST_ASSERT_EQUALS(temp.dc, static_cast<u8>(2));



        // | 0010 | 0001 |
        temp.ac = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0x21);



        // | 1101 | 0001 |
        temp.dc = static_cast<u8>(13);

        TEST_ASSERT_EQUALS(temp.value8, 0xD1);
    }
    TEST_CASE_END();



    TEST_CASE("IdtDescriptorType");
    {
        IdtDescriptorType temp;



        // IdtDescriptorType:
        //
        // | D | CC | B | AAAA |
        //
        // gateType   : 4  'A'
        // __reserved : 1  'B'
        // dpl        : 2  'C'
        // p          : 1  'D'



        // | 1 | 00 | 0 | 1101 |
        temp.value8 = 0x8D;

        TEST_ASSERT_EQUALS(temp.gateType,   static_cast<u8>(13));
        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.dpl,        static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.p,          static_cast<u8>(1));



        // | 1 | 00 | 0 | 0010 |
        temp.gateType = static_cast<u8>(2);

        TEST_ASSERT_EQUALS(temp.value8, 0x82);



        // | 1 | 00 | 1 | 0010 |
        temp.__reserved = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0x92);



        // | 1 | 11 | 1 | 0010 |
        temp.dpl = static_cast<u8>(3);

        TEST_ASSERT_EQUALS(temp.value8, 0xF2);



        // | 0 | 11 | 1 | 0010 |
        temp.p = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x72);
    }
    TEST_CASE_END();



    TEST_CASE("MsrIa32BiosSignId");
    {
        MsrIa32BiosSignId temp;



        // MsrIa32BiosSignId:
        //
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // _reserved         : 32 'A'
        // microcodeRevision : 32 'B'



        // |           00001011            |
        // |           00000101            |
        // |           11000101            |
        // |           00010101            |
        // |           00011100            |
        // |           11000111            |
        // |           00111010            |
        // |           00001111            |
        temp.value64 = 0x0B05C5151CC73A0F;

        TEST_ASSERT_EQUALS(temp._reserved,         static_cast<good_U64>(482818575));
        TEST_ASSERT_EQUALS(temp.microcodeRevision, static_cast<good_U64>(184927509));



        // |           00001011            |
        // |           00000101            |
        // |           11000101            |
        // |           00010101            |
        // |           11100011            |
        // |           00111000            |
        // |           11000101            |
        // |           11110000            |
        temp._reserved = static_cast<good_U64>(3812148720);

        TEST_ASSERT_EQUALS(temp.value64, 0x0B05C515E338C5F0);



        // |           11110100            |
        // |           11111010            |
        // |           00111010            |
        // |           11101010            |
        // |           11100011            |
        // |           00111000            |
        // |           11000101            |
        // |           11110000            |
        temp.microcodeRevision = static_cast<good_U64>(4110039786);

        TEST_ASSERT_EQUALS(temp.value64, 0xF4FA3AEAE338C5F0);
    }
    TEST_CASE_END();



    TEST_CASE("PciAcceleratedGraphicsPortCommand");
    {
        PciAcceleratedGraphicsPortCommand temp;



        // PciAcceleratedGraphicsPortCommand:
        //
        // |           FFFFFFFF            |
        // |           EEEEEEEE            |
        // |        EEEEEE         | D | C |
        // |       BBBBB       |    AAA    |
        //
        // rate                           : 3  'A'
        // __reserved                     : 5  'B'
        // enableAcceleratedGraphicsPort  : 1  'C'
        // enableSideBandAddressing       : 1  'D'
        // __reserved2                    : 14 'E'
        // maximumNumberOfCommandRequests : 8  'F'



        // |           01010110            |
        // |           11010100            |
        // |        100110         | 1 | 0 |
        // |       01101       |    110    |
        temp.value32 = 0x56D49A6E;

        TEST_ASSERT_EQUALS(temp.rate,                           static_cast<u32>(6));
        TEST_ASSERT_EQUALS(temp.__reserved,                     static_cast<u32>(13));
        TEST_ASSERT_EQUALS(temp.enableAcceleratedGraphicsPort,  static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.enableSideBandAddressing,       static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved2,                    static_cast<u32>(13606));
        TEST_ASSERT_EQUALS(temp.maximumNumberOfCommandRequests, static_cast<u32>(86));



        // |           01010110            |
        // |           11010100            |
        // |        100110         | 1 | 0 |
        // |       01101       |    001    |
        temp.rate = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x56D49A69);



        // |           01010110            |
        // |           11010100            |
        // |        100110         | 1 | 0 |
        // |       10010       |    001    |
        temp.__reserved = static_cast<u32>(18);

        TEST_ASSERT_EQUALS(temp.value32, 0x56D49A91);



        // |           01010110            |
        // |           11010100            |
        // |        100110         | 1 | 1 |
        // |       10010       |    001    |
        temp.enableAcceleratedGraphicsPort = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x56D49B91);



        // |           01010110            |
        // |           11010100            |
        // |        100110         | 0 | 1 |
        // |       10010       |    001    |
        temp.enableSideBandAddressing = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x56D49991);



        // |           01010110            |
        // |           00101011            |
        // |        011001         | 0 | 1 |
        // |       10010       |    001    |
        temp.__reserved2 = static_cast<u32>(2777);

        TEST_ASSERT_EQUALS(temp.value32, 0x562B6591);



        // |           10101001            |
        // |           00101011            |
        // |        011001         | 0 | 1 |
        // |       10010       |    001    |
        temp.maximumNumberOfCommandRequests = static_cast<u32>(169);

        TEST_ASSERT_EQUALS(temp.value32, 0xA92B6591);
    }
    TEST_CASE_END();



    TEST_CASE("PciAcceleratedGraphicsPortStatus");
    {
        PciAcceleratedGraphicsPortStatus temp;



        // PciAcceleratedGraphicsPortStatus:
        //
        // |           EEEEEEEE            |
        // |           DDDDDDDD            |
        // |        DDDDDD         | C | B |
        // |        BBBBBB         |  AA   |
        //
        // rate                           : 2  'A'
        // __reserved                     : 7  'B'
        // supportSideBandAddressing      : 1  'C'
        // __reserved2                    : 14 'D'
        // maximumNumberOfCommandRequests : 8  'E'



        // |           00110000            |
        // |           11011110            |
        // |        010100         | 1 | 1 |
        // |        001000         |  11   |
        temp.value32 = 0x30DE5323;

        TEST_ASSERT_EQUALS(temp.rate,                           static_cast<u32>(3));
        TEST_ASSERT_EQUALS(temp.__reserved,                     static_cast<u32>(72));
        TEST_ASSERT_EQUALS(temp.supportSideBandAddressing,      static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved2,                    static_cast<u32>(14228));
        TEST_ASSERT_EQUALS(temp.maximumNumberOfCommandRequests, static_cast<u32>(48));



        // |           00110000            |
        // |           11011110            |
        // |        010100         | 1 | 1 |
        // |        001000         |  00   |
        temp.rate = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x30DE5320);



        // |           00110000            |
        // |           11011110            |
        // |        010100         | 1 | 0 |
        // |        110111         |  00   |
        temp.__reserved = static_cast<u32>(55);

        TEST_ASSERT_EQUALS(temp.value32, 0x30DE52DC);



        // |           00110000            |
        // |           11011110            |
        // |        010100         | 0 | 0 |
        // |        110111         |  00   |
        temp.supportSideBandAddressing = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x30DE50DC);



        // |           00110000            |
        // |           00100001            |
        // |        101011         | 0 | 0 |
        // |        110111         |  00   |
        temp.__reserved2 = static_cast<u32>(2155);

        TEST_ASSERT_EQUALS(temp.value32, 0x3021ACDC);



        // |           11001111            |
        // |           00100001            |
        // |        101011         | 0 | 0 |
        // |        110111         |  00   |
        temp.maximumNumberOfCommandRequests = static_cast<u32>(207);

        TEST_ASSERT_EQUALS(temp.value32, 0xCF21ACDC);
    }
    TEST_CASE_END();



    TEST_CASE("PciBuiltInSelfTest");
    {
        PciBuiltInSelfTest temp;



        // PciBuiltInSelfTest:
        //
        // | D | C | BB | AAAA |
        //
        // completionCode : 4  'A'
        // __reserved     : 2  'B'
        // startBist      : 1  'C'
        // capable        : 1  'D'



        // | 1 | 1 | 10 | 0011 |
        temp.value8 = 0xE3;

        TEST_ASSERT_EQUALS(temp.completionCode, static_cast<u8>(3));
        TEST_ASSERT_EQUALS(temp.__reserved,     static_cast<u8>(2));
        TEST_ASSERT_EQUALS(temp.startBist,      static_cast<u8>(1));
        TEST_ASSERT_EQUALS(temp.capable,        static_cast<u8>(1));



        // | 1 | 1 | 10 | 1100 |
        temp.completionCode = static_cast<u8>(12);

        TEST_ASSERT_EQUALS(temp.value8, 0xEC);



        // | 1 | 1 | 01 | 1100 |
        temp.__reserved = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0xDC);



        // | 1 | 0 | 01 | 1100 |
        temp.startBist = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x9C);



        // | 0 | 0 | 01 | 1100 |
        temp.capable = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x1C);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressAccessControlServicesAcsCapability");
    {
        PciExpressAccessControlServicesAcsCapability temp;



        // PciExpressAccessControlServicesAcsCapability:
        //
        // |           IIIIIIII            |
        // | H | G | F | E | D | C | B | A |
        //
        // acsSourceValidation      : 1  'A'
        // acsTranslationBlocking   : 1  'B'
        // acsP2pRequestRedirect    : 1  'C'
        // acsP2pCompletionRedirect : 1  'D'
        // acsUpstreamForwarding    : 1  'E'
        // acsP2pEgressControl      : 1  'F'
        // acsDirectTranslatedP2p   : 1  'G'
        // __reserved               : 1  'H'
        // egressControlVectorSize  : 8  'I'



        // |           00111111            |
        // | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 0 |
        temp.value16 = 0x3F18;

        TEST_ASSERT_EQUALS(temp.acsSourceValidation,      static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.acsTranslationBlocking,   static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.acsP2pRequestRedirect,    static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.acsP2pCompletionRedirect, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.acsUpstreamForwarding,    static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.acsP2pEgressControl,      static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.acsDirectTranslatedP2p,   static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.egressControlVectorSize,  static_cast<u16>(63));



        // |           00111111            |
        // | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 |
        temp.acsSourceValidation = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3F19);



        // |           00111111            |
        // | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 1 |
        temp.acsTranslationBlocking = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3F1B);



        // |           00111111            |
        // | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 |
        temp.acsP2pRequestRedirect = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3F1F);



        // |           00111111            |
        // | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 1 |
        temp.acsP2pCompletionRedirect = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x3F17);



        // |           00111111            |
        // | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 |
        temp.acsUpstreamForwarding = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x3F07);



        // |           00111111            |
        // | 0 | 0 | 1 | 0 | 0 | 1 | 1 | 1 |
        temp.acsP2pEgressControl = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3F27);



        // |           00111111            |
        // | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 1 |
        temp.acsDirectTranslatedP2p = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3F67);



        // |           00111111            |
        // | 1 | 1 | 1 | 0 | 0 | 1 | 1 | 1 |
        temp.__reserved = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3FE7);



        // |           11000000            |
        // | 1 | 1 | 1 | 0 | 0 | 1 | 1 | 1 |
        temp.egressControlVectorSize = static_cast<u16>(192);

        TEST_ASSERT_EQUALS(temp.value16, 0xC0E7);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressAdvancedErrorCapabilitiesAndControl");
    {
        PciExpressAdvancedErrorCapabilitiesAndControl temp;



        // PciExpressAdvancedErrorCapabilitiesAndControl:
        //
        // |           IIIIIIII            |
        // |           IIIIIIII            |
        // |     IIII      | H | G | F | E |
        // | D | C | B |       AAAAA       |
        //
        // firstErrorPointer              : 5  'A'
        // ecrcGenerationCapable          : 1  'B'
        // ecrcGenerationEnable           : 1  'C'
        // ecrcCheckCapable               : 1  'D'
        // ecrcCheckEnable                : 1  'E'
        // multipleHeaderRecordingCapable : 1  'F'
        // multipleHeaderRecordingEnable  : 1  'G'
        // tlpPrefixLogPresent            : 1  'H'
        // __reserved                     : 20 'I'



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 1 | 0 | 1 | 1 |
        // | 0 | 0 | 0 |       01110       |
        temp.value32 = 0x9FAA1B0E;

        TEST_ASSERT_EQUALS(temp.firstErrorPointer,              static_cast<u32>(14));
        TEST_ASSERT_EQUALS(temp.ecrcGenerationCapable,          static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.ecrcGenerationEnable,           static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.ecrcCheckCapable,               static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.ecrcCheckEnable,                static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.multipleHeaderRecordingCapable, static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.multipleHeaderRecordingEnable,  static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.tlpPrefixLogPresent,            static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,                     static_cast<u32>(653985));



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 1 | 0 | 1 | 1 |
        // | 0 | 0 | 0 |       10001       |
        temp.firstErrorPointer = static_cast<u32>(17);

        TEST_ASSERT_EQUALS(temp.value32, 0x9FAA1B11);



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 1 | 0 | 1 | 1 |
        // | 0 | 0 | 1 |       10001       |
        temp.ecrcGenerationCapable = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x9FAA1B31);



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 1 | 0 | 1 | 1 |
        // | 0 | 1 | 1 |       10001       |
        temp.ecrcGenerationEnable = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x9FAA1B71);



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 1 | 0 | 1 | 1 |
        // | 1 | 1 | 1 |       10001       |
        temp.ecrcCheckCapable = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x9FAA1BF1);



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 1 | 0 | 1 | 0 |
        // | 1 | 1 | 1 |       10001       |
        temp.ecrcCheckEnable = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x9FAA1AF1);



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 1 | 0 | 0 | 0 |
        // | 1 | 1 | 1 |       10001       |
        temp.multipleHeaderRecordingCapable = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x9FAA18F1);



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 1 | 1 | 0 | 0 |
        // | 1 | 1 | 1 |       10001       |
        temp.multipleHeaderRecordingEnable = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x9FAA1CF1);



        // |           10011111            |
        // |           10101010            |
        // |     0001      | 0 | 1 | 0 | 0 |
        // | 1 | 1 | 1 |       10001       |
        temp.tlpPrefixLogPresent = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x9FAA14F1);



        // |           01100000            |
        // |           01010101            |
        // |     1110      | 0 | 1 | 0 | 0 |
        // | 1 | 1 | 1 |       10001       |
        temp.__reserved = static_cast<u32>(394590);

        TEST_ASSERT_EQUALS(temp.value32, 0x6055E4F1);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressAriCapabilityRegister");
    {
        PciExpressAriCapabilityRegister temp;



        // PciExpressAriCapabilityRegister:
        //
        // |           DDDDDDDD            |
        // |        CCCCCC         | B | A |
        //
        // mfvcFunctionGroupsCapability : 1  'A'
        // acsFunctionGroupsCapability  : 1  'B'
        // __reserved                   : 6  'C'
        // nextFunctionNumber           : 8  'D'



        // |           01110100            |
        // |        001001         | 0 | 0 |
        temp.value16 = 0x7424;

        TEST_ASSERT_EQUALS(temp.mfvcFunctionGroupsCapability, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.acsFunctionGroupsCapability,  static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,                   static_cast<u16>(9));
        TEST_ASSERT_EQUALS(temp.nextFunctionNumber,           static_cast<u16>(116));



        // |           01110100            |
        // |        001001         | 0 | 1 |
        temp.mfvcFunctionGroupsCapability = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x7425);



        // |           01110100            |
        // |        001001         | 1 | 1 |
        temp.acsFunctionGroupsCapability = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x7427);



        // |           01110100            |
        // |        110110         | 1 | 1 |
        temp.__reserved = static_cast<u16>(54);

        TEST_ASSERT_EQUALS(temp.value16, 0x74DB);



        // |           10001011            |
        // |        110110         | 1 | 1 |
        temp.nextFunctionNumber = static_cast<u16>(139);

        TEST_ASSERT_EQUALS(temp.value16, 0x8BDB);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressAriControlRegister");
    {
        PciExpressAriControlRegister temp;



        // PciExpressAriControlRegister:
        //
        // |           EEEEEEEE            |
        // | E |    DDD    |  CC   | B | A |
        //
        // mfvcFunctionGroupsEnable : 1  'A'
        // acsFunctionGroupsEnable  : 1  'B'
        // __reserved               : 2  'C'
        // functionGroup            : 3  'D'
        // __reserved2              : 9  'E'



        // |           00000011            |
        // | 1 |    111    |  00   | 1 | 1 |
        temp.value16 = 0x03F3;

        TEST_ASSERT_EQUALS(temp.mfvcFunctionGroupsEnable, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.acsFunctionGroupsEnable,  static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.functionGroup,            static_cast<u16>(7));
        TEST_ASSERT_EQUALS(temp.__reserved2,              static_cast<u16>(7));



        // |           00000011            |
        // | 1 |    111    |  00   | 1 | 0 |
        temp.mfvcFunctionGroupsEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x03F2);



        // |           00000011            |
        // | 1 |    111    |  00   | 0 | 0 |
        temp.acsFunctionGroupsEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x03F0);



        // |           00000011            |
        // | 1 |    111    |  11   | 0 | 0 |
        temp.__reserved = static_cast<u16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x03FC);



        // |           00000011            |
        // | 1 |    000    |  11   | 0 | 0 |
        temp.functionGroup = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x038C);



        // |           11111100            |
        // | 0 |    000    |  11   | 0 | 0 |
        temp.__reserved2 = static_cast<u16>(504);

        TEST_ASSERT_EQUALS(temp.value16, 0xFC0C);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressCapabilityRegister");
    {
        PciExpressCapabilityRegister temp;



        // PciExpressCapabilityRegister:
        //
        // | F | E |       DDDDD       | C |
        // |     BBBB      |     AAAA      |
        //
        // capabilityVersion      : 4  'A'
        // devicePortType         : 4  'B'
        // slotImplemented        : 1  'C'
        // interruptMessageNumber : 5  'D'
        // undefined              : 1  'E'
        // __reserved             : 1  'F'



        // | 0 | 0 |       01100       | 0 |
        // |     0000      |     1000      |
        temp.value16 = 0x1808;

        TEST_ASSERT_EQUALS(temp.capabilityVersion,      static_cast<u16>(8));
        TEST_ASSERT_EQUALS(temp.devicePortType,         static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.slotImplemented,        static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.interruptMessageNumber, static_cast<u16>(12));
        TEST_ASSERT_EQUALS(temp.undefined,              static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,             static_cast<u16>(0));



        // | 0 | 0 |       01100       | 0 |
        // |     0000      |     0111      |
        temp.capabilityVersion = static_cast<u16>(7);

        TEST_ASSERT_EQUALS(temp.value16, 0x1807);



        // | 0 | 0 |       01100       | 0 |
        // |     1111      |     0111      |
        temp.devicePortType = static_cast<u16>(15);

        TEST_ASSERT_EQUALS(temp.value16, 0x18F7);



        // | 0 | 0 |       01100       | 1 |
        // |     1111      |     0111      |
        temp.slotImplemented = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x19F7);



        // | 0 | 0 |       10011       | 1 |
        // |     1111      |     0111      |
        temp.interruptMessageNumber = static_cast<u16>(19);

        TEST_ASSERT_EQUALS(temp.value16, 0x27F7);



        // | 0 | 1 |       10011       | 1 |
        // |     1111      |     0111      |
        temp.undefined = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x67F7);



        // | 1 | 1 |       10011       | 1 |
        // |     1111      |     0111      |
        temp.__reserved = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xE7F7);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressDeviceCapability");
    {
        PciExpressDeviceCapability temp;



        // PciExpressDeviceCapability:
        //
        // |    LLL    | K |  JJ   |  II   |
        // |        IIIIII         |  HH   |
        // | G |    FFF    |    EEE    | D |
        // |  DD   | C |  BB   |    AAA    |
        //
        // maximumPayloadSizeSupported  : 3  'A'
        // phantomFunctionsSupported    : 2  'B'
        // extendedTagFieldSupported    : 1  'C'
        // endpointL0sAcceptableLatency : 3  'D'
        // endpointL1AcceptableLatency  : 3  'E'
        // undefined                    : 3  'F'
        // roleBasedErrorReporting      : 1  'G'
        // __reserved                   : 2  'H'
        // capturedSlotPowerLimitValue  : 8  'I'
        // capturedSlotPowerLimitScale  : 2  'J'
        // functionLevelResetCapability : 1  'K'
        // __reserved2                  : 3  'L'



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  10   |
        // | 1 |    000    |    101    | 0 |
        // |  01   | 0 |  10   |    011    |
        temp.value32 = 0x79828A53;

        TEST_ASSERT_EQUALS(temp.maximumPayloadSizeSupported,  static_cast<u32>(3));
        TEST_ASSERT_EQUALS(temp.phantomFunctionsSupported,    static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.extendedTagFieldSupported,    static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.endpointL0sAcceptableLatency, static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.endpointL1AcceptableLatency,  static_cast<u32>(5));
        TEST_ASSERT_EQUALS(temp.undefined,                    static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.roleBasedErrorReporting,      static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,                   static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.capturedSlotPowerLimitValue,  static_cast<u32>(96));
        TEST_ASSERT_EQUALS(temp.capturedSlotPowerLimitScale,  static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.functionLevelResetCapability, static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved2,                  static_cast<u32>(3));



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  10   |
        // | 1 |    000    |    101    | 0 |
        // |  01   | 0 |  10   |    100    |
        temp.maximumPayloadSizeSupported = static_cast<u32>(4);

        TEST_ASSERT_EQUALS(temp.value32, 0x79828A54);



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  10   |
        // | 1 |    000    |    101    | 0 |
        // |  01   | 0 |  01   |    100    |
        temp.phantomFunctionsSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x79828A4C);



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  10   |
        // | 1 |    000    |    101    | 0 |
        // |  01   | 1 |  01   |    100    |
        temp.extendedTagFieldSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x79828A6C);



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  10   |
        // | 1 |    000    |    101    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.endpointL0sAcceptableLatency = static_cast<u32>(6);

        TEST_ASSERT_EQUALS(temp.value32, 0x79828BAC);



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  10   |
        // | 1 |    000    |    010    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.endpointL1AcceptableLatency = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x798285AC);



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  10   |
        // | 1 |    111    |    010    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.undefined = static_cast<u32>(7);

        TEST_ASSERT_EQUALS(temp.value32, 0x7982F5AC);



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  10   |
        // | 0 |    111    |    010    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.roleBasedErrorReporting = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x798275AC);



        // |    011    | 1 |  10   |  01   |
        // |        100000         |  01   |
        // | 0 |    111    |    010    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.__reserved = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x798175AC);



        // |    011    | 1 |  10   |  10   |
        // |        011111         |  01   |
        // | 0 |    111    |    010    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.capturedSlotPowerLimitValue = static_cast<u32>(159);

        TEST_ASSERT_EQUALS(temp.value32, 0x7A7D75AC);



        // |    011    | 1 |  01   |  10   |
        // |        011111         |  01   |
        // | 0 |    111    |    010    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.capturedSlotPowerLimitScale = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x767D75AC);



        // |    011    | 0 |  01   |  10   |
        // |        011111         |  01   |
        // | 0 |    111    |    010    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.functionLevelResetCapability = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x667D75AC);



        // |    100    | 0 |  01   |  10   |
        // |        011111         |  01   |
        // | 0 |    111    |    010    | 1 |
        // |  10   | 1 |  01   |    100    |
        temp.__reserved2 = static_cast<u32>(4);

        TEST_ASSERT_EQUALS(temp.value32, 0x867D75AC);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressDeviceCapability2");
    {
        PciExpressDeviceCapability2 temp;



        // PciExpressDeviceCapability2:
        //
        // | U |     TTTT      | S |  RR   |
        // |  QQ   | P | O |  NN   | M | L |
        // |  KK   |  JJ   | I | H | G | F |
        // | E | D | C | B |     AAAA      |
        //
        // completionTimeoutRangesSupported              : 4  'A'
        // completionTimeoutDisableSupported             : 1  'B'
        // ariForwardingSupported                        : 1  'C'
        // atomicOpRoutingSupported                      : 1  'D'
        // atomicOp32CompleterSupported                  : 1  'E'
        // atomicOp64CompleterSupported                  : 1  'F'
        // cas128CompleterSupported                      : 1  'G'
        // noRoEnabledPrPrPassing                        : 1  'H'
        // ltrMechanismSupported                         : 1  'I'
        // tphCompleterSupported                         : 2  'J'
        // lnSystemCls                                   : 2  'K'
        // tenBitTagCompleterSupported                   : 1  'L'
        // tenBitTagRequesterSupported                   : 1  'M'
        // obff                                          : 2  'N'
        // extendedFmtFieldSupported                     : 1  'O'
        // endEndTlpPrefixSupported                      : 1  'P'
        // maxEndEndTlpPrefixes                          : 2  'Q'
        // emergencyPowerReductionSupported              : 2  'R'
        // emergencyPowerReductionInitializationRequired : 1  'S'
        // __reserved                                    : 4  'T'
        // frsSupported                                  : 1  'U'



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 1 | 0 | 1 |
        // | 1 | 1 | 0 | 1 |     1011      |
        temp.value32 = 0x012605DB;

        TEST_ASSERT_EQUALS(temp.completionTimeoutRangesSupported,              static_cast<u32>(11));
        TEST_ASSERT_EQUALS(temp.completionTimeoutDisableSupported,             static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.ariForwardingSupported,                        static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.atomicOpRoutingSupported,                      static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.atomicOp32CompleterSupported,                  static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.atomicOp64CompleterSupported,                  static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.cas128CompleterSupported,                      static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.noRoEnabledPrPrPassing,                        static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.ltrMechanismSupported,                         static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.tphCompleterSupported,                         static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.lnSystemCls,                                   static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.tenBitTagCompleterSupported,                   static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.tenBitTagRequesterSupported,                   static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.obff,                                          static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.extendedFmtFieldSupported,                     static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.endEndTlpPrefixSupported,                      static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.maxEndEndTlpPrefixes,                          static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.emergencyPowerReductionSupported,              static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.emergencyPowerReductionInitializationRequired, static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,                                    static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.frsSupported,                                  static_cast<u32>(0));



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 1 | 0 | 1 |
        // | 1 | 1 | 0 | 1 |     0100      |
        temp.completionTimeoutRangesSupported = static_cast<u32>(4);

        TEST_ASSERT_EQUALS(temp.value32, 0x012605D4);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 1 | 0 | 1 |
        // | 1 | 1 | 0 | 0 |     0100      |
        temp.completionTimeoutDisableSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x012605C4);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 1 | 0 | 1 |
        // | 1 | 1 | 1 | 0 |     0100      |
        temp.ariForwardingSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x012605E4);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 1 | 0 | 1 |
        // | 1 | 0 | 1 | 0 |     0100      |
        temp.atomicOpRoutingSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x012605A4);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 1 | 0 | 1 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.atomicOp32CompleterSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x01260524);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 1 | 0 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.atomicOp64CompleterSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x01260424);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 1 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.cas128CompleterSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x01260624);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 0 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.noRoEnabledPrPrPassing = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x01260224);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  00   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.ltrMechanismSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x01260A24);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  00   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.tphCompleterSupported = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x01263A24);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 0 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.lnSystemCls = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x0126FA24);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 1 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.tenBitTagCompleterSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x0127FA24);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  01   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.tenBitTagRequesterSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x0125FA24);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 0 |  10   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.obff = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x0129FA24);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 1 | 1 |  10   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.extendedFmtFieldSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x0139FA24);



        // | 0 |     0000      | 0 |  01   |
        // |  00   | 0 | 1 |  10   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.endEndTlpPrefixSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x0119FA24);



        // | 0 |     0000      | 0 |  01   |
        // |  11   | 0 | 1 |  10   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.maxEndEndTlpPrefixes = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x01D9FA24);



        // | 0 |     0000      | 0 |  10   |
        // |  11   | 0 | 1 |  10   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.emergencyPowerReductionSupported = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x02D9FA24);



        // | 0 |     0000      | 1 |  10   |
        // |  11   | 0 | 1 |  10   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.emergencyPowerReductionInitializationRequired = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x06D9FA24);



        // | 0 |     1111      | 1 |  10   |
        // |  11   | 0 | 1 |  10   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.__reserved = static_cast<u32>(15);

        TEST_ASSERT_EQUALS(temp.value32, 0x7ED9FA24);



        // | 1 |     1111      | 1 |  10   |
        // |  11   | 0 | 1 |  10   | 0 | 1 |
        // |  11   |  11   | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 |     0100      |
        temp.frsSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xFED9FA24);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressDeviceControl");
    {
        PciExpressDeviceControl temp;



        // PciExpressDeviceControl:
        //
        // | L |    KKK    | J | I | H | G |
        // |    FFF    | E | D | C | B | A |
        //
        // correctableErrorReportingEnable                            : 1  'A'
        // nonFatalErrorReportingEnable                               : 1  'B'
        // fatalErrorReportingEnable                                  : 1  'C'
        // unsupportedRequestReportingEnable                          : 1  'D'
        // enableRelaxedOrdering                                      : 1  'E'
        // maximumPayloadSize                                         : 3  'F'
        // extendedTagFieldEnable                                     : 1  'G'
        // phantomFunctionsEnable                                     : 1  'H'
        // auxPowerPmEnable                                           : 1  'I'
        // enableNoSnoop                                              : 1  'J'
        // maximumReadRequestSize                                     : 3  'K'
        // bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset : 1  'L'



        // | 0 |    000    | 0 | 1 | 1 | 1 |
        // |    101    | 1 | 1 | 0 | 1 | 1 |
        temp.value16 = 0x07BB;

        TEST_ASSERT_EQUALS(temp.correctableErrorReportingEnable,                            static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.nonFatalErrorReportingEnable,                               static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.fatalErrorReportingEnable,                                  static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.unsupportedRequestReportingEnable,                          static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.enableRelaxedOrdering,                                      static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.maximumPayloadSize,                                         static_cast<u16>(5));
        TEST_ASSERT_EQUALS(temp.extendedTagFieldEnable,                                     static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.phantomFunctionsEnable,                                     static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.auxPowerPmEnable,                                           static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.enableNoSnoop,                                              static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.maximumReadRequestSize,                                     static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset, static_cast<u16>(0));



        // | 0 |    000    | 0 | 1 | 1 | 1 |
        // |    101    | 1 | 1 | 0 | 1 | 0 |
        temp.correctableErrorReportingEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x07BA);



        // | 0 |    000    | 0 | 1 | 1 | 1 |
        // |    101    | 1 | 1 | 0 | 0 | 0 |
        temp.nonFatalErrorReportingEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x07B8);



        // | 0 |    000    | 0 | 1 | 1 | 1 |
        // |    101    | 1 | 1 | 1 | 0 | 0 |
        temp.fatalErrorReportingEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x07BC);



        // | 0 |    000    | 0 | 1 | 1 | 1 |
        // |    101    | 1 | 0 | 1 | 0 | 0 |
        temp.unsupportedRequestReportingEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x07B4);



        // | 0 |    000    | 0 | 1 | 1 | 1 |
        // |    101    | 0 | 0 | 1 | 0 | 0 |
        temp.enableRelaxedOrdering = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x07A4);



        // | 0 |    000    | 0 | 1 | 1 | 1 |
        // |    010    | 0 | 0 | 1 | 0 | 0 |
        temp.maximumPayloadSize = static_cast<u16>(2);

        TEST_ASSERT_EQUALS(temp.value16, 0x0744);



        // | 0 |    000    | 0 | 1 | 1 | 0 |
        // |    010    | 0 | 0 | 1 | 0 | 0 |
        temp.extendedTagFieldEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x0644);



        // | 0 |    000    | 0 | 1 | 0 | 0 |
        // |    010    | 0 | 0 | 1 | 0 | 0 |
        temp.phantomFunctionsEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x0444);



        // | 0 |    000    | 0 | 0 | 0 | 0 |
        // |    010    | 0 | 0 | 1 | 0 | 0 |
        temp.auxPowerPmEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x0044);



        // | 0 |    000    | 1 | 0 | 0 | 0 |
        // |    010    | 0 | 0 | 1 | 0 | 0 |
        temp.enableNoSnoop = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x0844);



        // | 0 |    111    | 1 | 0 | 0 | 0 |
        // |    010    | 0 | 0 | 1 | 0 | 0 |
        temp.maximumReadRequestSize = static_cast<u16>(7);

        TEST_ASSERT_EQUALS(temp.value16, 0x7844);



        // | 1 |    111    | 1 | 0 | 0 | 0 |
        // |    010    | 0 | 0 | 1 | 0 | 0 |
        temp.bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xF844);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressDeviceControl2");
    {
        PciExpressDeviceControl2 temp;



        // PciExpressDeviceControl2:
        //
        // | L |  KK   | J | I | H | G | F |
        // | E | D | C | B |     AAAA      |
        //
        // completionTimeoutValue         : 4  'A'
        // completionTimeoutDisable       : 1  'B'
        // ariForwardingEnable            : 1  'C'
        // atomicOpRequesterEnable        : 1  'D'
        // atomicOpEgressBlocking         : 1  'E'
        // idoRequestEnable               : 1  'F'
        // idoCompletionEnable            : 1  'G'
        // ltrMechanismEnable             : 1  'H'
        // emergencyPowerReductionRequest : 1  'I'
        // tenBitTagRequesterEnable       : 1  'J'
        // obff                           : 2  'K'
        // endEndTlpPrefixBlocking        : 1  'L'



        // | 1 |  10   | 0 | 1 | 0 | 1 | 0 |
        // | 0 | 1 | 1 | 1 |     0101      |
        temp.value16 = 0xCA75;

        TEST_ASSERT_EQUALS(temp.completionTimeoutValue,         static_cast<u16>(5));
        TEST_ASSERT_EQUALS(temp.completionTimeoutDisable,       static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.ariForwardingEnable,            static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.atomicOpRequesterEnable,        static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.atomicOpEgressBlocking,         static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.idoRequestEnable,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.idoCompletionEnable,            static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.ltrMechanismEnable,             static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.emergencyPowerReductionRequest, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.tenBitTagRequesterEnable,       static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.obff,                           static_cast<u16>(2));
        TEST_ASSERT_EQUALS(temp.endEndTlpPrefixBlocking,        static_cast<u16>(1));



        // | 1 |  10   | 0 | 1 | 0 | 1 | 0 |
        // | 0 | 1 | 1 | 1 |     1010      |
        temp.completionTimeoutValue = static_cast<u16>(10);

        TEST_ASSERT_EQUALS(temp.value16, 0xCA7A);



        // | 1 |  10   | 0 | 1 | 0 | 1 | 0 |
        // | 0 | 1 | 1 | 0 |     1010      |
        temp.completionTimeoutDisable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xCA6A);



        // | 1 |  10   | 0 | 1 | 0 | 1 | 0 |
        // | 0 | 1 | 0 | 0 |     1010      |
        temp.ariForwardingEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xCA4A);



        // | 1 |  10   | 0 | 1 | 0 | 1 | 0 |
        // | 0 | 0 | 0 | 0 |     1010      |
        temp.atomicOpRequesterEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xCA0A);



        // | 1 |  10   | 0 | 1 | 0 | 1 | 0 |
        // | 1 | 0 | 0 | 0 |     1010      |
        temp.atomicOpEgressBlocking = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xCA8A);



        // | 1 |  10   | 0 | 1 | 0 | 1 | 1 |
        // | 1 | 0 | 0 | 0 |     1010      |
        temp.idoRequestEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xCB8A);



        // | 1 |  10   | 0 | 1 | 0 | 0 | 1 |
        // | 1 | 0 | 0 | 0 |     1010      |
        temp.idoCompletionEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xC98A);



        // | 1 |  10   | 0 | 1 | 1 | 0 | 1 |
        // | 1 | 0 | 0 | 0 |     1010      |
        temp.ltrMechanismEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xCD8A);



        // | 1 |  10   | 0 | 0 | 1 | 0 | 1 |
        // | 1 | 0 | 0 | 0 |     1010      |
        temp.emergencyPowerReductionRequest = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xC58A);



        // | 1 |  10   | 1 | 0 | 1 | 0 | 1 |
        // | 1 | 0 | 0 | 0 |     1010      |
        temp.tenBitTagRequesterEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xD58A);



        // | 1 |  01   | 1 | 0 | 1 | 0 | 1 |
        // | 1 | 0 | 0 | 0 |     1010      |
        temp.obff = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xB58A);



        // | 0 |  01   | 1 | 0 | 1 | 0 | 1 |
        // | 1 | 0 | 0 | 0 |     1010      |
        temp.endEndTlpPrefixBlocking = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x358A);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressDynamicPowerAllocationCapabilityRegister");
    {
        PciExpressDynamicPowerAllocationCapabilityRegister temp;



        // PciExpressDynamicPowerAllocationCapabilityRegister:
        //
        // |           HHHHHHHH            |
        // |           GGGGGGGG            |
        // |  FF   |  EE   |  DD   |  CC   |
        // |    BBB    |       AAAAA       |
        //
        // substateMaximum         : 5  'A'
        // __reserved              : 3  'B'
        // transitionLatencyUnit   : 2  'C'
        // __reserved2             : 2  'D'
        // powerAllocationScale    : 2  'E'
        // __reserved3             : 2  'F'
        // transitionLatencyValue0 : 8  'G'
        // transitionLatencyValue1 : 8  'H'



        // |           00001010            |
        // |           00100100            |
        // |  11   |  01   |  01   |  00   |
        // |    000    |       00110       |
        temp.value32 = 0x0A24D406;

        TEST_ASSERT_EQUALS(temp.substateMaximum,         static_cast<u32>(6));
        TEST_ASSERT_EQUALS(temp.__reserved,              static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.transitionLatencyUnit,   static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved2,             static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.powerAllocationScale,    static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved3,             static_cast<u32>(3));
        TEST_ASSERT_EQUALS(temp.transitionLatencyValue0, static_cast<u32>(36));
        TEST_ASSERT_EQUALS(temp.transitionLatencyValue1, static_cast<u32>(10));



        // |           00001010            |
        // |           00100100            |
        // |  11   |  01   |  01   |  00   |
        // |    000    |       11001       |
        temp.substateMaximum = static_cast<u32>(25);

        TEST_ASSERT_EQUALS(temp.value32, 0x0A24D419);



        // |           00001010            |
        // |           00100100            |
        // |  11   |  01   |  01   |  00   |
        // |    111    |       11001       |
        temp.__reserved = static_cast<u32>(7);

        TEST_ASSERT_EQUALS(temp.value32, 0x0A24D4F9);



        // |           00001010            |
        // |           00100100            |
        // |  11   |  01   |  01   |  11   |
        // |    111    |       11001       |
        temp.transitionLatencyUnit = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x0A24D7F9);



        // |           00001010            |
        // |           00100100            |
        // |  11   |  01   |  10   |  11   |
        // |    111    |       11001       |
        temp.__reserved2 = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x0A24DBF9);



        // |           00001010            |
        // |           00100100            |
        // |  11   |  10   |  10   |  11   |
        // |    111    |       11001       |
        temp.powerAllocationScale = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x0A24EBF9);



        // |           00001010            |
        // |           00100100            |
        // |  00   |  10   |  10   |  11   |
        // |    111    |       11001       |
        temp.__reserved3 = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x0A242BF9);



        // |           00001010            |
        // |           11011011            |
        // |  00   |  10   |  10   |  11   |
        // |    111    |       11001       |
        temp.transitionLatencyValue0 = static_cast<u32>(219);

        TEST_ASSERT_EQUALS(temp.value32, 0x0ADB2BF9);



        // |           11110101            |
        // |           11011011            |
        // |  00   |  10   |  10   |  11   |
        // |    111    |       11001       |
        temp.transitionLatencyValue1 = static_cast<u32>(245);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5DB2BF9);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressDynamicPowerAllocationControlRegister");
    {
        PciExpressDynamicPowerAllocationControlRegister temp;



        // PciExpressDynamicPowerAllocationControlRegister:
        //
        // |           BBBBBBBB            |
        // |    BBB    |       AAAAA       |
        //
        // substateControl : 5  'A'
        // __reserved      : 11 'B'



        // |           11110100            |
        // |    010    |       00110       |
        temp.value16 = 0xF446;

        TEST_ASSERT_EQUALS(temp.substateControl, static_cast<u16>(6));
        TEST_ASSERT_EQUALS(temp.__reserved,      static_cast<u16>(1954));



        // |           11110100            |
        // |    010    |       11001       |
        temp.substateControl = static_cast<u16>(25);

        TEST_ASSERT_EQUALS(temp.value16, 0xF459);



        // |           00001011            |
        // |    101    |       11001       |
        temp.__reserved = static_cast<u16>(93);

        TEST_ASSERT_EQUALS(temp.value16, 0x0BB9);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressDynamicPowerAllocationStatusRegister");
    {
        PciExpressDynamicPowerAllocationStatusRegister temp;



        // PciExpressDynamicPowerAllocationStatusRegister:
        //
        // |          DDDDDDD          | C |
        // |    BBB    |       AAAAA       |
        //
        // substateStatus         : 5  'A'
        // __reserved             : 3  'B'
        // substateControlEnabled : 1  'C'
        // __reserved2            : 7  'D'



        // |          1101100          | 1 |
        // |    110    |       01110       |
        temp.value16 = 0xD9CE;

        TEST_ASSERT_EQUALS(temp.substateStatus,         static_cast<u16>(14));
        TEST_ASSERT_EQUALS(temp.__reserved,             static_cast<u16>(6));
        TEST_ASSERT_EQUALS(temp.substateControlEnabled, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved2,            static_cast<u16>(108));



        // |          1101100          | 1 |
        // |    110    |       10001       |
        temp.substateStatus = static_cast<u16>(17);

        TEST_ASSERT_EQUALS(temp.value16, 0xD9D1);



        // |          1101100          | 1 |
        // |    001    |       10001       |
        temp.__reserved = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xD931);



        // |          1101100          | 0 |
        // |    001    |       10001       |
        temp.substateControlEnabled = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xD831);



        // |          0010011          | 0 |
        // |    001    |       10001       |
        temp.__reserved2 = static_cast<u16>(19);

        TEST_ASSERT_EQUALS(temp.value16, 0x2631);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressLatencyToleranceReportingMaxNoSnoopLatencyRegister");
    {
        PciExpressLatencyToleranceReportingMaxNoSnoopLatencyRegister temp;



        // PciExpressLatencyToleranceReportingMaxNoSnoopLatencyRegister:
        //
        // |    CCC    |    BBB    |  AA   |
        // |           AAAAAAAA            |
        //
        // latencyValue : 10 'A'
        // latencyScale : 3  'B'
        // __reserved   : 3  'C'



        // |    110    |    001    |  01   |
        // |           11100110            |
        temp.value16 = 0xC5E6;

        TEST_ASSERT_EQUALS(temp.latencyValue, static_cast<u16>(486));
        TEST_ASSERT_EQUALS(temp.latencyScale, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,   static_cast<u16>(6));



        // |    110    |    001    |  10   |
        // |           00011001            |
        temp.latencyValue = static_cast<u16>(537);

        TEST_ASSERT_EQUALS(temp.value16, 0xC619);



        // |    110    |    110    |  10   |
        // |           00011001            |
        temp.latencyScale = static_cast<u16>(6);

        TEST_ASSERT_EQUALS(temp.value16, 0xDA19);



        // |    001    |    110    |  10   |
        // |           00011001            |
        temp.__reserved = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3A19);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressLatencyToleranceReportingMaxSnoopLatencyRegister");
    {
        PciExpressLatencyToleranceReportingMaxSnoopLatencyRegister temp;



        // PciExpressLatencyToleranceReportingMaxSnoopLatencyRegister:
        //
        // |    CCC    |    BBB    |  AA   |
        // |           AAAAAAAA            |
        //
        // latencyValue : 10 'A'
        // latencyScale : 3  'B'
        // __reserved   : 3  'C'



        // |    100    |    100    |  11   |
        // |           11000000            |
        temp.value16 = 0x93C0;

        TEST_ASSERT_EQUALS(temp.latencyValue, static_cast<u16>(960));
        TEST_ASSERT_EQUALS(temp.latencyScale, static_cast<u16>(4));
        TEST_ASSERT_EQUALS(temp.__reserved,   static_cast<u16>(4));



        // |    100    |    100    |  00   |
        // |           00111111            |
        temp.latencyValue = static_cast<u16>(63);

        TEST_ASSERT_EQUALS(temp.value16, 0x903F);



        // |    100    |    011    |  00   |
        // |           00111111            |
        temp.latencyScale = static_cast<u16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x8C3F);



        // |    011    |    011    |  00   |
        // |           00111111            |
        temp.__reserved = static_cast<u16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x6C3F);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressLinkCapability");
    {
        PciExpressLinkCapability temp;



        // PciExpressLinkCapability:
        //
        // |           LLLLLLLL            |
        // | K | J | I | H | G | F |  EE   |
        // | E |    DDD    |  CC   |  BB   |
        // |     BBBB      |     AAAA      |
        //
        // supportedLinkSpeeds                     : 4  'A'
        // maximumLinkWidth                        : 6  'B'
        // aspmSupport                             : 2  'C'
        // l0sExitLatency                          : 3  'D'
        // l1ExitLatency                           : 3  'E'
        // clockPowerManagement                    : 1  'F'
        // surpriseDownErrorReportingCapable       : 1  'G'
        // dataLinkLayerLinkActiveReportingCapable : 1  'H'
        // linkBandwidthNotificationCapability     : 1  'I'
        // aspmOptionalityCompliance               : 1  'J'
        // __reserved                              : 1  'K'
        // portNumber                              : 8  'L'



        // |           00111110            |
        // | 1 | 0 | 1 | 1 | 0 | 0 |  00   |
        // | 0 |    110    |  10   |  10   |
        // |     1111      |     1000      |
        temp.value32 = 0x3EB06AF8;

        TEST_ASSERT_EQUALS(temp.supportedLinkSpeeds,                     static_cast<u32>(8));
        TEST_ASSERT_EQUALS(temp.maximumLinkWidth,                        static_cast<u32>(47));
        TEST_ASSERT_EQUALS(temp.aspmSupport,                             static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.l0sExitLatency,                          static_cast<u32>(6));
        TEST_ASSERT_EQUALS(temp.l1ExitLatency,                           static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.clockPowerManagement,                    static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.surpriseDownErrorReportingCapable,       static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.dataLinkLayerLinkActiveReportingCapable, static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.linkBandwidthNotificationCapability,     static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.aspmOptionalityCompliance,               static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,                              static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.portNumber,                              static_cast<u32>(62));



        // |           00111110            |
        // | 1 | 0 | 1 | 1 | 0 | 0 |  00   |
        // | 0 |    110    |  10   |  10   |
        // |     1111      |     0111      |
        temp.supportedLinkSpeeds = static_cast<u32>(7);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EB06AF7);



        // |           00111110            |
        // | 1 | 0 | 1 | 1 | 0 | 0 |  00   |
        // | 0 |    110    |  10   |  01   |
        // |     0000      |     0111      |
        temp.maximumLinkWidth = static_cast<u32>(16);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EB06907);



        // |           00111110            |
        // | 1 | 0 | 1 | 1 | 0 | 0 |  00   |
        // | 0 |    110    |  01   |  01   |
        // |     0000      |     0111      |
        temp.aspmSupport = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EB06507);



        // |           00111110            |
        // | 1 | 0 | 1 | 1 | 0 | 0 |  00   |
        // | 0 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.l0sExitLatency = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EB01507);



        // |           00111110            |
        // | 1 | 0 | 1 | 1 | 0 | 0 |  11   |
        // | 1 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.l1ExitLatency = static_cast<u32>(7);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EB39507);



        // |           00111110            |
        // | 1 | 0 | 1 | 1 | 0 | 1 |  11   |
        // | 1 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.clockPowerManagement = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EB79507);



        // |           00111110            |
        // | 1 | 0 | 1 | 1 | 1 | 1 |  11   |
        // | 1 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.surpriseDownErrorReportingCapable = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EBF9507);



        // |           00111110            |
        // | 1 | 0 | 1 | 0 | 1 | 1 |  11   |
        // | 1 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.dataLinkLayerLinkActiveReportingCapable = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x3EAF9507);



        // |           00111110            |
        // | 1 | 0 | 0 | 0 | 1 | 1 |  11   |
        // | 1 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.linkBandwidthNotificationCapability = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x3E8F9507);



        // |           00111110            |
        // | 1 | 1 | 0 | 0 | 1 | 1 |  11   |
        // | 1 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.aspmOptionalityCompliance = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x3ECF9507);



        // |           00111110            |
        // | 0 | 1 | 0 | 0 | 1 | 1 |  11   |
        // | 1 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.__reserved = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x3E4F9507);



        // |           11000001            |
        // | 0 | 1 | 0 | 0 | 1 | 1 |  11   |
        // | 1 |    001    |  01   |  01   |
        // |     0000      |     0111      |
        temp.portNumber = static_cast<u32>(193);

        TEST_ASSERT_EQUALS(temp.value32, 0xC14F9507);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressLinkCapability2");
    {
        PciExpressLinkCapability2 temp;



        // PciExpressLinkCapability2:
        //
        // |           DDDDDDDD            |
        // |           DDDDDDDD            |
        // |          DDDDDDD          | C |
        // |          BBBBBBB          | A |
        //
        // __reserved       : 1  'A'
        // linkSpeedsVector : 7  'B'
        // crosslink        : 1  'C'
        // __reserved2      : 23 'D'



        // |           11011010            |
        // |           01001011            |
        // |          0100111          | 0 |
        // |          1101100          | 1 |
        temp.value32 = 0xDA4B4ED9;

        TEST_ASSERT_EQUALS(temp.__reserved,       static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.linkSpeedsVector, static_cast<u32>(108));
        TEST_ASSERT_EQUALS(temp.crosslink,        static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved2,      static_cast<u32>(7153063));



        // |           11011010            |
        // |           01001011            |
        // |          0100111          | 0 |
        // |          1101100          | 0 |
        temp.__reserved = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xDA4B4ED8);



        // |           11011010            |
        // |           01001011            |
        // |          0100111          | 0 |
        // |          0010011          | 0 |
        temp.linkSpeedsVector = static_cast<u32>(19);

        TEST_ASSERT_EQUALS(temp.value32, 0xDA4B4E26);



        // |           11011010            |
        // |           01001011            |
        // |          0100111          | 1 |
        // |          0010011          | 0 |
        temp.crosslink = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xDA4B4F26);



        // |           00100101            |
        // |           10110100            |
        // |          1011000          | 1 |
        // |          0010011          | 0 |
        temp.__reserved2 = static_cast<u32>(1235544);

        TEST_ASSERT_EQUALS(temp.value32, 0x25B4B126);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressLinkControl");
    {
        PciExpressLinkControl temp;



        // PciExpressLinkControl:
        //
        // |     LLLL      | K | J | I | H |
        // | G | F | E | D | C | B |  AA   |
        //
        // aspmControl                            : 2  'A'
        // __reserved                             : 1  'B'
        // readCompletionBoundary                 : 1  'C'
        // linkDisable                            : 1  'D'
        // retrainLink                            : 1  'E'
        // commonClockConfiguration               : 1  'F'
        // extendedSynch                          : 1  'G'
        // enableClockPowerManagement             : 1  'H'
        // hardwareAutonomousWidthDisable         : 1  'I'
        // linkBandwidthManagementInterruptEnable : 1  'J'
        // linkAutonomousBandwidthInterruptEnable : 1  'K'
        // __reserved2                            : 4  'L'



        // |     0010      | 0 | 0 | 1 | 0 |
        // | 0 | 0 | 0 | 1 | 1 | 0 |  00   |
        temp.value16 = 0x2218;

        TEST_ASSERT_EQUALS(temp.aspmControl,                            static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,                             static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.readCompletionBoundary,                 static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.linkDisable,                            static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.retrainLink,                            static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.commonClockConfiguration,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.extendedSynch,                          static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.enableClockPowerManagement,             static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.hardwareAutonomousWidthDisable,         static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.linkBandwidthManagementInterruptEnable, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.linkAutonomousBandwidthInterruptEnable, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.__reserved2,                            static_cast<u16>(2));



        // |     0010      | 0 | 0 | 1 | 0 |
        // | 0 | 0 | 0 | 1 | 1 | 0 |  11   |
        temp.aspmControl = static_cast<u16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x221B);



        // |     0010      | 0 | 0 | 1 | 0 |
        // | 0 | 0 | 0 | 1 | 1 | 1 |  11   |
        temp.__reserved = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x221F);



        // |     0010      | 0 | 0 | 1 | 0 |
        // | 0 | 0 | 0 | 1 | 0 | 1 |  11   |
        temp.readCompletionBoundary = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2217);



        // |     0010      | 0 | 0 | 1 | 0 |
        // | 0 | 0 | 0 | 0 | 0 | 1 |  11   |
        temp.linkDisable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2207);



        // |     0010      | 0 | 0 | 1 | 0 |
        // | 0 | 0 | 1 | 0 | 0 | 1 |  11   |
        temp.retrainLink = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2227);



        // |     0010      | 0 | 0 | 1 | 0 |
        // | 0 | 1 | 1 | 0 | 0 | 1 |  11   |
        temp.commonClockConfiguration = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2267);



        // |     0010      | 0 | 0 | 1 | 0 |
        // | 1 | 1 | 1 | 0 | 0 | 1 |  11   |
        temp.extendedSynch = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x22E7);



        // |     0010      | 0 | 0 | 1 | 1 |
        // | 1 | 1 | 1 | 0 | 0 | 1 |  11   |
        temp.enableClockPowerManagement = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x23E7);



        // |     0010      | 0 | 0 | 0 | 1 |
        // | 1 | 1 | 1 | 0 | 0 | 1 |  11   |
        temp.hardwareAutonomousWidthDisable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x21E7);



        // |     0010      | 0 | 1 | 0 | 1 |
        // | 1 | 1 | 1 | 0 | 0 | 1 |  11   |
        temp.linkBandwidthManagementInterruptEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x25E7);



        // |     0010      | 1 | 1 | 0 | 1 |
        // | 1 | 1 | 1 | 0 | 0 | 1 |  11   |
        temp.linkAutonomousBandwidthInterruptEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2DE7);



        // |     1101      | 1 | 1 | 0 | 1 |
        // | 1 | 1 | 1 | 0 | 0 | 1 |  11   |
        temp.__reserved2 = static_cast<u16>(13);

        TEST_ASSERT_EQUALS(temp.value16, 0xDDE7);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressLinkControl2");
    {
        PciExpressLinkControl2 temp;



        // PciExpressLinkControl2:
        //
        // |     HHHH      | G | F |  EE   |
        // | E | D | C | B |     AAAA      |
        //
        // targetLinkSpeed                : 4  'A'
        // enterCompliance                : 1  'B'
        // hardwareAutonomousSpeedDisable : 1  'C'
        // selectableDeemphasis           : 1  'D'
        // transmitMargin                 : 3  'E'
        // enterModifiedCompliance        : 1  'F'
        // complianceSos                  : 1  'G'
        // complianceDeemphasis           : 4  'H'



        // |     0011      | 0 | 0 |  01   |
        // | 1 | 0 | 1 | 1 |     0111      |
        temp.value16 = 0x31B7;

        TEST_ASSERT_EQUALS(temp.targetLinkSpeed,                static_cast<u16>(7));
        TEST_ASSERT_EQUALS(temp.enterCompliance,                static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.hardwareAutonomousSpeedDisable, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.selectableDeemphasis,           static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.transmitMargin,                 static_cast<u16>(3));
        TEST_ASSERT_EQUALS(temp.enterModifiedCompliance,        static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.complianceSos,                  static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.complianceDeemphasis,           static_cast<u16>(3));



        // |     0011      | 0 | 0 |  01   |
        // | 1 | 0 | 1 | 1 |     1000      |
        temp.targetLinkSpeed = static_cast<u16>(8);

        TEST_ASSERT_EQUALS(temp.value16, 0x31B8);



        // |     0011      | 0 | 0 |  01   |
        // | 1 | 0 | 1 | 0 |     1000      |
        temp.enterCompliance = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x31A8);



        // |     0011      | 0 | 0 |  01   |
        // | 1 | 0 | 0 | 0 |     1000      |
        temp.hardwareAutonomousSpeedDisable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x3188);



        // |     0011      | 0 | 0 |  01   |
        // | 1 | 1 | 0 | 0 |     1000      |
        temp.selectableDeemphasis = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x31C8);



        // |     0011      | 0 | 0 |  10   |
        // | 0 | 1 | 0 | 0 |     1000      |
        temp.transmitMargin = static_cast<u16>(4);

        TEST_ASSERT_EQUALS(temp.value16, 0x3248);



        // |     0011      | 0 | 1 |  10   |
        // | 0 | 1 | 0 | 0 |     1000      |
        temp.enterModifiedCompliance = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3648);



        // |     0011      | 1 | 1 |  10   |
        // | 0 | 1 | 0 | 0 |     1000      |
        temp.complianceSos = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3E48);



        // |     1100      | 1 | 1 |  10   |
        // | 0 | 1 | 0 | 0 |     1000      |
        temp.complianceDeemphasis = static_cast<u16>(12);

        TEST_ASSERT_EQUALS(temp.value16, 0xCE48);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressLinkStatus");
    {
        PciExpressLinkStatus temp;



        // PciExpressLinkStatus:
        //
        // | H | G | F | E | D | C |  BB   |
        // |     BBBB      |     AAAA      |
        //
        // currentLinkSpeed              : 4  'A'
        // negotiatedLinkWidth           : 6  'B'
        // undefined                     : 1  'C'
        // linkTraining                  : 1  'D'
        // slotClockConfiguration        : 1  'E'
        // dataLinkLayerLinkActive       : 1  'F'
        // linkBandwidthManagementStatus : 1  'G'
        // linkAutonomousBandwidthStatus : 1  'H'



        // | 1 | 1 | 0 | 1 | 1 | 1 |  11   |
        // |     0010      |     1010      |
        temp.value16 = 0xDF2A;

        TEST_ASSERT_EQUALS(temp.currentLinkSpeed,              static_cast<u16>(10));
        TEST_ASSERT_EQUALS(temp.negotiatedLinkWidth,           static_cast<u16>(50));
        TEST_ASSERT_EQUALS(temp.undefined,                     static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.linkTraining,                  static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.slotClockConfiguration,        static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.dataLinkLayerLinkActive,       static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.linkBandwidthManagementStatus, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.linkAutonomousBandwidthStatus, static_cast<u16>(1));



        // | 1 | 1 | 0 | 1 | 1 | 1 |  11   |
        // |     0010      |     0101      |
        temp.currentLinkSpeed = static_cast<u16>(5);

        TEST_ASSERT_EQUALS(temp.value16, 0xDF25);



        // | 1 | 1 | 0 | 1 | 1 | 1 |  00   |
        // |     1101      |     0101      |
        temp.negotiatedLinkWidth = static_cast<u16>(13);

        TEST_ASSERT_EQUALS(temp.value16, 0xDCD5);



        // | 1 | 1 | 0 | 1 | 1 | 0 |  00   |
        // |     1101      |     0101      |
        temp.undefined = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xD8D5);



        // | 1 | 1 | 0 | 1 | 0 | 0 |  00   |
        // |     1101      |     0101      |
        temp.linkTraining = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xD0D5);



        // | 1 | 1 | 0 | 0 | 0 | 0 |  00   |
        // |     1101      |     0101      |
        temp.slotClockConfiguration = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xC0D5);



        // | 1 | 1 | 1 | 0 | 0 | 0 |  00   |
        // |     1101      |     0101      |
        temp.dataLinkLayerLinkActive = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xE0D5);



        // | 1 | 0 | 1 | 0 | 0 | 0 |  00   |
        // |     1101      |     0101      |
        temp.linkBandwidthManagementStatus = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xA0D5);



        // | 0 | 0 | 1 | 0 | 0 | 0 |  00   |
        // |     1101      |     0101      |
        temp.linkAutonomousBandwidthStatus = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x20D5);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressLinkStatus2");
    {
        PciExpressLinkStatus2 temp;



        // PciExpressLinkStatus2:
        //
        // |           GGGGGGGG            |
        // |  GG   | F | E | D | C | B | A |
        //
        // currentDeemphasisLevel       : 1  'A'
        // equalizationComplete         : 1  'B'
        // equalizationPhase1Successful : 1  'C'
        // equalizationPhase2Successful : 1  'D'
        // equalizationPhase3Successful : 1  'E'
        // linkEqualizationRequest      : 1  'F'
        // __reserved                   : 10 'G'



        // |           00011110            |
        // |  01   | 1 | 0 | 1 | 1 | 1 | 1 |
        temp.value16 = 0x1E6F;

        TEST_ASSERT_EQUALS(temp.currentDeemphasisLevel,       static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.equalizationComplete,         static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.equalizationPhase1Successful, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.equalizationPhase2Successful, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.equalizationPhase3Successful, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.linkEqualizationRequest,      static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,                   static_cast<u16>(121));



        // |           00011110            |
        // |  01   | 1 | 0 | 1 | 1 | 1 | 0 |
        temp.currentDeemphasisLevel = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x1E6E);



        // |           00011110            |
        // |  01   | 1 | 0 | 1 | 1 | 0 | 0 |
        temp.equalizationComplete = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x1E6C);



        // |           00011110            |
        // |  01   | 1 | 0 | 1 | 0 | 0 | 0 |
        temp.equalizationPhase1Successful = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x1E68);



        // |           00011110            |
        // |  01   | 1 | 0 | 0 | 0 | 0 | 0 |
        temp.equalizationPhase2Successful = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x1E60);



        // |           00011110            |
        // |  01   | 1 | 1 | 0 | 0 | 0 | 0 |
        temp.equalizationPhase3Successful = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x1E70);



        // |           00011110            |
        // |  01   | 0 | 1 | 0 | 0 | 0 | 0 |
        temp.linkEqualizationRequest = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x1E50);



        // |           11100001            |
        // |  10   | 0 | 1 | 0 | 0 | 0 | 0 |
        temp.__reserved = static_cast<u16>(902);

        TEST_ASSERT_EQUALS(temp.value16, 0xE190);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressMulticastBaseAddressRegister");
    {
        PciExpressMulticastBaseAddressRegister temp;



        // PciExpressMulticastBaseAddressRegister:
        //
        // |           CCCCCCCC            |
        // |           CCCCCCCC            |
        // |           CCCCCCCC            |
        // |           CCCCCCCC            |
        // |           CCCCCCCC            |
        // |           CCCCCCCC            |
        // |     CCCC      |     BBBB      |
        // |  BB   |        AAAAAA         |
        //
        // mcIndexPosition : 6  'A'
        // __reserved      : 6  'B'
        // mcBaseAddress   : 52 'C'



        // |           11111010            |
        // |           11111110            |
        // |           11111010            |
        // |           00011111            |
        // |           00011110            |
        // |           01101111            |
        // |     1000      |     1111      |
        // |  10   |        101111         |
        temp.value64 = 0xFAFEFA1F1E6F8FAF;

        TEST_ASSERT_EQUALS(temp.mcIndexPosition, static_cast<u64>(47));
        TEST_ASSERT_EQUALS(temp.__reserved,      static_cast<u64>(62));
        TEST_ASSERT_EQUALS(temp.mcBaseAddress,   static_cast<u64>(4415568399689464));



        // |           11111010            |
        // |           11111110            |
        // |           11111010            |
        // |           00011111            |
        // |           00011110            |
        // |           01101111            |
        // |     1000      |     1111      |
        // |  10   |        010000         |
        temp.mcIndexPosition = static_cast<u64>(16);

        TEST_ASSERT_EQUALS(temp.value64, 0xFAFEFA1F1E6F8F90);



        // |           11111010            |
        // |           11111110            |
        // |           11111010            |
        // |           00011111            |
        // |           00011110            |
        // |           01101111            |
        // |     1000      |     0000      |
        // |  01   |        010000         |
        temp.__reserved = static_cast<u64>(1);

        TEST_ASSERT_EQUALS(temp.value64, 0xFAFEFA1F1E6F8050);



        // |           00000101            |
        // |           00000001            |
        // |           00000101            |
        // |           11100000            |
        // |           11100001            |
        // |           10010000            |
        // |     0111      |     0000      |
        // |  01   |        010000         |
        temp.mcBaseAddress = static_cast<u64>(88031227681031);

        TEST_ASSERT_EQUALS(temp.value64, 0x050105E0E1907050);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressMulticastCapabilityRegister");
    {
        PciExpressMulticastCapabilityRegister temp;



        // PciExpressMulticastCapabilityRegister:
        //
        // | E | D |        CCCCCC         |
        // |  BB   |        AAAAAA         |
        //
        // mcMaxGroup                  : 6  'A'
        // __reserved                  : 2  'B'
        // mcWindowSizeRequested       : 6  'C'
        // __reserved2                 : 1  'D'
        // mcEcrcRegenerationSupported : 1  'E'



        // | 0 | 1 |        110111         |
        // |  00   |        110111         |
        temp.value16 = 0x7737;

        TEST_ASSERT_EQUALS(temp.mcMaxGroup,                  static_cast<u16>(55));
        TEST_ASSERT_EQUALS(temp.__reserved,                  static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.mcWindowSizeRequested,       static_cast<u16>(55));
        TEST_ASSERT_EQUALS(temp.__reserved2,                 static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.mcEcrcRegenerationSupported, static_cast<u16>(0));



        // | 0 | 1 |        110111         |
        // |  00   |        001000         |
        temp.mcMaxGroup = static_cast<u16>(8);

        TEST_ASSERT_EQUALS(temp.value16, 0x7708);



        // | 0 | 1 |        110111         |
        // |  11   |        001000         |
        temp.__reserved = static_cast<u16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x77C8);



        // | 0 | 1 |        001000         |
        // |  11   |        001000         |
        temp.mcWindowSizeRequested = static_cast<u16>(8);

        TEST_ASSERT_EQUALS(temp.value16, 0x48C8);



        // | 0 | 0 |        001000         |
        // |  11   |        001000         |
        temp.__reserved2 = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x08C8);



        // | 1 | 0 |        001000         |
        // |  11   |        001000         |
        temp.mcEcrcRegenerationSupported = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x88C8);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressMulticastControlRegister");
    {
        PciExpressMulticastControlRegister temp;



        // PciExpressMulticastControlRegister:
        //
        // | C |          BBBBBBB          |
        // |  BB   |        AAAAAA         |
        //
        // mcNumGroup : 6  'A'
        // __reserved : 9  'B'
        // mcEnable   : 1  'C'



        // | 0 |          0010001          |
        // |  10   |        011100         |
        temp.value16 = 0x119C;

        TEST_ASSERT_EQUALS(temp.mcNumGroup, static_cast<u16>(28));
        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u16>(70));
        TEST_ASSERT_EQUALS(temp.mcEnable,   static_cast<u16>(0));



        // | 0 |          0010001          |
        // |  10   |        100011         |
        temp.mcNumGroup = static_cast<u16>(35);

        TEST_ASSERT_EQUALS(temp.value16, 0x11A3);



        // | 0 |          1101110          |
        // |  01   |        100011         |
        temp.__reserved = static_cast<u16>(441);

        TEST_ASSERT_EQUALS(temp.value16, 0x6E63);



        // | 1 |          1101110          |
        // |  01   |        100011         |
        temp.mcEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xEE63);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressMulticastOverlayBaseAddressRegister");
    {
        PciExpressMulticastOverlayBaseAddressRegister temp;



        // PciExpressMulticastOverlayBaseAddressRegister:
        //
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |  BB   |        AAAAAA         |
        //
        // mcOverlaySize        : 6  'A'
        // mcOverlayBaseAddress : 58 'B'



        // |           10101110            |
        // |           00011000            |
        // |           10111001            |
        // |           10010101            |
        // |           10101110            |
        // |           11001001            |
        // |           00110010            |
        // |  10   |        010101         |
        temp.value64 = 0xAE18B995AEC93295;

        TEST_ASSERT_EQUALS(temp.mcOverlaySize,        static_cast<u64>(21));
        TEST_ASSERT_EQUALS(temp.mcOverlayBaseAddress, static_cast<u64>(196015325227721930));



        // |           10101110            |
        // |           00011000            |
        // |           10111001            |
        // |           10010101            |
        // |           10101110            |
        // |           11001001            |
        // |           00110010            |
        // |  10   |        101010         |
        temp.mcOverlaySize = static_cast<u64>(42);

        TEST_ASSERT_EQUALS(temp.value64, 0xAE18B995AEC932AA);



        // |           01010001            |
        // |           11100111            |
        // |           01000110            |
        // |           01101010            |
        // |           01010001            |
        // |           00110110            |
        // |           11001101            |
        // |  01   |        101010         |
        temp.mcOverlayBaseAddress = static_cast<u64>(92215050923989813);

        TEST_ASSERT_EQUALS(temp.value64, 0x51E7466A5136CD6A);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressPowerBudgetingData");
    {
        PciExpressPowerBudgetingData temp;



        // PciExpressPowerBudgetingData:
        //
        // |           GGGGGGGG            |
        // |    GGG    |    FFF    |  EE   |
        // | E |  DD   |    CCC    |  BB   |
        // |           AAAAAAAA            |
        //
        // basePower  : 8  'A'
        // dataScale  : 2  'B'
        // pmSubState : 3  'C'
        // pmState    : 2  'D'
        // type       : 3  'E'
        // powerRail  : 3  'F'
        // __reserved : 11 'G'



        // |           10010001            |
        // |    110    |    100    |  00   |
        // | 1 |  10   |    110    |  10   |
        // |           11001010            |
        temp.value32 = 0x91D0DACA;

        TEST_ASSERT_EQUALS(temp.basePower,  static_cast<u32>(202));
        TEST_ASSERT_EQUALS(temp.dataScale,  static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.pmSubState, static_cast<u32>(6));
        TEST_ASSERT_EQUALS(temp.pmState,    static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.type,       static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.powerRail,  static_cast<u32>(4));
        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u32>(1166));



        // |           10010001            |
        // |    110    |    100    |  00   |
        // | 1 |  10   |    110    |  10   |
        // |           00110101            |
        temp.basePower = static_cast<u32>(53);

        TEST_ASSERT_EQUALS(temp.value32, 0x91D0DA35);



        // |           10010001            |
        // |    110    |    100    |  00   |
        // | 1 |  10   |    110    |  01   |
        // |           00110101            |
        temp.dataScale = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x91D0D935);



        // |           10010001            |
        // |    110    |    100    |  00   |
        // | 1 |  10   |    001    |  01   |
        // |           00110101            |
        temp.pmSubState = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x91D0C535);



        // |           10010001            |
        // |    110    |    100    |  00   |
        // | 1 |  01   |    001    |  01   |
        // |           00110101            |
        temp.pmState = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x91D0A535);



        // |           10010001            |
        // |    110    |    100    |  11   |
        // | 0 |  01   |    001    |  01   |
        // |           00110101            |
        temp.type = static_cast<u32>(6);

        TEST_ASSERT_EQUALS(temp.value32, 0x91D32535);



        // |           10010001            |
        // |    110    |    011    |  11   |
        // | 0 |  01   |    001    |  01   |
        // |           00110101            |
        temp.powerRail = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x91CF2535);



        // |           01101110            |
        // |    001    |    011    |  11   |
        // | 0 |  01   |    001    |  01   |
        // |           00110101            |
        temp.__reserved = static_cast<u32>(881);

        TEST_ASSERT_EQUALS(temp.value32, 0x6E2F2535);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressResizableBaseAddressControl");
    {
        PciExpressResizableBaseAddressControl temp;



        // PciExpressResizableBaseAddressControl:
        //
        // |           EEEEEEEE            |
        // |           EEEEEEEE            |
        // |    EEE    |       DDDDD       |
        // |    CCC    |  BB   |    AAA    |
        //
        // barIndex              : 3  'A'
        // __reserved            : 2  'B'
        // numberOfResizableBars : 3  'C'
        // barSize               : 5  'D'
        // __reserved2           : 19 'E'



        // |           01011001            |
        // |           10111001            |
        // |    011    |       00001       |
        // |    101    |  01   |    101    |
        temp.value32 = 0x59B961AD;

        TEST_ASSERT_EQUALS(temp.barIndex,              static_cast<u32>(5));
        TEST_ASSERT_EQUALS(temp.__reserved,            static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.numberOfResizableBars, static_cast<u32>(5));
        TEST_ASSERT_EQUALS(temp.barSize,               static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved2,           static_cast<u32>(183755));



        // |           01011001            |
        // |           10111001            |
        // |    011    |       00001       |
        // |    101    |  01   |    010    |
        temp.barIndex = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x59B961AA);



        // |           01011001            |
        // |           10111001            |
        // |    011    |       00001       |
        // |    101    |  10   |    010    |
        temp.__reserved = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x59B961B2);



        // |           01011001            |
        // |           10111001            |
        // |    011    |       00001       |
        // |    010    |  10   |    010    |
        temp.numberOfResizableBars = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x59B96152);



        // |           01011001            |
        // |           10111001            |
        // |    011    |       11110       |
        // |    010    |  10   |    010    |
        temp.barSize = static_cast<u32>(30);

        TEST_ASSERT_EQUALS(temp.value32, 0x59B97E52);



        // |           10100110            |
        // |           01000110            |
        // |    100    |       11110       |
        // |    010    |  10   |    010    |
        temp.__reserved2 = static_cast<u32>(340532);

        TEST_ASSERT_EQUALS(temp.value32, 0xA6469E52);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressRootComplexInternalLinkControlLinkCapabilities");
    {
        PciExpressRootComplexInternalLinkControlLinkCapabilities temp;



        // PciExpressRootComplexInternalLinkControlLinkCapabilities:
        //
        // |           FFFFFFFF            |
        // |        FFFFFF         |  EE   |
        // | E |    DDD    |  CC   |  BB   |
        // |     BBBB      |     AAAA      |
        //
        // supportedLinkSpeeds : 4  'A'
        // maximumLinkWidth    : 6  'B'
        // aspmSupport         : 2  'C'
        // l0sExitLatency      : 3  'D'
        // l1ExitLatency       : 3  'E'
        // __reserved          : 14 'F'



        // |           10101001            |
        // |        001001         |  01   |
        // | 0 |    101    |  01   |  10   |
        // |     0000      |     0111      |
        temp.value32 = 0xA9255607;

        TEST_ASSERT_EQUALS(temp.supportedLinkSpeeds, static_cast<u32>(7));
        TEST_ASSERT_EQUALS(temp.maximumLinkWidth,    static_cast<u32>(32));
        TEST_ASSERT_EQUALS(temp.aspmSupport,         static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.l0sExitLatency,      static_cast<u32>(5));
        TEST_ASSERT_EQUALS(temp.l1ExitLatency,       static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.__reserved,          static_cast<u32>(10825));



        // |           10101001            |
        // |        001001         |  01   |
        // | 0 |    101    |  01   |  10   |
        // |     0000      |     1000      |
        temp.supportedLinkSpeeds = static_cast<u32>(8);

        TEST_ASSERT_EQUALS(temp.value32, 0xA9255608);



        // |           10101001            |
        // |        001001         |  01   |
        // | 0 |    101    |  01   |  01   |
        // |     1111      |     1000      |
        temp.maximumLinkWidth = static_cast<u32>(31);

        TEST_ASSERT_EQUALS(temp.value32, 0xA92555F8);



        // |           10101001            |
        // |        001001         |  01   |
        // | 0 |    101    |  10   |  01   |
        // |     1111      |     1000      |
        temp.aspmSupport = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0xA92559F8);



        // |           10101001            |
        // |        001001         |  01   |
        // | 0 |    010    |  10   |  01   |
        // |     1111      |     1000      |
        temp.l0sExitLatency = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0xA92529F8);



        // |           10101001            |
        // |        001001         |  10   |
        // | 1 |    010    |  10   |  01   |
        // |     1111      |     1000      |
        temp.l1ExitLatency = static_cast<u32>(5);

        TEST_ASSERT_EQUALS(temp.value32, 0xA926A9F8);



        // |           01010110            |
        // |        110110         |  10   |
        // | 1 |    010    |  10   |  01   |
        // |     1111      |     1000      |
        temp.__reserved = static_cast<u32>(5558);

        TEST_ASSERT_EQUALS(temp.value32, 0x56DAA9F8);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressRootComplexInternalLinkControlLinkControl");
    {
        PciExpressRootComplexInternalLinkControlLinkControl temp;



        // PciExpressRootComplexInternalLinkControlLinkControl:
        //
        // |           DDDDDDDD            |
        // | C |       BBBBB       |  AA   |
        //
        // aspmControl   : 2  'A'
        // __reserved    : 5  'B'
        // extendedSynch : 1  'C'
        // __reserved2   : 8  'D'



        // |           11110101            |
        // | 1 |       01111       |  10   |
        temp.value16 = 0xF5BE;

        TEST_ASSERT_EQUALS(temp.aspmControl,   static_cast<u16>(2));
        TEST_ASSERT_EQUALS(temp.__reserved,    static_cast<u16>(15));
        TEST_ASSERT_EQUALS(temp.extendedSynch, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved2,   static_cast<u16>(245));



        // |           11110101            |
        // | 1 |       01111       |  01   |
        temp.aspmControl = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xF5BD);



        // |           11110101            |
        // | 1 |       10000       |  01   |
        temp.__reserved = static_cast<u16>(16);

        TEST_ASSERT_EQUALS(temp.value16, 0xF5C1);



        // |           11110101            |
        // | 0 |       10000       |  01   |
        temp.extendedSynch = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xF541);



        // |           00001010            |
        // | 0 |       10000       |  01   |
        temp.__reserved2 = static_cast<u16>(10);

        TEST_ASSERT_EQUALS(temp.value16, 0x0A41);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressRootComplexInternalLinkControlLinkStatus");
    {
        PciExpressRootComplexInternalLinkControlLinkStatus temp;



        // PciExpressRootComplexInternalLinkControlLinkStatus:
        //
        // |        CCCCCC         |  BB   |
        // |     BBBB      |     AAAA      |
        //
        // currentLinkSpeed    : 4  'A'
        // negotiatedLinkWidth : 6  'B'
        // __reserved          : 6  'C'



        // |        110000         |  01   |
        // |     1011      |     1000      |
        temp.value16 = 0xC1B8;

        TEST_ASSERT_EQUALS(temp.currentLinkSpeed,    static_cast<u16>(8));
        TEST_ASSERT_EQUALS(temp.negotiatedLinkWidth, static_cast<u16>(27));
        TEST_ASSERT_EQUALS(temp.__reserved,          static_cast<u16>(48));



        // |        110000         |  01   |
        // |     1011      |     0111      |
        temp.currentLinkSpeed = static_cast<u16>(7);

        TEST_ASSERT_EQUALS(temp.value16, 0xC1B7);



        // |        110000         |  10   |
        // |     0100      |     0111      |
        temp.negotiatedLinkWidth = static_cast<u16>(36);

        TEST_ASSERT_EQUALS(temp.value16, 0xC247);



        // |        001111         |  10   |
        // |     0100      |     0111      |
        temp.__reserved = static_cast<u16>(15);

        TEST_ASSERT_EQUALS(temp.value16, 0x3E47);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressRootComplexLinkDeclarationElementSelfDescription");
    {
        PciExpressRootComplexLinkDeclarationElementSelfDescription temp;



        // PciExpressRootComplexLinkDeclarationElementSelfDescription:
        //
        // |           EEEEEEEE            |
        // |           DDDDDDDD            |
        // |           CCCCCCCC            |
        // |     BBBB      |     AAAA      |
        //
        // elementType         : 4  'A'
        // __reserved          : 4  'B'
        // numberOfLinkEntries : 8  'C'
        // componentId         : 8  'D'
        // portNumber          : 8  'E'



        // |           10011000            |
        // |           00100000            |
        // |           11001100            |
        // |     0101      |     0000      |
        temp.value32 = 0x9820CC50;

        TEST_ASSERT_EQUALS(temp.elementType,         static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,          static_cast<u32>(5));
        TEST_ASSERT_EQUALS(temp.numberOfLinkEntries, static_cast<u32>(204));
        TEST_ASSERT_EQUALS(temp.componentId,         static_cast<u32>(32));
        TEST_ASSERT_EQUALS(temp.portNumber,          static_cast<u32>(152));



        // |           10011000            |
        // |           00100000            |
        // |           11001100            |
        // |     0101      |     1111      |
        temp.elementType = static_cast<u32>(15);

        TEST_ASSERT_EQUALS(temp.value32, 0x9820CC5F);



        // |           10011000            |
        // |           00100000            |
        // |           11001100            |
        // |     1010      |     1111      |
        temp.__reserved = static_cast<u32>(10);

        TEST_ASSERT_EQUALS(temp.value32, 0x9820CCAF);



        // |           10011000            |
        // |           00100000            |
        // |           00110011            |
        // |     1010      |     1111      |
        temp.numberOfLinkEntries = static_cast<u32>(51);

        TEST_ASSERT_EQUALS(temp.value32, 0x982033AF);



        // |           10011000            |
        // |           11011111            |
        // |           00110011            |
        // |     1010      |     1111      |
        temp.componentId = static_cast<u32>(223);

        TEST_ASSERT_EQUALS(temp.value32, 0x98DF33AF);



        // |           01100111            |
        // |           11011111            |
        // |           00110011            |
        // |     1010      |     1111      |
        temp.portNumber = static_cast<u32>(103);

        TEST_ASSERT_EQUALS(temp.value32, 0x67DF33AF);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace");
    {
        PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace temp;



        // PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace:
        //
        // |           FFFFFFFF            |
        // |           FFFFFFFF            |
        // |           FFFFFFFF            |
        // |           FFFFFFFF            |
        // |     FFFF      |     EEEE      |
        // |     EEEE      |     DDDD      |
        // | D |    CCC    |     BBBB      |
        // |       BBBBB       |    AAA    |
        //
        // encodedNumberOfBusNumberBits  : 3  'A'
        // __reserved                    : 9  'B'
        // functionNumber                : 3  'C'
        // deviceNumber                  : 5  'D'
        // busNumber                     : 8  'E'
        // configurationSpaceBaseAddress : 36 'F'



        // |           10100011            |
        // |           10011001            |
        // |           11110111            |
        // |           00111101            |
        // |     0111      |     1111      |
        // |     0000      |     1010      |
        // | 0 |    101    |     1101      |
        // |       10010       |    100    |
        temp.value64 = 0xA399F73D7F0A5D94;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBits,  static_cast<u64>(4));
        TEST_ASSERT_EQUALS(temp.__reserved,                    static_cast<u64>(434));
        TEST_ASSERT_EQUALS(temp.functionNumber,                static_cast<u64>(5));
        TEST_ASSERT_EQUALS(temp.deviceNumber,                  static_cast<u64>(20));
        TEST_ASSERT_EQUALS(temp.busNumber,                     static_cast<u64>(240));
        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddress, static_cast<u64>(43916424151));



        // |           10100011            |
        // |           10011001            |
        // |           11110111            |
        // |           00111101            |
        // |     0111      |     1111      |
        // |     0000      |     1010      |
        // | 0 |    101    |     1101      |
        // |       10010       |    011    |
        temp.encodedNumberOfBusNumberBits = static_cast<u64>(3);

        TEST_ASSERT_EQUALS(temp.value64, 0xA399F73D7F0A5D93);



        // |           10100011            |
        // |           10011001            |
        // |           11110111            |
        // |           00111101            |
        // |     0111      |     1111      |
        // |     0000      |     1010      |
        // | 0 |    101    |     0010      |
        // |       01101       |    011    |
        temp.__reserved = static_cast<u64>(77);

        TEST_ASSERT_EQUALS(temp.value64, 0xA399F73D7F0A526B);



        // |           10100011            |
        // |           10011001            |
        // |           11110111            |
        // |           00111101            |
        // |     0111      |     1111      |
        // |     0000      |     1010      |
        // | 0 |    010    |     0010      |
        // |       01101       |    011    |
        temp.functionNumber = static_cast<u64>(2);

        TEST_ASSERT_EQUALS(temp.value64, 0xA399F73D7F0A226B);



        // |           10100011            |
        // |           10011001            |
        // |           11110111            |
        // |           00111101            |
        // |     0111      |     1111      |
        // |     0000      |     0101      |
        // | 1 |    010    |     0010      |
        // |       01101       |    011    |
        temp.deviceNumber = static_cast<u64>(11);

        TEST_ASSERT_EQUALS(temp.value64, 0xA399F73D7F05A26B);



        // |           10100011            |
        // |           10011001            |
        // |           11110111            |
        // |           00111101            |
        // |     0111      |     0000      |
        // |     1111      |     0101      |
        // | 1 |    010    |     0010      |
        // |       01101       |    011    |
        temp.busNumber = static_cast<u64>(15);

        TEST_ASSERT_EQUALS(temp.value64, 0xA399F73D70F5A26B);



        // |           01011100            |
        // |           01100110            |
        // |           00001000            |
        // |           11000010            |
        // |     1000      |     0000      |
        // |     1111      |     0101      |
        // | 1 |    010    |     0010      |
        // |       01101       |    011    |
        temp.configurationSpaceBaseAddress = static_cast<u64>(24803052584);

        TEST_ASSERT_EQUALS(temp.value64, 0x5C6608C280F5A26B);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressRootComplexLinkDeclarationLinkDescription");
    {
        PciExpressRootComplexLinkDeclarationLinkDescription temp;



        // PciExpressRootComplexLinkDeclarationLinkDescription:
        //
        // |           FFFFFFFF            |
        // |           EEEEEEEE            |
        // |           DDDDDDDD            |
        // |       DDDDD       | C | B | A |
        //
        // linkValid           : 1  'A'
        // linkType            : 1  'B'
        // associateRcrbHeader : 1  'C'
        // __reserved          : 13 'D'
        // targetComponentId   : 8  'E'
        // targetPortNumber    : 8  'F'



        // |           01010001            |
        // |           00110100            |
        // |           11100011            |
        // |       11101       | 1 | 0 | 0 |
        temp.value32 = 0x5134E3EC;

        TEST_ASSERT_EQUALS(temp.linkValid,           static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.linkType,            static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.associateRcrbHeader, static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,          static_cast<u32>(7293));
        TEST_ASSERT_EQUALS(temp.targetComponentId,   static_cast<u32>(52));
        TEST_ASSERT_EQUALS(temp.targetPortNumber,    static_cast<u32>(81));



        // |           01010001            |
        // |           00110100            |
        // |           11100011            |
        // |       11101       | 1 | 0 | 1 |
        temp.linkValid = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x5134E3ED);



        // |           01010001            |
        // |           00110100            |
        // |           11100011            |
        // |       11101       | 1 | 1 | 1 |
        temp.linkType = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x5134E3EF);



        // |           01010001            |
        // |           00110100            |
        // |           11100011            |
        // |       11101       | 0 | 1 | 1 |
        temp.associateRcrbHeader = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x5134E3EB);



        // |           01010001            |
        // |           00110100            |
        // |           00011100            |
        // |       00010       | 0 | 1 | 1 |
        temp.__reserved = static_cast<u32>(898);

        TEST_ASSERT_EQUALS(temp.value32, 0x51341C13);



        // |           01010001            |
        // |           11001011            |
        // |           00011100            |
        // |       00010       | 0 | 1 | 1 |
        temp.targetComponentId = static_cast<u32>(203);

        TEST_ASSERT_EQUALS(temp.value32, 0x51CB1C13);



        // |           10101110            |
        // |           11001011            |
        // |           00011100            |
        // |       00010       | 0 | 1 | 1 |
        temp.targetPortNumber = static_cast<u32>(174);

        TEST_ASSERT_EQUALS(temp.value32, 0xAECB1C13);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressRootErrorStatus");
    {
        PciExpressRootErrorStatus temp;



        // PciExpressRootErrorStatus:
        //
        // |       IIIII       |    HHH    |
        // |           HHHHHHHH            |
        // |           HHHHHHHH            |
        // | H | G | F | E | D | C | B | A |
        //
        // errCorReceived                      : 1  'A'
        // multipleErrCorReceived              : 1  'B'
        // errFatalOrNonFatalReceived          : 1  'C'
        // multipleErrFatalOrNonFatalReceived  : 1  'D'
        // firstUncorrectableFatal             : 1  'E'
        // nonFatalErrorMessagesReceived       : 1  'F'
        // fatalErrorMessagesReceived          : 1  'G'
        // __reserved                          : 20 'H'
        // advancedErrorInterruptMessageNumber : 5  'I'



        // |       00000       |    000    |
        // |           01010100            |
        // |           00100011            |
        // | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 0 |
        temp.value32 = 0x005423EC;

        TEST_ASSERT_EQUALS(temp.errCorReceived,                      static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.multipleErrCorReceived,              static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.errFatalOrNonFatalReceived,          static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.multipleErrFatalOrNonFatalReceived,  static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.firstUncorrectableFatal,             static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.nonFatalErrorMessagesReceived,       static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.fatalErrorMessagesReceived,          static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,                          static_cast<u32>(43079));
        TEST_ASSERT_EQUALS(temp.advancedErrorInterruptMessageNumber, static_cast<u32>(0));



        // |       00000       |    000    |
        // |           01010100            |
        // |           00100011            |
        // | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.errCorReceived = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x005423ED);



        // |       00000       |    000    |
        // |           01010100            |
        // |           00100011            |
        // | 1 | 1 | 1 | 0 | 1 | 1 | 1 | 1 |
        temp.multipleErrCorReceived = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x005423EF);



        // |       00000       |    000    |
        // |           01010100            |
        // |           00100011            |
        // | 1 | 1 | 1 | 0 | 1 | 0 | 1 | 1 |
        temp.errFatalOrNonFatalReceived = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x005423EB);



        // |       00000       |    000    |
        // |           01010100            |
        // |           00100011            |
        // | 1 | 1 | 1 | 0 | 0 | 0 | 1 | 1 |
        temp.multipleErrFatalOrNonFatalReceived = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x005423E3);



        // |       00000       |    000    |
        // |           01010100            |
        // |           00100011            |
        // | 1 | 1 | 1 | 1 | 0 | 0 | 1 | 1 |
        temp.firstUncorrectableFatal = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x005423F3);



        // |       00000       |    000    |
        // |           01010100            |
        // |           00100011            |
        // | 1 | 1 | 0 | 1 | 0 | 0 | 1 | 1 |
        temp.nonFatalErrorMessagesReceived = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x005423D3);



        // |       00000       |    000    |
        // |           01010100            |
        // |           00100011            |
        // | 1 | 0 | 0 | 1 | 0 | 0 | 1 | 1 |
        temp.fatalErrorMessagesReceived = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x00542393);



        // |       00000       |    111    |
        // |           10101011            |
        // |           11011100            |
        // | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 1 |
        temp.__reserved = static_cast<u32>(1005496);

        TEST_ASSERT_EQUALS(temp.value32, 0x07ABDC13);



        // |       11111       |    111    |
        // |           10101011            |
        // |           11011100            |
        // | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 1 |
        temp.advancedErrorInterruptMessageNumber = static_cast<u32>(31);

        TEST_ASSERT_EQUALS(temp.value32, 0xFFABDC13);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressRootStatus");
    {
        PciExpressRootStatus temp;



        // PciExpressRootStatus:
        //
        // |           DDDDDDDD            |
        // |        DDDDDD         | C | B |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // pmeRequesterId : 16 'A'
        // pmeStatus      : 1  'B'
        // pmePending     : 1  'C'
        // __reserved     : 14 'D'



        // |           00100100            |
        // |        100100         | 0 | 1 |
        // |           11011011            |
        // |           00100000            |
        temp.value32 = 0x2491DB20;

        TEST_ASSERT_EQUALS(temp.pmeRequesterId, static_cast<u32>(56096));
        TEST_ASSERT_EQUALS(temp.pmeStatus,      static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.pmePending,     static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,     static_cast<u32>(2340));



        // |           00100100            |
        // |        100100         | 0 | 1 |
        // |           00100100            |
        // |           11011111            |
        temp.pmeRequesterId = static_cast<u32>(9439);

        TEST_ASSERT_EQUALS(temp.value32, 0x249124DF);



        // |           00100100            |
        // |        100100         | 0 | 0 |
        // |           00100100            |
        // |           11011111            |
        temp.pmeStatus = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x249024DF);



        // |           00100100            |
        // |        100100         | 1 | 0 |
        // |           00100100            |
        // |           11011111            |
        temp.pmePending = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x249224DF);



        // |           11011011            |
        // |        011011         | 1 | 0 |
        // |           00100100            |
        // |           11011111            |
        temp.__reserved = static_cast<u32>(14043);

        TEST_ASSERT_EQUALS(temp.value32, 0xDB6E24DF);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressSlotCapability");
    {
        PciExpressSlotCapability temp;



        // PciExpressSlotCapability:
        //
        // |           LLLLLLLL            |
        // |       LLLLL       | K | J | I |
        // | I |          HHHHHHH          |
        // | H | G | F | E | D | C | B | A |
        //
        // attentionButtonPresent            : 1  'A'
        // powerControllerPresent            : 1  'B'
        // mrlSensorPresent                  : 1  'C'
        // attentionIndicatorPresent         : 1  'D'
        // powerIndicatorPresent             : 1  'E'
        // hotPlugSurprise                   : 1  'F'
        // hotPlugCapable                    : 1  'G'
        // slotPowerLimitValue               : 8  'H'
        // slotPowerLimitScale               : 2  'I'
        // electromechanicalInterlockPresent : 1  'J'
        // noCommandCompletedSupport         : 1  'K'
        // physicalSlotNumber                : 13 'L'



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          0100100          |
        // | 0 | 1 | 0 | 0 | 1 | 1 | 0 | 1 |
        temp.value32 = 0xF5FE244D;

        TEST_ASSERT_EQUALS(temp.attentionButtonPresent,            static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.powerControllerPresent,            static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.mrlSensorPresent,                  static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.attentionIndicatorPresent,         static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.powerIndicatorPresent,             static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.hotPlugSurprise,                   static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.hotPlugCapable,                    static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.slotPowerLimitValue,               static_cast<u32>(72));
        TEST_ASSERT_EQUALS(temp.slotPowerLimitScale,               static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.electromechanicalInterlockPresent, static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.noCommandCompletedSupport,         static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.physicalSlotNumber,                static_cast<u32>(7871));



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          0100100          |
        // | 0 | 1 | 0 | 0 | 1 | 1 | 0 | 0 |
        temp.attentionButtonPresent = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FE244C);



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          0100100          |
        // | 0 | 1 | 0 | 0 | 1 | 1 | 1 | 0 |
        temp.powerControllerPresent = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FE244E);



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          0100100          |
        // | 0 | 1 | 0 | 0 | 1 | 0 | 1 | 0 |
        temp.mrlSensorPresent = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FE244A);



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          0100100          |
        // | 0 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
        temp.attentionIndicatorPresent = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FE2442);



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          0100100          |
        // | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 0 |
        temp.powerIndicatorPresent = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FE2452);



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          0100100          |
        // | 0 | 1 | 1 | 1 | 0 | 0 | 1 | 0 |
        temp.hotPlugSurprise = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FE2472);



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          0100100          |
        // | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
        temp.hotPlugCapable = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FE2432);



        // |           11110101            |
        // |       11111       | 1 | 1 | 0 |
        // | 0 |          1011011          |
        // | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
        temp.slotPowerLimitValue = static_cast<u32>(183);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FE5BB2);



        // |           11110101            |
        // |       11111       | 1 | 1 | 1 |
        // | 1 |          1011011          |
        // | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
        temp.slotPowerLimitScale = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FFDBB2);



        // |           11110101            |
        // |       11111       | 1 | 0 | 1 |
        // | 1 |          1011011          |
        // | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
        temp.electromechanicalInterlockPresent = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5FDDBB2);



        // |           11110101            |
        // |       11111       | 0 | 0 | 1 |
        // | 1 |          1011011          |
        // | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
        temp.noCommandCompletedSupport = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xF5F9DBB2);



        // |           00001010            |
        // |       00000       | 0 | 0 | 1 |
        // | 1 |          1011011          |
        // | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
        temp.physicalSlotNumber = static_cast<u32>(320);

        TEST_ASSERT_EQUALS(temp.value32, 0x0A01DBB2);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressSlotControl");
    {
        PciExpressSlotControl temp;



        // PciExpressSlotControl:
        //
        // |    LLL    | K | J | I |  HH   |
        // |  GG   | F | E | D | C | B | A |
        //
        // attentionButtonPressedEnable      : 1  'A'
        // powerFaultDetectedEnable          : 1  'B'
        // mrlSensorChangedEnable            : 1  'C'
        // presenceDetectChangedEnable       : 1  'D'
        // commandCompletedInterruptEnable   : 1  'E'
        // hotPlugInterruptEnable            : 1  'F'
        // attentionIndicatorControl         : 2  'G'
        // powerIndicatorControl             : 2  'H'
        // powerControllerControl            : 1  'I'
        // electromechanicalInterlockControl : 1  'J'
        // dataLinkLayerStateChangedEnable   : 1  'K'
        // __reserved                        : 3  'L'



        // |    001    | 1 | 1 | 0 |  01   |
        // |  01   | 0 | 0 | 0 | 1 | 0 | 0 |
        temp.value16 = 0x3944;

        TEST_ASSERT_EQUALS(temp.attentionButtonPressedEnable,      static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.powerFaultDetectedEnable,          static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.mrlSensorChangedEnable,            static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.presenceDetectChangedEnable,       static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.commandCompletedInterruptEnable,   static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.hotPlugInterruptEnable,            static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.attentionIndicatorControl,         static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.powerIndicatorControl,             static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.powerControllerControl,            static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.electromechanicalInterlockControl, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.dataLinkLayerStateChangedEnable,   static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,                        static_cast<u16>(1));



        // |    001    | 1 | 1 | 0 |  01   |
        // |  01   | 0 | 0 | 0 | 1 | 0 | 1 |
        temp.attentionButtonPressedEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3945);



        // |    001    | 1 | 1 | 0 |  01   |
        // |  01   | 0 | 0 | 0 | 1 | 1 | 1 |
        temp.powerFaultDetectedEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3947);



        // |    001    | 1 | 1 | 0 |  01   |
        // |  01   | 0 | 0 | 0 | 0 | 1 | 1 |
        temp.mrlSensorChangedEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x3943);



        // |    001    | 1 | 1 | 0 |  01   |
        // |  01   | 0 | 0 | 1 | 0 | 1 | 1 |
        temp.presenceDetectChangedEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x394B);



        // |    001    | 1 | 1 | 0 |  01   |
        // |  01   | 0 | 1 | 1 | 0 | 1 | 1 |
        temp.commandCompletedInterruptEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x395B);



        // |    001    | 1 | 1 | 0 |  01   |
        // |  01   | 1 | 1 | 1 | 0 | 1 | 1 |
        temp.hotPlugInterruptEnable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x397B);



        // |    001    | 1 | 1 | 0 |  01   |
        // |  10   | 1 | 1 | 1 | 0 | 1 | 1 |
        temp.attentionIndicatorControl = static_cast<u16>(2);

        TEST_ASSERT_EQUALS(temp.value16, 0x39BB);



        // |    001    | 1 | 1 | 0 |  10   |
        // |  10   | 1 | 1 | 1 | 0 | 1 | 1 |
        temp.powerIndicatorControl = static_cast<u16>(2);

        TEST_ASSERT_EQUALS(temp.value16, 0x3ABB);



        // |    001    | 1 | 1 | 1 |  10   |
        // |  10   | 1 | 1 | 1 | 0 | 1 | 1 |
        temp.powerControllerControl = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3EBB);



        // |    001    | 1 | 0 | 1 |  10   |
        // |  10   | 1 | 1 | 1 | 0 | 1 | 1 |
        temp.electromechanicalInterlockControl = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x36BB);



        // |    001    | 0 | 0 | 1 |  10   |
        // |  10   | 1 | 1 | 1 | 0 | 1 | 1 |
        temp.dataLinkLayerStateChangedEnable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x26BB);



        // |    110    | 0 | 0 | 1 |  10   |
        // |  10   | 1 | 1 | 1 | 0 | 1 | 1 |
        temp.__reserved = static_cast<u16>(6);

        TEST_ASSERT_EQUALS(temp.value16, 0xC6BB);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressTphRequesterCapabilityRegister");
    {
        PciExpressTphRequesterCapabilityRegister temp;



        // PciExpressTphRequesterCapabilityRegister:
        //
        // |       IIIII       |    HHH    |
        // |           HHHHHHHH            |
        // |       GGGGG       |  FF   | E |
        // |       DDDDD       | C | B | A |
        //
        // noStModeSupported             : 1  'A'
        // interruptVectorModeSupported  : 1  'B'
        // deviceSpecificModeSupported   : 1  'C'
        // __reserved                    : 5  'D'
        // extendedTphRequesterSupported : 1  'E'
        // stTableLocation               : 2  'F'
        // __reserved2                   : 5  'G'
        // stTableSize                   : 11 'H'
        // __reserved3                   : 5  'I'



        // |       11101       |    101    |
        // |           00111100            |
        // |       00110       |  11   | 1 |
        // |       01011       | 0 | 1 | 1 |
        temp.value32 = 0xED3C375B;

        TEST_ASSERT_EQUALS(temp.noStModeSupported,             static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.interruptVectorModeSupported,  static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.deviceSpecificModeSupported,   static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,                    static_cast<u32>(11));
        TEST_ASSERT_EQUALS(temp.extendedTphRequesterSupported, static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.stTableLocation,               static_cast<u32>(3));
        TEST_ASSERT_EQUALS(temp.__reserved2,                   static_cast<u32>(6));
        TEST_ASSERT_EQUALS(temp.stTableSize,                   static_cast<u32>(1340));
        TEST_ASSERT_EQUALS(temp.__reserved3,                   static_cast<u32>(29));



        // |       11101       |    101    |
        // |           00111100            |
        // |       00110       |  11   | 1 |
        // |       01011       | 0 | 1 | 0 |
        temp.noStModeSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xED3C375A);



        // |       11101       |    101    |
        // |           00111100            |
        // |       00110       |  11   | 1 |
        // |       01011       | 0 | 0 | 0 |
        temp.interruptVectorModeSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xED3C3758);



        // |       11101       |    101    |
        // |           00111100            |
        // |       00110       |  11   | 1 |
        // |       01011       | 1 | 0 | 0 |
        temp.deviceSpecificModeSupported = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xED3C375C);



        // |       11101       |    101    |
        // |           00111100            |
        // |       00110       |  11   | 1 |
        // |       10100       | 1 | 0 | 0 |
        temp.__reserved = static_cast<u32>(20);

        TEST_ASSERT_EQUALS(temp.value32, 0xED3C37A4);



        // |       11101       |    101    |
        // |           00111100            |
        // |       00110       |  11   | 0 |
        // |       10100       | 1 | 0 | 0 |
        temp.extendedTphRequesterSupported = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xED3C36A4);



        // |       11101       |    101    |
        // |           00111100            |
        // |       00110       |  00   | 0 |
        // |       10100       | 1 | 0 | 0 |
        temp.stTableLocation = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xED3C30A4);



        // |       11101       |    101    |
        // |           00111100            |
        // |       11001       |  00   | 0 |
        // |       10100       | 1 | 0 | 0 |
        temp.__reserved2 = static_cast<u32>(25);

        TEST_ASSERT_EQUALS(temp.value32, 0xED3CC8A4);



        // |       11101       |    010    |
        // |           11000011            |
        // |       11001       |  00   | 0 |
        // |       10100       | 1 | 0 | 0 |
        temp.stTableSize = static_cast<u32>(707);

        TEST_ASSERT_EQUALS(temp.value32, 0xEAC3C8A4);



        // |       00010       |    010    |
        // |           11000011            |
        // |       11001       |  00   | 0 |
        // |       10100       | 1 | 0 | 0 |
        temp.__reserved3 = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0x12C3C8A4);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressTphRequesterControlRegister");
    {
        PciExpressTphRequesterControlRegister temp;



        // PciExpressTphRequesterControlRegister:
        //
        // |           DDDDDDDD            |
        // |           DDDDDDDD            |
        // |        DDDDDD         |  CC   |
        // |       BBBBB       |    AAA    |
        //
        // stModeSelect       : 3  'A'
        // __reserved         : 5  'B'
        // tphRequesterEnable : 2  'C'
        // __reserved2        : 22 'D'



        // |           11111000            |
        // |           00100100            |
        // |        101001         |  10   |
        // |       00110       |    000    |
        temp.value32 = 0xF824A630;

        TEST_ASSERT_EQUALS(temp.stModeSelect,       static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,         static_cast<u32>(6));
        TEST_ASSERT_EQUALS(temp.tphRequesterEnable, static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.__reserved2,        static_cast<u32>(4065577));



        // |           11111000            |
        // |           00100100            |
        // |        101001         |  10   |
        // |       00110       |    111    |
        temp.stModeSelect = static_cast<u32>(7);

        TEST_ASSERT_EQUALS(temp.value32, 0xF824A637);



        // |           11111000            |
        // |           00100100            |
        // |        101001         |  10   |
        // |       11001       |    111    |
        temp.__reserved = static_cast<u32>(25);

        TEST_ASSERT_EQUALS(temp.value32, 0xF824A6CF);



        // |           11111000            |
        // |           00100100            |
        // |        101001         |  01   |
        // |       11001       |    111    |
        temp.tphRequesterEnable = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xF824A5CF);



        // |           00000111            |
        // |           11011011            |
        // |        010110         |  01   |
        // |       11001       |    111    |
        temp.__reserved2 = static_cast<u32>(128726);

        TEST_ASSERT_EQUALS(temp.value32, 0x07DB59CF);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressVendorSpecificHeader");
    {
        PciExpressVendorSpecificHeader temp;



        // PciExpressVendorSpecificHeader:
        //
        // |           CCCCCCCC            |
        // |     CCCC      |     BBBB      |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // id       : 16 'A'
        // revision : 4  'B'
        // length   : 12 'C'



        // |           10101011            |
        // |     0111      |     1110      |
        // |           00001101            |
        // |           00101110            |
        temp.value32 = 0xAB7E0D2E;

        TEST_ASSERT_EQUALS(temp.id,       static_cast<u32>(3374));
        TEST_ASSERT_EQUALS(temp.revision, static_cast<u32>(14));
        TEST_ASSERT_EQUALS(temp.length,   static_cast<u32>(2743));



        // |           10101011            |
        // |     0111      |     1110      |
        // |           11110010            |
        // |           11010001            |
        temp.id = static_cast<u32>(62161);

        TEST_ASSERT_EQUALS(temp.value32, 0xAB7EF2D1);



        // |           10101011            |
        // |     0111      |     0001      |
        // |           11110010            |
        // |           11010001            |
        temp.revision = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xAB71F2D1);



        // |           01010100            |
        // |     1000      |     0001      |
        // |           11110010            |
        // |           11010001            |
        temp.length = static_cast<u32>(1352);

        TEST_ASSERT_EQUALS(temp.value32, 0x5481F2D1);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressVirtualChannelPortVirtualChannelCapability1");
    {
        PciExpressVirtualChannelPortVirtualChannelCapability1 temp;



        // PciExpressVirtualChannelPortVirtualChannelCapability1:
        //
        // |           GGGGGGGG            |
        // |           GGGGGGGG            |
        // |     GGGG      |  FF   |  EE   |
        // | D |    CCC    | B |    AAA    |
        //
        // extendedVirtualChannelCount            : 3  'A'
        // __reserved                             : 1  'B'
        // lowPriorityExtendedVirtualChannelCount : 3  'C'
        // __reserved2                            : 1  'D'
        // referenceClock                         : 2  'E'
        // portArbitrationTableEntrySize          : 2  'F'
        // __reserved3                            : 20 'G'



        // |           11001010            |
        // |           11110010            |
        // |     0000      |  11   |  11   |
        // | 1 |    000    | 0 |    100    |
        temp.value32 = 0xCAF20F84;

        TEST_ASSERT_EQUALS(temp.extendedVirtualChannelCount,            static_cast<u32>(4));
        TEST_ASSERT_EQUALS(temp.__reserved,                             static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.lowPriorityExtendedVirtualChannelCount, static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved2,                            static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.referenceClock,                         static_cast<u32>(3));
        TEST_ASSERT_EQUALS(temp.portArbitrationTableEntrySize,          static_cast<u32>(3));
        TEST_ASSERT_EQUALS(temp.__reserved3,                            static_cast<u32>(831264));



        // |           11001010            |
        // |           11110010            |
        // |     0000      |  11   |  11   |
        // | 1 |    000    | 0 |    011    |
        temp.extendedVirtualChannelCount = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0xCAF20F83);



        // |           11001010            |
        // |           11110010            |
        // |     0000      |  11   |  11   |
        // | 1 |    000    | 1 |    011    |
        temp.__reserved = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xCAF20F8B);



        // |           11001010            |
        // |           11110010            |
        // |     0000      |  11   |  11   |
        // | 1 |    111    | 1 |    011    |
        temp.lowPriorityExtendedVirtualChannelCount = static_cast<u32>(7);

        TEST_ASSERT_EQUALS(temp.value32, 0xCAF20FFB);



        // |           11001010            |
        // |           11110010            |
        // |     0000      |  11   |  11   |
        // | 0 |    111    | 1 |    011    |
        temp.__reserved2 = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xCAF20F7B);



        // |           11001010            |
        // |           11110010            |
        // |     0000      |  11   |  00   |
        // | 0 |    111    | 1 |    011    |
        temp.referenceClock = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xCAF20C7B);



        // |           11001010            |
        // |           11110010            |
        // |     0000      |  00   |  00   |
        // | 0 |    111    | 1 |    011    |
        temp.portArbitrationTableEntrySize = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xCAF2007B);



        // |           00110101            |
        // |           00001101            |
        // |     1111      |  00   |  00   |
        // | 0 |    111    | 1 |    011    |
        temp.__reserved3 = static_cast<u32>(217311);

        TEST_ASSERT_EQUALS(temp.value32, 0x350DF07B);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressVirtualChannelPortVirtualChannelCapability2");
    {
        PciExpressVirtualChannelPortVirtualChannelCapability2 temp;



        // PciExpressVirtualChannelPortVirtualChannelCapability2:
        //
        // |           CCCCCCCC            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           AAAAAAAA            |
        //
        // virtualChannelArbitrationCapability  : 8  'A'
        // __reserved                           : 16 'B'
        // virtualChannelArbitrationTableOffset : 8  'C'



        // |           11010100            |
        // |           10101011            |
        // |           01010001            |
        // |           11011001            |
        temp.value32 = 0xD4AB51D9;

        TEST_ASSERT_EQUALS(temp.virtualChannelArbitrationCapability,  static_cast<u32>(217));
        TEST_ASSERT_EQUALS(temp.__reserved,                           static_cast<u32>(43857));
        TEST_ASSERT_EQUALS(temp.virtualChannelArbitrationTableOffset, static_cast<u32>(212));



        // |           11010100            |
        // |           10101011            |
        // |           01010001            |
        // |           00100110            |
        temp.virtualChannelArbitrationCapability = static_cast<u32>(38);

        TEST_ASSERT_EQUALS(temp.value32, 0xD4AB5126);



        // |           11010100            |
        // |           01010100            |
        // |           10101110            |
        // |           00100110            |
        temp.__reserved = static_cast<u32>(21678);

        TEST_ASSERT_EQUALS(temp.value32, 0xD454AE26);



        // |           00101011            |
        // |           01010100            |
        // |           10101110            |
        // |           00100110            |
        temp.virtualChannelArbitrationTableOffset = static_cast<u32>(43);

        TEST_ASSERT_EQUALS(temp.value32, 0x2B54AE26);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressVirtualChannelPortVirtualChannelControl");
    {
        PciExpressVirtualChannelPortVirtualChannelControl temp;



        // PciExpressVirtualChannelPortVirtualChannelControl:
        //
        // |           CCCCCCCC            |
        // |     CCCC      |    BBB    | A |
        //
        // loadVirtualChannelArbitrationTable : 1  'A'
        // virtualChannelArbitrationSelect    : 3  'B'
        // __reserved                         : 12 'C'



        // |           00110001            |
        // |     0111      |    110    | 1 |
        temp.value16 = 0x317D;

        TEST_ASSERT_EQUALS(temp.loadVirtualChannelArbitrationTable, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.virtualChannelArbitrationSelect,    static_cast<u16>(6));
        TEST_ASSERT_EQUALS(temp.__reserved,                         static_cast<u16>(791));



        // |           00110001            |
        // |     0111      |    110    | 0 |
        temp.loadVirtualChannelArbitrationTable = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x317C);



        // |           00110001            |
        // |     0111      |    001    | 0 |
        temp.virtualChannelArbitrationSelect = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3172);



        // |           11001110            |
        // |     1000      |    001    | 0 |
        temp.__reserved = static_cast<u16>(3304);

        TEST_ASSERT_EQUALS(temp.value16, 0xCE82);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressVirtualChannelVirtualChannelResourceCapability");
    {
        PciExpressVirtualChannelVirtualChannelResourceCapability temp;



        // PciExpressVirtualChannelVirtualChannelResourceCapability:
        //
        // |           GGGGGGGG            |
        // | F |          EEEEEEE          |
        // | D | C |        BBBBBB         |
        // |           AAAAAAAA            |
        //
        // portArbitrationCapability  : 8  'A'
        // __reserved                 : 6  'B'
        // undefined                  : 1  'C'
        // rejectSnoopTransactions    : 1  'D'
        // maximumTimeSlots           : 7  'E'
        // __reserved2                : 1  'F'
        // portArbitrationTableOffset : 8  'G'



        // |           11111111            |
        // | 1 |          0111110          |
        // | 0 | 1 |        011111         |
        // |           10010110            |
        temp.value32 = 0xFFBE5F96;

        TEST_ASSERT_EQUALS(temp.portArbitrationCapability,  static_cast<u32>(150));
        TEST_ASSERT_EQUALS(temp.__reserved,                 static_cast<u32>(31));
        TEST_ASSERT_EQUALS(temp.undefined,                  static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.rejectSnoopTransactions,    static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.maximumTimeSlots,           static_cast<u32>(62));
        TEST_ASSERT_EQUALS(temp.__reserved2,                static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.portArbitrationTableOffset, static_cast<u32>(255));



        // |           11111111            |
        // | 1 |          0111110          |
        // | 0 | 1 |        011111         |
        // |           01101001            |
        temp.portArbitrationCapability = static_cast<u32>(105);

        TEST_ASSERT_EQUALS(temp.value32, 0xFFBE5F69);



        // |           11111111            |
        // | 1 |          0111110          |
        // | 0 | 1 |        100000         |
        // |           01101001            |
        temp.__reserved = static_cast<u32>(32);

        TEST_ASSERT_EQUALS(temp.value32, 0xFFBE6069);



        // |           11111111            |
        // | 1 |          0111110          |
        // | 0 | 0 |        100000         |
        // |           01101001            |
        temp.undefined = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xFFBE2069);



        // |           11111111            |
        // | 1 |          0111110          |
        // | 1 | 0 |        100000         |
        // |           01101001            |
        temp.rejectSnoopTransactions = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xFFBEA069);



        // |           11111111            |
        // | 1 |          1000001          |
        // | 1 | 0 |        100000         |
        // |           01101001            |
        temp.maximumTimeSlots = static_cast<u32>(65);

        TEST_ASSERT_EQUALS(temp.value32, 0xFFC1A069);



        // |           11111111            |
        // | 0 |          1000001          |
        // | 1 | 0 |        100000         |
        // |           01101001            |
        temp.__reserved2 = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0xFF41A069);



        // |           00000000            |
        // | 0 |          1000001          |
        // | 1 | 0 |        100000         |
        // |           01101001            |
        temp.portArbitrationTableOffset = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x0041A069);
    }
    TEST_CASE_END();



    TEST_CASE("PciExpressVirtualChannelVirtualChannelResourceControl");
    {
        PciExpressVirtualChannelVirtualChannelResourceControl temp;



        // PciExpressVirtualChannelVirtualChannelResourceControl:
        //
        // | H |     GGGG      |    FFF    |
        // |     EEEE      |    DDD    | C |
        // |           BBBBBBBB            |
        // |           AAAAAAAA            |
        //
        // tcVcMap                  : 8  'A'
        // __reserved               : 8  'B'
        // loadPortArbitrationTable : 1  'C'
        // portArbitrationSelect    : 3  'D'
        // __reserved2              : 4  'E'
        // virtualChannelId         : 3  'F'
        // __reserved3              : 4  'G'
        // virtualChannelEnable     : 1  'H'



        // | 0 |     1110      |    110    |
        // |     1011      |    001    | 1 |
        // |           11100011            |
        // |           01100010            |
        temp.value32 = 0x76B3E362;

        TEST_ASSERT_EQUALS(temp.tcVcMap,                  static_cast<u32>(98));
        TEST_ASSERT_EQUALS(temp.__reserved,               static_cast<u32>(227));
        TEST_ASSERT_EQUALS(temp.loadPortArbitrationTable, static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.portArbitrationSelect,    static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved2,              static_cast<u32>(11));
        TEST_ASSERT_EQUALS(temp.virtualChannelId,         static_cast<u32>(6));
        TEST_ASSERT_EQUALS(temp.__reserved3,              static_cast<u32>(14));
        TEST_ASSERT_EQUALS(temp.virtualChannelEnable,     static_cast<u32>(0));



        // | 0 |     1110      |    110    |
        // |     1011      |    001    | 1 |
        // |           11100011            |
        // |           10011101            |
        temp.tcVcMap = static_cast<u32>(157);

        TEST_ASSERT_EQUALS(temp.value32, 0x76B3E39D);



        // | 0 |     1110      |    110    |
        // |     1011      |    001    | 1 |
        // |           00011100            |
        // |           10011101            |
        temp.__reserved = static_cast<u32>(28);

        TEST_ASSERT_EQUALS(temp.value32, 0x76B31C9D);



        // | 0 |     1110      |    110    |
        // |     1011      |    001    | 0 |
        // |           00011100            |
        // |           10011101            |
        temp.loadPortArbitrationTable = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x76B21C9D);



        // | 0 |     1110      |    110    |
        // |     1011      |    110    | 0 |
        // |           00011100            |
        // |           10011101            |
        temp.portArbitrationSelect = static_cast<u32>(6);

        TEST_ASSERT_EQUALS(temp.value32, 0x76BC1C9D);



        // | 0 |     1110      |    110    |
        // |     0100      |    110    | 0 |
        // |           00011100            |
        // |           10011101            |
        temp.__reserved2 = static_cast<u32>(4);

        TEST_ASSERT_EQUALS(temp.value32, 0x764C1C9D);



        // | 0 |     1110      |    001    |
        // |     0100      |    110    | 0 |
        // |           00011100            |
        // |           10011101            |
        temp.virtualChannelId = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x714C1C9D);



        // | 0 |     0001      |    001    |
        // |     0100      |    110    | 0 |
        // |           00011100            |
        // |           10011101            |
        temp.__reserved3 = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x094C1C9D);



        // | 1 |     0001      |    001    |
        // |     0100      |    110    | 0 |
        // |           00011100            |
        // |           10011101            |
        temp.virtualChannelEnable = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x894C1C9D);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedBridgeSecondaryStatus");
    {
        PciExtendedBridgeSecondaryStatus temp;



        // PciExtendedBridgeSecondaryStatus:
        //
        // |          HHHHHHH          | G |
        // |  GG   | F | E | D | C | B | A |
        //
        // is64BitDevice             : 1  'A'
        // support133MHz             : 1  'B'
        // splitCompletionDiscarded  : 1  'C'
        // unexpectedSplitCompletion : 1  'D'
        // splitCompletionOverrun    : 1  'E'
        // splitRequestDelayed       : 1  'F'
        // secondaryClockFrequency   : 3  'G'
        // __reserved                : 7  'H'



        // |          0101110          | 1 |
        // |  10   | 0 | 1 | 0 | 0 | 1 | 1 |
        temp.value16 = 0x5D93;

        TEST_ASSERT_EQUALS(temp.is64BitDevice,             static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.support133MHz,             static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.splitCompletionDiscarded,  static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.unexpectedSplitCompletion, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.splitCompletionOverrun,    static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.splitRequestDelayed,       static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.secondaryClockFrequency,   static_cast<u16>(6));
        TEST_ASSERT_EQUALS(temp.__reserved,                static_cast<u16>(46));



        // |          0101110          | 1 |
        // |  10   | 0 | 1 | 0 | 0 | 1 | 0 |
        temp.is64BitDevice = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x5D92);



        // |          0101110          | 1 |
        // |  10   | 0 | 1 | 0 | 0 | 0 | 0 |
        temp.support133MHz = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x5D90);



        // |          0101110          | 1 |
        // |  10   | 0 | 1 | 0 | 1 | 0 | 0 |
        temp.splitCompletionDiscarded = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x5D94);



        // |          0101110          | 1 |
        // |  10   | 0 | 1 | 1 | 1 | 0 | 0 |
        temp.unexpectedSplitCompletion = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x5D9C);



        // |          0101110          | 1 |
        // |  10   | 0 | 0 | 1 | 1 | 0 | 0 |
        temp.splitCompletionOverrun = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x5D8C);



        // |          0101110          | 1 |
        // |  10   | 1 | 0 | 1 | 1 | 0 | 0 |
        temp.splitRequestDelayed = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x5DAC);



        // |          0101110          | 0 |
        // |  01   | 1 | 0 | 1 | 1 | 0 | 0 |
        temp.secondaryClockFrequency = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x5C6C);



        // |          1010001          | 0 |
        // |  01   | 1 | 0 | 1 | 1 | 0 | 0 |
        temp.__reserved = static_cast<u16>(81);

        TEST_ASSERT_EQUALS(temp.value16, 0xA26C);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedBridgeStatus");
    {
        PciExtendedBridgeStatus temp;



        // PciExtendedBridgeStatus:
        //
        // |           JJJJJJJJ            |
        // |  JJ   | I | H | G | F | E | D |
        // |           CCCCCCCC            |
        // |       BBBBB       |    AAA    |
        //
        // functionNumber            : 3  'A'
        // deviceNumber              : 5  'B'
        // busNumber                 : 8  'C'
        // is64BitDevice             : 1  'D'
        // support133MHz             : 1  'E'
        // splitCompletionDiscarded  : 1  'F'
        // unexpectedSplitCompletion : 1  'G'
        // splitCompletionOverrun    : 1  'H'
        // splitRequestDelayed       : 1  'I'
        // __reserved                : 10 'J'



        // |           01010010            |
        // |  11   | 1 | 0 | 0 | 0 | 0 | 1 |
        // |           00000000            |
        // |       00010       |    100    |
        temp.value32 = 0x52E10014;

        TEST_ASSERT_EQUALS(temp.functionNumber,            static_cast<u32>(4));
        TEST_ASSERT_EQUALS(temp.deviceNumber,              static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.busNumber,                 static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.is64BitDevice,             static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.support133MHz,             static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.splitCompletionDiscarded,  static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.unexpectedSplitCompletion, static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.splitCompletionOverrun,    static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.splitRequestDelayed,       static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,                static_cast<u32>(331));



        // |           01010010            |
        // |  11   | 1 | 0 | 0 | 0 | 0 | 1 |
        // |           00000000            |
        // |       00010       |    011    |
        temp.functionNumber = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x52E10013);



        // |           01010010            |
        // |  11   | 1 | 0 | 0 | 0 | 0 | 1 |
        // |           00000000            |
        // |       11101       |    011    |
        temp.deviceNumber = static_cast<u32>(29);

        TEST_ASSERT_EQUALS(temp.value32, 0x52E100EB);



        // |           01010010            |
        // |  11   | 1 | 0 | 0 | 0 | 0 | 1 |
        // |           11111111            |
        // |       11101       |    011    |
        temp.busNumber = static_cast<u32>(255);

        TEST_ASSERT_EQUALS(temp.value32, 0x52E1FFEB);



        // |           01010010            |
        // |  11   | 1 | 0 | 0 | 0 | 0 | 0 |
        // |           11111111            |
        // |       11101       |    011    |
        temp.is64BitDevice = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x52E0FFEB);



        // |           01010010            |
        // |  11   | 1 | 0 | 0 | 0 | 1 | 0 |
        // |           11111111            |
        // |       11101       |    011    |
        temp.support133MHz = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x52E2FFEB);



        // |           01010010            |
        // |  11   | 1 | 0 | 0 | 1 | 1 | 0 |
        // |           11111111            |
        // |       11101       |    011    |
        temp.splitCompletionDiscarded = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x52E6FFEB);



        // |           01010010            |
        // |  11   | 1 | 0 | 1 | 1 | 1 | 0 |
        // |           11111111            |
        // |       11101       |    011    |
        temp.unexpectedSplitCompletion = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x52EEFFEB);



        // |           01010010            |
        // |  11   | 1 | 1 | 1 | 1 | 1 | 0 |
        // |           11111111            |
        // |       11101       |    011    |
        temp.splitCompletionOverrun = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x52FEFFEB);



        // |           01010010            |
        // |  11   | 0 | 1 | 1 | 1 | 1 | 0 |
        // |           11111111            |
        // |       11101       |    011    |
        temp.splitRequestDelayed = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x52DEFFEB);



        // |           10101101            |
        // |  00   | 0 | 1 | 1 | 1 | 1 | 0 |
        // |           11111111            |
        // |       11101       |    011    |
        temp.__reserved = static_cast<u32>(692);

        TEST_ASSERT_EQUALS(temp.value32, 0xAD1EFFEB);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedDeviceCommand");
    {
        PciExtendedDeviceCommand temp;



        // PciExtendedDeviceCommand:
        //
        // |           EEEEEEEE            |
        // | E |    DDD    |  CC   | B | A |
        //
        // enableDataParityErrorRecovery       : 1  'A'
        // enableRelaxedOrdering               : 1  'B'
        // maximumMemoryReadByteCount          : 2  'C'
        // maximumOutstandingSplitTransactions : 3  'D'
        // __reserved                          : 9  'E'



        // |           10110100            |
        // | 0 |    111    |  10   | 0 | 0 |
        temp.value16 = 0xB478;

        TEST_ASSERT_EQUALS(temp.enableDataParityErrorRecovery,       static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.enableRelaxedOrdering,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.maximumMemoryReadByteCount,          static_cast<u16>(2));
        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactions, static_cast<u16>(7));
        TEST_ASSERT_EQUALS(temp.__reserved,                          static_cast<u16>(360));



        // |           10110100            |
        // | 0 |    111    |  10   | 0 | 1 |
        temp.enableDataParityErrorRecovery = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xB479);



        // |           10110100            |
        // | 0 |    111    |  10   | 1 | 1 |
        temp.enableRelaxedOrdering = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xB47B);



        // |           10110100            |
        // | 0 |    111    |  01   | 1 | 1 |
        temp.maximumMemoryReadByteCount = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xB477);



        // |           10110100            |
        // | 0 |    000    |  01   | 1 | 1 |
        temp.maximumOutstandingSplitTransactions = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xB407);



        // |           01001011            |
        // | 1 |    000    |  01   | 1 | 1 |
        temp.__reserved = static_cast<u16>(151);

        TEST_ASSERT_EQUALS(temp.value16, 0x4B87);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedDeviceStatus");
    {
        PciExtendedDeviceStatus temp;



        // PciExtendedDeviceStatus:
        //
        // |  MM   | L |    KKK    |  JJ   |
        // | J |  II   | H | G | F | E | D |
        // |           CCCCCCCC            |
        // |       BBBBB       |    AAA    |
        //
        // functionNumber                              : 3  'A'
        // deviceNumber                                : 5  'B'
        // busNumber                                   : 8  'C'
        // is64BitDevice                               : 1  'D'
        // support133MHz                               : 1  'E'
        // splitCompletionDiscarded                    : 1  'F'
        // unexpectedSplitCompletion                   : 1  'G'
        // deviceComplexity                            : 1  'H'
        // designedMaximumMemoryReadByteCount          : 2  'I'
        // designedMaximumOutstandingSplitTransactions : 3  'J'
        // designedMaximumCumulativeReadSize           : 3  'K'
        // receivedSplitCompletionErrorMessage         : 1  'L'
        // __reserved                                  : 2  'M'



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 0 | 1 | 1 | 0 | 0 |
        // |           01110110            |
        // |       11110       |    100    |
        temp.value32 = 0x460C76F4;

        TEST_ASSERT_EQUALS(temp.functionNumber,                              static_cast<u32>(4));
        TEST_ASSERT_EQUALS(temp.deviceNumber,                                static_cast<u32>(30));
        TEST_ASSERT_EQUALS(temp.busNumber,                                   static_cast<u32>(118));
        TEST_ASSERT_EQUALS(temp.is64BitDevice,                               static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.support133MHz,                               static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.splitCompletionDiscarded,                    static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.unexpectedSplitCompletion,                   static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.deviceComplexity,                            static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.designedMaximumMemoryReadByteCount,          static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactions, static_cast<u32>(4));
        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSize,           static_cast<u32>(1));
        TEST_ASSERT_EQUALS(temp.receivedSplitCompletionErrorMessage,         static_cast<u32>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,                                  static_cast<u32>(1));



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 0 | 1 | 1 | 0 | 0 |
        // |           01110110            |
        // |       11110       |    011    |
        temp.functionNumber = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x460C76F3);



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 0 | 1 | 1 | 0 | 0 |
        // |           01110110            |
        // |       00001       |    011    |
        temp.deviceNumber = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x460C760B);



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 0 | 1 | 1 | 0 | 0 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.busNumber = static_cast<u32>(137);

        TEST_ASSERT_EQUALS(temp.value32, 0x460C890B);



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 0 | 1 | 1 | 0 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.is64BitDevice = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x460D890B);



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 0 | 1 | 1 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.support133MHz = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x460F890B);



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 0 | 1 | 0 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.splitCompletionDiscarded = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x460B890B);



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 0 | 0 | 0 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.unexpectedSplitCompletion = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x4603890B);



        // |  01   | 0 |    001    |  10   |
        // | 0 |  00   | 1 | 0 | 0 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.deviceComplexity = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x4613890B);



        // |  01   | 0 |    001    |  10   |
        // | 0 |  11   | 1 | 0 | 0 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.designedMaximumMemoryReadByteCount = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x4673890B);



        // |  01   | 0 |    001    |  01   |
        // | 1 |  11   | 1 | 0 | 0 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.designedMaximumOutstandingSplitTransactions = static_cast<u32>(3);

        TEST_ASSERT_EQUALS(temp.value32, 0x45F3890B);



        // |  01   | 0 |    110    |  01   |
        // | 1 |  11   | 1 | 0 | 0 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.designedMaximumCumulativeReadSize = static_cast<u32>(6);

        TEST_ASSERT_EQUALS(temp.value32, 0x59F3890B);



        // |  01   | 1 |    110    |  01   |
        // | 1 |  11   | 1 | 0 | 0 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.receivedSplitCompletionErrorMessage = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0x79F3890B);



        // |  10   | 1 |    110    |  01   |
        // | 1 |  11   | 1 | 0 | 0 | 1 | 1 |
        // |           10001001            |
        // |       00001       |    011    |
        temp.__reserved = static_cast<u32>(2);

        TEST_ASSERT_EQUALS(temp.value32, 0xB9F3890B);
    }
    TEST_CASE_END();



    TEST_CASE("PciHeaderTypeUnion");
    {
        PciHeaderTypeUnion temp;



        // PciHeaderTypeUnion:
        //
        // | B | AAAAAAA |
        //
        // type            : 7  'A'
        // isMultiFunction : 1  'B'



        // | 0 | 1111111 |
        temp.value8 = 0x7F;

        TEST_ASSERT_EQUALS(temp.type,            static_cast<u8>(127));
        TEST_ASSERT_EQUALS(temp.isMultiFunction, static_cast<u8>(0));



        // | 0 | 0000000 |
        temp.type = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x00);



        // | 1 | 0000000 |
        temp.isMultiFunction = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0x80);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportCommand");
    {
        PciHyperTransportCommand temp;



        // PciHyperTransportCommand:
        //
        // |    BBB    |       AAAAA       |
        // |           AAAAAAAA            |
        //
        // __reserved     : 13 'A'
        // capabilityType : 3  'B'



        // |    011    |       01100       |
        // |           01001001            |
        temp.value16 = 0x6C49;

        TEST_ASSERT_EQUALS(temp.__reserved,     static_cast<u16>(3145));
        TEST_ASSERT_EQUALS(temp.capabilityType, static_cast<u16>(3));



        // |    011    |       10011       |
        // |           10110110            |
        temp.__reserved = static_cast<u16>(5046);

        TEST_ASSERT_EQUALS(temp.value16, 0x73B6);



        // |    100    |       10011       |
        // |           10110110            |
        temp.capabilityType = static_cast<u16>(4);

        TEST_ASSERT_EQUALS(temp.value16, 0x93B6);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportHostSecondaryInterfaceCommand");
    {
        PciHyperTransportHostSecondaryInterfaceCommand temp;



        // PciHyperTransportHostSecondaryInterfaceCommand:
        //
        // |    JJJ    | I | H | G | F | E |
        // | D |       CCCCC       | B | A |
        //
        // warmReset                  : 1  'A'
        // doubleEnded                : 1  'B'
        // deviceNumber               : 5  'C'
        // chainSide                  : 1  'D'
        // hostHide                   : 1  'E'
        // __reserved                 : 1  'F'
        // actAsSlave                 : 1  'G'
        // hostInboundEndOfChainError : 1  'H'
        // dropOnUninit               : 1  'I'
        // capabilityType             : 3  'J'



        // |    001    | 0 | 0 | 1 | 1 | 0 |
        // | 1 |       11001       | 1 | 0 |
        temp.value16 = 0x26E6;

        TEST_ASSERT_EQUALS(temp.warmReset,                  static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.doubleEnded,                static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.deviceNumber,               static_cast<u16>(25));
        TEST_ASSERT_EQUALS(temp.chainSide,                  static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.hostHide,                   static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.__reserved,                 static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.actAsSlave,                 static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.hostInboundEndOfChainError, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.dropOnUninit,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.capabilityType,             static_cast<u16>(1));



        // |    001    | 0 | 0 | 1 | 1 | 0 |
        // | 1 |       11001       | 1 | 1 |
        temp.warmReset = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x26E7);



        // |    001    | 0 | 0 | 1 | 1 | 0 |
        // | 1 |       11001       | 0 | 1 |
        temp.doubleEnded = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x26E5);



        // |    001    | 0 | 0 | 1 | 1 | 0 |
        // | 1 |       00110       | 0 | 1 |
        temp.deviceNumber = static_cast<u16>(6);

        TEST_ASSERT_EQUALS(temp.value16, 0x2699);



        // |    001    | 0 | 0 | 1 | 1 | 0 |
        // | 0 |       00110       | 0 | 1 |
        temp.chainSide = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2619);



        // |    001    | 0 | 0 | 1 | 1 | 1 |
        // | 0 |       00110       | 0 | 1 |
        temp.hostHide = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2719);



        // |    001    | 0 | 0 | 1 | 0 | 1 |
        // | 0 |       00110       | 0 | 1 |
        temp.__reserved = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2519);



        // |    001    | 0 | 0 | 0 | 0 | 1 |
        // | 0 |       00110       | 0 | 1 |
        temp.actAsSlave = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x2119);



        // |    001    | 0 | 1 | 0 | 0 | 1 |
        // | 0 |       00110       | 0 | 1 |
        temp.hostInboundEndOfChainError = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x2919);



        // |    001    | 1 | 1 | 0 | 0 | 1 |
        // | 0 |       00110       | 0 | 1 |
        temp.dropOnUninit = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3919);



        // |    110    | 1 | 1 | 0 | 0 | 1 |
        // | 0 |       00110       | 0 | 1 |
        temp.capabilityType = static_cast<u16>(6);

        TEST_ASSERT_EQUALS(temp.value16, 0xD919);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportLinkConfig");
    {
        PciHyperTransportLinkConfig temp;



        // PciHyperTransportLinkConfig:
        //
        // | H |    GGG    | F |    EEE    |
        // | D |    CCC    | B |    AAA    |
        //
        // maximumLinkWidthIn             : 3  'A'
        // doublewordFlowControlIn        : 1  'B'
        // maximumLinkWidthOut            : 3  'C'
        // doublewordFlowControlOut       : 1  'D'
        // linkWidthIn                    : 3  'E'
        // enableDoublewordFlowControlIn  : 1  'F'
        // linkWidthOut                   : 3  'G'
        // enableDoublewordFlowControlOut : 1  'H'



        // | 0 |    011    | 1 |    010    |
        // | 1 |    100    | 0 |    111    |
        temp.value16 = 0x3AC7;

        TEST_ASSERT_EQUALS(temp.maximumLinkWidthIn,             static_cast<u16>(7));
        TEST_ASSERT_EQUALS(temp.doublewordFlowControlIn,        static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.maximumLinkWidthOut,            static_cast<u16>(4));
        TEST_ASSERT_EQUALS(temp.doublewordFlowControlOut,       static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.linkWidthIn,                    static_cast<u16>(2));
        TEST_ASSERT_EQUALS(temp.enableDoublewordFlowControlIn,  static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.linkWidthOut,                   static_cast<u16>(3));
        TEST_ASSERT_EQUALS(temp.enableDoublewordFlowControlOut, static_cast<u16>(0));



        // | 0 |    011    | 1 |    010    |
        // | 1 |    100    | 0 |    000    |
        temp.maximumLinkWidthIn = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x3AC0);



        // | 0 |    011    | 1 |    010    |
        // | 1 |    100    | 1 |    000    |
        temp.doublewordFlowControlIn = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x3AC8);



        // | 0 |    011    | 1 |    010    |
        // | 1 |    011    | 1 |    000    |
        temp.maximumLinkWidthOut = static_cast<u16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x3AB8);



        // | 0 |    011    | 1 |    010    |
        // | 0 |    011    | 1 |    000    |
        temp.doublewordFlowControlOut = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x3A38);



        // | 0 |    011    | 1 |    101    |
        // | 0 |    011    | 1 |    000    |
        temp.linkWidthIn = static_cast<u16>(5);

        TEST_ASSERT_EQUALS(temp.value16, 0x3D38);



        // | 0 |    011    | 0 |    101    |
        // | 0 |    011    | 1 |    000    |
        temp.enableDoublewordFlowControlIn = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x3538);



        // | 0 |    100    | 0 |    101    |
        // | 0 |    011    | 1 |    000    |
        temp.linkWidthOut = static_cast<u16>(4);

        TEST_ASSERT_EQUALS(temp.value16, 0x4538);



        // | 1 |    100    | 0 |    101    |
        // | 0 |    011    | 1 |    000    |
        temp.enableDoublewordFlowControlOut = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xC538);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportLinkControl");
    {
        PciHyperTransportLinkControl temp;



        // PciHyperTransportLinkControl:
        //
        // | M | L | K | J |     IIII      |
        // | H | G | F | E | D | C | B | A |
        //
        // enableSourceId               : 1  'A'
        // enableCrcFlood               : 1  'B'
        // crcStartTest                 : 1  'C'
        // crcForceError                : 1  'D'
        // linkFailure                  : 1  'E'
        // initializationComplete       : 1  'F'
        // endOfChain                   : 1  'G'
        // transmitterOff               : 1  'H'
        // crcError                     : 4  'I'
        // enableIsochronousFlowControl : 1  'J'
        // enableLdtStopTristate        : 1  'K'
        // extendedCtlTime              : 1  'L'
        // enable64BitAddressing        : 1  'M'



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 0 |
        temp.value16 = 0xEA52;

        TEST_ASSERT_EQUALS(temp.enableSourceId,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.enableCrcFlood,               static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.crcStartTest,                 static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.crcForceError,                static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.linkFailure,                  static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.initializationComplete,       static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.endOfChain,                   static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.transmitterOff,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.crcError,                     static_cast<u16>(10));
        TEST_ASSERT_EQUALS(temp.enableIsochronousFlowControl, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.enableLdtStopTristate,        static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.extendedCtlTime,              static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.enable64BitAddressing,        static_cast<u16>(1));



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 1 |
        temp.enableSourceId = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xEA53);



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 0 | 1 | 0 | 1 | 0 | 0 | 0 | 1 |
        temp.enableCrcFlood = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xEA51);



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |
        temp.crcStartTest = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xEA55);



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 0 | 1 | 0 | 1 | 1 | 1 | 0 | 1 |
        temp.crcForceError = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xEA5D);



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 0 | 1 | 0 | 0 | 1 | 1 | 0 | 1 |
        temp.linkFailure = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xEA4D);



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 0 | 1 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.initializationComplete = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xEA6D);



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.endOfChain = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xEA2D);



        // | 1 | 1 | 1 | 0 |     1010      |
        // | 1 | 0 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.transmitterOff = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xEAAD);



        // | 1 | 1 | 1 | 0 |     0101      |
        // | 1 | 0 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.crcError = static_cast<u16>(5);

        TEST_ASSERT_EQUALS(temp.value16, 0xE5AD);



        // | 1 | 1 | 1 | 1 |     0101      |
        // | 1 | 0 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.enableIsochronousFlowControl = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xF5AD);



        // | 1 | 1 | 0 | 1 |     0101      |
        // | 1 | 0 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.enableLdtStopTristate = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xD5AD);



        // | 1 | 0 | 0 | 1 |     0101      |
        // | 1 | 0 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.extendedCtlTime = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x95AD);



        // | 0 | 0 | 0 | 1 |     0101      |
        // | 1 | 0 | 1 | 0 | 1 | 1 | 0 | 1 |
        temp.enable64BitAddressing = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x15AD);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportLinkErrorAndFrequencyUnion");
    {
        PciHyperTransportLinkErrorAndFrequencyUnion temp;



        // PciHyperTransportLinkErrorAndFrequencyUnion:
        //
        // | BBBB | AAAA |
        //
        // frequency : 4  'A'
        // error     : 4  'B'



        // | 0000 | 0001 |
        temp.value8 = 0x01;

        TEST_ASSERT_EQUALS(temp.frequency, static_cast<u8>(1));
        TEST_ASSERT_EQUALS(temp.error,     static_cast<u8>(0));



        // | 0000 | 1110 |
        temp.frequency = static_cast<u8>(14);

        TEST_ASSERT_EQUALS(temp.value8, 0x0E);



        // | 1111 | 1110 |
        temp.error = static_cast<u8>(15);

        TEST_ASSERT_EQUALS(temp.value8, 0xFE);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportSlavePrimaryInterfaceCommand");
    {
        PciHyperTransportSlavePrimaryInterfaceCommand temp;



        // PciHyperTransportSlavePrimaryInterfaceCommand:
        //
        // |    FFF    | E | D | C |  BB   |
        // |    BBB    |       AAAAA       |
        //
        // baseUnitId       : 5  'A'
        // unitCount        : 5  'B'
        // masterHost       : 1  'C'
        // defaultDirection : 1  'D'
        // dropOnUninit     : 1  'E'
        // capabilityType   : 3  'F'



        // |    100    | 0 | 1 | 0 |  00   |
        // |    101    |       10011       |
        temp.value16 = 0x88B3;

        TEST_ASSERT_EQUALS(temp.baseUnitId,       static_cast<u16>(19));
        TEST_ASSERT_EQUALS(temp.unitCount,        static_cast<u16>(5));
        TEST_ASSERT_EQUALS(temp.masterHost,       static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.defaultDirection, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.dropOnUninit,     static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.capabilityType,   static_cast<u16>(4));



        // |    100    | 0 | 1 | 0 |  00   |
        // |    101    |       01100       |
        temp.baseUnitId = static_cast<u16>(12);

        TEST_ASSERT_EQUALS(temp.value16, 0x88AC);



        // |    100    | 0 | 1 | 0 |  11   |
        // |    010    |       01100       |
        temp.unitCount = static_cast<u16>(26);

        TEST_ASSERT_EQUALS(temp.value16, 0x8B4C);



        // |    100    | 0 | 1 | 1 |  11   |
        // |    010    |       01100       |
        temp.masterHost = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x8F4C);



        // |    100    | 0 | 0 | 1 |  11   |
        // |    010    |       01100       |
        temp.defaultDirection = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x874C);



        // |    100    | 1 | 0 | 1 |  11   |
        // |    010    |       01100       |
        temp.dropOnUninit = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x974C);



        // |    011    | 1 | 0 | 1 |  11   |
        // |    010    |       01100       |
        temp.capabilityType = static_cast<u16>(3);

        TEST_ASSERT_EQUALS(temp.value16, 0x774C);
    }
    TEST_CASE_END();



    TEST_CASE("PciMessageSignaledInterruptsExtendedMessageControl");
    {
        PciMessageSignaledInterruptsExtendedMessageControl temp;



        // PciMessageSignaledInterruptsExtendedMessageControl:
        //
        // | C |     BBBB      |    AAA    |
        // |           AAAAAAAA            |
        //
        // tableSize  : 11 'A'
        // __reserved : 4  'B'
        // enableMSIX : 1  'C'



        // | 1 |     0110      |    101    |
        // |           10110010            |
        temp.value16 = 0xB5B2;

        TEST_ASSERT_EQUALS(temp.tableSize,  static_cast<u16>(1458));
        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u16>(6));
        TEST_ASSERT_EQUALS(temp.enableMSIX, static_cast<u16>(1));



        // | 1 |     0110      |    010    |
        // |           01001101            |
        temp.tableSize = static_cast<u16>(589);

        TEST_ASSERT_EQUALS(temp.value16, 0xB24D);



        // | 1 |     1001      |    010    |
        // |           01001101            |
        temp.__reserved = static_cast<u16>(9);

        TEST_ASSERT_EQUALS(temp.value16, 0xCA4D);



        // | 0 |     1001      |    010    |
        // |           01001101            |
        temp.enableMSIX = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x4A4D);
    }
    TEST_CASE_END();



    TEST_CASE("PciMessageSignaledInterruptsExtendedTableOffsetBirUnion");
    {
        PciMessageSignaledInterruptsExtendedTableOffsetBirUnion temp;



        // PciMessageSignaledInterruptsExtendedTableOffsetBirUnion:
        //
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |       BBBBB       |    AAA    |
        //
        // baseAddressIndicator : 3  'A'
        // tableOffset          : 29 'B'



        // |           00101000            |
        // |           01101100            |
        // |           00111001            |
        // |       11000       |    111    |
        temp.value32 = 0x286C39C7;

        TEST_ASSERT_EQUALS(temp.baseAddressIndicator, static_cast<u32>(7));
        TEST_ASSERT_EQUALS(temp.tableOffset,          static_cast<u32>(84772664));



        // |           00101000            |
        // |           01101100            |
        // |           00111001            |
        // |       11000       |    000    |
        temp.baseAddressIndicator = static_cast<u32>(0);

        TEST_ASSERT_EQUALS(temp.value32, 0x286C39C0);



        // |           11010111            |
        // |           10010011            |
        // |           11000110            |
        // |       00111       |    000    |
        temp.tableOffset = static_cast<u32>(452098247);

        TEST_ASSERT_EQUALS(temp.value32, 0xD793C638);
    }
    TEST_CASE_END();



    TEST_CASE("PciMessageSignaledInterruptsMessageAddress");
    {
        PciMessageSignaledInterruptsMessageAddress temp;



        // PciMessageSignaledInterruptsMessageAddress:
        //
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |           BBBBBBBB            |
        // |        BBBBBB         |  AA   |
        //
        // __reserved : 2  'A'
        // value      : 30 'B'



        // |           11000100            |
        // |           11010100            |
        // |           10101001            |
        // |        101001         |  10   |
        temp.value32 = 0xC4D4A9A6;

        TEST_ASSERT_EQUALS(temp.__reserved, static_cast<u32>(2));
        TEST_ASSERT_EQUALS(temp.value,      static_cast<u32>(825567849));



        // |           11000100            |
        // |           11010100            |
        // |           10101001            |
        // |        101001         |  01   |
        temp.__reserved = static_cast<u32>(1);

        TEST_ASSERT_EQUALS(temp.value32, 0xC4D4A9A5);



        // |           00111011            |
        // |           00101011            |
        // |           01010110            |
        // |        010110         |  01   |
        temp.value = static_cast<u32>(248173974);

        TEST_ASSERT_EQUALS(temp.value32, 0x3B2B5659);
    }
    TEST_CASE_END();



    TEST_CASE("PciMessageSignaledInterruptsMessageControl");
    {
        PciMessageSignaledInterruptsMessageControl temp;



        // PciMessageSignaledInterruptsMessageControl:
        //
        // |          FFFFFFF          | E |
        // | D |    CCC    |    BBB    | A |
        //
        // enableMSI               : 1  'A'
        // supportMultipleMessage  : 3  'B'
        // enableMultipleMessage   : 3  'C'
        // support64BitAddress     : 1  'D'
        // supportPerVectorMasking : 1  'E'
        // __reserved              : 7  'F'



        // |          0111110          | 1 |
        // | 1 |    011    |    011    | 1 |
        temp.value16 = 0x7DB7;

        TEST_ASSERT_EQUALS(temp.enableMSI,               static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.supportMultipleMessage,  static_cast<u16>(3));
        TEST_ASSERT_EQUALS(temp.enableMultipleMessage,   static_cast<u16>(3));
        TEST_ASSERT_EQUALS(temp.support64BitAddress,     static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.supportPerVectorMasking, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,              static_cast<u16>(62));



        // |          0111110          | 1 |
        // | 1 |    011    |    011    | 0 |
        temp.enableMSI = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x7DB6);



        // |          0111110          | 1 |
        // | 1 |    011    |    100    | 0 |
        temp.supportMultipleMessage = static_cast<u16>(4);

        TEST_ASSERT_EQUALS(temp.value16, 0x7DB8);



        // |          0111110          | 1 |
        // | 1 |    100    |    100    | 0 |
        temp.enableMultipleMessage = static_cast<u16>(4);

        TEST_ASSERT_EQUALS(temp.value16, 0x7DC8);



        // |          0111110          | 1 |
        // | 0 |    100    |    100    | 0 |
        temp.support64BitAddress = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x7D48);



        // |          0111110          | 0 |
        // | 0 |    100    |    100    | 0 |
        temp.supportPerVectorMasking = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x7C48);



        // |          1000001          | 0 |
        // | 0 |    100    |    100    | 0 |
        temp.__reserved = static_cast<u16>(65);

        TEST_ASSERT_EQUALS(temp.value16, 0x8248);
    }
    TEST_CASE_END();



    TEST_CASE("PciPowerManagementBridgeSupportExtensions");
    {
        PciPowerManagementBridgeSupportExtensions temp;



        // PciPowerManagementBridgeSupportExtensions:
        //
        // | C | B | AAAAAA |
        //
        // __reserved           : 6  'A'
        // b2B3ForD3Hot         : 1  'B'
        // busPowerClockControl : 1  'C'



        // | 0 | 0 | 010011 |
        temp.value8 = 0x13;

        TEST_ASSERT_EQUALS(temp.__reserved,           static_cast<u8>(19));
        TEST_ASSERT_EQUALS(temp.b2B3ForD3Hot,         static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.busPowerClockControl, static_cast<u8>(0));



        // | 0 | 0 | 101100 |
        temp.__reserved = static_cast<u8>(44);

        TEST_ASSERT_EQUALS(temp.value8, 0x2C);



        // | 0 | 1 | 101100 |
        temp.b2B3ForD3Hot = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0x6C);



        // | 1 | 1 | 101100 |
        temp.busPowerClockControl = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value8, 0xEC);
    }
    TEST_CASE_END();



    TEST_CASE("PciPowerManagementCapabilities");
    {
        PciPowerManagementCapabilities temp;



        // PciPowerManagementCapabilities:
        //
        // |       HHHHH       | G | F | E |
        // |  EE   | D | C | B |    AAA    |
        //
        // version                      : 3  'A'
        // pmeClock                     : 1  'B'
        // __reserved                   : 1  'C'
        // deviceSpecificInitialization : 1  'D'
        // auxCurrent                   : 3  'E'
        // supportD1                    : 1  'F'
        // supportD2                    : 1  'G'
        // supportPme                   : 5  'H'



        // |       11001       | 0 | 0 | 1 |
        // |  10   | 1 | 0 | 1 |    110    |
        temp.value16 = 0xC9AE;

        TEST_ASSERT_EQUALS(temp.version,                      static_cast<u16>(6));
        TEST_ASSERT_EQUALS(temp.pmeClock,                     static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,                   static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.deviceSpecificInitialization, static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.auxCurrent,                   static_cast<u16>(6));
        TEST_ASSERT_EQUALS(temp.supportD1,                    static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.supportD2,                    static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.supportPme,                   static_cast<u16>(25));



        // |       11001       | 0 | 0 | 1 |
        // |  10   | 1 | 0 | 1 |    001    |
        temp.version = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xC9A9);



        // |       11001       | 0 | 0 | 1 |
        // |  10   | 1 | 0 | 0 |    001    |
        temp.pmeClock = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xC9A1);



        // |       11001       | 0 | 0 | 1 |
        // |  10   | 1 | 1 | 0 |    001    |
        temp.__reserved = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xC9B1);



        // |       11001       | 0 | 0 | 1 |
        // |  10   | 0 | 1 | 0 |    001    |
        temp.deviceSpecificInitialization = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xC991);



        // |       11001       | 0 | 0 | 0 |
        // |  01   | 0 | 1 | 0 |    001    |
        temp.auxCurrent = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xC851);



        // |       11001       | 0 | 1 | 0 |
        // |  01   | 0 | 1 | 0 |    001    |
        temp.supportD1 = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xCA51);



        // |       11001       | 1 | 1 | 0 |
        // |  01   | 0 | 1 | 0 |    001    |
        temp.supportD2 = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xCE51);



        // |       00110       | 1 | 1 | 0 |
        // |  01   | 0 | 1 | 0 |    001    |
        temp.supportPme = static_cast<u16>(6);

        TEST_ASSERT_EQUALS(temp.value16, 0x3651);
    }
    TEST_CASE_END();



    TEST_CASE("PciPowerManagementControlStatus");
    {
        PciPowerManagementControlStatus temp;



        // PciPowerManagementControlStatus:
        //
        // | H |  GG   |     FFFF      | E |
        // |     DDDD      | C | B |  AA   |
        //
        // powerState              : 2  'A'
        // __reservedForPciExpress : 1  'B'
        // noSoftReset             : 1  'C'
        // __reserved              : 4  'D'
        // enablePme               : 1  'E'
        // dataSelect              : 4  'F'
        // dataScale               : 2  'G'
        // pmeStatus               : 1  'H'



        // | 1 |  10   |     0010      | 0 |
        // |     1011      | 1 | 0 |  11   |
        temp.value16 = 0xC4BB;

        TEST_ASSERT_EQUALS(temp.powerState,              static_cast<u16>(3));
        TEST_ASSERT_EQUALS(temp.__reservedForPciExpress, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.noSoftReset,             static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,              static_cast<u16>(11));
        TEST_ASSERT_EQUALS(temp.enablePme,               static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.dataSelect,              static_cast<u16>(2));
        TEST_ASSERT_EQUALS(temp.dataScale,               static_cast<u16>(2));
        TEST_ASSERT_EQUALS(temp.pmeStatus,               static_cast<u16>(1));



        // | 1 |  10   |     0010      | 0 |
        // |     1011      | 1 | 0 |  00   |
        temp.powerState = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xC4B8);



        // | 1 |  10   |     0010      | 0 |
        // |     1011      | 1 | 1 |  00   |
        temp.__reservedForPciExpress = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xC4BC);



        // | 1 |  10   |     0010      | 0 |
        // |     1011      | 0 | 1 |  00   |
        temp.noSoftReset = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0xC4B4);



        // | 1 |  10   |     0010      | 0 |
        // |     0100      | 0 | 1 |  00   |
        temp.__reserved = static_cast<u16>(4);

        TEST_ASSERT_EQUALS(temp.value16, 0xC444);



        // | 1 |  10   |     0010      | 1 |
        // |     0100      | 0 | 1 |  00   |
        temp.enablePme = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xC544);



        // | 1 |  10   |     1101      | 1 |
        // |     0100      | 0 | 1 |  00   |
        temp.dataSelect = static_cast<u16>(13);

        TEST_ASSERT_EQUALS(temp.value16, 0xDB44);



        // | 1 |  01   |     1101      | 1 |
        // |     0100      | 0 | 1 |  00   |
        temp.dataScale = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xBB44);



        // | 0 |  01   |     1101      | 1 |
        // |     0100      | 0 | 1 |  00   |
        temp.pmeStatus = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x3B44);
    }
    TEST_CASE_END();



    TEST_CASE("PciSlotNumberingExpansionSlot");
    {
        PciSlotNumberingExpansionSlot temp;



        // PciSlotNumberingExpansionSlot:
        //
        // | CC | B | AAAAA |
        //
        // expansionSlotsProvided : 5  'A'
        // firstInChassis         : 1  'B'
        // __reserved             : 2  'C'



        // | 11 | 1 | 00100 |
        temp.value8 = 0xE4;

        TEST_ASSERT_EQUALS(temp.expansionSlotsProvided, static_cast<u8>(4));
        TEST_ASSERT_EQUALS(temp.firstInChassis,         static_cast<u8>(1));
        TEST_ASSERT_EQUALS(temp.__reserved,             static_cast<u8>(3));



        // | 11 | 1 | 11011 |
        temp.expansionSlotsProvided = static_cast<u8>(27);

        TEST_ASSERT_EQUALS(temp.value8, 0xFB);



        // | 11 | 0 | 11011 |
        temp.firstInChassis = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0xDB);



        // | 00 | 0 | 11011 |
        temp.__reserved = static_cast<u8>(0);

        TEST_ASSERT_EQUALS(temp.value8, 0x1B);
    }
    TEST_CASE_END();



    TEST_CASE("PciStatus");
    {
        PciStatus temp;



        // PciStatus:
        //
        // | M | L | K | J | I |  HH   | G |
        // | F | E | D | C | B |    AAA    |
        //
        // __reserved            : 3  'A'
        // interruptStatus       : 1  'B'
        // capabilitiesList      : 1  'C'
        // support64MHz          : 1  'D'
        // __reserved2           : 1  'E'
        // fastBackToBackCapable : 1  'F'
        // masterDataParityError : 1  'G'
        // deviceSelectTiming    : 2  'H'
        // signaledTargetAbort   : 1  'I'
        // receivedTargetAbort   : 1  'J'
        // receivedMasterAbort   : 1  'K'
        // signaledSystemError   : 1  'L'
        // detectedParityError   : 1  'M'



        // | 1 | 0 | 0 | 1 | 1 |  10   | 0 |
        // | 0 | 0 | 0 | 1 | 0 |    101    |
        temp.value16 = 0x9C15;

        TEST_ASSERT_EQUALS(temp.__reserved,            static_cast<u16>(5));
        TEST_ASSERT_EQUALS(temp.interruptStatus,       static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.capabilitiesList,      static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.support64MHz,          static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.__reserved2,           static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.fastBackToBackCapable, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.masterDataParityError, static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.deviceSelectTiming,    static_cast<u16>(2));
        TEST_ASSERT_EQUALS(temp.signaledTargetAbort,   static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.receivedTargetAbort,   static_cast<u16>(1));
        TEST_ASSERT_EQUALS(temp.receivedMasterAbort,   static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.signaledSystemError,   static_cast<u16>(0));
        TEST_ASSERT_EQUALS(temp.detectedParityError,   static_cast<u16>(1));



        // | 1 | 0 | 0 | 1 | 1 |  10   | 0 |
        // | 0 | 0 | 0 | 1 | 0 |    010    |
        temp.__reserved = static_cast<u16>(2);

        TEST_ASSERT_EQUALS(temp.value16, 0x9C12);



        // | 1 | 0 | 0 | 1 | 1 |  10   | 0 |
        // | 0 | 0 | 0 | 1 | 1 |    010    |
        temp.interruptStatus = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x9C1A);



        // | 1 | 0 | 0 | 1 | 1 |  10   | 0 |
        // | 0 | 0 | 0 | 0 | 1 |    010    |
        temp.capabilitiesList = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x9C0A);



        // | 1 | 0 | 0 | 1 | 1 |  10   | 0 |
        // | 0 | 0 | 1 | 0 | 1 |    010    |
        temp.support64MHz = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x9C2A);



        // | 1 | 0 | 0 | 1 | 1 |  10   | 0 |
        // | 0 | 1 | 1 | 0 | 1 |    010    |
        temp.__reserved2 = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x9C6A);



        // | 1 | 0 | 0 | 1 | 1 |  10   | 0 |
        // | 1 | 1 | 1 | 0 | 1 |    010    |
        temp.fastBackToBackCapable = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x9CEA);



        // | 1 | 0 | 0 | 1 | 1 |  10   | 1 |
        // | 1 | 1 | 1 | 0 | 1 |    010    |
        temp.masterDataParityError = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x9DEA);



        // | 1 | 0 | 0 | 1 | 1 |  01   | 1 |
        // | 1 | 1 | 1 | 0 | 1 |    010    |
        temp.deviceSelectTiming = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x9BEA);



        // | 1 | 0 | 0 | 1 | 0 |  01   | 1 |
        // | 1 | 1 | 1 | 0 | 1 |    010    |
        temp.signaledTargetAbort = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x93EA);



        // | 1 | 0 | 0 | 0 | 0 |  01   | 1 |
        // | 1 | 1 | 1 | 0 | 1 |    010    |
        temp.receivedTargetAbort = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x83EA);



        // | 1 | 0 | 1 | 0 | 0 |  01   | 1 |
        // | 1 | 1 | 1 | 0 | 1 |    010    |
        temp.receivedMasterAbort = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xA3EA);



        // | 1 | 1 | 1 | 0 | 0 |  01   | 1 |
        // | 1 | 1 | 1 | 0 | 1 |    010    |
        temp.signaledSystemError = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xE3EA);



        // | 0 | 1 | 1 | 0 | 0 |  01   | 1 |
        // | 1 | 1 | 1 | 0 | 1 |    010    |
        temp.detectedParityError = static_cast<u16>(0);

        TEST_ASSERT_EQUALS(temp.value16, 0x63EA);
    }
    TEST_CASE_END();



    TEST_CASE("PciVitalProductDataAddressUnion");
    {
        PciVitalProductDataAddressUnion temp;



        // PciVitalProductDataAddressUnion:
        //
        // | B |          AAAAAAA          |
        // |           AAAAAAAA            |
        //
        // value    : 15 'A'
        // finished : 1  'B'



        // | 0 |          0101111          |
        // |           00111010            |
        temp.value16 = 0x2F3A;

        TEST_ASSERT_EQUALS(temp.value,    static_cast<u16>(12090));
        TEST_ASSERT_EQUALS(temp.finished, static_cast<u16>(0));



        // | 0 |          1010000          |
        // |           11000101            |
        temp.value = static_cast<u16>(20677);

        TEST_ASSERT_EQUALS(temp.value16, 0x50C5);



        // | 1 |          1010000          |
        // |           11000101            |
        temp.finished = static_cast<u16>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xD0C5);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedCapabilityHeader");
    {
        PciExtendedCapabilityHeader temp;



        // PciExtendedCapabilityHeader:
        //
        // |           CCCCCCCC            |
        // |     CCCC      |     BBBB      |
        // |           AAAAAAAA            |
        // |           AAAAAAAA            |
        //
        // capabilityId         : 16 'A'
        // capabilityVersion    : 4  'B'
        // nextCapabilityOffset : 12 'C'



        // |           10111100            |
        // |     0110      |     1000      |
        // |           11110010            |
        // |           00010001            |
        temp.value32 = 0xBC68F211;

        TEST_ASSERT_EQUALS(temp.capabilityId,         static_cast<u32>(61969));
        TEST_ASSERT_EQUALS(temp.capabilityVersion,    static_cast<u32>(8));
        TEST_ASSERT_EQUALS(temp.nextCapabilityOffset, static_cast<u32>(3014));



        // |           10111100            |
        // |     0110      |     1000      |
        // |           00001101            |
        // |           11101110            |
        temp.capabilityId = static_cast<u32>(3566);

        TEST_ASSERT_EQUALS(temp.value32, 0xBC680DEE);



        // |           10111100            |
        // |     0110      |     0111      |
        // |           00001101            |
        // |           11101110            |
        temp.capabilityVersion = static_cast<u32>(7);

        TEST_ASSERT_EQUALS(temp.value32, 0xBC670DEE);



        // |           01000011            |
        // |     1001      |     0111      |
        // |           00001101            |
        // |           11101110            |
        temp.nextCapabilityOffset = static_cast<u32>(1081);

        TEST_ASSERT_EQUALS(temp.value32, 0x43970DEE);
    }
    TEST_CASE_END();



    TEST_CASE("ZLibHeader");
    {
        ZLibHeader temp;



        // ZLibHeader:
        //
        // |  EE   | D |       CCCCC       |
        // |     BBBB      |     AAAA      |
        //
        // compressionMethod : 4  'A'
        // compressionInfo   : 4  'B'
        // checkBits         : 5  'C'
        // presetDictionary  : 1  'D'
        // compressionLevel  : 2  'E'



        // |  10   | 0 |       01011       |
        // |     0001      |     1001      |
        temp.value16 = 0x8B19;

        TEST_ASSERT_EQUALS(temp.compressionMethod, static_cast<u8>(9));
        TEST_ASSERT_EQUALS(temp.compressionInfo,   static_cast<u8>(1));
        TEST_ASSERT_EQUALS(temp.checkBits,         static_cast<u8>(11));
        TEST_ASSERT_EQUALS(temp.presetDictionary,  static_cast<u8>(0));
        TEST_ASSERT_EQUALS(temp.compressionLevel,  static_cast<u8>(2));



        // |  10   | 0 |       01011       |
        // |     0001      |     0110      |
        temp.compressionMethod = static_cast<u8>(6);

        TEST_ASSERT_EQUALS(temp.value16, 0x8B16);



        // |  10   | 0 |       01011       |
        // |     1110      |     0110      |
        temp.compressionInfo = static_cast<u8>(14);

        TEST_ASSERT_EQUALS(temp.value16, 0x8BE6);



        // |  10   | 0 |       10100       |
        // |     1110      |     0110      |
        temp.checkBits = static_cast<u8>(20);

        TEST_ASSERT_EQUALS(temp.value16, 0x94E6);



        // |  10   | 1 |       10100       |
        // |     1110      |     0110      |
        temp.presetDictionary = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0xB4E6);



        // |  01   | 1 |       10100       |
        // |     1110      |     0110      |
        temp.compressionLevel = static_cast<u8>(1);

        TEST_ASSERT_EQUALS(temp.value16, 0x74E6);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_GENERATED_COM_NGOS_SHARED_COMMON_TYPES_H
