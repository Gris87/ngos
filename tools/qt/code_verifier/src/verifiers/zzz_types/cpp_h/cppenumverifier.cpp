#include "cppenumverifier.h"

#include "src/other/codeverificationfiletype.h"



CppEnumVerifier::CppEnumVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mDefinitionRegExp("^ *enum( +class)?(?: +(\\w+))? *(: *\\w+)?$")
    , mValueRegExp("^ *([A-Z_][A-Z\\d_]*)(?: *=.*)?,?(?: *\\/\\/.*)?$")
{
    // Nothing
}

void CppEnumVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppEnumVerifier");
        removeComments(line);



        QRegularExpressionMatch match = mDefinitionRegExp.match(line);

        if (match.hasMatch())
        {
            QString enumClass = match.captured(1);
            QString enumName  = match.captured(2);
            QString enumType  = match.captured(3);



            if (enumClass == "")
            {
                worker->addError(path, i, "Expected enum class definition");
            }



            if (enumName != "")
            {
                if (enumType != "")
                {
                    QStringList values;
                    qint64      maxValueLength = 0;



                    i += 2;

                    while (i < lines.length() && lines.at(i) != "};")
                    {
                        QString anotherLine = lines.at(i);

                        if (
                            anotherLine != ""
                            &&
                            !anotherLine.trimmed().startsWith("//")
                           )
                        {
                            match = mValueRegExp.match(anotherLine);

                            if (match.hasMatch())
                            {
                                QString value = match.captured(1);

                                values.append(value);

                                if (value.length() > maxValueLength)
                                {
                                    maxValueLength = value.length();
                                }
                            }
                            else
                            {
                                worker->addError(path, i, "Invalid enum value");
                            }
                        }



                        ++i;
                    }



                    QString enumNameFromLowerCase = enumName.at(0).toLower() + enumName.mid(1);
                    QString variableName          = enumNameFromLowerCase;

                    for (qint64 j = enumName.length() - 2; j >= 0; --j)
                    {
                        if (
                            enumName.at(j).isUpper()
                            &&
                            enumName.mid(j) != "Class"
                           )
                        {
                            variableName = enumName.at(j).toLower() + enumName.mid(j + 1);

                            break;
                        }
                    }



                    // Ignore CppAlignmentVerifier [BEGIN]
                    QString toStringFunction = "inline const char* " + enumNameFromLowerCase + "ToString(" + enumName + ' ' + variableName + ") // TEST: NO\n";

                    toStringFunction += "{\n";



                    QString traceCommand = traceCommandFromPath(path);

                    if (traceCommand != "")
                    {
                        toStringFunction += "    // " + traceCommand + "((\" | " + variableName + " = %u\", " + variableName + ")); // Commented to avoid bad looking logs\n";
                        toStringFunction += '\n';
                        toStringFunction += '\n';
                        toStringFunction += '\n';
                    }



                    toStringFunction += "    switch (" + variableName + ")\n";
                    toStringFunction += "    {\n";

                    for (qint64 j = 0; j < values.length(); ++j)
                    {
                        const QString &value   = values.at(j);
                        QString        spaces  = QString("%1").arg("", maxValueLength - value.length(), QChar(' '));
                        QString        comment = value.length() > 1 ? "" : " // Ignore CppSingleCharVerifier";

                        toStringFunction += "        case " + enumName + "::" + value + ": " + spaces + "return \"" + value + "\";" + comment + '\n';
                    }

                    toStringFunction += '\n';
                    toStringFunction += "        default: return \"UNKNOWN\";\n";
                    toStringFunction += "    }\n";
                    toStringFunction += '}';

                    if (!content.contains(toStringFunction))
                    {
                        worker->addError(path, i, QString("Enum to string conversion function not found. Expecting for:\n%1").arg(toStringFunction));
                    }
                    // Ignore CppAlignmentVerifier [END]
                }
                else
                {
                    worker->addError(path, i, "Expected enum type");
                }
            }
            else
            {
                worker->addError(path, i, "Expected enum name");
            }
        }
    }
}



CppEnumVerifier cppEnumVerifierInstance;
