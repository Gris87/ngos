#ifndef NGOS_LINKAGE_H
#define NGOS_LINKAGE_H



// Ignore CppAlignmentVerifier [BEGIN]
#define __ASM_NEWLINE ;

// TEST: NO
#define ENTRY(name) \
    .globl  name    __ASM_NEWLINE \
    name:

// TEST: NO
#define END_ENTRY(name) \
    .size   name, .-name

// TEST: NO
#define GLOBAL_FUNCTION(name) \
    .globl  name            __ASM_NEWLINE \
    .type   name, @function __ASM_NEWLINE \
    name:

// TEST: NO
#define END_FUNCTION(name) \
    END_ENTRY(name)
// Ignore CppAlignmentVerifier [END]



#ifdef __cplusplus
#define CPP_EXTERN_C extern "C" // Ignore CppExternDeclaredVerifier
#else
#define CPP_EXTERN_C
#endif



#define CPP_NO_OPTIMIZATION __attribute__((optimize("O0")))



#define AVOID_UNUSED(x) (void)x;



#define IS_CONSTANT(x) __builtin_constant_p(x)



#define FLAGS_TO_STRING(res, flags, typeToString, type) \
    { \
        char *cur = res; \
        *cur      = 0; \
        \
        u8 unknownCount = 0; \
        \
        \
        \
        for (i64 i = 0; i < (i64)(sizeof(flags) << 3); ++i) \
        { \
            u64 flag = (1ULL << i); \
            \
            if (flags & flag) \
            { \
                const char *flagString = typeToString((type)flag); \
                \
                if (!strcmp(flagString, "UNKNOWN")) \
                { \
                    ++unknownCount; \
                } \
                else \
                { \
                    if (cur != res) \
                    { \
                        cur = strapp(cur, " | "); \
                    } \
                    \
                    cur = strapp(cur, flagString); \
                } \
            } \
        } \
        \
        \
        \
        if (unknownCount) \
        { \
            if (cur != res) \
            { \
                cur = strapp(cur, " | "); \
            } \
            \
            \
            \
            if (unknownCount == 1) \
            { \
                strapp(cur, "UNKNOWN"); \
            } \
            else \
            { \
                sprintf(cur, "UNKNOWN x %u", unknownCount); \
            } \
        } \
    }



#endif // NGOS_LINKAGE_H
