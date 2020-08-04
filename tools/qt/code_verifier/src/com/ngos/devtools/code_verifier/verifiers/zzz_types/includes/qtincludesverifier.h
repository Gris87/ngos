#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_INCLUDES_QTINCLUDESVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_INCLUDES_QTINCLUDESVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>



class QtIncludesVerifier: public BaseCodeVerifier
{
public:
    QtIncludesVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
    void addSubfoldersWithQtPro(QStringList &block, const QString &parentFolder, const QString &path); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_INCLUDES_QTINCLUDESVERIFIER_H
