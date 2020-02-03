#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H



#include <buildconfig.h>
#include <common/src/bits64/assets/assetentry.h>
#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/checksum/adler.h>
#include <common/src/bits64/checksum/crc.h>
#include <common/src/bits64/checksum/lib/md5hash.h>
#include <common/src/bits64/checksum/md5.h>
#include <common/src/bits64/console/console.h>
#include <common/src/bits64/console/graphicalconsole.h>
#include <common/src/bits64/console/lib/glyphdata.h>
#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/cpu/cpufamily.h>
#include <common/src/bits64/cpu/cpuvendor.h>
#include <common/src/bits64/cpu/model/amdcpumodel.h>
#include <common/src/bits64/cpu/model/intelcpumodel.h>
#include <common/src/bits64/cpu/msr/msr.h>
#include <common/src/bits64/cpu/x86bug.h>
#include <common/src/bits64/cpu/x86bugword.h>
#include <common/src/bits64/cpu/x86feature.h>
#include <common/src/bits64/cpu/x86featureword.h>
#include <common/src/bits64/cryptography/aes.h>
#include <common/src/bits64/dmi/dmi.h>
#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmientrytype.h>
#include <common/src/bits64/dmi/dmiidentity.h>
#include <common/src/bits64/dmi/dmimemorydevice.h>
#include <common/src/bits64/dmi/dmistoreduuid.h>
#include <common/src/bits64/dmi/entry/dmibaseboardentry.h>
#include <common/src/bits64/dmi/entry/dmibiosentry.h>
#include <common/src/bits64/dmi/entry/dmibioslanguageentry.h>
#include <common/src/bits64/dmi/entry/dmicacheentry.h>
#include <common/src/bits64/dmi/entry/dmichassisentry.h>
#include <common/src/bits64/dmi/entry/dmicoolingdeviceentry.h>
#include <common/src/bits64/dmi/entry/dmielectricalcurrentprobeentry.h>
#include <common/src/bits64/dmi/entry/dmigroupassociationsentry.h>
#include <common/src/bits64/dmi/entry/dmimanagementdevicecomponententry.h>
#include <common/src/bits64/dmi/entry/dmimanagementdeviceentry.h>
#include <common/src/bits64/dmi/entry/dmimanagementdevicethresholddataentry.h>
#include <common/src/bits64/dmi/entry/dmimemoryarraymappedaddressentry.h>
#include <common/src/bits64/dmi/entry/dmimemorydeviceentry.h>
#include <common/src/bits64/dmi/entry/dmimemorydevicemappedaddressentry.h>
#include <common/src/bits64/dmi/entry/dmioemstringsentry.h>
#include <common/src/bits64/dmi/entry/dmionboarddevicesentry.h>
#include <common/src/bits64/dmi/entry/dmionboarddevicesextendedentry.h>
#include <common/src/bits64/dmi/entry/dmiphysicalmemoryarrayentry.h>
#include <common/src/bits64/dmi/entry/dmiportablebatteryentry.h>
#include <common/src/bits64/dmi/entry/dmiportconnectorentry.h>
#include <common/src/bits64/dmi/entry/dmiprocessorentry.h>
#include <common/src/bits64/dmi/entry/dmisystembootentry.h>
#include <common/src/bits64/dmi/entry/dmisystemconfigurationentry.h>
#include <common/src/bits64/dmi/entry/dmisystementry.h>
#include <common/src/bits64/dmi/entry/dmisystempowersupplyentry.h>
#include <common/src/bits64/dmi/entry/dmisystemslotsentry.h>
#include <common/src/bits64/dmi/entry/dmitemperatureprobeentry.h>
#include <common/src/bits64/dmi/entry/dmivoltageprobeentry.h>
#include <common/src/bits64/dmi/entry/lib/dmibaseboardfeatureflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibaseboardtype.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsbiosreservedflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsextension.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicssystemreservedflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibiosextendedromsize.h>
#include <common/src/bits64/dmi/entry/lib/dmibiosextendedromsizeunit.h>
#include <common/src/bits64/dmi/entry/lib/dmibioslanguageflags.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheassociativity.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheconfiguration.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheerrorcorrectiontype.h>
#include <common/src/bits64/dmi/entry/lib/dmicachelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheoperationalmode.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesize.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesize2.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesizegranularity.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesramtypeflags.h>
#include <common/src/bits64/dmi/entry/lib/dmicachetype.h>
#include <common/src/bits64/dmi/entry/lib/dmichassiscontainedelement.h>
#include <common/src/bits64/dmi/entry/lib/dmichassissecuritystatus.h>
#include <common/src/bits64/dmi/entry/lib/dmichassisstate.h>
#include <common/src/bits64/dmi/entry/lib/dmichassistype.h>
#include <common/src/bits64/dmi/entry/lib/dmicoolingdevicestatus.h>
#include <common/src/bits64/dmi/entry/lib/dmicoolingdevicetype.h>
#include <common/src/bits64/dmi/entry/lib/dmicoolingdevicetypeandstatus.h>
#include <common/src/bits64/dmi/entry/lib/dmielectricalcurrentprobelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmielectricalcurrentprobelocationandstatus.h>
#include <common/src/bits64/dmi/entry/lib/dmielectricalcurrentprobestatus.h>
#include <common/src/bits64/dmi/entry/lib/dmigroupassociationsgroup.h>
#include <common/src/bits64/dmi/entry/lib/dmimanagementdeviceaddresstype.h>
#include <common/src/bits64/dmi/entry/lib/dmimanagementdevicetype.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceformfactor.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceoperatingmodecapabilityflags.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetechnology.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetype.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetypedetailflags.h>
#include <common/src/bits64/dmi/entry/lib/dmionboarddevicesdevice.h>
#include <common/src/bits64/dmi/entry/lib/dmionboarddevicesdevicetype.h>
#include <common/src/bits64/dmi/entry/lib/dmionboarddevicesextendeddevicetype.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarrayerrorcorrection.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarraylocation.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarrayuse.h>
#include <common/src/bits64/dmi/entry/lib/dmiportablebatterydevicechemistry.h>
#include <common/src/bits64/dmi/entry/lib/dmiportablebatterymanufacturedate.h>
#include <common/src/bits64/dmi/entry/lib/dmiportconnectorporttype.h>
#include <common/src/bits64/dmi/entry/lib/dmiportconnectortype.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorcharacteristicsflags.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorfamily.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorfamily2.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorfeatureflags.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorid.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorsignature.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorstatus.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessortype.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorupgrade.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorvoltageflags.h>
#include <common/src/bits64/dmi/entry/lib/dmisystembootstatus.h>
#include <common/src/bits64/dmi/entry/lib/dmisystempowersupplycharacteristics.h>
#include <common/src/bits64/dmi/entry/lib/dmisystempowersupplyinputvoltagerangeswitch.h>
#include <common/src/bits64/dmi/entry/lib/dmisystempowersupplystatus.h>
#include <common/src/bits64/dmi/entry/lib/dmisystempowersupplytype.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotscharacteristicsflags.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotsdatabuswidth.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotslength.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotspeergroup.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotstype.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotsusage.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemwakeuptime.h>
#include <common/src/bits64/dmi/entry/lib/dmitemperatureprobelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmitemperatureprobelocationandstatus.h>
#include <common/src/bits64/dmi/entry/lib/dmitemperatureprobestatus.h>
#include <common/src/bits64/dmi/entry/lib/dmivoltageprobelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmivoltageprobelocationandstatus.h>
#include <common/src/bits64/dmi/entry/lib/dmivoltageprobestatus.h>
#include <common/src/bits64/fpu/fpu.h>
#include <common/src/bits64/fpu/fpustate.h>
#include <common/src/bits64/fpu/fsavestate.h>
#include <common/src/bits64/fpu/fxsavestate.h>
#include <common/src/bits64/fpu/xfeature/extendedregisters.h>
#include <common/src/bits64/fpu/xfeature/xfeatureavx512opmaskstate.h>
#include <common/src/bits64/fpu/xfeature/xfeatureavx512zmmfrom0to15state.h>
#include <common/src/bits64/fpu/xfeature/xfeatureavx512zmmfrom16to31state.h>
#include <common/src/bits64/fpu/xfeature/xfeatureavxstate.h>
#include <common/src/bits64/fpu/xfeature/xfeaturempxboundconfigandstatusregistersstate.h>
#include <common/src/bits64/fpu/xfeature/xfeaturempxboundregistersstate.h>
#include <common/src/bits64/fpu/xfeature/xfeaturepkrustate.h>
#include <common/src/bits64/fpu/xfeatureflags.h>
#include <common/src/bits64/fpu/xfeaturetypeflags.h>
#include <common/src/bits64/fpu/xsavestate.h>
#include <common/src/bits64/fpu/xstateheader.h>
#include <common/src/bits64/graphics/bmp/bmp.h>
#include <common/src/bits64/graphics/bmp/lib/bmpcolormap.h>
#include <common/src/bits64/graphics/bmp/lib/bmpcompressionmethod.h>
#include <common/src/bits64/graphics/bmp/lib/bmpheader.h>
#include <common/src/bits64/graphics/bmp/lib/bmpinformationheader.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/jpeg/jpeg.h>
#include <common/src/bits64/graphics/jpeg/jpegcomponent.h>
#include <common/src/bits64/graphics/jpeg/jpegdecoder.h>
#include <common/src/bits64/graphics/jpeg/jpegvlccode.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegcomponentid.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegdefinehuffmantablemarker.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegdefinequantizationtablemarker.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegdefinerestartintervalmarker.h>
#include <common/src/bits64/graphics/jpeg/lib/jpeghuffmantable.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegmarkerheader.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegmarkertype.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegquantizationtable.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegstartofframecomponent.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegstartofframemarker.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegstartofscancomponent.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegstartofscanmarker.h>
#include <common/src/bits64/graphics/ninepatch.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngembeddediccprofile.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngimagegamma.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngimageheader.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngimagelastmodificationtime.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngphysicalpixeldimensions.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngprimarychromaticities.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngsignificantbits.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngstandardrgbcolorspace.h>
#include <common/src/bits64/graphics/png/lib/pngchunk.h>
#include <common/src/bits64/graphics/png/lib/pngchunktype.h>
#include <common/src/bits64/graphics/png/lib/pngcolortype.h>
#include <common/src/bits64/graphics/png/lib/pngcompressionmethod.h>
#include <common/src/bits64/graphics/png/lib/pngfiltermethod.h>
#include <common/src/bits64/graphics/png/lib/pngfiltertype.h>
#include <common/src/bits64/graphics/png/lib/pngheader.h>
#include <common/src/bits64/graphics/png/lib/pnginterlacemethod.h>
#include <common/src/bits64/graphics/png/lib/pngrenderingintent.h>
#include <common/src/bits64/graphics/png/lib/pngunitspecifier.h>
#include <common/src/bits64/graphics/png/png.h>
#include <common/src/bits64/graphics/png/pngdecoder.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/graphics/stretchrange.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/other/widgetstate.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/controls/tabbutton.h>
#include <common/src/bits64/gui/widgets/controls/tablewidget.h>
#include <common/src/bits64/gui/widgets/controls/tabwidget.h>
#include <common/src/bits64/gui/widgets/misc/consolewidget.h>
#include <common/src/bits64/gui/widgets/misc/cursorwidget.h>
#include <common/src/bits64/gui/widgets/misc/imagewidget.h>
#include <common/src/bits64/gui/widgets/misc/labelwidget.h>
#include <common/src/bits64/gui/widgets/misc/panelwidget.h>
#include <common/src/bits64/gui/widgets/misc/tablecellwidget.h>
#include <common/src/bits64/gui/widgets/misc/tableheaderwidget.h>
#include <common/src/bits64/gui/widgets/misc/tablerowwidget.h>
#include <common/src/bits64/gui/widgets/misc/tabpagewidget.h>
#include <common/src/bits64/gui/widgets/misc/wrapperwidget.h>
#include <common/src/bits64/gui/widgets/special/rootwidget.h>
#include <common/src/bits64/gui/widgets/special/screenwidget.h>
#include <common/src/bits64/gui/widgets/widget.h>
#include <common/src/bits64/inflate/inflateblocktype.h>
#include <common/src/bits64/inflate/inflatecode.h>
#include <common/src/bits64/inflate/inflatecodetype.h>
#include <common/src/bits64/inflate/inflatedecoder.h>
#include <common/src/bits64/serial/serial.h>
#include <common/src/bits64/zlib/zlib.h>
#include <common/src/bits64/zlib/zlibcompressioninfo.h>
#include <common/src/bits64/zlib/zlibcompressionlevel.h>
#include <common/src/bits64/zlib/zlibcompressionmethod.h>
#include <common/src/bits64/zlib/zlibheader.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(Adler),                                         1);
        TEST_ASSERT_EQUALS(sizeof(AES),                                           64);
        TEST_ASSERT_EQUALS(sizeof(AmdCpuModel),                                   1);
        TEST_ASSERT_EQUALS(sizeof(ArrayList<u8>),                                 24);
        TEST_ASSERT_EQUALS(sizeof(AssetEntry),                                    24);
        TEST_ASSERT_EQUALS(sizeof(Assets),                                        1);
        TEST_ASSERT_EQUALS(sizeof(Bmp),                                           1);
        TEST_ASSERT_EQUALS(sizeof(BmpColorMap),                                   4);
        TEST_ASSERT_EQUALS(sizeof(BmpCompressionMethod),                          4);
        TEST_ASSERT_EQUALS(sizeof(BmpHeader),                                     14);
        TEST_ASSERT_EQUALS(sizeof(BmpInformationHeader),                          40);
        TEST_ASSERT_EQUALS(sizeof(Button),                                        216);
        TEST_ASSERT_EQUALS(sizeof(Console),                                       1);
        TEST_ASSERT_EQUALS(sizeof(ConsoleWidget),                                 96);
        TEST_ASSERT_EQUALS(sizeof(CPU),                                           1);
        TEST_ASSERT_EQUALS(sizeof(CpuFamily),                                     2);
        TEST_ASSERT_EQUALS(sizeof(CpuVendor),                                     1);
        TEST_ASSERT_EQUALS(sizeof(Crc),                                           1);
        TEST_ASSERT_EQUALS(sizeof(CursorWidget),                                  96);
        TEST_ASSERT_EQUALS(sizeof(DMI),                                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardEntry),                             15);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardFeatureFlag),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardType),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsBiosReservedFlag),        1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsExtension),               2);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsFlag),                    8);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsSystemReservedFlag),      1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntry),                                  26);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosExtendedRomSize),                        2);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosExtendedRomSizeUnit),                    1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosLanguageEntry),                          22);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosLanguageFlag),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheAssociativity),                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheConfiguration),                         2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheEntry),                                 27);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheErrorCorrectionType),                   1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheLocation),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheOperationalMode),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSize),                                  2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSize2),                                 4);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSizeGranularity),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSramTypeFlag),                          2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisContainedElement),                    3);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntry),                               21);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisSecurityStatus),                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisState),                               1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisType),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceEntry),                         15);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceStatus),                        1);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceType),                          1);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceTypeAndStatus),                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeEntry),                22);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeLocation),             1);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeLocationAndStatus),    1);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeStatus),               1);
        TEST_ASSERT_EQUALS(sizeof(DmiEntryHeader),                                4);
        TEST_ASSERT_EQUALS(sizeof(DmiEntryType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiGroupAssociationsEntry),                     5);
        TEST_ASSERT_EQUALS(sizeof(DmiGroupAssociationsGroup),                     3);
        TEST_ASSERT_EQUALS(sizeof(DmiIdentity),                                   1);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceAddressType),                1);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceComponentEntry),             11);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceEntry),                      11);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceThresholdDataEntry),         16);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceType),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryArrayMappedAddressEntry),              31);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDevice),                               72);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntry),                          84);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceFormFactor),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceMappedAddressEntry),             35);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceOperatingModeCapabilityFlag),    2);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceTechnology),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceType),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceTypeDetailFlag),                 2);
        TEST_ASSERT_EQUALS(sizeof(DmiOemStringsEntry),                            5);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesDevice),                       2);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesDeviceType),                   1);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesEntry),                        4);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesExtendedDeviceType),           1);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesExtendedEntry),                11);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayEntry),                   23);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayErrorCorrection),         1);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayLocation),                1);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayUse),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryDeviceChemistry),             1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryEntry),                       26);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryManufactureDate),             2);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorEntry),                         9);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorPortType),                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorType),                          1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorCharacteristicsFlag),               2);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntry),                             48);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFamily),                            1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFamily2),                           2);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFeatureFlag),                       4);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorId),                                8);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorSignature),                         4);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorStatus),                            1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorType),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorUpgrade),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorVoltageFlag),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiStoredUuid),                                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemBootEntry),                            11);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemBootStatus),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemConfigurationEntry),                   5);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemEntry),                                27);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyCharacteristics),           2);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyEntry),                     22);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyInputVoltageRangeSwitch),   1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyStatus),                    1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyType),                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsCharacteristicsFlag),             2);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsDataBusWidth),                    1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsEntry),                           19);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsLength),                          1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsPeerGroup),                       5);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsType),                            1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsUsage),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemWakeUpTime),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeEntry),                      22);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeLocation),                   1);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeLocationAndStatus),          1);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeStatus),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeEntry),                          22);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeLocation),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeLocationAndStatus),              1);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeStatus),                         1);
        TEST_ASSERT_EQUALS(sizeof(FPU),                                           1);
        TEST_ASSERT_EQUALS(sizeof(FpuState),                                      4096);
        TEST_ASSERT_EQUALS(sizeof(FSaveState),                                    112);
        TEST_ASSERT_EQUALS(sizeof(FXSaveState),                                   512);
        TEST_ASSERT_EQUALS(sizeof(GlyphData),                                     5);
        TEST_ASSERT_EQUALS(sizeof(GraphicalConsole),                              1);
        TEST_ASSERT_EQUALS(sizeof(Graphics),                                      1);
        TEST_ASSERT_EQUALS(sizeof(GUI),                                           1);
        TEST_ASSERT_EQUALS(sizeof(Image),                                         32);
        TEST_ASSERT_EQUALS(sizeof(ImageWidget),                                   96);
        TEST_ASSERT_EQUALS(sizeof(InflateBlockType),                              1);
        TEST_ASSERT_EQUALS(sizeof(InflateCode),                                   4);
        TEST_ASSERT_EQUALS(sizeof(InflateCodeType),                               1);
        TEST_ASSERT_EQUALS(sizeof(InflateDecoder),                                40);
        TEST_ASSERT_EQUALS(sizeof(IntelCpuModel),                                 1);
        TEST_ASSERT_EQUALS(sizeof(Jpeg),                                          1);
        TEST_ASSERT_EQUALS(sizeof(JpegComponent),                                 56);
        TEST_ASSERT_EQUALS(sizeof(JpegComponentId),                               1);
        TEST_ASSERT_EQUALS(sizeof(JpegDecoder),                                   808);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineHuffmanTableMarker),                  4);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineQuantizationTableMarker),             4);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineRestartIntervalMarker),               6);
        TEST_ASSERT_EQUALS(sizeof(JpegHuffmanTable),                              17);
        TEST_ASSERT_EQUALS(sizeof(JpegHuffmanTableType),                          1);
        TEST_ASSERT_EQUALS(sizeof(JpegMarkerHeader),                              4);
        TEST_ASSERT_EQUALS(sizeof(JpegMarkerType),                                1);
        TEST_ASSERT_EQUALS(sizeof(JpegQuantizationTable),                         1);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfFrameComponent),                     3);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfFrameMarker),                        10);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfScanComponent),                      2);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfScanMarker),                         5);
        TEST_ASSERT_EQUALS(sizeof(JpegVlcCode),                                   2);
        TEST_ASSERT_EQUALS(sizeof(LabelWidget),                                   112);
        TEST_ASSERT_EQUALS(sizeof(ListElement<u8>),                               24);
        TEST_ASSERT_EQUALS(sizeof(List<u8>),                                      16);
        TEST_ASSERT_EQUALS(sizeof(MD5),                                           96);
        TEST_ASSERT_EQUALS(sizeof(Md5Hash),                                       16);
        TEST_ASSERT_EQUALS(sizeof(MpxBoundRegister),                              16);
        TEST_ASSERT_EQUALS(sizeof(MSR),                                           1);
        TEST_ASSERT_EQUALS(sizeof(NinePatch),                                     40);
        TEST_ASSERT_EQUALS(sizeof(PanelWidget),                                   104);
        TEST_ASSERT_EQUALS(sizeof(Png),                                           1);
        TEST_ASSERT_EQUALS(sizeof(PngChunk),                                      8);
        TEST_ASSERT_EQUALS(sizeof(PngChunkType),                                  4);
        TEST_ASSERT_EQUALS(sizeof(PngColorType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(PngCompressionMethod),                          1);
        TEST_ASSERT_EQUALS(sizeof(PngDecoder),                                    112);
        TEST_ASSERT_EQUALS(sizeof(PngEmbeddedIccProfile),                         80);
        TEST_ASSERT_EQUALS(sizeof(PngFilterMethod),                               1);
        TEST_ASSERT_EQUALS(sizeof(PngFilterType),                                 1);
        TEST_ASSERT_EQUALS(sizeof(PngHeader),                                     16);
        TEST_ASSERT_EQUALS(sizeof(PngImageGamma),                                 4);
        TEST_ASSERT_EQUALS(sizeof(PngImageHeader),                                13);
        TEST_ASSERT_EQUALS(sizeof(PngImageLastModificationTime),                  7);
        TEST_ASSERT_EQUALS(sizeof(PngInterlaceMethod),                            1);
        TEST_ASSERT_EQUALS(sizeof(PngPhysicalPixelDimensions),                    9);
        TEST_ASSERT_EQUALS(sizeof(PngPrimaryChromaticities),                      32);
        TEST_ASSERT_EQUALS(sizeof(PngRenderingIntent),                            1);
        TEST_ASSERT_EQUALS(sizeof(PngSignificantBits),                            4);
        TEST_ASSERT_EQUALS(sizeof(PngStandardRgbColorSpace),                      1);
        TEST_ASSERT_EQUALS(sizeof(PngUnitSpecifier),                              1);
        TEST_ASSERT_EQUALS(sizeof(Register128Bit),                                16);
        TEST_ASSERT_EQUALS(sizeof(Register256Bit),                                32);
        TEST_ASSERT_EQUALS(sizeof(Register512Bit),                                64);
        TEST_ASSERT_EQUALS(sizeof(RgbaPixel),                                     4);
        TEST_ASSERT_EQUALS(sizeof(RgbPixel),                                      3);
        TEST_ASSERT_EQUALS(sizeof(RootWidget),                                    104);
        TEST_ASSERT_EQUALS(sizeof(ScreenWidget),                                  144);
        TEST_ASSERT_EQUALS(sizeof(Serial),                                        1);
        TEST_ASSERT_EQUALS(sizeof(StretchRange),                                  4);
        TEST_ASSERT_EQUALS(sizeof(TabButton),                                     296);
        TEST_ASSERT_EQUALS(sizeof(TableCellWidget),                               88);
        TEST_ASSERT_EQUALS(sizeof(TableHeaderWidget),                             104);
        TEST_ASSERT_EQUALS(sizeof(TableRowWidget),                                120);
        TEST_ASSERT_EQUALS(sizeof(TableWidget),                                   240);
        TEST_ASSERT_EQUALS(sizeof(TabPageWidget),                                 88);
        TEST_ASSERT_EQUALS(sizeof(TabWidget),                                     152);
        TEST_ASSERT_EQUALS(sizeof(Widget),                                        88);
        TEST_ASSERT_EQUALS(sizeof(WidgetState),                                   1);
        TEST_ASSERT_EQUALS(sizeof(WrapperWidget),                                 88);
        TEST_ASSERT_EQUALS(sizeof(X86Bug),                                        2);
        TEST_ASSERT_EQUALS(sizeof(x86BugWord),                                    1);
        TEST_ASSERT_EQUALS(sizeof(X86Feature),                                    2);
        TEST_ASSERT_EQUALS(sizeof(x86FeatureWord),                                1);
        TEST_ASSERT_EQUALS(sizeof(XFeature),                                      1);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512OpmaskState),                     64);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512ZmmFrom0To15State),               512);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512ZmmFrom16To31State),              1024);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvxState),                              256);
        TEST_ASSERT_EQUALS(sizeof(XFeatureFlag),                                  4);
        TEST_ASSERT_EQUALS(sizeof(XFeatureMpxBoundConfigAndStatusRegistersState), 64);
        TEST_ASSERT_EQUALS(sizeof(XFeatureMpxBoundRegistersState),                64);
        TEST_ASSERT_EQUALS(sizeof(XFeaturePkruState),                             8);
        TEST_ASSERT_EQUALS(sizeof(XFeatureTypeFlag),                              8);
        TEST_ASSERT_EQUALS(sizeof(XSaveState),                                    576);
        TEST_ASSERT_EQUALS(sizeof(XStateHeader),                                  64);
        TEST_ASSERT_EQUALS(sizeof(ZLib),                                          1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionInfo),                           1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionLevel),                          1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionMethod),                         1);
        TEST_ASSERT_EQUALS(sizeof(ZLibHeader),                                    2);
    }
    TEST_CASE_END();



    TEST_CASE("DmiOnboardDevicesExtendedEntry");
    {
        DmiOnboardDevicesExtendedEntry temp;



        //  DmiOnboardDevicesExtendedEntry - deviceTypeAndEnabled:
        // ====================================
        // |  enabled : 1  |  deviceType : 7  |
        // ====================================



        temp.deviceTypeAndEnabled = 0x85;   // ||  1  |  0000101  ||

        TEST_ASSERT_EQUALS(temp.deviceType, 5);
        TEST_ASSERT_EQUALS(temp.enabled,    1);



        temp.deviceType = 10;               // ||  1  |  0001010  ||

        TEST_ASSERT_EQUALS(temp.deviceTypeAndEnabled, 0x8A);



        temp.enabled = 0;                   // ||  0  |  0001010  ||

        TEST_ASSERT_EQUALS(temp.deviceTypeAndEnabled, 0x0A);



        //  DmiOnboardDevicesExtendedEntry - functionNumberAndDeviceNumber:
        // =============================================
        // |  deviceNumber : 5  |  functionNumber : 3  |
        // =============================================



        temp.functionNumberAndDeviceNumber = 0x0D;  // ||  00001  |  101  ||

        TEST_ASSERT_EQUALS(temp.functionNumber, 5);
        TEST_ASSERT_EQUALS(temp.deviceNumber,   1);



        temp.functionNumber = 2;                    // ||  00001  |  010  ||

        TEST_ASSERT_EQUALS(temp.functionNumberAndDeviceNumber, 0x0A);



        temp.deviceNumber = 9;                      // ||  01001  |  010  ||

        TEST_ASSERT_EQUALS(temp.functionNumberAndDeviceNumber, 0x4A);
    }
    TEST_CASE_END();



    TEST_CASE("DmiProcessorEntry");
    {
        DmiProcessorEntry temp;



        //  DmiProcessorEntry - processorStatus:
        // ===============================================================================
        // |  __reserved2 : 1  |  socketPopulated : 1  |  __reserved : 3  |  status : 3  |
        // ===============================================================================



        temp.processorStatus = 0x55;    // ||  0  |  1  |  010  |  101  ||

        TEST_ASSERT_EQUALS(temp.status,          5);
        TEST_ASSERT_EQUALS(temp.__reserved,      2);
        TEST_ASSERT_EQUALS(temp.socketPopulated, 1);
        TEST_ASSERT_EQUALS(temp.__reserved2,     0);



        temp.status = 2;                // ||  0  |  1  |  010  |  010  ||

        TEST_ASSERT_EQUALS(temp.processorStatus, 0x52);



        temp.__reserved = 1;            // ||  0  |  1  |  001  |  010  ||

        TEST_ASSERT_EQUALS(temp.processorStatus, 0x4A);



        temp.socketPopulated = 0;       // ||  0  |  0  |  001  |  010  ||

        TEST_ASSERT_EQUALS(temp.processorStatus, 0x0A);



        temp.__reserved2 = 1;           // ||  1  |  0  |  001  |  010  ||

        TEST_ASSERT_EQUALS(temp.processorStatus, 0x8A);
    }
    TEST_CASE_END();



    TEST_CASE("DmiSystemSlotsEntry");
    {
        DmiSystemSlotsEntry temp;



        //  DmiSystemSlotsEntry - functionNumberAndDeviceNumber:
        // =============================================
        // |  deviceNumber : 5  |  functionNumber : 3  |
        // =============================================



        temp.functionNumberAndDeviceNumber = 0x0D;  // ||  00001  |  101  ||

        TEST_ASSERT_EQUALS(temp.functionNumber, 5);
        TEST_ASSERT_EQUALS(temp.deviceNumber,   1);



        temp.functionNumber = 2;                    // ||  00001  |  010  ||

        TEST_ASSERT_EQUALS(temp.functionNumberAndDeviceNumber, 0x0A);



        temp.deviceNumber = 9;                      // ||  01001  |  010  ||

        TEST_ASSERT_EQUALS(temp.functionNumberAndDeviceNumber, 0x4A);
    }
    TEST_CASE_END();



    TEST_CASE("DmiBiosExtendedRomSize");
    {
        DmiBiosExtendedRomSize temp;



        //  DmiBiosExtendedRomSize - value16:
        // =============================
        // |  unit : 2  |  value : 14  |
        // =============================



        temp.value16 = 0x4005;  // ||  01  |  00000000000101  ||

        TEST_ASSERT_EQUALS(temp.value, 5);
        TEST_ASSERT_EQUALS(temp.unit,  1);



        temp.value = 8;         // ||  01  |  00000000001000  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4008);



        temp.unit = 2;          // ||  10  |  00000000001000  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x8008);
    }
    TEST_CASE_END();



    TEST_CASE("DmiCacheConfiguration");
    {
        DmiCacheConfiguration temp;



        //  DmiCacheConfiguration - value16:
        // =====================================================================================================
        // |  enabled : 1  |  location : 2  |  __reserved : 1  |  socketed : 1  |          level : 3           |
        // |                             __reserved2 : 6                               |  operationalMode : 2  |
        // =====================================================================================================



        temp.value16 = 0x4A55;      // ||  010010  |  10  ||  0  |  10  |  1  |  0  |  101  ||

        TEST_ASSERT_EQUALS(temp.level,           5);
        TEST_ASSERT_EQUALS(temp.socketed,        0);
        TEST_ASSERT_EQUALS(temp.__reserved,      1);
        TEST_ASSERT_EQUALS(temp.location,        2);
        TEST_ASSERT_EQUALS(temp.enabled,         0);
        TEST_ASSERT_EQUALS(temp.operationalMode, 2);
        TEST_ASSERT_EQUALS(temp.__reserved2,     18);



        temp.level = 2;             // ||  010010  |  10  ||  0  |  10  |  1  |  0  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4A52);



        temp.socketed = 1;          // ||  010010  |  10  ||  0  |  10  |  1  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4A5A);



        temp.__reserved = 0;        // ||  010010  |  10  ||  0  |  10  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4A4A);



        temp.location = 1;          // ||  010010  |  10  ||  0  |  01  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4A2A);



        temp.enabled = 1;           // ||  010010  |  10  ||  1  |  01  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4AAA);



        temp.operationalMode = 1;   // ||  010010  |  01  ||  1  |  01  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x49AA);



        temp.__reserved2 = 11;      // ||  001011  |  01  ||  1  |  01  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x2DAA);
    }
    TEST_CASE_END();



    TEST_CASE("DmiCacheSize");
    {
        DmiCacheSize temp;



        //  DmiCacheSize - value16:
        // ====================================
        // |  granularity : 1  |  value : 15  |
        // ====================================



        temp.value16 = 0x8005;  // ||  1  |  000000000000101  ||

        TEST_ASSERT_EQUALS(temp.value,        5);
        TEST_ASSERT_EQUALS(temp.granularity,  1);



        temp.value = 8;         // ||  1  |  000000000001000  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x8008);



        temp.granularity = 0;   // ||  0  |  000000000001000  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x0008);
    }
    TEST_CASE_END();



    TEST_CASE("DmiCacheSize2");
    {
        DmiCacheSize2 temp;



        //  DmiCacheSize2 - value32:
        // ====================================
        // |  granularity : 1  |  value : 31  |
        // ====================================



        temp.value32 = 0x80000005;  // ||  1  |  0000000000000000000000000000101  ||

        TEST_ASSERT_EQUALS(temp.value,        5);
        TEST_ASSERT_EQUALS(temp.granularity,  1);



        temp.value = 8;         // ||  1  |  0000000000000000000000000001000  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x80000008);



        temp.granularity = 0;   // ||  0  |  0000000000000000000000000001000  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x00000008);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H
