SOURCES += \
    $$PWD/asm/arch/x86_64/bits64/memory/memcpy.S \
    $$PWD/asm/arch/x86_64/bits64/memory/memset.S \
    $$PWD/asm/arch/x86_64/bits64/memory/memzero.S \
    $$PWD/src/bits64/assets/assets.cpp \
    $$PWD/src/bits64/checksum/adler.cpp \
    $$PWD/src/bits64/checksum/crc.cpp \
    $$PWD/src/bits64/checksum/md5.cpp \
    $$PWD/src/bits64/compilation/fixforglobaldestructors.cpp \
    $$PWD/src/bits64/compilation/fixforvtable.cpp \
    $$PWD/src/bits64/console/console.cpp \
    $$PWD/src/bits64/console/graphicalconsole.cpp \
    $$PWD/src/bits64/cpu/cpu.cpp \
    $$PWD/src/bits64/cpu/generated/x86bugsnames.cpp \
    $$PWD/src/bits64/cpu/generated/x86featuresnames.cpp \
    $$PWD/src/bits64/cpu/msr/msr.cpp \
    $$PWD/src/bits64/cryptography/aes.cpp \
    $$PWD/src/bits64/dmi/dmi.cpp \
    $$PWD/src/bits64/fpu/fpu.cpp \
    $$PWD/src/bits64/graphics/bmp/bmp.cpp \
    $$PWD/src/bits64/graphics/graphics.cpp \
    $$PWD/src/bits64/graphics/image.cpp \
    $$PWD/src/bits64/graphics/jpeg/jpeg.cpp \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegzigzagorder.cpp \
    $$PWD/src/bits64/graphics/ninepatch.cpp \
    $$PWD/src/bits64/graphics/png/png.cpp \
    $$PWD/src/bits64/graphics/stretchrange.cpp \
    $$PWD/src/bits64/gui/gui.cpp \
    $$PWD/src/bits64/gui/widgets/controls/button.cpp \
    $$PWD/src/bits64/gui/widgets/controls/tabbutton.cpp \
    $$PWD/src/bits64/gui/widgets/controls/tablewidget.cpp \
    $$PWD/src/bits64/gui/widgets/controls/tabwidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/consolewidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/cursorwidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/imagewidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/labelwidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/panelwidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/tablecellwidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/tableheaderwidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/tablerowwidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/tabpagewidget.cpp \
    $$PWD/src/bits64/gui/widgets/misc/wrapperwidget.cpp \
    $$PWD/src/bits64/gui/widgets/special/rootwidget.cpp \
    $$PWD/src/bits64/gui/widgets/special/screenwidget.cpp \
    $$PWD/src/bits64/gui/widgets/widget.cpp \
    $$PWD/src/bits64/inflate/inflate.cpp \
    $$PWD/src/bits64/memory/malloc.cpp \
    $$PWD/src/bits64/memory/memory.cpp \
    $$PWD/src/bits64/printf/printf.cpp \
    $$PWD/src/bits64/random/random.cpp \
    $$PWD/src/bits64/serial/serial.cpp \
    $$PWD/src/bits64/string/generated/bytesdecimals.cpp \
    $$PWD/src/bits64/string/generated/numberdecimals.cpp \
    $$PWD/src/bits64/string/string.cpp \
    $$PWD/src/bits64/zlib/zlib.cpp

