#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H



#include <buildconfig.h>
#include <common/src/bits64/assets/assetentry.h>
#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/checksum/adler.h>
#include <common/src/bits64/checksum/crc.h>
#include <common/src/bits64/console/console.h>
#include <common/src/bits64/console/lib/glyphdata.h>
#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/cpu/cpufamily.h>
#include <common/src/bits64/cpu/cpuvendor.h>
#include <common/src/bits64/cpu/model/amd.h>
#include <common/src/bits64/cpu/model/intel.h>
#include <common/src/bits64/cpu/msr/msr.h>
#include <common/src/bits64/cpu/x86bug.h>
#include <common/src/bits64/cpu/x86bugword.h>
#include <common/src/bits64/cpu/x86feature.h>
#include <common/src/bits64/cpu/x86featureword.h>
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
#include <common/src/bits64/graphics/png/lib/chunks/pngimagegamma.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngimageheader.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngphysicalpixeldimensions.h>
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
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/misc/cursorwidget.h>
#include <common/src/bits64/gui/widgets/misc/imagewidget.h>
#include <common/src/bits64/gui/widgets/misc/screenwidget.h>
#include <common/src/bits64/gui/widgets/widget.h>
#include <common/src/bits64/inflate/inflateblocktype.h>
#include <common/src/bits64/inflate/inflatecode.h>
#include <common/src/bits64/inflate/inflatecodetype.h>
#include <common/src/bits64/inflate/inflatedecoder.h>
#include <common/src/bits64/memory/fixforvtable.h>
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
        TEST_ASSERT_EQUALS(sizeof(AmdCpuModel),                                   1);
        TEST_ASSERT_EQUALS(sizeof(AssetEntry),                                    24);
        TEST_ASSERT_EQUALS(sizeof(Assets),                                        1);
        TEST_ASSERT_EQUALS(sizeof(Bmp),                                           1);
        TEST_ASSERT_EQUALS(sizeof(BmpColorMap),                                   4);
        TEST_ASSERT_EQUALS(sizeof(BmpCompressionMethod),                          4);
        TEST_ASSERT_EQUALS(sizeof(BmpHeader),                                     14);
        TEST_ASSERT_EQUALS(sizeof(BmpInformationHeader),                          40);
        TEST_ASSERT_EQUALS(sizeof(Button),                                        144);
        TEST_ASSERT_EQUALS(sizeof(CPU),                                           1);
        TEST_ASSERT_EQUALS(sizeof(Console),                                       1);
        TEST_ASSERT_EQUALS(sizeof(CpuFamily),                                     2);
        TEST_ASSERT_EQUALS(sizeof(CpuVendor),                                     1);
        TEST_ASSERT_EQUALS(sizeof(Crc),                                           1);
        TEST_ASSERT_EQUALS(sizeof(CursorWidget),                                  96);
        TEST_ASSERT_EQUALS(sizeof(FPU),                                           1);
        TEST_ASSERT_EQUALS(sizeof(FSaveState),                                    112);
        TEST_ASSERT_EQUALS(sizeof(FXSaveState),                                   512);
        TEST_ASSERT_EQUALS(sizeof(FpuState),                                      4096);
        TEST_ASSERT_EQUALS(sizeof(GUI),                                           1);
        TEST_ASSERT_EQUALS(sizeof(GlyphData),                                     5);
        TEST_ASSERT_EQUALS(sizeof(Graphics),                                      1);
        TEST_ASSERT_EQUALS(sizeof(Image),                                         6);
        TEST_ASSERT_EQUALS(sizeof(ImageWidget),                                   80);
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
        TEST_ASSERT_EQUALS(sizeof(JpegMarkerHeader),                              4);
        TEST_ASSERT_EQUALS(sizeof(JpegMarkerType),                                1);
        TEST_ASSERT_EQUALS(sizeof(JpegQuantizationTable),                         1);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfFrameComponent),                     3);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfFrameMarker),                        10);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfScanComponent),                      2);
        TEST_ASSERT_EQUALS(sizeof(JpegStartOfScanMarker),                         5);
        TEST_ASSERT_EQUALS(sizeof(JpegVlcCode),                                   2);
        TEST_ASSERT_EQUALS(sizeof(List<u8>),                                      16);
        TEST_ASSERT_EQUALS(sizeof(ListElement<u8>),                               24);
        TEST_ASSERT_EQUALS(sizeof(MSR),                                           1);
        TEST_ASSERT_EQUALS(sizeof(MpxBoundRegister),                              16);
        TEST_ASSERT_EQUALS(sizeof(Png),                                           1);
        TEST_ASSERT_EQUALS(sizeof(PngChunk),                                      8);
        TEST_ASSERT_EQUALS(sizeof(PngChunkType),                                  4);
        TEST_ASSERT_EQUALS(sizeof(PngColorType),                                  1);
        TEST_ASSERT_EQUALS(sizeof(PngCompressionMethod),                          1);
        TEST_ASSERT_EQUALS(sizeof(PngDecoder),                                    88);
        TEST_ASSERT_EQUALS(sizeof(PngFilterMethod),                               1);
        TEST_ASSERT_EQUALS(sizeof(PngFilterType),                                 1);
        TEST_ASSERT_EQUALS(sizeof(PngHeader),                                     16);
        TEST_ASSERT_EQUALS(sizeof(PngImageGamma),                                 4);
        TEST_ASSERT_EQUALS(sizeof(PngImageHeader),                                13);
        TEST_ASSERT_EQUALS(sizeof(PngInterlaceMethod),                            1);
        TEST_ASSERT_EQUALS(sizeof(PngPhysicalPixelDimensions),                    9);
        TEST_ASSERT_EQUALS(sizeof(PngRenderingIntent),                            1);
        TEST_ASSERT_EQUALS(sizeof(PngSignificantBits),                            4);
        TEST_ASSERT_EQUALS(sizeof(PngStandardRgbColorSpace),                      1);
        TEST_ASSERT_EQUALS(sizeof(PngUnitSpecifier),                              1);
        TEST_ASSERT_EQUALS(sizeof(Register128Bit),                                16);
        TEST_ASSERT_EQUALS(sizeof(Register256Bit),                                32);
        TEST_ASSERT_EQUALS(sizeof(Register512Bit),                                64);
        TEST_ASSERT_EQUALS(sizeof(RgbPixel),                                      3);
        TEST_ASSERT_EQUALS(sizeof(RgbaPixel),                                     4);
        TEST_ASSERT_EQUALS(sizeof(ScreenWidget),                                  88);
        TEST_ASSERT_EQUALS(sizeof(Serial),                                        1);
        TEST_ASSERT_EQUALS(sizeof(Widget),                                        64);
        TEST_ASSERT_EQUALS(sizeof(X86Bug),                                        2);
        TEST_ASSERT_EQUALS(sizeof(X86Feature),                                    2);
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
        TEST_ASSERT_EQUALS(sizeof(__cxxabiv1::__class_type_info),                 8);
        TEST_ASSERT_EQUALS(sizeof(__cxxabiv1::__si_class_type_info),              8);
        TEST_ASSERT_EQUALS(sizeof(x86BugWord),                                    1);
        TEST_ASSERT_EQUALS(sizeof(x86FeatureWord),                                1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H
