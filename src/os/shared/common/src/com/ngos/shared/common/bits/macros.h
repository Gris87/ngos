#ifndef COM_NGOS_SHARED_COMMON_BITS_MACROS_H                                                                                                                                                            // Colorize: green
#define COM_NGOS_SHARED_COMMON_BITS_MACROS_H                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#ifndef __ASSEMBLER__                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                          // Colorize: green
#endif                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#ifndef __ASSEMBLER__                                                                                                                                                                                          // Colorize: green
#define BIT(bit) (1ULL << static_cast<good_U8>(bit))                                                                                                                                                     // Colorize: green
#else                                                                                                                                                                                                    // Colorize: green
#define BIT(bit) (1ULL << (bit))                                                                                                                                                                         // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define BIT_0  BIT(0)  // 0x0000000000000001                                                                                                                                                                                  // Colorize: green
#define BIT_1  BIT(1)  // 0x0000000000000002                                                                                                                                                                                 // Colorize: green
#define BIT_2  BIT(2)  // 0x0000000000000004                                                                                                                                                                                  // Colorize: green
#define BIT_3  BIT(3)  // 0x0000000000000008                                                                                                                                                                                  // Colorize: green
#define BIT_4  BIT(4)  // 0x0000000000000010                                                                                                                                                                                  // Colorize: green
#define BIT_5  BIT(5)  // 0x0000000000000020                                                                                                                                                                                  // Colorize: green
#define BIT_6  BIT(6)  // 0x0000000000000040                                                                                                                                                                                  // Colorize: green
#define BIT_7  BIT(7)  // 0x0000000000000080                                                                                                                                                                                  // Colorize: green
#define BIT_8  BIT(8)  // 0x0000000000000100                                                                                                                                                                                  // Colorize: green
#define BIT_9  BIT(9)  // 0x0000000000000200                                                                                                                                                                                  // Colorize: green
#define BIT_10 BIT(10) // 0x0000000000000400                                                                                                                                                                                  // Colorize: green
#define BIT_11 BIT(11) // 0x0000000000000800                                                                                                                                                                                  // Colorize: green
#define BIT_12 BIT(12) // 0x0000000000001000                                                                                                                                                                                  // Colorize: green
#define BIT_13 BIT(13) // 0x0000000000002000                                                                                                                                                                                  // Colorize: green
#define BIT_14 BIT(14) // 0x0000000000004000                                                                                                                                                                                  // Colorize: green
#define BIT_15 BIT(15) // 0x0000000000008000                                                                                                                                                                                  // Colorize: green
#define BIT_16 BIT(16) // 0x0000000000010000                                                                                                                                                                                  // Colorize: green
#define BIT_17 BIT(17) // 0x0000000000020000                                                                                                                                                                                  // Colorize: green
#define BIT_18 BIT(18) // 0x0000000000040000                                                                                                                                                                                  // Colorize: green
#define BIT_19 BIT(19) // 0x0000000000080000                                                                                                                                                                                  // Colorize: green
#define BIT_20 BIT(20) // 0x0000000000100000                                                                                                                                                                                  // Colorize: green
#define BIT_21 BIT(21) // 0x0000000000200000                                                                                                                                                                                  // Colorize: green
#define BIT_22 BIT(22) // 0x0000000000400000                                                                                                                                                                                  // Colorize: green
#define BIT_23 BIT(23) // 0x0000000000800000                                                                                                                                                                                  // Colorize: green
#define BIT_24 BIT(24) // 0x0000000001000000                                                                                                                                                                                  // Colorize: green
#define BIT_25 BIT(25) // 0x0000000002000000                                                                                                                                                                                  // Colorize: green
#define BIT_26 BIT(26) // 0x0000000004000000                                                                                                                                                                                  // Colorize: green
#define BIT_27 BIT(27) // 0x0000000008000000                                                                                                                                                                                  // Colorize: green
#define BIT_28 BIT(28) // 0x0000000010000000                                                                                                                                                                                  // Colorize: green
#define BIT_29 BIT(29) // 0x0000000020000000                                                                                                                                                                                  // Colorize: green
#define BIT_30 BIT(30) // 0x0000000040000000                                                                                                                                                                                  // Colorize: green
#define BIT_31 BIT(31) // 0x0000000080000000                                                                                                                                                                                  // Colorize: green
#define BIT_32 BIT(32) // 0x0000000100000000                                                                                                                                                                                  // Colorize: green
#define BIT_33 BIT(33) // 0x0000000200000000                                                                                                                                                                                  // Colorize: green
#define BIT_34 BIT(34) // 0x0000000400000000                                                                                                                                                                                  // Colorize: green
#define BIT_35 BIT(35) // 0x0000000800000000                                                                                                                                                                                  // Colorize: green
#define BIT_36 BIT(36) // 0x0000001000000000                                                                                                                                                                                  // Colorize: green
#define BIT_37 BIT(37) // 0x0000002000000000                                                                                                                                                                                  // Colorize: green
#define BIT_38 BIT(38) // 0x0000004000000000                                                                                                                                                                                  // Colorize: green
#define BIT_39 BIT(39) // 0x0000008000000000                                                                                                                                                                                  // Colorize: green
#define BIT_40 BIT(40) // 0x0000010000000000                                                                                                                                                                                  // Colorize: green
#define BIT_41 BIT(41) // 0x0000020000000000                                                                                                                                                                                  // Colorize: green
#define BIT_42 BIT(42) // 0x0000040000000000                                                                                                                                                                                  // Colorize: green
#define BIT_43 BIT(43) // 0x0000080000000000                                                                                                                                                                                  // Colorize: green
#define BIT_44 BIT(44) // 0x0000100000000000                                                                                                                                                                                  // Colorize: green
#define BIT_45 BIT(45) // 0x0000200000000000                                                                                                                                                                                  // Colorize: green
#define BIT_46 BIT(46) // 0x0000400000000000                                                                                                                                                                                  // Colorize: green
#define BIT_47 BIT(47) // 0x0000800000000000                                                                                                                                                                                  // Colorize: green
#define BIT_48 BIT(48) // 0x0001000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_49 BIT(49) // 0x0002000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_50 BIT(50) // 0x0004000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_51 BIT(51) // 0x0008000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_52 BIT(52) // 0x0010000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_53 BIT(53) // 0x0020000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_54 BIT(54) // 0x0040000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_55 BIT(55) // 0x0080000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_56 BIT(56) // 0x0100000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_57 BIT(57) // 0x0200000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_58 BIT(58) // 0x0400000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_59 BIT(59) // 0x0800000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_60 BIT(60) // 0x1000000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_61 BIT(61) // 0x2000000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_62 BIT(62) // 0x4000000000000000                                                                                                                                                                                  // Colorize: green
#define BIT_63 BIT(63) // 0x8000000000000000                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define SIZE_BY_BITS(bits) BIT(bits)                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_BITS_MACROS_H                                                                                                                                                           // Colorize: green
