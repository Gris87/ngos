#ifndef BUILDCONFIG_H
#define BUILDCONFIG_H



// =========================================================================
// AVAILABLE BUILD CONFIG OPTIONS
// =========================================================================



#define OPTION_YES 1    // Option enabled
#define OPTION_NO  0    // Option disabled

#define OPTION_ARCH_X86_64 0    // x86_64

#define OPTION_OPTIMIZATION_LEVEL_0 0    // Compile without optimization
#define OPTION_OPTIMIZATION_LEVEL_1 1    // Compile with -O1 option
#define OPTION_OPTIMIZATION_LEVEL_2 2    // Compile with -O2 option
#define OPTION_OPTIMIZATION_LEVEL_3 3    // Compile with -O3 option

#define OPTION_KERNEL_COMPRESSION_NONE 0    // Do not compress kernel
#define OPTION_KERNEL_COMPRESSION_XZ   1    // Compress kernel with xz
#define OPTION_KERNEL_COMPRESSION_GZIP 2    // Compress kernel with gzip

#define OPTION_LOG_LEVEL_INHERIT           -1   // Log level is inherited from General log level
#define OPTION_LOG_LEVEL_NONE              0    // Logging is disabled
#define OPTION_LOG_LEVEL_FATAL             1    // Log fatal messages only
#define OPTION_LOG_LEVEL_CRITICAL          2    // Log critical and fatal messages
#define OPTION_LOG_LEVEL_ERROR             3    // Log error and more critical messages
#define OPTION_LOG_LEVEL_WARNING           4    // Log warning and more critical messages
#define OPTION_LOG_LEVEL_INFO              5    // Log info and more critical messages
#define OPTION_LOG_LEVEL_DEBUG             6    // Log debug and more critical messages
#define OPTION_LOG_LEVEL_VERBOSE           7    // Log verbose and more critical messages
#define OPTION_LOG_LEVEL_VERY_VERBOSE      8    // Log very verbose and more critical messages
#define OPTION_LOG_LEVEL_VERY_VERY_VERBOSE 9    // Log as much as possible
#define OPTION_LOG_LEVEL_TRACE             10   // Log as much as possible + log each function call

#define OPTION_REALTIME_RAM_USAGE_LOWEST  0     // Use the lowest amount of memory to enable realtime with enough accuracy / performance
#define OPTION_REALTIME_RAM_USAGE_LOWER   1     // Use a little bit more memory to increase accuracy / performance in realtime
#define OPTION_REALTIME_RAM_USAGE_LOW     2     // Use a little bit more memory to increase accuracy / performance in realtime
#define OPTION_REALTIME_RAM_USAGE_MEDIUM  3     // Use a little bit more memory to increase accuracy / performance in realtime
#define OPTION_REALTIME_RAM_USAGE_HIGH    4     // Use a little bit more memory to increase accuracy / performance in realtime
#define OPTION_REALTIME_RAM_USAGE_HIGHER  5     // Use a little bit more memory to increase accuracy / performance in realtime
#define OPTION_REALTIME_RAM_USAGE_HIGHEST 6     // Use the highest amount of memory to enable realtime with the best accuracy / performance

#define OPTION_X86_64_VECTORIZATION_MODE_SSE2       0   // Compile kernel with SSE2 vectorization
#define OPTION_X86_64_VECTORIZATION_MODE_SSE3       1   // Compile kernel with SSE3 vectorization
#define OPTION_X86_64_VECTORIZATION_MODE_SSE4       2   // Compile kernel with SSE4 vectorization
#define OPTION_X86_64_VECTORIZATION_MODE_AVX        3   // Compile kernel with AVX vectorization
#define OPTION_X86_64_VECTORIZATION_MODE_AVX2       4   // Compile kernel with AVX2 vectorization
#define OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V1 5   // Compile kernel with AVX-512 vectorization (F + CD + ER + PF)
#define OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V2 6   // Compile kernel with AVX-512 vectorization (F + CD + BW + DQ + VL)
#define OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3 7   // Compile kernel with AVX-512 vectorization (F + CD + BW + DQ + VL + IFMA + VBMI)

