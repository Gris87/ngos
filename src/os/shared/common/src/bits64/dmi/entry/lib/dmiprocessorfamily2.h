#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY2_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY2_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiProcessorFamily2: u16
{
    NONE                                  = 0,
    OTHER                                 = 0x0001,
    UNKNOWN                               = 0x0002,
    _8086                                 = 0x0003,
    _80286                                = 0x0004,
    INTEL_386                             = 0x0005,
    INTEL_486                             = 0x0006,
    _8087                                 = 0x0007,
    _80287                                = 0x0008,
    _80387                                = 0x0009,
    _80487                                = 0x000A,
    PENTIUM                               = 0x000B,
    PENTIUM_PRO                           = 0x000C,
    PENTIUM_II                            = 0x000D,
    PENTIUM_MMX                           = 0x000E,
    CELERON                               = 0x000F,
    PENTIUM_IIXEON                        = 0x0010,
    PENTIUM_III                           = 0x0011,
    M1                                    = 0x0012,
    M2                                    = 0x0013,
    INTEL_CELERON_M                       = 0x0014,
    INTEL_PENTIUM_4_HT                    = 0x0015,
    AMD_DURON                             = 0x0018,
    K5                                    = 0x0019,
    K6                                    = 0x001A,
    K6_2                                  = 0x001B,
    K6_3                                  = 0x001C,
    AMD_ATHLON                            = 0x001D,
    AMD_29000                             = 0x001E,
    K6_2_PLUS                             = 0x001F,
    POWER_PC                              = 0x0020,
    POWER_PC_601                          = 0x0021,
    POWER_PC_603                          = 0x0022,
    POWER_PC_603_PLUS                     = 0x0023,
    POWER_PC_604                          = 0x0024,
    POWER_PC_620                          = 0x0025,
    POWER_PCX_704                         = 0x0026,
    POWER_PC_750                          = 0x0027,
    INTEL_CORE_DUO                        = 0x0028,
    INTEL_CORE_DUO_MOBILE                 = 0x0029,
    INTEL_CORE_SOLO_MOBILE                = 0x002A,
    INTEL_ATOM                            = 0x002B,
    INTEL_CORE_M                          = 0x002C,
    INTEL_COREM_3                         = 0x002D,
    INTEL_COREM_5                         = 0x002E,
    INTEL_COREM_7                         = 0x002F,
    ALPHA                                 = 0x0030,
    ALPHA_21064                           = 0x0031,
    ALPHA_21066                           = 0x0032,
    ALPHA_21164                           = 0x0033,
    ALPHA_21164_PC                        = 0x0034,
    ALPHA_21164A                          = 0x0035,
    ALPHA_21264                           = 0x0036,
    ALPHA_21364                           = 0x0037,
    AMD_TURION_IIULTRA_DUAL_CORE_MOBILE_M = 0x0038,
    AMD_TURION_IIDUAL_CORE_MOBILE_M       = 0x0039,
    AMD_ATHLON_IIDUAL_CORE_M              = 0x003A,
    AMD_OPTERON_6100_SERIES               = 0x003B,
    AMD_OPTERON_4100_SERIES               = 0x003C,
    AMD_OPTERON_6200_SERIES               = 0x003D,
    AMD_OPTERON_4200_SERIES               = 0x003E,
    AMD_FX_SERIES                         = 0x003F,
    MIPS                                  = 0x0040,
    MIPSR_4000                            = 0x0041,
    MIPSR_4200                            = 0x0042,
    MIPSR_4400                            = 0x0043,
    MIPSR_4600                            = 0x0044,
    MIPSR_10000                           = 0x0045,
    AMD_CSERIES                           = 0x0046,
    AMD_ESERIES                           = 0x0047,
    AMD_ASERIES                           = 0x0048,
    AMD_GSERIES                           = 0x0049,
    AMD_ZSERIES                           = 0x004A,
    AMD_RSERIES                           = 0x004B,
    AMD_OPTERON_4300                      = 0x004C,
    AMD_OPTERON_6300                      = 0x004D,
    AMD_OPTERON_3300                      = 0x004E,
    AMD_FIRE_PRO_SERIES                   = 0x004F,
    SPARC                                 = 0x0050,
    SUPER_SPARC                           = 0x0051,
    MICRO_SPARC_II                        = 0x0052,
    MICRO_SPARC_IIEP                      = 0x0053,
    ULTRA_SPARC                           = 0x0054,
    ULTRA_SPARC_II                        = 0x0055,
    ULTRA_SPARC_III                       = 0x0056,
    ULTRA_SPARC_III_2                     = 0x0057,
    ULTRA_SPARC_IIII                      = 0x0058,
    _68040                                = 0x0060,
    _68XXX                                = 0x0061,
    _68000                                = 0x0062,
    _68010                                = 0x0063,
    _68020                                = 0x0064,
    _68030                                = 0x0065,
    AMD_ATHLON_X_4_QUAD_CORE              = 0x0066,
    AMD_OPTERON_X_1000_SERIES             = 0x0067,
    AMD_OPTERON_X_2000_SERIES             = 0x0068,
    AMD_OPTERON_ASERIES                   = 0x0069,
    AMD_OPTERON_X_3000_SERIES             = 0x006A,
    AMD_ZEN                               = 0x006B,
    HOBBIT                                = 0x0070,
    CRUSOE_TM_5000                        = 0x0078,
    CRUSOE_TM_3000                        = 0x0079,
    EFFICEON_TM_8000                      = 0x007A,
    WEITEK                                = 0x0080,
    ITANIUM                               = 0x0082,
    AMD_ATHLON_64                         = 0x0083,
    AMD_OPTERON                           = 0x0084,
    AMD_SEMPRON                           = 0x0085,
    AMD_TURION_64_MOBILE                  = 0x0086,
    DUAL_CORE_AMD_OPTERON                 = 0x0087,
    AMD_ATHLON_64_X_2_DUAL_CORE           = 0x0088,
    AMD_TURION_64_X_2_MOBILE              = 0x0089,
    QUAD_CORE_AMD_OPTERON                 = 0x008A,
    THIRD_GENERATION_AMD_OPTERON          = 0x008B,
    AMD_PHENOM_FX_QUAD_CORE               = 0x008C,
    AMD_PHENOM_X_4_QUAD_CORE              = 0x008D,
    AMD_PHENOM_X_2_DUAL_CORE              = 0x008E,
    AMD_ATHLON_X_2_DUAL_CORE              = 0x008F,
    PARISC                                = 0x0090,
    PA_RISC_8500                          = 0x0091,
    PA_RISC_8000                          = 0x0092,
    PA_RISC_7300_LC                       = 0x0093,
    PA_RISC_7200                          = 0x0094,
    PA_RISC_7100_LC                       = 0x0095,
    PA_RISC_7100                          = 0x0096,
    V30                                   = 0x00A0,
    QUAD_CORE_INTEL_XEON_3200_SERIES      = 0x00A1,
    DUAL_CORE_INTEL_XEON_3000_SERIES      = 0x00A2,
    QUAD_CORE_INTEL_XEON_5300_SERIES      = 0x00A3,
    DUAL_CORE_INTEL_XEON_5100_SERIES      = 0x00A4,
    DUAL_CORE_INTEL_XEON_5000_SERIES      = 0x00A5,
    DUAL_CORE_INTEL_XEON_LV               = 0x00A6,
    DUAL_CORE_INTEL_XEON_ULV              = 0x00A7,
    DUAL_CORE_INTEL_XEON_7100_SERIES      = 0x00A8,
    QUAD_CORE_INTEL_XEON_5400_SERIES      = 0x00A9,
    QUAD_CORE_INTEL_XEON                  = 0x00AA,
    DUAL_CORE_INTEL_XEON_5200_SERIES      = 0x00AB,
    DUAL_CORE_INTEL_XEON_7200_SERIES      = 0x00AC,
    QUAD_CORE_INTEL_XEON_7300_SERIES      = 0x00AD,
    QUAD_CORE_INTEL_XEON_7400_SERIES      = 0x00AE,
    MULTI_CORE_INTEL_XEON_7400_SERIES     = 0x00AF,
    PENTIUM_IIIXEON                       = 0x00B0,
    PENTIUM_IIISPEED_STEP                 = 0x00B1,
    PENTIUM_4                             = 0x00B2,
    INTEL_XEON                            = 0x00B3,
    AS_400                                = 0x00B4,
    INTEL_XEON_MP                         = 0x00B5,
    AMDATHLON_XP                          = 0x00B6,
    AMDATHLON_MP                          = 0x00B7,
    INTEL_ITANIUM_2                       = 0x00B8,
    INTEL_PENTIUM_M                       = 0x00B9,
    INTEL_CELERON_D                       = 0x00BA,
    INTEL_PENTIUM_D                       = 0x00BB,
    INTEL_PENTIUM_EX                      = 0x00BC,
    INTEL_CORE_SOLO                       = 0x00BD,
    RESERVED                              = 0x00BE,
    INTEL_CORE_2                          = 0x00BF,
    INTEL_CORE_2_SOLO                     = 0x00C0,
    INTEL_CORE_2_EXTREME                  = 0x00C1,
    INTEL_CORE_2_QUAD                     = 0x00C2,
    INTEL_CORE_2_EXTREME_MOBILE           = 0x00C3,
    INTEL_CORE_2_DUO_MOBILE               = 0x00C4,
    INTEL_CORE_2_SOLO_MOBILE              = 0x00C5,
    INTEL_CORE_I_7                        = 0x00C6,
    DUAL_CORE_INTEL_CELERON               = 0x00C7,
    IBM_390                               = 0x00C8,
    G4                                    = 0x00C9,
    G5                                    = 0x00CA,
    G6                                    = 0x00CB,
    Z_ARCHITECTURE                        = 0x00CC,
    INTEL_CORE_I_5                        = 0x00CD,
    INTEL_CORE_I_3                        = 0x00CE,
    INTEL_CORE_I_9                        = 0x00CF,
    VIA_C7_M                              = 0x00D2,
    VIA_C7_D                              = 0x00D3,
    VIA_C7                                = 0x00D4,
    VIA_EDEN                              = 0x00D5,
    MULTI_CORE_INTEL_XEON                 = 0x00D6,
    DUAL_CORE_INTEL_XEON_3_SERIES         = 0x00D7,
    QUAD_CORE_INTEL_XEON_3_SERIES         = 0x00D8,
    VIA_NANO                              = 0x00D9,
    DUAL_CORE_INTEL_XEON_5_SERIES         = 0x00DA,
    QUAD_CORE_INTEL_XEON_5_SERIES         = 0x00DB,
    DUAL_CORE_INTEL_XEON_7_SERIES         = 0x00DD,
    QUAD_CORE_INTEL_XEON_7_SERIES         = 0x00DE,
    MULTI_CORE_INTEL_XEON_7_SERIES        = 0x00DF,
    MULTI_CORE_INTEL_XEON_3400_SERIES     = 0x00E0,
    AMD_OPTERON_3000_SERIES               = 0x00E4,
    AMD_SEMPRON_II                        = 0x00E5,
    EMBEDDED_AMD_OPTERON_QUAD_CORE        = 0x00E6,
    AMD_PHENOM_TRIPLE_CORE                = 0x00E7,
    AMD_TURION_ULTRA_DUAL_CORE_MOBILE     = 0x00E8,
    AMD_TURION_DUAL_CORE_MOBILE           = 0x00E9,
    AMD_ATHLON_DUAL_CORE                  = 0x00EA,
    AMD_SEMPRON_SI                        = 0x00EB,
    AMD_PHENOM_II                         = 0x00EC,
    AMD_ATHLON_II                         = 0x00ED,
    SIX_CORE_AMD_OPTERON                  = 0x00EE,
    AMD_SEMPRON_M                         = 0x00EF,
    I860                                  = 0x00FA,
    I960                                  = 0x00FB,
    INDICATOR_FAMILY_2                    = 0x00FE,
    RESERVED_1                            = 0x00FF,
    ARM_V7                                = 0x0100,
    ARM_V8                                = 0x0101,
    SH3                                   = 0x0104,
    SH4                                   = 0x0105,
    ARM                                   = 0x0118,
    STRONG_ARM                            = 0x0119,
    _6_X86                                = 0x012C,
    MEDIA_GX                              = 0x012D,
    MII                                   = 0x012E,
    WIN_CHIP                              = 0x0140,
    DSP                                   = 0x015E,
    VIDEO_PROCESSOR                       = 0x01F4
};



