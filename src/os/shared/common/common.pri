SOURCES += \
    $$PWD/asm/arch/x86_64/com/ngos/shared/common/memory/memcpy.S \
    $$PWD/asm/arch/x86_64/com/ngos/shared/common/memory/memset.S \
    $$PWD/asm/arch/x86_64/com/ngos/shared/common/memory/memzero.S \
    $$PWD/src/com/ngos/shared/common/assets/assets.cpp \
    $$PWD/src/com/ngos/shared/common/checksum/adler.cpp \
    $$PWD/src/com/ngos/shared/common/checksum/crc.cpp \
    $$PWD/src/com/ngos/shared/common/checksum/md5.cpp \
    $$PWD/src/com/ngos/shared/common/compilation/fixforglobaldestructors.cpp \
    $$PWD/src/com/ngos/shared/common/compilation/fixforvtable.cpp \
    $$PWD/src/com/ngos/shared/common/console/console.cpp \
    $$PWD/src/com/ngos/shared/common/console/graphicalconsole.cpp \
    $$PWD/src/com/ngos/shared/common/cpu/cpu.cpp \
    $$PWD/src/com/ngos/shared/common/cpu/generated/x86bugsnames.cpp \
    $$PWD/src/com/ngos/shared/common/cpu/generated/x86featuresnames.cpp \
    $$PWD/src/com/ngos/shared/common/cpu/msr/msr.cpp \
    $$PWD/src/com/ngos/shared/common/cryptography/aes.cpp \
    $$PWD/src/com/ngos/shared/common/dmi/dmi.cpp \
    $$PWD/src/com/ngos/shared/common/fpu/fpu.cpp \
    $$PWD/src/com/ngos/shared/common/graphics/bmp/bmp.cpp \
    $$PWD/src/com/ngos/shared/common/graphics/graphics.cpp \
    $$PWD/src/com/ngos/shared/common/graphics/image.cpp \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/jpeg.cpp \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegzigzagorder.cpp \
    $$PWD/src/com/ngos/shared/common/graphics/ninepatch.cpp \
    $$PWD/src/com/ngos/shared/common/graphics/png/png.cpp \
    $$PWD/src/com/ngos/shared/common/graphics/stretchrange.cpp \
    $$PWD/src/com/ngos/shared/common/gui/gui.cpp \
    $$PWD/src/com/ngos/shared/common/gui/other/presseventhandler.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/button.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/tabbutton.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/tablewidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/tabwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/toolbutton.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/treewidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/consolewidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/cursorwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/imagewidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/labelwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/panelwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/progressbarwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/tablecellwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/tableheaderwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/tablerowwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/tabpagewidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/treenodewidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/wrapperwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/special/rootwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/special/screenwidget.cpp \
    $$PWD/src/com/ngos/shared/common/gui/widgets/widget.cpp \
    $$PWD/src/com/ngos/shared/common/hex/generated/hexchars.cpp \
    $$PWD/src/com/ngos/shared/common/hex/hex.cpp \
    $$PWD/src/com/ngos/shared/common/inflate/inflate.cpp \
    $$PWD/src/com/ngos/shared/common/memory/malloc.cpp \
    $$PWD/src/com/ngos/shared/common/memory/memory.cpp \
    $$PWD/src/com/ngos/shared/common/printf/printf.cpp \
    $$PWD/src/com/ngos/shared/common/random/random.cpp \
    $$PWD/src/com/ngos/shared/common/serial/serial.cpp \
    $$PWD/src/com/ngos/shared/common/string/generated/bytesdecimals.cpp \
    $$PWD/src/com/ngos/shared/common/string/generated/numberdecimals.cpp \
    $$PWD/src/com/ngos/shared/common/string/string.cpp \
    $$PWD/src/com/ngos/shared/common/time/time.cpp \
    $$PWD/src/com/ngos/shared/common/zlib/zlib.cpp

