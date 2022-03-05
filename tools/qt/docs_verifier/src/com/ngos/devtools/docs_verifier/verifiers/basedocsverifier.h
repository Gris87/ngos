#ifndef COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_BASEDOCSVERIFIER_H                                                                                                                                     // Colorize: green
#define COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_BASEDOCSVERIFIER_H                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QList>                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/docs_verifier/other/docsfileinfo.h>                                                                                                                                          // Colorize: green
#include <com/ngos/devtools/docs_verifier/threads/docsworkerthread.h>                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VERIFIER_IGNORE(line, comment) \
    if (line.contains(comment)) \
    { \
        continue; \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VERIFIER_IGNORE_REGION(lines, i, line, comment) \
    if (line.contains(comment " [BEGIN]")) \
    { \
        do \
        { \
            ++i; \
        } while(i < lines.size() && !lines.at(i).contains(comment " [END]")); \
        \
        continue; \
    } \
    else \
    { \
        VERIFIER_IGNORE(line, comment) \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class BaseDocsVerifier                                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    BaseDocsVerifier(DocsVerificationFileType verification); // TEST: NO                                                                                                                                 // Colorize: green
    BaseDocsVerifier(qint64 verification); // TEST: NO                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static void verifyAll(DocsWorkerThread *worker, DocsFileInfo *fileInfo, const QString &content, const QStringList &lines); // TEST: NO                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static qint64 getAmountOfChecks(); // TEST: NO                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
protected:                                                                                                                                                                                               // Colorize: green
    virtual void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) = 0; // TEST: NO                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void removeComments(QString &line); // TEST: NO                                                                                                                                                      // Colorize: green
    void removeStrings(QString &line); // TEST: NO                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    static QList<BaseDocsVerifier *> sVerifiers;                                                                                                                                                         // Colorize: green
    static qint64                    sAmountOfChecks;                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    qint64 mVerification;                                                                                                                                                                                // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_DOCS_VERIFIER_VERIFIERS_BASEDOCSVERIFIER_H                                                                                                                                   // Colorize: green
