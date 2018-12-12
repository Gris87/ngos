#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMASTATE_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMASTATE_H



#include <buildconfig.h>
#include <ngos/types.h>



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
// The symbol names are in from STATE_oldest_older_previous. REP means
// either Short or Long repeated match, and NONLIT means any non-literal.
enum class LzmaState: u8
{
    STATE_LIT_LIT,
    STATE_MATCH_LIT_LIT,
    STATE_REP_LIT_LIT,
    STATE_SHORTREP_LIT_LIT,
    STATE_MATCH_LIT,
    STATE_REP_LIT,
    STATE_SHORTREP_LIT,
    STATE_LIT_MATCH,
    STATE_LIT_LONGREP,
    STATE_LIT_SHORTREP,
    STATE_NONLIT_MATCH,
    STATE_NONLIT_REP
};



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMASTATE_H
