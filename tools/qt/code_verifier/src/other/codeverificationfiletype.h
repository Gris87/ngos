#ifndef CODE_VERIFIER_SRC_OTHER_CODEVERIFICATIONFILETYPE_H
#define CODE_VERIFIER_SRC_OTHER_CODEVERIFICATIONFILETYPE_H



#include <Qt>



#define VERIFICATION_ANY_FILE_TYPE 0xFFFFFFFFFFFFFFFF

#define VERIFICATION_COMMON_CPP \
    ( \
        (quint64)VerificationFileType::CPP \
        | (quint64)VerificationFileType::H \
    )

#define VERIFICATION_AVOID_TABS \
    ( \
        (quint64)VerificationFileType::TEXT \
        | (quint64)VerificationFileType::CPP \
        | (quint64)VerificationFileType::H \
        | (quint64)VerificationFileType::S \
        | (quint64)VerificationFileType::PHP \
        | (quint64)VerificationFileType::PRO \
        | (quint64)VerificationFileType::PRI \
        | (quint64)VerificationFileType::LD \
        | (quint64)VerificationFileType::SH \
        | (quint64)VerificationFileType::INCLUDES \
        | (quint64)VerificationFileType::XML \
        | (quint64)VerificationFileType::UI \
        | (quint64)VerificationFileType::QRC \
    )

#define VERIFICATION_INDENT_SPACES \
    ( \
        (quint64)VerificationFileType::PRO \
        | (quint64)VerificationFileType::PRI \
        | (quint64)VerificationFileType::LD \
        | (quint64)VerificationFileType::SH \
        | (quint64)VerificationFileType::INCLUDES \
        | (quint64)VerificationFileType::XML \
        | (quint64)VerificationFileType::QRC \
    )

#define VERIFICATION_INDENT_TABS \
    ( \
        (quint64)VerificationFileType::MAKEFILE \
    )



enum class VerificationFileType: quint64
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



inline const char* verificationFileTypeToString(VerificationFileType type) // TEST: NO
{
    switch (type)
    {
        case VerificationFileType::NONE:     return "NONE";
        case VerificationFileType::TEXT:     return "TEXT";
        case VerificationFileType::CPP:      return "CPP";
        case VerificationFileType::H:        return "H"; // Ignore CppSingleCharVerifier
        case VerificationFileType::S:        return "S"; // Ignore CppSingleCharVerifier
        case VerificationFileType::PHP:      return "PHP";
        case VerificationFileType::MAKEFILE: return "MAKEFILE";
        case VerificationFileType::PRO:      return "PRO";
        case VerificationFileType::PRI:      return "PRI";
        case VerificationFileType::LD:       return "LD";
        case VerificationFileType::SH:       return "SH";
        case VerificationFileType::INCLUDES: return "INCLUDES";
        case VerificationFileType::XML:      return "XML";
        case VerificationFileType::UI:       return "UI";
        case VerificationFileType::QRC:      return "QRC";

        default: return "UNKNOWN";
    }
}



#endif // CODE_VERIFIER_SRC_OTHER_CODEVERIFICATIONFILETYPE_H
