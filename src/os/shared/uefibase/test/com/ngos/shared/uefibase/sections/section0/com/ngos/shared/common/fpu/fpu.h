#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_FPU_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_FPU_H



#include <buildconfig.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_fpu_fpu);
{
    TEST_CASE("setFeature()/clearFeature()/hasFeature()");
    {
        XFeatureTypeFlags temp = FPU::sXFeatures;
        FPU::sXFeatures        = 0;

        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX), false);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::SSE), false);

        TEST_ASSERT_EQUALS(FPU::setFeature(XFeature::AVX), NgosStatus::OK);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX), true);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::SSE), false);
        TEST_ASSERT_EQUALS(FPU::sXFeatures,                0x0000000000000004);

        TEST_ASSERT_EQUALS(FPU::setFeature(XFeature::SSE), NgosStatus::OK);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX), true);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::SSE), true);
        TEST_ASSERT_EQUALS(FPU::sXFeatures,                0x0000000000000006);

        TEST_ASSERT_EQUALS(FPU::clearFeature(XFeature::AVX), NgosStatus::OK);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX),   false);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::SSE),   true);
        TEST_ASSERT_EQUALS(FPU::sXFeatures,                  0x0000000000000002);

        TEST_ASSERT_EQUALS(FPU::clearFeature(XFeature::SSE), NgosStatus::OK);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX),   false);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::SSE),   false);
        TEST_ASSERT_EQUALS(FPU::sXFeatures,                  0);



        FPU::sXFeatures = 0x0000000000000267;

        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::FPU),                                   true);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::SSE),                                   true);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX),                                   true);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::MPX_BOUND_REGISTERS),                   false);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::MPX_BOUND_CONFIG_AND_STATUS_REGISTERS), false);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX512_OPMASK),                         true);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX512_ZMM_FROM_0_TO_15),               true);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::AVX512_ZMM_FROM_16_TO_31),              false);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::PT),                                    false);
        TEST_ASSERT_EQUALS(FPU::hasFeature(XFeature::PKRU),                                  true);

        FPU::sXFeatures = temp;
    }
    TEST_CASE_END();



    TEST_CASE("setFlag()/clearFlag()/hasFlag()");
    {
        XFeatureTypeFlags temp = FPU::sXFeatures;
        FPU::sXFeatures        = 0;

        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX), false);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::SSE), false);

        TEST_ASSERT_EQUALS(FPU::setFlag(XFeatureTypeFlag::AVX), NgosStatus::OK);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX), true);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::SSE), false);
        TEST_ASSERT_EQUALS(FPU::sXFeatures,                     0x0000000000000004);

        TEST_ASSERT_EQUALS(FPU::setFlag(XFeatureTypeFlag::SSE), NgosStatus::OK);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX), true);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::SSE), true);
        TEST_ASSERT_EQUALS(FPU::sXFeatures,                     0x0000000000000006);

        TEST_ASSERT_EQUALS(FPU::clearFlag(XFeatureTypeFlag::AVX), NgosStatus::OK);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX),   false);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::SSE),   true);
        TEST_ASSERT_EQUALS(FPU::sXFeatures,                       0x0000000000000002);

        TEST_ASSERT_EQUALS(FPU::clearFlag(XFeatureTypeFlag::SSE), NgosStatus::OK);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX),   false);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::SSE),   false);
        TEST_ASSERT_EQUALS(FPU::sXFeatures,                       0);



        FPU::sXFeatures = 0x0000000000000267;

        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::FPU),                                   true);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::SSE),                                   true);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX),                                   true);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::MPX_BOUND_REGISTERS),                   false);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::MPX_BOUND_CONFIG_AND_STATUS_REGISTERS), false);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX512_OPMASK),                         true);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX512_ZMM_FROM_0_TO_15),               true);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::AVX512_ZMM_FROM_16_TO_31),              false);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::PT),                                    false);
        TEST_ASSERT_EQUALS(FPU::hasFlag(XFeatureTypeFlag::PKRU),                                  true);

        FPU::sXFeatures = temp;
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_FPU_H
