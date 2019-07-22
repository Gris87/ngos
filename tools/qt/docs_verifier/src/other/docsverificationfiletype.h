#ifndef DOCS_VERIFIER_SRC_OTHER_DOCSVERIFICATIONFILETYPE_H
#define DOCS_VERIFIER_SRC_OTHER_DOCSVERIFICATIONFILETYPE_H



#include <Qt>



#define VERIFICATION_ANY_FILE_TYPE 0xFFFFFFFFFFFFFFFF



enum class VerificationFileType: quint64
{
    NONE = 0,
    TEXT = (1ULL << 0),
    MD   = (1ULL << 1)
};



inline const char* verificationFileTypeToString(VerificationFileType type) // TEST: NO
{
    switch (type)
    {
        case VerificationFileType::NONE: return "NONE";
        case VerificationFileType::TEXT: return "TEXT";
        case VerificationFileType::MD:   return "MD";

        default: return "UNKNOWN";
    }
}



#endif // DOCS_VERIFIER_SRC_OTHER_DOCSVERIFICATIONFILETYPE_H
