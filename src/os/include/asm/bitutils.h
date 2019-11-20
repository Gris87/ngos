#ifndef ASM_BITUTILS_H
#define ASM_BITUTILS_H



#include <asm/instructions.h>
#include <ngos/linkage.h>
#include <ngos/status.h>
#include <ngos/types.h>
#include <ngos/utils.h>



#define CONST_BIT_ADDRESS(address, bit) (u8 *)((u64)(address) + ((bit) >> 3))  // ">> 3" == "/ 8"
#define CONST_BIT_IN_U8(bit)            (1ULL << ((bit) & 7))



class BitUtils
{
public:
    static inline bool test(u8 *address, u64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            return *CONST_BIT_ADDRESS(address, bit) & CONST_BIT_IN_U8(bit);
        }
        else
        {
            return bt(address, bit);
        }
    }

    static inline NgosStatus set(u8 *address, u64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "orb    %1, %0"                                   // orb    %rax, (%rbx)    # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
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
            return btsPure(address, bit);
        }

        return NgosStatus::OK;
    }

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
            return btsPureSafe(address, bit);
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
            return btrPure(address, bit);
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
            return btrPureSafe(address, bit);
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
            return btcPure(address, bit);
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
            return btcPureSafe(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline u8 findFirstBit16(u16 value)
    {
        if (!value) // value == 0
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
        if (!value) // value == 0
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
        if (!value) // value == 0
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
        if (!value) // value == 0
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
        if (!value) // value == 0
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
        if (!value) // value == 0
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



#endif // ASM_BITUTILS_H
