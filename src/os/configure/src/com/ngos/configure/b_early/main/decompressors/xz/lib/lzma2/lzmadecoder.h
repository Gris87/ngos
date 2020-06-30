#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADECODER_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADECODER_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2.h"
#include "src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmalengthdecoder.h"
#include "src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmastate.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



struct LzmaDecoder
{
    // Distances of latest four matches
    u32 repeat0;
    u32 repeat1;
    u32 repeat2;
    u32 repeat3;

    // Types of the most recently seen LZMA symbols
    LzmaState state;

    // Length of a match. This is updated so that dictionaryRepeat can
    // be called again to finish repeating the whole match.
    u32 length;

    // LZMA properties or related bit masks (number of literal
    // context bits, a mask derived from the number of literal
    // position bits, and a mask derived from the number
    // position bits)
    //
    u32 lc;
    u32 literalPositionMask; // (1ULL << lp) - 1
    u32 positionMask;        // (1ULL << pb) - 1

    // If 1, it's a match. Otherwise it's a single 8-bit literal.
    u16 isMatch[STATES][POS_STATES_MAX];

    // If 1, it's a repeated match. The distance is one of repeat0 .. repeat3.
    u16 isRepeat[STATES];

    // If 0, distance of a repeated match is repeat0.
    // Otherwise check isRepeat1.
    u16 isRepeat0[STATES];

    // If 0, distance of a repeated match is repeat1.
    // Otherwise check isRepeat2.
    u16 isRepeat1[STATES];

    // If 0, distance of a repeated match is repeat2. Otherwise it is repeat3.
    u16 isRepeat2[STATES];

    // If 1, the repeated match has length of one byte. Otherwise
    // the length is decoded from repeatLengthDecoder.
    u16 isRepeat0Long[STATES][POS_STATES_MAX];

    // Probability tree for the highest two bits of the match
    // distance. There is a separate probability tree for match
    // lengths of 2 (i.e. MATCH_LEN_MIN), 3, 4, and [5, 273].
    u16 distanceSlot[DIST_STATES][DIST_SLOTS];

    // Probility trees for additional bits for match distance
    // when the distance is in the range [4, 127].
    u16 distanceSpecial[FULL_DISTANCES - DIST_MODEL_END];

    // Probability tree for the lowest four bits of a match
    // distance that is equal to or greater than 128.
    u16 distanceAlign[ALIGN_SIZE];

    // Length of a normal match
    LzmaLengthDecoder matchLengthDecoder;

    // Length of a repeated match
    LzmaLengthDecoder repeatLengthDecoder;

    // Probabilities of literals
    u16 literal[LITERAL_CODERS_MAX][LITERAL_CODER_SIZE];
};



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADECODER_H
