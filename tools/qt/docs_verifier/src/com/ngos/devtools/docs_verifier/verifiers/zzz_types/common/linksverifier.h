#ifndef COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_LINKSVERIFIER_H                                                                                                                       // Colorize: green
#define COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_LINKSVERIFIER_H                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/docs_verifier/verifiers/basedocsverifier.h>                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QRegularExpression>                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class LinksVerifier: public BaseDocsVerifier                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    LinksVerifier(); // TEST: NO                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    QRegularExpression mLinkRegExp;                                                                                                                                                                      // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_LINKSVERIFIER_H                                                                                                                     // Colorize: green
