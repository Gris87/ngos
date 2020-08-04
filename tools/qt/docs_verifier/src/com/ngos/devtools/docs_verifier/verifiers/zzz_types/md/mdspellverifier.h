#ifndef COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_ZZZ_TYPES_MD_MDSPELLVERIFIER_H
#define COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_ZZZ_TYPES_MD_MDSPELLVERIFIER_H



#include <com/ngos/devtools/docs_verifier/verifiers/basedocsverifier.h>



class MdSpellVerifier: public BaseDocsVerifier
{
public:
    MdSpellVerifier(); // TEST: NO

    void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_ZZZ_TYPES_MD_MDSPELLVERIFIER_H
