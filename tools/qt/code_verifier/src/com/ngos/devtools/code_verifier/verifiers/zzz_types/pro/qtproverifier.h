#ifndef CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PRO_QTPROVERIFIER_H
#define CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PRO_QTPROVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>



class QtProVerifier: public BaseCodeVerifier
{
public:
    QtProVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
    void verifyDefinitions(CodeWorkerThread *worker, const QString &path, const QString &content); // TEST: NO
    void verifyFileBlocks(CodeWorkerThread *worker, const QString &path, const QStringList &lines); // TEST: NO
    qint64 verifyFilesBlock(CodeWorkerThread *worker, const QString &path, const QStringList &lines, qint64 startPos, const QString &extension); // TEST: NO
};



#endif // CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PRO_QTPROVERIFIER_H
