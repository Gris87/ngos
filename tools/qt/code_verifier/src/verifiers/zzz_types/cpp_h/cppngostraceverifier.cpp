#include "cppngostraceverifier.h"

#include <QMap>

#include "src/other/codeverificationfiletype.h"



CppNgosTraceVerifier::CppNgosTraceVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mDefinitionRegExp("^(struct|class|enum( class)?) (\\w+)(: \\w+)?$")
{
    // Nothing
}

void CppNgosTraceVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    QString traceCommand;

    if (path.contains("/src/os/configure/"))
    {
        if (path.contains("uefi/"))
        {
            traceCommand = "UEFI_LT";
        }
        else
        if (path.contains("early/"))
        {
            traceCommand = "EARLY_LT";
        }
        else
        {
            traceCommand = "COMMON_LT";
        }
    }
    else
    if (path.contains("/src/os/kernel/"))
    {
        if (path.contains("early/"))
        {
            traceCommand = "EARLY_LT";
        }
        else
        {
            traceCommand = "COMMON_LT";
        }
    }
    else
    if (path.contains("/src/os/installer/"))
    {
        if (path.contains("early/"))
        {
            traceCommand = "EARLY_LT";
        }
        else
        {
            traceCommand = "COMMON_LT";
        }
    }
    else
    if (path.contains("/src/os/kernelbase/"))
    {
        if (path.contains("early/"))
        {
            traceCommand = "EARLY_LT";
        }
        else
        {
            traceCommand = "COMMON_LT";
        }
    }
    else
    if (path.contains("/src/os/common/"))
    {
        traceCommand = "COMMON_LT";
    }
    else
    {
        return;
    }



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppNgosTraceVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        if (line == '{')
        {
            qint64 n = i - 1;

            while (n >= 0 && lines.at(n).startsWith(' '))
            {
                --n;
            }

            if (n >= 0)
            {
                QString funcDesc = lines.at(n);

                if (
                    !funcDesc.startsWith("TEST_CASES(")
                    &&
                    !funcDesc.startsWith("enum")
                    &&
                    !funcDesc.endsWith('=')
                    &&
                    !mDefinitionRegExp.match(funcDesc).hasMatch()
                   )
                {
                    qint64 index = funcDesc.indexOf('(');

                    if (index >= 0)
                    {
                        qint64 index2 = funcDesc.indexOf(')', index + 1);

                        if (index2 >= 0)
                        {
                            funcDesc = funcDesc.mid(index + 1, index2 - index - 1);



                            QStringList arguments;

                            if (funcDesc != "")
                            {
                                arguments = funcDesc.split(',');
                            }



                            for (qint64 j = 0; j < arguments.length(); ++j)
                            {
                                QString argument = arguments.at(j).trimmed();



                                if (argument == "...")
                                {
                                    arguments.removeAt(j);
                                    --j;

                                    continue;
                                }



                                if (argument.startsWith("const "))
                                {
                                    argument = argument.remove(0, 6);
                                }



                                index = argument.indexOf(' ');

                                if (index >= 0)
                                {
                                    argument = argument.remove(0, index + 1);
                                }
                                else
                                {
                                    worker->addError(path, n, "Name of argument is missing");
                                }



                                while (
                                       argument.startsWith(' ')
                                       ||
                                       argument.startsWith('*')
                                       ||
                                       argument.startsWith('&')
                                       ||
                                       argument.startsWith("/*")
                                      )
                                {
                                    argument = argument.remove(0, 1);
                                }



                                if (argument.endsWith("*/"))
                                {
                                    argument.remove(argument.length() - 2, 2);
                                }



                                arguments[j] = argument;
                            }



                            QString traceLine;
                            bool    found = false;



                            n = i + 1;

                            while (n < lines.length())
                            {
                                traceLine = lines.at(n).trimmed();

                                if (traceLine.contains(traceCommand + "((\""))
                                {
                                    found = true;

                                    if (traceLine.startsWith("//") && !traceLine.contains(")); // Commented to"))
                                    {
                                        worker->addError(path, n, "Trace command commented without description");
                                    }

                                    break;
                                }

                                if (!traceLine.startsWith("//"))
                                {
                                    break;
                                }

                                ++n;
                            }



                            if (found)
                            {
                                if (traceLine.startsWith("//"))
                                {
                                    traceLine = traceLine.mid(2, traceLine.lastIndexOf("// Commented to") - 2).trimmed();
                                }



                                if (arguments.length()) // arguments.length() > 0
                                {
                                    QString parsedTrace = traceLine.mid(traceCommand.length() + 3);



                                    if (parsedTrace.startsWith(" | "))
                                    {
                                        parsedTrace = parsedTrace.remove(0, 3);
                                    }



                                    index = parsedTrace.indexOf('\"');

                                    if (index >= 0)
                                    {
                                        parsedTrace = parsedTrace.left(index);



                                        QStringList            parsedArguments = parsedTrace.split(',');
                                        QMap<QString, QString> parsedArgumentTypes;

                                        for (qint64 j = 0; j < parsedArguments.length(); ++j)
                                        {
                                            QString parsedArgument = parsedArguments.at(j);



                                            index = parsedArgument.indexOf('=');

                                            QString name = parsedArgument.left(index).trimmed();
                                            QString type = parsedArgument.mid(index + 1).trimmed();



                                            parsedArgumentTypes.insert(name, type);
                                        }



                                        QString trace = traceCommand + "((\" | ";

                                        for (qint64 j = 0; j < arguments.length(); ++j)
                                        {
                                            QString argument = arguments.at(j);

                                            if (j > 0)
                                            {
                                                trace += ", ";
                                            }

                                            trace += argument;
                                            trace += " = ";
                                            trace += parsedArgumentTypes.value(argument, "%d");
                                        }

                                        trace += '\"';

                                        for (qint64 j = 0; j < arguments.length(); ++j)
                                        {
                                            QString argument = arguments.at(j);

                                            if (parsedArgumentTypes.value(argument, "%d") != "...")
                                            {
                                                trace += ", ";
                                                trace += argument;
                                            }
                                        }

                                        trace += "));";



                                        if (traceLine != trace)
                                        {
                                            worker->addError(path, n, QString("Trace command is invalid. Expected: \"%1\"").arg(trace));
                                        }
                                    }
                                    else
                                    {
                                        worker->addError(path, n, "Unexpected behavior while NGOS Trace verification");
                                    }
                                }
                                else
                                {
                                    if (traceLine != traceCommand + "((\"\"));")
                                    {
                                        worker->addError(path, n, QString("Trace command should be \"%1((\"\"));\"").arg(traceCommand));
                                    }
                                }
                            }
                            else
                            {
                                QString trace;

                                if (arguments.length()) // arguments.length() > 0
                                {
                                    trace = traceCommand + "((\" | ";

                                    for (qint64 j = 0; j < arguments.length(); ++j)
                                    {
                                        QString argument = arguments.at(j);

                                        if (j > 0)
                                        {
                                            trace += ", ";
                                        }

                                        trace += argument;
                                        trace += " = %d";
                                    }

                                    trace += '\"';

                                    for (qint64 j = 0; j < arguments.length(); ++j)
                                    {
                                        QString argument = arguments.at(j);

                                        trace += ", ";
                                        trace += argument;
                                    }

                                    trace += "));";
                                }
                                else
                                {
                                    trace = traceCommand + "((\"\"));";
                                }



                                worker->addError(path, i + 1, QString("Trace command not found at the beginning of the function: \"%1\"").arg(trace));
                            }
                        }
                        else
                        {
                            worker->addError(path, n, "Expected closing bracket )");
                        }
                    }
                    else
                    {
                        worker->addError(path, n, "Expected opening bracket (");
                    }
                }
            }
            else
            {
                worker->addError(path, i, "Unexpected behavior while NGOS Trace verification");
            }
        }
    }
}



CppNgosTraceVerifier cppNgosTraceVerifierInstance;
