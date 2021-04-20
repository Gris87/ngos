#include "asmcommentsverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



#define COMMENT_POS 80



AsmCommentsVerifier::AsmCommentsVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::S)
{
    // Nothing
}

void AsmCommentsVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "# AsmCommentsVerifier");
        // removeComments(line); // Can't remove comments



        if (line.size() > COMMENT_POS && line.at(COMMENT_POS) == '#')
        {
            QString left         = line.left(COMMENT_POS);
            QString right        = line.mid(COMMENT_POS + 1);
            QString leftTrimmed  = left.trimmed();
            QString rightTrimmed = right.trimmed();

            if (leftTrimmed.size() < COMMENT_POS - 1)
            {
                if (leftTrimmed != "" && !leftTrimmed.startsWith('#'))
                {
                    if (rightTrimmed == "")
                    {
                        worker->addError(path, i, "Comment absent");
                    }
                    else
                    if (rightTrimmed.startsWith('?'))
                    {
                        worker->addWarning(path, i, "Comment should be updated");
                    }
                }
            }
            else
            {
                if (line.startsWith('#'))
                {
                    if (left == "# ----------------------------------------------------------------------------- ")
                    {
                        if (right != " -----------------------------------------------------------------------------")
                        {
                            worker->addError(path, i, "Unexpected comment");
                        }
                    }
                    else
                    if (left == "# ============================================================================= ")
                    {
                        if (right != " =============================================================================")
                        {
                            worker->addError(path, i, "Unexpected comment");
                        }
                    }
                    else
                    {
                        worker->addError(path, i, "Too long code");
                    }
                }
                else
                {
                    worker->addError(path, i, "Too long code");
                }
            }
        }
        else
        {
            if (
                !line.startsWith("#include ")
                &&
                !line.startsWith("#if")
                &&
                !line.startsWith("#else")
                &&
                !line.startsWith("#elif")
                &&
                !line.startsWith("#endif")
                &&
                !line.endsWith('\\')
                &&
                (
                 i <= 0
                 ||
                 !lines.at(i - 1).endsWith('\\')
                )
                &&
                i < lines.size() - 1
               )
            {
                worker->addError(path, i, QString("Comment absent in position %1").arg(COMMENT_POS));
            }
        }
    }
}



AsmCommentsVerifier asmCommentsVerifierInstance;
