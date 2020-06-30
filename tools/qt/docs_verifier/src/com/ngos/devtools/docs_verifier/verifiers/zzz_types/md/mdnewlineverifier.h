#ifndef DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDNEWLINEVERIFIER_H
#define DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDNEWLINEVERIFIER_H



#include "src/verifiers/basedocsverifier.h"



class MdNewLineVerifier: public BaseDocsVerifier
{
public:
    MdNewLineVerifier(); // TEST: NO

    void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDNEWLINEVERIFIER_H
