#include "cppequalalignmentverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



struct EqualEntry
{
    qint64 indent;
    qint64 nameIndex;
    qint64 beforeSpaces;
    qint64 equalIndex;
    qint64 afterSpaces;
    qint64 valueIndex;
};



CppEqualAlignmentVerifier::CppEqualAlignmentVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mEqualExpressionRegExp("^( *)((?:static|const) +)*(\\w[\\w<,>*& ]*)?( [&*]*)(?:\\w+::)*(\\w(?:[\\w\\.\\->]|\\[[^\\]]+\\])*)(( *)([+\\-*\\/<>=&|^!]*=)( *)(.*))?; *$")
{
    // Nothing
}

void CppEqualAlignmentVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QList<EqualEntry> ranges;

        for (; i < lines.size(); ++i) // Ignore CppForVerifier
        {
            QString line = lines.at(i);
            VERIFIER_IGNORE(line, "// Ignore CppEqualAlignmentVerifier");
            removeComments(line);



            QRegularExpressionMatch match = mEqualExpressionRegExp.match(line);

            if (
                line.contains("operator")
                ||
                !match.hasMatch()
               )
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
                            first.nameIndex != current.nameIndex
                            &&
                            first.nameIndex != first.indent
                            &&
                            current.nameIndex != current.indent
                           )
                        {
                            worker->addWarning(path, i, "Variable names should be aligned");
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
            QString keywords     = match.captured(2);
            QString type         = match.captured(3);
            QString reference    = match.captured(4);
            QString name         = match.captured(5);
            QString expression   = match.captured(6);
            QString beforeSpaces = match.captured(7);
            QString afterSpaces  = match.captured(9);



            if (
                type == "return"
                ||
                type == "delete"
                ||
                type == "struct"
                ||
                type == "class"
                ||
                type.startsWith("typedef")
               )
            {
                continue;
            }



            EqualEntry equalEntry;

            equalEntry.indent       = indent.length() + (type == "" ? reference.length() - reference.trimmed().length() : 0);
            equalEntry.nameIndex    = type != "" ? match.capturedStart(5) : equalEntry.indent;
            equalEntry.beforeSpaces = expression != "" ? beforeSpaces.length() : -1;
            equalEntry.equalIndex   = match.capturedStart(8);
            equalEntry.afterSpaces  = expression != "" ? afterSpaces.length() : -1;
            equalEntry.valueIndex   = match.capturedStart(10);



            if (name != "")
            {
                if (
                    (name.at(0) < 'a' || name.at(0) > 'z')
                    &&
                    !name.startsWith("__pad")
                    &&
                    !name.startsWith("__reserved")
                    &&
                    !keywords.contains("const")
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
                    worker->addError(path, i, QString("Space not found before equal sign at position %1")
                                                        .arg(equalEntry.equalIndex)
                                     );
                }

                if (afterSpaces == "")
                {
                    worker->addError(path, i, QString("Space not found after equal sign at position %1")
                                                        .arg(equalEntry.valueIndex)
                                     );
                }
            }



            ranges.append(equalEntry);
        }
    }
}



CppEqualAlignmentVerifier cppEqualAlignmentVerifierInstance;