#define OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE 0     // Compile kernel without Fused Multiply-Add support
#define OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA4 1     // Compile kernel with Fused Multiply-Add 4 (4 means with 4 operands)
#define OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3 2     // Compile kernel with Fused Multiply-Add 3 (3 means with 3 operands)



// =========================================================================
// BUILD CONFIG PARAMETERS
// =========================================================================



/***
 *** Category: General
 *** Name: Architecture
 ***
 *** Description: Target platform architecture.
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_ARCH_X86_64
 ***
 *** Default: OPTION_ARCH_X86_64
 ***/
#define NGOS_BUILD_ARCH OPTION_ARCH_X86_64



/***
 *** Category: General
 *** Name: Release
 ***
 *** Description: Build kernel in Release / Debug mode.
 ***
 *** Type: Boolean
 ***
 *** Values: true = OPTION_YES, false = OPTION_NO
 *** Value description: true = Release mode, false = Debug mode
 ***
 *** Default: OPTION_YES
 ***/
#define NGOS_BUILD_RELEASE OPTION_NO



/***
 *** Category: General
 *** Name: Test mode
 ***
 *** Description: Build kernel with including tests.
 ***
 *** Type: Boolean
 ***
 *** Values: true = OPTION_YES, false = OPTION_NO
 *** Value description: true = Include tests, false = Do not include tests
 ***
 *** Default: OPTION_NO
 ***/
#define NGOS_BUILD_TEST_MODE OPTION_YES



#if NGOS_BUILD_RELEASE == OPTION_NO
/***
 *** Category: General
 *** Name: Optimization level
 ***
 *** Description: Selected optimization level during compilation.
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_OPTIMIZATION_LEVEL_0, \
 ***         OPTION_OPTIMIZATION_LEVEL_1, \
 ***         OPTION_OPTIMIZATION_LEVEL_2, \
 ***         OPTION_OPTIMIZATION_LEVEL_3
 ***
 *** Default: OPTION_OPTIMIZATION_LEVEL_0
 ***/
#define NGOS_BUILD_OPTIMIZATION_LEVEL OPTION_OPTIMIZATION_LEVEL_0
#else
#define NGOS_BUILD_OPTIMIZATION_LEVEL OPTION_OPTIMIZATION_LEVEL_3
#endif



/***
 *** Category: General
 *** Name: Kernel compression method
 ***
 *** Description: Selected type of kernel compression.
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_KERNEL_COMPRESSION_NONE, \
 ***         OPTION_KERNEL_COMPRESSION_GZIP, \
 ***         OPTION_KERNEL_COMPRESSION_XZ
 ***
 *** Default: OPTION_KERNEL_COMPRESSION_XZ
 ***/
#define NGOS_BUILD_KERNEL_COMPRESSION OPTION_KERNEL_COMPRESSION_XZ



/***
 *** Category: General
 *** Name: 5 level paging
 ***
 *** Description: Build kernel with 5 level paging.
 ***
 *** Type: Boolean
 ***
 *** Values: true = OPTION_YES, false = OPTION_NO
 *** Value description: true = Use 5 level paging, false = Use 4 level paging
 ***
 *** Default: OPTION_NO
 ***/
#define NGOS_BUILD_5_LEVEL_PAGING OPTION_NO



#if NGOS_BUILD_RELEASE == OPTION_NO
/***
 *** Category: General -> Logging
 *** Name: General log level
 ***
 *** Description: Set the general level of logging.
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_LOG_LEVEL_NONE, \
 ***         OPTION_LOG_LEVEL_FATAL, \
 ***         OPTION_LOG_LEVEL_CRITICAL, \
 ***         OPTION_LOG_LEVEL_ERROR, \
 ***         OPTION_LOG_LEVEL_WARNING, \
 ***         OPTION_LOG_LEVEL_INFO, \
 ***         OPTION_LOG_LEVEL_DEBUG, \
 ***         OPTION_LOG_LEVEL_VERBOSE, \
 ***         OPTION_LOG_LEVEL_VERY_VERBOSE, \
 ***         OPTION_LOG_LEVEL_VERY_VERY_VERBOSE, \
 ***         OPTION_LOG_LEVEL_TRACE
 ***
 *** Default: OPTION_LOG_LEVEL_DEBUG
 ***/
