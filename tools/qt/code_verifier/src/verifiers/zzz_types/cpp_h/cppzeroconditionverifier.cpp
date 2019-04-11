#include "cppzeroconditionverifier.h"

#include "src/other/codeverificationfiletype.h"



CppZeroConditionVerifier::CppZeroConditionVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mIndexRegExp("^.*index\\d* *(<=|>|==|!=) *\\d+.*$")
{
    // Nothing
}

void CppZeroConditionVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    if (path.endsWith("/cppzeroconditionverifier.cpp"))
    {
        return;
    }



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppZeroConditionVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        QString lineTrimmed = line.trimmed();

        if (lineTrimmed.contains("ASSERT("))
        {
            continue;
        }



        qint64 index = -1;

        do
        {
            index = lineTrimmed.indexOf('0', index + 1);

            if (index < 0)
            {
                break;
            }

            if (
                index < lineTrimmed.length() - 1
                &&
                lineTrimmed.at(index + 1) == 'x'
               )
            {
                lineTrimmed.remove(index, 2);

                while (
                       index < lineTrimmed.length() - 1
                       &&
                       lineTrimmed.at(index) == '0'
                       &&
                       (
                        (
                         lineTrimmed.at(index + 1) >= '0'
                         &&
                         lineTrimmed.at(index + 1) <= '9'
                        )
                        ||
                        (
                         lineTrimmed.at(index + 1) >= 'a'
                         &&
                         lineTrimmed.at(index + 1) <= 'f'
                        )
                        ||
                        (
                         lineTrimmed.at(index + 1) >= 'A'
                         &&
                         lineTrimmed.at(index + 1) <= 'F'
                        )
                       )
                      )
                {
                    lineTrimmed.remove(index, 1);
                }
            }
        } while(true);



        if (lineTrimmed.contains(" == 0"))
        {
            worker->addWarning(path, i, "Condition \" == 0\" can be simplified");
        }

        if (lineTrimmed.contains(" != 0"))
        {
            worker->addWarning(path, i, "Condition \" != 0\" can be simplified");
        }

        if (lineTrimmed.contains("size() > 0"))
        {
            worker->addWarning(path, i, "Condition \"size() > 0\" can be simplified");
        }

        if (lineTrimmed.contains("size() >= 0"))
        {
            worker->addWarning(path, i, "Condition \"size() >= 0\" always true");
        }

        if (lineTrimmed.contains("size() < 0"))
        {
            worker->addWarning(path, i, "Condition \"size() < 0\" always false");
        }

        if (lineTrimmed.contains("size() <= 0"))
        {
            worker->addWarning(path, i, "Condition \"size() <= 0\" can be simplified");
        }

        if (lineTrimmed.contains("length() > 0"))
        {
            worker->addWarning(path, i, "Condition \"length() > 0\" can be simplified");
        }

        if (lineTrimmed.contains("length() >= 0"))
        {
            worker->addWarning(path, i, "Condition \"length() >= 0\" always true");
        }

        if (lineTrimmed.contains("length() < 0"))
        {
            worker->addWarning(path, i, "Condition \"length() < 0\" always false");
        }

        if (lineTrimmed.contains("length() <= 0"))
        {
            worker->addWarning(path, i, "Condition \"length() <= 0\" can be simplified");
        }



        QRegularExpressionMatch match = mIndexRegExp.match(lineTrimmed);

        if (match.hasMatch())
        {
            worker->addError(path, i, "Invalid condition for index");
        }
    }
}



CppZeroConditionVerifier cppZeroConditionVerifierInstance;
