NGOS
====

0.3. Configuration
------------------

All configuration parameters are defined in [include/buildconfig.h](../../../include/buildconfig.h) file.

You can use the following tools to avoid manually editing of this file:
* [Build config maker](../7.%20Tools/07.%20Build%20config%20maker/README.md)
* [Build config GUI](../7.%20Tools/08.%20Build%20config%20GUI/README.md)

### ========== General parameters ==========

#### ---------- NGOS_BUILD_ARCH ----------

**Description:**<br/>
Target platform architecture.

**Values:**
* OPTION_ARCH_X86_64

**Default:** OPTION_ARCH_X86_64

This option allows to choose the target platform architecture.

#### ---------- NGOS_BUILD_RELEASE ----------

**Description:**<br/>
Build kernel in Release / Debug mode.

**Values:**
* OPTION_YES
* OPTION_NO

**Default:** OPTION_YES

If the value is OPTION_YES then the kernel will be built in Release mode, otherwise in Debug mode.

#### ---------- NGOS_BUILD_TEST_MODE ----------

**Description:**<br/>
Build kernel with including tests.

**Values:**
* OPTION_YES
* OPTION_NO

**Default:** OPTION_NO

If the value is OPTION_YES then the kernel will be built with tests, otherwise without tests.

#### ---------- NGOS_BUILD_KERNEL_COMPRESSION ----------

**Description:**<br/>
Selected type of kernel compression.

**Values:**
* OPTION_KERNEL_COMPRESSION_NONE
* OPTION_KERNEL_COMPRESSION_XZ
* OPTION_KERNEL_COMPRESSION_GZIP

**Default:** OPTION_KERNEL_COMPRESSION_XZ

This option can determine compression algorithm for the included kernel or installer image.

#### ---------- NGOS_BUILD_5_LEVEL_PAGING ----------

**Description:**<br/>
Build kernel with 5 level paging.

**Values:**
* OPTION_YES
* OPTION_NO

**Default:** OPTION_NO

If the value is OPTION_YES then the kernel will be built with 5 level paging, otherwise with 4 level paging.

#### ---------- NGOS_BUILD_LOG_LEVEL ----------

**Description:**<br/>
Set the general level of logging.

**Values:**
* OPTION_LOG_LEVEL_NONE              - Logging is disabled
* OPTION_LOG_LEVEL_FATAL             - Log fatal messages only
* OPTION_LOG_LEVEL_CRITICAL          - Log critical and fatal messages
* OPTION_LOG_LEVEL_ERROR             - Log error and more critical messages
* OPTION_LOG_LEVEL_WARNING           - Log warning and more critical messages
* OPTION_LOG_LEVEL_INFO              - Log info and more critical messages
* OPTION_LOG_LEVEL_DEBUG             - Log debug and more critical messages
* OPTION_LOG_LEVEL_VERBOSE           - Log verbose and more critical messages
* OPTION_LOG_LEVEL_VERY_VERBOSE      - Log very verbose and more critical messages
* OPTION_LOG_LEVEL_VERY_VERY_VERBOSE - Log as much as possible
* OPTION_LOG_LEVEL_TRACE             - Log as much as possible + log each function call

**Default:** OPTION_LOG_LEVEL_DEBUG

It is the most general logging level that can be inherited by logging levels below.

#### ---------- NGOS_BUILD_COMMON_LOG_LEVEL ----------

**Description:**<br/>
Set level of logging for common code.

