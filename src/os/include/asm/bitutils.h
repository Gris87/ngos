#ifndef ASM_BITUTILS_H
#define ASM_BITUTILS_H



#include <asm/instructions.h>
#include <ngos/linkage.h>
#include <ngos/status.h>
#include <ngos/types.h>



#define CONST_BIT_ADDRESS(address, bit) (u8 *)((u64)(address) + ((bit) >> 3)) // TEST: NO // ">> 3" == "/ 8"
#define CONST_BIT_IN_U8(bit)            (1ULL << ((bit) & 7))                 // TEST: NO



class BitUtils
{
public:
    static inline bool test(u8 *address, u64 bit) // TEST: NO
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

    static inline NgosStatus set(u8 *address, u64 bit) // TEST: NO
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "orb     %1, %0"                                    // orb     %rax, (%rbx) # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                               // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))     // "m" == use memory, "+" - read and write
                    :                                               // Input parameters
                        "i" (CONST_BIT_IN_U8(bit))                  // "i" == integer constant // Ignore CppSingleCharVerifier
                    :                                               // Clobber list
                        "memory"                                    // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return btsPure(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus setSafe(u8 *address, u64 bit) // TEST: NO
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock orb    %1, %0"                                // lock orb    %rax, (%rbx) # lock - CPU will lock system Bus until instruction finish # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                               // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))     // "m" == use memory, "+" - read and write
                    :                                               // Input parameters
                        "i" (CONST_BIT_IN_U8(bit))                  // "i" == integer constant // Ignore CppSingleCharVerifier
                    :                                               // Clobber list
                        "memory"                                    // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return btsPureSafe(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus clear(u8 *address, u64 bit) // TEST: NO
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "andb    %1, %0"                                    // andb    %rax, (%rbx) # Clears bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                               // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))     // "m" == use memory, "+" - read and write
                    :                                               // Input parameters
                        "i" ((u8)~CONST_BIT_IN_U8(bit))             // "i" == integer constant // Ignore CppSingleCharVerifier
                    :                                               // Clobber list
                        "memory"                                    // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return btrPure(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus clearSafe(u8 *address, u64 bit) // TEST: NO
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock andb   %1, %0"                                // lock andb   %rax, (%rbx) # lock - CPU will lock system Bus until instruction finish # Clears bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                               // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))     // "m" == use memory, "+" - read and write
                    :                                               // Input parameters
                        "i" ((u8)~CONST_BIT_IN_U8(bit))             // "i" == integer constant // Ignore CppSingleCharVerifier
                    :                                               // Clobber list
                        "memory"                                    // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return btrPureSafe(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus invert(u8 *address, u64 bit) // TEST: NO
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "xorb    %1, %0"                                    // xorb    %rax, (%rbx) # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                               // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))     // "m" == use memory, "+" - read and write
                    :                                               // Input parameters
                        "i" (CONST_BIT_IN_U8(bit))                  // "i" == integer constant // Ignore CppSingleCharVerifier
                    :                                               // Clobber list
                        "memory"                                    // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return btcPure(address, bit);
        }

        return NgosStatus::OK;
    }

    static inline NgosStatus invertSafe(u8 *address, u64 bit) // TEST: NO
    {
        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "lock xorb   %1, %0"                                // lock xorb   %rax, (%rbx) # lock - CPU will lock system Bus until instruction finish # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
                    :                                               // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit))     // "m" == use memory, "+" - read and write
                    :                                               // Input parameters
                        "i" (CONST_BIT_IN_U8(bit))                  // "i" == integer constant // Ignore CppSingleCharVerifier
                    :                                               // Clobber list
                        "memory"                                    // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            return btcPureSafe(address, bit);
        }

        return NgosStatus::OK;
    }
};



#endif // ASM_BITUTILS_H