#define NGOS_BUILD_LOG_LEVEL OPTION_LOG_LEVEL_TRACE
#else
#define NGOS_BUILD_LOG_LEVEL OPTION_LOG_LEVEL_ERROR
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO
/***
 *** Category: General -> Logging
 *** Name: Log level for common stuff
 ***
 *** Description: Set level of logging for common code.
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_LOG_LEVEL_INHERIT, \
 ***         OPTION_LOG_LEVEL_NONE, \
 ***         OPTION_LOG_LEVEL_FATAL, \
 ***         OPTION_LOG_LEVEL_CRITICAL, \
 ***         OPTION_LOG_LEVEL_ERROR, \
 ***         OPTION_LOG_LEVEL_WARNING, \
 ***         OPTION_LOG_LEVEL_INFO, \
 ***         OPTION_LOG_LEVEL_DEBUG, \
 ***         OPTION_LOG_LEVEL_VERBOSE, \
 ***         OPTION_LOG_LEVEL_VERY_VERBOSE, \
 ***         OPTION_LOG_LEVEL_VERY_VERY_VERBOSE, \
 ***         OPTION_LOG_LEVEL_TRACE
 ***
 *** Default: OPTION_LOG_LEVEL_INHERIT
 ***/
#define NGOS_BUILD_COMMON_LOG_LEVEL OPTION_LOG_LEVEL_INHERIT
#else
#define NGOS_BUILD_COMMON_LOG_LEVEL OPTION_LOG_LEVEL_INHERIT
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO
/***
 *** Category: General -> Logging
 *** Name: UEFI log level
 ***
 *** Description: Set the UEFI level of logging.
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_LOG_LEVEL_INHERIT, \
 ***         OPTION_LOG_LEVEL_NONE, \
 ***         OPTION_LOG_LEVEL_FATAL, \
 ***         OPTION_LOG_LEVEL_CRITICAL, \
 ***         OPTION_LOG_LEVEL_ERROR, \
 ***         OPTION_LOG_LEVEL_WARNING, \
 ***         OPTION_LOG_LEVEL_INFO, \
 ***         OPTION_LOG_LEVEL_DEBUG, \
 ***         OPTION_LOG_LEVEL_VERBOSE, \
 ***         OPTION_LOG_LEVEL_VERY_VERBOSE, \
 ***         OPTION_LOG_LEVEL_VERY_VERY_VERBOSE, \
 ***         OPTION_LOG_LEVEL_TRACE
 ***
 *** Default: OPTION_LOG_LEVEL_INHERIT
 ***/
#define NGOS_BUILD_UEFI_LOG_LEVEL OPTION_LOG_LEVEL_INHERIT
#else
#define NGOS_BUILD_UEFI_LOG_LEVEL OPTION_LOG_LEVEL_INHERIT
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO
/***
 *** Category: General -> Logging
 *** Name: Early log level
 ***
 *** Description: Set the early level of logging.
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_LOG_LEVEL_INHERIT, \
 ***         OPTION_LOG_LEVEL_NONE, \
 ***         OPTION_LOG_LEVEL_FATAL, \
 ***         OPTION_LOG_LEVEL_CRITICAL, \
 ***         OPTION_LOG_LEVEL_ERROR, \
 ***         OPTION_LOG_LEVEL_WARNING, \
 ***         OPTION_LOG_LEVEL_INFO, \
 ***         OPTION_LOG_LEVEL_DEBUG, \
 ***         OPTION_LOG_LEVEL_VERBOSE, \
 ***         OPTION_LOG_LEVEL_VERY_VERBOSE, \
 ***         OPTION_LOG_LEVEL_VERY_VERY_VERBOSE, \
 ***         OPTION_LOG_LEVEL_TRACE
 ***
 *** Default: OPTION_LOG_LEVEL_INHERIT
 ***/
