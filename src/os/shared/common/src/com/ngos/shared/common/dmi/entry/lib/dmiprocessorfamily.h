#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiProcessorFamily: u8
{
    NONE                                   = 0,
    OTHER                                  = 0x01,
    UNKNOWN                                = 0x02,
    _8086                                  = 0x03,
    _80286                                 = 0x04,
    INTEL_386                              = 0x05,
    INTEL_486                              = 0x06,
    _8087                                  = 0x07,
    _80287                                 = 0x08,
    _80387                                 = 0x09,
    _80487                                 = 0x0A,
    PENTIUM                                = 0x0B,
    PENTIUM_PRO                            = 0x0C,
    PENTIUM_II                             = 0x0D,
    PENTIUM_MMX                            = 0x0E,
    CELERON                                = 0x0F,
    PENTIUM_II_XEON                        = 0x10,
    PENTIUM_III                            = 0x11,
    M1                                     = 0x12,
    M2                                     = 0x13,
    INTEL_CELERON_M                        = 0x14,
    INTEL_PENTIUM_4_HT                     = 0x15,
    AMD_DURON                              = 0x18,
    K5                                     = 0x19,
    K6                                     = 0x1A,
    K6_2                                   = 0x1B,
    K6_3                                   = 0x1C,
    AMD_ATHLON                             = 0x1D,
    AMD_29000                              = 0x1E,
    K6_2_PLUS                              = 0x1F,
    POWER_PC                               = 0x20,
    POWER_PC_601                           = 0x21,
    POWER_PC_603                           = 0x22,
    POWER_PC_603_PLUS                      = 0x23,
    POWER_PC_604                           = 0x24,
    POWER_PC_620                           = 0x25,
    POWER_PC_X704                          = 0x26,
    POWER_PC_750                           = 0x27,
    INTEL_CORE_DUO                         = 0x28,
    INTEL_CORE_DUO_MOBILE                  = 0x29,
    INTEL_CORE_SOLO_MOBILE                 = 0x2A,
    INTEL_ATOM                             = 0x2B,
    INTEL_CORE_M                           = 0x2C,
    INTEL_CORE_M3                          = 0x2D,
    INTEL_CORE_M5                          = 0x2E,
    INTEL_CORE_M7                          = 0x2F,
    ALPHA                                  = 0x30,
    ALPHA_21064                            = 0x31,
    ALPHA_21066                            = 0x32,
    ALPHA_21164                            = 0x33,
    ALPHA_21164_PC                         = 0x34,
    ALPHA_21164A                           = 0x35,
    ALPHA_21264                            = 0x36,
    ALPHA_21364                            = 0x37,
    AMD_TURION_II_ULTRA_DUAL_CORE_MOBILE_M = 0x38,
    AMD_TURION_II_DUAL_CORE_MOBILE_M       = 0x39,
    AMD_ATHLON_II_DUAL_CORE_M              = 0x3A,
    AMD_OPTERON_6100_SERIES                = 0x3B,
    AMD_OPTERON_4100_SERIES                = 0x3C,
    AMD_OPTERON_6200_SERIES                = 0x3D,
    AMD_OPTERON_4200_SERIES                = 0x3E,
    AMD_FX_SERIES                          = 0x3F,
    MIPS                                   = 0x40,
    MIPS_R4000                             = 0x41,
    MIPS_R4200                             = 0x42,
    MIPS_R4400                             = 0x43,
    MIPS_R4600                             = 0x44,
    MIPS_R10000                            = 0x45,
    AMD_C_SERIES                           = 0x46,
    AMD_E_SERIES                           = 0x47,
    AMD_A_SERIES                           = 0x48,
    AMD_G_SERIES                           = 0x49,
    AMD_Z_SERIES                           = 0x4A,
    AMD_R_SERIES                           = 0x4B,
    AMD_OPTERON_4300_SERIES                = 0x4C,
    AMD_OPTERON_6300_SERIES                = 0x4D,
    AMD_OPTERON_3300_SERIES                = 0x4E,
    AMD_FIRE_PRO_SERIES                    = 0x4F,
    SPARC                                  = 0x50,
    SUPER_SPARC                            = 0x51,
    MICRO_SPARC_II                         = 0x52,
    MICRO_SPARC_IIEP                       = 0x53,
    ULTRA_SPARC                            = 0x54,
    ULTRA_SPARC_II                         = 0x55,
    ULTRA_SPARC_III                        = 0x56,
    ULTRA_SPARC_III_2                      = 0x57,
    ULTRA_SPARC_IIII                       = 0x58,
    _68040                                 = 0x60,
    _68XXX                                 = 0x61,
    _68000                                 = 0x62,
    _68010                                 = 0x63,
    _68020                                 = 0x64,
    _68030                                 = 0x65,
    AMD_ATHLON_X4_QUAD_CORE                = 0x66,
    AMD_OPTERON_X1000_SERIES               = 0x67,
    AMD_OPTERON_X2000_SERIES               = 0x68,
    AMD_OPTERON_A_SERIES                   = 0x69,
    AMD_OPTERON_X3000_SERIES               = 0x6A,
    AMD_ZEN                                = 0x6B,
    HOBBIT                                 = 0x70,
    CRUSOE_TM5000                          = 0x78,
    CRUSOE_TM3000                          = 0x79,
    EFFICEON_TM8000                        = 0x7A,
    WEITEK                                 = 0x80,
    ITANIUM                                = 0x82,
    AMD_ATHLON_64                          = 0x83,
    AMD_OPTERON                            = 0x84,
    AMD_SEMPRON                            = 0x85,
    AMD_TURION_64_MOBILE                   = 0x86,
    DUAL_CORE_AMD_OPTERON                  = 0x87,
    AMD_ATHLON_64_X2_DUAL_CORE             = 0x88,
    AMD_TURION_64_X2_MOBILE                = 0x89,
    QUAD_CORE_AMD_OPTERON                  = 0x8A,
    THIRD_GENERATION_AMD_OPTERON           = 0x8B,
    AMD_PHENOM_FX_QUAD_CORE                = 0x8C,
    AMD_PHENOM_X4_QUAD_CORE                = 0x8D,
    AMD_PHENOM_X2_DUAL_CORE                = 0x8E,
    AMD_ATHLON_X2_DUAL_CORE                = 0x8F,
    PA_RISC                                = 0x90,
    PA_RISC_8500                           = 0x91,
    PA_RISC_8000                           = 0x92,
    PA_RISC_7300_LC                        = 0x93,
    PA_RISC_7200                           = 0x94,
    PA_RISC_7100_LC                        = 0x95,
    PA_RISC_7100                           = 0x96,
    V30                                    = 0xA0,
    QUAD_CORE_INTEL_XEON_3200_SERIES       = 0xA1,
    DUAL_CORE_INTEL_XEON_3000_SERIES       = 0xA2,
    QUAD_CORE_INTEL_XEON_5300_SERIES       = 0xA3,
    DUAL_CORE_INTEL_XEON_5100_SERIES       = 0xA4,
    DUAL_CORE_INTEL_XEON_5000_SERIES       = 0xA5,
    DUAL_CORE_INTEL_XEON_LV                = 0xA6,
    DUAL_CORE_INTEL_XEON_ULV               = 0xA7,
    DUAL_CORE_INTEL_XEON_7100_SERIES       = 0xA8,
    QUAD_CORE_INTEL_XEON_5400_SERIES       = 0xA9,
    QUAD_CORE_INTEL_XEON                   = 0xAA,
    DUAL_CORE_INTEL_XEON_5200_SERIES       = 0xAB,
    DUAL_CORE_INTEL_XEON_7200_SERIES       = 0xAC,
    QUAD_CORE_INTEL_XEON_7300_SERIES       = 0xAD,
    QUAD_CORE_INTEL_XEON_7400_SERIES       = 0xAE,
    MULTI_CORE_INTEL_XEON_7400_SERIES      = 0xAF,
    PENTIUM_III_XEON                       = 0xB0,
    PENTIUM_III_SPEED_STEP                 = 0xB1,
    PENTIUM_4                              = 0xB2,
    INTEL_XEON                             = 0xB3,
    AS400                                  = 0xB4,
    INTEL_XEON_MP                          = 0xB5,
    AMD_ATHLON_XP                          = 0xB6,
    AMD_ATHLON_MP                          = 0xB7,
    INTEL_ITANIUM_2                        = 0xB8,
    INTEL_PENTIUM_M                        = 0xB9,
    INTEL_CELERON_D                        = 0xBA,
    INTEL_PENTIUM_D                        = 0xBB,
    INTEL_PENTIUM_EXTREME                  = 0xBC,
    INTEL_CORE_SOLO                        = 0xBD,
    RESERVED                               = 0xBE,
    INTEL_CORE_2_DUO                       = 0xBF,
    INTEL_CORE_2_SOLO                      = 0xC0,
    INTEL_CORE_2_EXTREME                   = 0xC1,
    INTEL_CORE_2_QUAD                      = 0xC2,
    INTEL_CORE_2_EXTREME_MOBILE            = 0xC3,
    INTEL_CORE_2_DUO_MOBILE                = 0xC4,
    INTEL_CORE_2_SOLO_MOBILE               = 0xC5,
    INTEL_CORE_I7                          = 0xC6,
    DUAL_CORE_INTEL_CELERON                = 0xC7,
    IBM390                                 = 0xC8,
    G4                                     = 0xC9,
    G5                                     = 0xCA,
    G6                                     = 0xCB,
    Z_ARCHITECTURE                         = 0xCC,
    INTEL_CORE_I5                          = 0xCD,
    INTEL_CORE_I3                          = 0xCE,
    INTEL_CORE_I9                          = 0xCF,
    VIA_C7_M                               = 0xD2,
    VIA_C7_D                               = 0xD3,
    VIA_C7                                 = 0xD4,
    VIA_EDEN                               = 0xD5,
    MULTI_CORE_INTEL_XEON                  = 0xD6,
    DUAL_CORE_INTEL_XEON_3XXX_SERIES       = 0xD7,
    QUAD_CORE_INTEL_XEON_3XXX_SERIES       = 0xD8,
    VIA_NANO                               = 0xD9,
    DUAL_CORE_INTEL_XEON_5XXX_SERIES       = 0xDA,
    QUAD_CORE_INTEL_XEON_5XXX_SERIES       = 0xDB,
    DUAL_CORE_INTEL_XEON_7XXX_SERIES       = 0xDD,
    QUAD_CORE_INTEL_XEON_7XXX_SERIES       = 0xDE,
    MULTI_CORE_INTEL_XEON_7XXX_SERIES      = 0xDF,
    MULTI_CORE_INTEL_XEON_3400_SERIES      = 0xE0,
    AMD_OPTERON_3000_SERIES                = 0xE4,
    AMD_SEMPRON_II                         = 0xE5,
    EMBEDDED_AMD_OPTERON_QUAD_CORE         = 0xE6,
    AMD_PHENOM_TRIPLE_CORE                 = 0xE7,
    AMD_TURION_ULTRA_DUAL_CORE_MOBILE      = 0xE8,
    AMD_TURION_DUAL_CORE_MOBILE            = 0xE9,
    AMD_ATHLON_DUAL_CORE                   = 0xEA,
    AMD_SEMPRON_SI                         = 0xEB,
    AMD_PHENOM_II                          = 0xEC,
    AMD_ATHLON_II                          = 0xED,
    SIX_CORE_AMD_OPTERON                   = 0xEE,
    AMD_SEMPRON_M                          = 0xEF,
    I860                                   = 0xFA,
    I960                                   = 0xFB,
    INDICATOR_FAMILY_2                     = 0xFE,
    RESERVED_2                             = 0xFF
};