HEADERS += \
    $$PWD/src/bits64/assets/assetentry.h \
    $$PWD/src/bits64/assets/assets.h \
    $$PWD/src/bits64/checksum/adler.h \
    $$PWD/src/bits64/checksum/crc.h \
    $$PWD/src/bits64/checksum/lib/md5hash.h \
    $$PWD/src/bits64/checksum/md5.h \
    $$PWD/src/bits64/console/console.h \
    $$PWD/src/bits64/console/graphicalconsole.h \
    $$PWD/src/bits64/console/lib/glyphdata.h \
    $$PWD/src/bits64/containers/arraylist.h \
    $$PWD/src/bits64/containers/lib/listelement.h \
    $$PWD/src/bits64/containers/list.h \
    $$PWD/src/bits64/cpu/cpu.h \
    $$PWD/src/bits64/cpu/cpufamily.h \
    $$PWD/src/bits64/cpu/cpuvendor.h \
    $$PWD/src/bits64/cpu/flags.h \
    $$PWD/src/bits64/cpu/generated/x86bugsnames.h \
    $$PWD/src/bits64/cpu/generated/x86featuresnames.h \
    $$PWD/src/bits64/cpu/model/amd.h \
    $$PWD/src/bits64/cpu/model/cpumodel.h \
    $$PWD/src/bits64/cpu/model/intel.h \
    $$PWD/src/bits64/cpu/msr/msr.h \
    $$PWD/src/bits64/cpu/msr/msrregisters.h \
    $$PWD/src/bits64/cpu/x86bug.h \
    $$PWD/src/bits64/cpu/x86bugword.h \
    $$PWD/src/bits64/cpu/x86feature.h \
    $$PWD/src/bits64/cpu/x86featureword.h \
    $$PWD/src/bits64/cryptography/aes.h \
    $$PWD/src/bits64/dmi/dmi.h \
    $$PWD/src/bits64/dmi/dmientryheader.h \
    $$PWD/src/bits64/dmi/dmientrytype.h \
    $$PWD/src/bits64/dmi/dmiidentity.h \
    $$PWD/src/bits64/dmi/dmimemorydevice.h \
    $$PWD/src/bits64/dmi/dmistoreduuid.h \
    $$PWD/src/bits64/dmi/entry/dmibaseboardentry.h \
    $$PWD/src/bits64/dmi/entry/dmibiosentry.h \
    $$PWD/src/bits64/dmi/entry/dmichassisentry.h \
    $$PWD/src/bits64/dmi/entry/dmimemoryarraymappedaddressentry.h \
    $$PWD/src/bits64/dmi/entry/dmimemorydeviceentry.h \
    $$PWD/src/bits64/dmi/entry/dmiphysicalmemoryarrayentry.h \
    $$PWD/src/bits64/dmi/entry/dmiprocessorentry.h \
    $$PWD/src/bits64/dmi/entry/dmisystembootentry.h \
    $$PWD/src/bits64/dmi/entry/dmisystementry.h \
    $$PWD/src/bits64/dmi/entry/lib/dmibaseboardfeatureflags.h \
    $$PWD/src/bits64/dmi/entry/lib/dmibaseboardtype.h \
    $$PWD/src/bits64/dmi/entry/lib/dmibioscharacteristicsbiosreservedflags.h \
    $$PWD/src/bits64/dmi/entry/lib/dmibioscharacteristicsextension.h \
    $$PWD/src/bits64/dmi/entry/lib/dmibioscharacteristicsflags.h \
    $$PWD/src/bits64/dmi/entry/lib/dmibioscharacteristicssystemreservedflags.h \
    $$PWD/src/bits64/dmi/entry/lib/dmibiosextendedromsize.h \
    $$PWD/src/bits64/dmi/entry/lib/dmichassiscontainedelement.h \
    $$PWD/src/bits64/dmi/entry/lib/dmichassissecuritystatus.h \
    $$PWD/src/bits64/dmi/entry/lib/dmichassisstate.h \
    $$PWD/src/bits64/dmi/entry/lib/dmichassistype.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiphysicalmemoryarrayerrorcorrection.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiphysicalmemoryarraylocation.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiphysicalmemoryarrayuse.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiprocessorfamily.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiprocessorfamily2.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiprocessorfeatureflags.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiprocessorid.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiprocessorsignature.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiprocessortype.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiprocessorupgrade.h \
    $$PWD/src/bits64/dmi/entry/lib/dmiprocessorvoltageflags.h \
    $$PWD/src/bits64/dmi/entry/lib/dmisystembootstatus.h \
    $$PWD/src/bits64/dmi/entry/lib/dmisystemwakeuptime.h \
    $$PWD/src/bits64/early/earlyassert.h \
    $$PWD/src/bits64/early/earlylog.h \
    $$PWD/src/bits64/fpu/fpu.h \
    $$PWD/src/bits64/fpu/fpustate.h \
    $$PWD/src/bits64/fpu/fsavestate.h \
    $$PWD/src/bits64/fpu/fxsavestate.h \
    $$PWD/src/bits64/fpu/macros.h \
    $$PWD/src/bits64/fpu/xfeature.h \
    $$PWD/src/bits64/fpu/xfeature/extendedregisters.h \
    $$PWD/src/bits64/fpu/xfeature/xfeatureavx512opmaskstate.h \
    $$PWD/src/bits64/fpu/xfeature/xfeatureavx512zmmfrom0to15state.h \
    $$PWD/src/bits64/fpu/xfeature/xfeatureavx512zmmfrom16to31state.h \
    $$PWD/src/bits64/fpu/xfeature/xfeatureavxstate.h \
    $$PWD/src/bits64/fpu/xfeature/xfeaturempxboundconfigandstatusregistersstate.h \
    $$PWD/src/bits64/fpu/xfeature/xfeaturempxboundregistersstate.h \
    $$PWD/src/bits64/fpu/xfeature/xfeaturepkrustate.h \
    $$PWD/src/bits64/fpu/xfeatureflags.h \
    $$PWD/src/bits64/fpu/xfeaturetypeflags.h \
    $$PWD/src/bits64/fpu/xsavestate.h \
    $$PWD/src/bits64/fpu/xstateheader.h \
    $$PWD/src/bits64/graphics/bmp/bmp.h \
    $$PWD/src/bits64/graphics/bmp/lib/bmpcolormap.h \
    $$PWD/src/bits64/graphics/bmp/lib/bmpcompressionmethod.h \
    $$PWD/src/bits64/graphics/bmp/lib/bmpheader.h \
    $$PWD/src/bits64/graphics/bmp/lib/bmpinformationheader.h \
    $$PWD/src/bits64/graphics/graphics.h \
    $$PWD/src/bits64/graphics/image.h \
    $$PWD/src/bits64/graphics/jpeg/jpeg.h \
    $$PWD/src/bits64/graphics/jpeg/jpegcomponent.h \
    $$PWD/src/bits64/graphics/jpeg/jpegdecoder.h \
    $$PWD/src/bits64/graphics/jpeg/jpegvlccode.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegcomponentid.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegdefinehuffmantablemarker.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegdefinequantizationtablemarker.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegdefinerestartintervalmarker.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpeghuffmantable.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegmarkerheader.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegmarkertype.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegquantizationtable.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegstartofframecomponent.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegstartofframemarker.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegstartofscancomponent.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegstartofscanmarker.h \
    $$PWD/src/bits64/graphics/jpeg/lib/jpegzigzagorder.h \
    $$PWD/src/bits64/graphics/ninepatch.h \
    $$PWD/src/bits64/graphics/png/lib/chunks/pngembeddediccprofile.h \
    $$PWD/src/bits64/graphics/png/lib/chunks/pngimagegamma.h \
    $$PWD/src/bits64/graphics/png/lib/chunks/pngimageheader.h \
    $$PWD/src/bits64/graphics/png/lib/chunks/pngimagelastmodificationtime.h \
    $$PWD/src/bits64/graphics/png/lib/chunks/pngphysicalpixeldimensions.h \
    $$PWD/src/bits64/graphics/png/lib/chunks/pngprimarychromaticities.h \
    $$PWD/src/bits64/graphics/png/lib/chunks/pngsignificantbits.h \
    $$PWD/src/bits64/graphics/png/lib/chunks/pngstandardrgbcolorspace.h \
    $$PWD/src/bits64/graphics/png/lib/pngchunk.h \
    $$PWD/src/bits64/graphics/png/lib/pngchunktype.h \
    $$PWD/src/bits64/graphics/png/lib/pngcolortype.h \
    $$PWD/src/bits64/graphics/png/lib/pngcompressionmethod.h \
    $$PWD/src/bits64/graphics/png/lib/pngfiltermethod.h \
    $$PWD/src/bits64/graphics/png/lib/pngfiltertype.h \
    $$PWD/src/bits64/graphics/png/lib/pngheader.h \
    $$PWD/src/bits64/graphics/png/lib/pnginterlacemethod.h \
    $$PWD/src/bits64/graphics/png/lib/pngrenderingintent.h \
    $$PWD/src/bits64/graphics/png/lib/pngunitspecifier.h \
    $$PWD/src/bits64/graphics/png/png.h \
    $$PWD/src/bits64/graphics/png/pngdecoder.h \
    $$PWD/src/bits64/graphics/rgbapixel.h \
    $$PWD/src/bits64/graphics/rgbpixel.h \
    $$PWD/src/bits64/graphics/stretchrange.h \
    $$PWD/src/bits64/gui/gui.h \
    $$PWD/src/bits64/gui/other/widgetstate.h \
    $$PWD/src/bits64/gui/widgets/controls/button.h \
    $$PWD/src/bits64/gui/widgets/controls/tabbutton.h \
    $$PWD/src/bits64/gui/widgets/controls/tablewidget.h \
    $$PWD/src/bits64/gui/widgets/controls/tabwidget.h \
    $$PWD/src/bits64/gui/widgets/misc/consolewidget.h \
    $$PWD/src/bits64/gui/widgets/misc/cursorwidget.h \
    $$PWD/src/bits64/gui/widgets/misc/imagewidget.h \
    $$PWD/src/bits64/gui/widgets/misc/labelwidget.h \
    $$PWD/src/bits64/gui/widgets/misc/panelwidget.h \
    $$PWD/src/bits64/gui/widgets/misc/tablecellwidget.h \
    $$PWD/src/bits64/gui/widgets/misc/tableheaderwidget.h \
    $$PWD/src/bits64/gui/widgets/misc/tablerowwidget.h \
    $$PWD/src/bits64/gui/widgets/misc/tabpagewidget.h \
    $$PWD/src/bits64/gui/widgets/misc/wrapperwidget.h \
    $$PWD/src/bits64/gui/widgets/special/rootwidget.h \
    $$PWD/src/bits64/gui/widgets/special/screenwidget.h \
    $$PWD/src/bits64/gui/widgets/widget.h \
    $$PWD/src/bits64/inflate/inflate.h \
    $$PWD/src/bits64/inflate/inflateblocktype.h \
    $$PWD/src/bits64/inflate/inflatecode.h \
    $$PWD/src/bits64/inflate/inflatecodetype.h \
    $$PWD/src/bits64/inflate/inflatedecoder.h \
    $$PWD/src/bits64/inflate/inflatefixedcodes.h \
    $$PWD/src/bits64/log/assert.h \
    $$PWD/src/bits64/log/log.h \
    $$PWD/src/bits64/memory/asm_memcpy.h \
    $$PWD/src/bits64/memory/asm_memset.h \
    $$PWD/src/bits64/memory/asm_memzero.h \
    $$PWD/src/bits64/memory/malloc.h \
    $$PWD/src/bits64/memory/memory.h \
    $$PWD/src/bits64/printf/printf.h \
    $$PWD/src/bits64/random/random.h \
    $$PWD/src/bits64/serial/serial.h \
    $$PWD/src/bits64/string/generated/bytesdecimals.h \
    $$PWD/src/bits64/string/generated/numberdecimals.h \
    $$PWD/src/bits64/string/string.h \
    $$PWD/src/bits64/string/utils.h \
    $$PWD/src/bits64/zlib/zlib.h \
    $$PWD/src/bits64/zlib/zlibcompressioninfo.h \
    $$PWD/src/bits64/zlib/zlibcompressionlevel.h \
    $$PWD/src/bits64/zlib/zlibcompressionmethod.h \
    $$PWD/src/bits64/zlib/zlibheader.h