#define NGOS_BUILD_EARLY_LOG_LEVEL OPTION_LOG_LEVEL_INHERIT
#else
#define NGOS_BUILD_EARLY_LOG_LEVEL OPTION_LOG_LEVEL_INHERIT
#endif



/***
 *** Category: General -> Realtime
 *** Name: Use realtime mode
 ***
 *** Description: Build kernel in realtime mode. \
 ***              In this mode some functions works extremely fast, but it takes some memory.
 ***
 *** Type: Boolean
 ***
 *** Values: true = OPTION_YES, false = OPTION_NO
 *** Value description: true = Use realtime mode, false = Do not use realtime mode
 ***
 *** Default: OPTION_YES
 ***/
#define NGOS_BUILD_REALTIME OPTION_YES



/***
 *** Category: General -> Realtime
 *** Name: RAM usage in realtime mode
 ***
 *** Description: How much memory it is allowed to use in realtime mode. \
 ***              The bigger memory usage -> better accuracy / performance.
 ***
 *** Enabled: NGOS_BUILD_REALTIME == OPTION_YES
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_REALTIME_RAM_USAGE_LOWEST, \
 ***         OPTION_REALTIME_RAM_USAGE_LOWER, \
 ***         OPTION_REALTIME_RAM_USAGE_LOW, \
 ***         OPTION_REALTIME_RAM_USAGE_MEDIUM, \
 ***         OPTION_REALTIME_RAM_USAGE_HIGH, \
 ***         OPTION_REALTIME_RAM_USAGE_HIGHER, \
 ***         OPTION_REALTIME_RAM_USAGE_HIGHEST
 ***
 *** Default: OPTION_REALTIME_RAM_USAGE_HIGHEST
 ***/
#define NGOS_BUILD_REALTIME_RAM_USAGE OPTION_REALTIME_RAM_USAGE_HIGHEST



/***
 *** Category: Other -> Kernel relocation
 *** Name: Kernel alignment
 ***
 *** Description: Align kernel location according to this value.
 ***
 *** Type: Integer (Power of 2)
 ***
 *** Minimum: 0x0000000000200000
 *** Maximum: 0x0000000010000000
 ***
 *** Default: 0x0000000000200000
 ***/
#define NGOS_BUILD_KERNEL_ALIGN 0x0000000000200000



/***
 *** Category: Architecture specific -> x86_64
 *** Name: Vectorization mode
 ***
 *** Description: Vectorization allows your machine significantly improve performance, but only the modern CPUs supports the best vectorization modes.
 ***
 *** Enabled: NGOS_BUILD_ARCH == OPTION_ARCH_X86_64
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_X86_64_VECTORIZATION_MODE_SSE2, \
 ***         OPTION_X86_64_VECTORIZATION_MODE_SSE3, \
 ***         OPTION_X86_64_VECTORIZATION_MODE_SSE4, \
 ***         OPTION_X86_64_VECTORIZATION_MODE_AVX, \
 ***         OPTION_X86_64_VECTORIZATION_MODE_AVX2, \
 ***         OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V1, \
 ***         OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V2, \
 ***         OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3
 ***
 *** Default: OPTION_X86_64_VECTORIZATION_MODE_AVX2
 ***/
#define NGOS_BUILD_X86_64_VECTORIZATION_MODE OPTION_X86_64_VECTORIZATION_MODE_AVX2



/***
 *** Category: Architecture specific -> x86_64
 *** Name: Fused Multiply-Add
 ***
 *** Description: The FMA instruction set is an extension to the 128 and 256-bit Streaming SIMD Extensions instructions in the x86 microprocessor instruction set to perform fused multiply-add (FMA) operations. \
 ***              Please note that FMA4 was realized in hardware before FMA3.
 ***
 *** Enabled: NGOS_BUILD_ARCH == OPTION_ARCH_X86_64
 ***
 *** Type: Combobox
 ***
 *** Values: OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE, \
 ***         OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA4, \
 ***         OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3
 ***
 *** Default: OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3
 ***/
#define NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3



