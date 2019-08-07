#include "qmake.h"

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QIODevice>
#include <console/console.h>
#include <buildconfig.h>

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
    lines.append("CAT   = cat");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Project specific definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("TARGET              = " + mEntries.value("TARGET").join(' '));
    lines.append("");



    QString tail;



    QString vectorizationFlags = mEntries.value("VECTORIZATION_FLAGS").join(' ');

    if (vectorizationFlags != "")
    {
        lines.append("VECTORIZATION_FLAGS = " + vectorizationFlags);
    }
    else
    {
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_NONE
        lines.append("VECTORIZATION_FLAGS = -mno-mmx -mno-sse");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE
        lines.append("VECTORIZATION_FLAGS = -msse");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE2
        lines.append("VECTORIZATION_FLAGS = -msse2");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE3
        lines.append("VECTORIZATION_FLAGS = -msse3 -mssse3");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE4
        lines.append("VECTORIZATION_FLAGS = -msse4 -msse4.1 -msse4.2");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX
        lines.append("VECTORIZATION_FLAGS = -mavx");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX2
        lines.append("VECTORIZATION_FLAGS = -mavx2");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V1
        lines.append("VECTORIZATION_FLAGS = -mavx512f -mavx512cd -mavx512er -mavx512pf");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V2
        lines.append("VECTORIZATION_FLAGS = -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl");
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3
        lines.append("VECTORIZATION_FLAGS = -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl -mavx512ifma -mavx512vbmi");
#else
#error Unexpected value for NGOS_BUILD_X86_64_VECTORIZATION_MODE parameter
#endif
    }

    tail += " $(VECTORIZATION_FLAGS)";



    QString fmaFlags = mEntries.value("FMA_FLAGS").join(' ');

    if (fmaFlags != "")
    {
        lines.append("FMA_FLAGS           = " + fmaFlags);
    }
    else
    {
#if NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE
        lines.append("FMA_FLAGS           = -mno-fma");
#elif NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA4
        lines.append("FMA_FLAGS           = -mfma4");
#elif NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3
        lines.append("FMA_FLAGS           = -mfma");
#else
#error Unexpected value for NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD parameter
#endif
    }

    tail += " $(FMA_FLAGS)";



#if NGOS_BUILD_RELEASE == OPTION_NO
    lines.append("DEBUG_FLAGS         = -g");

    tail += " $(DEBUG_FLAGS)";
#endif



    const QStringList &defines = mEntries.value("DEFINES");

    if (defines.length() > 0)
    {
        lines.append("");
        lines.append("DEFINES             = \\");

        for (qint64 i = 0; i < defines.length(); ++i)
        {
            lines.append("\t-D" + defines.at(i) + (i < defines.length() - 1 ? " \\" : ""));
        }

        tail += " $(DEFINES)";
    }



    const QStringList &includes = mEntries.value("INCLUDEPATH");

    if (includes.length() > 0)
    {
        lines.append("");
        lines.append("INCLUDES            = \\");
        lines.append("\t-I . \\                             # " + workingDirectory);

        for (qint64 i = 0; i < includes.length(); ++i)
        {
            QString include = includes.at(i);

            if (i < includes.length() - 1)
            {
                include += " \\";
            }

            lines.append(QString("\t-I %1 %2 # %3").arg(include).arg("", 30 - include.length(), QChar(' ')).arg(QFileInfo(workingDirectory + '/' + includes.at(i)).absoluteFilePath()));
        }
    }
    else
    {
        lines.append("");
        lines.append("INCLUDES            = -I .    # " + workingDirectory);
    }

    tail += " $(INCLUDES)";



    lines.append("");
    lines.append("CFLAGS              = " + mEntries.value("QMAKE_CFLAGS").join(' ')   + tail);
    lines.append("CXXFLAGS            = " + mEntries.value("QMAKE_CXXFLAGS").join(' ') + tail);
    lines.append("LFLAGS              = " + mEntries.value("QMAKE_LFLAGS").join(' '));
    lines.append("");
    lines.append("OUTPUT_DIR          = build");
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
    lines.append("OBJECTS             = \\");



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
    qint64 workersCount = QThread::idealThreadCount();

    SearchDependenciesThread::init(mEntries.value("INCLUDEPATH"), mEntries.value("SOURCES"), workersCount);



    QList<SearchDependenciesThread *> threads;

    for (qint64 i = 0; i < workersCount; ++i)
    {
        SearchDependenciesThread *thread = new SearchDependenciesThread(workingDirectory);
        thread->start();
        threads.append(thread);
    }



    QString     additionalLdDependencies = "";
    QStringList lFlags                   = mEntries.value("QMAKE_LFLAGS");

    for (qint64 i = 0; i < lFlags.length(); ++i)
    {
        const QString &flag = lFlags.at(i);

        if (flag == "-T")
        {
            if (i < lFlags.length() - 1)
            {
                ++i;

                additionalLdDependencies += ' ' + lFlags.at(i);
            }
        }
    }



    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Target definitions:");
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
    lines.append("$(OUTPUT_DIR)/$(TARGET): $(OBJECTS)" + additionalLdDependencies);
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
