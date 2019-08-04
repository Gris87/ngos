#include "qmake.h"

#include <QCoreApplication>
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
    , mMakefileDependencies()
{
    // Nothing
}

qint64 QMake::process()
{
    QFileInfo fileInfo         = QFileInfo(mPathToProFile);
    QString   workingDirectory = fileInfo.absolutePath();



    qint64 res = processInWorkingDirectory(workingDirectory, fileInfo.fileName());

    if (res)
    {
        return res;
    }



    return generateMakefile(workingDirectory);
}

qint64 QMake::processInWorkingDirectory(const QString &workingDirectory, const QString &proFilename)
{
    QString pathToProFile = workingDirectory + '/' + proFilename;

    mMakefileDependencies.append(pathToProFile);



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
    if (!mEntries.contains("SUBDIRS"))
    {
        Console::err("SUBDIRS not specified in pro file");

        return 1;
    }



    QStringList lines;

    lines.append("####################################");
    lines.append("# Makefile definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("QMAKE = " + qApp->applicationFilePath());
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Project specific definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("SUBDIRS = " + mEntries.value("SUBDIRS").join(' '));
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Targets:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("all: Makefile $(SUBDIRS)");
    lines.append("");
    lines.append("clean: Makefile $(SUBDIRS)");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("$(SUBDIRS):");
    lines.append("\tsh -c \"cd $@ && lupdate -noobsolete $@.pro && lrelease $@.pro && $(QMAKE) $@.pro && make -j`nproc` $(MAKECMDGOALS)\"");



    return save(workingDirectory, lines, "$(SUBDIRS)");
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

qint64 QMake::save(const QString &workingDirectory, const QStringList &lines, const QString &phony)
{
    QFile file(workingDirectory + "/Makefile");

    if (!file.open(QIODevice::WriteOnly))
    {
        Console::err("Failed to create Makefile");

        return 1;
    }



    file.write("####################################\n");
    file.write("# Makefile generated by qmake (NGOS)\n");
    file.write("####################################\n");
    file.write("\n\n\n");
    file.write(lines.join('\n').toUtf8());
    file.write("\n");

    if (phony != "")
    {
        file.write("\n\n\n");
        file.write(QString(".PHONY: %1\n").arg(phony).toUtf8());
    }

    file.write("\n\n\n");
    file.write("####################################\n");
    file.write("# Makefile target:\n");
    file.write("####################################\n");
    file.write("\n\n\n");
    file.write(QString("Makefile: $(QMAKE) %1\n").arg(mMakefileDependencies.join(' ')).toUtf8());
    file.write(QString("\t$(QMAKE) %1\n").arg(mMakefileDependencies.at(0)).toUtf8());



    file.close();

    return 0;
}