**Values:**
* OPTION_LOG_LEVEL_INHERIT           - Log level is inherited from General log level
* OPTION_LOG_LEVEL_NONE              - Logging is disabled
* OPTION_LOG_LEVEL_FATAL             - Log fatal messages only
* OPTION_LOG_LEVEL_CRITICAL          - Log critical and fatal messages
* OPTION_LOG_LEVEL_ERROR             - Log error and more critical messages
* OPTION_LOG_LEVEL_WARNING           - Log warning and more critical messages
* OPTION_LOG_LEVEL_INFO              - Log info and more critical messages
* OPTION_LOG_LEVEL_DEBUG             - Log debug and more critical messages
* OPTION_LOG_LEVEL_VERBOSE           - Log verbose and more critical messages
* OPTION_LOG_LEVEL_VERY_VERBOSE      - Log very verbose and more critical messages
* OPTION_LOG_LEVEL_VERY_VERY_VERBOSE - Log as much as possible
* OPTION_LOG_LEVEL_TRACE             - Log as much as possible + log each function call

**Default:** OPTION_LOG_LEVEL_INHERIT

Logging level for some common stuff like memory management, string operations and so on.

#### ---------- NGOS_BUILD_UEFI_LOG_LEVEL ----------

**Description:**<br/>
Set the UEFI level of logging.

**Values:**
* OPTION_LOG_LEVEL_INHERIT           - Log level is inherited from General log level
* OPTION_LOG_LEVEL_NONE              - Logging is disabled
* OPTION_LOG_LEVEL_FATAL             - Log fatal messages only
* OPTION_LOG_LEVEL_CRITICAL          - Log critical and fatal messages
* OPTION_LOG_LEVEL_ERROR             - Log error and more critical messages
* OPTION_LOG_LEVEL_WARNING           - Log warning and more critical messages
* OPTION_LOG_LEVEL_INFO              - Log info and more critical messages
* OPTION_LOG_LEVEL_DEBUG             - Log debug and more critical messages
* OPTION_LOG_LEVEL_VERBOSE           - Log verbose and more critical messages
* OPTION_LOG_LEVEL_VERY_VERBOSE      - Log very verbose and more critical messages
* OPTION_LOG_LEVEL_VERY_VERY_VERBOSE - Log as much as possible
* OPTION_LOG_LEVEL_TRACE             - Log as much as possible + log each function call

**Default:** OPTION_LOG_LEVEL_INHERIT

This logging level take a place while we are still in UEFI before calling UEFI::exitBootServices() and jumping to relocated kernel.

#### ---------- NGOS_BUILD_EARLY_LOG_LEVEL ----------

**Description:**<br/>
Set the early level of logging.

**Values:**
* OPTION_LOG_LEVEL_INHERIT           - Log level is inherited from General log level
* OPTION_LOG_LEVEL_NONE              - Logging is disabled
* OPTION_LOG_LEVEL_FATAL             - Log fatal messages only
* OPTION_LOG_LEVEL_CRITICAL          - Log critical and fatal messages
* OPTION_LOG_LEVEL_ERROR             - Log error and more critical messages
* OPTION_LOG_LEVEL_WARNING           - Log warning and more critical messages
* OPTION_LOG_LEVEL_INFO              - Log info and more critical messages
* OPTION_LOG_LEVEL_DEBUG             - Log debug and more critical messages
* OPTION_LOG_LEVEL_VERBOSE           - Log verbose and more critical messages
* OPTION_LOG_LEVEL_VERY_VERBOSE      - Log very verbose and more critical messages
* OPTION_LOG_LEVEL_VERY_VERY_VERBOSE - Log as much as possible
* OPTION_LOG_LEVEL_TRACE             - Log as much as possible + log each function call

**Default:** OPTION_LOG_LEVEL_INHERIT

This level of logging is named as early because it is active after UEFI at the very beginning of kernel.

### ========== Realtime parameters ==========

#### ---------- NGOS_BUILD_REALTIME ----------

**Description:**<br/>
Build kernel in realtime mode.<br/>
In this mode some functions works extremely fast, but it takes some memory.

**Values:**
* OPTION_YES
* OPTION_NO

**Default:** OPTION_NO

If the value is OPTION_YES then the kernel will be built in realtime mode, otherwise in non-realtime mode.<br/>
Realtime feature allows to some functions (such as sin, cos, ln...) to use a list of predefined results with the guaranteed accuracy.<br/>
It makes such functions work extremely fast, but it takes some memory to keep the results.<br/>
This feature also means that we will gonna use arrays instead of QHash or QMap if possible.

