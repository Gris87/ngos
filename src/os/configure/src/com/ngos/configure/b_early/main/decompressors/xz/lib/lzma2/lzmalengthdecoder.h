#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMALENGTHDECODER_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMALENGTHDECODER_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



// Probabilities for a length decoder.
struct LzmaLengthDecoder
{
    // Probability of match length being at least 10
    u16 choice;

    // Probability of match length being at least 18
    u16 choice2;

    // Probabilities for match lengths 2-9
    u16 low[POS_STATES_MAX][LEN_LOW_SYMBOLS];

    // Probabilities for match lengths 10-17
    u16 mid[POS_STATES_MAX][LEN_MID_SYMBOLS];

    // Probabilities for match lengths 18-273
    u16 high[LEN_HIGH_SYMBOLS];
};



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMALENGTHDECODER_H
