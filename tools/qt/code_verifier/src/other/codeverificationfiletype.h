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
    MAKEFILE = (1ULL << 4),
    PRO      = (1ULL << 5),
    PRI      = (1ULL << 6),
    LD       = (1ULL << 7),
    SH       = (1ULL << 8),
    INCLUDES = (1ULL << 9),
    XML      = (1ULL << 10),
    UI       = (1ULL << 11),
    QRC      = (1ULL << 12)
};



#endif // CODE_VERIFIER_SRC_OTHER_CODEVERIFICATIONFILETYPE_H
