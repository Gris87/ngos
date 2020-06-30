#ifndef DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDSTRUCTUREVERIFIER_H
#define DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDSTRUCTUREVERIFIER_H



#include "src/verifiers/basedocsverifier.h"

#include <QRegularExpression>



class MdStructureVerifier: public BaseDocsVerifier
{
public:
    MdStructureVerifier(); // TEST: NO

    void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mSectionIdRegExp;
    QRegularExpression mLinkRegExp;
};



#endif // DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_MD_MDSTRUCTUREVERIFIER_H
