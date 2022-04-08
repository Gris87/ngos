#ifndef COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H                                                                                                                                                            // Colorize: green
#define COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/asm/asmutils.h>                                                                                                                                                     // Colorize: green
#include <com/ngos/shared/common/ngos/linkage.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/status.h>                                                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/ngos/utils.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define CONST_BIT_ADDRESS(address, bit) (reinterpret_cast<u8 *>(address) + ((bit) / 8))                                                                                                                                 // Colorize: green
#define CONST_BIT_IN_U8(bit)            (1ULL << ((bit) & 7))                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class BitUtils                                                                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    static inline bool test(u8 *address, i64 bit)                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (IS_CONSTANT(bit))                                                                                                                                                                            // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return *CONST_BIT_ADDRESS(address, bit) & CONST_BIT_IN_U8(bit);                                                                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return AsmUtils::bt(address, bit);                                                                                                                                                           // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static inline NgosStatus set(u8 *address, i64 bit)                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (IS_CONSTANT(bit))                                                                                                                                                                            // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            // Ignore CppAlignmentVerifier [BEGIN]                                                                                                                                                       // Colorize: green
            asm volatile(                                                                                                                                                                                // Colorize: green
                "orb    %1, %0"                                   // orb    %rax, (%rbx)    # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address                                       // Colorize: green
                    :                                             // Output parameters                                                                                                                   // Colorize: green
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write                                                                                              // Colorize: green
                    :                                             // Input parameters                                                                                                                    // Colorize: green
                        "i" (CONST_BIT_IN_U8(bit))                // 'i' - integer constant // Ignore CppSingleCharVerifier                                                                              // Colorize: green
                    :                                             // Clobber list                                                                                                                        // Colorize: green
                        "memory"                                  // Inform gcc that memory will be changed                                                                                              // Colorize: green
            );                                                                                                                                                                                           // Colorize: green
            // Ignore CppAlignmentVerifier [END]                                                                                                                                                         // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return AsmUtils::btsPure(address, bit);                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return NgosStatus::OK;                                                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green

    static inline NgosStatus setSafe(u8 *address, u64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock orb   %1, %0"                               // lock orb   %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" (CONST_BIT_IN_U8(bit))                // 'i' - integer constant // Ignore CppSingleCharVerifier
                    :                                             // Clobber list
                        "memory"                                  // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return AsmUtils::btsPureSafe(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus clear(u8 *address, u64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "andb   %1, %0"                                   // andb   %rax, (%rbx)    # Clears bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" ((u8)~CONST_BIT_IN_U8(bit))           // 'i' - integer constant // Ignore CppSingleCharVerifier
                    :                                             // Clobber list
                        "memory"                                  // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return AsmUtils::btrPure(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus clearSafe(u8 *address, u64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock andb  %1, %0"                               // lock andb  %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Clears bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" ((u8)~CONST_BIT_IN_U8(bit))           // 'i' - integer constant // Ignore CppSingleCharVerifier
                    :                                             // Clobber list
                        "memory"                                  // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return AsmUtils::btrPureSafe(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus invert(u8 *address, u64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "xorb   %1, %0"                                   // xorb   %rax, (%rbx)    # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" (CONST_BIT_IN_U8(bit))                // 'i' - integer constant // Ignore CppSingleCharVerifier
                    :                                             // Clobber list
                        "memory"                                  // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return AsmUtils::btcPure(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus invertSafe(u8 *address, u64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock xorb  %1, %0"                               // lock xorb  %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" (CONST_BIT_IN_U8(bit))                // 'i' - integer constant // Ignore CppSingleCharVerifier
                    :                                             // Clobber list
                        "memory"                                  // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return AsmUtils::btcPureSafe(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline u8 findFirstBit16(u16 value)
    {
        if (value == 0)
        {
            return 0;
        }



        u16 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfw  %1, %0"   // bsfw   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                 // Output parameters
                    "=r" (res)    // 'r' - any general register, '=' - write only
                :                 // Input parameters
                    "r" (value)   // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findFirstBit32(u32 value)
    {
        if (value == 0)
        {
            return 0;
        }



        u32 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfl  %1, %0"   // bsfl   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                 // Output parameters
                    "=r" (res)    // 'r' - any general register, '=' - write only
                :                 // Input parameters
                    "r" (value)   // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findFirstBit64(u64 value)
    {
        if (value == 0)
        {
            return 0;
        }



        u64 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfq  %1, %0"   // bsfq   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                 // Output parameters
                    "=r" (res)    // 'r' - any general register, '=' - write only
                :                 // Input parameters
                    "r" (value)   // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findFirstZero16(u16 value)
    {
        if (value == (u16)-1LL)
        {
            return 0;
        }



        u16 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfw  %1, %0"       // bsfw   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((u16)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findFirstZero32(u32 value)
    {
        if (value == (u32)-1LL)
        {
            return 0;
        }



        u32 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfl  %1, %0"       // bsfl   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((u32)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findFirstZero64(u64 value)
    {
        if (value == (u64)-1LL)
        {
            return 0;
        }



        u64 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfq  %1, %0"       // bsfq   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((u64)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findLastBit16(u16 value)
    {
        if (value == 0)
        {
            return 0;
        }



        u16 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrw   %1, %0"       // bsrw   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                 // Output parameters
                    "=r" (res)    // 'r' - any general register, '=' - write only
                :                 // Input parameters
                    "r" (value)   // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findLastBit32(u32 value)
    {
        if (value == 0)
        {
            return 0;
        }



        u32 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrl   %1, %0"       // bsrl   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                 // Output parameters
                    "=r" (res)    // 'r' - any general register, '=' - write only
                :                 // Input parameters
                    "r" (value)   // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findLastBit64(u64 value)
    {
        if (value == 0)
        {
            return 0;
        }



        u64 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrq   %1, %0"       // bsrq   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                 // Output parameters
                    "=r" (res)    // 'r' - any general register, '=' - write only
                :                 // Input parameters
                    "r" (value)   // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findLastZero16(u16 value)
    {
        if (value == (u16)-1LL)
        {
            return 0;
        }



        u16 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrw   %1, %0"           // bsrw   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((u16)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findLastZero32(u32 value)
    {
        if (value == (u32)-1LL)
        {
            return 0;
        }



        u32 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrl   %1, %0"           // bsrl   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((u32)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline u8 findLastZero64(u64 value)
    {
        if (value == (u64)-1LL)
        {
            return 0;
        }



        u64 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrq   %1, %0"           // bsrq   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((u64)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline i8 getCountOrder16(u16 value)
    {
        if (IS_POWER_OF_2(value))
        {
            return (i8)(findLastBit16(value) - 1);
        }
        else
        {
            return (i8)findLastBit16(value);
        }
    }

    static inline i8 getCountOrder32(u32 value)
    {
        if (IS_POWER_OF_2(value))
        {
            return (i8)(findLastBit32(value) - 1);
        }
        else
        {
            return (i8)findLastBit32(value);
        }
    }

    static inline i8 getCountOrder64(u64 value)
    {
        if (IS_POWER_OF_2(value))
        {
            return (i8)(findLastBit64(value) - 1);
        }
        else
        {
            return (i8)findLastBit64(value);
        }
    }
};



#endif // COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H
