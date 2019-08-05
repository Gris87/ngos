#include "qmake.h"

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QIODevice>
#include <console/console.h>

#include "src/threads/searchdependenciesthread.h"



QMake::QMake(const QString &pathToProFile)
    : mPathToProFile(pathToProFile)
    , mCommentRegexp("^((?:[^\\\"#]+(?:\\\"[^\\\"]*\\\")?)*)#.*$")
    , mEntryRegexp("^ *(\\w+) *([+-]?=) *(.*)$")
    , mEntryValueRegexp("(\\\"[^\\\"]*\\\"|[^ ]+)")
    , mIncludeRegexp("^ *include\\((.*)\\).*$")
    , mEntries()
    , mSourceToObjectMap()
    , mMakefileDependencies()
{
    // Nothing
}

qint64 QMake::process()
{
    QFileInfo fileInfo         = QFileInfo(mPathToProFile);
    QString   workingDirectory = fileInfo.absolutePath();



    qint64 res = processInWorkingDirectory(workingDirectory, fileInfo.fileName());

    if (res) // res != 0
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



        match = mIncludeRegexp.match(line);

        if (match.hasMatch())
        {
            QString includePath = match.captured(1);
            includePath.remove("$$PWD/");

            QFileInfo fileInfo            = QFileInfo(workingDirectory + '/' + includePath);
            QString   workingSubDirectory = fileInfo.absolutePath();



            qint64 res = processInWorkingDirectory(workingSubDirectory, fileInfo.fileName());

            if (res) // res != 0
            {
                return res;
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
    if (!mEntries.contains("SOURCES"))
    {
        Console::err("SOURCES not specified in pro file");

        return 1;
    }

    if (!mEntries.contains("TARGET"))
    {
        Console::err("TARGET not specified in pro file");

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
    lines.append("CC    = x86_64-elf-gcc");
    lines.append("CXX   = x86_64-elf-g++");
    lines.append("LD    = x86_64-elf-ld");
    lines.append("");
    lines.append("MKDIR = mkdir -p");
    lines.append("RMDIR = rm -rf");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Project specific definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("TARGET     = " + mEntries.value("TARGET").join(' '));
    lines.append("");
    lines.append("INCLUDES   = \\");



    QStringList includes = mEntries.value("INCLUDEPATH");

    if (includes.length() > 0)
    {
        lines.append("\t-I . \\");

        for (qint64 i = 0; i < includes.length(); ++i)
        {
            lines.append("\t-I " + includes.at(i) + (i < includes.length() - 1 ? " \\" : ""));
        }
    }
    else
    {
        lines.append("\t-I .");
    }



    lines.append("");
    lines.append("CFLAGS     = " + mEntries.value("QMAKE_CFLAGS").join(' ')   + " $(INCLUDES)");
    lines.append("CXXFLAGS   = " + mEntries.value("QMAKE_CXXFLAGS").join(' ') + " $(INCLUDES)");
    lines.append("LFLAGS     = " + mEntries.value("QMAKE_LFLAGS").join(' '));
    lines.append("");
    lines.append("OUTPUT_DIR = build");
    lines.append("");



    qint64 res = addApplicationObjectsDefinitions(workingDirectory, lines);

    if (res) // res != 0
    {
        return res;
    }



    res = addApplicationBuildTargets(workingDirectory, lines);

    if (res) // res != 0
    {
        return res;
    }



    return save(workingDirectory, lines);
}

qint64 QMake::generateLibraryMakefile(const QString &workingDirectory)
{
    Console::err(workingDirectory);

    return 0;
}

qint64 QMake::addApplicationObjectsDefinitions(const QString & /*workingDirectory*/, QStringList &lines)
{
    lines.append("OBJECTS    = \\");



    const QStringList &sources = mEntries.value("SOURCES");

    for (qint64 i = 0; i < sources.length(); ++i)
    {
        QString originalSource = sources.at(i);
        QString source         = originalSource;



        if (source.endsWith(".cpp"))
        {
            source.remove(source.length() - 4, 4);
        }
        else
        if (source.endsWith(".S"))
        {
            source.remove(source.length() - 2, 2);
        }
        else
        {
            Console::err(QString("Unexpected source: %1").arg(source));

            return 1;
        }

        if (source.startsWith('/'))
        {
            source.remove(0, 1);
        }



        QString object = "$(OUTPUT_DIR)/" + source + ".o";

        mSourceToObjectMap.insert(originalSource, object);
        lines.append("\t" + object + (i < sources.length() - 1 ? " \\" : ""));
    }



    return 0;
}

qint64 QMake::addApplicationBuildTargets(const QString &workingDirectory, QStringList &lines)
{
    SearchDependenciesThread::initSources(mEntries.value("INCLUDEPATH"), mEntries.value("SOURCES"));



    QList<SearchDependenciesThread *> threads;

    for (qint64 i = 0; i < QThread::idealThreadCount(); ++i)
    {
        SearchDependenciesThread *thread = new SearchDependenciesThread(workingDirectory);
        thread->start();
        threads.append(thread);
    }



    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Targets definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("all: Makefile $(OUTPUT_DIR)/$(TARGET)");
    lines.append("");
    lines.append("clean: Makefile");
    lines.append("\t$(RMDIR) $(OUTPUT_DIR)");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("$(OUTPUT_DIR)/$(TARGET): $(OBJECTS)");
    lines.append("\t$(LD) $(LFLAGS) $(OBJECTS) -o $@");



    bool hasErrors = false;

    for (qint64 i = 0; i < threads.length(); ++i)
    {
        SearchDependenciesThread *thread = threads.at(i);
        thread->wait();



        QStringList errors = thread->getErrors();

        if (errors.length() > 0)
        {
            hasErrors = true;

            for (qint64 j = 0; j < errors.length(); ++j)
            {
                Console::err(errors.at(j));
            }
        }



        delete thread;
    }



    if (hasErrors)
    {
        return 1;
    }



    QMap<QString, QStringList> dependenciesMap = SearchDependenciesThread::buildDependenciesMap();

    for (QMap<QString, QString>::Iterator it = mSourceToObjectMap.begin(); it != mSourceToObjectMap.end(); ++it)
    {
        QString source = it.key();
        QString object = it.value();



        if (!dependenciesMap.contains(source))
        {
            Console::err(QString("Dependencies not found for source: %1").arg(source));

            return 1;
        }

        QStringList dependencies = dependenciesMap.value(source);



        lines.append("");
        lines.append("");
        lines.append("");
        lines.append(QString("%1: %2 %3").arg(object).arg(source).arg(dependencies.join(' ')));

        if (source.endsWith(".cpp"))
        {
            lines.append("\t$(MKDIR) $(@D)");
            lines.append("\t$(CXX) -c $(CXXFLAGS) -E $< -o $@.cpp");
            lines.append("\t$(CXX) -c $(CXXFLAGS) -S $< -o $@.S");
            lines.append("\t$(CXX) -c $(CXXFLAGS) $< -o $@");
        }
        else
        if (source.endsWith(".S"))
        {
            lines.append("\t$(MKDIR) $(@D)");
            lines.append("\t$(CC) -c $(CFLAGS) $< -o $@");
        }
        else
        {
            Console::err(QString("Unexpected source: %1").arg(source));

            return 1;
        }
    }



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
