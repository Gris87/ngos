#include "cppenumverifier.h"

#include "src/other/codeverificationfiletype.h"



CppEnumVerifier::CppEnumVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mDefinitionRegExp("^ *enum( +class)?(?: +(\\w+))? *(?:: *(\\w+))?$")
    , mValueRegExp("^ *([A-Z_][A-Z\\d_]*)(?: *= *([^,]+))?,?(?: *\\/\\/.*)?$")
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
                    QStringList valuesNumeric;
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
                                QString value        = match.captured(1);
                                QString valueNumeric = match.captured(2);

                                values.append(value);
                                valuesNumeric.append(valueNumeric);

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
                    QString toStringFunction = "\n\n\n";

                    toStringFunction += "inline const char* " + enumNameFromLowerCase + "ToString(" + enumName + ' ' + variableName + ") // TEST: NO\n";
                    toStringFunction += "{\n";



                    QString traceCommand = traceCommandFromPath(path);

                    if (traceCommand != "")
                    {
                        toStringFunction += "    // " + traceCommand + "((\" | " + variableName + " = %u\", " + variableName + ")); // Commented to avoid bad looking logs\n";
                        toStringFunction += "\n\n\n";
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
                    toStringFunction += "}\n";
                    toStringFunction += "\n\n\n";

                    if (!content.contains(toStringFunction))
                    {
                        worker->addError(path, i, QString("Enum to string conversion function not found. Expecting for:\n%1").arg(toStringFunction));
                    }
                    // Ignore CppAlignmentVerifier [END]



                    if (enumName.endsWith("Flag"))
                    {
                        QString expectedEnumType = "";

                        for (qint64 j = 0; j < enumNameFromLowerCase.length(); ++j)
                        {
                            QChar ch = enumNameFromLowerCase.at(j);

                            if (ch.isUpper())
                            {
                                expectedEnumType += '_';
                                expectedEnumType += ch.toLower();
                            }
                            else
                            {
                                expectedEnumType += ch;
                            }
                        }

                        expectedEnumType += 's';



                        if (enumType != expectedEnumType)
                        {
                            worker->addError(path, i, QString("Enum should use type %1 for flags").arg(expectedEnumType));
                        }



                        if (values.contains("MAXIMUM"))
                        {
                            worker->addError(path, i, "Enum value MAXIMUM not allowed for flags");
                        }
                        else
                        {
                            if (values.contains("NONE"))
                            {
                                if (values.first() != "NONE")
                                {
                                    worker->addError(path, i, "Enum value NONE should be first");
                                }

                                if (valuesNumeric.first() != '0')
                                {
                                    worker->addError(path, i, "Numeric value of NONE should be zero");
                                }
                            }
                            else
                            {
                                worker->addError(path, i, "Enum value NONE should be first");
                            }

                            if (valuesNumeric.contains(""))
                            {
                                worker->addError(path, i, "Numeric values should be provided for enum");
                            }
                        }



                        quint64 totalStringSize = 13; // Length of "UNKNOWN x 99" + zero byte

                        for (qint64 j = 0; j < values.length(); ++j)
                        {
                            const QString &value = values.at(j);

                            if (value != "NONE")
                            {
                                totalStringSize += values.at(j).length() + 3; // 3 == length of " | "
                            }
                        }



                        // Ignore CppAlignmentVerifier [BEGIN]
                        toStringFunction =  "\n\n\n";
                        toStringFunction += "inline const char* " + enumNameFromLowerCase + "sToString(" + enumType + " flags) // TEST: NO\n";
                        toStringFunction += "{\n";



                        if (traceCommand != "")
                        {
                            toStringFunction += "    // " + traceCommand + "((\" | flags = %u\", flags)); // Commented to avoid bad looking logs\n";
                            toStringFunction += "\n\n\n";
                        }



                        toStringFunction += "    if (!flags)\n";
                        toStringFunction += "    {\n";
                        toStringFunction += "        return \"NONE\";\n";
                        toStringFunction += "    }\n";
                        toStringFunction += "\n\n\n";
                        toStringFunction += "    static char res[" + QString::number(totalStringSize) + "];\n";
                        toStringFunction += '\n';
                        toStringFunction += "    FLAGS_TO_STRING(res, flags, " + enumNameFromLowerCase + "ToString, " + enumName + ");\n";
                        toStringFunction += '\n';
                        toStringFunction += "    return res;\n";
                        toStringFunction += "}\n";
                        toStringFunction += "\n\n\n";

                        if (!content.contains(toStringFunction))
                        {
                            worker->addError(path, i, QString("Enum to string conversion function not found. Expecting for:\n%1").arg(toStringFunction));
                        }
                        // Ignore CppAlignmentVerifier [END]
                    }
                    else
                    {
                        if (
                            enumType != "u8"
                            &&
                            enumType != "u16"
                            &&
                            enumType != "u32"
                            &&
                            enumType != "u64"
                            &&
                            enumType != "quint8"
                            &&
                            enumType != "quint16"
                            &&
                            enumType != "quint32"
                            &&
                            enumType != "quint64"
                           )
                        {
                            worker->addError(path, i, "Enum type expecting to be one of the standard types");
                        }



                        if (values.contains("MAXIMUM"))
                        {
                            if (values.last() != "MAXIMUM")
                            {
                                worker->addError(path, i, "Enum value MAXIMUM should be last");
                            }

                            if (values.contains("NONE"))
                            {
                                worker->addError(path, i, "Enum value NONE not allowed when value MAXIMUM present");
                            }

                            if (valuesNumeric.count("") != valuesNumeric.length())
                            {
                                worker->addError(path, i, "Numeric values of the enum are not allowed when value MAXIMUM present");
                            }
                        }
                        else
                        {
                            if (values.contains("NONE"))
                            {
                                if (values.first() != "NONE")
                                {
                                    worker->addError(path, i, "Enum value NONE should be first");
                                }

                                if (valuesNumeric.first() != '0')
                                {
                                    worker->addError(path, i, "Numeric value of NONE should be zero");
                                }
                            }
                            else
                            {
                                if (valuesNumeric.first() != '0')
                                {
                                    worker->addError(path, i, "Enum value NONE should be first");
                                }
                            }

                            if (valuesNumeric.contains(""))
                            {
                                worker->addError(path, i, "Numeric values should be provided for enum");
                            }
                        }
                    }
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
