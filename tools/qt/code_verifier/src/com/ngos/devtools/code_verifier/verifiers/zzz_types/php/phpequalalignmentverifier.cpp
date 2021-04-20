#include "phpequalalignmentverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



struct EqualEntry
{
    qint64 indent;
    qint64 beforeSpaces;
    qint64 equalIndex;
    qint64 afterSpaces;
    qint64 valueIndex;
};



PhpEqualAlignmentVerifier::PhpEqualAlignmentVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
    , mEqualExpressionRegExp("^( *)(\\$\\w[\\w\\->]*(?:\\[[^\\]]+\\])*)(( *)([+\\-*\\/<>=&|^!.]*=)( *)(.*))?; *$")
{
    // Nothing
}

void PhpEqualAlignmentVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QList<EqualEntry> ranges;

        for (; i < lines.size(); ++i) // Ignore CppForVerifier
        {
            QString line = lines.at(i);
            VERIFIER_IGNORE(line, "// Ignore PhpEqualAlignmentVerifier");
            removeComments(line);



            QRegularExpressionMatch match = mEqualExpressionRegExp.match(line);

            if (!match.hasMatch())
            {
                if (!ranges.isEmpty())
                {
                    for (qint64 j = 1; j < ranges.size(); ++j)
                    {
                        const EqualEntry &first   = ranges.constFirst();
                        const EqualEntry &current = ranges.at(j);



                        if (first.indent != current.indent)
                        {
                            worker->addError(path, i, "Indentation is invalid");
                        }



                        if (
                            first.beforeSpaces >= 0
                            &&
                            current.beforeSpaces >= 0
                            &&
                            (
                             first.equalIndex != current.equalIndex
                             ||
                             first.valueIndex != current.valueIndex
                            )
                           )
                        {
                            worker->addWarning(path, i, "Alignment required for equal sign");
                        }
                    }



                    bool haveExpression = false;
                    bool spaceBeforeOk  = false;
                    bool spaceAfterOk   = false;



                    for (qint64 j = 0; j < ranges.size(); ++j)
                    {
                        const EqualEntry &current = ranges.at(j);



                        if (current.beforeSpaces >= 0)
                        {
                            haveExpression = true;
                        }

                        if (current.beforeSpaces == 1)
                        {
                            spaceBeforeOk = true;
                        }

                        if (current.afterSpaces == 1)
                        {
                            spaceAfterOk = true;
                        }
                    }

                    if (haveExpression)
                    {
                        if (!spaceBeforeOk)
                        {
                            worker->addWarning(path, i, "Single space not found before equal sign");
                        }

                        if (!spaceAfterOk)
                        {
                            worker->addWarning(path, i, "Single space not found after equal sign");
                        }
                    }
                }



                break;
            }



            QString indent       = match.captured(1);
            QString name         = match.captured(2);
            QString expression   = match.captured(3);
            QString beforeSpaces = match.captured(4);
            QString afterSpaces  = match.captured(6);



            EqualEntry equalEntry;

            equalEntry.indent       = indent.size();
            equalEntry.beforeSpaces = expression != "" ? beforeSpaces.size() : -1;
            equalEntry.equalIndex   = match.capturedStart(5);
            equalEntry.afterSpaces  = expression != "" ? afterSpaces.size() : -1;
            equalEntry.valueIndex   = match.capturedStart(7);



            if (name != "")
            {
                if (
                    (name.at(1) < 'a' || name.at(1) > 'z')
                    &&
                    name != "$_POST"
                   )
                {
                    worker->addError(path, i, "Variable name should be named in camelcase");
                }
            }
            else
            {
                worker->addError(path, i, "Name is empty");
            }



            if (expression != "")
            {
                if (beforeSpaces == "")
                {
                    worker->addError(path, i, QString("Space not found before equal sign at position %1").arg(equalEntry.equalIndex));
                }

                if (afterSpaces == "")
                {
                    worker->addError(path, i, QString("Space not found after equal sign at position %1").arg(equalEntry.valueIndex));
                }
            }



            ranges.append(equalEntry);
        }
    }
}



PhpEqualAlignmentVerifier phpEqualAlignmentVerifierInstance;
