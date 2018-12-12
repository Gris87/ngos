#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSTRACEVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSTRACEVERIFIER_H



#include "src/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class CppNgosTraceVerifier: public BaseCodeVerifier
{
public:
    CppNgosTraceVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mDefinitionRegExp;
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPNGOSTRACEVERIFIER_H
