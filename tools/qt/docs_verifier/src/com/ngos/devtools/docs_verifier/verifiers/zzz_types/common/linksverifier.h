#ifndef DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_LINKSVERIFIER_H
#define DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_LINKSVERIFIER_H



#include "src/verifiers/basedocsverifier.h"

#include <QRegularExpression>



class LinksVerifier: public BaseDocsVerifier
{
public:
    LinksVerifier(); // TEST: NO

    void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mLinkRegExp;
};



#endif // DOCS_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_LINKSVERIFIER_H
