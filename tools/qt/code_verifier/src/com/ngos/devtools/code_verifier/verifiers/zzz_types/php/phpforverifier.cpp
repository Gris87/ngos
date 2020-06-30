#include "phpforverifier.h"

#include "src/com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"



PhpForVerifier::PhpForVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
    , mInitRegexp("^\\$(\\w) = .+$")
    , mConditionRegexp("^\\$(\\w) [<>]=? .+$")
    , mStepRegexp("^[+-]{0,2}\\$(\\w)(?: [+-]= .+)?$")
{
    // Nothing
}

void PhpForVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpForVerifier");
        removeComments(line);



        if (line.trimmed().startsWith("for ("))
        {
            QStringList variablesStack;

            i = verifyCycleFor(worker, path, lines, i, variablesStack);
        }
    }
}

qint64 PhpForVerifier::verifyCycleFor(CodeWorkerThread *worker, const QString &path, const QStringList &lines, qint64 row, QStringList &variablesStack)
{
    QString line = lines.at(row);
    removeComments(line);

    qint64 index = line.indexOf('(');

    if (index >= 0)
    {
        qint64 index2 = line.lastIndexOf(')');

        if (index2 >= 0)
        {
            QStringList fields = line.mid(index + 1, index2 - index - 1).split(';');

            if (fields.length() == 3)
            {
                QRegularExpressionMatch initMatch      = mInitRegexp.match(fields.at(0).trimmed());
                QRegularExpressionMatch conditionMatch = mConditionRegexp.match(fields.at(1).trimmed());
                QRegularExpressionMatch stepMatch      = mStepRegexp.match(fields.at(2).trimmed());



                if (!initMatch.hasMatch())
                {
                    worker->addError(path, row, QString("Unexpected initialization field: %1").arg(fields.at(0).trimmed()));
                }

                if (!conditionMatch.hasMatch())
                {
                    worker->addError(path, row, QString("Unexpected condition field: %1").arg(fields.at(1).trimmed()));
                }

                if (!stepMatch.hasMatch())
                {
                    worker->addError(path, row, QString("Unexpected step field: %1").arg(fields.at(2).trimmed()));
                }



                QString varName = initMatch.captured(1);



                if (conditionMatch.captured(1) != varName)
                {
                    worker->addError(path, row, QString("Invalid variable usage. Expected %1").arg(varName));
                }



                if (stepMatch.captured(1) != varName)
                {
                    worker->addError(path, row, QString("Invalid variable usage. Expected %1").arg(varName));
                }



                if (variablesStack.contains(varName))
                {
                    worker->addError(path, row, "Variable already specified earlier");
                }



                QString spaces = line.left(line.indexOf("for ("));



                qint64 endRow = row + 1;

                while (endRow < lines.length() && lines.at(endRow) != spaces + '}')
                {
                    ++endRow;
                }



                variablesStack.append(varName);

                for (qint64 i = row + 1; i <= endRow; ++i)
                {
                    QString line = lines.at(i);
                    VERIFIER_IGNORE(line, "// Ignore PhpForVerifier");
                    removeComments(line);



                    if (line.trimmed().startsWith("for ("))
                    {
                        i = verifyCycleFor(worker, path, lines, i, variablesStack);
                    }
                }

                variablesStack.removeOne(varName);



                return endRow;
            }
            else
            {
                worker->addError(path, row, "Invalid format");
            }
        }
        else
        {
            worker->addError(path, row, "Expected closing bracket )");
        }
    }
    else
    {
        worker->addError(path, row, "Expected openning bracket (");
    }



    return row;
}



PhpForVerifier phpForVerifierInstance;
