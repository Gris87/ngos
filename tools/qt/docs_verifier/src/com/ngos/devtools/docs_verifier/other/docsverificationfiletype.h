#ifndef DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSVERIFICATIONFILETYPE_H
#define DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSVERIFICATIONFILETYPE_H



#include <Qt>
#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <stdio.h>



#define VERIFICATION_ANY_FILE_TYPE 0xFFFFFFFFFFFFFFFF



enum class DocsVerificationFileType: quint64 // Ignore CppEnumVerifier
{
    NONE = 0,
    TEXT = (1ULL << 0),
    MD   = (1ULL << 1)
};



inline const char8* enumToString(DocsVerificationFileType type) // TEST: NO
{
    switch (type)
    {
        case DocsVerificationFileType::NONE: return "NONE";
        case DocsVerificationFileType::TEXT: return "TEXT";
        case DocsVerificationFileType::MD:   return "MD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DocsVerificationFileType type) // TEST: NO
{
    static char8 res[29];

    sprintf(res, "0x%016llX (%s)", (quint64)type, enumToString(type));

    return res;
}



#endif // DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_OTHER_DOCSVERIFICATIONFILETYPE_H
