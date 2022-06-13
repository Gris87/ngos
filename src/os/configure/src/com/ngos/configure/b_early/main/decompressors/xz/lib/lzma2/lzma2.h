#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2_H



#include <buildconfig.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define LZMA_DECODER_IS_SINGLE(mode) true
#define LZMA_DECODER_IS_MULTI(mode)  false



// Range coder constants
#define RC_SHIFT_BITS           8
#define RC_TOP_BITS             24
#define RC_TOP_VALUE            BIT(RC_TOP_BITS)
#define RC_BIT_MODEL_TOTAL_BITS 11
#define RC_BIT_MODEL_TOTAL      BIT(RC_BIT_MODEL_TOTAL_BITS)
#define RC_MOVE_BITS            5

// Range decoder initialization eats the first five bytes of each LZMA chunk.
#define RC_INIT_BYTES 5

// Minimum number of usable input buffer to safely decode one LZMA symbol.
// The worst case is that we decode 22 bits using probabilities and 26
// direct bits. This may decode at maximum of 20 bytes of input. However,
// lzmaMain() does an extra normalization before returning, thus we
// need to put 21 here.
#define LZMA_IN_REQUIRED 21

// Maximum number of position states. A position state is the lowest pb
// number of bits of the current uncompressed offset. In some places there
// are different sets of probabilities for different position states.
#define POS_STATES_MAX BIT_4

// Total number of states
#define STATES 12

// The lowest 7 states indicate that the previous state was a literal.
#define LITERAL_STATES 7

// Each literal coder is divided in three sections:
// - 0x0001-0x00FF: Without match byte
// - 0x0101-0x01FF: With match byte; match bit is 0
// - 0x0201-0x02FF: With match byte; match bit is 1
//
// Match byte is used when the previous LZMA symbol was something else than
// a literal (that is, it was some kind of match).
#define LITERAL_CODER_SIZE 0x0300

// Maximum number of literal coders
#define LITERAL_CODERS_MAX BIT_4

// Minimum length of a match is two bytes.
#define MATCH_LEN_MIN 2

// Match length is encoded with 4, 5, or 10 bits.
//
// Length   Bits
// 2-9      4   = Choice=0 + 3 bits
// 10-17    5   = Choice=1 + Choice2=0 + 3 bits
// 18-273   10  = Choice=1 + Choice2=1 + 8 bits
//
#define LEN_LOW_BITS     3
#define LEN_LOW_SYMBOLS  BIT(LEN_LOW_BITS)
#define LEN_MID_BITS     3
#define LEN_MID_SYMBOLS  BIT(LEN_MID_BITS)
#define LEN_HIGH_BITS    8
#define LEN_HIGH_SYMBOLS BIT(LEN_HIGH_BITS)

// Different sets of probabilities are used for match distances that have
// very Short match length: Lengths of 2, 3, and 4 bytes have a separate
// set of probabilities for each length. The matches with longer length
// use a shared set of probabilities.
#define DIST_STATES 4

// The highest two bits of a 32-bit match distance are encoded using six bits.
// This six-bit value is called a distance slot. This way encoding a 32-bit
// value takes 6-36 bits, larger values taking more bits.
//
#define DIST_SLOT_BITS 6
#define DIST_SLOTS     BIT(DIST_SLOT_BITS)

// Match distances up to 127 are fully encoded using probabilities. Since
// the highest two bits (distance slot) are always encoded using six bits,
// the distances 0-3 don't need any additional bits to encode, since the
// distance slot itself is the same as the actual distance. DIST_MODEL_START
// indicates the first distance slot where at least one additional bit is
// needed.
#define DIST_MODEL_START 4

// Match distances greater than 127 are encoded in three pieces:
// - distance slot: the highest two bits
// - direct bits: 2-26 bits below the highest two bits
// - alignment bits: four lowest bits
//
// Direct bits don't use any probabilities.
//
// The distance slot value of 14 is for distances 128-191.
#define DIST_MODEL_END 14

// Distance slots that indicate a distance <= 127.
//
#define FULL_DISTANCES_BITS (DIST_MODEL_END / 2)
#define FULL_DISTANCES      BIT(FULL_DISTANCES_BITS)

// For match distances greater than 127, only the highest two bits and the
// lowest four bits (alignment) is encoded using probabilities.
#define ALIGN_BITS 4
#define ALIGN_SIZE BIT(ALIGN_BITS)

// Total number of all probability variables
#define PROBS_TOTAL (1846 + LITERAL_CODERS_MAX * LITERAL_CODER_SIZE)



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2_H