#### ---------- NGOS_BUILD_REALTIME_RAM_USAGE ----------

**Description:**<br/>
How much memory it is allowed to use in realtime mode.<br/>
The bigger memory usage -> better accuracy / performance.

**Values:**
* OPTION_REALTIME_RAM_USAGE_LOWEST  - Use the lowest amount of memory to enable realtime with enough accuracy / performance
* OPTION_REALTIME_RAM_USAGE_LOWER   - Use a little bit more memory to increase accuracy / performance in realtime
* OPTION_REALTIME_RAM_USAGE_LOW     - Use a little bit more memory to increase accuracy / performance in realtime
* OPTION_REALTIME_RAM_USAGE_MEDIUM  - Use a little bit more memory to increase accuracy / performance in realtime
* OPTION_REALTIME_RAM_USAGE_HIGH    - Use a little bit more memory to increase accuracy / performance in realtime
* OPTION_REALTIME_RAM_USAGE_HIGHER  - Use a little bit more memory to increase accuracy / performance in realtime
* OPTION_REALTIME_RAM_USAGE_HIGHEST - Use the highest amount of memory to enable realtime with the best accuracy / performance

**Default:** OPTION_REALTIME_RAM_USAGE_HIGHEST

This parameter determine how much memory it is allowed to use in order to provide more accurate results.

### ========== Kernel relocation parameters ==========

#### ---------- NGOS_BUILD_KERNEL_ALIGN ----------

**Description:**<br/>
Align kernel location according to this value.

**Values:**<br/>
Integer (Power of 2)

**Minimum:** 0x0000000000000001<br/>
**Maximum:** 0x0000000080000000

**Default:** 0x0000000001000000

This parameter is used to keep the kernel location aligned.

### ========== Architecture specific parameters ==========

#### ---------- NGOS_BUILD_X86_64_VECTORIZATION_MODE ----------

**Description:**<br/>
Vectorization allows your machine significantly improve performance, but only the modern CPUs supports the best vectorization modes.

**Values:**
* OPTION_X86_64_VECTORIZATION_MODE_NONE       - Compile kernel without vectorization
* OPTION_X86_64_VECTORIZATION_MODE_SSE        - Compile kernel with SSE vectorization
* OPTION_X86_64_VECTORIZATION_MODE_SSE2       - Compile kernel with SSE2 vectorization
* OPTION_X86_64_VECTORIZATION_MODE_SSE3       - Compile kernel with SSE3 vectorization
* OPTION_X86_64_VECTORIZATION_MODE_SSE4       - Compile kernel with SSE4 vectorization
* OPTION_X86_64_VECTORIZATION_MODE_AVX        - Compile kernel with AVX vectorization
* OPTION_X86_64_VECTORIZATION_MODE_AVX2       - Compile kernel with AVX2 vectorization
* OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V1 - Compile kernel with AVX-512 vectorization (F + CD + ER + PF)
* OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V2 - Compile kernel with AVX-512 vectorization (F + CD + BW + DQ + VL)
* OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3 - Compile kernel with AVX-512 vectorization (F + CD + BW + DQ + VL + IFMA + VBMI)

**Default:** OPTION_X86_64_VECTORIZATION_MODE_AVX2

#### ---------- NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD ----------

**Description:**<br/>
The FMA instruction set is an extension to the 128 and 256-bit Streaming SIMD Extensions instructions in the x86 microprocessor instruction set to perform fused multiply-add (FMA) operations.<br/>
Please note that FMA4 was realized in hardware before FMA3.

**Values:**
* OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE - Compile kernel without Fused Multiply-Add support
* OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA4 - Compile kernel with Fused Multiply-Add 4 (4 means with 4 operands)
* OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3 - Compile kernel with Fused Multiply-Add 3 (3 means with 3 operands)

**Default:** OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3