HEADERS += \
    $$PWD/src/com/ngos/shared/common/asm/bitutils.h \
    $$PWD/src/com/ngos/shared/common/asm/instructions.h \
    $$PWD/src/com/ngos/shared/common/assets/assetentry.h \
    $$PWD/src/com/ngos/shared/common/assets/assets.h \
    $$PWD/src/com/ngos/shared/common/bootparams/bootparams.h \
    $$PWD/src/com/ngos/shared/common/bootparams/bootparamsheader.h \
    $$PWD/src/com/ngos/shared/common/bootparams/memorymapentry.h \
    $$PWD/src/com/ngos/shared/common/bootparams/memorymapentrytype.h \
    $$PWD/src/com/ngos/shared/common/bootparams/pciromimagewithinfo.h \
    $$PWD/src/com/ngos/shared/common/bootparams/uefiinfo.h \
    $$PWD/src/com/ngos/shared/common/bootparams/uefimemorymapinfo.h \
    $$PWD/src/com/ngos/shared/common/checksum/adler.h \
    $$PWD/src/com/ngos/shared/common/checksum/crc.h \
    $$PWD/src/com/ngos/shared/common/checksum/lib/md5hash.h \
    $$PWD/src/com/ngos/shared/common/checksum/md5.h \
    $$PWD/src/com/ngos/shared/common/console/console.h \
    $$PWD/src/com/ngos/shared/common/console/graphicalconsole.h \
    $$PWD/src/com/ngos/shared/common/console/lib/glyphdata.h \
    $$PWD/src/com/ngos/shared/common/containers/arraylist.h \
    $$PWD/src/com/ngos/shared/common/containers/lib/listelement.h \
    $$PWD/src/com/ngos/shared/common/containers/lib/mapelement.h \
    $$PWD/src/com/ngos/shared/common/containers/list.h \
    $$PWD/src/com/ngos/shared/common/containers/map.h \
    $$PWD/src/com/ngos/shared/common/cpu/cpu.h \
    $$PWD/src/com/ngos/shared/common/cpu/cpufamily.h \
    $$PWD/src/com/ngos/shared/common/cpu/cpuvendor.h \
    $$PWD/src/com/ngos/shared/common/cpu/flags.h \
    $$PWD/src/com/ngos/shared/common/cpu/generated/x86bugsnames.h \
    $$PWD/src/com/ngos/shared/common/cpu/generated/x86featuresnames.h \
    $$PWD/src/com/ngos/shared/common/cpu/model/amdcpumodel.h \
    $$PWD/src/com/ngos/shared/common/cpu/model/cpumodel.h \
    $$PWD/src/com/ngos/shared/common/cpu/model/intelcpumodel.h \
    $$PWD/src/com/ngos/shared/common/cpu/msr/msr.h \
    $$PWD/src/com/ngos/shared/common/cpu/msr/msrregisters.h \
    $$PWD/src/com/ngos/shared/common/cpu/x86bug.h \
    $$PWD/src/com/ngos/shared/common/cpu/x86bugword.h \
    $$PWD/src/com/ngos/shared/common/cpu/x86feature.h \
    $$PWD/src/com/ngos/shared/common/cpu/x86featureword.h \
    $$PWD/src/com/ngos/shared/common/cryptography/aes.h \
    $$PWD/src/com/ngos/shared/common/dmi/dmi.h \
    $$PWD/src/com/ngos/shared/common/dmi/dmientryheader.h \
    $$PWD/src/com/ngos/shared/common/dmi/dmientrytype.h \
    $$PWD/src/com/ngos/shared/common/dmi/dmiidentity.h \
    $$PWD/src/com/ngos/shared/common/dmi/dmimemorydevice.h \
    $$PWD/src/com/ngos/shared/common/dmi/dmistoreduuid.h \
    $$PWD/src/com/ngos/shared/common/dmi/dmistringid.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmiadditionalinformationentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmibaseboardentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmibiosentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmibioslanguageentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmibits32memoryerrorinformationentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmibits64memoryerrorinformationentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmicacheentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmichassisentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmicoolingdeviceentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmielectricalcurrentprobeentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmigroupassociationsentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmihardwaresecurityentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmiinactiveentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmimanagementdevicecomponententry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmimanagementdeviceentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmimanagementdevicethresholddataentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmimemoryarraymappedaddressentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmimemorydeviceentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmimemorydevicemappedaddressentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmioemstringsentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmionboarddevicesentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmionboarddevicesextendedentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmioutofbandremoteaccessentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmiphysicalmemoryarrayentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmiportablebatteryentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmiportconnectorentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmiprocessorentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmisystembootentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmisystemconfigurationentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmisystementry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmisystempowersupplyentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmisystemresetentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmisystemslotsentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmitemperatureprobeentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/dmivoltageprobeentry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiadditionalinformation.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibaseboardfeatureflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibaseboardtype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicsbiosreservedflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicsflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicssystemreservedflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibiosextendedromsize.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibiosextendedromsizeunit.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibioslanguageflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibiosromsize.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibits32memoryerrorinformationerrorgranularity.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibits32memoryerrorinformationerroroperation.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibits32memoryerrorinformationerrortype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibits64memoryerrorinformationerrorgranularity.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibits64memoryerrorinformationerroroperation.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmibits64memoryerrorinformationerrortype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicacheassociativity.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicacheconfiguration.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicacheerrorcorrectiontype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicachelocation.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicacheoperationalmode.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicachesize.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicachesize2.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicachesizegranularity.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicachesramtypeflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicachetype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelement.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelementtype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelementtypeselect.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmichassissecuritystatus.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmichassisstate.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmichassistype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicoolingdevicestatus.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmicoolingdevicetype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmielectricalcurrentprobelocation.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmielectricalcurrentprobestatus.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmigroupassociationsitem.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmihardwaresecuritysettings.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmihardwaresecuritystatus.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimanagementdeviceaddresstype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimanagementdevicetype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemoryarraymappedaddressrange.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceattributes.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceextendedsize.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceformfactor.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicemappedaddressrange.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceoperatingmodecapabilityflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicesize.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicesizegranularity.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetechnology.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetypedetailflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevice.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevicetype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesextendeddevicetype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmioutofbandremoteaccessconnectionflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarrayerrorcorrection.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarraylocation.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarraymaximumcapacity.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarrayuse.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiportablebatterydevicechemistry.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiportablebatterymanufacturedate.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiportconnectorporttype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiportconnectortype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorcharacteristicsflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorfamily.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorfamily2.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorfeatureflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorid.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorsignature.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorstatus.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessortype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorupgrade.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorvoltage.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorvoltageflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorvoltagemodetype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystembootstatus.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplycharacteristics.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplyinputvoltagerangeswitch.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplystatus.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplytype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemresetbootoption.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemresetcapabilities.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemslotscharacteristicsflags.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemslotsdatabuswidth.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemslotslength.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemslotspeergroup.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemslotstype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemslotsusage.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmisystemwakeuptype.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmitemperatureprobelocation.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmitemperatureprobestatus.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmivoltageprobelocation.h \
    $$PWD/src/com/ngos/shared/common/dmi/entry/lib/dmivoltageprobestatus.h \
    $$PWD/src/com/ngos/shared/common/early/earlyassert.h \
    $$PWD/src/com/ngos/shared/common/early/earlylog.h \
    $$PWD/src/com/ngos/shared/common/elf/class.h \
    $$PWD/src/com/ngos/shared/common/elf/data.h \
    $$PWD/src/com/ngos/shared/common/elf/fileversion.h \
    $$PWD/src/com/ngos/shared/common/elf/header.h \
    $$PWD/src/com/ngos/shared/common/elf/headeridentification.h \
    $$PWD/src/com/ngos/shared/common/elf/machine.h \
    $$PWD/src/com/ngos/shared/common/elf/osabi.h \
    $$PWD/src/com/ngos/shared/common/elf/programflags.h \
    $$PWD/src/com/ngos/shared/common/elf/programheadertableentry.h \
    $$PWD/src/com/ngos/shared/common/elf/programtype.h \
    $$PWD/src/com/ngos/shared/common/elf/rela.h \
    $$PWD/src/com/ngos/shared/common/elf/relatype.h \
    $$PWD/src/com/ngos/shared/common/elf/sectionflags.h \
    $$PWD/src/com/ngos/shared/common/elf/sectionheadertableentry.h \
    $$PWD/src/com/ngos/shared/common/elf/sectiontype.h \
    $$PWD/src/com/ngos/shared/common/elf/symbol.h \
    $$PWD/src/com/ngos/shared/common/elf/symbolbind.h \
    $$PWD/src/com/ngos/shared/common/elf/symboltype.h \
    $$PWD/src/com/ngos/shared/common/elf/symbolvisibility.h \
    $$PWD/src/com/ngos/shared/common/elf/type.h \
    $$PWD/src/com/ngos/shared/common/elf/version.h \
    $$PWD/src/com/ngos/shared/common/fpu/fpu.h \
    $$PWD/src/com/ngos/shared/common/fpu/fpustate.h \
    $$PWD/src/com/ngos/shared/common/fpu/fsavestate.h \
    $$PWD/src/com/ngos/shared/common/fpu/fxsavestate.h \
    $$PWD/src/com/ngos/shared/common/fpu/macros.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature/extendedregisters.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature/xfeatureavx512opmaskstate.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature/xfeatureavx512zmmfrom0to15state.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature/xfeatureavx512zmmfrom16to31state.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature/xfeatureavxstate.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature/xfeaturempxboundconfigandstatusregistersstate.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature/xfeaturempxboundregistersstate.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeature/xfeaturepkrustate.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeatureflags.h \
    $$PWD/src/com/ngos/shared/common/fpu/xfeaturetypeflags.h \
    $$PWD/src/com/ngos/shared/common/fpu/xsavestate.h \
    $$PWD/src/com/ngos/shared/common/fpu/xstateheader.h \
    $$PWD/src/com/ngos/shared/common/gdt/flags.h \
    $$PWD/src/com/ngos/shared/common/gdt/gdtdescriptor.h \
    $$PWD/src/com/ngos/shared/common/gdt/gdtregister.h \
    $$PWD/src/com/ngos/shared/common/gdt/segments.h \
    $$PWD/src/com/ngos/shared/common/gpt/gptdata.h \
    $$PWD/src/com/ngos/shared/common/gpt/gptentry.h \
    $$PWD/src/com/ngos/shared/common/gpt/gptheader.h \
    $$PWD/src/com/ngos/shared/common/gpt/utils.h \
    $$PWD/src/com/ngos/shared/common/graphics/bmp/bmp.h \
    $$PWD/src/com/ngos/shared/common/graphics/bmp/lib/bmpcolormap.h \
    $$PWD/src/com/ngos/shared/common/graphics/bmp/lib/bmpcompressionmethod.h \
    $$PWD/src/com/ngos/shared/common/graphics/bmp/lib/bmpheader.h \
    $$PWD/src/com/ngos/shared/common/graphics/bmp/lib/bmpinformationheader.h \
    $$PWD/src/com/ngos/shared/common/graphics/graphics.h \
    $$PWD/src/com/ngos/shared/common/graphics/image.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/jpeg.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/jpegcomponent.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/jpegdecoder.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/jpegvlccode.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegcomponentid.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegdefinehuffmantablemarker.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegdefinequantizationtablemarker.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegdefinerestartintervalmarker.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantable.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantabletype.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegmarkertype.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegquantizationtable.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegstartofframecomponent.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegstartofframemarker.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscancomponent.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscanmarker.h \
    $$PWD/src/com/ngos/shared/common/graphics/jpeg/lib/jpegzigzagorder.h \
    $$PWD/src/com/ngos/shared/common/graphics/ninepatch.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/chunks/pngembeddediccprofile.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/chunks/pngimagegamma.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/chunks/pngimageheader.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/chunks/pngimagelastmodificationtime.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/chunks/pngphysicalpixeldimensions.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/chunks/pngprimarychromaticities.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/chunks/pngsignificantbits.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/chunks/pngstandardrgbcolorspace.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngchunk.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngchunktype.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngcolortype.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngcompressionmethod.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngfiltermethod.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngfiltertype.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngheader.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pnginterlacemethod.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngrenderingintent.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/lib/pngunitspecifier.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/png.h \
    $$PWD/src/com/ngos/shared/common/graphics/png/pngdecoder.h \
    $$PWD/src/com/ngos/shared/common/graphics/rgbapixel.h \
    $$PWD/src/com/ngos/shared/common/graphics/rgbpixel.h \
    $$PWD/src/com/ngos/shared/common/graphics/stretchrange.h \
    $$PWD/src/com/ngos/shared/common/gui/gui.h \
    $$PWD/src/com/ngos/shared/common/gui/other/defines.h \
    $$PWD/src/com/ngos/shared/common/gui/other/horizontalalignment.h \
    $$PWD/src/com/ngos/shared/common/gui/other/presseventhandler.h \
    $$PWD/src/com/ngos/shared/common/gui/other/verticalalignment.h \
    $$PWD/src/com/ngos/shared/common/gui/other/widgetstate.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/button.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/tabbutton.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/tablewidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/tabwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/toolbutton.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/controls/treewidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/consolewidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/cursorwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/imagewidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/labelwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/panelwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/progressbarwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/tablecellwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/tableheaderwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/tablerowwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/tabpagewidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/treenodewidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/misc/wrapperwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/special/rootwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/special/screenwidget.h \
    $$PWD/src/com/ngos/shared/common/gui/widgets/widget.h \
    $$PWD/src/com/ngos/shared/common/guid/guid.h \
    $$PWD/src/com/ngos/shared/common/guid/utils.h \
    $$PWD/src/com/ngos/shared/common/hex/hex.h \
    $$PWD/src/com/ngos/shared/common/idt/flags.h \
    $$PWD/src/com/ngos/shared/common/idt/idtdescriptor.h \
    $$PWD/src/com/ngos/shared/common/idt/idtgatetype.h \
    $$PWD/src/com/ngos/shared/common/idt/idtregister.h \
    $$PWD/src/com/ngos/shared/common/idt/macros.h \
    $$PWD/src/com/ngos/shared/common/inflate/inflate.h \
    $$PWD/src/com/ngos/shared/common/inflate/inflateblocktype.h \
    $$PWD/src/com/ngos/shared/common/inflate/inflatecode.h \
    $$PWD/src/com/ngos/shared/common/inflate/inflatecodetype.h \
    $$PWD/src/com/ngos/shared/common/inflate/inflatedecoder.h \
    $$PWD/src/com/ngos/shared/common/inflate/inflatefixedcodes.h \
    $$PWD/src/com/ngos/shared/common/log/assert.h \
    $$PWD/src/com/ngos/shared/common/log/log.h \
    $$PWD/src/com/ngos/shared/common/macro/constants.h \
    $$PWD/src/com/ngos/shared/common/macro/utils.h \
    $$PWD/src/com/ngos/shared/common/mbr/mbr.h \
    $$PWD/src/com/ngos/shared/common/mbr/mbrpartition.h \
    $$PWD/src/com/ngos/shared/common/mbr/mbrpartitiontype.h \
    $$PWD/src/com/ngos/shared/common/memory/asm_memcpy.h \
    $$PWD/src/com/ngos/shared/common/memory/asm_memset.h \
    $$PWD/src/com/ngos/shared/common/memory/asm_memzero.h \
    $$PWD/src/com/ngos/shared/common/memory/malloc.h \
    $$PWD/src/com/ngos/shared/common/memory/memory.h \
    $$PWD/src/com/ngos/shared/common/ngos/flags.h \
    $$PWD/src/com/ngos/shared/common/ngos/linkage.h \
    $$PWD/src/com/ngos/shared/common/ngos/status.h \
    $$PWD/src/com/ngos/shared/common/ngos/types.h \
    $$PWD/src/com/ngos/shared/common/ngos/utils.h \
    $$PWD/src/com/ngos/shared/common/page/macros.h \
    $$PWD/src/com/ngos/shared/common/pagetable/flags.h \
    $$PWD/src/com/ngos/shared/common/pagetable/macros.h \
    $$PWD/src/com/ngos/shared/common/pagetable/types.h \
    $$PWD/src/com/ngos/shared/common/pagetable/utils.h \
    $$PWD/src/com/ngos/shared/common/pci/macros.h \
    $$PWD/src/com/ngos/shared/common/pci/pciregisters.h \
    $$PWD/src/com/ngos/shared/common/printf/printf.h \
    $$PWD/src/com/ngos/shared/common/random/random.h \
    $$PWD/src/com/ngos/shared/common/serial/serial.h \
    $$PWD/src/com/ngos/shared/common/string/generated/bytesdecimals.h \
    $$PWD/src/com/ngos/shared/common/string/generated/numberdecimals.h \
    $$PWD/src/com/ngos/shared/common/string/string.h \
    $$PWD/src/com/ngos/shared/common/string/utils.h \
    $$PWD/src/com/ngos/shared/common/time/time.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefiacpi20configurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefiacpiconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefidebuginfoconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefidxeservicesconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefihcdpconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefihoblistconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefilzmadecompressconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefimemoryattributesconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefimemorystatuscoderecordconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefimemorytypeinformationconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefimpsconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefipropertiesconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefisalsystemconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefismbios3configurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefismbiosconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefisystemresourceconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/config/uefiugaioconfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/macros.h \
    $$PWD/src/com/ngos/shared/common/uefi/types.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiabsolutepointermode.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiabsolutepointermodeattributeflags.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiabsolutepointerprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiabsolutepointerstate.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiabsolutepointerstateactivebuttonflags.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiacpiaddressspacedescriptor.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiacpidescriptor.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiacpiresourcetype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiallocatetype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiblockiomedia.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiblockioprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefibootservices.h \
    $$PWD/src/com/ngos/shared/common/uefi/ueficapsuleheader.h \
    $$PWD/src/com/ngos/shared/common/uefi/ueficonfigurationtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/ueficonsolecontrolprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/ueficonsolecontrolscreenmode.h \
    $$PWD/src/com/ngos/shared/common/uefi/ueficpuphysicallocation.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefidevicepath.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefidevicepathsubtype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefidevicepathtotextprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefidevicepathtype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefieventtype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefifileattributeflags.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefifileinfo.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefifileiotoken.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefifilemodeflags.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefifilepath.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefifileprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefigraphicsoutputbltoperation.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefigraphicsoutputbltpixel.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefigraphicsoutputmodeinformation.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefigraphicsoutputprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefigraphicsoutputprotocolmode.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefigraphicspixelformat.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiharddrivedevicepath.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiharddrivedevicepathmbrtype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiharddrivedevicepathsignaturetype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiinputkey.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiinputkeyscancode.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiinterfacetype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiipaddress.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiipv4address.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiipv6address.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiloadedimageprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefilocatesearchtype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefimacaddress.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefimemorydescriptor.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefimemorytype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefimpservicesprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefinetworkstatistics.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiopenprotocolinformationentry.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipciioprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipciioprotocolaccess.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipciioprotocolattributeoperation.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipciioprotocolconfigaccess.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipciioprotocoloperation.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipciioprotocolwidth.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipcirootbridgeioprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipcirootbridgeioprotocolaccess.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipcirootbridgeioprotocoloperation.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipcirootbridgeioprotocolwidth.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefipixelbitmask.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiprocessorinformation.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiprocessorinformationstatusflags.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiresettype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefiruntimeservices.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplefilesystemprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimpleinputinterface.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplenetworkinterfacetype.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplenetworkinterruptflags.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplenetworkmode.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplenetworkprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplenetworkreceivefilterflags.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplenetworkstate.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplepointermode.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplepointerprotocol.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimplepointerstate.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimpletextoutputinterface.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisimpletextoutputmode.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefistatus.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefisystemtable.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefitableheader.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefitime.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefitimecapabilicies.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefitimerdelay.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefitpl.h \
    $$PWD/src/com/ngos/shared/common/uefi/uefivariableattributeflags.h \
    $$PWD/src/com/ngos/shared/common/uuid/utils.h \
    $$PWD/src/com/ngos/shared/common/uuid/uuid.h \
    $$PWD/src/com/ngos/shared/common/zlib/zlib.h \
    $$PWD/src/com/ngos/shared/common/zlib/zlibcompressioninfo.h \
    $$PWD/src/com/ngos/shared/common/zlib/zlibcompressionlevel.h \
    $$PWD/src/com/ngos/shared/common/zlib/zlibcompressionmethod.h \
    $$PWD/src/com/ngos/shared/common/zlib/zlibheader.h
