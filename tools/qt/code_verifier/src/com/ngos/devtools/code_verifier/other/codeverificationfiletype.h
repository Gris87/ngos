#ifndef CODE_VERIFIER_SRC_OTHER_CODEVERIFICATIONFILETYPE_H
#define CODE_VERIFIER_SRC_OTHER_CODEVERIFICATIONFILETYPE_H



#include <Qt>
#include <ngos/types.h>
#include <stdio.h>



#define VERIFICATION_ANY_FILE_TYPE 0xFFFFFFFFFFFFFFFF

#define VERIFICATION_COMMON_CPP \
    ( \
        (quint64)CodeVerificationFileType::CPP \
        | (quint64)CodeVerificationFileType::H \
    )

#define VERIFICATION_AVOID_TABS \
    ( \
        (quint64)CodeVerificationFileType::TEXT \
        | (quint64)CodeVerificationFileType::CPP \
        | (quint64)CodeVerificationFileType::H \
        | (quint64)CodeVerificationFileType::S \
        | (quint64)CodeVerificationFileType::PHP \
        | (quint64)CodeVerificationFileType::PRO \
        | (quint64)CodeVerificationFileType::PRI \
        | (quint64)CodeVerificationFileType::LD \
        | (quint64)CodeVerificationFileType::SH \
        | (quint64)CodeVerificationFileType::INCLUDES \
        | (quint64)CodeVerificationFileType::XML \
        | (quint64)CodeVerificationFileType::UI \
        | (quint64)CodeVerificationFileType::QRC \
    )

#define VERIFICATION_INDENT_SPACES \
    ( \
        (quint64)CodeVerificationFileType::PRO \
        | (quint64)CodeVerificationFileType::PRI \
        | (quint64)CodeVerificationFileType::LD \
        | (quint64)CodeVerificationFileType::SH \
        | (quint64)CodeVerificationFileType::INCLUDES \
        | (quint64)CodeVerificationFileType::XML \
        | (quint64)CodeVerificationFileType::QRC \
    )

#define VERIFICATION_INDENT_TABS \
    ( \
        (quint64)CodeVerificationFileType::MAKEFILE \
    )



enum class CodeVerificationFileType: quint64 // Ignore CppEnumVerifier
{
    NONE     = 0,
    TEXT     = (1ULL << 0),
    CPP      = (1ULL << 1),
    H        = (1ULL << 2),
    S        = (1ULL << 3),
    PHP      = (1ULL << 4),
    MAKEFILE = (1ULL << 5),
    PRO      = (1ULL << 6),
    PRI      = (1ULL << 7),
    LD       = (1ULL << 8),
    SH       = (1ULL << 9),
    INCLUDES = (1ULL << 10),
    XML      = (1ULL << 11),
    UI       = (1ULL << 12),
    QRC      = (1ULL << 13)
};



inline const char8* enumToString(CodeVerificationFileType type) // TEST: NO
{
    switch (type)
    {
        case CodeVerificationFileType::NONE:     return "NONE";
        case CodeVerificationFileType::TEXT:     return "TEXT";
        case CodeVerificationFileType::CPP:      return "CPP";
        case CodeVerificationFileType::H:        return "H"; // Ignore CppSingleCharVerifier
        case CodeVerificationFileType::S:        return "S"; // Ignore CppSingleCharVerifier
        case CodeVerificationFileType::PHP:      return "PHP";
        case CodeVerificationFileType::MAKEFILE: return "MAKEFILE";
        case CodeVerificationFileType::PRO:      return "PRO";
        case CodeVerificationFileType::PRI:      return "PRI";
        case CodeVerificationFileType::LD:       return "LD";
        case CodeVerificationFileType::SH:       return "SH";
        case CodeVerificationFileType::INCLUDES: return "INCLUDES";
        case CodeVerificationFileType::XML:      return "XML";
        case CodeVerificationFileType::UI:       return "UI";
        case CodeVerificationFileType::QRC:      return "QRC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(CodeVerificationFileType type) // TEST: NO
{
    static char8 res[30];

    sprintf(res, "0x%016llX (%s)", (quint64)type, enumToString(type));

    return res;
}



#endif // CODE_VERIFIER_SRC_OTHER_CODEVERIFICATIONFILETYPE_H
