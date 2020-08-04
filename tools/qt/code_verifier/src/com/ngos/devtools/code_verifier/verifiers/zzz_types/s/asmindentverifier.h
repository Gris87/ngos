#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_S_ASMINDENTVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_S_ASMINDENTVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>

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



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_S_ASMINDENTVERIFIER_H
