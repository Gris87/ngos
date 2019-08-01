#include "qmake.h"

#include <QFile>
#include <QFileInfo>
#include <QIODevice>
#include <console/console.h>



QMake::QMake(const QString &pathToProFile)
    : mPathToProFile(pathToProFile)
    , mCommentRegexp("^((?:[^\\\"#]+(?:\\\"[^\\\"]*\\\")?)*)#.*$")
    , mEntryRegexp("^ *(\\w+) *([+-]?=) *(.*)$")
    , mEntryValueRegexp("(\\\"[^\\\"]*\\\"|[^ ]+)")
    , mEntries()
{
    // Nothing
}

qint64 QMake::process()
{
    QString workingDirectory = QFileInfo(mPathToProFile).absolutePath();



    qint64 res = processInWorkingDirectory(workingDirectory, mPathToProFile);

    if (res)
    {
        return res;
    }



    return generateMakefile(workingDirectory);
}

qint64 QMake::processInWorkingDirectory(const QString &workingDirectory, const QString &pathToProFile)
{
    QFile file(pathToProFile);

    if (!file.open(QIODevice::ReadOnly))
    {
        Console::err(QString("Failed to read file \"%1\"").arg(pathToProFile));

        return 1;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i).trimmed();

        QRegularExpressionMatch match = mCommentRegexp.match(line);

        if (match.hasMatch())
        {
            line = match.captured(1).trimmed();
        }

        lines[i] = line;
    }



    return processLines(workingDirectory, lines);
}

qint64 QMake::processLines(const QString &workingDirectory, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);



        if (line == "")
        {
            continue;
        }



        QRegularExpressionMatch match = mEntryRegexp.match(line);

        if (match.hasMatch())
        {
            QString entryName     = match.captured(1);
            QString entryOperator = match.captured(2);
            QString entryValue    = match.captured(3);



            while (entryValue.endsWith('\\'))
            {
                do
                {
                    entryValue.remove(entryValue.length() - 1, 1);
                } while(entryValue.endsWith('\\'));

                entryValue = entryValue.trimmed();

                ++i;

                if (i < lines.length())
                {
                    entryValue = entryValue + ' ' + lines.at(i);
                }
            }



            if (!parseEntry(workingDirectory, entryName, entryOperator, entryValue))
            {
                return 1;
            }



            continue;
        }



        Console::err(QString("Ignoring line: %1").arg(line));
    }



    return 0;
}

bool QMake::parseEntry(const QString &workingDirectory, const QString &entryName, const QString &entryOperator, const QString &entryValue)
{
    QStringList                     values;
    QRegularExpressionMatchIterator matches = mEntryValueRegexp.globalMatch(entryValue);

    while (matches.hasNext())
    {
        QRegularExpressionMatch match = matches.next();

        QString value = match.captured(0);
        value.replace("$$PWD", workingDirectory);

        values.append(value);
    }

    values.removeDuplicates();



    if (entryOperator == '=')
    {
        mEntries.insert(entryName, values);
    }
    else
    if (entryOperator == "+=")
    {
        QStringList &entryValues = mEntries[entryName];
        entryValues.append(values);
        entryValues.removeDuplicates();
    }
    else
    if (entryOperator == "-=")
    {
        QStringList &entryValues = mEntries[entryName];

        for (qint64 i = 0; i < values.length(); ++i)
        {
            entryValues.removeOne(values.at(i));
        }
    }
    else
    {
        Console::err(QString("Unexpected operator %1").arg(entryOperator));
    }



    return true;
}

qint64 QMake::generateMakefile(const QString &workingDirectory)
{
    if (!mEntries.contains("TEMPLATE"))
    {
        Console::err("TEMPLATE not specified in pro file");

        return 1;
    }



    QString templateValue = mEntries.value("TEMPLATE").join(' ');

    if (templateValue == "subdirs")
    {
        return generateSubdirsMakefile(workingDirectory);
    }

    if (templateValue == "app")
    {
        return generateApplicationMakefile(workingDirectory);
    }

    if (templateValue == "lib")
    {
        return generateLibraryMakefile(workingDirectory);
    }



    Console::err(QString("Unexpected TEMPLATE value: %1").arg(templateValue));

    return 1;
}

qint64 QMake::generateSubdirsMakefile(const QString &workingDirectory)
{
    Console::err(workingDirectory);

    return 0;
}

qint64 QMake::generateApplicationMakefile(const QString &workingDirectory)
{
    Console::err(workingDirectory);

    return 0;
}

qint64 QMake::generateLibraryMakefile(const QString &workingDirectory)
{
    Console::err(workingDirectory);

    return 0;
}
