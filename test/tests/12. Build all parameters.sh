#!/bin/bash



###########################################################################################
#    PARAMETERS
###########################################################################################



WORKING_DIR=`pwd`
BUILD_CONFIG=include/buildconfig.h
BUILD_LOG=/tmp/ngos_test.log
BUILD_CFG_BACKUP=/tmp/ngos_test_buildconfig2.h



###########################################################################################
#    FUNCTIONS
###########################################################################################



function run_build
{
    echo "Building with $1"

    tools/qt/build_config_maker/build/build_config_maker ${BUILD_CONFIG} $1 >  ${BUILD_LOG} 2>&1
    make all                                                                >> ${BUILD_LOG} 2>&1

    if [ $? -ne 0 ]; then
        cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
        cd ${WORKING_DIR}/

        cat ${BUILD_LOG} 2>&1
        exit 1
    fi
}



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m           Test: Build all parameters\e[0m"
echo -e "\e[36m==================================================\e[0m"



cd ../../
cp ${BUILD_CONFIG} ${BUILD_CFG_BACKUP}



run_build NGOS_BUILD_ARCH=OPTION_ARCH_X86_64

run_build NGOS_BUILD_RELEASE=OPTION_YES
run_build NGOS_BUILD_RELEASE=OPTION_NO

run_build NGOS_BUILD_TEST_MODE=OPTION_NO
run_build NGOS_BUILD_TEST_MODE=OPTION_YES

run_build NGOS_BUILD_KERNEL_COMPRESSION=OPTION_KERNEL_COMPRESSION_NONE
run_build NGOS_BUILD_KERNEL_COMPRESSION=OPTION_KERNEL_COMPRESSION_GZIP
run_build NGOS_BUILD_KERNEL_COMPRESSION=OPTION_KERNEL_COMPRESSION_XZ

run_build NGOS_BUILD_5_LEVEL_PAGING=OPTION_YES
run_build NGOS_BUILD_5_LEVEL_PAGING=OPTION_NO

run_build NGOS_BUILD_LOG_LEVEL=OPTION_LOG_LEVEL_FATAL
run_build NGOS_BUILD_LOG_LEVEL=OPTION_LOG_LEVEL_TRACE

run_build NGOS_BUILD_COMMON_LOG_LEVEL=OPTION_LOG_LEVEL_INHERIT
run_build NGOS_BUILD_COMMON_LOG_LEVEL=OPTION_LOG_LEVEL_FATAL
run_build NGOS_BUILD_COMMON_LOG_LEVEL=OPTION_LOG_LEVEL_TRACE

run_build NGOS_BUILD_UEFI_LOG_LEVEL=OPTION_LOG_LEVEL_INHERIT
run_build NGOS_BUILD_UEFI_LOG_LEVEL=OPTION_LOG_LEVEL_FATAL
run_build NGOS_BUILD_UEFI_LOG_LEVEL=OPTION_LOG_LEVEL_TRACE

run_build NGOS_BUILD_EARLY_LOG_LEVEL=OPTION_LOG_LEVEL_INHERIT
run_build NGOS_BUILD_EARLY_LOG_LEVEL=OPTION_LOG_LEVEL_FATAL
run_build NGOS_BUILD_EARLY_LOG_LEVEL=OPTION_LOG_LEVEL_TRACE

run_build NGOS_BUILD_REALTIME=OPTION_NO
run_build NGOS_BUILD_REALTIME=OPTION_YES

run_build NGOS_BUILD_REALTIME_RAM_USAGE=OPTION_REALTIME_RAM_USAGE_LOWEST
run_build NGOS_BUILD_REALTIME_RAM_USAGE=OPTION_REALTIME_RAM_USAGE_LOWER
run_build NGOS_BUILD_REALTIME_RAM_USAGE=OPTION_REALTIME_RAM_USAGE_LOW
run_build NGOS_BUILD_REALTIME_RAM_USAGE=OPTION_REALTIME_RAM_USAGE_MEDIUM
run_build NGOS_BUILD_REALTIME_RAM_USAGE=OPTION_REALTIME_RAM_USAGE_HIGH
run_build NGOS_BUILD_REALTIME_RAM_USAGE=OPTION_REALTIME_RAM_USAGE_HIGHER
run_build NGOS_BUILD_REALTIME_RAM_USAGE=OPTION_REALTIME_RAM_USAGE_HIGHEST

run_build NGOS_BUILD_KERNEL_ALIGN=0x0000000000200000
run_build NGOS_BUILD_KERNEL_ALIGN=0x0000000001000000

run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_NONE
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_SSE
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_SSE2
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_SSE3
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_SSE4
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_AVX
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_AVX2
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V1
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V2
run_build NGOS_BUILD_X86_64_VECTORIZATION_MODE=OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3

run_build NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD=OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE
run_build NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD=OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA4
run_build NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD=OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3



cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
cd ${WORKING_DIR}/



exit 0