inline const char8* enumToString(DmiProcessorFamily family) // TEST: NO
{
    // COMMON_LT((" | family = %u", family)); // Commented to avoid bad looking logs



    switch (family)
    {
        case DmiProcessorFamily::NONE:                                   return "NONE";
        case DmiProcessorFamily::OTHER:                                  return "OTHER";
        case DmiProcessorFamily::UNKNOWN:                                return "UNKNOWN";
        case DmiProcessorFamily::_8086:                                  return "_8086";
        case DmiProcessorFamily::_80286:                                 return "_80286";
        case DmiProcessorFamily::INTEL_386:                              return "INTEL_386";
        case DmiProcessorFamily::INTEL_486:                              return "INTEL_486";
        case DmiProcessorFamily::_8087:                                  return "_8087";
        case DmiProcessorFamily::_80287:                                 return "_80287";
        case DmiProcessorFamily::_80387:                                 return "_80387";
        case DmiProcessorFamily::_80487:                                 return "_80487";
        case DmiProcessorFamily::PENTIUM:                                return "PENTIUM";
        case DmiProcessorFamily::PENTIUM_PRO:                            return "PENTIUM_PRO";
        case DmiProcessorFamily::PENTIUM_II:                             return "PENTIUM_II";
        case DmiProcessorFamily::PENTIUM_MMX:                            return "PENTIUM_MMX";
        case DmiProcessorFamily::CELERON:                                return "CELERON";
        case DmiProcessorFamily::PENTIUM_II_XEON:                        return "PENTIUM_II_XEON";
        case DmiProcessorFamily::PENTIUM_III:                            return "PENTIUM_III";
        case DmiProcessorFamily::M1:                                     return "M1";
        case DmiProcessorFamily::M2:                                     return "M2";
        case DmiProcessorFamily::INTEL_CELERON_M:                        return "INTEL_CELERON_M";
        case DmiProcessorFamily::INTEL_PENTIUM_4_HT:                     return "INTEL_PENTIUM_4_HT";
        case DmiProcessorFamily::AMD_DURON:                              return "AMD_DURON";
        case DmiProcessorFamily::K5:                                     return "K5";
        case DmiProcessorFamily::K6:                                     return "K6";
        case DmiProcessorFamily::K6_2:                                   return "K6_2";
        case DmiProcessorFamily::K6_3:                                   return "K6_3";
        case DmiProcessorFamily::AMD_ATHLON:                             return "AMD_ATHLON";
        case DmiProcessorFamily::AMD_29000:                              return "AMD_29000";
        case DmiProcessorFamily::K6_2_PLUS:                              return "K6_2_PLUS";
        case DmiProcessorFamily::POWER_PC:                               return "POWER_PC";
        case DmiProcessorFamily::POWER_PC_601:                           return "POWER_PC_601";
        case DmiProcessorFamily::POWER_PC_603:                           return "POWER_PC_603";
        case DmiProcessorFamily::POWER_PC_603_PLUS:                      return "POWER_PC_603_PLUS";
        case DmiProcessorFamily::POWER_PC_604:                           return "POWER_PC_604";
        case DmiProcessorFamily::POWER_PC_620:                           return "POWER_PC_620";
        case DmiProcessorFamily::POWER_PC_X704:                          return "POWER_PC_X704";
        case DmiProcessorFamily::POWER_PC_750:                           return "POWER_PC_750";
        case DmiProcessorFamily::INTEL_CORE_DUO:                         return "INTEL_CORE_DUO";
        case DmiProcessorFamily::INTEL_CORE_DUO_MOBILE:                  return "INTEL_CORE_DUO_MOBILE";
        case DmiProcessorFamily::INTEL_CORE_SOLO_MOBILE:                 return "INTEL_CORE_SOLO_MOBILE";
        case DmiProcessorFamily::INTEL_ATOM:                             return "INTEL_ATOM";
        case DmiProcessorFamily::INTEL_CORE_M:                           return "INTEL_CORE_M";
        case DmiProcessorFamily::INTEL_CORE_M3:                          return "INTEL_CORE_M3";
        case DmiProcessorFamily::INTEL_CORE_M5:                          return "INTEL_CORE_M5";
        case DmiProcessorFamily::INTEL_CORE_M7:                          return "INTEL_CORE_M7";
        case DmiProcessorFamily::ALPHA:                                  return "ALPHA";
        case DmiProcessorFamily::ALPHA_21064:                            return "ALPHA_21064";
        case DmiProcessorFamily::ALPHA_21066:                            return "ALPHA_21066";
        case DmiProcessorFamily::ALPHA_21164:                            return "ALPHA_21164";
        case DmiProcessorFamily::ALPHA_21164_PC:                         return "ALPHA_21164_PC";
        case DmiProcessorFamily::ALPHA_21164A:                           return "ALPHA_21164A";
        case DmiProcessorFamily::ALPHA_21264:                            return "ALPHA_21264";
        case DmiProcessorFamily::ALPHA_21364:                            return "ALPHA_21364";
        case DmiProcessorFamily::AMD_TURION_II_ULTRA_DUAL_CORE_MOBILE_M: return "AMD_TURION_II_ULTRA_DUAL_CORE_MOBILE_M";
        case DmiProcessorFamily::AMD_TURION_II_DUAL_CORE_MOBILE_M:       return "AMD_TURION_II_DUAL_CORE_MOBILE_M";
        case DmiProcessorFamily::AMD_ATHLON_II_DUAL_CORE_M:              return "AMD_ATHLON_II_DUAL_CORE_M";
        case DmiProcessorFamily::AMD_OPTERON_6100_SERIES:                return "AMD_OPTERON_6100_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_4100_SERIES:                return "AMD_OPTERON_4100_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_6200_SERIES:                return "AMD_OPTERON_6200_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_4200_SERIES:                return "AMD_OPTERON_4200_SERIES";
        case DmiProcessorFamily::AMD_FX_SERIES:                          return "AMD_FX_SERIES";
        case DmiProcessorFamily::MIPS:                                   return "MIPS";
        case DmiProcessorFamily::MIPS_R4000:                             return "MIPS_R4000";
        case DmiProcessorFamily::MIPS_R4200:                             return "MIPS_R4200";
        case DmiProcessorFamily::MIPS_R4400:                             return "MIPS_R4400";
        case DmiProcessorFamily::MIPS_R4600:                             return "MIPS_R4600";
        case DmiProcessorFamily::MIPS_R10000:                            return "MIPS_R10000";
        case DmiProcessorFamily::AMD_C_SERIES:                           return "AMD_C_SERIES";
        case DmiProcessorFamily::AMD_E_SERIES:                           return "AMD_E_SERIES";
        case DmiProcessorFamily::AMD_A_SERIES:                           return "AMD_A_SERIES";
        case DmiProcessorFamily::AMD_G_SERIES:                           return "AMD_G_SERIES";
        case DmiProcessorFamily::AMD_Z_SERIES:                           return "AMD_Z_SERIES";
        case DmiProcessorFamily::AMD_R_SERIES:                           return "AMD_R_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_4300_SERIES:                return "AMD_OPTERON_4300_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_6300_SERIES:                return "AMD_OPTERON_6300_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_3300_SERIES:                return "AMD_OPTERON_3300_SERIES";
        case DmiProcessorFamily::AMD_FIRE_PRO_SERIES:                    return "AMD_FIRE_PRO_SERIES";
        case DmiProcessorFamily::SPARC:                                  return "SPARC";
        case DmiProcessorFamily::SUPER_SPARC:                            return "SUPER_SPARC";
        case DmiProcessorFamily::MICRO_SPARC_II:                         return "MICRO_SPARC_II";
        case DmiProcessorFamily::MICRO_SPARC_IIEP:                       return "MICRO_SPARC_IIEP";
        case DmiProcessorFamily::ULTRA_SPARC:                            return "ULTRA_SPARC";
        case DmiProcessorFamily::ULTRA_SPARC_II:                         return "ULTRA_SPARC_II";
        case DmiProcessorFamily::ULTRA_SPARC_III:                        return "ULTRA_SPARC_III";
        case DmiProcessorFamily::ULTRA_SPARC_III_2:                      return "ULTRA_SPARC_III_2";
        case DmiProcessorFamily::ULTRA_SPARC_IIII:                       return "ULTRA_SPARC_IIII";
        case DmiProcessorFamily::_68040:                                 return "_68040";
        case DmiProcessorFamily::_68XXX:                                 return "_68XXX";
        case DmiProcessorFamily::_68000:                                 return "_68000";
        case DmiProcessorFamily::_68010:                                 return "_68010";
        case DmiProcessorFamily::_68020:                                 return "_68020";
        case DmiProcessorFamily::_68030:                                 return "_68030";
        case DmiProcessorFamily::AMD_ATHLON_X4_QUAD_CORE:                return "AMD_ATHLON_X4_QUAD_CORE";
        case DmiProcessorFamily::AMD_OPTERON_X1000_SERIES:               return "AMD_OPTERON_X1000_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_X2000_SERIES:               return "AMD_OPTERON_X2000_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_A_SERIES:                   return "AMD_OPTERON_A_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_X3000_SERIES:               return "AMD_OPTERON_X3000_SERIES";
        case DmiProcessorFamily::AMD_ZEN:                                return "AMD_ZEN";
        case DmiProcessorFamily::HOBBIT:                                 return "HOBBIT";
        case DmiProcessorFamily::CRUSOE_TM5000:                          return "CRUSOE_TM5000";
        case DmiProcessorFamily::CRUSOE_TM3000:                          return "CRUSOE_TM3000";
        case DmiProcessorFamily::EFFICEON_TM8000:                        return "EFFICEON_TM8000";
        case DmiProcessorFamily::WEITEK:                                 return "WEITEK";
        case DmiProcessorFamily::ITANIUM:                                return "ITANIUM";
        case DmiProcessorFamily::AMD_ATHLON_64:                          return "AMD_ATHLON_64";
        case DmiProcessorFamily::AMD_OPTERON:                            return "AMD_OPTERON";
        case DmiProcessorFamily::AMD_SEMPRON:                            return "AMD_SEMPRON";
        case DmiProcessorFamily::AMD_TURION_64_MOBILE:                   return "AMD_TURION_64_MOBILE";
        case DmiProcessorFamily::DUAL_CORE_AMD_OPTERON:                  return "DUAL_CORE_AMD_OPTERON";
        case DmiProcessorFamily::AMD_ATHLON_64_X2_DUAL_CORE:             return "AMD_ATHLON_64_X2_DUAL_CORE";
        case DmiProcessorFamily::AMD_TURION_64_X2_MOBILE:                return "AMD_TURION_64_X2_MOBILE";
        case DmiProcessorFamily::QUAD_CORE_AMD_OPTERON:                  return "QUAD_CORE_AMD_OPTERON";
        case DmiProcessorFamily::THIRD_GENERATION_AMD_OPTERON:           return "THIRD_GENERATION_AMD_OPTERON";
        case DmiProcessorFamily::AMD_PHENOM_FX_QUAD_CORE:                return "AMD_PHENOM_FX_QUAD_CORE";
        case DmiProcessorFamily::AMD_PHENOM_X4_QUAD_CORE:                return "AMD_PHENOM_X4_QUAD_CORE";
        case DmiProcessorFamily::AMD_PHENOM_X2_DUAL_CORE:                return "AMD_PHENOM_X2_DUAL_CORE";
        case DmiProcessorFamily::AMD_ATHLON_X2_DUAL_CORE:                return "AMD_ATHLON_X2_DUAL_CORE";
        case DmiProcessorFamily::PA_RISC:                                return "PA_RISC";
        case DmiProcessorFamily::PA_RISC_8500:                           return "PA_RISC_8500";
        case DmiProcessorFamily::PA_RISC_8000:                           return "PA_RISC_8000";
        case DmiProcessorFamily::PA_RISC_7300_LC:                        return "PA_RISC_7300_LC";
        case DmiProcessorFamily::PA_RISC_7200:                           return "PA_RISC_7200";
        case DmiProcessorFamily::PA_RISC_7100_LC:                        return "PA_RISC_7100_LC";
        case DmiProcessorFamily::PA_RISC_7100:                           return "PA_RISC_7100";
        case DmiProcessorFamily::V30:                                    return "V30";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON_3200_SERIES:       return "QUAD_CORE_INTEL_XEON_3200_SERIES";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_3000_SERIES:       return "DUAL_CORE_INTEL_XEON_3000_SERIES";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON_5300_SERIES:       return "QUAD_CORE_INTEL_XEON_5300_SERIES";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_5100_SERIES:       return "DUAL_CORE_INTEL_XEON_5100_SERIES";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_5000_SERIES:       return "DUAL_CORE_INTEL_XEON_5000_SERIES";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_LV:                return "DUAL_CORE_INTEL_XEON_LV";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_ULV:               return "DUAL_CORE_INTEL_XEON_ULV";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_7100_SERIES:       return "DUAL_CORE_INTEL_XEON_7100_SERIES";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON_5400_SERIES:       return "QUAD_CORE_INTEL_XEON_5400_SERIES";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON:                   return "QUAD_CORE_INTEL_XEON";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_5200_SERIES:       return "DUAL_CORE_INTEL_XEON_5200_SERIES";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_7200_SERIES:       return "DUAL_CORE_INTEL_XEON_7200_SERIES";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON_7300_SERIES:       return "QUAD_CORE_INTEL_XEON_7300_SERIES";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON_7400_SERIES:       return "QUAD_CORE_INTEL_XEON_7400_SERIES";
        case DmiProcessorFamily::MULTI_CORE_INTEL_XEON_7400_SERIES:      return "MULTI_CORE_INTEL_XEON_7400_SERIES";
        case DmiProcessorFamily::PENTIUM_III_XEON:                       return "PENTIUM_III_XEON";
        case DmiProcessorFamily::PENTIUM_III_SPEED_STEP:                 return "PENTIUM_III_SPEED_STEP";
        case DmiProcessorFamily::PENTIUM_4:                              return "PENTIUM_4";
        case DmiProcessorFamily::INTEL_XEON:                             return "INTEL_XEON";
        case DmiProcessorFamily::AS400:                                  return "AS400";
        case DmiProcessorFamily::INTEL_XEON_MP:                          return "INTEL_XEON_MP";
        case DmiProcessorFamily::AMD_ATHLON_XP:                          return "AMD_ATHLON_XP";
        case DmiProcessorFamily::AMD_ATHLON_MP:                          return "AMD_ATHLON_MP";
        case DmiProcessorFamily::INTEL_ITANIUM_2:                        return "INTEL_ITANIUM_2";
        case DmiProcessorFamily::INTEL_PENTIUM_M:                        return "INTEL_PENTIUM_M";
        case DmiProcessorFamily::INTEL_CELERON_D:                        return "INTEL_CELERON_D";
        case DmiProcessorFamily::INTEL_PENTIUM_D:                        return "INTEL_PENTIUM_D";
        case DmiProcessorFamily::INTEL_PENTIUM_EXTREME:                  return "INTEL_PENTIUM_EXTREME";
        case DmiProcessorFamily::INTEL_CORE_SOLO:                        return "INTEL_CORE_SOLO";
        case DmiProcessorFamily::RESERVED:                               return "RESERVED";
        case DmiProcessorFamily::INTEL_CORE_2_DUO:                       return "INTEL_CORE_2_DUO";
        case DmiProcessorFamily::INTEL_CORE_2_SOLO:                      return "INTEL_CORE_2_SOLO";
        case DmiProcessorFamily::INTEL_CORE_2_EXTREME:                   return "INTEL_CORE_2_EXTREME";
        case DmiProcessorFamily::INTEL_CORE_2_QUAD:                      return "INTEL_CORE_2_QUAD";
        case DmiProcessorFamily::INTEL_CORE_2_EXTREME_MOBILE:            return "INTEL_CORE_2_EXTREME_MOBILE";
        case DmiProcessorFamily::INTEL_CORE_2_DUO_MOBILE:                return "INTEL_CORE_2_DUO_MOBILE";
        case DmiProcessorFamily::INTEL_CORE_2_SOLO_MOBILE:               return "INTEL_CORE_2_SOLO_MOBILE";
        case DmiProcessorFamily::INTEL_CORE_I7:                          return "INTEL_CORE_I7";
        case DmiProcessorFamily::DUAL_CORE_INTEL_CELERON:                return "DUAL_CORE_INTEL_CELERON";
        case DmiProcessorFamily::IBM390:                                 return "IBM390";
        case DmiProcessorFamily::G4:                                     return "G4";
        case DmiProcessorFamily::G5:                                     return "G5";
        case DmiProcessorFamily::G6:                                     return "G6";
        case DmiProcessorFamily::Z_ARCHITECTURE:                         return "Z_ARCHITECTURE";
        case DmiProcessorFamily::INTEL_CORE_I5:                          return "INTEL_CORE_I5";
        case DmiProcessorFamily::INTEL_CORE_I3:                          return "INTEL_CORE_I3";
        case DmiProcessorFamily::INTEL_CORE_I9:                          return "INTEL_CORE_I9";
        case DmiProcessorFamily::VIA_C7_M:                               return "VIA_C7_M";
        case DmiProcessorFamily::VIA_C7_D:                               return "VIA_C7_D";
        case DmiProcessorFamily::VIA_C7:                                 return "VIA_C7";
        case DmiProcessorFamily::VIA_EDEN:                               return "VIA_EDEN";
        case DmiProcessorFamily::MULTI_CORE_INTEL_XEON:                  return "MULTI_CORE_INTEL_XEON";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_3XXX_SERIES:       return "DUAL_CORE_INTEL_XEON_3XXX_SERIES";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON_3XXX_SERIES:       return "QUAD_CORE_INTEL_XEON_3XXX_SERIES";
        case DmiProcessorFamily::VIA_NANO:                               return "VIA_NANO";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_5XXX_SERIES:       return "DUAL_CORE_INTEL_XEON_5XXX_SERIES";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON_5XXX_SERIES:       return "QUAD_CORE_INTEL_XEON_5XXX_SERIES";
        case DmiProcessorFamily::DUAL_CORE_INTEL_XEON_7XXX_SERIES:       return "DUAL_CORE_INTEL_XEON_7XXX_SERIES";
        case DmiProcessorFamily::QUAD_CORE_INTEL_XEON_7XXX_SERIES:       return "QUAD_CORE_INTEL_XEON_7XXX_SERIES";
        case DmiProcessorFamily::MULTI_CORE_INTEL_XEON_7XXX_SERIES:      return "MULTI_CORE_INTEL_XEON_7XXX_SERIES";
        case DmiProcessorFamily::MULTI_CORE_INTEL_XEON_3400_SERIES:      return "MULTI_CORE_INTEL_XEON_3400_SERIES";
        case DmiProcessorFamily::AMD_OPTERON_3000_SERIES:                return "AMD_OPTERON_3000_SERIES";
        case DmiProcessorFamily::AMD_SEMPRON_II:                         return "AMD_SEMPRON_II";
        case DmiProcessorFamily::EMBEDDED_AMD_OPTERON_QUAD_CORE:         return "EMBEDDED_AMD_OPTERON_QUAD_CORE";
        case DmiProcessorFamily::AMD_PHENOM_TRIPLE_CORE:                 return "AMD_PHENOM_TRIPLE_CORE";
        case DmiProcessorFamily::AMD_TURION_ULTRA_DUAL_CORE_MOBILE:      return "AMD_TURION_ULTRA_DUAL_CORE_MOBILE";
        case DmiProcessorFamily::AMD_TURION_DUAL_CORE_MOBILE:            return "AMD_TURION_DUAL_CORE_MOBILE";
        case DmiProcessorFamily::AMD_ATHLON_DUAL_CORE:                   return "AMD_ATHLON_DUAL_CORE";
        case DmiProcessorFamily::AMD_SEMPRON_SI:                         return "AMD_SEMPRON_SI";
        case DmiProcessorFamily::AMD_PHENOM_II:                          return "AMD_PHENOM_II";
        case DmiProcessorFamily::AMD_ATHLON_II:                          return "AMD_ATHLON_II";
        case DmiProcessorFamily::SIX_CORE_AMD_OPTERON:                   return "SIX_CORE_AMD_OPTERON";
        case DmiProcessorFamily::AMD_SEMPRON_M:                          return "AMD_SEMPRON_M";
        case DmiProcessorFamily::I860:                                   return "I860";
        case DmiProcessorFamily::I960:                                   return "I960";
        case DmiProcessorFamily::INDICATOR_FAMILY_2:                     return "INDICATOR_FAMILY_2";
        case DmiProcessorFamily::RESERVED_2:                             return "RESERVED_2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiProcessorFamily family) // TEST: NO
{
    // COMMON_LT((" | family = %u", family)); // Commented to avoid bad looking logs



    static char8 res[46];

    sprintf(res, "0x%02X (%s)", family, enumToString(family));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY_H
