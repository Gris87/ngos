#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_BASECODEVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_BASECODEVERIFIER_H



#include <QList>

#include <com/ngos/devtools/code_verifier/other/codefileinfo.h>
#include <com/ngos/devtools/code_verifier/threads/codeworkerthread.h>



#define VERIFIER_IGNORE(line, comment) \
    if (line.contains(comment)) \
    { \
        continue; \
    }

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
    }



class BaseCodeVerifier
{
public:
    BaseCodeVerifier(CodeVerificationFileType verification); // TEST: NO
    BaseCodeVerifier(quint64 verification); // TEST: NO

    static void verifyAll(CodeWorkerThread *worker, CodeFileInfo *fileInfo, const QString &content, const QStringList &lines); // TEST: NO

    static quint64 getAmountOfChecks(); // TEST: NO

protected:
    virtual void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines); // TEST: NO

    void removeComments(QString &line); // TEST: NO
    void removeStrings(QString &line); // TEST: NO

    QString logPrefixFromPath(const QString &path); // TEST: NO
    QString traceCommandFromPath(const QString &path); // TEST: NO

private:
    static QList<BaseCodeVerifier *> sVerifiers;
    static quint64                   sAmountOfChecks;

    quint64 mVerification;
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_BASECODEVERIFIER_H
