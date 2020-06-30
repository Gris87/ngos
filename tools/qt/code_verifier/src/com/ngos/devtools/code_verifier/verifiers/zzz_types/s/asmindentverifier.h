#ifndef CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_S_ASMINDENTVERIFIER_H
#define CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_S_ASMINDENTVERIFIER_H



#include "src/com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class AsmIndentVerifier: public BaseCodeVerifier
{
public:
    AsmIndentVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mConstRegExp;
    QRegularExpression mLabelRegExp;
    QRegularExpression mOperationRegExp;
};



#endif // CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_S_ASMINDENTVERIFIER_H
