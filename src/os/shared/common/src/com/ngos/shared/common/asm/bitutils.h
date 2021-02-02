#ifndef COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H
#define COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H



#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/ngos/utils.h>



#define CONST_BIT_ADDRESS(address, bit) (bad_uint8 *)((bad_uint64)(address) + ((bit) / 8))
#define CONST_BIT_IN_bad_uint8(bit)            (1ULL << ((bit) & 7))



class BitUtils
{
public:
    static inline bool test(bad_uint8 *address, bad_uint64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            return *CONST_BIT_ADDRESS(address, bit) & CONST_BIT_IN_bad_uint8(bit);
        }
        else
        {
            return bt(address, bit);
        }
    }

    static inline NgosStatus set(bad_uint8 *address, bad_uint64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "orb    %1, %0"                                   // orb    %rax, (%rbx)    # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" (CONST_BIT_IN_bad_uint8(bit))                // 'i' - integer constant // Ignore CppSingleCharVerifier
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

    static inline NgosStatus setSafe(bad_uint8 *address, bad_uint64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock orb   %1, %0"                               // lock orb   %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" (CONST_BIT_IN_bad_uint8(bit))                // 'i' - integer constant // Ignore CppSingleCharVerifier
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

    static inline NgosStatus clear(bad_uint8 *address, bad_uint64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "andb   %1, %0"                                   // andb   %rax, (%rbx)    # Clears bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" ((bad_uint8)~CONST_BIT_IN_bad_uint8(bit))           // 'i' - integer constant // Ignore CppSingleCharVerifier
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

    static inline NgosStatus clearSafe(bad_uint8 *address, bad_uint64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock andb  %1, %0"                               // lock andb  %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Clears bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" ((bad_uint8)~CONST_BIT_IN_bad_uint8(bit))           // 'i' - integer constant // Ignore CppSingleCharVerifier
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

    static inline NgosStatus invert(bad_uint8 *address, bad_uint64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "xorb   %1, %0"                                   // xorb   %rax, (%rbx)    # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" (CONST_BIT_IN_bad_uint8(bit))                // 'i' - integer constant // Ignore CppSingleCharVerifier
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

    static inline NgosStatus invertSafe(bad_uint8 *address, bad_uint64 bit)
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock xorb  %1, %0"                               // lock xorb  %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                             // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))   // 'm' - use memory, '+' - read and write
                    :                                             // Input parameters
                        "i" (CONST_BIT_IN_bad_uint8(bit))                // 'i' - integer constant // Ignore CppSingleCharVerifier
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

    static inline bad_uint8 findFirstBit16(bad_uint16 value)
    {
        if (value == 0)
        {
            return 0;
        }



        bad_uint16 res;

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

    static inline bad_uint8 findFirstBit32(bad_uint32 value)
    {
        if (value == 0)
        {
            return 0;
        }



        bad_uint32 res;

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

    static inline bad_uint8 findFirstBit64(bad_uint64 value)
    {
        if (value == 0)
        {
            return 0;
        }



        bad_uint64 res;

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

    static inline bad_uint8 findFirstZero16(bad_uint16 value)
    {
        if (value == (bad_uint16)-1LL)
        {
            return 0;
        }



        bad_uint16 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfw  %1, %0"       // bsfw   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((bad_uint16)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline bad_uint8 findFirstZero32(bad_uint32 value)
    {
        if (value == (bad_uint32)-1LL)
        {
            return 0;
        }



        bad_uint32 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfl  %1, %0"       // bsfl   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((bad_uint32)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline bad_uint8 findFirstZero64(bad_uint64 value)
    {
        if (value == (bad_uint64)-1LL)
        {
            return 0;
        }



        bad_uint64 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rep; bsfq  %1, %0"       // bsfq   %rdx, %rax      # or tzcnt   %rdx, %rax if CPU supported # Find first bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((bad_uint64)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline bad_uint8 findLastBit16(bad_uint16 value)
    {
        if (value == 0)
        {
            return 0;
        }



        bad_uint16 res;

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

    static inline bad_uint8 findLastBit32(bad_uint32 value)
    {
        if (value == 0)
        {
            return 0;
        }



        bad_uint32 res;

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

    static inline bad_uint8 findLastBit64(bad_uint64 value)
    {
        if (value == 0)
        {
            return 0;
        }



        bad_uint64 res;

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

    static inline bad_uint8 findLastZero16(bad_uint16 value)
    {
        if (value == (bad_uint16)-1LL)
        {
            return 0;
        }



        bad_uint16 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrw   %1, %0"           // bsrw   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((bad_uint16)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline bad_uint8 findLastZero32(bad_uint32 value)
    {
        if (value == (bad_uint32)-1LL)
        {
            return 0;
        }



        bad_uint32 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrl   %1, %0"           // bsrl   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((bad_uint32)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline bad_uint8 findLastZero64(bad_uint64 value)
    {
        if (value == (bad_uint64)-1LL)
        {
            return 0;
        }



        bad_uint64 res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bsrq   %1, %0"           // bsrq   %rdx, %rax      # Find last bit in RDX and store result in RAX. %rax == res. %rdx == value
                :                     // Output parameters
                    "=r" (res)        // 'r' - any general register, '=' - write only
                :                     // Input parameters
                    "r" ((bad_uint64)~value) // 'r' - any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res + 1;
    }

    static inline bad_int8 getCountOrder16(bad_uint16 value)
    {
        if (IS_POWER_OF_2(value))
        {
            return (bad_int8)(findLastBit16(value) - 1);
        }
        else
        {
            return (bad_int8)findLastBit16(value);
        }
    }

    static inline bad_int8 getCountOrder32(bad_uint32 value)
    {
        if (IS_POWER_OF_2(value))
        {
            return (bad_int8)(findLastBit32(value) - 1);
        }
        else
        {
            return (bad_int8)findLastBit32(value);
        }
    }

    static inline bad_int8 getCountOrder64(bad_uint64 value)
    {
        if (IS_POWER_OF_2(value))
        {
            return (bad_int8)(findLastBit64(value) - 1);
        }
        else
        {
            return (bad_int8)findLastBit64(value);
        }
    }
};



#endif // COM_NGOS_SHARED_COMMON_ASM_BITUTILS_H