// =========================================================================
// BUILD CONFIG PARAMETERS VERIFICATION
// =========================================================================



#if NGOS_BUILD_ARCH < OPTION_ARCH_X86_64 || NGOS_BUILD_ARCH > OPTION_ARCH_X86_64
#error Invalid value for NGOS_BUILD_ARCH parameter
#endif

#if NGOS_BUILD_RELEASE != OPTION_NO && NGOS_BUILD_RELEASE != OPTION_YES
#error Invalid value for NGOS_BUILD_RELEASE parameter
#endif

#if NGOS_BUILD_TEST_MODE != OPTION_NO && NGOS_BUILD_TEST_MODE != OPTION_YES
#error Invalid value for NGOS_BUILD_TEST_MODE parameter
#endif

#if NGOS_BUILD_OPTIMIZATION_LEVEL < OPTION_OPTIMIZATION_LEVEL_0 || NGOS_BUILD_OPTIMIZATION_LEVEL > OPTION_OPTIMIZATION_LEVEL_3
#error Invalid value for NGOS_BUILD_OPTIMIZATION_LEVEL parameter
#endif

#if NGOS_BUILD_KERNEL_COMPRESSION < OPTION_KERNEL_COMPRESSION_NONE || NGOS_BUILD_KERNEL_COMPRESSION > OPTION_KERNEL_COMPRESSION_GZIP
#error Invalid value for NGOS_BUILD_KERNEL_COMPRESSION parameter
#endif

#if NGOS_BUILD_LOG_LEVEL < OPTION_LOG_LEVEL_NONE || NGOS_BUILD_LOG_LEVEL > OPTION_LOG_LEVEL_TRACE
#error Invalid value for NGOS_BUILD_LOG_LEVEL parameter
#endif

#if NGOS_BUILD_COMMON_LOG_LEVEL < OPTION_LOG_LEVEL_INHERIT || NGOS_BUILD_COMMON_LOG_LEVEL > OPTION_LOG_LEVEL_TRACE
#error Invalid value for NGOS_BUILD_COMMON_LOG_LEVEL parameter
#endif

#if NGOS_BUILD_UEFI_LOG_LEVEL < OPTION_LOG_LEVEL_INHERIT || NGOS_BUILD_UEFI_LOG_LEVEL > OPTION_LOG_LEVEL_TRACE
#error Invalid value for NGOS_BUILD_UEFI_LOG_LEVEL parameter
#endif

#if NGOS_BUILD_EARLY_LOG_LEVEL < OPTION_LOG_LEVEL_INHERIT || NGOS_BUILD_EARLY_LOG_LEVEL > OPTION_LOG_LEVEL_TRACE
#error Invalid value for NGOS_BUILD_EARLY_LOG_LEVEL parameter
#endif

#if NGOS_BUILD_REALTIME != OPTION_NO && NGOS_BUILD_REALTIME != OPTION_YES
#error Invalid value for NGOS_BUILD_REALTIME parameter
#endif

#if NGOS_BUILD_REALTIME_RAM_USAGE < OPTION_REALTIME_RAM_USAGE_LOWEST || NGOS_BUILD_REALTIME_RAM_USAGE > OPTION_REALTIME_RAM_USAGE_HIGHEST
#error Invalid value for NGOS_BUILD_REALTIME_RAM_USAGE parameter
#endif

#if NGOS_BUILD_KERNEL_ALIGN < 0x0000000000200000 || NGOS_BUILD_KERNEL_ALIGN > 0x0000000001000000
#error Invalid value for NGOS_BUILD_KERNEL_ALIGN parameter
#endif

#if NGOS_BUILD_X86_64_VECTORIZATION_MODE < OPTION_X86_64_VECTORIZATION_MODE_SSE2 || NGOS_BUILD_X86_64_VECTORIZATION_MODE > OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3
#error Invalid value for NGOS_BUILD_X86_64_VECTORIZATION_MODE parameter
#endif

#if NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD < OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE || NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD > OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3
#error Invalid value for NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD parameter
#endif



#endif // BUILDCONFIG_H
