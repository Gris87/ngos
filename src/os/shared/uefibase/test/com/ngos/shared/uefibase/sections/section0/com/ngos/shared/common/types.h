#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TYPES_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TYPES_H



#include <buildconfig.h>
#include <com/ngos/shared/common/asm/bitutils.h>
#include <com/ngos/shared/common/assets/assetentry.h>
#include <com/ngos/shared/common/assets/assets.h>
#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/bootparams/bootparamsheader.h>
#include <com/ngos/shared/common/bootparams/memorymapentry.h>
#include <com/ngos/shared/common/bootparams/memorymapentrytype.h>
#include <com/ngos/shared/common/bootparams/pciromimagewithinfo.h>
#include <com/ngos/shared/common/bootparams/uefiinfo.h>
#include <com/ngos/shared/common/bootparams/uefimemorymapinfo.h>
#include <com/ngos/shared/common/checksum/adler.h>
#include <com/ngos/shared/common/checksum/crc.h>
#include <com/ngos/shared/common/checksum/lib/md5hash.h>
#include <com/ngos/shared/common/checksum/md5.h>
#include <com/ngos/shared/common/console/console.h>
#include <com/ngos/shared/common/console/graphicalconsole.h>
#include <com/ngos/shared/common/console/lib/glyphdata.h>
#include <com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/common/containers/list.h>
#include <com/ngos/shared/common/containers/map.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/cpu/cpufamily.h>
#include <com/ngos/shared/common/cpu/cpuvendor.h>
#include <com/ngos/shared/common/cpu/model/amdcpumodel.h>
#include <com/ngos/shared/common/cpu/model/intelcpumodel.h>
#include <com/ngos/shared/common/cpu/msr/msr.h>
#include <com/ngos/shared/common/cpu/x86bug.h>
#include <com/ngos/shared/common/cpu/x86bugword.h>
#include <com/ngos/shared/common/cpu/x86feature.h>
#include <com/ngos/shared/common/cpu/x86featureword.h>
#include <com/ngos/shared/common/cryptography/aes.h>
#include <com/ngos/shared/common/dmi/dmi.h>
#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmientrytype.h>
#include <com/ngos/shared/common/dmi/dmiidentity.h>
#include <com/ngos/shared/common/dmi/dmimemorydevice.h>
#include <com/ngos/shared/common/dmi/dmistoreduuid.h>
#include <com/ngos/shared/common/dmi/entry/dmiadditionalinformationentry.h>
#include <com/ngos/shared/common/dmi/entry/dmibaseboardentry.h>
#include <com/ngos/shared/common/dmi/entry/dmibiosentry.h>
#include <com/ngos/shared/common/dmi/entry/dmibioslanguageentry.h>
#include <com/ngos/shared/common/dmi/entry/dmicacheentry.h>
#include <com/ngos/shared/common/dmi/entry/dmichassisentry.h>
#include <com/ngos/shared/common/dmi/entry/dmicoolingdeviceentry.h>
#include <com/ngos/shared/common/dmi/entry/dmielectricalcurrentprobeentry.h>
#include <com/ngos/shared/common/dmi/entry/dmigroupassociationsentry.h>
#include <com/ngos/shared/common/dmi/entry/dmimanagementdevicecomponententry.h>
#include <com/ngos/shared/common/dmi/entry/dmimanagementdeviceentry.h>
#include <com/ngos/shared/common/dmi/entry/dmimanagementdevicethresholddataentry.h>
#include <com/ngos/shared/common/dmi/entry/dmimemoryarraymappedaddressentry.h>
#include <com/ngos/shared/common/dmi/entry/dmimemorydeviceentry.h>
#include <com/ngos/shared/common/dmi/entry/dmimemorydevicemappedaddressentry.h>
#include <com/ngos/shared/common/dmi/entry/dmioemstringsentry.h>
#include <com/ngos/shared/common/dmi/entry/dmionboarddevicesentry.h>
#include <com/ngos/shared/common/dmi/entry/dmionboarddevicesextendedentry.h>
#include <com/ngos/shared/common/dmi/entry/dmiphysicalmemoryarrayentry.h>
#include <com/ngos/shared/common/dmi/entry/dmiportablebatteryentry.h>
#include <com/ngos/shared/common/dmi/entry/dmiportconnectorentry.h>
#include <com/ngos/shared/common/dmi/entry/dmiprocessorentry.h>
#include <com/ngos/shared/common/dmi/entry/dmisystembootentry.h>
#include <com/ngos/shared/common/dmi/entry/dmisystemconfigurationentry.h>
#include <com/ngos/shared/common/dmi/entry/dmisystementry.h>
#include <com/ngos/shared/common/dmi/entry/dmisystempowersupplyentry.h>
#include <com/ngos/shared/common/dmi/entry/dmisystemslotsentry.h>
#include <com/ngos/shared/common/dmi/entry/dmitemperatureprobeentry.h>
#include <com/ngos/shared/common/dmi/entry/dmivoltageprobeentry.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiadditionalinformation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibaseboardfeatureflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibaseboardtype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicsbiosreservedflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicsflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicssystemreservedflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibiosextendedromsize.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibiosextendedromsizeunit.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibioslanguageflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheassociativity.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheconfiguration.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheerrorcorrectiontype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheoperationalmode.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachesize.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachesize2.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachesizegranularity.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachesramtypeflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachetype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelement.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassissecuritystatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassisstate.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassistype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicoolingdevicestatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicoolingdevicetype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmielectricalcurrentprobelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmielectricalcurrentprobestatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmigroupassociationsitem.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimanagementdeviceaddresstype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimanagementdevicetype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceformfactor.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceoperatingmodecapabilityflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetechnology.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetypedetailflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevice.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevicetype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesextendeddevicetype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarrayerrorcorrection.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarraylocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarrayuse.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiportablebatterydevicechemistry.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiportablebatterymanufacturedate.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiportconnectorporttype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiportconnectortype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorcharacteristicsflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorfamily.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorfamily2.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorfeatureflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorsignature.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorstatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessortype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorupgrade.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorvoltageflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystembootstatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplycharacteristics.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplyinputvoltagerangeswitch.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplystatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplytype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotscharacteristicsflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotsdatabuswidth.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotslength.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotspeergroup.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotstype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotsusage.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemwakeuptype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmitemperatureprobelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmitemperatureprobestatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmivoltageprobelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmivoltageprobestatus.h>
#include <com/ngos/shared/common/elf/class.h>
#include <com/ngos/shared/common/elf/data.h>
#include <com/ngos/shared/common/elf/header.h>
#include <com/ngos/shared/common/elf/headeridentification.h>
#include <com/ngos/shared/common/elf/programheadertableentry.h>
#include <com/ngos/shared/common/elf/rela.h>
#include <com/ngos/shared/common/elf/relatype.h>
#include <com/ngos/shared/common/elf/sectionheadertableentry.h>
#include <com/ngos/shared/common/elf/symbol.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/fpu/fpustate.h>
#include <com/ngos/shared/common/fpu/fsavestate.h>
#include <com/ngos/shared/common/fpu/fxsavestate.h>
#include <com/ngos/shared/common/fpu/xfeature/extendedregisters.h>
#include <com/ngos/shared/common/fpu/xfeature/xfeatureavx512opmaskstate.h>
#include <com/ngos/shared/common/fpu/xfeature/xfeatureavx512zmmfrom0to15state.h>
#include <com/ngos/shared/common/fpu/xfeature/xfeatureavx512zmmfrom16to31state.h>
#include <com/ngos/shared/common/fpu/xfeature/xfeatureavxstate.h>
#include <com/ngos/shared/common/fpu/xfeature/xfeaturempxboundconfigandstatusregistersstate.h>
#include <com/ngos/shared/common/fpu/xfeature/xfeaturempxboundregistersstate.h>
#include <com/ngos/shared/common/fpu/xfeature/xfeaturepkrustate.h>
#include <com/ngos/shared/common/fpu/xfeatureflags.h>
#include <com/ngos/shared/common/fpu/xfeaturetypeflags.h>
#include <com/ngos/shared/common/fpu/xsavestate.h>
#include <com/ngos/shared/common/fpu/xstateheader.h>
#include <com/ngos/shared/common/gdt/gdtdescriptor.h>
#include <com/ngos/shared/common/gdt/gdtregister.h>
#include <com/ngos/shared/common/gpt/gptdata.h>
#include <com/ngos/shared/common/gpt/gptentry.h>
#include <com/ngos/shared/common/gpt/gptheader.h>
#include <com/ngos/shared/common/graphics/bmp/bmp.h>
#include <com/ngos/shared/common/graphics/bmp/lib/bmpcolormap.h>
#include <com/ngos/shared/common/graphics/bmp/lib/bmpcompressionmethod.h>
#include <com/ngos/shared/common/graphics/bmp/lib/bmpheader.h>
#include <com/ngos/shared/common/graphics/bmp/lib/bmpinformationheader.h>
#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/graphics/jpeg/jpeg.h>
#include <com/ngos/shared/common/graphics/jpeg/jpegcomponent.h>
#include <com/ngos/shared/common/graphics/jpeg/jpegdecoder.h>
#include <com/ngos/shared/common/graphics/jpeg/jpegvlccode.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegcomponentid.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegdefinehuffmantablemarker.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegdefinequantizationtablemarker.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegdefinerestartintervalmarker.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantable.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkertype.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegquantizationtable.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofframecomponent.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofframemarker.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscancomponent.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscanmarker.h>
#include <com/ngos/shared/common/graphics/ninepatch.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngembeddediccprofile.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngimagegamma.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngimageheader.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngimagelastmodificationtime.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngphysicalpixeldimensions.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngprimarychromaticities.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngsignificantbits.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngstandardrgbcolorspace.h>
#include <com/ngos/shared/common/graphics/png/lib/pngchunk.h>
#include <com/ngos/shared/common/graphics/png/lib/pngchunktype.h>
#include <com/ngos/shared/common/graphics/png/lib/pngcolortype.h>
#include <com/ngos/shared/common/graphics/png/lib/pngcompressionmethod.h>
#include <com/ngos/shared/common/graphics/png/lib/pngfiltermethod.h>
#include <com/ngos/shared/common/graphics/png/lib/pngfiltertype.h>
#include <com/ngos/shared/common/graphics/png/lib/pngheader.h>
#include <com/ngos/shared/common/graphics/png/lib/pnginterlacemethod.h>
#include <com/ngos/shared/common/graphics/png/lib/pngrenderingintent.h>
#include <com/ngos/shared/common/graphics/png/lib/pngunitspecifier.h>
#include <com/ngos/shared/common/graphics/png/png.h>
#include <com/ngos/shared/common/graphics/png/pngdecoder.h>
#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/graphics/rgbpixel.h>
#include <com/ngos/shared/common/graphics/stretchrange.h>
#include <com/ngos/shared/common/gui/gui.h>
#include <com/ngos/shared/common/gui/other/horizontalalignment.h>
#include <com/ngos/shared/common/gui/other/presseventhandler.h>
#include <com/ngos/shared/common/gui/other/verticalalignment.h>
#include <com/ngos/shared/common/gui/other/widgetstate.h>
#include <com/ngos/shared/common/gui/widgets/controls/button.h>
#include <com/ngos/shared/common/gui/widgets/controls/tabbutton.h>
#include <com/ngos/shared/common/gui/widgets/controls/tablewidget.h>
#include <com/ngos/shared/common/gui/widgets/controls/tabwidget.h>
#include <com/ngos/shared/common/gui/widgets/controls/toolbutton.h>
#include <com/ngos/shared/common/gui/widgets/controls/treewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/consolewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/cursorwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/imagewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/labelwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/panelwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/progressbarwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/tablecellwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/tableheaderwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/tablerowwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/tabpagewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/treenodewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/wrapperwidget.h>
#include <com/ngos/shared/common/gui/widgets/special/rootwidget.h>
#include <com/ngos/shared/common/gui/widgets/special/screenwidget.h>
#include <com/ngos/shared/common/gui/widgets/widget.h>
#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/hex/hex.h>
#include <com/ngos/shared/common/idt/idtdescriptor.h>
#include <com/ngos/shared/common/idt/idtgatetype.h>
#include <com/ngos/shared/common/idt/idtregister.h>
#include <com/ngos/shared/common/inflate/inflateblocktype.h>
#include <com/ngos/shared/common/inflate/inflatecode.h>
#include <com/ngos/shared/common/inflate/inflatecodetype.h>
#include <com/ngos/shared/common/inflate/inflatedecoder.h>
#include <com/ngos/shared/common/mbr/mbr.h>
#include <com/ngos/shared/common/mbr/mbrpartition.h>
#include <com/ngos/shared/common/mbr/mbrpartitiontype.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/pagetable/types.h>
#include <com/ngos/shared/common/pci/pciregisters.h>
#include <com/ngos/shared/common/serial/serial.h>
#include <com/ngos/shared/common/time/time.h>
#include <com/ngos/shared/common/uefi/config/uefiacpi20configurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefiacpiconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefidebuginfoconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefidxeservicesconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefihcdpconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefihoblistconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefilzmadecompressconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefimemoryattributesconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefimemorystatuscoderecordconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefimemorytypeinformationconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefimpsconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefipropertiesconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefisalsystemconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefismbios3configurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefismbiosconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefisystemresourceconfigurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefiugaioconfigurationtable.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointermode.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointermodeattributeflags.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerprotocol.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerstate.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerstateactivebuttonflags.h>
#include <com/ngos/shared/common/uefi/uefiacpiaddressspacedescriptor.h>
#include <com/ngos/shared/common/uefi/uefiacpidescriptor.h>
#include <com/ngos/shared/common/uefi/uefiacpiresourcetype.h>
#include <com/ngos/shared/common/uefi/uefiallocatetype.h>
#include <com/ngos/shared/common/uefi/uefiblockiomedia.h>
#include <com/ngos/shared/common/uefi/uefiblockioprotocol.h>
#include <com/ngos/shared/common/uefi/uefibootservices.h>
#include <com/ngos/shared/common/uefi/ueficapsuleheader.h>
#include <com/ngos/shared/common/uefi/ueficonfigurationtable.h>
#include <com/ngos/shared/common/uefi/ueficonsolecontrolprotocol.h>
#include <com/ngos/shared/common/uefi/ueficonsolecontrolscreenmode.h>
#include <com/ngos/shared/common/uefi/ueficpuphysicallocation.h>
#include <com/ngos/shared/common/uefi/uefidevicepath.h>
#include <com/ngos/shared/common/uefi/uefidevicepathtotextprotocol.h>
#include <com/ngos/shared/common/uefi/uefieventtype.h>
#include <com/ngos/shared/common/uefi/uefifileattributeflags.h>
#include <com/ngos/shared/common/uefi/uefifileinfo.h>
#include <com/ngos/shared/common/uefi/uefifileiotoken.h>
#include <com/ngos/shared/common/uefi/uefifilemodeflags.h>
#include <com/ngos/shared/common/uefi/uefifilepath.h>
#include <com/ngos/shared/common/uefi/uefifileprotocol.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputbltoperation.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputbltpixel.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputmodeinformation.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputprotocol.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputprotocolmode.h>
#include <com/ngos/shared/common/uefi/uefigraphicspixelformat.h>
#include <com/ngos/shared/common/uefi/uefiharddrivedevicepath.h>
#include <com/ngos/shared/common/uefi/uefiharddrivedevicepathmbrtype.h>
#include <com/ngos/shared/common/uefi/uefiharddrivedevicepathsignaturetype.h>
#include <com/ngos/shared/common/uefi/uefiinputkey.h>
#include <com/ngos/shared/common/uefi/uefiinputkeyscancode.h>
#include <com/ngos/shared/common/uefi/uefiinterfacetype.h>
#include <com/ngos/shared/common/uefi/uefiipaddress.h>
#include <com/ngos/shared/common/uefi/uefiipv4address.h>
#include <com/ngos/shared/common/uefi/uefiipv6address.h>
#include <com/ngos/shared/common/uefi/uefiloadedimageprotocol.h>
#include <com/ngos/shared/common/uefi/uefilocatesearchtype.h>
#include <com/ngos/shared/common/uefi/uefimacaddress.h>
#include <com/ngos/shared/common/uefi/uefimemorydescriptor.h>
#include <com/ngos/shared/common/uefi/uefimemorytype.h>
#include <com/ngos/shared/common/uefi/uefimpservicesprotocol.h>
#include <com/ngos/shared/common/uefi/uefinetworkstatistics.h>
#include <com/ngos/shared/common/uefi/uefiopenprotocolinformationentry.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocol.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolaccess.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolattributeoperation.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolconfigaccess.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocoloperation.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolwidth.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocol.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocolaccess.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocoloperation.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocolwidth.h>
#include <com/ngos/shared/common/uefi/uefipixelbitmask.h>
#include <com/ngos/shared/common/uefi/uefiprocessorinformation.h>
#include <com/ngos/shared/common/uefi/uefiprocessorinformationstatusflags.h>
#include <com/ngos/shared/common/uefi/uefiresettype.h>
#include <com/ngos/shared/common/uefi/uefiruntimeservices.h>
#include <com/ngos/shared/common/uefi/uefisimplefilesystemprotocol.h>
#include <com/ngos/shared/common/uefi/uefisimpleinputinterface.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkinterfacetype.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkinterruptflags.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkmode.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkprotocol.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkreceivefilterflags.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkstate.h>
#include <com/ngos/shared/common/uefi/uefisimplepointermode.h>
#include <com/ngos/shared/common/uefi/uefisimplepointerprotocol.h>
#include <com/ngos/shared/common/uefi/uefisimplepointerstate.h>
#include <com/ngos/shared/common/uefi/uefisimpletextoutputinterface.h>
#include <com/ngos/shared/common/uefi/uefisimpletextoutputmode.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>
#include <com/ngos/shared/common/uefi/uefisystemtable.h>
#include <com/ngos/shared/common/uefi/uefitableheader.h>
#include <com/ngos/shared/common/uefi/uefitime.h>
#include <com/ngos/shared/common/uefi/uefitimecapabilicies.h>
#include <com/ngos/shared/common/uefi/uefitimerdelay.h>
#include <com/ngos/shared/common/uefi/uefitpl.h>
#include <com/ngos/shared/common/uefi/uefivariableattributeflags.h>
#include <com/ngos/shared/common/uuid/uuid.h>
#include <com/ngos/shared/common/zlib/zlib.h>
#include <com/ngos/shared/common/zlib/zlibcompressioninfo.h>
#include <com/ngos/shared/common/zlib/zlibcompressionlevel.h>
#include <com/ngos/shared/common/zlib/zlibcompressionmethod.h>
#include <com/ngos/shared/common/zlib/zlibheader.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(Adler),                                           1);
        TEST_ASSERT_EQUALS(sizeof(AES),                                             64);
        TEST_ASSERT_EQUALS(sizeof(AmdCpuModel),                                     1);
        TEST_ASSERT_EQUALS(sizeof(ArrayList<u8>),                                   24);
        TEST_ASSERT_EQUALS(sizeof(AssetEntry),                                      24);
        TEST_ASSERT_EQUALS(sizeof(Assets),                                          1);
        TEST_ASSERT_EQUALS(sizeof(BitUtils),                                        1);
        TEST_ASSERT_EQUALS(sizeof(Bmp),                                             1);
        TEST_ASSERT_EQUALS(sizeof(BmpColorMap),                                     4);
        TEST_ASSERT_EQUALS(sizeof(BmpCompressionMethod),                            4);
        TEST_ASSERT_EQUALS(sizeof(BmpHeader),                                       14);
        TEST_ASSERT_EQUALS(sizeof(BmpInformationHeader),                            40);
        TEST_ASSERT_EQUALS(sizeof(BootParams),                                      624);
        TEST_ASSERT_EQUALS(sizeof(BootParamsHeader),                                32);
        TEST_ASSERT_EQUALS(sizeof(Button),                                          224);
        TEST_ASSERT_EQUALS(sizeof(Console),                                         1);
        TEST_ASSERT_EQUALS(sizeof(ConsoleWidget),                                   96);
        TEST_ASSERT_EQUALS(sizeof(CPU),                                             1);
        TEST_ASSERT_EQUALS(sizeof(CpuFamily),                                       2);
        TEST_ASSERT_EQUALS(sizeof(CpuVendor),                                       1);
        TEST_ASSERT_EQUALS(sizeof(Crc),                                             1);
        TEST_ASSERT_EQUALS(sizeof(CursorWidget),                                    96);
        TEST_ASSERT_EQUALS(sizeof(DMI),                                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiAdditionalInformation),                        5);
        TEST_ASSERT_EQUALS(sizeof(DmiAdditionalInformationEntry),                   5);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardEntry),                               15);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardFeatureFlag),                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardType),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsBiosReservedFlag),          1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsFlag),                      8);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsSystemReservedFlag),        1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntry),                                    18);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntryV21),                                 19);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntryV23),                                 20);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntryV24),                                 24);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntryV31),                                 26);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosExtendedRomSize),                          2);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosExtendedRomSizeUnit),                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosLanguageEntry),                            22);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosLanguageFlag),                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosRomSize),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits32MemoryErrorInformationEntry),            23);
        TEST_ASSERT_EQUALS(sizeof(DmiBits32MemoryErrorInformationErrorGranularity), 1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits32MemoryErrorInformationErrorOperation),   1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits32MemoryErrorInformationErrorType),        1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits64MemoryErrorInformationEntry),            31);
        TEST_ASSERT_EQUALS(sizeof(DmiBits64MemoryErrorInformationErrorGranularity), 1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits64MemoryErrorInformationErrorOperation),   1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits64MemoryErrorInformationErrorType),        1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheAssociativity),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheConfiguration),                           2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheEntry),                                   15);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheEntryV21),                                19);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheEntryV31),                                27);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheErrorCorrectionType),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheLocation),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheOperationalMode),                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSize),                                    2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSize2),                                   4);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSizeGranularity),                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSramTypeFlag),                            2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheType),                                    1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisContainedElement),                      3);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisContainedElementType),                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisContainedElementTypeSelect),            1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntry),                                 9);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntryV21),                              13);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntryV23),                              21);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntryV27),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisSecurityStatus),                        1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisState),                                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceEntry),                           14);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceEntryV27),                        15);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceStatus),                          1);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceType),                            1);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeEntry),                  22);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeLocation),               1);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeStatus),                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiEntryHeader),                                  4);
        TEST_ASSERT_EQUALS(sizeof(DmiEntryType),                                    1);
        TEST_ASSERT_EQUALS(sizeof(DmiGroupAssociationsEntry),                       5);
        TEST_ASSERT_EQUALS(sizeof(DmiGroupAssociationsItem),                        3);
        TEST_ASSERT_EQUALS(sizeof(DmiHardwareSecurityEntry),                        5);
        TEST_ASSERT_EQUALS(sizeof(DmiHardwareSecuritySettings),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiHardwareSecurityStatus),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiIdentity),                                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiInactiveEntry),                                4);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceAddressType),                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceComponentEntry),               11);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceEntry),                        11);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceThresholdDataEntry),           16);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceType),                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryArrayMappedAddressEntry),                15);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryArrayMappedAddressEntryV27),             31);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryArrayMappedAddressRange),                4);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDevice),                                 64);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceAttributes),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntry),                            21);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV23),                         27);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV26),                         28);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV27),                         34);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV28),                         40);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV32),                         84);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV33),                         92);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceExtendedSize),                     4);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceFormFactor),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceMappedAddressEntry),               19);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceMappedAddressEntryV27),            35);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceMappedAddressRange),               4);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceOperatingModeCapabilityFlag),      2);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceSize),                             2);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceSizeGranularity),                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceTechnology),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceType),                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceTypeDetailFlag),                   2);
        TEST_ASSERT_EQUALS(sizeof(DmiOemStringsEntry),                              5);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesDevice),                         2);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesDeviceType),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesEntry),                          4);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesExtendedDeviceType),             1);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesExtendedEntry),                  11);
        TEST_ASSERT_EQUALS(sizeof(DmiOutOfBandRemoteAccessConnectionFlag),          1);
        TEST_ASSERT_EQUALS(sizeof(DmiOutOfBandRemoteAccessEntry),                   6);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayEntry),                     15);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayEntryV27),                  23);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayErrorCorrection),           1);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayLocation),                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayMaximumCapacity),           4);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayUse),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryDeviceChemistry),               1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryEntry),                         16);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryEntryV22),                      26);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryManufactureDate),               2);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorEntry),                           9);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorPortType),                        1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorType),                            1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorCharacteristicsFlag),                 2);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntry),                               26);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV21),                            32);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV23),                            35);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV25),                            40);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV26),                            42);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV30),                            48);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFamily),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFamily2),                             2);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFeatureFlag),                         4);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorId),                                  8);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorSignature),                           4);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorStatus),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorType),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorUpgrade),                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorVoltage),                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorVoltageFlag),                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorVoltageModeType),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiStoredUuid),                                   1);
        TEST_ASSERT_EQUALS(sizeof(DmiStringId),                                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemBootEntry),                              11);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemBootStatus),                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemConfigurationEntry),                     5);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemEntry),                                  8);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemEntryV21),                               25);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemEntryV24),                               27);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyCharacteristics),             2);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyEntry),                       22);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyInputVoltageRangeSwitch),     1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyStatus),                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyType),                        1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemResetBootOption),                        1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemResetCapabilities),                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemResetEntry),                             13);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsCharacteristicsFlag),               2);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsDataBusWidth),                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsEntry),                             13);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsEntryV26),                          17);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsEntryV32),                          19);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsLength),                            1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsPeerGroup),                         5);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsType),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsUsage),                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemWakeUpType),                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeEntry),                        22);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeLocation),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeStatus),                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeEntry),                            22);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeLocation),                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeStatus),                           1);
        TEST_ASSERT_EQUALS(sizeof(ElfClass),                                        1);
        TEST_ASSERT_EQUALS(sizeof(ElfData),                                         1);
        TEST_ASSERT_EQUALS(sizeof(ElfFileVersion),                                  1);
        TEST_ASSERT_EQUALS(sizeof(ElfHeader),                                       64);
        TEST_ASSERT_EQUALS(sizeof(ElfHeaderIdentification),                         16);
        TEST_ASSERT_EQUALS(sizeof(ElfMachine),                                      2);
        TEST_ASSERT_EQUALS(sizeof(ElfOsAbi),                                        1);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramFlag),                                  4);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramHeaderTableEntry),                      56);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramType),                                  4);
        TEST_ASSERT_EQUALS(sizeof(ElfRela),                                         24);
        TEST_ASSERT_EQUALS(sizeof(ElfRelaType),                                     4);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionFlag),                                  8);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionHeaderTableEntry),                      64);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionType),                                  4);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbol),                                       24);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolBind),                                   1);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolType),                                   1);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolVisibility),                             1);
        TEST_ASSERT_EQUALS(sizeof(ElfType),                                         2);
        TEST_ASSERT_EQUALS(sizeof(ElfVersion),                                      4);
        TEST_ASSERT_EQUALS(sizeof(FPU),                                             1);
        TEST_ASSERT_EQUALS(sizeof(FpuState),                                        4096);
        TEST_ASSERT_EQUALS(sizeof(FSaveState),                                      112);
        TEST_ASSERT_EQUALS(sizeof(FXSaveState),                                     512);
        TEST_ASSERT_EQUALS(sizeof(GdtDescriptor),                                   8);
        TEST_ASSERT_EQUALS(sizeof(GdtRegister),                                     10);
        TEST_ASSERT_EQUALS(sizeof(GlyphData),                                       5);
        TEST_ASSERT_EQUALS(sizeof(GptData),                                         24);
        TEST_ASSERT_EQUALS(sizeof(GptEntry),                                        128);
        TEST_ASSERT_EQUALS(sizeof(GptHeader),                                       96);
        TEST_ASSERT_EQUALS(sizeof(GraphicalConsole),                                1);
        TEST_ASSERT_EQUALS(sizeof(Graphics),                                        1);
        TEST_ASSERT_EQUALS(sizeof(GUI),                                             1);
        TEST_ASSERT_EQUALS(sizeof(Guid),                                            16);
        TEST_ASSERT_EQUALS(sizeof(Hex),                                             1);
        TEST_ASSERT_EQUALS(sizeof(HorizontalAlignment),                             1);
        TEST_ASSERT_EQUALS(sizeof(IdtDescriptor),                                   16);
        TEST_ASSERT_EQUALS(sizeof(IdtGateType),                                     1);
        TEST_ASSERT_EQUALS(sizeof(IdtRegister),                                     10);
        TEST_ASSERT_EQUALS(sizeof(Image),                                           32);
        TEST_ASSERT_EQUALS(sizeof(ImageWidget),                                     104);
        TEST_ASSERT_EQUALS(sizeof(InflateBlockType),                                1);
        TEST_ASSERT_EQUALS(sizeof(InflateCode),                                     4);
        TEST_ASSERT_EQUALS(sizeof(InflateCodeType),                                 1);
        TEST_ASSERT_EQUALS(sizeof(InflateDecoder),                                  40);
        TEST_ASSERT_EQUALS(sizeof(IntelCpuModel),                                   1);
        TEST_ASSERT_EQUALS(sizeof(Jpeg),                                            1);
        TEST_ASSERT_EQUALS(sizeof(JpegComponent),                                   56);
        TEST_ASSERT_EQUALS(sizeof(JpegComponentId),                                 1);
        TEST_ASSERT_EQUALS(sizeof(JpegDecoder),                                     808);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineHuffmanTableMarker),                    4);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineQuantizationTableMarker),               4);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineRestartIntervalMarker),                 6);
        TEST_ASSERT_EQUALS(sizeof(JpegHuffmanTable),                                17);
        TEST_ASSERT_EQUALS(sizeof(JpegHuffmanTableType),                            1);
        TEST_ASSERT_EQUALS(sizeof(JpegMarkerHeader),                                4);
        TEST_ASSERT_EQUALS(sizeof(JpegMarkerType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(JpegQuantizationTable),                           1);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfFrameComponent),                       3);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfFrameMarker),                          10);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfScanComponent),                        2);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfScanMarker),                           5);
        TEST_ASSERT_EQUALS(sizeof(JpegVlcCode),                                     2);
        TEST_ASSERT_EQUALS(sizeof(LabelWidget),                                     112);
        TEST_ASSERT_EQUALS(sizeof(ListElement<u8>),                                 24);
        TEST_ASSERT_EQUALS(sizeof(List<u8>),                                        16);
        TEST_ASSERT_EQUALS(sizeof(MapElement<u8, u32>),                             8);
        TEST_ASSERT_EQUALS(sizeof(Map<u8, u32>),                                    24);
        TEST_ASSERT_EQUALS(sizeof(Mbr),                                             512);
        TEST_ASSERT_EQUALS(sizeof(MbrPartition),                                    16);
        TEST_ASSERT_EQUALS(sizeof(MbrPartitionType),                                1);
        TEST_ASSERT_EQUALS(sizeof(MD5),                                             96);
        TEST_ASSERT_EQUALS(sizeof(Md5Hash),                                         16);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntry),                                  24);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntryType),                              1);
        TEST_ASSERT_EQUALS(sizeof(MpxBoundRegister),                                16);
        TEST_ASSERT_EQUALS(sizeof(MSR),                                             1);
        TEST_ASSERT_EQUALS(sizeof(NgosStatus),                                      8);
        TEST_ASSERT_EQUALS(sizeof(NinePatch),                                       40);
        TEST_ASSERT_EQUALS(sizeof(PanelWidget),                                     104);
        TEST_ASSERT_EQUALS(sizeof(PciRegister),                                     1);
        TEST_ASSERT_EQUALS(sizeof(PciRomImageWithInfo),                             56);
        TEST_ASSERT_EQUALS(sizeof(PGD),                                             8);
        TEST_ASSERT_EQUALS(sizeof(PMD),                                             8);
        TEST_ASSERT_EQUALS(sizeof(Png),                                             1);
        TEST_ASSERT_EQUALS(sizeof(PngChunk),                                        8);
        TEST_ASSERT_EQUALS(sizeof(PngChunkType),                                    4);
        TEST_ASSERT_EQUALS(sizeof(PngColorType),                                    1);
        TEST_ASSERT_EQUALS(sizeof(PngCompressionMethod),                            1);
        TEST_ASSERT_EQUALS(sizeof(PngDecoder),                                      112);
        TEST_ASSERT_EQUALS(sizeof(PngEmbeddedIccProfile),                           80);
        TEST_ASSERT_EQUALS(sizeof(PngFilterMethod),                                 1);
        TEST_ASSERT_EQUALS(sizeof(PngFilterType),                                   1);
        TEST_ASSERT_EQUALS(sizeof(PngHeader),                                       16);
        TEST_ASSERT_EQUALS(sizeof(PngImageGamma),                                   4);
        TEST_ASSERT_EQUALS(sizeof(PngImageHeader),                                  13);
        TEST_ASSERT_EQUALS(sizeof(PngImageLastModificationTime),                    7);
        TEST_ASSERT_EQUALS(sizeof(PngInterlaceMethod),                              1);
        TEST_ASSERT_EQUALS(sizeof(PngPhysicalPixelDimensions),                      9);
        TEST_ASSERT_EQUALS(sizeof(PngPrimaryChromaticities),                        32);
        TEST_ASSERT_EQUALS(sizeof(PngRenderingIntent),                              1);
        TEST_ASSERT_EQUALS(sizeof(PngSignificantBits),                              4);
        TEST_ASSERT_EQUALS(sizeof(PngStandardRgbColorSpace),                        1);
        TEST_ASSERT_EQUALS(sizeof(PngUnitSpecifier),                                1);
        TEST_ASSERT_EQUALS(sizeof(PressEventHandler),                               8);
        TEST_ASSERT_EQUALS(sizeof(ProgressBarWidget),                               152);
        TEST_ASSERT_EQUALS(sizeof(PTE),                                             8);
        TEST_ASSERT_EQUALS(sizeof(PUD),                                             8);
        TEST_ASSERT_EQUALS(sizeof(Register128Bit),                                  16);
        TEST_ASSERT_EQUALS(sizeof(Register256Bit),                                  32);
        TEST_ASSERT_EQUALS(sizeof(Register512Bit),                                  64);
        TEST_ASSERT_EQUALS(sizeof(RgbaPixel),                                       4);
        TEST_ASSERT_EQUALS(sizeof(RgbPixel),                                        3);
        TEST_ASSERT_EQUALS(sizeof(RootWidget),                                      104);
        TEST_ASSERT_EQUALS(sizeof(ScreenWidget),                                    144);
        TEST_ASSERT_EQUALS(sizeof(Serial),                                          1);
        TEST_ASSERT_EQUALS(sizeof(StretchRange),                                    4);
        TEST_ASSERT_EQUALS(sizeof(TabButton),                                       304);
        TEST_ASSERT_EQUALS(sizeof(TableCellWidget),                                 88);
        TEST_ASSERT_EQUALS(sizeof(TableHeaderWidget),                               104);
        TEST_ASSERT_EQUALS(sizeof(TableRowWidget),                                  120);
        TEST_ASSERT_EQUALS(sizeof(TableWidget),                                     240);
        TEST_ASSERT_EQUALS(sizeof(TabPageWidget),                                   88);
        TEST_ASSERT_EQUALS(sizeof(TabWidget),                                       152);
        TEST_ASSERT_EQUALS(sizeof(Time),                                            1);
        TEST_ASSERT_EQUALS(sizeof(ToolButton),                                      192);
        TEST_ASSERT_EQUALS(sizeof(TreeNodeWidget),                                  216);
        TEST_ASSERT_EQUALS(sizeof(TreeWidget),                                      176);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerMode),                         56);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerModeAttributeFlag),            4);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerProtocol),                     32);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerState),                        32);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerStateActiveButtonFlag),        4);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpi20ConfigurationTable),                    1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiAddressSpaceDescriptor),                  46);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiConfigurationTable),                      1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiDescriptor),                              1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiResourceType),                            1);
        TEST_ASSERT_EQUALS(sizeof(UefiAllocateType),                                4);
        TEST_ASSERT_EQUALS(sizeof(UefiBlockIoMedia),                                48);
        TEST_ASSERT_EQUALS(sizeof(UefiBlockIoProtocol),                             48);
        TEST_ASSERT_EQUALS(sizeof(UefiBootServices),                                376);
        TEST_ASSERT_EQUALS(sizeof(UefiCapsuleHeader),                               28);
        TEST_ASSERT_EQUALS(sizeof(UefiConfigurationTable),                          24);
        TEST_ASSERT_EQUALS(sizeof(UefiConsoleControlProtocol),                      24);
        TEST_ASSERT_EQUALS(sizeof(UefiConsoleControlScreenMode),                    4);
        TEST_ASSERT_EQUALS(sizeof(UefiCpuPhysicalLocation),                         12);
        TEST_ASSERT_EQUALS(sizeof(UefiDebugInfoConfigurationTable),                 1);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePath),                                  4);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathSubType),                           1);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathToTextProtocol),                    16);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathType),                              1);
        TEST_ASSERT_EQUALS(sizeof(UefiDxeServicesConfigurationTable),               1);
        TEST_ASSERT_EQUALS(sizeof(UefiEventType),                                   4);
        TEST_ASSERT_EQUALS(sizeof(UefiFileAttributeFlag),                           8);
        TEST_ASSERT_EQUALS(sizeof(UefiFileInfo),                                    80);
        TEST_ASSERT_EQUALS(sizeof(UefiFileIoToken),                                 32);
        TEST_ASSERT_EQUALS(sizeof(UefiFileModeFlag),                                8);
        TEST_ASSERT_EQUALS(sizeof(UefiFilePath),                                    4);
        TEST_ASSERT_EQUALS(sizeof(UefiFileProtocol),                                120);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputBltOperation),                  4);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputBltPixel),                      4);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputModeInformation),               36);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputProtocol),                      32);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputProtocolMode),                  40);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsPixelFormat),                         4);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePath),                         48);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePathMbrType),                  1);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePathSignatureType),            1);
        TEST_ASSERT_EQUALS(sizeof(UefiHcdpConfigurationTable),                      1);
        TEST_ASSERT_EQUALS(sizeof(UefiHobListConfigurationTable),                   1);
        TEST_ASSERT_EQUALS(sizeof(UefiInfo),                                        40);
        TEST_ASSERT_EQUALS(sizeof(UefiInputKey),                                    4);
        TEST_ASSERT_EQUALS(sizeof(UefiInputKeyScanCode),                            2);
        TEST_ASSERT_EQUALS(sizeof(UefiInterfaceType),                               4);
        TEST_ASSERT_EQUALS(sizeof(UefiIpAddress),                                   16);
        TEST_ASSERT_EQUALS(sizeof(UefiIpV4Address),                                 4);
        TEST_ASSERT_EQUALS(sizeof(UefiIpV6Address),                                 16);
        TEST_ASSERT_EQUALS(sizeof(UefiLoadedImageProtocol),                         96);
        TEST_ASSERT_EQUALS(sizeof(UefiLocateSearchType),                            4);
        TEST_ASSERT_EQUALS(sizeof(UefiLzmaDecompressConfigurationTable),            1);
        TEST_ASSERT_EQUALS(sizeof(UefiMacAddress),                                  32);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryAttributesConfigurationTable),          16);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryDescriptor),                            40);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryMapInfo),                               32);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryStatusCodeRecordConfigurationTable),    1);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryType),                                  4);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryTypeInformationConfigurationTable),     1);
        TEST_ASSERT_EQUALS(sizeof(UefiMpsConfigurationTable),                       1);
        TEST_ASSERT_EQUALS(sizeof(UefiMpServicesProtocol),                          56);
        TEST_ASSERT_EQUALS(sizeof(UefiNetworkStatistics),                           208);
        TEST_ASSERT_EQUALS(sizeof(UefiOpenProtocolInformationEntry),                24);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocol),                               160);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAccess),                         16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAttributeOperation),             4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolConfigAccess),                   16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolOperation),                      4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolWidth),                          4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciRootBridgeIoProtocol),                     152);
        TEST_ASSERT_EQUALS(sizeof(UefiPciRootBridgeIoProtocolAccess),               16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciRootBridgeIoProtocolOperation),            4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciRootBridgeIoProtocolWidth),                4);
        TEST_ASSERT_EQUALS(sizeof(UefiPixelBitmask),                                16);
        TEST_ASSERT_EQUALS(sizeof(UefiProcessorInformation),                        24);
        TEST_ASSERT_EQUALS(sizeof(UefiProcessorInformationStatusFlag),              4);
        TEST_ASSERT_EQUALS(sizeof(UefiPropertiesConfigurationTable),                1);
        TEST_ASSERT_EQUALS(sizeof(UefiResetType),                                   4);
        TEST_ASSERT_EQUALS(sizeof(UefiRuntimeServices),                             136);
        TEST_ASSERT_EQUALS(sizeof(UefiSalSystemConfigurationTable),                 1);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleFileSystemProtocol),                    16);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleInputInterface),                        24);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkInterfaceType),                  1);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkInterruptFlag),                  4);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkMode),                           656);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkProtocol),                       128);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkReceiveFilterFlag),              4);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkState),                          4);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerMode),                           32);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerProtocol),                       32);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerState),                          16);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleTextOutputInterface),                   80);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleTextOutputMode),                        24);
        TEST_ASSERT_EQUALS(sizeof(UefiSmbios3ConfigurationTable),                   24);
        TEST_ASSERT_EQUALS(sizeof(UefiSmbiosConfigurationTable),                    31);
        TEST_ASSERT_EQUALS(sizeof(UefiStatus),                                      8);
        TEST_ASSERT_EQUALS(sizeof(UefiSystemResourceConfigurationTable),            1);
        TEST_ASSERT_EQUALS(sizeof(UefiSystemTable),                                 120);
        TEST_ASSERT_EQUALS(sizeof(UefiTableHeader),                                 24);
        TEST_ASSERT_EQUALS(sizeof(UefiTime),                                        16);
        TEST_ASSERT_EQUALS(sizeof(UefiTimeCapabilities),                            12);
        TEST_ASSERT_EQUALS(sizeof(UefiTimerDelay),                                  4);
        TEST_ASSERT_EQUALS(sizeof(UefiTpl),                                         8);
        TEST_ASSERT_EQUALS(sizeof(UefiUgaIoConfigurationTable),                     1);
        TEST_ASSERT_EQUALS(sizeof(UefiVariableAttributeFlag),                       4);
        TEST_ASSERT_EQUALS(sizeof(Uuid),                                            16);
        TEST_ASSERT_EQUALS(sizeof(VerticalAlignment),                               1);
        TEST_ASSERT_EQUALS(sizeof(Widget),                                          88);
        TEST_ASSERT_EQUALS(sizeof(WidgetState),                                     1);
        TEST_ASSERT_EQUALS(sizeof(WrapperWidget),                                   88);
        TEST_ASSERT_EQUALS(sizeof(X86Bug),                                          2);
        TEST_ASSERT_EQUALS(sizeof(x86BugWord),                                      1);
        TEST_ASSERT_EQUALS(sizeof(X86Feature),                                      2);
        TEST_ASSERT_EQUALS(sizeof(x86FeatureWord),                                  1);
        TEST_ASSERT_EQUALS(sizeof(XFeature),                                        1);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512OpmaskState),                       64);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512ZmmFrom0To15State),                 512);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512ZmmFrom16To31State),                1024);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvxState),                                256);
        TEST_ASSERT_EQUALS(sizeof(XFeatureFlag),                                    4);
        TEST_ASSERT_EQUALS(sizeof(XFeatureMpxBoundConfigAndStatusRegistersState),   64);
        TEST_ASSERT_EQUALS(sizeof(XFeatureMpxBoundRegistersState),                  64);
        TEST_ASSERT_EQUALS(sizeof(XFeaturePkruState),                               8);
        TEST_ASSERT_EQUALS(sizeof(XFeatureTypeFlag),                                8);
        TEST_ASSERT_EQUALS(sizeof(XSaveState),                                      576);
        TEST_ASSERT_EQUALS(sizeof(XStateHeader),                                    64);
        TEST_ASSERT_EQUALS(sizeof(ZLib),                                            1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionInfo),                             1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionLevel),                            1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionMethod),                           1);
        TEST_ASSERT_EQUALS(sizeof(ZLibHeader),                                      2);

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(sizeof(P4D), 8);
#endif
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

        TEST_ASSERT_EQUALS(temp.value,       5);
        TEST_ASSERT_EQUALS(temp.granularity, 1);



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

        TEST_ASSERT_EQUALS(temp.value,       5);
        TEST_ASSERT_EQUALS(temp.granularity, 1);



        temp.value = 8;             // ||  1  |  0000000000000000000000000001000  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x80000008);



        temp.granularity = 0;       // ||  0  |  0000000000000000000000000001000  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x00000008);
    }
    TEST_CASE_END();



    TEST_CASE("DmiChassisContainedElementType");
    {
        DmiChassisContainedElementType temp;



        //  DmiChassisContainedElementType - value8:
        // ==========================================================
        // |  typeSelect : 1  |  baseboardType or dmiEntryType : 7  |
        // ==========================================================



        temp.value8 = 0x6A;         // ||  0  |  1101010  ||

        TEST_ASSERT_EQUALS(temp.typeSelect,    0);
        TEST_ASSERT_EQUALS(temp.baseboardType, 106);
        TEST_ASSERT_EQUALS(temp.dmiEntryType,  106);



        temp.typeSelect = 1;        // ||  1  |  1101010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0xEA);



        temp.baseboardType = 5;     // ||  1  |  0000101  ||

        TEST_ASSERT_EQUALS(temp.value8,       0x85);
        TEST_ASSERT_EQUALS(temp.dmiEntryType, 5);



        temp.dmiEntryType = 2;      // ||  1  |  0000010  ||

        TEST_ASSERT_EQUALS(temp.value8,        0x82);
        TEST_ASSERT_EQUALS(temp.baseboardType, 2);
    }
    TEST_CASE_END();



    TEST_CASE("DmiChassisEntry");
    {
        DmiChassisEntry temp;



        //  DmiChassisEntry - typeAndLocked:
        // =============================
        // |  locked : 1  |  type : 7  |
        // =============================



        temp.typeAndLocked = 0x85;  // ||  1  |  0000101  ||

        TEST_ASSERT_EQUALS(temp.type,   5);
        TEST_ASSERT_EQUALS(temp.locked, 1);



        temp.type = 10;             // ||  1  |  0001010  ||

        TEST_ASSERT_EQUALS(temp.typeAndLocked, 0x8A);



        temp.locked = 0;            // ||  0  |  0001010  ||

        TEST_ASSERT_EQUALS(temp.typeAndLocked, 0x0A);
    }
    TEST_CASE_END();



    TEST_CASE("DmiCoolingDeviceEntry");
    {
        DmiCoolingDeviceEntry temp;



        //  DmiCoolingDeviceEntry - deviceTypeAndStatus:
        // ===================================
        // |  status : 3  |  deviceType : 5  |
        // ===================================



        temp.deviceTypeAndStatus = 0x45;    // ||  010  |  00101  ||

        TEST_ASSERT_EQUALS(temp.deviceType, 5);
        TEST_ASSERT_EQUALS(temp.status,     2);



        temp.deviceType = 8;                // ||  010  |  01000  ||

        TEST_ASSERT_EQUALS(temp.deviceTypeAndStatus, 0x48);



        temp.status = 1;                    // ||  001  |  01000  ||

        TEST_ASSERT_EQUALS(temp.deviceTypeAndStatus, 0x28);
    }
    TEST_CASE_END();



    TEST_CASE("DmiElectricalCurrentProbeEntry");
    {
        DmiElectricalCurrentProbeEntry temp;



        //  DmiElectricalCurrentProbeEntry - locationAndStatus:
        // =================================
        // |  status : 3  |  location : 5  |
        // =================================



        temp.locationAndStatus = 0x45;      // ||  010  |  00101  ||

        TEST_ASSERT_EQUALS(temp.location, 5);
        TEST_ASSERT_EQUALS(temp.status,   2);



        temp.location = 8;                  // ||  010  |  01000  ||

        TEST_ASSERT_EQUALS(temp.locationAndStatus, 0x48);



        temp.status = 1;                    // ||  001  |  01000  ||

        TEST_ASSERT_EQUALS(temp.locationAndStatus, 0x28);
    }
    TEST_CASE_END();



    TEST_CASE("DmiHardwareSecuritySettings");
    {
        DmiHardwareSecuritySettings temp;



        //  DmiHardwareSecuritySettings - value8:
        // ================================================================================================================================
        // |  powerOnPasswordStatus : 2  |  keyboardPasswordStatus : 2  |  administratorPasswordStatus : 2  |  frontPanelResetStatus : 2  |
        // ================================================================================================================================



        temp.value8 = 0x1B;                     // ||  00  |  01  |  10  |  11  ||

        TEST_ASSERT_EQUALS(temp.frontPanelResetStatus,       3);
        TEST_ASSERT_EQUALS(temp.administratorPasswordStatus, 2);
        TEST_ASSERT_EQUALS(temp.keyboardPasswordStatus,      1);
        TEST_ASSERT_EQUALS(temp.powerOnPasswordStatus,       0);



        temp.frontPanelResetStatus = 2;         // ||  00  |  01  |  10  |  10  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x1A);



        temp.administratorPasswordStatus = 1;   // ||  00  |  01  |  01  |  10  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x16);



        temp.keyboardPasswordStatus = 0;        // ||  00  |  00  |  01  |  10  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x06);



        temp.powerOnPasswordStatus = 1;         // ||  01  |  00  |  01  |  10  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x46);
    }
    TEST_CASE_END();



    TEST_CASE("DmiMemoryDeviceAttributes");
    {
        DmiMemoryDeviceAttributes temp;



        //  DmiMemoryDeviceAttributes - value8:
        // =================================
        // |  __reserved : 4  |  rank : 4  |
        // =================================



        temp.value8 = 0x95;     // ||  1001  |  0101  ||

        TEST_ASSERT_EQUALS(temp.rank,       5);
        TEST_ASSERT_EQUALS(temp.__reserved, 9);



        temp.rank = 8;          // ||  1001  |  1000  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x98);



        temp.__reserved = 0;    // ||  0000  |  1000  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x08);
    }
    TEST_CASE_END();



    TEST_CASE("DmiMemoryDeviceExtendedSize");
    {
        DmiMemoryDeviceExtendedSize temp;



        //  DmiMemoryDeviceExtendedSize - value32:
        // ====================================
        // |  __reserved : 1  |  value : 31  |
        // ====================================



        temp.value32 = 0x80000005;  // ||  1  |  0000000000000000000000000000101  ||

        TEST_ASSERT_EQUALS(temp.value,      5);
        TEST_ASSERT_EQUALS(temp.__reserved, 1);



        temp.value = 8;             // ||  1  |  0000000000000000000000000001000  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x80000008);



        temp.__reserved = 0;        // ||  0  |  0000000000000000000000000001000  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x00000008);
    }
    TEST_CASE_END();



    TEST_CASE("DmiMemoryDeviceSize");
    {
        DmiMemoryDeviceSize temp;



        //  DmiMemoryDeviceSize - value16:
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



    TEST_CASE("DmiOnboardDevicesDevice");
    {
        DmiOnboardDevicesDevice temp;



        //  DmiOnboardDevicesDevice - deviceTypeAndEnabled:
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



    TEST_CASE("DmiPortableBatteryManufactureDate");
    {
        DmiPortableBatteryManufactureDate temp;



        //  DmiPortableBatteryManufactureDate - value16:
        // =========================================
        // |  year : 7  |  month : 4  |  date : 5  |
        // =========================================



        temp.value16 = 0x4BB6;    // ||  0100101  |  1101  |  10110  ||

        TEST_ASSERT_EQUALS(temp.date,  22);
        TEST_ASSERT_EQUALS(temp.month, 13);
        TEST_ASSERT_EQUALS(temp.year,  37);



        temp.date = 26;         // ||  0100101  |  1101  |  11010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4BBA);



        temp.month = 7;         // ||  0100101  |  0111  |  11010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4AFA);



        temp.year = 7;          // ||  0000111  |  0111  |  11010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x0EFA);
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



    TEST_CASE("DmiProcessorSignature");
    {
        DmiProcessorSignature temp;



        //  DmiProcessorSignature - value32:
        // =========================================================
        // |           model : 4           |      stepping : 4     |
        // |  __reserved : 2  |  type : 2  |       family : 4      |
        // |      -extendedFamily : 8      |   extendedModel : 4   |
        // |        __reserved2 : 4        |  extendedFamily- : 8  |
        // =========================================================



        temp.value32 = 0x5AAB65D6;      // ||  0101  |  10101010  |  1011  ||  01  |  10  |  0101  ||  1101  |  0110  ||

        TEST_ASSERT_EQUALS(temp.stepping,       6);
        TEST_ASSERT_EQUALS(temp.model,          13);
        TEST_ASSERT_EQUALS(temp.family,         5);
        TEST_ASSERT_EQUALS(temp.type,           2);
        TEST_ASSERT_EQUALS(temp.__reserved,     1);
        TEST_ASSERT_EQUALS(temp.extendedModel,  11);
        TEST_ASSERT_EQUALS(temp.extendedFamily, 170);
        TEST_ASSERT_EQUALS(temp.__reserved2,    5);



        temp.stepping = 11;             // ||  0101  |  10101010  |  1011  ||  01  |  10  |  0101  ||  1101  |  1011 ||

        TEST_ASSERT_EQUALS(temp.value32, 0x5AAB65DB);



        temp.model = 5;                 // ||  0101  |  10101010  |  1011  ||  01  |  10  |  0101  ||  0101  |  1011 ||

        TEST_ASSERT_EQUALS(temp.value32, 0x5AAB655B);



        temp.family = 2;                // ||  0101  |  10101010  |  1011  ||  01  |  10  |  0010  ||  0101  |  1011 ||

        TEST_ASSERT_EQUALS(temp.value32, 0x5AAB625B);



        temp.type = 1;                  // ||  0101  |  10101010  |  1011  ||  01  |  01  |  0010  ||  0101  |  1011 ||

        TEST_ASSERT_EQUALS(temp.value32, 0x5AAB525B);



        temp.__reserved = 3;            // ||  0101  |  10101010  |  1011  ||  11  |  01  |  0010  ||  0101  |  1011 ||

        TEST_ASSERT_EQUALS(temp.value32, 0x5AABD25B);



        temp.extendedModel = 8;         // ||  0101  |  10101010  |  1000  ||  11  |  01  |  0010  ||  0101  |  1011 ||

        TEST_ASSERT_EQUALS(temp.value32, 0x5AA8D25B);



        temp.extendedFamily = 21;       // ||  0101  |  00010101  |  1000  ||  11  |  01  |  0010  ||  0101  |  1011 ||

        TEST_ASSERT_EQUALS(temp.value32, 0x5158D25B);



        temp.__reserved2 = 7;           // ||  0111  |  00010101  |  1000  ||  11  |  01  |  0010  ||  0101  |  1011 ||

        TEST_ASSERT_EQUALS(temp.value32, 0x7158D25B);
    }
    TEST_CASE_END();



    TEST_CASE("DmiProcessorVoltage");
    {
        DmiProcessorVoltage temp;



        //  DmiProcessorVoltage - value8:
        // =========================================
        // |  modeType : 1  |  flags or value : 7  |
        // =========================================



        temp.value8 = 0x6A;     // ||  0  |  1101010  ||

        TEST_ASSERT_EQUALS(temp.modeType, 0);
        TEST_ASSERT_EQUALS(temp.flags,    106);
        TEST_ASSERT_EQUALS(temp.value,    106);



        temp.modeType = 1;      // ||  1  |  1101010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0xEA);



        temp.flags = 5;         // ||  1  |  0000101  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x85);
        TEST_ASSERT_EQUALS(temp.value,  5);



        temp.value = 2;         // ||  1  |  0000010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x82);
        TEST_ASSERT_EQUALS(temp.flags,  2);
    }
    TEST_CASE_END();



    TEST_CASE("DmiSystemPowerSupplyCharacteristics");
    {
        DmiSystemPowerSupplyCharacteristics temp;



        //  DmiSystemPowerSupplyCharacteristics - value16:
        // =========================================================================================================================================
        // |  __reserved : 2  |  type : 4  |  status : 3  |  inputVoltageRangeSwitch : 4  |  unplugged : 1  |  present : 1  |  hotReplaceable : 1  |
        // =========================================================================================================================================



        temp.value16 = 0x97AA;              // ||  10  |  0101  |  111  |  0101  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.hotReplaceable,          0);
        TEST_ASSERT_EQUALS(temp.present,                 1);
        TEST_ASSERT_EQUALS(temp.unplugged,               0);
        TEST_ASSERT_EQUALS(temp.inputVoltageRangeSwitch, 5);
        TEST_ASSERT_EQUALS(temp.status,                  7);
        TEST_ASSERT_EQUALS(temp.type,                    5);
        TEST_ASSERT_EQUALS(temp.__reserved,              2);



        temp.hotReplaceable = 1;            // ||  10  |  0101  |  111  |  0101  |  0  |  1  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x97AB);



        temp.present = 0;                   // ||  10  |  0101  |  111  |  0101  |  0  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x97A9);



        temp.unplugged = 1;                 // ||  10  |  0101  |  111  |  0101  |  1  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x97AD);



        temp.inputVoltageRangeSwitch = 8;   // ||  10  |  0101  |  111  |  1000  |  1  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x97C5);



        temp.status = 2;                    // ||  10  |  0101  |  010  |  1000  |  1  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x9545);



        temp.type = 8;                      // ||  10  |  1000  |  010  |  1000  |  1  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xA145);



        temp.__reserved = 1;                // ||  01  |  1000  |  010  |  1000  |  1  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x6145);
    }
    TEST_CASE_END();



    TEST_CASE("DmiSystemResetCapabilities");
    {
        DmiSystemResetCapabilities temp;



        //  DmiSystemResetCapabilities - value8:
        // =========================================================================================================
        // |  __reserved : 2  |  watchdogEnabled : 1  |  bootOptionOnLimit : 2  |  bootOption : 2  |  enabled : 1  |
        // =========================================================================================================



        temp.value8 = 0x5D;             // ||  01  |  0  |  11  |  10  |  1  ||

        TEST_ASSERT_EQUALS(temp.enabled,           1);
        TEST_ASSERT_EQUALS(temp.bootOption,        2);
        TEST_ASSERT_EQUALS(temp.bootOptionOnLimit, 3);
        TEST_ASSERT_EQUALS(temp.watchdogEnabled,   0);
        TEST_ASSERT_EQUALS(temp.__reserved,        1);



        temp.enabled = 0;               // ||  01  |  0  |  11  |  10  |  0  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x5C);



        temp.bootOption = 1;            // ||  01  |  0  |  11  |  01  |  0  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x5A);



        temp.bootOptionOnLimit = 0;     // ||  01  |  0  |  00  |  01  |  0  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x42);



        temp.watchdogEnabled = 1;       // ||  01  |  1  |  00  |  01  |  0  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x62);



        temp.__reserved = 3;            // ||  11  |  1  |  00  |  01  |  0  ||

        TEST_ASSERT_EQUALS(temp.value8, 0xE2);
    }
    TEST_CASE_END();



    TEST_CASE("DmiSystemSlotsEntryV26");
    {
        DmiSystemSlotsEntryV26 temp;



        //  DmiSystemSlotsEntryV26 - functionNumberAndDeviceNumber:
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



    TEST_CASE("DmiSystemSlotsPeerGroup");
    {
        DmiSystemSlotsPeerGroup temp;



        //  DmiSystemSlotsPeerGroup - functionNumberAndDeviceNumber:
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



    TEST_CASE("DmiTemperatureProbeEntry");
    {
        DmiTemperatureProbeEntry temp;



        //  DmiTemperatureProbeEntry - locationAndStatus:
        // =================================
        // |  status : 3  |  location : 5  |
        // =================================



        temp.locationAndStatus = 0x45;      // ||  010  |  00101  ||

        TEST_ASSERT_EQUALS(temp.location, 5);
        TEST_ASSERT_EQUALS(temp.status,   2);



        temp.location = 8;                  // ||  010  |  01000  ||

        TEST_ASSERT_EQUALS(temp.locationAndStatus, 0x48);



        temp.status = 1;                    // ||  001  |  01000  ||

        TEST_ASSERT_EQUALS(temp.locationAndStatus, 0x28);
    }
    TEST_CASE_END();



    TEST_CASE("DmiVoltageProbeEntry");
    {
        DmiVoltageProbeEntry temp;



        //  DmiVoltageProbeEntry - locationAndStatus:
        // =================================
        // |  status : 3  |  location : 5  |
        // =================================



        temp.locationAndStatus = 0x45;      // ||  010  |  00101  ||

        TEST_ASSERT_EQUALS(temp.location, 5);
        TEST_ASSERT_EQUALS(temp.status,   2);



        temp.location = 8;                  // ||  010  |  01000  ||

        TEST_ASSERT_EQUALS(temp.locationAndStatus, 0x48);



        temp.status = 1;                    // ||  001  |  01000  ||

        TEST_ASSERT_EQUALS(temp.locationAndStatus, 0x28);
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



    TEST_CASE("JpegHuffmanTable");
    {
        JpegHuffmanTable temp;



        //  JpegHuffmanTable - idAndType:
        // ============================================
        // |  __reserved : 3  |  type : 1  |  id : 4  |
        // ===========================================



        temp.idAndType = 0x55;      // ||  010  |  1  |  0101  ||

        TEST_ASSERT_EQUALS(temp.id,         5);
        TEST_ASSERT_EQUALS(temp.type,       1);
        TEST_ASSERT_EQUALS(temp.__reserved, 2);



        temp.id = 2;                // ||  010  |  1  |  0010  ||

        TEST_ASSERT_EQUALS(temp.idAndType, 0x52);



        temp.type = 0;              // ||  010  |  0  |  0010  ||

        TEST_ASSERT_EQUALS(temp.idAndType, 0x42);



        temp.__reserved = 4;        // ||  100  |  0  |  0010  ||

        TEST_ASSERT_EQUALS(temp.idAndType, 0x82);
    }
    TEST_CASE_END();



    TEST_CASE("JpegQuantizationTable");
    {
        JpegQuantizationTable temp;



        //  JpegQuantizationTable - idAndPrecision:
        // ==============================
        // |  precision : 4  |  id : 4  |
        // ==============================



        temp.idAndPrecision = 0x95;     // ||  1001  |  0101  ||

        TEST_ASSERT_EQUALS(temp.id,        5);
        TEST_ASSERT_EQUALS(temp.precision, 9);



        temp.id = 2;                    // ||  1001  |  0010  ||

        TEST_ASSERT_EQUALS(temp.idAndPrecision, 0x92);



        temp.precision = 7;             // ||  0111  |  0010  ||

        TEST_ASSERT_EQUALS(temp.idAndPrecision, 0x72);
    }
    TEST_CASE_END();



    TEST_CASE("JpegStartOfFrameComponent");
    {
        JpegStartOfFrameComponent temp;



        //  JpegStartOfFrameComponent - samplingFactor:
        // =================================================
        // |  samplingFactorX : 4  |  samplingFactorY : 4  |
        // =================================================



        temp.samplingFactor = 0x95;     // ||  1001  |  0101  ||

        TEST_ASSERT_EQUALS(temp.samplingFactorY, 5);
        TEST_ASSERT_EQUALS(temp.samplingFactorX, 9);



        temp.samplingFactorY = 2;       // ||  1001  |  0010  ||

        TEST_ASSERT_EQUALS(temp.samplingFactor, 0x92);



        temp.samplingFactorX = 7;       // ||  0111  |  0010  ||

        TEST_ASSERT_EQUALS(temp.samplingFactor, 0x72);
    }
    TEST_CASE_END();



    TEST_CASE("JpegStartOfScanComponent");
    {
        JpegStartOfScanComponent temp;



        //  JpegStartOfScanComponent - huffmanTableIds:
        // ===================================================
        // |  huffmanDcTableId : 4  |  huffmanAcTableId : 4  |
        // ===================================================



        temp.huffmanTableIds = 0x95;    // ||  1001  |  0101  ||

        TEST_ASSERT_EQUALS(temp.huffmanAcTableId, 5);
        TEST_ASSERT_EQUALS(temp.huffmanDcTableId, 9);



        temp.huffmanAcTableId = 2;      // ||  1001  |  0010  ||

        TEST_ASSERT_EQUALS(temp.huffmanTableIds, 0x92);



        temp.huffmanDcTableId = 7;      // ||  0111  |  0010  ||

        TEST_ASSERT_EQUALS(temp.huffmanTableIds, 0x72);
    }
    TEST_CASE_END();



    TEST_CASE("ZLibHeader");
    {
        ZLibHeader temp;



        //  ZLibHeader - value16:
        // ===================================================================================
        // |                compressionInfo : 4                    |  compressionMethod : 4  |
        // |  compressionLevel : 2 | presetDictionary : 1  |          checkBits : 5          |
        // ===================================================================================



        temp.value16 = 0xAC95;          // ||  10  |  1  |  01100  ||  1001  |  0101  ||

        TEST_ASSERT_EQUALS(temp.compressionMethod, 5);
        TEST_ASSERT_EQUALS(temp.compressionInfo,   9);
        TEST_ASSERT_EQUALS(temp.checkBits,         12);
        TEST_ASSERT_EQUALS(temp.presetDictionary,  1);
        TEST_ASSERT_EQUALS(temp.compressionLevel,  2);



        temp.compressionMethod = 2;     // ||  10  |  1  |  01100  ||  1001  |  0010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAC92);



        temp.compressionInfo = 7;       // ||  10  |  1  |  01100  ||  0111  |  0010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAC72);



        temp.checkBits = 11;            // ||  10  |  1  |  01011  ||  0111  |  0010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAB72);



        temp.presetDictionary = 0;      // ||  10  |  0  |  01011  ||  0111  |  0010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x8B72);



        temp.compressionLevel = 1;      // ||  01  |  0  |  01011  ||  0111  |  0010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x4B72);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TYPES_H
