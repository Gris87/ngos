#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEVERIFICATIONFILETYPE_H                                                                                                                                 // Colorize: green
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEVERIFICATIONFILETYPE_H                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <Qt>                                                                                                                                                                                            // Colorize: green
#include <stdio.h>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/flags.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VERIFICATION_ANY_FILE_TYPE 0xFFFFFFFFFFFFFFFF                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VERIFICATION_COMMON_CPP \
    FLAGS( \
        CodeVerificationFileType::CPP, \
        CodeVerificationFileType::H \
    )                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VERIFICATION_AVOID_TABS \
    FLAGS( \
        CodeVerificationFileType::TEXT, \
        CodeVerificationFileType::CPP, \
        CodeVerificationFileType::H, \
        CodeVerificationFileType::S, \
        CodeVerificationFileType::PHP, \
        CodeVerificationFileType::PRO, \
        CodeVerificationFileType::PRI, \
        CodeVerificationFileType::LD, \
        CodeVerificationFileType::SH, \
        CodeVerificationFileType::INCLUDES, \
        CodeVerificationFileType::XML, \
        CodeVerificationFileType::UI, \
        CodeVerificationFileType::QRC \
    )                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VERIFICATION_INDENT_SPACES \
    FLAGS( \
        CodeVerificationFileType::PRO, \
        CodeVerificationFileType::PRI, \
        CodeVerificationFileType::LD, \
        CodeVerificationFileType::SH, \
        CodeVerificationFileType::INCLUDES, \
        CodeVerificationFileType::XML, \
        CodeVerificationFileType::QRC \
    )                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VERIFICATION_INDENT_TABS \
    FLAGS( \
        CodeVerificationFileType::MAKEFILE \
    )                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class CodeVerificationFileType: quint64                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE     = 0,                                                                                                                                                                                        // Colorize: green
    TEXT     = (1ULL << 0),                                                                                                                                                                              // Colorize: green
    CPP      = (1ULL << 1),                                                                                                                                                                              // Colorize: green
    H        = (1ULL << 2),                                                                                                                                                                              // Colorize: green
    S        = (1ULL << 3),                                                                                                                                                                              // Colorize: green
    PHP      = (1ULL << 4),                                                                                                                                                                              // Colorize: green
    MAKEFILE = (1ULL << 5),                                                                                                                                                                              // Colorize: green
    PRO      = (1ULL << 6),                                                                                                                                                                              // Colorize: green
    PRI      = (1ULL << 7),                                                                                                                                                                              // Colorize: green
    LD       = (1ULL << 8),                                                                                                                                                                              // Colorize: green
    SH       = (1ULL << 9),                                                                                                                                                                              // Colorize: green
    INCLUDES = (1ULL << 10),                                                                                                                                                                             // Colorize: green
    XML      = (1ULL << 11),                                                                                                                                                                             // Colorize: green
    UI       = (1ULL << 12),                                                                                                                                                                             // Colorize: green
    QRC      = (1ULL << 13)                                                                                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(CodeVerificationFileType type) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    switch (type)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CodeVerificationFileType::NONE:     return "NONE";                                                                                                                                          // Colorize: green
        case CodeVerificationFileType::TEXT:     return "TEXT";                                                                                                                                          // Colorize: green
        case CodeVerificationFileType::CPP:      return "CPP";                                                                                                                                           // Colorize: green
        case CodeVerificationFileType::H:        return "H"; // Ignore CppSingleCharVerifier                                                                                                             // Colorize: green
        case CodeVerificationFileType::S:        return "S"; // Ignore CppSingleCharVerifier                                                                                                             // Colorize: green
        case CodeVerificationFileType::PHP:      return "PHP";                                                                                                                                           // Colorize: green
        case CodeVerificationFileType::MAKEFILE: return "MAKEFILE";                                                                                                                                      // Colorize: green
        case CodeVerificationFileType::PRO:      return "PRO";                                                                                                                                           // Colorize: green
        case CodeVerificationFileType::PRI:      return "PRI";                                                                                                                                           // Colorize: green
        case CodeVerificationFileType::LD:       return "LD";                                                                                                                                            // Colorize: green
        case CodeVerificationFileType::SH:       return "SH";                                                                                                                                            // Colorize: green
        case CodeVerificationFileType::INCLUDES: return "INCLUDES";                                                                                                                                      // Colorize: green
        case CodeVerificationFileType::XML:      return "XML";                                                                                                                                           // Colorize: green
        case CodeVerificationFileType::UI:       return "UI";                                                                                                                                            // Colorize: green
        case CodeVerificationFileType::QRC:      return "QRC";                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(CodeVerificationFileType type) // TEST: NO                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    static char8 res[30];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%016llX (%s)", (enum_t)type, enumToString(type));                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEVERIFICATIONFILETYPE_H                                                                                                                               // Colorize: green
