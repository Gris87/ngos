#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H



#include <buildconfig.h>
#include <common/src/bits64/assets/assetentry.h>
#include <common/src/bits64/console/lib/glyphdata.h>
#include <common/src/bits64/fpu/fpustate.h>
#include <common/src/bits64/fpu/fsavestate.h>
#include <common/src/bits64/fpu/fxsavestate.h>
#include <common/src/bits64/fpu/xfeatures/extendedregisters.h>
#include <common/src/bits64/fpu/xfeatures/xfeatureavx512opmaskstate.h>
#include <common/src/bits64/fpu/xfeatures/xfeatureavx512zmmfrom0to15state.h>
#include <common/src/bits64/fpu/xfeatures/xfeatureavx512zmmfrom16to31state.h>
#include <common/src/bits64/fpu/xfeatures/xfeatureavxstate.h>
#include <common/src/bits64/fpu/xfeatures/xfeaturempxboundconfigandstatusregistersstate.h>
#include <common/src/bits64/fpu/xfeatures/xfeaturempxboundregistersstate.h>
#include <common/src/bits64/fpu/xfeatures/xfeaturepkrustate.h>
#include <common/src/bits64/fpu/xsavestate.h>
#include <common/src/bits64/fpu/xstateheader.h>

#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(AssetEntry), 24);

        TEST_ASSERT_EQUALS(sizeof(GlyphData), 5);

        TEST_ASSERT_EQUALS(sizeof(FSaveState), 112);

        TEST_ASSERT_EQUALS(sizeof(FXSaveState), 512);

        TEST_ASSERT_EQUALS(sizeof(Register128Bit), 16);
        TEST_ASSERT_EQUALS(sizeof(Register256Bit), 32);
        TEST_ASSERT_EQUALS(sizeof(Register512Bit), 64);

        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512OpmaskState), 64);

        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512ZmmFrom0To15State), 512);

        TEST_ASSERT_EQUALS(sizeof(XFeatureAvx512ZmmFrom16To31State), 1024);

        TEST_ASSERT_EQUALS(sizeof(XFeatureAvxState), 256);

        TEST_ASSERT_EQUALS(sizeof(XFeatureMpxBoundConfigAndStatusRegistersState), 64);

        TEST_ASSERT_EQUALS(sizeof(MpxBoundRegister),               16);
        TEST_ASSERT_EQUALS(sizeof(XFeatureMpxBoundRegistersState), 64);

        TEST_ASSERT_EQUALS(sizeof(XFeaturePkruState), 8);

        TEST_ASSERT_EQUALS(sizeof(XSaveState), 576);

        TEST_ASSERT_EQUALS(sizeof(XStateHeader), 64);
    }
    TEST_CASE_END();



    TEST_CASE("Size of unions");
    {
        TEST_ASSERT_EQUALS(sizeof(FpuState), 4096);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_TYPES_H
