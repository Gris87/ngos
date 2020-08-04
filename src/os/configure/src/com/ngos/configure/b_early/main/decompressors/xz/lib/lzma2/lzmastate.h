#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMASTATE_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMASTATE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



// This enum is used to track which LZMA symbols have occurred most recently
// and in which order. This information is used to predict the next symbol.
//
// Symbols:
// - Literal: One 8-bit byte
// - Match: Repeat a chunk of data at some distance
// - Long repeat: Multi-byte match at a recently seen distance
// - Short repeat: One-byte repeat at a recently seen distance
//
// The symbol names are in form: oldest_older_previous. REPEAT means
// either Short or Long repeated match, and NONLITERAL means any non-literal.
enum class LzmaState: u8
{
    LITERAL_LITERAL             = 0,
    MATCH_LITERAL_LITERAL       = 1,
    REPEAT_LITERAL_LITERAL      = 2,
    SHORTREPEAT_LITERAL_LITERAL = 3,
    MATCH_LITERAL               = 4,
    REPEAT_LITERAL              = 5,
    SHORTREPEAT_LITERAL         = 6,
    LITERAL_MATCH               = 7,
    LITERAL_LONGREPEAT          = 8,
    LITERAL_SHORTREPEAT         = 9,
    NONLITERAL_MATCH            = 10,
    NONLITERAL_REPEAT           = 11
};



inline const char8* enumToString(LzmaState state) // TEST: NO
{
    // EARLY_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case LzmaState::LITERAL_LITERAL:             return "LITERAL_LITERAL";
        case LzmaState::MATCH_LITERAL_LITERAL:       return "MATCH_LITERAL_LITERAL";
        case LzmaState::REPEAT_LITERAL_LITERAL:      return "REPEAT_LITERAL_LITERAL";
        case LzmaState::SHORTREPEAT_LITERAL_LITERAL: return "SHORTREPEAT_LITERAL_LITERAL";
        case LzmaState::MATCH_LITERAL:               return "MATCH_LITERAL";
        case LzmaState::REPEAT_LITERAL:              return "REPEAT_LITERAL";
        case LzmaState::SHORTREPEAT_LITERAL:         return "SHORTREPEAT_LITERAL";
        case LzmaState::LITERAL_MATCH:               return "LITERAL_MATCH";
        case LzmaState::LITERAL_LONGREPEAT:          return "LITERAL_LONGREPEAT";
        case LzmaState::LITERAL_SHORTREPEAT:         return "LITERAL_SHORTREPEAT";
        case LzmaState::NONLITERAL_MATCH:            return "NONLITERAL_MATCH";
        case LzmaState::NONLITERAL_REPEAT:           return "NONLITERAL_REPEAT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(LzmaState state) // TEST: NO
{
    // EARLY_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[35];

    sprintf(res, "0x%02X (%s)", state, enumToString(state));

    return res;
}



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMASTATE_H
