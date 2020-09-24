#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TYPES_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TYPES_H



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
#include <com/ngos/shared/common/pci/capability/pciacceleratedgraphicsport8xcapability.h>
#include <com/ngos/shared/common/pci/capability/pciacceleratedgraphicsportcapability.h>
#include <com/ngos/shared/common/pci/capability/pcicentralresourcecontrolcapability.h>
#include <com/ngos/shared/common/pci/capability/pcidebugportcapability.h>
#include <com/ngos/shared/common/pci/capability/pciexpresscapability.h>
#include <com/ngos/shared/common/pci/capability/pciextendedbridgecapability.h>
#include <com/ngos/shared/common/pci/capability/pciextendeddevicecapability.h>
#include <com/ngos/shared/common/pci/capability/pcihotplugcapability.h>
#include <com/ngos/shared/common/pci/capability/pcihotswapcapability.h>
#include <com/ngos/shared/common/pci/capability/pcihypertransportcapability.h>
#include <com/ngos/shared/common/pci/capability/pcihypertransporthostsecondaryinterfaceblockcapability.h>
#include <com/ngos/shared/common/pci/capability/pcihypertransportslaveprimaryinterfaceblockcapability.h>
#include <com/ngos/shared/common/pci/capability/pcimessagesignaledinterrupts64capability.h>
#include <com/ngos/shared/common/pci/capability/pcimessagesignaledinterrupts64pervectormaskingcapability.h>
#include <com/ngos/shared/common/pci/capability/pcimessagesignaledinterruptscapability.h>
#include <com/ngos/shared/common/pci/capability/pcimessagesignaledinterruptsextendedcapability.h>
#include <com/ngos/shared/common/pci/capability/pcipowermanagementinterfacecapability.h>
#include <com/ngos/shared/common/pci/capability/pcisecuredevicecapability.h>
#include <com/ngos/shared/common/pci/capability/pcislotnumberingcapability.h>
#include <com/ngos/shared/common/pci/capability/pcivendorcapability.h>
#include <com/ngos/shared/common/pci/capability/pcivitalproductdatacapability.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass00/pcisubclass00.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0101.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0105.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0106.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0107.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0108.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pcisubclass01.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass02/pcisubclass02.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass03/pciinterface0300.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass03/pcisubclass03.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass04/pcisubclass04.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass05/pcisubclass05.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass06/pciinterface0604.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass06/pciinterface0608.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass06/pciinterface0609.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass06/pcisubclass06.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass07/pciinterface0700.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass07/pciinterface0701.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass07/pciinterface0703.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass07/pcisubclass07.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0800.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0801.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0802.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0803.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pcisubclass08.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass09/pciinterface0904.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass09/pcisubclass09.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0a/pcisubclass0a.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0b/pcisubclass0b.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0c/pciinterface0c00.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0c/pciinterface0c03.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0c/pciinterface0c07.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0c/pcisubclass0c.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0d/pcisubclass0d.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0e/pcisubclass0e.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0f/pcisubclass0f.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass10/pcisubclass10.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass11/pcisubclass11.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass12/pcisubclass12.h>
#include <com/ngos/shared/common/pci/database/generated/pcibaseclass.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0010/pcidevice0010.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0014/pcidevice0014.h>
#include <com/ngos/shared/common/pci/database/generated/vendor001c/pcidevice001c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0070/pcidevice0070.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0095/pcidevice0095.h>
#include <com/ngos/shared/common/pci/database/generated/vendor018a/pcidevice018a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor021b/pcidevice021b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor02ac/pcidevice02ac.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0357/pcidevice0357.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0432/pcidevice0432.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0675/pcidevice0675.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcidevice0731.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0795/pcidevice0795.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0b0b/pcidevice0b0b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0e11/pcidevice0e11.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0eac/pcidevice0eac.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1000/pcidevice1000.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1001/pcidevice1001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1002/pcidevice1002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1003/pcidevice1003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1004/pcidevice1004.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1005/pcidevice1005.h>
#include <com/ngos/shared/common/pci/database/generated/vendor100b/pcidevice100b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor100c/pcidevice100c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor100e/pcidevice100e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1011/pcidevice1011.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1013/pcidevice1013.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcidevice1014.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1017/pcidevice1017.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101a/pcidevice101a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101b/pcidevice101b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101c/pcidevice101c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101e/pcidevice101e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1022/pcidevice1022.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1023/pcidevice1023.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1025/pcidevice1025.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1028/pcidevice1028.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102a/pcidevice102a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102b/pcidevice102b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102c/pcidevice102c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102d/pcidevice102d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102f/pcidevice102f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1031/pcidevice1031.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1033/pcidevice1033.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1036/pcidevice1036.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1039/pcidevice1039.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcidevice103c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1042/pcidevice1042.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1043/pcidevice1043.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1044/pcidevice1044.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1045/pcidevice1045.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1048/pcidevice1048.h>
#include <com/ngos/shared/common/pci/database/generated/vendor104a/pcidevice104a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor104b/pcidevice104b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor104c/pcidevice104c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor104d/pcidevice104d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor104e/pcidevice104e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1050/pcidevice1050.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1054/pcidevice1054.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1055/pcidevice1055.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1057/pcidevice1057.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcidevice105a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105d/pcidevice105d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1060/pcidevice1060.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1061/pcidevice1061.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1064/pcidevice1064.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1066/pcidevice1066.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1067/pcidevice1067.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1069/pcidevice1069.h>
#include <com/ngos/shared/common/pci/database/generated/vendor106b/pcidevice106b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor106c/pcidevice106c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1071/pcidevice1071.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcidevice1073.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1074/pcidevice1074.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1077/pcidevice1077.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1078/pcidevice1078.h>
#include <com/ngos/shared/common/pci/database/generated/vendor107d/pcidevice107d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor107e/pcidevice107e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor107f/pcidevice107f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1080/pcidevice1080.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1081/pcidevice1081.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1083/pcidevice1083.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108a/pcidevice108a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108d/pcidevice108d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108e/pcidevice108e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1090/pcidevice1090.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1091/pcidevice1091.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1092/pcidevice1092.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1093/pcidevice1093.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1095/pcidevice1095.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1098/pcidevice1098.h>
#include <com/ngos/shared/common/pci/database/generated/vendor109e/pcidevice109e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10a5/pcidevice10a5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10a8/pcidevice10a8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10a9/pcidevice10a9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10aa/pcidevice10aa.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ad/pcidevice10ad.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b3/pcidevice10b3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b4/pcidevice10b4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b5/pcidevice10b5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcidevice10b6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b7/pcidevice10b7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b8/pcidevice10b8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcidevice10b9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ba/pcidevice10ba.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10bd/pcidevice10bd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10c8/pcidevice10c8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10cc/pcidevice10cc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10cd/pcidevice10cd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10cf/pcidevice10cf.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10d9/pcidevice10d9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10da/pcidevice10da.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10dc/pcidevice10dc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10dd/pcidevice10dd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10de/pcidevice10de.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10df/pcidevice10df.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10e0/pcidevice10e0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10e1/pcidevice10e1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10e3/pcidevice10e3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10e4/pcidevice10e4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10e8/pcidevice10e8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ea/pcidevice10ea.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10eb/pcidevice10eb.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ec/pcidevice10ec.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ed/pcidevice10ed.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ee/pcidevice10ee.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ef/pcidevice10ef.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10f1/pcidevice10f1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10f5/pcidevice10f5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10fa/pcidevice10fa.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10fb/pcidevice10fb.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10fc/pcidevice10fc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1101/pcidevice1101.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcidevice1102.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1103/pcidevice1103.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1105/pcidevice1105.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1106/pcidevice1106.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1107/pcidevice1107.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1108/pcidevice1108.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1109/pcidevice1109.h>
#include <com/ngos/shared/common/pci/database/generated/vendor110a/pcidevice110a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor110b/pcidevice110b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1110/pcidevice1110.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1112/pcidevice1112.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1113/pcidevice1113.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1114/pcidevice1114.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1116/pcidevice1116.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1117/pcidevice1117.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1119/pcidevice1119.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111a/pcidevice111a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111c/pcidevice111c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111d/pcidevice111d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111f/pcidevice111f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1120/pcidevice1120.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1124/pcidevice1124.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1127/pcidevice1127.h>
#include <com/ngos/shared/common/pci/database/generated/vendor112f/pcidevice112f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1131/pcidevice1131.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcidevice1133.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1134/pcidevice1134.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1135/pcidevice1135.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1136/pcidevice1136.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcidevice1137.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1138/pcidevice1138.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1139/pcidevice1139.h>
#include <com/ngos/shared/common/pci/database/generated/vendor113c/pcidevice113c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor113f/pcidevice113f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1142/pcidevice1142.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1144/pcidevice1144.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1145/pcidevice1145.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1148/pcidevice1148.h>
#include <com/ngos/shared/common/pci/database/generated/vendor114a/pcidevice114a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor114f/pcidevice114f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1158/pcidevice1158.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1159/pcidevice1159.h>
#include <com/ngos/shared/common/pci/database/generated/vendor115d/pcidevice115d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1163/pcidevice1163.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1165/pcidevice1165.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcidevice1166.h>
#include <com/ngos/shared/common/pci/database/generated/vendor116a/pcidevice116a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1172/pcidevice1172.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1178/pcidevice1178.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1179/pcidevice1179.h>
#include <com/ngos/shared/common/pci/database/generated/vendor117c/pcidevice117c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1180/pcidevice1180.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1186/pcidevice1186.h>
#include <com/ngos/shared/common/pci/database/generated/vendor118c/pcidevice118c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor118d/pcidevice118d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1190/pcidevice1190.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1191/pcidevice1191.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1193/pcidevice1193.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1197/pcidevice1197.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1199/pcidevice1199.h>
#include <com/ngos/shared/common/pci/database/generated/vendor119b/pcidevice119b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor119e/pcidevice119e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor119f/pcidevice119f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11a9/pcidevice11a9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11ab/pcidevice11ab.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11ad/pcidevice11ad.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11af/pcidevice11af.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11b0/pcidevice11b0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11b8/pcidevice11b8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11b9/pcidevice11b9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11bc/pcidevice11bc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11bd/pcidevice11bd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11c1/pcidevice11c1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11c8/pcidevice11c8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11c9/pcidevice11c9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11cb/pcidevice11cb.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11d1/pcidevice11d1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11d4/pcidevice11d4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11d5/pcidevice11d5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11de/pcidevice11de.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11e3/pcidevice11e3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11ec/pcidevice11ec.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11f0/pcidevice11f0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11f3/pcidevice11f3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11f4/pcidevice11f4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11f6/pcidevice11f6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11f8/pcidevice11f8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11fe/pcidevice11fe.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11ff/pcidevice11ff.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1202/pcidevice1202.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1204/pcidevice1204.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1208/pcidevice1208.h>
#include <com/ngos/shared/common/pci/database/generated/vendor120e/pcidevice120e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor120f/pcidevice120f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1217/pcidevice1217.h>
#include <com/ngos/shared/common/pci/database/generated/vendor121a/pcidevice121a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor121e/pcidevice121e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1220/pcidevice1220.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1221/pcidevice1221.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1223/pcidevice1223.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1227/pcidevice1227.h>
#include <com/ngos/shared/common/pci/database/generated/vendor122d/pcidevice122d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor122e/pcidevice122e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1231/pcidevice1231.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1236/pcidevice1236.h>
#include <com/ngos/shared/common/pci/database/generated/vendor123d/pcidevice123d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor123f/pcidevice123f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1242/pcidevice1242.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1244/pcidevice1244.h>
#include <com/ngos/shared/common/pci/database/generated/vendor124b/pcidevice124b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor124d/pcidevice124d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor124f/pcidevice124f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1254/pcidevice1254.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1255/pcidevice1255.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1256/pcidevice1256.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1259/pcidevice1259.h>
#include <com/ngos/shared/common/pci/database/generated/vendor125b/pcidevice125b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor125c/pcidevice125c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor125d/pcidevice125d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor125f/pcidevice125f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1260/pcidevice1260.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1266/pcidevice1266.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1267/pcidevice1267.h>
#include <com/ngos/shared/common/pci/database/generated/vendor126c/pcidevice126c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor126f/pcidevice126f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1273/pcidevice1273.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1274/pcidevice1274.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1278/pcidevice1278.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1279/pcidevice1279.h>
#include <com/ngos/shared/common/pci/database/generated/vendor127a/pcidevice127a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor127e/pcidevice127e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1282/pcidevice1282.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1283/pcidevice1283.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1285/pcidevice1285.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1287/pcidevice1287.h>
#include <com/ngos/shared/common/pci/database/generated/vendor128d/pcidevice128d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor128e/pcidevice128e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1292/pcidevice1292.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1295/pcidevice1295.h>
#include <com/ngos/shared/common/pci/database/generated/vendor129a/pcidevice129a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12a3/pcidevice12a3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12ab/pcidevice12ab.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12ae/pcidevice12ae.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12b9/pcidevice12b9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12be/pcidevice12be.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12c3/pcidevice12c3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12c4/pcidevice12c4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12c5/pcidevice12c5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12c7/pcidevice12c7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12cb/pcidevice12cb.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12d2/pcidevice12d2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12d4/pcidevice12d4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12d5/pcidevice12d5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12d8/pcidevice12d8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12d9/pcidevice12d9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12de/pcidevice12de.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12e0/pcidevice12e0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12eb/pcidevice12eb.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12f8/pcidevice12f8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12fb/pcidevice12fb.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1303/pcidevice1303.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1307/pcidevice1307.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1308/pcidevice1308.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1317/pcidevice1317.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1318/pcidevice1318.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1319/pcidevice1319.h>
#include <com/ngos/shared/common/pci/database/generated/vendor131f/pcidevice131f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1331/pcidevice1331.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1332/pcidevice1332.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1344/pcidevice1344.h>
#include <com/ngos/shared/common/pci/database/generated/vendor134a/pcidevice134a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor134d/pcidevice134d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1353/pcidevice1353.h>
#include <com/ngos/shared/common/pci/database/generated/vendor135a/pcidevice135a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor135c/pcidevice135c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor135e/pcidevice135e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1360/pcidevice1360.h>
#include <com/ngos/shared/common/pci/database/generated/vendor136a/pcidevice136a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor136b/pcidevice136b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1371/pcidevice1371.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1374/pcidevice1374.h>
#include <com/ngos/shared/common/pci/database/generated/vendor137a/pcidevice137a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1382/pcidevice1382.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1385/pcidevice1385.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1389/pcidevice1389.h>
#include <com/ngos/shared/common/pci/database/generated/vendor138a/pcidevice138a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1393/pcidevice1393.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1394/pcidevice1394.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1397/pcidevice1397.h>
#include <com/ngos/shared/common/pci/database/generated/vendor139a/pcidevice139a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13a3/pcidevice13a3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13a8/pcidevice13a8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13c0/pcidevice13c0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13c1/pcidevice13c1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13c2/pcidevice13c2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13c6/pcidevice13c6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13c7/pcidevice13c7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13d0/pcidevice13d0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13d1/pcidevice13d1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13df/pcidevice13df.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13ec/pcidevice13ec.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13f0/pcidevice13f0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13f4/pcidevice13f4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13f6/pcidevice13f6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13fe/pcidevice13fe.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1400/pcidevice1400.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1402/pcidevice1402.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1407/pcidevice1407.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1409/pcidevice1409.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1412/pcidevice1412.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1414/pcidevice1414.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcidevice1415.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1420/pcidevice1420.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1425/pcidevice1425.h>
#include <com/ngos/shared/common/pci/database/generated/vendor142e/pcidevice142e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1432/pcidevice1432.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1435/pcidevice1435.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144a/pcidevice144a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcidevice144d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor145f/pcidevice145f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1461/pcidevice1461.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1462/pcidevice1462.h>
#include <com/ngos/shared/common/pci/database/generated/vendor146a/pcidevice146a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor146c/pcidevice146c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor147b/pcidevice147b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1482/pcidevice1482.h>
#include <com/ngos/shared/common/pci/database/generated/vendor148d/pcidevice148d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1497/pcidevice1497.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1498/pcidevice1498.h>
#include <com/ngos/shared/common/pci/database/generated/vendor149d/pcidevice149d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14a4/pcidevice14a4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14af/pcidevice14af.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14b3/pcidevice14b3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14b5/pcidevice14b5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14b7/pcidevice14b7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14b9/pcidevice14b9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14ba/pcidevice14ba.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14bc/pcidevice14bc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14c0/pcidevice14c0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14c1/pcidevice14c1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14c3/pcidevice14c3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14cd/pcidevice14cd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14d2/pcidevice14d2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14d3/pcidevice14d3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14d6/pcidevice14d6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14d9/pcidevice14d9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14db/pcidevice14db.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14dc/pcidevice14dc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14e4/pcidevice14e4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14ea/pcidevice14ea.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14ec/pcidevice14ec.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14f1/pcidevice14f1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14f2/pcidevice14f2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14f3/pcidevice14f3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14f8/pcidevice14f8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor14fc/pcidevice14fc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1500/pcidevice1500.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1507/pcidevice1507.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1516/pcidevice1516.h>
#include <com/ngos/shared/common/pci/database/generated/vendor151a/pcidevice151a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor151c/pcidevice151c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor151f/pcidevice151f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1522/pcidevice1522.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1524/pcidevice1524.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1532/pcidevice1532.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1538/pcidevice1538.h>
#include <com/ngos/shared/common/pci/database/generated/vendor153b/pcidevice153b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor153f/pcidevice153f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1542/pcidevice1542.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1543/pcidevice1543.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1556/pcidevice1556.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1571/pcidevice1571.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1578/pcidevice1578.h>
#include <com/ngos/shared/common/pci/database/generated/vendor157c/pcidevice157c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1589/pcidevice1589.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1590/pcidevice1590.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1592/pcidevice1592.h>
#include <com/ngos/shared/common/pci/database/generated/vendor159b/pcidevice159b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15a2/pcidevice15a2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15ac/pcidevice15ac.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15ad/pcidevice15ad.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15b3/pcidevice15b3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15b6/pcidevice15b6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15b7/pcidevice15b7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15b8/pcidevice15b8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15bc/pcidevice15bc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15c5/pcidevice15c5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15c7/pcidevice15c7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15cf/pcidevice15cf.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15dc/pcidevice15dc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15e2/pcidevice15e2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15e8/pcidevice15e8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15e9/pcidevice15e9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15ec/pcidevice15ec.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1618/pcidevice1618.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1619/pcidevice1619.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1621/pcidevice1621.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1626/pcidevice1626.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1629/pcidevice1629.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1638/pcidevice1638.h>
#include <com/ngos/shared/common/pci/database/generated/vendor163c/pcidevice163c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1657/pcidevice1657.h>
#include <com/ngos/shared/common/pci/database/generated/vendor165a/pcidevice165a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor165c/pcidevice165c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor165f/pcidevice165f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1668/pcidevice1668.h>
#include <com/ngos/shared/common/pci/database/generated/vendor166d/pcidevice166d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1677/pcidevice1677.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1678/pcidevice1678.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1679/pcidevice1679.h>
#include <com/ngos/shared/common/pci/database/generated/vendor167b/pcidevice167b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor167d/pcidevice167d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1682/pcidevice1682.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1688/pcidevice1688.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168a/pcidevice168a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcidevice168c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor169c/pcidevice169c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16ab/pcidevice16ab.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16ae/pcidevice16ae.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16c3/pcidevice16c3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16c6/pcidevice16c6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16ca/pcidevice16ca.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16cd/pcidevice16cd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16d5/pcidevice16d5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16da/pcidevice16da.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16e3/pcidevice16e3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16e5/pcidevice16e5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16ec/pcidevice16ec.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16ed/pcidevice16ed.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16f2/pcidevice16f2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16f4/pcidevice16f4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor170b/pcidevice170b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1719/pcidevice1719.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1725/pcidevice1725.h>
#include <com/ngos/shared/common/pci/database/generated/vendor172a/pcidevice172a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1737/pcidevice1737.h>
#include <com/ngos/shared/common/pci/database/generated/vendor173b/pcidevice173b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1743/pcidevice1743.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1745/pcidevice1745.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1760/pcidevice1760.h>
#include <com/ngos/shared/common/pci/database/generated/vendor177d/pcidevice177d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1796/pcidevice1796.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1797/pcidevice1797.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1799/pcidevice1799.h>
#include <com/ngos/shared/common/pci/database/generated/vendor179a/pcidevice179a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor179c/pcidevice179c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17a0/pcidevice17a0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17aa/pcidevice17aa.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17b3/pcidevice17b3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17b4/pcidevice17b4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17cb/pcidevice17cb.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17cc/pcidevice17cc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17d3/pcidevice17d3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17d5/pcidevice17d5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17db/pcidevice17db.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17df/pcidevice17df.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17e4/pcidevice17e4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17e6/pcidevice17e6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17f3/pcidevice17f3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17fe/pcidevice17fe.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1800/pcidevice1800.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1804/pcidevice1804.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1813/pcidevice1813.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1814/pcidevice1814.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1822/pcidevice1822.h>
#include <com/ngos/shared/common/pci/database/generated/vendor182d/pcidevice182d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor182e/pcidevice182e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor182f/pcidevice182f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1830/pcidevice1830.h>
#include <com/ngos/shared/common/pci/database/generated/vendor183b/pcidevice183b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor184a/pcidevice184a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1850/pcidevice1850.h>
#include <com/ngos/shared/common/pci/database/generated/vendor185b/pcidevice185b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1864/pcidevice1864.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1867/pcidevice1867.h>
#include <com/ngos/shared/common/pci/database/generated/vendor186c/pcidevice186c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1876/pcidevice1876.h>
#include <com/ngos/shared/common/pci/database/generated/vendor187e/pcidevice187e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1888/pcidevice1888.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1896/pcidevice1896.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18a2/pcidevice18a2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ac/pcidevice18ac.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18b8/pcidevice18b8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18c3/pcidevice18c3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ca/pcidevice18ca.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18d2/pcidevice18d2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18dd/pcidevice18dd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18e6/pcidevice18e6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ec/pcidevice18ec.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18f4/pcidevice18f4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18f6/pcidevice18f6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18f7/pcidevice18f7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1904/pcidevice1904.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1912/pcidevice1912.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1923/pcidevice1923.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcidevice1924.h>
#include <com/ngos/shared/common/pci/database/generated/vendor192a/pcidevice192a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1931/pcidevice1931.h>
#include <com/ngos/shared/common/pci/database/generated/vendor193f/pcidevice193f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1942/pcidevice1942.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1947/pcidevice1947.h>
#include <com/ngos/shared/common/pci/database/generated/vendor194a/pcidevice194a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1957/pcidevice1957.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1959/pcidevice1959.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1966/pcidevice1966.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1969/pcidevice1969.h>
#include <com/ngos/shared/common/pci/database/generated/vendor196a/pcidevice196a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1971/pcidevice1971.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1974/pcidevice1974.h>
#include <com/ngos/shared/common/pci/database/generated/vendor197b/pcidevice197b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1982/pcidevice1982.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1987/pcidevice1987.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1989/pcidevice1989.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1999/pcidevice1999.h>
#include <com/ngos/shared/common/pci/database/generated/vendor199d/pcidevice199d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor199f/pcidevice199f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor19a2/pcidevice19a2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor19ac/pcidevice19ac.h>
#include <com/ngos/shared/common/pci/database/generated/vendor19ae/pcidevice19ae.h>
#include <com/ngos/shared/common/pci/database/generated/vendor19ba/pcidevice19ba.h>
#include <com/ngos/shared/common/pci/database/generated/vendor19e3/pcidevice19e3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor19e5/pcidevice19e5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor19e7/pcidevice19e7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a03/pcidevice1a03.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a07/pcidevice1a07.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a08/pcidevice1a08.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a0e/pcidevice1a0e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a17/pcidevice1a17.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a1d/pcidevice1a1d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a29/pcidevice1a29.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a2b/pcidevice1a2b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a30/pcidevice1a30.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a3b/pcidevice1a3b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a41/pcidevice1a41.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a4a/pcidevice1a4a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a55/pcidevice1a55.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a73/pcidevice1a73.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a78/pcidevice1a78.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a84/pcidevice1a84.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a88/pcidevice1a88.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a8c/pcidevice1a8c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a8e/pcidevice1a8e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1aa8/pcidevice1aa8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ab6/pcidevice1ab6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ab8/pcidevice1ab8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ac1/pcidevice1ac1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ad7/pcidevice1ad7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ade/pcidevice1ade.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ae0/pcidevice1ae0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ae7/pcidevice1ae7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ae8/pcidevice1ae8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ae9/pcidevice1ae9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1aea/pcidevice1aea.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1aed/pcidevice1aed.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1af4/pcidevice1af4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b03/pcidevice1b03.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b1a/pcidevice1b1a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b21/pcidevice1b21.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b26/pcidevice1b26.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b36/pcidevice1b36.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b37/pcidevice1b37.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b39/pcidevice1b39.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b3a/pcidevice1b3a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b3e/pcidevice1b3e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b47/pcidevice1b47.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b4b/pcidevice1b4b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b55/pcidevice1b55.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b66/pcidevice1b66.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b6f/pcidevice1b6f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b73/pcidevice1b73.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b74/pcidevice1b74.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b85/pcidevice1b85.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b94/pcidevice1b94.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bad/pcidevice1bad.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bb0/pcidevice1bb0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bb1/pcidevice1bb1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bb3/pcidevice1bb3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bbf/pcidevice1bbf.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bcf/pcidevice1bcf.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bd0/pcidevice1bd0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bd4/pcidevice1bd4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bee/pcidevice1bee.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bef/pcidevice1bef.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bf4/pcidevice1bf4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c09/pcidevice1c09.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c1c/pcidevice1c1c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c1f/pcidevice1c1f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c28/pcidevice1c28.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c2c/pcidevice1c2c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c36/pcidevice1c36.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c3b/pcidevice1c3b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c44/pcidevice1c44.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c58/pcidevice1c58.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c5c/pcidevice1c5c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c5f/pcidevice1c5f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c63/pcidevice1c63.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c7e/pcidevice1c7e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c7f/pcidevice1c7f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c8a/pcidevice1c8a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cb0/pcidevice1cb0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cb5/pcidevice1cb5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cc1/pcidevice1cc1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cc4/pcidevice1cc4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cc5/pcidevice1cc5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cc7/pcidevice1cc7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ccf/pcidevice1ccf.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cd2/pcidevice1cd2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cd7/pcidevice1cd7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1ce4/pcidevice1ce4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d0f/pcidevice1d0f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d17/pcidevice1d17.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d18/pcidevice1d18.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d1d/pcidevice1d1d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d22/pcidevice1d22.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d26/pcidevice1d26.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d37/pcidevice1d37.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d44/pcidevice1d44.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d65/pcidevice1d65.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d6a/pcidevice1d6a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d6c/pcidevice1d6c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d78/pcidevice1d78.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d82/pcidevice1d82.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d87/pcidevice1d87.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d94/pcidevice1d94.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d95/pcidevice1d95.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d9b/pcidevice1d9b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1da3/pcidevice1da3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1dbf/pcidevice1dbf.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1dd8/pcidevice1dd8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1de0/pcidevice1de0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1de1/pcidevice1de1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1de5/pcidevice1de5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1def/pcidevice1def.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1df3/pcidevice1df3.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1df7/pcidevice1df7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1dfc/pcidevice1dfc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e0f/pcidevice1e0f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e24/pcidevice1e24.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e36/pcidevice1e36.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e38/pcidevice1e38.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e4b/pcidevice1e4b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e4c/pcidevice1e4c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e57/pcidevice1e57.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e89/pcidevice1e89.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc0/pcidevice1fc0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc1/pcidevice1fc1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcidevice1fc9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fcc/pcidevice1fcc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fce/pcidevice1fce.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fd4/pcidevice1fd4.h>
#include <com/ngos/shared/common/pci/database/generated/vendor2000/pcidevice2000.h>
#include <com/ngos/shared/common/pci/database/generated/vendor2003/pcidevice2003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor22b8/pcidevice22b8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor2348/pcidevice2348.h>
#include <com/ngos/shared/common/pci/database/generated/vendor2955/pcidevice2955.h>
#include <com/ngos/shared/common/pci/database/generated/vendor31ab/pcidevice31ab.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3388/pcidevice3388.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3442/pcidevice3442.h>
#include <com/ngos/shared/common/pci/database/generated/vendor37d9/pcidevice37d9.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3d3d/pcidevice3d3d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4005/pcidevice4005.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4033/pcidevice4033.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4040/pcidevice4040.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4144/pcidevice4144.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4150/pcidevice4150.h>
#include <com/ngos/shared/common/pci/database/generated/vendor416c/pcidevice416c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4348/pcidevice4348.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4444/pcidevice4444.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4624/pcidevice4624.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4916/pcidevice4916.h>
#include <com/ngos/shared/common/pci/database/generated/vendor494f/pcidevice494f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4a14/pcidevice4a14.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4c53/pcidevice4c53.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4d51/pcidevice4d51.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4d56/pcidevice4d56.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4ddc/pcidevice4ddc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5045/pcidevice5045.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5046/pcidevice5046.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5053/pcidevice5053.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5145/pcidevice5145.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5168/pcidevice5168.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5301/pcidevice5301.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5333/pcidevice5333.h>
#include <com/ngos/shared/common/pci/database/generated/vendor544c/pcidevice544c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor544d/pcidevice544d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5452/pcidevice5452.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5455/pcidevice5455.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5544/pcidevice5544.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5555/pcidevice5555.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5851/pcidevice5851.h>
#include <com/ngos/shared/common/pci/database/generated/vendor5853/pcidevice5853.h>
#include <com/ngos/shared/common/pci/database/generated/vendor631c/pcidevice631c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor6374/pcidevice6374.h>
#include <com/ngos/shared/common/pci/database/generated/vendor6549/pcidevice6549.h>
#include <com/ngos/shared/common/pci/database/generated/vendor6666/pcidevice6666.h>
#include <com/ngos/shared/common/pci/database/generated/vendor6688/pcidevice6688.h>
#include <com/ngos/shared/common/pci/database/generated/vendor7063/pcidevice7063.h>
#include <com/ngos/shared/common/pci/database/generated/vendor7357/pcidevice7357.h>
#include <com/ngos/shared/common/pci/database/generated/vendor7401/pcidevice7401.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8008/pcidevice8008.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8086/pcidevice8086.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcidevice8088.h>
#include <com/ngos/shared/common/pci/database/generated/vendor80ee/pcidevice80ee.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8686/pcidevice8686.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8800/pcidevice8800.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8c4a/pcidevice8c4a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8e2e/pcidevice8e2e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcidevice9004.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9005/pcidevice9005.h>
#include <com/ngos/shared/common/pci/database/generated/vendor907f/pcidevice907f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9412/pcidevice9412.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9413/pcidevice9413.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9618/pcidevice9618.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9699/pcidevice9699.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9710/pcidevice9710.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9902/pcidevice9902.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9d32/pcidevice9d32.h>
#include <com/ngos/shared/common/pci/database/generated/vendora727/pcidevicea727.h>
#include <com/ngos/shared/common/pci/database/generated/vendoraaaa/pcideviceaaaa.h>
#include <com/ngos/shared/common/pci/database/generated/vendoraecb/pcideviceaecb.h>
#include <com/ngos/shared/common/pci/database/generated/vendoraffe/pcideviceaffe.h>
#include <com/ngos/shared/common/pci/database/generated/vendorbdbd/pcidevicebdbd.h>
#include <com/ngos/shared/common/pci/database/generated/vendorc0a9/pcidevicec0a9.h>
#include <com/ngos/shared/common/pci/database/generated/vendorcace/pcidevicecace.h>
#include <com/ngos/shared/common/pci/database/generated/vendorcafe/pcidevicecafe.h>
#include <com/ngos/shared/common/pci/database/generated/vendorcddd/pcidevicecddd.h>
#include <com/ngos/shared/common/pci/database/generated/vendord161/pcideviced161.h>
#include <com/ngos/shared/common/pci/database/generated/vendord209/pcideviced209.h>
#include <com/ngos/shared/common/pci/database/generated/vendord4d4/pcideviced4d4.h>
#include <com/ngos/shared/common/pci/database/generated/vendordada/pcidevicedada.h>
#include <com/ngos/shared/common/pci/database/generated/vendordcba/pcidevicedcba.h>
#include <com/ngos/shared/common/pci/database/generated/vendordd01/pcidevicedd01.h>
#include <com/ngos/shared/common/pci/database/generated/vendordeaf/pcidevicedeaf.h>
#include <com/ngos/shared/common/pci/database/generated/vendordeda/pcidevicededa.h>
#include <com/ngos/shared/common/pci/database/generated/vendore000/pcidevicee000.h>
#include <com/ngos/shared/common/pci/database/generated/vendore159/pcidevicee159.h>
#include <com/ngos/shared/common/pci/database/generated/vendore4bf/pcidevicee4bf.h>
#include <com/ngos/shared/common/pci/database/generated/vendorea01/pcideviceea01.h>
#include <com/ngos/shared/common/pci/database/generated/vendorea60/pcideviceea60.h>
#include <com/ngos/shared/common/pci/database/generated/vendoreace/pcideviceeace.h>
#include <com/ngos/shared/common/pci/database/generated/vendorec80/pcideviceec80.h>
#include <com/ngos/shared/common/pci/database/generated/vendoredd8/pcideviceedd8.h>
#include <com/ngos/shared/common/pci/database/generated/vendorf1d0/pcidevicef1d0.h>
#include <com/ngos/shared/common/pci/database/generated/vendorfa57/pcidevicefa57.h>
#include <com/ngos/shared/common/pci/database/generated/vendorfeda/pcidevicefeda.h>
#include <com/ngos/shared/common/pci/database/generated/vendorfede/pcidevicefede.h>
#include <com/ngos/shared/common/pci/database/generated/vendorfffd/pcidevicefffd.h>
#include <com/ngos/shared/common/pci/database/generated/vendorfffe/pcidevicefffe.h>
#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportcommand.h>
#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportrateflags.h>
#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportstatus.h>
#include <com/ngos/shared/common/pci/lib/pcibuiltinselftest.h>
#include <com/ngos/shared/common/pci/lib/pcicommandflags.h>
#include <com/ngos/shared/common/pci/lib/pcideviceselecttiming.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgedownstreamsplittransaction.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgesecondaryclockfrequency.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgesecondarystatus.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgestatus.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgeupstreamsplittransaction.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicecommand.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicecomplexity.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicestatus.h>
#include <com/ngos/shared/common/pci/lib/pciheadertype.h>
#include <com/ngos/shared/common/pci/lib/pciheadertypeunion.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportcapabilitytype.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportcommand.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransporterrorhandlingflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransporthostsecondaryinterfacecommand.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransporthostsecondaryinterfacefeatureflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkconfig.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkerrorandfrequencyunion.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkerrorflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkfrequency.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkfrequencycapabilityflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkwidth.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportrevision.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportslaveprimaryinterfacecommand.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportslaveprimaryinterfacefeatureflags.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsextendedmessagecontrol.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsextendedtableoffsetbirunion.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessageaddress.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessagecontrol.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementauxcurrent.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementbridgesupportextensions.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementcapabilities.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementcontrolstatus.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementpowerstate.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementsupportpmeflags.h>
#include <com/ngos/shared/common/pci/lib/pcislotnumberingexpansionslot.h>
#include <com/ngos/shared/common/pci/lib/pcistatus.h>
#include <com/ngos/shared/common/pci/lib/pcivitalproductdataaddressunion.h>
#include <com/ngos/shared/common/pci/pcibridgecontrolregister.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>
#include <com/ngos/shared/common/pci/pcicapabilitytype.h>
#include <com/ngos/shared/common/pci/pcicardbuscontrolregister.h>
#include <com/ngos/shared/common/pci/pciconfigurationspace.h>
#include <com/ngos/shared/common/pci/pcideviceheadertyperegion.h>
#include <com/ngos/shared/common/pci/pcideviceindependentregion.h>
#include <com/ngos/shared/common/pci/pciregister.h>
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
        TEST_ASSERT_EQUALS(sizeof(Adler),                                                    1);
        TEST_ASSERT_EQUALS(sizeof(AES),                                                      64);
        TEST_ASSERT_EQUALS(sizeof(AmdCpuModel),                                              1);
        TEST_ASSERT_EQUALS(sizeof(ArrayList<u8>),                                            24);
        TEST_ASSERT_EQUALS(sizeof(AssetEntry),                                               24);
        TEST_ASSERT_EQUALS(sizeof(Assets),                                                   1);
        TEST_ASSERT_EQUALS(sizeof(BitUtils),                                                 1);
        TEST_ASSERT_EQUALS(sizeof(Bmp),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(BmpColorMap),                                              4);
        TEST_ASSERT_EQUALS(sizeof(BmpCompressionMethod),                                     4);
        TEST_ASSERT_EQUALS(sizeof(BmpHeader),                                                14);
        TEST_ASSERT_EQUALS(sizeof(BmpInformationHeader),                                     40);
        TEST_ASSERT_EQUALS(sizeof(BootParams),                                               624);
        TEST_ASSERT_EQUALS(sizeof(BootParamsHeader),                                         32);
        TEST_ASSERT_EQUALS(sizeof(Button),                                                   224);
        TEST_ASSERT_EQUALS(sizeof(Console),                                                  1);
        TEST_ASSERT_EQUALS(sizeof(ConsoleWidget),                                            96);
        TEST_ASSERT_EQUALS(sizeof(CPU),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(CpuFamily),                                                2);
        TEST_ASSERT_EQUALS(sizeof(CpuVendor),                                                1);
        TEST_ASSERT_EQUALS(sizeof(Crc),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(CursorWidget),                                             96);
        TEST_ASSERT_EQUALS(sizeof(DMI),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiAdditionalInformation),                                 5);
        TEST_ASSERT_EQUALS(sizeof(DmiAdditionalInformationEntry),                            5);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardEntry),                                        15);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardFeatureFlag),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiBaseboardType),                                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsBiosReservedFlag),                   1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsFlag),                               8);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosCharacteristicsSystemReservedFlag),                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntry),                                             18);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntryV21),                                          19);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntryV23),                                          20);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntryV24),                                          24);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosEntryV31),                                          26);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosExtendedRomSize),                                   2);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosExtendedRomSizeUnit),                               1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosLanguageEntry),                                     22);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosLanguageFlag),                                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiBiosRomSize),                                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits32MemoryErrorInformationEntry),                     23);
        TEST_ASSERT_EQUALS(sizeof(DmiBits32MemoryErrorInformationErrorGranularity),          1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits32MemoryErrorInformationErrorOperation),            1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits32MemoryErrorInformationErrorType),                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits64MemoryErrorInformationEntry),                     31);
        TEST_ASSERT_EQUALS(sizeof(DmiBits64MemoryErrorInformationErrorGranularity),          1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits64MemoryErrorInformationErrorOperation),            1);
        TEST_ASSERT_EQUALS(sizeof(DmiBits64MemoryErrorInformationErrorType),                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheAssociativity),                                    1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheConfiguration),                                    2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheEntry),                                            15);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheEntryV21),                                         19);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheEntryV31),                                         27);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheErrorCorrectionType),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheLocation),                                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheOperationalMode),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSize),                                             2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSize2),                                            4);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSizeGranularity),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheSramTypeFlag),                                     2);
        TEST_ASSERT_EQUALS(sizeof(DmiCacheType),                                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisContainedElement),                               3);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisContainedElementType),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisContainedElementTypeSelect),                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntry),                                          9);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntryV21),                                       13);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntryV23),                                       21);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisEntryV27),                                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisSecurityStatus),                                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisState),                                          1);
        TEST_ASSERT_EQUALS(sizeof(DmiChassisType),                                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceEntry),                                    14);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceEntryV27),                                 15);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceStatus),                                   1);
        TEST_ASSERT_EQUALS(sizeof(DmiCoolingDeviceType),                                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeEntry),                           22);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeLocation),                        1);
        TEST_ASSERT_EQUALS(sizeof(DmiElectricalCurrentProbeStatus),                          1);
        TEST_ASSERT_EQUALS(sizeof(DmiEntryHeader),                                           4);
        TEST_ASSERT_EQUALS(sizeof(DmiEntryType),                                             1);
        TEST_ASSERT_EQUALS(sizeof(DmiGroupAssociationsEntry),                                5);
        TEST_ASSERT_EQUALS(sizeof(DmiGroupAssociationsItem),                                 3);
        TEST_ASSERT_EQUALS(sizeof(DmiHardwareSecurityEntry),                                 5);
        TEST_ASSERT_EQUALS(sizeof(DmiHardwareSecuritySettings),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiHardwareSecurityStatus),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiIdentity),                                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiInactiveEntry),                                         4);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceAddressType),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceComponentEntry),                        11);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceEntry),                                 11);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceThresholdDataEntry),                    16);
        TEST_ASSERT_EQUALS(sizeof(DmiManagementDeviceType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryArrayMappedAddressEntry),                         15);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryArrayMappedAddressEntryV27),                      31);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryArrayMappedAddressRange),                         4);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDevice),                                          64);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceAttributes),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntry),                                     21);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV23),                                  27);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV26),                                  28);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV27),                                  34);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV28),                                  40);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV32),                                  84);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceEntryV33),                                  92);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceExtendedSize),                              4);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceFormFactor),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceMappedAddressEntry),                        19);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceMappedAddressEntryV27),                     35);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceMappedAddressRange),                        4);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceOperatingModeCapabilityFlag),               2);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceSize),                                      2);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceSizeGranularity),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceTechnology),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceType),                                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiMemoryDeviceTypeDetailFlag),                            2);
        TEST_ASSERT_EQUALS(sizeof(DmiOemStringsEntry),                                       5);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesDevice),                                  2);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesDeviceType),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesEntry),                                   4);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesExtendedDeviceType),                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiOnboardDevicesExtendedEntry),                           11);
        TEST_ASSERT_EQUALS(sizeof(DmiOutOfBandRemoteAccessConnectionFlag),                   1);
        TEST_ASSERT_EQUALS(sizeof(DmiOutOfBandRemoteAccessEntry),                            6);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayEntry),                              15);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayEntryV27),                           23);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayErrorCorrection),                    1);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayLocation),                           1);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayMaximumCapacity),                    4);
        TEST_ASSERT_EQUALS(sizeof(DmiPhysicalMemoryArrayUse),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryDeviceChemistry),                        1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryEntry),                                  16);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryEntryV22),                               26);
        TEST_ASSERT_EQUALS(sizeof(DmiPortableBatteryManufactureDate),                        2);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorEntry),                                    9);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorPortType),                                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiPortConnectorType),                                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorCharacteristicsFlag),                          2);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntry),                                        26);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV21),                                     32);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV23),                                     35);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV25),                                     40);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV26),                                     42);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorEntryV30),                                     48);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFamily),                                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFamily2),                                      2);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorFeatureFlag),                                  4);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorId),                                           8);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorSignature),                                    4);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorStatus),                                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorType),                                         1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorUpgrade),                                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorVoltage),                                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorVoltageFlag),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiProcessorVoltageModeType),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiStoredUuid),                                            1);
        TEST_ASSERT_EQUALS(sizeof(DmiStringId),                                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemBootEntry),                                       11);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemBootStatus),                                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemConfigurationEntry),                              5);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemEntry),                                           8);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemEntryV21),                                        25);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemEntryV24),                                        27);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyCharacteristics),                      2);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyEntry),                                22);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyInputVoltageRangeSwitch),              1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyStatus),                               1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemPowerSupplyType),                                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemResetBootOption),                                 1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemResetCapabilities),                               1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemResetEntry),                                      13);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsCharacteristicsFlag),                        2);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsDataBusWidth),                               1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsEntry),                                      13);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsEntryV26),                                   17);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsEntryV32),                                   19);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsLength),                                     1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsPeerGroup),                                  5);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsType),                                       1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemSlotsUsage),                                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiSystemWakeUpType),                                      1);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeEntry),                                 22);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeLocation),                              1);
        TEST_ASSERT_EQUALS(sizeof(DmiTemperatureProbeStatus),                                1);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeEntry),                                     22);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeLocation),                                  1);
        TEST_ASSERT_EQUALS(sizeof(DmiVoltageProbeStatus),                                    1);
        TEST_ASSERT_EQUALS(sizeof(ElfClass),                                                 1);
        TEST_ASSERT_EQUALS(sizeof(ElfData),                                                  1);
        TEST_ASSERT_EQUALS(sizeof(ElfFileVersion),                                           1);
        TEST_ASSERT_EQUALS(sizeof(ElfHeader),                                                64);
        TEST_ASSERT_EQUALS(sizeof(ElfHeaderIdentification),                                  16);
        TEST_ASSERT_EQUALS(sizeof(ElfMachine),                                               2);
        TEST_ASSERT_EQUALS(sizeof(ElfOsAbi),                                                 1);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramFlag),                                           4);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramHeaderTableEntry),                               56);
        TEST_ASSERT_EQUALS(sizeof(ElfProgramType),                                           4);
        TEST_ASSERT_EQUALS(sizeof(ElfRela),                                                  24);
        TEST_ASSERT_EQUALS(sizeof(ElfRelaType),                                              4);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionFlag),                                           8);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionHeaderTableEntry),                               64);
        TEST_ASSERT_EQUALS(sizeof(ElfSectionType),                                           4);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbol),                                                24);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolBind),                                            1);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolType),                                            1);
        TEST_ASSERT_EQUALS(sizeof(ElfSymbolVisibility),                                      1);
        TEST_ASSERT_EQUALS(sizeof(ElfType),                                                  2);
        TEST_ASSERT_EQUALS(sizeof(ElfVersion),                                               4);
        TEST_ASSERT_EQUALS(sizeof(FPU),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(FpuState),                                                 4096);
        TEST_ASSERT_EQUALS(sizeof(FSaveState),                                               112);
        TEST_ASSERT_EQUALS(sizeof(FXSaveState),                                              512);
        TEST_ASSERT_EQUALS(sizeof(GdtDescriptor),                                            8);
        TEST_ASSERT_EQUALS(sizeof(GdtRegister),                                              10);
        TEST_ASSERT_EQUALS(sizeof(GlyphData),                                                5);
        TEST_ASSERT_EQUALS(sizeof(GptData),                                                  24);
        TEST_ASSERT_EQUALS(sizeof(GptEntry),                                                 128);
        TEST_ASSERT_EQUALS(sizeof(GptHeader),                                                96);
        TEST_ASSERT_EQUALS(sizeof(GraphicalConsole),                                         1);
        TEST_ASSERT_EQUALS(sizeof(Graphics),                                                 1);
        TEST_ASSERT_EQUALS(sizeof(GUI),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(Guid),                                                     16);
        TEST_ASSERT_EQUALS(sizeof(Hex),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(HorizontalAlignment),                                      1);
        TEST_ASSERT_EQUALS(sizeof(IdtDescriptor),                                            16);
        TEST_ASSERT_EQUALS(sizeof(IdtGateType),                                              1);
        TEST_ASSERT_EQUALS(sizeof(IdtRegister),                                              10);
        TEST_ASSERT_EQUALS(sizeof(Image),                                                    32);
        TEST_ASSERT_EQUALS(sizeof(ImageWidget),                                              104);
        TEST_ASSERT_EQUALS(sizeof(InflateBlockType),                                         1);
        TEST_ASSERT_EQUALS(sizeof(InflateCode),                                              4);
        TEST_ASSERT_EQUALS(sizeof(InflateCodeType),                                          1);
        TEST_ASSERT_EQUALS(sizeof(InflateDecoder),                                           40);
        TEST_ASSERT_EQUALS(sizeof(IntelCpuModel),                                            1);
        TEST_ASSERT_EQUALS(sizeof(Jpeg),                                                     1);
        TEST_ASSERT_EQUALS(sizeof(JpegComponent),                                            56);
        TEST_ASSERT_EQUALS(sizeof(JpegComponentId),                                          1);
        TEST_ASSERT_EQUALS(sizeof(JpegDecoder),                                              808);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineHuffmanTableMarker),                             4);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineQuantizationTableMarker),                        4);
        TEST_ASSERT_EQUALS(sizeof(JpegDefineRestartIntervalMarker),                          6);
        TEST_ASSERT_EQUALS(sizeof(JpegHuffmanTable),                                         17);
        TEST_ASSERT_EQUALS(sizeof(JpegHuffmanTableType),                                     1);
        TEST_ASSERT_EQUALS(sizeof(JpegMarkerHeader),                                         4);
        TEST_ASSERT_EQUALS(sizeof(JpegMarkerType),                                           1);
        TEST_ASSERT_EQUALS(sizeof(JpegQuantizationTable),                                    1);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfFrameComponent),                                3);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfFrameMarker),                                   10);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfScanComponent),                                 2);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfScanMarker),                                    5);
        TEST_ASSERT_EQUALS(sizeof(JpegVlcCode),                                              2);
        TEST_ASSERT_EQUALS(sizeof(LabelWidget),                                              112);
        TEST_ASSERT_EQUALS(sizeof(ListElement<u8>),                                          24);
        TEST_ASSERT_EQUALS(sizeof(List<u8>),                                                 16);
        TEST_ASSERT_EQUALS(sizeof(MapElement<u8, u32>),                                      8);
        TEST_ASSERT_EQUALS(sizeof(Map<u8, u32>),                                             24);
        TEST_ASSERT_EQUALS(sizeof(Mbr),                                                      512);
        TEST_ASSERT_EQUALS(sizeof(MbrPartition),                                             16);
        TEST_ASSERT_EQUALS(sizeof(MbrPartitionType),                                         1);
        TEST_ASSERT_EQUALS(sizeof(MD5),                                                      96);
        TEST_ASSERT_EQUALS(sizeof(Md5Hash),                                                  16);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntry),                                           24);
        TEST_ASSERT_EQUALS(sizeof(MemoryMapEntryType),                                       1);
        TEST_ASSERT_EQUALS(sizeof(MpxBoundRegister),                                         16);
        TEST_ASSERT_EQUALS(sizeof(MSR),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(NgosStatus),                                               8);
        TEST_ASSERT_EQUALS(sizeof(NinePatch),                                                40);
        TEST_ASSERT_EQUALS(sizeof(PanelWidget),                                              104);
        TEST_ASSERT_EQUALS(sizeof(PciAcceleratedGraphicsPort8xCapability),                   2);
        TEST_ASSERT_EQUALS(sizeof(PciAcceleratedGraphicsPortCapability),                     12);
        TEST_ASSERT_EQUALS(sizeof(PciAcceleratedGraphicsPortCommand),                        4);
        TEST_ASSERT_EQUALS(sizeof(PciAcceleratedGraphicsPortRateFlag),                       1);
        TEST_ASSERT_EQUALS(sizeof(PciAcceleratedGraphicsPortStatus),                         4);
        TEST_ASSERT_EQUALS(sizeof(PciBaseClass),                                             1);
        TEST_ASSERT_EQUALS(sizeof(PciBridgeControlRegister),                                 48);
        TEST_ASSERT_EQUALS(sizeof(PciBuiltInSelfTest),                                       1);
        TEST_ASSERT_EQUALS(sizeof(PciCapabilityHeader),                                      2);
        TEST_ASSERT_EQUALS(sizeof(PciCapabilityType),                                        1);
        TEST_ASSERT_EQUALS(sizeof(PciCardBusControlRegister),                                48);
        TEST_ASSERT_EQUALS(sizeof(PciCentralResourceControlCapability),                      2);
        TEST_ASSERT_EQUALS(sizeof(PciCommandFlag),                                           2);
        TEST_ASSERT_EQUALS(sizeof(PciConfigurationSpace),                                    256);
        TEST_ASSERT_EQUALS(sizeof(PciDebugPortCapability),                                   2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0010),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0014),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice001C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0070),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0095),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice018A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice021B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice02AC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0357),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0432),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0675),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0731),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0795),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0B0B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0E11),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice0EAC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1000),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1001),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1002),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1003),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1004),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1005),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice100B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice100C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice100E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1011),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1013),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1014),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1017),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice101A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice101B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice101C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice101E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1022),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1023),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1025),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1028),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice102A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice102B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice102C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice102D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice102F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1031),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1033),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1036),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1039),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice103C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1042),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1043),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1044),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1045),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1048),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice104A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice104B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice104C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice104D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice104E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1050),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1054),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1055),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1057),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice105A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice105D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1060),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1061),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1064),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1066),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1067),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1069),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice106B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice106C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1071),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1073),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1074),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1077),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1078),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice107D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice107E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice107F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1080),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1081),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1083),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice108A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice108D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice108E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1090),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1091),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1092),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1093),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1095),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1098),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice109E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10A5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10A8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10A9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10AA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10AD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10B3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10B4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10B5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10B6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10B7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10B8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10B9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10BA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10BD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10C8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10CC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10CD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10CF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10D9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10DA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10DC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10DD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10DE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10DF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10E0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10E1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10E3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10E4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10E8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10EA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10EB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10EC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10ED),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10EE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10EF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10F1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10F5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10FA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10FB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice10FC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1101),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1102),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1103),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1105),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1106),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1107),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1108),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1109),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice110A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice110B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1110),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1112),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1113),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1114),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1116),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1117),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1119),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice111A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice111C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice111D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice111F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1120),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1124),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1127),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice112F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1131),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1133),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1134),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1135),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1136),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1137),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1138),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1139),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice113C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice113F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1142),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1144),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1145),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1148),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice114A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice114F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1158),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1159),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice115D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1163),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1165),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1166),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice116A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1172),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1178),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1179),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice117C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1180),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1186),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice118C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice118D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1190),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1191),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1193),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1197),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1199),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice119B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice119E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice119F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11A9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11AB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11AD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11AF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11B0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11B8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11B9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11BC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11BD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11C1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11C8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11C9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11CB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11D1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11D4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11D5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11DE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11E3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11EC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11F0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11F3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11F4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11F6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11F8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11FE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice11FF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1202),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1204),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1208),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice120E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice120F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1217),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice121A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice121E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1220),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1221),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1223),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1227),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice122D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice122E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1231),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1236),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice123D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice123F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1242),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1244),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice124B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice124D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice124F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1254),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1255),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1256),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1259),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice125B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice125C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice125D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice125F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1260),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1266),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1267),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice126C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice126F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1273),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1274),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1278),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1279),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice127A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice127E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1282),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1283),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1285),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1287),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice128D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice128E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1292),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1295),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice129A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12A3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12AB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12AE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12B9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12BE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12C3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12C4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12C5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12C7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12CB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12D2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12D4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12D5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12D8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12D9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12DE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12E0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12EB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12F8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice12FB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1303),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1307),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1308),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1317),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1318),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1319),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice131F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1331),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1332),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1344),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice134A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice134D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1353),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice135A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice135C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice135E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1360),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice136A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice136B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1371),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1374),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice137A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1382),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1385),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1389),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice138A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1393),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1394),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1397),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice139A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13A3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13A8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13C0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13C1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13C2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13C6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13C7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13D0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13D1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13DF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13EC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13F0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13F4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13F6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice13FE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1400),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1402),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1407),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1409),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1412),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1414),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1415),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1420),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1425),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice142E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1432),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1435),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice144A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice144D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice145F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1461),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1462),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice146A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice146C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice147B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1482),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice148D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1497),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1498),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice149D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14A4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14AF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14B3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14B5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14B7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14B9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14BA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14BC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14C0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14C1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14C3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14CD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14D2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14D3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14D6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14D9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14DB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14DC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14E4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14EA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14EC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14F1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14F2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14F3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14F8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice14FC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1500),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1507),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1516),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice151A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice151C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice151F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1522),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1524),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1532),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1538),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice153B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice153F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1542),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1543),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1556),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1571),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1578),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice157C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1589),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1590),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1592),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice159B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15A2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15AC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15AD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15B3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15B6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15B7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15B8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15BC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15C5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15C7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15CF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15DC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15E2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15E8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15E9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice15EC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1618),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1619),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1621),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1626),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1629),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1638),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice163C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1657),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice165A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice165C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice165F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1668),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice166D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1677),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1678),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1679),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice167B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice167D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1682),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1688),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice168A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice168C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice169C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16AB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16AE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16C3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16C6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16CA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16CD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16D5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16DA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16E3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16E5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16EC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16ED),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16F2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice16F4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice170B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1719),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1725),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice172A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1737),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice173B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1743),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1745),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1760),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice177D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1796),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1797),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1799),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice179A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice179C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17A0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17AA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17B3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17B4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17CB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17CC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17D3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17D5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17DB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17DF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17E4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17E6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17F3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice17FE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1800),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1804),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1813),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1814),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1822),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice182D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice182E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice182F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1830),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice183B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice184A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1850),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice185B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1864),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1867),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice186C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1876),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice187E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1888),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1896),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18A2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18AC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18B8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18C3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18CA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18D2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18DD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18E6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18EC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18F4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18F6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice18F7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1904),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1912),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1923),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1924),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice192A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1931),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice193F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1942),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1947),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice194A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1957),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1959),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1966),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1969),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice196A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1971),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1974),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice197B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1982),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1987),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1989),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1999),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice199D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice199F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice19A2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice19AC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice19AE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice19BA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice19E3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice19E5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice19E7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A03),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A07),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A08),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A0E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A17),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A1D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A29),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A2B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A30),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A3B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A41),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A4A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A55),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A73),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A78),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A84),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A88),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A8C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1A8E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AA8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AB6),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AB8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AC1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AD7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1ADE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AE0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AE7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AE8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AE9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AEA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AED),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1AF4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B03),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B1A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B21),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B26),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B36),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B37),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B39),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B3A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B3E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B47),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B4B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B55),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B66),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B6F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B73),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B74),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B85),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1B94),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BAD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BB0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BB1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BB3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BBF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BCF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BD0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BD4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BEE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BEF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1BF4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C09),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C1C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C1F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C28),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C2C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C36),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C3B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C44),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C58),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C5C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C5F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C63),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C7E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C7F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1C8A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CB0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CB5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CC1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CC4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CC5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CC7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CCF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CD2),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CD7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1CE4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D0F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D17),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D18),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D1D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D22),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D26),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D37),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D44),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D65),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D6A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D6C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D78),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D82),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D87),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D94),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D95),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1D9B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DA3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DBF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DD8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DE0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DE1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DE5),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DEF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DF3),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DF7),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1DFC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1E0F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1E24),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1E36),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1E38),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1E4B),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1E4C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1E57),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1E89),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1EB1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1FC0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1FC1),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1FC9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1FCC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1FCE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice1FD4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice2000),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice2003),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice22B8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice2348),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice2955),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice31AB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice3388),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice3442),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice37D9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice3D3D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4005),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4033),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4040),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4144),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4150),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice416C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4348),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4444),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4624),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4916),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice494F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4A14),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4C53),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4D51),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4D56),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice4DDC),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5045),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5046),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5053),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5145),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5168),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5301),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5333),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice544C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice544D),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5452),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5455),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5544),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5555),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5851),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice5853),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice631C),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice6374),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice6549),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice6666),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice6688),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice7063),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice7357),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice7401),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice8008),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice8086),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice8088),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice80EE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice8686),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice8800),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice8C4A),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice8E2E),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9004),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9005),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice907F),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9412),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9413),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9618),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9699),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9710),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9902),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDevice9D32),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceA727),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceAAAA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceAECB),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceAFFE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceBDBD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceC0A9),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceCACE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceCAFE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceCDDD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceD161),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceD209),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceD4D4),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceDADA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceDCBA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceDD01),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceDEAF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceDEDA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceE000),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceE159),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceE4BF),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceEA01),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceEA60),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceEACE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceEC80),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceEDD8),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceF1D0),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceFA57),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceFEDA),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceFEDE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceFFFD),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceFFFE),                                            2);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceHeaderTypeRegion),                                48);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceIndependentRegion),                               16);
        TEST_ASSERT_EQUALS(sizeof(PciDeviceSelectTiming),                                    1);
        TEST_ASSERT_EQUALS(sizeof(PciExpressCapability),                                     2);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedBridgeCapability),                              16);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedBridgeDownstreamSplitTransaction),              4);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedBridgeSecondaryClockFrequency),                 1);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedBridgeSecondaryStatus),                         2);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedBridgeStatus),                                  4);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedBridgeUpstreamSplitTransaction),                4);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedDeviceCapability),                              8);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedDeviceCommand),                                 2);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedDeviceComplexity),                              1);
        TEST_ASSERT_EQUALS(sizeof(PciExtendedDeviceStatus),                                  4);
        TEST_ASSERT_EQUALS(sizeof(PciHeaderType),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciHeaderTypeUnion),                                       1);
        TEST_ASSERT_EQUALS(sizeof(PciHotPlugCapability),                                     2);
        TEST_ASSERT_EQUALS(sizeof(PciHotSwapCapability),                                     2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportCapability),                              4);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportCapabilityType),                          1);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportCommand),                                 2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportErrorHandlingFlag),                       2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportHostSecondaryInterfaceBlockCapability),   24);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportHostSecondaryInterfaceCommand),           2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportHostSecondaryInterfaceFeatureFlag),       2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportLinkConfig),                              2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportLinkControl),                             2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportLinkErrorAndFrequencyUnion),              1);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportLinkErrorFlag),                           1);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportLinkFrequency),                           1);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportLinkFrequencyCapabilityFlag),             2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportLinkWidth),                               1);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportRevision),                                1);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportSlavePrimaryInterfaceBlockCapability),    28);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportSlavePrimaryInterfaceCommand),            2);
        TEST_ASSERT_EQUALS(sizeof(PciHyperTransportSlavePrimaryInterfaceFeatureFlag),        1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0101),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0105),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0106),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0107),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0108),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0300),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0604),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0608),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0609),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0700),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0701),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0703),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0800),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0801),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0802),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0803),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0904),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0C00),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0C03),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciInterface0C07),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PciMessageSignaledInterrupts64Capability),                 16);
        TEST_ASSERT_EQUALS(sizeof(PciMessageSignaledInterrupts64PerVectorMaskingCapability), 24);
        TEST_ASSERT_EQUALS(sizeof(PciMessageSignaledInterruptsCapability),                   12);
        TEST_ASSERT_EQUALS(sizeof(PciMessageSignaledInterruptsExtendedCapability),           12);
        TEST_ASSERT_EQUALS(sizeof(PciMessageSignaledInterruptsExtendedMessageControl),       2);
        TEST_ASSERT_EQUALS(sizeof(PciMessageSignaledInterruptsExtendedTableOffsetBirUnion),  4);
        TEST_ASSERT_EQUALS(sizeof(PciMessageSignaledInterruptsMessageAddress),               4);
        TEST_ASSERT_EQUALS(sizeof(PciMessageSignaledInterruptsMessageControl),               2);
        TEST_ASSERT_EQUALS(sizeof(PciPowerManagementAuxCurrent),                             1);
        TEST_ASSERT_EQUALS(sizeof(PciPowerManagementBridgeSupportExtensions),                1);
        TEST_ASSERT_EQUALS(sizeof(PciPowerManagementCapabilities),                           2);
        TEST_ASSERT_EQUALS(sizeof(PciPowerManagementControlStatus),                          2);
        TEST_ASSERT_EQUALS(sizeof(PciPowerManagementInterfaceCapability),                    8);
        TEST_ASSERT_EQUALS(sizeof(PciPowerManagementPowerState),                             1);
        TEST_ASSERT_EQUALS(sizeof(PciPowerManagementSupportPmeFlag),                         1);
        TEST_ASSERT_EQUALS(sizeof(PciRegister),                                              1);
        TEST_ASSERT_EQUALS(sizeof(PciRomImageWithInfo),                                      56);
        TEST_ASSERT_EQUALS(sizeof(PciSecureDeviceCapability),                                2);
        TEST_ASSERT_EQUALS(sizeof(PciSlotNumberingCapability),                               4);
        TEST_ASSERT_EQUALS(sizeof(PciSlotNumberingExpansionSlot),                            1);
        TEST_ASSERT_EQUALS(sizeof(PciStatus),                                                2);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass00),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass01),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass02),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass03),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass04),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass05),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass06),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass07),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass08),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass09),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass0A),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass0B),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass0C),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass0D),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass0E),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass0F),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass10),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass11),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubClass12),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice001C0001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice0E110046),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice0E11A0F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice0E11A0F7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice0E11AE10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice0E11B178),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000000A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000000B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000000C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000000F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000012),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000014),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000015),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000016),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000017),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000001B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000001C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000021),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000002F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000030),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000032),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000040),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000050),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000053),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000054),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000055),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000056),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000057),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000058),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000005B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000005D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000005F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000060),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000062),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000064),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000070),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000072),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000073),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000079),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000007C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000007E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000086),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000087),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1000008F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000097),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000AB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000AC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000AF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000C4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000CE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000CF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000D0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000D1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000E4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000E5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000E6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100000E7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100002B0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100002B1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000407),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000408),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000409),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000411),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000413),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000622),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000626),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10000702),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100010E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100010E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100010E2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100010E3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10001960),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10021308),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10021309),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10021314),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100215D8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100215DD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100215DE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100215DF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10021714),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10023150),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024150),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024151),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024152),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024153),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024170),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024171),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024172),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024173),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024242),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024336),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024337),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024370),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024371),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024372),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024373),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024374),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024375),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024376),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024377),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024378),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024379),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002437A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002437B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024380),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024383),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024385),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024386),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024387),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024388),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024389),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002438A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002438B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002438C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002438D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024390),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024391),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024392),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024396),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024397),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024398),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024399),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002439C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002439D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024742),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024744),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024749),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002474D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002474E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002474F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024750),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024752),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024753),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024756),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024757),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002475A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024966),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024A49),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024A54),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C42),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C46),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C49),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C4D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C50),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C52),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C57),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C59),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024C66),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024E44),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024E45),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024E4A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024E50),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024E52),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024E65),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10024E6A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025044),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025046),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025050),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025144),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025148),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002514C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025157),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025159),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002515E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025245),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025246),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002524C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002534D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025354),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025446),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025452),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025460),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002554B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002554D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002556D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025653),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025654),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025940),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025941),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025950),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025954),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025955),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025957),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025960),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025961),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025964),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025974),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025978),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002597E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002597F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025A12),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025A18),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025A1F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025A3F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025B60),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025B70),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025C63),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025D44),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025D52),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025D72),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025E4D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025E4F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10025E6D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026600),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026601),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026604),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026605),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026606),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026608),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026610),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026611),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026613),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026640),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026647),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026649),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026658),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002665C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002665F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026660),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026663),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026665),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026720),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026738),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026739),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002673E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026740),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026741),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026742),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026749),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002674A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026750),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026751),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026758),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026759),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002675F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026760),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026770),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026778),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026779),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002678A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026798),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002679A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002679B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002679E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267A0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267A1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267B0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267B1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267C4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267DF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267E8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267EF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100267FF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026800),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026801),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026808),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026809),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026810),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026811),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026818),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026819),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026820),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026821),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026825),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026828),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002682B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002682F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026837),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002683D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002683F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026840),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026841),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026860),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002687F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026880),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026889),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002688A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026898),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026899),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002689C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268A0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268A1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268A8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268A9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268B8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268BE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268BF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268C1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268C7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268C9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268D8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268D9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268DA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268E4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268E5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268F9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100268FA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026900),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026901),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002692B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026938),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10026939),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002699F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027104),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027109),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002710A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002710E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002710F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027124),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027129),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002712E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002712F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027142),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027145),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027146),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027162),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027166),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027188),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002718B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002719B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271BB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271C1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271C4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271C5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271C7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271D2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271E7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100271F2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027240),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027249),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002724B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027291),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002731F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027910),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027911),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027917),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10027919),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002791E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002791F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002796E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029400),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002940A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029442),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002944E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029480),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029490),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029495),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002949C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100294C1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100294C3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100294C9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029501),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029505),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002954F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029552),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029553),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029555),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029583),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029588),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029589),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002958C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029591),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029596),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029598),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100295C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100295C4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100295C5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029610),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002970F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029710),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029712),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029715),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029802),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029832),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029840),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029851),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029874),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029900),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029902),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10029903),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AA10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AA30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AA38),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AA60),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AA68),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AA90),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AA98),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AAC0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1002AAD8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10040304),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10040305),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10040306),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10040307),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100B0020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100B0022),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100B0502),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100B0503),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100B0510),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100B0511),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice100B0515),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10110009),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1011000F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10110014),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10110019),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10110034),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10110046),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10111065),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101300B8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101300BC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101300D6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10136001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10136003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10136005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1014002E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140031),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1014003E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140090),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140096),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101400B7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140142),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140144),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140170),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140180),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101401BD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101401EF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140219),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1014028C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101402BD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1014032D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10140339),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1014033D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1014034A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101404DA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101A0007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101A1DC1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101A1FA8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101E1960),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice101E9063),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10221410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10221412),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10221414),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10221480),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10221487),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1022149C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10221510),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10221536),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102215D0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102215D1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102215DF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102215E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102215E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102215E2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102215E3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102215E6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10222000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10222001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10222020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102243B0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102243B5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102243B9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227440),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227443),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227460),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227464),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227468),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227469),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1022746B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1022746D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227801),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227804),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227807),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227808),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227809),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1022780B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1022780D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1022780E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227814),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10227901),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1022790B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1022790E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10229600),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10229601),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10229603),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10229606),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10232001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10238400),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10238420),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10238520),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10238620),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10239750),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10239880),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10251521),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10251523),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10251533),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10251541),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10257101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10280001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10280002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10280003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10280004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1028000A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1028000F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10280013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10280015),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10280016),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102A001F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102A00C5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102A00CF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B051A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B051B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B051F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0520),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0521),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0522),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0525),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0527),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0528),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0532),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0533),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0534),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0538),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0540),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B0550),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B1000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B1001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B2527),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B2537),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B2538),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B2539),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B475D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B475F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B47A1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B47C1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102B4949),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102C00C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102C00E5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102C0C30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice102F0020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10330035),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10330067),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10330074),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103300CD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103300E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10330194),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10390004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1039000A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10390182),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10390191),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10390200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10390300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10390741),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10390761),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10390900),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10391182),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10391183),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10395513),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10396300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10396325),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10396326),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10396330),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10397001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10397002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10397007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10397012),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10397016),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10397018),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10397502),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C1029),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C102A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C1031),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C1048),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C1290),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C22F6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3220),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3230),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3238),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3239),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C323A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C323B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C323C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3301),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3302),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3306),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3307),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C3308),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice103C9602),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10430675),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10439602),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1044A501),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1044A511),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10488901),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104A0010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104A0500),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C3D07),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8009),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8019),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8021),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8022),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8023),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8024),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8025),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8026),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8027),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8029),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C802B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C802E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8031),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8032),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8033),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8034),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8035),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8039),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C803A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C803B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C803C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C803D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8204),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8231),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8235),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C823F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8241),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C8400),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104C9066),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CA106),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC16),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC1B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC1C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC42),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC44),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC46),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC47),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC4A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC51),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC54),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC55),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC56),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC60),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC8E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice104CAC8F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10500840),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10506692),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10571801),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10573410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10575600),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A0D30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A0D38),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A3319),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A3373),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A3376),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A4D30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A4D33),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A4D38),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A4D68),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A4D69),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A5275),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A6268),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A6269),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105A8650),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105D2339),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105D493D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice105D5348),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10690050),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1069B166),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1069BA56),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1069BA57),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice106B0031),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice106B003F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10730004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10730005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10730008),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1073000A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1073000C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1073000D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10730010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10730012),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10732000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10771216),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10771634),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10771644),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10771654),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10771656),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1077165C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1077165E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10771664),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772031),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772071),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772081),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772261),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772281),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772312),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772422),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772432),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10772532),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778021),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778022),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778030),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778070),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778080),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778084),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10778090),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108D0004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108D0007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108D0008),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108D0019),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108E1100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108E1101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108E1102),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108E1103),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108E5000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice108EA001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10920028),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1093727E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1093C4C4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10950648),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10950649),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10950670),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10950680),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10953112),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10953114),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10953124),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10953512),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10953531),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice109E0369),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice109E036C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice109E036E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice109E036F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice109E0370),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice109E0878),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice109E0879),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10A90009),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B41B1D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B50557),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B51000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B52000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B54000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B54001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B54002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B56540),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B56541),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B56542),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B58624),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B587B0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B59030),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B59050),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B59054),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B59056),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B5906D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B59080),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B59656),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B59733),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B59749),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B5D00D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B5D33D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B5D44D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B60002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B60003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B60006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B60007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B60009),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B6000A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B6000B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B6000C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B70001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B70013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B71007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B71700),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B73590),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B75057),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B75157),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B75257),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B75B57),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B76056),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B76560),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B76561),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B76562),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B76563),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79054),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79055),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79201),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79800),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79805),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79904),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B79905),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B80005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B80006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B90111),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B91521),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B91523),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B91533),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B91541),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B91563),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B95229),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B95237),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B95239),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B95288),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B95451),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B95455),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B95457),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10B97101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10BA0308),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10C80004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10C80005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10C80006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10C80016),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10C88005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10CD1300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10D90531),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DD0100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0028),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0029),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE002C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE002D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0041),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0042),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0045),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0047),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0050),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0051),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0052),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0053),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0054),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0055),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0057),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0059),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE005A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE005B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE005E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0060),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0064),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0065),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0066),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0067),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0068),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE006A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE006B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE006E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0080),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0084),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0085),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0087),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0088),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE008A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00A0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00CD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00DF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00E3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00E4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00E5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00E7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00E8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00EA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00F1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00F2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00F6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE00F9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0103),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0110),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0113),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0140),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0141),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0150),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0151),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0152),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0170),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0171),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0172),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0176),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0179),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0181),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0193),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01D1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01D3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01D8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01DE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01EA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01EB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01EC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01ED),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01EE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01EF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE01F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0202),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0221),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0240),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0242),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0244),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0247),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0251),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0253),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0260),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0261),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0264),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0265),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0266),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0267),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0269),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE026B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE026C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE026D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE026E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE026F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0270),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0271),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0272),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE027E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE027F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0291),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0295),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE029D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02E4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02F1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02F8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02F9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02FA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02FC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02FD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02FE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE02FF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0314),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0322),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0324),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0326),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0329),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0330),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0331),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0334),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0341),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0347),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0361),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0362),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0364),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0368),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0369),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE036C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE036D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE036E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0371),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0373),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE037F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0391),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0392),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0393),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0398),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE039C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03D0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03E2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03E8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03E9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03EA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03EB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03EC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03EF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03F1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03F2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03F3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03F5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE03F6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0400),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0402),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0404),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE040C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0421),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0425),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0427),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0429),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0442),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0444),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0446),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0447),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0448),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0449),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE044A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0450),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0454),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0455),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0458),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0459),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE045A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE045B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE045D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE053B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0542),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0547),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0548),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE054C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0550),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0554),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0555),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE055C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE055E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE055F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0560),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0562),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0568),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0569),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE056A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE056C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE056D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE056E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE056F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE05E3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE05E7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0609),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0610),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0611),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0614),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0615),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0622),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE062E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0641),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0644),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0649),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0652),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0654),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06D1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06D2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06DE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06DF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06E4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06E8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06E9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE06FF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0751),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0752),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0753),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0754),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0759),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE075A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE075B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE075C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE075D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0760),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0774),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0778),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE077A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE077B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE077C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE077D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE077E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07C1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07C3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07C8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07CB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07CD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07CE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07CF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07D0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07D1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07D2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07D3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07D6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07D7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07D8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07D9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07DA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07DC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07E3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07F4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07F8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07FC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE07FE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0847),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0849),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE084D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0863),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0866),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0867),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0872),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0873),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE087D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0A20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0A65),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0A6C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0A74),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0A7A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0A98),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AA0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AA2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AA3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AA4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AA5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AA6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AA7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AA9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AAB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AAD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AAE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AB0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AB4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AB9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AC0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AC4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AC6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AC7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AD0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0AD4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0BE2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0BE3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0BE9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0BEA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0BEB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0DD1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0DD8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0DE1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0DE9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0DEA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0DF4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0E08),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0E1B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0E22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0FC6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0FD1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0FD2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0FE3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0FE7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0FF6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE0FF7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1023),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1040),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE104A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1058),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE105A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE105B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1081),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1091),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1094),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1096),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE109B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE10F9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1140),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1180),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1185),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1189),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE118D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE11A3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE11B0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE11C2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE11C3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE11E3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1247),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1248),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE124D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE128B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1290),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1292),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1295),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1299),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1340),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1341),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE134D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE137A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1391),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE139A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE139B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE13BD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE13C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE13F2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE13F3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE13FA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1427),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE179C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE17F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1ADA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1ADB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1BA1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1BB5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1BB7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1BB9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1BBB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1BE0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1C20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1C23),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1C60),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1C82),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1CBA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1CBB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1D10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1D12),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1DB8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1DBA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1E07),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1E30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1E37),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1E78),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE1F02),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DE2206),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DF0720),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DFE200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DFE220),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DFE300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DFF100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DFF400),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DFFC00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10DFFD00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10E10391),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10E30148),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC5227),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC5229),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC522A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC5249),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC525A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC5287),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC5289),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8029),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8129),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8136),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8138),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8139),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8167),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8168),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8169),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8176),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8179),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8180),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EC8199),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10ECB723),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10ECB822),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice10EE7038),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020008),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020009),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1102000B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11020012),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11024001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11027002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11027003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11027005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11028938),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11030004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11032210),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11058475),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11058476),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060282),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060305),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060308),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060364),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060415),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060571),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060581),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060586),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060596),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060605),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060686),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11060691),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063038),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063043),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063044),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063053),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063057),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063058),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063059),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063065),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063068),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063074),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063099),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063104),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063106),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063116),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063147),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063149),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063164),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063168),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063177),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063188),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063189),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063205),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063227),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063249),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063288),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063403),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11063410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11064410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11066410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11067205),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11067410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11068410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11068598),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1106B188),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice110A4029),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice110A4069),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11131211),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11131216),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11139211),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice111A0003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice111A0005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice111A0007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice111D806A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice111D8088),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11270400),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11311561),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11311562),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11315400),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11315402),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11315405),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1131540B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11317130),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11317133),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11317134),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11317146),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11317160),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11317162),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11317164),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11317231),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11319730),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E017),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E018),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E019),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E01B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E01C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E01E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E022),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E024),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E028),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E02E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1133E032),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11370040),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11370042),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11370043),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11370044),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11370045),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11370046),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1137007A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice113700CF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11484000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11484300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11484320),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11489000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11489E00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice114F001D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice114F0024),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice114F0040),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice115D0003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice115D0005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice115D0007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice115D000B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice115D000F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice115D0101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice115D0103),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11632000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660132),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660201),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660203),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660212),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660213),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660214),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660217),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660220),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660221),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660223),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660227),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660230),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11660234),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1166024A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1166024B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1166040A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11790110),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11790601),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1179060A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1179060F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11790D01),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C0030),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C0042),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C0049),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C0064),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C0094),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C00BB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C00E6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C8070),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice117C8072),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800475),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800476),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800478),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800522),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800551),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800552),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800592),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800822),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800832),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800843),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11800852),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1180E476),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1180E822),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1180E823),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1180E832),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11861002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11861300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11863300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11864200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11864300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11864C00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB1FA6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB1FAA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB2A02),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4320),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4347),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4350),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4351),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4353),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4354),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4355),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4360),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4361),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4362),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4364),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB436A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB4381),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB6101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB6121),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB6480),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AB7042),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11AD0002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11ADC115),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11BD0040),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11BD0041),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11BD0042),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C10440),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C10441),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C10442),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C10445),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C10448),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C10449),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C1044A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C10450),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C15811),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C15901),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C18110),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C1AB11),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11C1AB30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11CB2000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11DE6057),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11DE6120),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11F62011),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11F62201),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice11F88032),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12024300),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice121700F7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice121711F7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12176933),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12176972),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12177110),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12177113),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12177120),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12177130),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12177223),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12178320),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12178330),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice121A0003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice121A0005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice121A0009),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice122D50DC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice122D80DA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice123F8120),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice123F8888),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12421560),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12440A00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12440E80),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice124B0040),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice125B1400),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice125D1968),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice125D1969),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice125D1978),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice125D1988),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice125D1989),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice125D1998),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice125D2898),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12603872),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12603873),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12603886),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12603890),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1260FFFF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12661910),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12741371),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12745880),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A1002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A1003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A1004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A1005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A1022),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A1023),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A1025),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A2005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A2013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A2014),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A2015),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A2016),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A4311),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A4320),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A4321),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A4322),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice127A8234),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12829102),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12838211),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12838212),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12838213),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12AE0001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12AE0002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12B91006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12B91007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12B91008),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12BE3042),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12D20018),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12D8E110),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12D91078),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12EB0001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12EB0002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12EB0003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice12EB8803),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13080001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13170985),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13171985),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13178201),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13190801),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13190802),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice131F2030),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice134D7890),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice134D7891),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1371434E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13940001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice139708B4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice139716B8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13972BD0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice139730B1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13A3002F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13A30033),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13A30034),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13A30035),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13A30037),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13C11001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13DF0001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13F00200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13F01023),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13F60100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13F60101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13F60111),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13F65011),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13F68788),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13FE1600),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice13FE16FF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14097168),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14097268),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14121712),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14121724),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14159501),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14159510),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14159511),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1415C158),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14250030),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14255001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice144DA808),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice144DA820),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice144DA821),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice144DA822),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice144DA824),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14C10008),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14C18043),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41600),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41639),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4163A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4163B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4163D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41644),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41645),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41646),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41647),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41648),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4164A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4164C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4164E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41650),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41653),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41654),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41657),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41659),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4165A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4165B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4165D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4165E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4165F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41668),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4166A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41677),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41678),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41679),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4167A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4167B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4167D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41682),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41688),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4168A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4168E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41691),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41692),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41693),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41696),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4169C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416A1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416A2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416A4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416A5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416A6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416A7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416A8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416A9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416AA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416AC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416AD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416AE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416AF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416B1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416C6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416C7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416D6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416D7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416D8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416D9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416E2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E416FD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4170C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4170D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41713),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E41750),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44301),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44311),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44312),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44315),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44318),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44319),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44320),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44324),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44325),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44328),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44329),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4432B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4432C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44331),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44353),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44357),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44359),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44365),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E443A3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44401),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E44727),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14E4D802),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11033),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11035),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11036),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11056),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11066),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11453),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11456),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11803),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F11815),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F12013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F12045),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F12093),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F12443),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F12702),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F12F00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F12F20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F12F30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F15B7A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F18800),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F18801),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F18802),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F18804),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F18811),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F18852),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice14F18880),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15160803),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15220100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15224000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15240510),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15241410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15241411),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15AD0801),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B31003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B31007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B31013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B31015),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B31017),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B31019),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B34117),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B3634A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B3673C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B36746),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B36750),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15B36764),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice15BC0105),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice16570013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice16570014),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice16570017),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice16570022),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice167B2102),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0012),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C001A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C001B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C001C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C001D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0023),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0024),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0027),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0029),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C002A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C002B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C002E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0030),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0032),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0033),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0034),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0036),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0037),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C003E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C0042),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168C1014),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice168CFF1D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice16AE1141),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice16F20200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17371032),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17371064),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice173B03EA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice177D9702),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice177D9712),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice177DA002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice177DA008),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice177DA01C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17CB0001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17CB0002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17D31214),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17D31280),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17D31680),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17D31880),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17D55831),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17D55832),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17D55833),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17FE2120),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice17FE2220),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18134000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18134100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140201),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140301),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140302),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140401),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140601),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140681),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140701),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18140781),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18143060),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18143090),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18143290),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18143298),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18145360),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18145390),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1814539F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18C30720),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18EC6D05),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18ECC006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18ECC032),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18ECC058),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18ECC132),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice18ECC232),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19240703),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19240710),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19240803),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19240813),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19240903),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19240923),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19240A03),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19240B03),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19246703),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19570084),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19570085),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice195700B6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19570111),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1957C006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19661980),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19691026),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19691048),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19691063),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19691090),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19691091),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19692062),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19711011),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice197B2361),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice197B2362),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice197B2363),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19A20700),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19A20704),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19A20710),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19A20714),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50123),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50202),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50203),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50205),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50206),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50210),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50211),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E50212),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E51822),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice19E5A221),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1A032000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1A780031),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1ADE3038),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1AED1005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1AF41110),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B210612),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B211042),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B211080),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B211184),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B360002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B360003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B360004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B360005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B360100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B3E1FA8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B4B2241),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B4B9123),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B4B9130),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B4B9230),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B6F7023),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B6F7052),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B731000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1B731100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1BB1005D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1BB10100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1C580003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1C580023),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1CB0D000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1D6AD107),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1D6C100D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1D6C100E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1D781512),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DD81000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DD81001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DD81002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DD81003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DD81004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DD81007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DF30201),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DF30202),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DF30203),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DF30204),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DF30205),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1DF30206),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1E0F0007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1E4C0010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1E570100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC93010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC93014),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC93110),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC93114),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC93310),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC93314),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC94020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC94022),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC94025),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC94026),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice1FC94027),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice33880021),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice33888011),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice33888012),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice33888013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice3D3D0002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice3D3D0003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice3D3D0006),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice3D3D0008),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice3D3D0009),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice3D3D000A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice3D3D000C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice3D3D07A2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice40054000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice40400001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice40400002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice40400005),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice40400100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice44440016),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice44440803),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice4A145000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice4C530000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice4C530001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338900),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338901),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338904),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338A01),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338A10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338A13),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338A20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338A21),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338A22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338A25),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338C01),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338C12),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338C13),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338C2E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53338E48),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice53339102),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice544D6178),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860044),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860045),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860046),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860082),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860083),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860084),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860085),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860087),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860089),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086008A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086008B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860090),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860091),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860100),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860102),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860104),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860105),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860116),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860126),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860150),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860151),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860152),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860153),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860154),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860155),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860156),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860158),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086015D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860162),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860166),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086016A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808602F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860326),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860327),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860412),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860416),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860600),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808606F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860885),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860886),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860887),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860888),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086088E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086088F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860890),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860891),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860892),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860893),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860894),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860895),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860896),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860897),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808608AE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808608AF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808608B1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808608B2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808608B3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808608B4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860953),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086095A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086095B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860A04),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860A0C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860A16),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860A54),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860A55),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860B60),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860BE1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860BF5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860C00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860C04),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860C0C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860CF8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860D58),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E02),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E08),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E21),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E23),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E24),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E25),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E27),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E28),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E2A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E2C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E34),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E36),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860E81),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860EA0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80860F35),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861002),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861004),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861008),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861009),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086100C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086100D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086100E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086100F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861011),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861012),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861014),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861015),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861016),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861017),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861018),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861019),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086101A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086101D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086101E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861026),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861027),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861028),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861031),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861038),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861039),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086103D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861040),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861043),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861048),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861049),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861050),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086105E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086105F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861060),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861064),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861068),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861075),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861076),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861077),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861078),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861079),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086107A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086107B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086107C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086107D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086107E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086108A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086108B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861092),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861096),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861099),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086109A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086109E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610A4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610A5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610A7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610B5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610B9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610BC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610BD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610C6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610C7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610C8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610C9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610D3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610D6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610D9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610DA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610E1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610E2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610E6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610E7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610E8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610EA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610EC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610EF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610F1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610F4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610F5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610F7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610F8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808610FB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861130),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861132),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861161),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861209),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861229),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861237),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861361),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861461),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861502),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861503),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086150B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086150D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086150E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861514),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861516),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861517),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086151C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861521),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861522),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861523),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861526),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861527),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861528),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861533),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861537),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086153A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086154A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086154D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861557),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861558),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086155A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086155C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086155D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861563),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086156F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861572),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861581),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861583),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861584),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861586),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861587),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861588),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861589),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086158A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086158B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861592),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861593),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086159B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615AA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615AB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615AC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615D0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615D1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615D5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615D8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615F2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808615FF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861616),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861903),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861904),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861906),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086190C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861910),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861911),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861916),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861919),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086191B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086191E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861960),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861962),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861A30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861A38),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861A48),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861B48),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C02),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C03),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C04),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C12),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C14),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C16),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C18),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C1A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C1E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C27),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C2C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C2D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C3A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C46),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C49),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C4A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C4B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C4F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C52),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861C56),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D02),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D18),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D1E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D24),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D2D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D3A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D3B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D3E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D41),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861D6B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E01),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E02),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E03),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E09),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E12),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E14),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E16),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E18),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E1A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E1E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E24),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E2D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E31),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E3A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E44),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E4A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E59),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E5D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861E5E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80861F40),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862415),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862425),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862440),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862442),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862443),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862444),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862445),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862446),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862448),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862449),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086244A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086244B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086244E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862482),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862483),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862484),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862485),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862486),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862487),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086248A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086248B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624C2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624C3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624C4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624C5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624C6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624C7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624CA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624CB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624CC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624CD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624D1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624D2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624D3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624D4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624D5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624D6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624D7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624DB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624DD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624DE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624DF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624F3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624F4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808624FD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862500),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862501),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862530),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862531),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862540),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862541),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862544),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086254C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862560),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862562),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862570),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862572),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862578),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862580),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862582),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862584),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862590),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862591),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862592),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625A2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625A3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625A4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625A6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625A9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625AA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625AB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625AC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625AD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625B0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625D4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625D8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625F1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625F3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625F5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808625F6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862600),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862620),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862621),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862622),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862623),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862624),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862625),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862626),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862627),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862640),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862641),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862651),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862652),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862653),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862658),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862659),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086265A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086265B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086265C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862660),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862662),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862664),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862666),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862668),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086266A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086266D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086266E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086266F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862670),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862681),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862682),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862688),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862689),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086268A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086268B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086268C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862690),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862692),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086269B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086269E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862700),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862701),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862723),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862770),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862772),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862778),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086277C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862782),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862792),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627A0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627A1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627A2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627A6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627AC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627AE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627B0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627B8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627B9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627BC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627BD),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627C1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627C3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627C4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627C5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627C8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627C9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627CA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627CB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627CC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627D0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627D2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627D4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627D6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627D8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627DA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627DC),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627DE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627DF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627E0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808627E2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862810),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862811),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862815),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862820),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862822),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862824),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862825),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862826),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862828),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862829),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086282A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862830),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862831),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862832),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862833),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862834),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862835),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862836),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086283A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086283E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086283F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862841),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862843),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862845),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862847),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086284B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862850),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862914),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862916),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862917),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862918),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862920),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862921),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862922),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862925),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862926),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862929),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086292D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862930),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862932),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862934),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862935),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862936),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862937),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862938),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862939),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086293A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086293C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086293E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862940),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862942),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862944),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862946),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862948),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086294A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086294C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862970),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862972),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862990),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629A0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629A2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629B0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629B1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629B2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629B3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629B4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629B6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629B7),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629C1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629C2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629C3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808629C4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A02),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A03),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A04),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A06),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A07),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A12),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A13),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A40),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A41),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A42),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A43),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862A44),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862E12),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862E20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862E21),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862E22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862E23),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862E30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80862E32),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863165),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863166),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863198),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863200),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863310),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863340),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863341),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863403),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863406),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863408),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086340A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086340E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863422),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863423),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086342E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863500),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086350C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863510),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863518),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863575),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863577),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863580),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863581),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863582),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863584),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863585),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863590),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863591),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863592),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863593),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863594),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863595),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863597),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863598),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863599),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086359B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086359E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086360C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808637C8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808637CE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808637D0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808637D1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808637D2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808637D3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A16),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A25),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A34),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A35),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A36),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A37),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A38),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A39),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A3A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A3C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A3E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A40),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A44),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A46),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A48),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863A4A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B07),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B09),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B0A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B14),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B25),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B28),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B29),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B2D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B2E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B2F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B30),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B32),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B34),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B3C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B42),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B44),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B46),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B48),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B4A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B56),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B64),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863B67),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863E1F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863E92),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863EA0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80863EC2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864220),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864222),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864223),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864227),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864229),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086422B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086422C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864230),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864232),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864237),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864238),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80864239),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086423C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086423D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80865201),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80865845),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80865904),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086590F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80865914),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80865916),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80865917),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808665F0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808665F1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F00),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F21),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F23),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F24),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F25),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F27),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F28),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F29),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F2A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80866F2C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867020),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867110),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867111),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867112),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867113),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867120),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867121),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867124),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867125),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867190),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867191),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867192),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867194),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867195),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808671A0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice808671A2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80867800),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868500),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C02),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C03),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C10),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C12),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C2D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C31),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C3A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C3D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C4C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C4E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868C4F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D06),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D2D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D31),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D3A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D3B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D44),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80868D7C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869C03),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869C20),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869C22),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869C26),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869C31),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869C3A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869C43),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D03),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D14),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D15),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D18),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D21),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D23),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D2F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D31),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D32),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D35),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D3A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D3D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D43),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D46),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D48),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D4E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D58),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D60),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D61),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D62),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D70),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D71),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869D84),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869DB4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869DC8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869DE8),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80869DE9),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A000),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A011),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A012),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A103),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A121),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A123),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A12F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A131),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A13A),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A14E),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A160),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A161),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A170),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1A1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1A3),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1A4),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1AF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1B1),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1BA),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1BB),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1BE),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A1C2),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A304),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A323),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A324),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A348),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A352),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A360),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A36D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A370),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086A379),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086B152),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086B555),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086D130),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086D131),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086D132),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086D138),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice8086F1A6),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80880101),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80880102),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80880103),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80880104),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80880105),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80880106),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80880107),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80880108),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80881001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice80882001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90045078),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90045647),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90046075),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90046178),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90046915),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90047815),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90047895),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90048078),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90048178),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90048778),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90048878),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050010),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050013),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005001F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050050),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050051),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050053),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050080),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050081),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005008F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice900500C0),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice900500C5),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice900500CF),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050250),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050283),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050284),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050285),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050286),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005028B),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005028C),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005028D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005028F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050410),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050412),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005041F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050430),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050432),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050500),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90050503),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90058011),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice90058017),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005801D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005801F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005808F),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice9005809D),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice97109815),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice97109835),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice97109845),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDevice97109855),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDeviceDD010003),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDeviceDD010007),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDeviceDD010011),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDeviceDD010201),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDeviceE1590001),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciSubDeviceF1D0EB16),                                     4);
        TEST_ASSERT_EQUALS(sizeof(PciVendor),                                                2);
        TEST_ASSERT_EQUALS(sizeof(PciVendorCapability),                                      4);
        TEST_ASSERT_EQUALS(sizeof(PciVitalProductDataAddressUnion),                          2);
        TEST_ASSERT_EQUALS(sizeof(PciVitalProductDataCapability),                            8);
        TEST_ASSERT_EQUALS(sizeof(PGD),                                                      8);
        TEST_ASSERT_EQUALS(sizeof(PMD),                                                      8);
        TEST_ASSERT_EQUALS(sizeof(Png),                                                      1);
        TEST_ASSERT_EQUALS(sizeof(PngChunk),                                                 8);
        TEST_ASSERT_EQUALS(sizeof(PngChunkType),                                             4);
        TEST_ASSERT_EQUALS(sizeof(PngColorType),                                             1);
        TEST_ASSERT_EQUALS(sizeof(PngCompressionMethod),                                     1);
        TEST_ASSERT_EQUALS(sizeof(PngDecoder),                                               112);
        TEST_ASSERT_EQUALS(sizeof(PngEmbeddedIccProfile),                                    80);
        TEST_ASSERT_EQUALS(sizeof(PngFilterMethod),                                          1);
        TEST_ASSERT_EQUALS(sizeof(PngFilterType),                                            1);
        TEST_ASSERT_EQUALS(sizeof(PngHeader),                                                16);
        TEST_ASSERT_EQUALS(sizeof(PngImageGamma),                                            4);
        TEST_ASSERT_EQUALS(sizeof(PngImageHeader),                                           13);
        TEST_ASSERT_EQUALS(sizeof(PngImageLastModificationTime),                             7);
        TEST_ASSERT_EQUALS(sizeof(PngInterlaceMethod),                                       1);
        TEST_ASSERT_EQUALS(sizeof(PngPhysicalPixelDimensions),                               9);
        TEST_ASSERT_EQUALS(sizeof(PngPrimaryChromaticities),                                 32);
        TEST_ASSERT_EQUALS(sizeof(PngRenderingIntent),                                       1);
        TEST_ASSERT_EQUALS(sizeof(PngSignificantBits),                                       4);
        TEST_ASSERT_EQUALS(sizeof(PngStandardRgbColorSpace),                                 1);
        TEST_ASSERT_EQUALS(sizeof(PngUnitSpecifier),                                         1);
        TEST_ASSERT_EQUALS(sizeof(PressEventHandler),                                        8);
        TEST_ASSERT_EQUALS(sizeof(ProgressBarWidget),                                        152);
        TEST_ASSERT_EQUALS(sizeof(PTE),                                                      8);
        TEST_ASSERT_EQUALS(sizeof(PUD),                                                      8);
        TEST_ASSERT_EQUALS(sizeof(Register128Bit),                                           16);
        TEST_ASSERT_EQUALS(sizeof(Register256Bit),                                           32);
        TEST_ASSERT_EQUALS(sizeof(Register512Bit),                                           64);
        TEST_ASSERT_EQUALS(sizeof(RgbaPixel),                                                4);
        TEST_ASSERT_EQUALS(sizeof(RgbPixel),                                                 3);
        TEST_ASSERT_EQUALS(sizeof(RootWidget),                                               104);
        TEST_ASSERT_EQUALS(sizeof(ScreenWidget),                                             144);
        TEST_ASSERT_EQUALS(sizeof(Serial),                                                   1);
        TEST_ASSERT_EQUALS(sizeof(StretchRange),                                             4);
        TEST_ASSERT_EQUALS(sizeof(TabButton),                                                304);
        TEST_ASSERT_EQUALS(sizeof(TableCellWidget),                                          88);
        TEST_ASSERT_EQUALS(sizeof(TableHeaderWidget),                                        104);
        TEST_ASSERT_EQUALS(sizeof(TableRowWidget),                                           120);
        TEST_ASSERT_EQUALS(sizeof(TableWidget),                                              240);
        TEST_ASSERT_EQUALS(sizeof(TabPageWidget),                                            88);
        TEST_ASSERT_EQUALS(sizeof(TabWidget),                                                152);
        TEST_ASSERT_EQUALS(sizeof(Time),                                                     1);
        TEST_ASSERT_EQUALS(sizeof(ToolButton),                                               192);
        TEST_ASSERT_EQUALS(sizeof(TreeNodeWidget),                                           216);
        TEST_ASSERT_EQUALS(sizeof(TreeWidget),                                               176);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerMode),                                  56);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerModeAttributeFlag),                     4);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerProtocol),                              32);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerState),                                 32);
        TEST_ASSERT_EQUALS(sizeof(UefiAbsolutePointerStateActiveButtonFlag),                 4);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpi20ConfigurationTable),                             1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiAddressSpaceDescriptor),                           46);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiConfigurationTable),                               1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiDescriptor),                                       1);
        TEST_ASSERT_EQUALS(sizeof(UefiAcpiResourceType),                                     1);
        TEST_ASSERT_EQUALS(sizeof(UefiAllocateType),                                         4);
        TEST_ASSERT_EQUALS(sizeof(UefiBlockIoMedia),                                         48);
        TEST_ASSERT_EQUALS(sizeof(UefiBlockIoProtocol),                                      48);
        TEST_ASSERT_EQUALS(sizeof(UefiBootServices),                                         376);
        TEST_ASSERT_EQUALS(sizeof(UefiCapsuleHeader),                                        28);
        TEST_ASSERT_EQUALS(sizeof(UefiConfigurationTable),                                   24);
        TEST_ASSERT_EQUALS(sizeof(UefiConsoleControlProtocol),                               24);
        TEST_ASSERT_EQUALS(sizeof(UefiConsoleControlScreenMode),                             4);
        TEST_ASSERT_EQUALS(sizeof(UefiCpuPhysicalLocation),                                  12);
        TEST_ASSERT_EQUALS(sizeof(UefiDebugInfoConfigurationTable),                          1);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePath),                                           4);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathSubType),                                    1);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathToTextProtocol),                             16);
        TEST_ASSERT_EQUALS(sizeof(UefiDevicePathType),                                       1);
        TEST_ASSERT_EQUALS(sizeof(UefiDxeServicesConfigurationTable),                        1);
        TEST_ASSERT_EQUALS(sizeof(UefiEventType),                                            4);
        TEST_ASSERT_EQUALS(sizeof(UefiFileAttributeFlag),                                    8);
        TEST_ASSERT_EQUALS(sizeof(UefiFileInfo),                                             80);
        TEST_ASSERT_EQUALS(sizeof(UefiFileIoToken),                                          32);
        TEST_ASSERT_EQUALS(sizeof(UefiFileModeFlag),                                         8);
        TEST_ASSERT_EQUALS(sizeof(UefiFilePath),                                             4);
        TEST_ASSERT_EQUALS(sizeof(UefiFileProtocol),                                         120);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputBltOperation),                           4);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputBltPixel),                               4);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputModeInformation),                        36);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputProtocol),                               32);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsOutputProtocolMode),                           40);
        TEST_ASSERT_EQUALS(sizeof(UefiGraphicsPixelFormat),                                  4);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePath),                                  48);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePathMbrType),                           1);
        TEST_ASSERT_EQUALS(sizeof(UefiHardDriveDevicePathSignatureType),                     1);
        TEST_ASSERT_EQUALS(sizeof(UefiHcdpConfigurationTable),                               1);
        TEST_ASSERT_EQUALS(sizeof(UefiHobListConfigurationTable),                            1);
        TEST_ASSERT_EQUALS(sizeof(UefiInfo),                                                 40);
        TEST_ASSERT_EQUALS(sizeof(UefiInputKey),                                             4);
        TEST_ASSERT_EQUALS(sizeof(UefiInputKeyScanCode),                                     2);
        TEST_ASSERT_EQUALS(sizeof(UefiInterfaceType),                                        4);
        TEST_ASSERT_EQUALS(sizeof(UefiIpAddress),                                            16);
        TEST_ASSERT_EQUALS(sizeof(UefiIpV4Address),                                          4);
        TEST_ASSERT_EQUALS(sizeof(UefiIpV6Address),                                          16);
        TEST_ASSERT_EQUALS(sizeof(UefiLoadedImageProtocol),                                  96);
        TEST_ASSERT_EQUALS(sizeof(UefiLocateSearchType),                                     4);
        TEST_ASSERT_EQUALS(sizeof(UefiLzmaDecompressConfigurationTable),                     1);
        TEST_ASSERT_EQUALS(sizeof(UefiMacAddress),                                           32);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryAttributesConfigurationTable),                   16);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryDescriptor),                                     40);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryMapInfo),                                        32);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryStatusCodeRecordConfigurationTable),             1);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryType),                                           4);
        TEST_ASSERT_EQUALS(sizeof(UefiMemoryTypeInformationConfigurationTable),              1);
        TEST_ASSERT_EQUALS(sizeof(UefiMpsConfigurationTable),                                1);
        TEST_ASSERT_EQUALS(sizeof(UefiMpServicesProtocol),                                   56);
        TEST_ASSERT_EQUALS(sizeof(UefiNetworkStatistics),                                    208);
        TEST_ASSERT_EQUALS(sizeof(UefiOpenProtocolInformationEntry),                         24);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocol),                                        160);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAccess),                                  16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolAttributeOperation),                      4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolConfigAccess),                            16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolOperation),                               4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciIoProtocolWidth),                                   4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciRootBridgeIoProtocol),                              152);
        TEST_ASSERT_EQUALS(sizeof(UefiPciRootBridgeIoProtocolAccess),                        16);
        TEST_ASSERT_EQUALS(sizeof(UefiPciRootBridgeIoProtocolOperation),                     4);
        TEST_ASSERT_EQUALS(sizeof(UefiPciRootBridgeIoProtocolWidth),                         4);
        TEST_ASSERT_EQUALS(sizeof(UefiPixelBitmask),                                         16);
        TEST_ASSERT_EQUALS(sizeof(UefiProcessorInformation),                                 24);
        TEST_ASSERT_EQUALS(sizeof(UefiProcessorInformationStatusFlag),                       4);
        TEST_ASSERT_EQUALS(sizeof(UefiPropertiesConfigurationTable),                         1);
        TEST_ASSERT_EQUALS(sizeof(UefiResetType),                                            4);
        TEST_ASSERT_EQUALS(sizeof(UefiRuntimeServices),                                      136);
        TEST_ASSERT_EQUALS(sizeof(UefiSalSystemConfigurationTable),                          1);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleFileSystemProtocol),                             16);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleInputInterface),                                 24);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkInterfaceType),                           1);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkInterruptFlag),                           4);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkMode),                                    656);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkProtocol),                                128);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkReceiveFilterFlag),                       4);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleNetworkState),                                   4);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerMode),                                    32);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerProtocol),                                32);
        TEST_ASSERT_EQUALS(sizeof(UefiSimplePointerState),                                   16);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleTextOutputInterface),                            80);
        TEST_ASSERT_EQUALS(sizeof(UefiSimpleTextOutputMode),                                 24);
        TEST_ASSERT_EQUALS(sizeof(UefiSmbios3ConfigurationTable),                            24);
        TEST_ASSERT_EQUALS(sizeof(UefiSmbiosConfigurationTable),                             31);
        TEST_ASSERT_EQUALS(sizeof(UefiStatus),                                               8);
        TEST_ASSERT_EQUALS(sizeof(UefiSystemResourceConfigurationTable),                     1);
        TEST_ASSERT_EQUALS(sizeof(UefiSystemTable),                                          120);
        TEST_ASSERT_EQUALS(sizeof(UefiTableHeader),                                          24);
        TEST_ASSERT_EQUALS(sizeof(UefiTime),                                                 16);
        TEST_ASSERT_EQUALS(sizeof(UefiTimeCapabilities),                                     12);
        TEST_ASSERT_EQUALS(sizeof(UefiTimerDelay),                                           4);
        TEST_ASSERT_EQUALS(sizeof(UefiTpl),                                                  8);
        TEST_ASSERT_EQUALS(sizeof(UefiUgaIoConfigurationTable),                              1);
        TEST_ASSERT_EQUALS(sizeof(UefiVariableAttributeFlag),                                4);
        TEST_ASSERT_EQUALS(sizeof(Uuid),                                                     16);
        TEST_ASSERT_EQUALS(sizeof(VerticalAlignment),                                        1);
        TEST_ASSERT_EQUALS(sizeof(Widget),                                                   88);
        TEST_ASSERT_EQUALS(sizeof(WidgetState),                                              1);
        TEST_ASSERT_EQUALS(sizeof(WrapperWidget),                                            88);
        TEST_ASSERT_EQUALS(sizeof(X86Bug),                                                   2);
        TEST_ASSERT_EQUALS(sizeof(x86BugWord),                                               1);
        TEST_ASSERT_EQUALS(sizeof(X86Feature),                                               2);
        TEST_ASSERT_EQUALS(sizeof(x86FeatureWord),                                           1);
        TEST_ASSERT_EQUALS(sizeof(XFeature),                                                 1);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512OpmaskState),                                64);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512ZmmFrom0To15State),                          512);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512ZmmFrom16To31State),                         1024);
        TEST_ASSERT_EQUALS(sizeof(XFeatureAvxState),                                         256);
        TEST_ASSERT_EQUALS(sizeof(XFeatureFlag),                                             4);
        TEST_ASSERT_EQUALS(sizeof(XFeatureMpxBoundConfigAndStatusRegistersState),            64);
        TEST_ASSERT_EQUALS(sizeof(XFeatureMpxBoundRegistersState),                           64);
        TEST_ASSERT_EQUALS(sizeof(XFeaturePkruState),                                        8);
        TEST_ASSERT_EQUALS(sizeof(XFeatureTypeFlag),                                         8);
        TEST_ASSERT_EQUALS(sizeof(XSaveState),                                               576);
        TEST_ASSERT_EQUALS(sizeof(XStateHeader),                                             64);
        TEST_ASSERT_EQUALS(sizeof(ZLib),                                                     1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionInfo),                                      1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionLevel),                                     1);
        TEST_ASSERT_EQUALS(sizeof(ZLibCompressionMethod),                                    1);
        TEST_ASSERT_EQUALS(sizeof(ZLibHeader),                                               2);

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(sizeof(P4D), 8);
#endif
    }
    TEST_CASE_END();



    TEST_CASE("DmiBiosExtendedRomSize");
    {
        DmiBiosExtendedRomSize temp;



        // DmiBiosExtendedRomSize:
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



        // DmiCacheConfiguration:
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



        // DmiCacheSize:
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



        // DmiCacheSize2:
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



        // DmiChassisContainedElementType:
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



        // DmiChassisEntry:
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



        // DmiCoolingDeviceEntry:
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



        // DmiElectricalCurrentProbeEntry:
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



        // DmiHardwareSecuritySettings:
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



        // DmiMemoryDeviceAttributes:
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



        // DmiMemoryDeviceExtendedSize:
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



        // DmiMemoryDeviceSize:
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



        // DmiOnboardDevicesDevice:
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



        // DmiOnboardDevicesExtendedEntry:
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



        // DmiOnboardDevicesExtendedEntry:
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



        // DmiPortableBatteryManufactureDate:
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



        // DmiProcessorEntry:
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



        // DmiProcessorSignature:
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



        // DmiProcessorVoltage:
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



        // DmiSystemPowerSupplyCharacteristics:
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



        // DmiSystemResetCapabilities:
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



        // DmiSystemSlotsEntryV26:
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



        // DmiSystemSlotsPeerGroup:
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



        // DmiTemperatureProbeEntry:
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



        // DmiVoltageProbeEntry:
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



        // IdtDescriptor:
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



        // JpegHuffmanTable:
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



        // JpegQuantizationTable:
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



        // JpegStartOfFrameComponent:
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



        // JpegStartOfScanComponent:
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



    TEST_CASE("PciAcceleratedGraphicsPortCommand");
    {
        PciAcceleratedGraphicsPortCommand temp;



        // PciAcceleratedGraphicsPortCommand:
        // =====================================================================================================
        // |                                 maximumNumberOfCommandRequests : 8                                |
        // |                                     __reserved2 ... : 8 (14)                                      |
        // |  ... __reserved2 : 6 (14)  |  enableSideBandAddressing : 1  |  enableAcceleratedGraphicsPort : 1  |
        // |  __reserved : 5  |                                    rate : 3                                    |
        // =====================================================================================================



        temp.value32 = 0x4D4D9563;                  // ||  01001101  ||  01001101  ...  100101  |  0  |  1  ||  01100  |  011  ||

        TEST_ASSERT_EQUALS(temp.rate,                           3);
        TEST_ASSERT_EQUALS(temp.__reserved,                     12);
        TEST_ASSERT_EQUALS(temp.enableAcceleratedGraphicsPort,  1);
        TEST_ASSERT_EQUALS(temp.enableSideBandAddressing,       0);
        TEST_ASSERT_EQUALS(temp.__reserved2,                    4965);
        TEST_ASSERT_EQUALS(temp.maximumNumberOfCommandRequests, 77);



        temp.rate = 4;                              // ||  01001101  ||  01001101  ...  100101  |  0  |  1  ||  01100  |  100  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D4D9564);



        temp.__reserved = 5;                        // ||  01001101  ||  01001101  ...  100101  |  0  |  1  ||  00101  |  100  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D4D952C);



        temp.enableAcceleratedGraphicsPort = 0;     // ||  01001101  ||  01001101  ...  100101  |  0  |  0  ||  00101  |  100  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D4D942C);



        temp.enableSideBandAddressing = 1;          // ||  01001101  ||  01001101  ...  100101  |  1  |  0  ||  00101  |  100  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D4D962C);



        temp.__reserved2 = 9876;                    // ||  01001101  ||  10011010  ...  010100  |  1  |  0  ||  00101  |  100  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D9A522C);



        temp.maximumNumberOfCommandRequests = 7;    // ||  00000111  ||  10011010  ...  010100  |  1  |  0  ||  00101  |  100  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x079A522C);
    }
    TEST_CASE_END();



    TEST_CASE("PciAcceleratedGraphicsPortStatus");
    {
        PciAcceleratedGraphicsPortStatus temp;



        // PciAcceleratedGraphicsPortStatus:
        // ===========================================================================================
        // |                            maximumNumberOfCommandRequests : 8                           |
        // |                                __reserved2 : 8 (14) ...                                 |
        // |  ... __reserved2 : 6 (14)  |  supportSideBandAddressing : 1  |  __reserved : 1 (7) ...  |
        // |   ... __reserved : 6 (7)   |                          rate : 2                          |
        // ===========================================================================================



        temp.value32 = 0x4D4D9563;                  // ||  01001101  ||  01001101  ...  100101  |  0  |  1  ...  011000  |  11  ||

        TEST_ASSERT_EQUALS(temp.rate,                           3);
        TEST_ASSERT_EQUALS(temp.__reserved,                     88);
        TEST_ASSERT_EQUALS(temp.supportSideBandAddressing,      0);
        TEST_ASSERT_EQUALS(temp.__reserved2,                    4965);
        TEST_ASSERT_EQUALS(temp.maximumNumberOfCommandRequests, 77);



        temp.rate = 1;                              // ||  01001101  ||  01001101  ...  100101  |  0  |  1  ...  011000  |  01  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D4D9561);



        temp.__reserved = 5;                        // ||  01001101  ||  01001101  ...  100101  |  0  |  0  ...  000101  |  01  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D4D9415);



        temp.supportSideBandAddressing = 1;         // ||  01001101  ||  01001101  ...  100101  |  1  |  0  ...  000101  |  01  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D4D9615);



        temp.__reserved2 = 9876;                    // ||  01001101  ||  10011010  ...  010100  |  1  |  0  ...  000101  |  01  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x4D9A5215);



        temp.maximumNumberOfCommandRequests = 7;    // ||  00000111  ||  10011010  ...  010100  |  1  |  0  ...  000101  |  01  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x079A5215);
    }
    TEST_CASE_END();



    TEST_CASE("PciBuiltInSelfTest");
    {
        PciBuiltInSelfTest temp;



        // PciBuiltInSelfTest:
        // =============================================================================
        // |  capable : 1  |  startBist : 1  |  __reserved : 2  |  completionCode : 4  |
        // =============================================================================



        temp.value8 = 0x9D;         // ||  1  |  0  |  01  |  1101  ||

        TEST_ASSERT_EQUALS(temp.completionCode, 13);
        TEST_ASSERT_EQUALS(temp.__reserved,     1);
        TEST_ASSERT_EQUALS(temp.startBist,      0);
        TEST_ASSERT_EQUALS(temp.capable,        1);



        temp.completionCode = 10;   // ||  1  |  0  |  01  |  1010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x9A);



        temp.__reserved = 3;        // ||  1  |  0  |  11  |  1010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0xBA);



        temp.startBist = 1;         // ||  1  |  1  |  11  |  1010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0xFA);



        temp.capable = 0;           // ||  0  |  1  |  11  |  1010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x7A);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedBridgeSecondaryStatus");
    {
        PciExtendedBridgeSecondaryStatus temp;



        // PciExtendedBridgeSecondaryStatus:
        // =====================================================================================================================================================================================================================================
        // |                                                                                      __reserved : 7                                                                                       |  secondaryClockFrequency : 1 (3) ...  |
        // |  ... secondaryClockFrequency : 2 (3)  |  splitRequestDelayed : 1  |  splitCompletionOverrun : 1  |  unexpectedSplitCompletion : 1  |  splitCompletionDiscarded : 1  |  support133MHz : 1  |           is64BitDevice : 1           |
        // =====================================================================================================================================================================================================================================



        temp.value16 = 0xCB55;                  // ||  1100101  |  1  ...  01  |  0  |  1  |  0  |  1  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.is64BitDevice,             1);
        TEST_ASSERT_EQUALS(temp.support133MHz,             0);
        TEST_ASSERT_EQUALS(temp.splitCompletionDiscarded,  1);
        TEST_ASSERT_EQUALS(temp.unexpectedSplitCompletion, 0);
        TEST_ASSERT_EQUALS(temp.splitCompletionOverrun,    1);
        TEST_ASSERT_EQUALS(temp.splitRequestDelayed,       0);
        TEST_ASSERT_EQUALS(temp.secondaryClockFrequency,   5);
        TEST_ASSERT_EQUALS(temp.__reserved,                101);



        temp.is64BitDevice = 0;                 // ||  1100101  |  1  ...  01  |  0  |  1  |  0  |  1  |  0  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCB54);



        temp.support133MHz = 1;                 // ||  1100101  |  1  ...  01  |  0  |  1  |  0  |  1  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCB56);



        temp.splitCompletionDiscarded = 0;      // ||  1100101  |  1  ...  01  |  0  |  1  |  0  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCB52);



        temp.unexpectedSplitCompletion = 1;     // ||  1100101  |  1  ...  01  |  0  |  1  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCB5A);



        temp.splitCompletionOverrun = 0;        // ||  1100101  |  1  ...  01  |  0  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCB4A);



        temp.splitRequestDelayed = 1;           // ||  1100101  |  1  ...  01  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCB6A);



        temp.secondaryClockFrequency = 3;       // ||  1100101  |  0  ...  11  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCAEA);



        temp.__reserved = 7;                    // ||  0000111  |  0  ...  11  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x0EEA);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedBridgeStatus");
    {
        PciExtendedBridgeStatus temp;



        // PciExtendedBridgeStatus:
        // =======================================================================================================================================================================================================
        // |                                                                                       __reserved : 8 (10) ...                                                                                       |
        // |  ... __reserved : 2 (10)  |  splitRequestDelayed : 1  |  splitCompletionOverrun : 1  |  unexpectedSplitCompletion : 1  |  splitCompletionDiscarded : 1  |  support133MHz : 1  |  is64BitDevice : 1  |
        // |                                                                                            busNumber : 8                                                                                            |
        // |                                                    deviceNumber : 5                                                    |                             functionNumber : 3                             |
        // =======================================================================================================================================================================================================



        temp.value32 = 0xCB55A9DD;              // ||  11001011  ...  01  |  0  |  1  |  0  |  1  |  0  |  1  ||  10101001  ||  11011  |  101  ||

        TEST_ASSERT_EQUALS(temp.functionNumber,            5);
        TEST_ASSERT_EQUALS(temp.deviceNumber,              27);
        TEST_ASSERT_EQUALS(temp.busNumber,                 169);
        TEST_ASSERT_EQUALS(temp.is64BitDevice,             1);
        TEST_ASSERT_EQUALS(temp.support133MHz,             0);
        TEST_ASSERT_EQUALS(temp.splitCompletionDiscarded,  1);
        TEST_ASSERT_EQUALS(temp.unexpectedSplitCompletion, 0);
        TEST_ASSERT_EQUALS(temp.splitCompletionOverrun,    1);
        TEST_ASSERT_EQUALS(temp.splitRequestDelayed,       0);
        TEST_ASSERT_EQUALS(temp.__reserved,                813);



        temp.functionNumber = 1;                // ||  11001011  ...  01  |  0  |  1  |  0  |  1  |  0  |  1  ||  10101001  ||  11011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB55A9D9);



        temp.deviceNumber = 4;                  // ||  11001011  ...  01  |  0  |  1  |  0  |  1  |  0  |  1  ||  10101001  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB55A921);



        temp.busNumber = 5;                     // ||  11001011  ...  01  |  0  |  1  |  0  |  1  |  0  |  1  ||  00000101  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB550521);



        temp.is64BitDevice = 0;                 // ||  11001011  ...  01  |  0  |  1  |  0  |  1  |  0  |  0  ||  00000101  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB540521);



        temp.support133MHz = 1;                 // ||  11001011  ...  01  |  0  |  1  |  0  |  1  |  1  |  0  ||  00000101  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB560521);



        temp.splitCompletionDiscarded = 0;      // ||  11001011  ...  01  |  0  |  1  |  0  |  0  |  1  |  0  ||  00000101  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB520521);



        temp.unexpectedSplitCompletion = 1;     // ||  11001011  ...  01  |  0  |  1  |  1  |  0  |  1  |  0  ||  00000101  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB5A0521);



        temp.splitCompletionOverrun = 0;        // ||  11001011  ...  01  |  0  |  0  |  1  |  0  |  1  |  0  ||  00000101  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB4A0521);



        temp.splitRequestDelayed = 1;           // ||  11001011  ...  01  |  1  |  0  |  1  |  0  |  1  |  0  ||  00000101  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCB6A0521);



        temp.__reserved = 7;                    // ||  00000001  ...  11  |  1  |  0  |  1  |  0  |  1  |  0  ||  00000101  ||  00100  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x01EA0521);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedDeviceCommand");
    {
        PciExtendedDeviceCommand temp;



        // PciExtendedDeviceCommand:
        // ===============================================================================================================================================================================
        // |                                                                            __reserved : 8 (9) ...                                                                           |
        // |  ... __reserved : 1 (9)  |  maximumOutstandingSplitTransactions : 3  |  maximumMemoryReadByteCount : 2  |  enableRelaxedOrdering : 1  |  enableDataParityErrorRecovery : 1  |
        // ===============================================================================================================================================================================



        temp.value16 = 0xCBBA;                          // ||  11001011  ...  1  |  011  |  10  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.enableDataParityErrorRecovery,       0);
        TEST_ASSERT_EQUALS(temp.enableRelaxedOrdering,               1);
        TEST_ASSERT_EQUALS(temp.maximumMemoryReadByteCount,          2);
        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactions, 3);
        TEST_ASSERT_EQUALS(temp.__reserved,                          407);



        temp.enableDataParityErrorRecovery = 1;         // ||  11001011  ...  1  |  011  |  10  |  1  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCBBB);



        temp.enableRelaxedOrdering = 0;                 // ||  11001011  ...  1  |  011  |  10  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCBB9);



        temp.maximumMemoryReadByteCount = 3;            // ||  11001011  ...  1  |  011  |  11  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCBBD);



        temp.maximumOutstandingSplitTransactions = 5;   // ||  11001011  ...  1  |  101  |  11  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xCBDD);



        temp.__reserved = 9;                            // ||  00000100  ...  1  |  101  |  11  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x04DD);
    }
    TEST_CASE_END();



    TEST_CASE("PciExtendedDeviceStatus");
    {
        PciExtendedDeviceStatus temp;



        // PciExtendedDeviceStatus:
        // ======================================================================================================================================================================================================================================================================================
        // |                                 __reserved : 2                                 |  receivedSplitCompletionErrorMessage : 1  |                           designedMaximumCumulativeReadSize : 3                           |  designedMaximumOutstandingSplitTransactions : 2 (3) ...  |
        // |  ... designedMaximumOutstandingSplitTransactions : 1 (3)  |             designedMaximumMemoryReadByteCount : 2             |  deviceComplexity : 1  |  unexpectedSplitCompletion : 1  |  splitCompletionDiscarded : 1  |      support133MHz : 1      |      is64BitDevice : 1      |
        // |                                                                                                                                   busNumber : 8                                                                                                                                    |
        // |                                                                                   deviceNumber : 5                                                                                    |                                     functionNumber : 3                                     |
        // ======================================================================================================================================================================================================================================================================================



        temp.value32 = 0xCBEAAE9D;                              // ||  11  |  0  |  010  |  11  ...  1  |  11  |  0  |  1  |  0  |  1  |  0  ||  10101110  ||  10011  |  101  ||

        TEST_ASSERT_EQUALS(temp.functionNumber,                              5);
        TEST_ASSERT_EQUALS(temp.deviceNumber,                                19);
        TEST_ASSERT_EQUALS(temp.busNumber,                                   174);
        TEST_ASSERT_EQUALS(temp.is64BitDevice,                               0);
        TEST_ASSERT_EQUALS(temp.support133MHz,                               1);
        TEST_ASSERT_EQUALS(temp.splitCompletionDiscarded,                    0);
        TEST_ASSERT_EQUALS(temp.unexpectedSplitCompletion,                   1);
        TEST_ASSERT_EQUALS(temp.deviceComplexity,                            0);
        TEST_ASSERT_EQUALS(temp.designedMaximumMemoryReadByteCount,          3);
        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactions, 7);
        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSize,           2);
        TEST_ASSERT_EQUALS(temp.receivedSplitCompletionErrorMessage,         0);
        TEST_ASSERT_EQUALS(temp.__reserved,                                  3);



        temp.functionNumber = 1;                                // ||  11  |  0  |  010  |  11  ...  1  |  11  |  0  |  1  |  0  |  1  |  0  ||  10101110  ||  10011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBEAAE99);



        temp.deviceNumber = 3;                                  // ||  11  |  0  |  010  |  11  ...  1  |  11  |  0  |  1  |  0  |  1  |  0  ||  10101110  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBEAAE19);



        temp.busNumber = 9;                                     // ||  11  |  0  |  010  |  11  ...  1  |  11  |  0  |  1  |  0  |  1  |  0  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBEA0919);



        temp.is64BitDevice = 1;                                 // ||  11  |  0  |  010  |  11  ...  1  |  11  |  0  |  1  |  0  |  1  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBEB0919);



        temp.support133MHz = 0;                                 // ||  11  |  0  |  010  |  11  ...  1  |  11  |  0  |  1  |  0  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBE90919);



        temp.splitCompletionDiscarded = 1;                      // ||  11  |  0  |  010  |  11  ...  1  |  11  |  0  |  1  |  1  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBED0919);



        temp.unexpectedSplitCompletion = 0;                     // ||  11  |  0  |  010  |  11  ...  1  |  11  |  0  |  0  |  1  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBE50919);



        temp.deviceComplexity = 1;                              // ||  11  |  0  |  010  |  11  ...  1  |  11  |  1  |  0  |  1  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBF50919);



        temp.designedMaximumMemoryReadByteCount = 2;            // ||  11  |  0  |  010  |  11  ...  1  |  10  |  1  |  0  |  1  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCBD50919);



        temp.designedMaximumOutstandingSplitTransactions = 4;   // ||  11  |  0  |  010  |  10  ...  0  |  10  |  1  |  0  |  1  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xCA550919);



        temp.designedMaximumCumulativeReadSize = 5;             // ||  11  |  0  |  101  |  10  ...  0  |  10  |  1  |  0  |  1  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xD6550919);



        temp.receivedSplitCompletionErrorMessage = 1;           // ||  11  |  1  |  101  |  10  ...  0  |  10  |  1  |  0  |  1  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0xF6550919);



        temp.__reserved = 1;                                    // ||  01  |  1  |  101  |  10  ...  0  |  10  |  1  |  0  |  1  |  0  |  1  ||  00001001  ||  00011  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x76550919);
    }
    TEST_CASE_END();



    TEST_CASE("PciHeaderTypeUnion");
    {
        PciHeaderTypeUnion temp;



        // PciHeaderTypeUnion:
        // ============================================
        // |  isMultiFunction : 1  |  headerType : 7  |
        // ============================================



        temp.value8 = 0x85;         // ||  1  |  0000101  ||

        TEST_ASSERT_EQUALS(temp.type,            5);
        TEST_ASSERT_EQUALS(temp.isMultiFunction, 1);



        temp.type = 10;             // ||  1  |  0001010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x8A);



        temp.isMultiFunction = 0;   // ||  0  |  0001010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x0A);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportCommand");
    {
        PciHyperTransportCommand temp;



        // PciHyperTransportCommand:
        // ============================================
        // |  capabilityType : 3  |  __reserved : 13  |
        // ============================================



        temp.value16 = 0x3645;      // ||  001  |  10110  ...  01000101  ||

        TEST_ASSERT_EQUALS(temp.__reserved,     5701);
        TEST_ASSERT_EQUALS(temp.capabilityType, 1);



        temp.__reserved = 10;       // ||  001  |  00000  ...  00001010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x200A);



        temp.capabilityType = 5;    // ||  101  |  00000  ...  00001010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xA00A);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportHostSecondaryInterfaceCommand");
    {
        PciHyperTransportHostSecondaryInterfaceCommand temp;



        // PciHyperTransportHostSecondaryInterfaceCommand:
        // =============================================================================================================================================================================
        // |                    capabilityType : 3                    |  dropOnUninit : 1  |  hostInboundEndOfChainError : 1  |  actAsSlave : 1  |  __reserved : 1   |  hostHide : 1   |
        // |  chainSide : 1  |                                                 deviceNumber : 5                                                  |  doubleEnded : 1  |  warmReset : 1  |
        // =============================================================================================================================================================================



        temp.value16 = 0x3645;                  // ||  001  |  1  |  0  |  1  |  1  |  0  ||  0  |  10001  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.warmReset,                  1);
        TEST_ASSERT_EQUALS(temp.doubleEnded,                0);
        TEST_ASSERT_EQUALS(temp.deviceNumber,               17);
        TEST_ASSERT_EQUALS(temp.chainSide,                  0);
        TEST_ASSERT_EQUALS(temp.hostHide,                   0);
        TEST_ASSERT_EQUALS(temp.__reserved,                 1);
        TEST_ASSERT_EQUALS(temp.actAsSlave,                 1);
        TEST_ASSERT_EQUALS(temp.hostInboundEndOfChainError, 0);
        TEST_ASSERT_EQUALS(temp.dropOnUninit,               1);
        TEST_ASSERT_EQUALS(temp.capabilityType,             1);



        temp.warmReset = 0;                     // ||  001  |  1  |  0  |  1  |  1  |  0  ||  0  |  10001  |  0  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3644);



        temp.doubleEnded = 1;                   // ||  001  |  1  |  0  |  1  |  1  |  0  ||  0  |  10001  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3646);



        temp.deviceNumber = 4;                  // ||  001  |  1  |  0  |  1  |  1  |  0  ||  0  |  00100  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3612);



        temp.chainSide = 1;                     // ||  001  |  1  |  0  |  1  |  1  |  0  ||  1  |  00100  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3692);



        temp.hostHide = 1;                      // ||  001  |  1  |  0  |  1  |  1  |  1  ||  1  |  00100  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3792);



        temp.__reserved = 0;                    // ||  001  |  1  |  0  |  1  |  0  |  1  ||  1  |  00100  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3592);



        temp.actAsSlave = 0;                    // ||  001  |  1  |  0  |  0  |  0  |  1  ||  1  |  00100  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3192);



        temp.hostInboundEndOfChainError = 1;    // ||  001  |  1  |  1  |  0  |  0  |  1  ||  1  |  00100  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3992);



        temp.dropOnUninit = 0;                  // ||  001  |  0  |  1  |  0  |  0  |  1  ||  1  |  00100  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x2992);



        temp.capabilityType = 6;                // ||  110  |  0  |  1  |  0  |  0  |  1  ||  1  |  00100  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xC992);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportLinkConfig");
    {
        PciHyperTransportLinkConfig temp;



        // PciHyperTransportLinkConfig:
        // =====================================================================================================================================
        // |  enableDoublewordFlowControlOut : 1  |      linkWidthOut : 3     |  enableDoublewordFlowControlIn : 1  |      linkWidthIn : 3     |
        // |     doublewordFlowControlOut : 1     |  maximumLinkWidthOut : 3  |     doublewordFlowControlIn : 1     |  maximumLinkWidthIn : 3  |
        // =====================================================================================================================================



        temp.value16 = 0x5555;                      // ||  0  |  101  |  0  |  101  ||  0  |  101  |  0  |  101  ||

        TEST_ASSERT_EQUALS(temp.maximumLinkWidthIn,             5);
        TEST_ASSERT_EQUALS(temp.doublewordFlowControlIn,        0);
        TEST_ASSERT_EQUALS(temp.maximumLinkWidthOut,            5);
        TEST_ASSERT_EQUALS(temp.doublewordFlowControlOut,       0);
        TEST_ASSERT_EQUALS(temp.linkWidthIn,                    5);
        TEST_ASSERT_EQUALS(temp.enableDoublewordFlowControlIn,  0);
        TEST_ASSERT_EQUALS(temp.linkWidthOut,                   5);
        TEST_ASSERT_EQUALS(temp.enableDoublewordFlowControlOut, 0);



        temp.maximumLinkWidthIn = 3;                // ||  0  |  101  |  0  |  101  ||  0  |  101  |  0  |  011  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x5553);



        temp.doublewordFlowControlIn = 1;           // ||  0  |  101  |  0  |  101  ||  0  |  101  |  1  |  011  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x555B);



        temp.maximumLinkWidthOut = 3;               // ||  0  |  101  |  0  |  101  ||  0  |  011  |  0  |  011  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x553B);



        temp.doublewordFlowControlOut = 1;          // ||  0  |  101  |  0  |  101  ||  1  |  011  |  1  |  011  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x55BB);



        temp.linkWidthIn = 3;                       // ||  0  |  101  |  0  |  011  ||  0  |  011  |  0  |  011  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x53BB);



        temp.enableDoublewordFlowControlIn = 1;     // ||  0  |  101  |  1  |  011  ||  1  |  011  |  1  |  011  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x5BBB);



        temp.linkWidthOut = 3;                      // ||  0  |  011  |  0  |  011  ||  0  |  011  |  0  |  011  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3BBB);



        temp.enableDoublewordFlowControlOut = 1;    // ||  1  |  011  |  1  |  011  ||  1  |  011  |  1  |  011  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xBBBB);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportLinkControl");
    {
        PciHyperTransportLinkControl temp;



        // PciHyperTransportLinkControl:
        // ====================================================================================================================================================================================================================
        // |  enable64BitAddressing : 1  |  extendedCtlTime : 1  |  enableLdtStopTristate : 1   |  enableIsochronousFlowControl : 1  |                                      crcError : 4                                      |
        // |      transmitterOff : 1     |     endOfChain : 1    |  initializationComplete : 1  |          linkFailure : 1           |  crcForceError : 1  |  crcStartTest : 1  |  enableCrcFlood : 1  |  enableSourceId : 1  |
        // ====================================================================================================================================================================================================================



        temp.value16 = 0x5655;                  // ||  0  |  1  |  0  |  1  |  0110  ||  0  |  1  |  0  |  1  |  0  |  1  |  0  |  1  ||

        TEST_ASSERT_EQUALS(temp.enableSourceId,               1);
        TEST_ASSERT_EQUALS(temp.enableCrcFlood,               0);
        TEST_ASSERT_EQUALS(temp.crcStartTest,                 1);
        TEST_ASSERT_EQUALS(temp.crcForceError,                0);
        TEST_ASSERT_EQUALS(temp.linkFailure,                  1);
        TEST_ASSERT_EQUALS(temp.initializationComplete,       0);
        TEST_ASSERT_EQUALS(temp.endOfChain,                   1);
        TEST_ASSERT_EQUALS(temp.transmitterOff,               0);
        TEST_ASSERT_EQUALS(temp.crcError,                     6);
        TEST_ASSERT_EQUALS(temp.enableIsochronousFlowControl, 1);
        TEST_ASSERT_EQUALS(temp.enableLdtStopTristate,        0);
        TEST_ASSERT_EQUALS(temp.extendedCtlTime,              1);
        TEST_ASSERT_EQUALS(temp.enable64BitAddressing,        0);



        temp.enableSourceId = 0;                // ||  0  |  1  |  0  |  1  |  0110  ||  0  |  1  |  0  |  1  |  0  |  1  |  0  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x5654);



        temp.enableCrcFlood = 1;                // ||  0  |  1  |  0  |  1  |  0110  ||  0  |  1  |  0  |  1  |  0  |  1  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x5656);



        temp.crcStartTest = 0;                  // ||  0  |  1  |  0  |  1  |  0110  ||  0  |  1  |  0  |  1  |  0  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x5652);



        temp.crcForceError = 1;                 // ||  0  |  1  |  0  |  1  |  0110  ||  0  |  1  |  0  |  1  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x565A);



        temp.linkFailure = 0;                   // ||  0  |  1  |  0  |  1  |  0110  ||  0  |  1  |  0  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x564A);



        temp.initializationComplete = 1;        // ||  0  |  1  |  0  |  1  |  0110  ||  0  |  1  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x566A);



        temp.endOfChain = 0;                    // ||  0  |  1  |  0  |  1  |  0110  ||  0  |  0  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x562A);



        temp.transmitterOff = 1;                // ||  0  |  1  |  0  |  1  |  0110  ||  1  |  0  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x56AA);



        temp.crcError = 7;                      // ||  0  |  1  |  0  |  1  |  0111  ||  1  |  0  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x57AA);



        temp.enableIsochronousFlowControl = 0;  // ||  0  |  1  |  0  |  0  |  0111  ||  1  |  0  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x47AA);



        temp.enableLdtStopTristate = 1;         // ||  0  |  1  |  1  |  0  |  0111  ||  1  |  0  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x67AA);



        temp.extendedCtlTime = 0;               // ||  0  |  0  |  1  |  0  |  0111  ||  1  |  0  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x27AA);



        temp.enable64BitAddressing = 1;         // ||  1  |  0  |  1  |  0  |  0111  ||  1  |  0  |  1  |  0  |  1  |  0  |  1  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xA7AA);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportLinkErrorAndFrequencyUnion");
    {
        PciHyperTransportLinkErrorAndFrequencyUnion temp;



        // PciHyperTransportLinkErrorAndFrequencyUnion:
        // =================================
        // |  error : 4  |  frequency : 4  |
        // =================================



        temp.value8 = 0x53;     // ||  0101  |  0011  ||

        TEST_ASSERT_EQUALS(temp.frequency, 3);
        TEST_ASSERT_EQUALS(temp.error,     5);



        temp.frequency = 7;     // ||  0101  |  0111  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x57);



        temp.error = 4;         // ||  0100  |  0111  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x47);
    }
    TEST_CASE_END();



    TEST_CASE("PciHyperTransportSlavePrimaryInterfaceCommand");
    {
        PciHyperTransportSlavePrimaryInterfaceCommand temp;



        // PciHyperTransportSlavePrimaryInterfaceCommand:
        // ======================================================================================================================
        // |    capabilityType : 3   |  dropOnUninit : 1  |  defaultDirection : 1  |  masterHost : 1  |  unitCount : 2 (5) ...  |
        // |  ... unitCount : 3 (5)  |                                      baseUnitId : 5                                      |
        // ======================================================================================================================



        temp.value16 = 0x3645;          // ||  001  |  1  |  0  |  1  |  10  ...  010  |  00101  ||

        TEST_ASSERT_EQUALS(temp.baseUnitId,       5);
        TEST_ASSERT_EQUALS(temp.unitCount,        18);
        TEST_ASSERT_EQUALS(temp.masterHost,       1);
        TEST_ASSERT_EQUALS(temp.defaultDirection, 0);
        TEST_ASSERT_EQUALS(temp.dropOnUninit,     1);
        TEST_ASSERT_EQUALS(temp.capabilityType,   1);



        temp.baseUnitId = 10;           // ||  001  |  1  |  0  |  1  |  10  ...  010  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x364A);



        temp.unitCount = 3;             // ||  001  |  1  |  0  |  1  |  00  ...  011  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x346A);



        temp.masterHost = 0;            // ||  001  |  1  |  0  |  0  |  00  ...  011  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x306A);



        temp.defaultDirection = 1;      // ||  001  |  1  |  1  |  0  |  00  ...  011  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x386A);



        temp.dropOnUninit = 0;          // ||  001  |  0  |  1  |  0  |  00  ...  011  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x286A);



        temp.capabilityType = 5;        // ||  101  |  0  |  1  |  0  |  00  ...  011  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xA86A);
    }
    TEST_CASE_END();



    TEST_CASE("PciMessageSignaledInterruptsExtendedMessageControl");
    {
        PciMessageSignaledInterruptsExtendedMessageControl temp;



        // PciMessageSignaledInterruptsExtendedMessageControl:
        // ==========================================================
        // |  enableMSIX : 1  |  __reserved : 4  |  tableSize : 11  |
        // ==========================================================



        temp.value16 = 0xDA0A;      // ||  1  |  1011  |  01000001010  ||

        TEST_ASSERT_EQUALS(temp.tableSize,  522);
        TEST_ASSERT_EQUALS(temp.__reserved, 11);
        TEST_ASSERT_EQUALS(temp.enableMSIX, 1);



        temp.tableSize = 10;        // ||  1  |  1011  |  00000001010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xD80A);



        temp.__reserved = 3;        // ||  1  |  0011  |  00000001010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x980A);



        temp.enableMSIX = 0;        // ||  0  |  0011  |  00000001010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x180A);
    }
    TEST_CASE_END();



    TEST_CASE("PciMessageSignaledInterruptsExtendedTableOffsetBirUnion");
    {
        PciMessageSignaledInterruptsExtendedTableOffsetBirUnion temp;



        // PciMessageSignaledInterruptsExtendedTableOffsetBirUnion:
        // ===================================================
        // |  tableOffset : 29  |  baseAddressIndicator : 3  |
        // ===================================================



        temp.value32 = 0x9080000A;          // ||  1001000010000000001  |  010  ||

        TEST_ASSERT_EQUALS(temp.baseAddressIndicator, 2);
        TEST_ASSERT_EQUALS(temp.tableOffset,          303038465);



        temp.baseAddressIndicator = 1;      // ||  1001000010000000001  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x90800009);



        temp.tableOffset = 1;               // ||  0000000000000000001  |  001  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x00000009);
    }
    TEST_CASE_END();



    TEST_CASE("PciMessageSignaledInterruptsMessageAddress");
    {
        PciMessageSignaledInterruptsMessageAddress temp;



        // PciMessageSignaledInterruptsMessageAddress:
        // ===================================
        // |  value : 30  |  __reserved : 2  |
        // ===================================



        temp.value32 = 0x9080000A;  // ||  10010000100000000010  |  10  ||

        TEST_ASSERT_EQUALS(temp.__reserved, 2);
        TEST_ASSERT_EQUALS(temp.value,      606076930);



        temp.__reserved = 1;        // ||  10010000100000000010  |  01  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x90800009);



        temp.value = 1;             // ||  00000000000000000001  |  01  ||

        TEST_ASSERT_EQUALS(temp.value32, 0x00000005);
    }
    TEST_CASE_END();



    TEST_CASE("PciMessageSignaledInterruptsMessageControl");
    {
        PciMessageSignaledInterruptsMessageControl temp;



        // PciMessageSignaledInterruptsMessageControl:
        // ==========================================================================================================================
        // |                                     __reserved : 7                                     |  supportPerVectorMasking : 1  |
        // |  support64BitAddress : 1  |  enableMultipleMessage : 3  |  supportMultipleMessage : 3  |         enableMSI : 1         |
        // ==========================================================================================================================



        temp.value16 = 0xB2BB;              // ||  1011001  |  0  ||  1  |  011  |  101  |  1  ||

        TEST_ASSERT_EQUALS(temp.enableMSI,               1);
        TEST_ASSERT_EQUALS(temp.supportMultipleMessage,  5);
        TEST_ASSERT_EQUALS(temp.enableMultipleMessage,   3);
        TEST_ASSERT_EQUALS(temp.support64BitAddress,     1);
        TEST_ASSERT_EQUALS(temp.supportPerVectorMasking, 0);
        TEST_ASSERT_EQUALS(temp.__reserved,              89);



        temp.enableMSI = 0;                 // ||  1011001  |  0  ||  1  |  011  |  101  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xB2BA);



        temp.supportMultipleMessage = 2;    // ||  1011001  |  0  ||  1  |  011  |  010  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xB2B4);



        temp.enableMultipleMessage = 5;     // ||  1011001  |  0  ||  1  |  101  |  010  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xB2D4);



        temp.support64BitAddress = 0;       // ||  1011001  |  0  ||  0  |  101  |  010  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xB254);



        temp.supportPerVectorMasking = 1;   // ||  1011001  |  1  ||  0  |  101  |  010  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xB354);



        temp.__reserved = 2;                // ||  0000010  |  1  ||  0  |  101  |  010  |  0  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x0554);
    }
    TEST_CASE_END();



    TEST_CASE("PciPowerManagementBridgeSupportExtensions");
    {
        PciPowerManagementBridgeSupportExtensions temp;



        // PciPowerManagementBridgeSupportExtensions:
        // ======================================================================
        // |  busPowerClockControl : 1  |  b2B3ForD3Hot : 1  |  __reserved : 6  |
        // ======================================================================



        temp.value8 = 0x9D;             // ||  1  |  0  |  011101  ||

        TEST_ASSERT_EQUALS(temp.__reserved,           29);
        TEST_ASSERT_EQUALS(temp.b2B3ForD3Hot,         0);
        TEST_ASSERT_EQUALS(temp.busPowerClockControl, 1);



        temp.__reserved = 10;           // ||  1  |  0  |  001010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x8A);



        temp.b2B3ForD3Hot = 1;          // ||  1  |  1  |  001010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0xCA);



        temp.busPowerClockControl = 0;  // ||  0  |  1  |  001010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x4A);
    }
    TEST_CASE_END();



    TEST_CASE("PciPowerManagementCapabilities");
    {
        PciPowerManagementCapabilities temp;



        // PciPowerManagementCapabilities:
        // ====================================================================================================================================================================
        // |                                           supportPme : 5                                          |  supportD2 : 1  |  supportD1 : 1  |  auxCurrent : 1 (3) ...  |
        // |  ... auxCurrent : 2 (3)  |  deviceSpecificInitialization : 1  |  __reserved : 1  |  pmeClock : 1  |                          version : 3                         |
        // ====================================================================================================================================================================



        temp.value16 = 0x9AD5;                      // ||  10011  |  0  |  1  |  0  ... 11  |  0  |  1  |  0  |  101  ||

        TEST_ASSERT_EQUALS(temp.version,                      5);
        TEST_ASSERT_EQUALS(temp.pmeClock,                     0);
        TEST_ASSERT_EQUALS(temp.__reserved,                   1);
        TEST_ASSERT_EQUALS(temp.deviceSpecificInitialization, 0);
        TEST_ASSERT_EQUALS(temp.auxCurrent,                   3);
        TEST_ASSERT_EQUALS(temp.supportD1,                    1);
        TEST_ASSERT_EQUALS(temp.supportD2,                    0);
        TEST_ASSERT_EQUALS(temp.supportPme,                   19);



        temp.version = 2;                           // ||  10011  |  0  |  1  |  0  ... 11  |  0  |  1  |  0  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x9AD2);



        temp.pmeClock = 1;                          // ||  10011  |  0  |  1  |  0  ... 11  |  0  |  1  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x9ADA);



        temp.__reserved = 0;                        // ||  10011  |  0  |  1  |  0  ... 11  |  0  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x9ACA);



        temp.deviceSpecificInitialization = 1;      // ||  10011  |  0  |  1  |  0  ... 11  |  1  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x9AEA);



        temp.auxCurrent = 5;                        // ||  10011  |  0  |  1  |  1  ... 01  |  1  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x9B6A);



        temp.supportD1 = 0;                         // ||  10011  |  0  |  0  |  1  ... 01  |  1  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x996A);



        temp.supportD2 = 1;                         // ||  10011  |  1  |  0  |  1  ... 01  |  1  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x9D6A);



        temp.supportPme = 3;                         // ||  00011  |  1  |  0  |  1  ... 01  |  1  |  0  |  1  |  010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x1D6A);
    }
    TEST_CASE_END();



    TEST_CASE("PciPowerManagementControlStatus");
    {
        PciPowerManagementControlStatus temp;



        // PciPowerManagementControlStatus:
        // ==========================================================================================================================================
        // |  pmeStatus : 1  |  dataScale : 2  |                                  dataSelect : 4                                  |  enablePme : 1  |
        // |                  __reserved: 4                  |  noSoftReset : 1  |  __reservedForPciExpress : 1  |          powerState : 2          |
        // ==========================================================================================================================================



        temp.value16 = 0xD36A;              // ||  1  |  10  |  1001  |  1  ||  0110  |  1  |  0  |  10  ||

        TEST_ASSERT_EQUALS(temp.powerState,              2);
        TEST_ASSERT_EQUALS(temp.__reservedForPciExpress, 0);
        TEST_ASSERT_EQUALS(temp.noSoftReset,             1);
        TEST_ASSERT_EQUALS(temp.__reserved,              6);
        TEST_ASSERT_EQUALS(temp.enablePme,               1);
        TEST_ASSERT_EQUALS(temp.dataSelect,              9);
        TEST_ASSERT_EQUALS(temp.dataScale,               2);
        TEST_ASSERT_EQUALS(temp.pmeStatus,               1);



        temp.powerState = 3;                // ||  1  |  10  |  1001  |  1  ||  0110  |  1  |  0  |  11  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xD36B);



        temp.__reservedForPciExpress = 1;   // ||  1  |  10  |  1001  |  1  ||  0110  |  1  |  1  |  11  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xD36F);



        temp.noSoftReset = 0;               // ||  1  |  10  |  1001  |  1  ||  0110  |  0  |  1  |  11  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xD367);



        temp.__reserved = 9;                // ||  1  |  10  |  1001  |  1  ||  1001  |  0  |  1  |  11  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xD397);



        temp.enablePme = 0;                 // ||  1  |  10  |  1001  |  0  ||  1001  |  0  |  1  |  11  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xD297);



        temp.dataSelect = 13;               // ||  1  |  10  |  1101  |  0  ||  1001  |  0  |  1  |  11  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xDA97);



        temp.dataScale = 1;                 // ||  1  |  01  |  1101  |  0  ||  1001  |  0  |  1  |  11  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xBA97);



        temp.pmeStatus = 0;                 // ||  0  |  01  |  1101  |  0  ||  1001  |  0  |  1  |  11  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x3A97);
    }
    TEST_CASE_END();



    TEST_CASE("PciSlotNumberingExpansionSlot");
    {
        PciSlotNumberingExpansionSlot temp;



        // PciSlotNumberingExpansionSlot:
        // ==========================================================================
        // |  __reserved : 2  |  firstInChassis : 1  |  expansionSlotsProvided : 5  |
        // ==========================================================================



        temp.value8 = 0xB4;                 // ||  10  |  1  |  10100  ||

        TEST_ASSERT_EQUALS(temp.expansionSlotsProvided, 20);
        TEST_ASSERT_EQUALS(temp.firstInChassis,         1);
        TEST_ASSERT_EQUALS(temp.__reserved,             2);



        temp.expansionSlotsProvided = 10;   // ||  10  |  1  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0xAA);



        temp.firstInChassis = 0;            // ||  10  |  0  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0x8A);



        temp.__reserved = 3;                // ||  11  |  0  |  01010  ||

        TEST_ASSERT_EQUALS(temp.value8, 0xCA);
    }
    TEST_CASE_END();



    TEST_CASE("PciStatus");
    {
        PciStatus temp;



        // PciStatus:
        // =====================================================================================================================
        // |     interruptStatus : 1     |                                   __reserved : 3                                    |
        // |  fastBackToBackCapable : 1  |      __reserved2 : 1      |     support64MHz : 1      |    capabilitiesList : 1     |
        // |   signaledTargetAbort : 1   |                 deviceSelectTiming : 2                |  masterDataParityError : 1  |
        // |   detectedParityError : 1   |  signaledSystemError : 1  |  receivedMasterAbort : 1  |   receivedTargetAbort : 1   |
        // =====================================================================================================================



        temp.value16 = 0xAAAB;                  // ||  1  |  0  |  1  |  0  |  1  |  01  |  0  ||  1  |  0  |  1  |  0  |  1  |  011  ||

        TEST_ASSERT_EQUALS(temp.__reserved,            3);
        TEST_ASSERT_EQUALS(temp.interruptStatus,       1);
        TEST_ASSERT_EQUALS(temp.capabilitiesList,      0);
        TEST_ASSERT_EQUALS(temp.support64MHz,          1);
        TEST_ASSERT_EQUALS(temp.__reserved2,           0);
        TEST_ASSERT_EQUALS(temp.fastBackToBackCapable, 1);
        TEST_ASSERT_EQUALS(temp.masterDataParityError, 0);
        TEST_ASSERT_EQUALS(temp.deviceSelectTiming,    1);
        TEST_ASSERT_EQUALS(temp.signaledTargetAbort,   1);
        TEST_ASSERT_EQUALS(temp.receivedTargetAbort,   0);
        TEST_ASSERT_EQUALS(temp.receivedMasterAbort,   1);
        TEST_ASSERT_EQUALS(temp.signaledSystemError,   0);
        TEST_ASSERT_EQUALS(temp.detectedParityError,   1);



        temp.__reserved = 1;                    // ||  1  |  0  |  1  |  0  |  1  |  01  |  0  ||  1  |  0  |  1  |  0  |  1  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAAA9);



        temp.interruptStatus = 0;               // ||  1  |  0  |  1  |  0  |  1  |  01  |  0  ||  1  |  0  |  1  |  0  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAAA1);



        temp.capabilitiesList = 1;              // ||  1  |  0  |  1  |  0  |  1  |  01  |  0  ||  1  |  0  |  1  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAAB1);



        temp.support64MHz = 0;                  // ||  1  |  0  |  1  |  0  |  1  |  01  |  0  ||  1  |  0  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAA91);



        temp.__reserved2 = 1;                   // ||  1  |  0  |  1  |  0  |  1  |  01  |  0  ||  1  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAAD1);



        temp.fastBackToBackCapable = 0;         // ||  1  |  0  |  1  |  0  |  1  |  01  |  0  ||  0  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAA51);



        temp.masterDataParityError = 1;         // ||  1  |  0  |  1  |  0  |  1  |  01  |  1  ||  0  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAB51);



        temp.deviceSelectTiming = 3;            // ||  1  |  0  |  1  |  0  |  1  |  11  |  1  ||  0  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xAF51);



        temp.signaledTargetAbort = 0;           // ||  1  |  0  |  1  |  0  |  0  |  11  |  1  ||  0  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xA751);



        temp.receivedTargetAbort = 1;           // ||  1  |  0  |  1  |  1  |  0  |  11  |  1  ||  0  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xB751);



        temp.receivedMasterAbort = 0;           // ||  1  |  0  |  0  |  1  |  0  |  11  |  1  ||  0  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x9751);



        temp.signaledSystemError = 1;           // ||  1  |  1  |  0  |  1  |  0  |  11  |  1  ||  0  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0xD751);



        temp.detectedParityError = 0;           // ||  0  |  1  |  0  |  1  |  0  |  11  |  1  ||  0  |  1  |  0  |  1  |  0  |  001  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x5751);
    }
    TEST_CASE_END();



    TEST_CASE("PciVitalProductDataAddressUnion");
    {
        PciVitalProductDataAddressUnion temp;



        // PciVitalProductDataAddressUnion:
        // =================================
        // |  finished : 1  |  value : 15  |
        // =================================



        temp.value16 = 0xBA57;  // ||  1  |  011101001010111  ||

        TEST_ASSERT_EQUALS(temp.value,    14935);
        TEST_ASSERT_EQUALS(temp.finished, 1);



        temp.value = 10;        // ||  1  |  000000000001010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x800A);



        temp.finished = 0;      // ||  0  |  000000000001010  ||

        TEST_ASSERT_EQUALS(temp.value16, 0x000A);
    }
    TEST_CASE_END();



    TEST_CASE("ZLibHeader");
    {
        ZLibHeader temp;



        // ZLibHeader:
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



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TYPES_H
