#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSLOGSVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSLOGSVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>

#include <QRegularExpression>



class CppNgosLogsVerifier: public BaseCodeVerifier
{
public:
    CppNgosLogsVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mDefinitionRegExp;
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSLOGSVERIFIER_H
