#include "asmindentverifier.h"

#include "src/other/codeverificationfiletype.h"



// Ignore CppAlignmentVerifier [BEGIN]
AsmIndentVerifier::AsmIndentVerifier()
    : BaseCodeVerifier(VerificationFileType::S)
    , mConstRegExp("^ *(\\w+) *=.*$")
    , mLabelRegExp("^(\\w+):.*$")
    , mOperationRegExp("^    (\\.?)(\\w{2,8})  .*$")
{
    // Nothing
}
// Ignore CppAlignmentVerifier [END]

void AsmIndentVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "# AsmIndentVerifier");



        if (
            !line.startsWith('#')
            &&
            !line.endsWith('\\')
            &&
            (
             i <= 0
             ||
             !lines.at(i - 1).endsWith('\\')
            )
            &&
            !line.startsWith(".code16")
            &&
            !line.startsWith(".code32")
            &&
            !line.startsWith(".code64")
            &&
            !line.startsWith(".data")
            &&
            !line.startsWith(".bss")
            &&
            !line.startsWith(".section")
            &&
            !line.startsWith(".balign")
            &&
            !line.startsWith(".align")
            &&
            !line.startsWith(".globl")
            &&
            (
             line.indexOf('(') <= 0
             ||
             line.left(line.indexOf('(')).toUpper() != line.left(line.indexOf('('))
            )
            &&
            !mConstRegExp.match(line).hasMatch()
            &&
            !mLabelRegExp.match(line).hasMatch()
           )
        {
            QString trimmedLine = line.trimmed();

            if (
                !trimmedLine.startsWith('#')
                &&
                !trimmedLine.startsWith("rep; ")
                &&
                i < lines.length() - 1
               )
            {
                if (
                    trimmedLine.startsWith(".code16")
                    ||
                    trimmedLine.startsWith(".code32")
                    ||
                    trimmedLine.startsWith(".code64")
                    ||
                    trimmedLine.startsWith(".data")
                    ||
                    trimmedLine.startsWith(".bss")
                    ||
                    trimmedLine.startsWith(".section")
                    ||
                    trimmedLine.startsWith(".balign")
                    ||
                    trimmedLine.startsWith(".align")
                    ||
                    trimmedLine.startsWith(".globl")
                    ||
                    mConstRegExp.match(trimmedLine).hasMatch()
                    ||
                    mLabelRegExp.match(trimmedLine).hasMatch()
                    ||
                    !mOperationRegExp.match(line).hasMatch()
                   )
                {
                    worker->addError(path, i, "Invalid indentation");
                }
            }
        }
    }
}



AsmIndentVerifier asmIndentVerifierInstance;
