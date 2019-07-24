#ifndef DOCS_VERIFIER_SRC_OTHER_DOCSVERIFICATIONFILETYPE_H
#define DOCS_VERIFIER_SRC_OTHER_DOCSVERIFICATIONFILETYPE_H



#include <Qt>



#define VERIFICATION_ANY_FILE_TYPE 0xFFFFFFFFFFFFFFFF



enum class DocsVerificationFileType: quint64
{
    NONE = 0,
    TEXT = (1ULL << 0),
    MD   = (1ULL << 1)
};



inline const char* verificationFileTypeToString(DocsVerificationFileType type) // TEST: NO
{
    switch (type)
    {
        case DocsVerificationFileType::NONE: return "NONE";
        case DocsVerificationFileType::TEXT: return "TEXT";
        case DocsVerificationFileType::MD:   return "MD";

        default: return "UNKNOWN";
    }
}



#endif // DOCS_VERIFIER_SRC_OTHER_DOCSVERIFICATIONFILETYPE_H
