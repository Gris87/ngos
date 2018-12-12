#ifndef DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDSPELLVERIFIER_H
#define DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDSPELLVERIFIER_H



#include "src/verifiers/basedocsverifier.h"



class MdSpellVerifier: public BaseDocsVerifier
{
public:
    MdSpellVerifier(); // TEST: NO

    void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDSPELLVERIFIER_H
