#ifndef CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPFORVERIFIER_H
#define CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPFORVERIFIER_H



#include "src/com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class CppForVerifier: public BaseCodeVerifier
{
public:
    CppForVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
    qint64 verifyCycleFor(CodeWorkerThread *worker, const QString &path, const QStringList &lines, qint64 row, QStringList &variablesStack); // TEST: NO

private:
    QRegularExpression mInitRegexp;
    QRegularExpression mConditionRegexp;
    QRegularExpression mStepRegexp;
    QRegularExpression mInitQHashRegexp;
    QRegularExpression mConditionQHashRegexp;
    QRegularExpression mStepQHashRegexp;
};



#endif // CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPFORVERIFIER_H
