#ifndef CODE_VERIFIER_SRC_VERIFIERS_BASECODEVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_BASECODEVERIFIER_H



#include <QList>

#include "src/other/codefileinfo.h"
#include "src/threads/codeworkerthread.h"



#define VERIFIER_REMOVE_COMMENTS(line) \
    { \
        qint64 index = line.indexOf("//"); \
        \
        if (index >= 0 && (!index || line.at(index - 1) != '\"') && (index >= line.length() - 2 || line.at(index + 2) != '\"')) \
        { \
            line = line.left(index); \
        } \
    }

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
        } while(i < lines.length() && !lines.at(i).contains(comment " [END]")); \
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
    BaseCodeVerifier(VerificationFileType verification); // TEST: NO
    BaseCodeVerifier(quint64 verification); // TEST: NO

    static void verifyAll(CodeWorkerThread *worker, CodeFileInfo *fileInfo, const QString &content, const QStringList &lines); // TEST: NO

    static quint64 getAmountOfVerifications(); // TEST: NO

protected:
    virtual void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines); // TEST: NO

private:
    static QList<BaseCodeVerifier *> sVerifiers;
    static quint64                   sAmountOfVerifications;

    quint64 mVerification;
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_BASECODEVERIFIER_H