inline const char8* enumToString(DmiProcessorFamily2 family2) // TEST: NO
{
    // COMMON_LT((" | family2 = %u", family2)); // Commented to avoid bad looking logs



    switch (family2)
    {
        case DmiProcessorFamily2::NONE:                                  return "NONE";
        case DmiProcessorFamily2::OTHER:                                 return "OTHER";
        case DmiProcessorFamily2::UNKNOWN:                               return "UNKNOWN";
        case DmiProcessorFamily2::_8086:                                 return "_8086";
        case DmiProcessorFamily2::_80286:                                return "_80286";
        case DmiProcessorFamily2::INTEL_386:                             return "INTEL_386";
        case DmiProcessorFamily2::INTEL_486:                             return "INTEL_486";
        case DmiProcessorFamily2::_8087:                                 return "_8087";
        case DmiProcessorFamily2::_80287:                                return "_80287";
        case DmiProcessorFamily2::_80387:                                return "_80387";
        case DmiProcessorFamily2::_80487:                                return "_80487";
        case DmiProcessorFamily2::PENTIUM:                               return "PENTIUM";
        case DmiProcessorFamily2::PENTIUM_PRO:                           return "PENTIUM_PRO";
        case DmiProcessorFamily2::PENTIUM_II:                            return "PENTIUM_II";
        case DmiProcessorFamily2::PENTIUM_MMX:                           return "PENTIUM_MMX";
        case DmiProcessorFamily2::CELERON:                               return "CELERON";
        case DmiProcessorFamily2::PENTIUM_IIXEON:                        return "PENTIUM_IIXEON";
        case DmiProcessorFamily2::PENTIUM_III:                           return "PENTIUM_III";
        case DmiProcessorFamily2::M1:                                    return "M1";
        case DmiProcessorFamily2::M2:                                    return "M2";
        case DmiProcessorFamily2::INTEL_CELERON_M:                       return "INTEL_CELERON_M";
        case DmiProcessorFamily2::INTEL_PENTIUM_4_HT:                    return "INTEL_PENTIUM_4_HT";
        case DmiProcessorFamily2::AMD_DURON:                             return "AMD_DURON";
        case DmiProcessorFamily2::K5:                                    return "K5";
        case DmiProcessorFamily2::K6:                                    return "K6";
        case DmiProcessorFamily2::K6_2:                                  return "K6_2";
        case DmiProcessorFamily2::K6_3:                                  return "K6_3";
        case DmiProcessorFamily2::AMD_ATHLON:                            return "AMD_ATHLON";
        case DmiProcessorFamily2::AMD_29000:                             return "AMD_29000";
        case DmiProcessorFamily2::K6_2_PLUS:                             return "K6_2_PLUS";
        case DmiProcessorFamily2::POWER_PC:                              return "POWER_PC";
        case DmiProcessorFamily2::POWER_PC_601:                          return "POWER_PC_601";
        case DmiProcessorFamily2::POWER_PC_603:                          return "POWER_PC_603";
        case DmiProcessorFamily2::POWER_PC_603_PLUS:                     return "POWER_PC_603_PLUS";
        case DmiProcessorFamily2::POWER_PC_604:                          return "POWER_PC_604";
        case DmiProcessorFamily2::POWER_PC_620:                          return "POWER_PC_620";
        case DmiProcessorFamily2::POWER_PCX_704:                         return "POWER_PCX_704";
        case DmiProcessorFamily2::POWER_PC_750:                          return "POWER_PC_750";
        case DmiProcessorFamily2::INTEL_CORE_DUO:                        return "INTEL_CORE_DUO";
        case DmiProcessorFamily2::INTEL_CORE_DUO_MOBILE:                 return "INTEL_CORE_DUO_MOBILE";
        case DmiProcessorFamily2::INTEL_CORE_SOLO_MOBILE:                return "INTEL_CORE_SOLO_MOBILE";
        case DmiProcessorFamily2::INTEL_ATOM:                            return "INTEL_ATOM";
        case DmiProcessorFamily2::INTEL_CORE_M:                          return "INTEL_CORE_M";
        case DmiProcessorFamily2::INTEL_COREM_3:                         return "INTEL_COREM_3";
        case DmiProcessorFamily2::INTEL_COREM_5:                         return "INTEL_COREM_5";
        case DmiProcessorFamily2::INTEL_COREM_7:                         return "INTEL_COREM_7";
        case DmiProcessorFamily2::ALPHA:                                 return "ALPHA";
        case DmiProcessorFamily2::ALPHA_21064:                           return "ALPHA_21064";
        case DmiProcessorFamily2::ALPHA_21066:                           return "ALPHA_21066";
        case DmiProcessorFamily2::ALPHA_21164:                           return "ALPHA_21164";
        case DmiProcessorFamily2::ALPHA_21164_PC:                        return "ALPHA_21164_PC";
        case DmiProcessorFamily2::ALPHA_21164A:                          return "ALPHA_21164A";
        case DmiProcessorFamily2::ALPHA_21264:                           return "ALPHA_21264";
        case DmiProcessorFamily2::ALPHA_21364:                           return "ALPHA_21364";
        case DmiProcessorFamily2::AMD_TURION_IIULTRA_DUAL_CORE_MOBILE_M: return "AMD_TURION_IIULTRA_DUAL_CORE_MOBILE_M";
        case DmiProcessorFamily2::AMD_TURION_IIDUAL_CORE_MOBILE_M:       return "AMD_TURION_IIDUAL_CORE_MOBILE_M";
        case DmiProcessorFamily2::AMD_ATHLON_IIDUAL_CORE_M:              return "AMD_ATHLON_IIDUAL_CORE_M";
        case DmiProcessorFamily2::AMD_OPTERON_6100_SERIES:               return "AMD_OPTERON_6100_SERIES";
        case DmiProcessorFamily2::AMD_OPTERON_4100_SERIES:               return "AMD_OPTERON_4100_SERIES";
        case DmiProcessorFamily2::AMD_OPTERON_6200_SERIES:               return "AMD_OPTERON_6200_SERIES";
        case DmiProcessorFamily2::AMD_OPTERON_4200_SERIES:               return "AMD_OPTERON_4200_SERIES";
        case DmiProcessorFamily2::AMD_FX_SERIES:                         return "AMD_FX_SERIES";
        case DmiProcessorFamily2::MIPS:                                  return "MIPS";
        case DmiProcessorFamily2::MIPSR_4000:                            return "MIPSR_4000";
        case DmiProcessorFamily2::MIPSR_4200:                            return "MIPSR_4200";
        case DmiProcessorFamily2::MIPSR_4400:                            return "MIPSR_4400";
        case DmiProcessorFamily2::MIPSR_4600:                            return "MIPSR_4600";
        case DmiProcessorFamily2::MIPSR_10000:                           return "MIPSR_10000";
        case DmiProcessorFamily2::AMD_CSERIES:                           return "AMD_CSERIES";
        case DmiProcessorFamily2::AMD_ESERIES:                           return "AMD_ESERIES";
        case DmiProcessorFamily2::AMD_ASERIES:                           return "AMD_ASERIES";
        case DmiProcessorFamily2::AMD_GSERIES:                           return "AMD_GSERIES";
        case DmiProcessorFamily2::AMD_ZSERIES:                           return "AMD_ZSERIES";
        case DmiProcessorFamily2::AMD_RSERIES:                           return "AMD_RSERIES";
        case DmiProcessorFamily2::AMD_OPTERON_4300:                      return "AMD_OPTERON_4300";
        case DmiProcessorFamily2::AMD_OPTERON_6300:                      return "AMD_OPTERON_6300";
        case DmiProcessorFamily2::AMD_OPTERON_3300:                      return "AMD_OPTERON_3300";
        case DmiProcessorFamily2::AMD_FIRE_PRO_SERIES:                   return "AMD_FIRE_PRO_SERIES";
        case DmiProcessorFamily2::SPARC:                                 return "SPARC";
        case DmiProcessorFamily2::SUPER_SPARC:                           return "SUPER_SPARC";
        case DmiProcessorFamily2::MICRO_SPARC_II:                        return "MICRO_SPARC_II";
        case DmiProcessorFamily2::MICRO_SPARC_IIEP:                      return "MICRO_SPARC_IIEP";
        case DmiProcessorFamily2::ULTRA_SPARC:                           return "ULTRA_SPARC";
        case DmiProcessorFamily2::ULTRA_SPARC_II:                        return "ULTRA_SPARC_II";
        case DmiProcessorFamily2::ULTRA_SPARC_III:                       return "ULTRA_SPARC_III";
        case DmiProcessorFamily2::ULTRA_SPARC_III_2:                     return "ULTRA_SPARC_III_2";
        case DmiProcessorFamily2::ULTRA_SPARC_IIII:                      return "ULTRA_SPARC_IIII";
        case DmiProcessorFamily2::_68040:                                return "_68040";
        case DmiProcessorFamily2::_68XXX:                                return "_68XXX";
        case DmiProcessorFamily2::_68000:                                return "_68000";
        case DmiProcessorFamily2::_68010:                                return "_68010";
        case DmiProcessorFamily2::_68020:                                return "_68020";
        case DmiProcessorFamily2::_68030:                                return "_68030";
        case DmiProcessorFamily2::AMD_ATHLON_X_4_QUAD_CORE:              return "AMD_ATHLON_X_4_QUAD_CORE";
        case DmiProcessorFamily2::AMD_OPTERON_X_1000_SERIES:             return "AMD_OPTERON_X_1000_SERIES";
        case DmiProcessorFamily2::AMD_OPTERON_X_2000_SERIES:             return "AMD_OPTERON_X_2000_SERIES";
        case DmiProcessorFamily2::AMD_OPTERON_ASERIES:                   return "AMD_OPTERON_ASERIES";
        case DmiProcessorFamily2::AMD_OPTERON_X_3000_SERIES:             return "AMD_OPTERON_X_3000_SERIES";
        case DmiProcessorFamily2::AMD_ZEN:                               return "AMD_ZEN";
        case DmiProcessorFamily2::HOBBIT:                                return "HOBBIT";
        case DmiProcessorFamily2::CRUSOE_TM_5000:                        return "CRUSOE_TM_5000";
        case DmiProcessorFamily2::CRUSOE_TM_3000:                        return "CRUSOE_TM_3000";
        case DmiProcessorFamily2::EFFICEON_TM_8000:                      return "EFFICEON_TM_8000";
        case DmiProcessorFamily2::WEITEK:                                return "WEITEK";
        case DmiProcessorFamily2::ITANIUM:                               return "ITANIUM";
        case DmiProcessorFamily2::AMD_ATHLON_64:                         return "AMD_ATHLON_64";
        case DmiProcessorFamily2::AMD_OPTERON:                           return "AMD_OPTERON";
        case DmiProcessorFamily2::AMD_SEMPRON:                           return "AMD_SEMPRON";
        case DmiProcessorFamily2::AMD_TURION_64_MOBILE:                  return "AMD_TURION_64_MOBILE";
        case DmiProcessorFamily2::DUAL_CORE_AMD_OPTERON:                 return "DUAL_CORE_AMD_OPTERON";
        case DmiProcessorFamily2::AMD_ATHLON_64_X_2_DUAL_CORE:           return "AMD_ATHLON_64_X_2_DUAL_CORE";
        case DmiProcessorFamily2::AMD_TURION_64_X_2_MOBILE:              return "AMD_TURION_64_X_2_MOBILE";
        case DmiProcessorFamily2::QUAD_CORE_AMD_OPTERON:                 return "QUAD_CORE_AMD_OPTERON";
        case DmiProcessorFamily2::THIRD_GENERATION_AMD_OPTERON:          return "THIRD_GENERATION_AMD_OPTERON";
        case DmiProcessorFamily2::AMD_PHENOM_FX_QUAD_CORE:               return "AMD_PHENOM_FX_QUAD_CORE";
        case DmiProcessorFamily2::AMD_PHENOM_X_4_QUAD_CORE:              return "AMD_PHENOM_X_4_QUAD_CORE";
        case DmiProcessorFamily2::AMD_PHENOM_X_2_DUAL_CORE:              return "AMD_PHENOM_X_2_DUAL_CORE";
        case DmiProcessorFamily2::AMD_ATHLON_X_2_DUAL_CORE:              return "AMD_ATHLON_X_2_DUAL_CORE";
        case DmiProcessorFamily2::PARISC:                                return "PARISC";
        case DmiProcessorFamily2::PA_RISC_8500:                          return "PA_RISC_8500";
        case DmiProcessorFamily2::PA_RISC_8000:                          return "PA_RISC_8000";
        case DmiProcessorFamily2::PA_RISC_7300_LC:                       return "PA_RISC_7300_LC";
        case DmiProcessorFamily2::PA_RISC_7200:                          return "PA_RISC_7200";
        case DmiProcessorFamily2::PA_RISC_7100_LC:                       return "PA_RISC_7100_LC";
        case DmiProcessorFamily2::PA_RISC_7100:                          return "PA_RISC_7100";
        case DmiProcessorFamily2::V30:                                   return "V30";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON_3200_SERIES:      return "QUAD_CORE_INTEL_XEON_3200_SERIES";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_3000_SERIES:      return "DUAL_CORE_INTEL_XEON_3000_SERIES";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON_5300_SERIES:      return "QUAD_CORE_INTEL_XEON_5300_SERIES";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_5100_SERIES:      return "DUAL_CORE_INTEL_XEON_5100_SERIES";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_5000_SERIES:      return "DUAL_CORE_INTEL_XEON_5000_SERIES";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_LV:               return "DUAL_CORE_INTEL_XEON_LV";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_ULV:              return "DUAL_CORE_INTEL_XEON_ULV";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_7100_SERIES:      return "DUAL_CORE_INTEL_XEON_7100_SERIES";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON_5400_SERIES:      return "QUAD_CORE_INTEL_XEON_5400_SERIES";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON:                  return "QUAD_CORE_INTEL_XEON";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_5200_SERIES:      return "DUAL_CORE_INTEL_XEON_5200_SERIES";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_7200_SERIES:      return "DUAL_CORE_INTEL_XEON_7200_SERIES";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON_7300_SERIES:      return "QUAD_CORE_INTEL_XEON_7300_SERIES";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON_7400_SERIES:      return "QUAD_CORE_INTEL_XEON_7400_SERIES";
        case DmiProcessorFamily2::MULTI_CORE_INTEL_XEON_7400_SERIES:     return "MULTI_CORE_INTEL_XEON_7400_SERIES";
        case DmiProcessorFamily2::PENTIUM_IIIXEON:                       return "PENTIUM_IIIXEON";
        case DmiProcessorFamily2::PENTIUM_IIISPEED_STEP:                 return "PENTIUM_IIISPEED_STEP";
        case DmiProcessorFamily2::PENTIUM_4:                             return "PENTIUM_4";
        case DmiProcessorFamily2::INTEL_XEON:                            return "INTEL_XEON";
        case DmiProcessorFamily2::AS_400:                                return "AS_400";
        case DmiProcessorFamily2::INTEL_XEON_MP:                         return "INTEL_XEON_MP";
        case DmiProcessorFamily2::AMDATHLON_XP:                          return "AMDATHLON_XP";
        case DmiProcessorFamily2::AMDATHLON_MP:                          return "AMDATHLON_MP";
        case DmiProcessorFamily2::INTEL_ITANIUM_2:                       return "INTEL_ITANIUM_2";
        case DmiProcessorFamily2::INTEL_PENTIUM_M:                       return "INTEL_PENTIUM_M";
        case DmiProcessorFamily2::INTEL_CELERON_D:                       return "INTEL_CELERON_D";
        case DmiProcessorFamily2::INTEL_PENTIUM_D:                       return "INTEL_PENTIUM_D";
        case DmiProcessorFamily2::INTEL_PENTIUM_EX:                      return "INTEL_PENTIUM_EX";
        case DmiProcessorFamily2::INTEL_CORE_SOLO:                       return "INTEL_CORE_SOLO";
        case DmiProcessorFamily2::RESERVED:                              return "RESERVED";
        case DmiProcessorFamily2::INTEL_CORE_2:                          return "INTEL_CORE_2";
        case DmiProcessorFamily2::INTEL_CORE_2_SOLO:                     return "INTEL_CORE_2_SOLO";
        case DmiProcessorFamily2::INTEL_CORE_2_EXTREME:                  return "INTEL_CORE_2_EXTREME";
        case DmiProcessorFamily2::INTEL_CORE_2_QUAD:                     return "INTEL_CORE_2_QUAD";
        case DmiProcessorFamily2::INTEL_CORE_2_EXTREME_MOBILE:           return "INTEL_CORE_2_EXTREME_MOBILE";
        case DmiProcessorFamily2::INTEL_CORE_2_DUO_MOBILE:               return "INTEL_CORE_2_DUO_MOBILE";
        case DmiProcessorFamily2::INTEL_CORE_2_SOLO_MOBILE:              return "INTEL_CORE_2_SOLO_MOBILE";
        case DmiProcessorFamily2::INTEL_CORE_I_7:                        return "INTEL_CORE_I_7";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_CELERON:               return "DUAL_CORE_INTEL_CELERON";
        case DmiProcessorFamily2::IBM_390:                               return "IBM_390";
        case DmiProcessorFamily2::G4:                                    return "G4";
        case DmiProcessorFamily2::G5:                                    return "G5";
        case DmiProcessorFamily2::G6:                                    return "G6";
        case DmiProcessorFamily2::Z_ARCHITECTURE:                        return "Z_ARCHITECTURE";
        case DmiProcessorFamily2::INTEL_CORE_I_5:                        return "INTEL_CORE_I_5";
        case DmiProcessorFamily2::INTEL_CORE_I_3:                        return "INTEL_CORE_I_3";
        case DmiProcessorFamily2::INTEL_CORE_I_9:                        return "INTEL_CORE_I_9";
        case DmiProcessorFamily2::VIA_C7_M:                              return "VIA_C7_M";
        case DmiProcessorFamily2::VIA_C7_D:                              return "VIA_C7_D";
        case DmiProcessorFamily2::VIA_C7:                                return "VIA_C7";
        case DmiProcessorFamily2::VIA_EDEN:                              return "VIA_EDEN";
        case DmiProcessorFamily2::MULTI_CORE_INTEL_XEON:                 return "MULTI_CORE_INTEL_XEON";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_3_SERIES:         return "DUAL_CORE_INTEL_XEON_3_SERIES";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON_3_SERIES:         return "QUAD_CORE_INTEL_XEON_3_SERIES";
        case DmiProcessorFamily2::VIA_NANO:                              return "VIA_NANO";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_5_SERIES:         return "DUAL_CORE_INTEL_XEON_5_SERIES";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON_5_SERIES:         return "QUAD_CORE_INTEL_XEON_5_SERIES";
        case DmiProcessorFamily2::DUAL_CORE_INTEL_XEON_7_SERIES:         return "DUAL_CORE_INTEL_XEON_7_SERIES";
        case DmiProcessorFamily2::QUAD_CORE_INTEL_XEON_7_SERIES:         return "QUAD_CORE_INTEL_XEON_7_SERIES";
        case DmiProcessorFamily2::MULTI_CORE_INTEL_XEON_7_SERIES:        return "MULTI_CORE_INTEL_XEON_7_SERIES";
        case DmiProcessorFamily2::MULTI_CORE_INTEL_XEON_3400_SERIES:     return "MULTI_CORE_INTEL_XEON_3400_SERIES";
        case DmiProcessorFamily2::AMD_OPTERON_3000_SERIES:               return "AMD_OPTERON_3000_SERIES";
        case DmiProcessorFamily2::AMD_SEMPRON_II:                        return "AMD_SEMPRON_II";
        case DmiProcessorFamily2::EMBEDDED_AMD_OPTERON_QUAD_CORE:        return "EMBEDDED_AMD_OPTERON_QUAD_CORE";
        case DmiProcessorFamily2::AMD_PHENOM_TRIPLE_CORE:                return "AMD_PHENOM_TRIPLE_CORE";
        case DmiProcessorFamily2::AMD_TURION_ULTRA_DUAL_CORE_MOBILE:     return "AMD_TURION_ULTRA_DUAL_CORE_MOBILE";
        case DmiProcessorFamily2::AMD_TURION_DUAL_CORE_MOBILE:           return "AMD_TURION_DUAL_CORE_MOBILE";
        case DmiProcessorFamily2::AMD_ATHLON_DUAL_CORE:                  return "AMD_ATHLON_DUAL_CORE";
        case DmiProcessorFamily2::AMD_SEMPRON_SI:                        return "AMD_SEMPRON_SI";
        case DmiProcessorFamily2::AMD_PHENOM_II:                         return "AMD_PHENOM_II";
        case DmiProcessorFamily2::AMD_ATHLON_II:                         return "AMD_ATHLON_II";
        case DmiProcessorFamily2::SIX_CORE_AMD_OPTERON:                  return "SIX_CORE_AMD_OPTERON";
        case DmiProcessorFamily2::AMD_SEMPRON_M:                         return "AMD_SEMPRON_M";
        case DmiProcessorFamily2::I860:                                  return "I860";
        case DmiProcessorFamily2::I960:                                  return "I960";
        case DmiProcessorFamily2::INDICATOR_FAMILY_2:                    return "INDICATOR_FAMILY_2";
        case DmiProcessorFamily2::RESERVED_1:                            return "RESERVED_1";
        case DmiProcessorFamily2::ARM_V7:                                return "ARM_V7";
        case DmiProcessorFamily2::ARM_V8:                                return "ARM_V8";
        case DmiProcessorFamily2::SH3:                                   return "SH3";
        case DmiProcessorFamily2::SH4:                                   return "SH4";
        case DmiProcessorFamily2::ARM:                                   return "ARM";
        case DmiProcessorFamily2::STRONG_ARM:                            return "STRONG_ARM";
        case DmiProcessorFamily2::_6_X86:                                return "_6_X86";
        case DmiProcessorFamily2::MEDIA_GX:                              return "MEDIA_GX";
        case DmiProcessorFamily2::MII:                                   return "MII";
        case DmiProcessorFamily2::WIN_CHIP:                              return "WIN_CHIP";
        case DmiProcessorFamily2::DSP:                                   return "DSP";
        case DmiProcessorFamily2::VIDEO_PROCESSOR:                       return "VIDEO_PROCESSOR";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiProcessorFamily2 family2) // TEST: NO
{
    // COMMON_LT((" | family2 = %u", family2)); // Commented to avoid bad looking logs



    static char8 res[47];

    sprintf(res, "0x%04X (%s)", family2, enumToString(family2));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY2_H
