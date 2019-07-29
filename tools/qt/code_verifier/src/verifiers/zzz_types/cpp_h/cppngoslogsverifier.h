#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSLOGSVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSLOGSVERIFIER_H



#include "src/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class CppNgosLogsVerifier: public BaseCodeVerifier
{
public:
    CppNgosLogsVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mDefinitionRegExp;
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSLOGSVERIFIER_H
