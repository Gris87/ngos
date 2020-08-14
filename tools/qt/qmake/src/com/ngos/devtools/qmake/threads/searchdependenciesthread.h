#ifndef COM_NGOS_DEVTOOLS_QMAKE_THREADS_SEARCHDEPENDENCIESTHREAD_H
#define COM_NGOS_DEVTOOLS_QMAKE_THREADS_SEARCHDEPENDENCIESTHREAD_H



#include <QThread>

#include <QHash>
#include <QMutex>
#include <QSemaphore>
#include <QSet>



class SearchDependenciesThread: public QThread
{
public:
    SearchDependenciesThread(const QString &workingDirectory); // TEST: NO

    static void init(const QStringList &includes, const QStringList &sources, qint64 numberOfThreads); // TEST: NO
    static QString takeSource(); // TEST: NO
    static void addDependencies(const QString &source, const QSet<QString> &dependencies); // TEST: NO
    static QHash<QString, QSet<QString>> buildDependenciesMap(); // TEST: NO
    static QSet<QString> buildDependenciesForSource(const QString &source, QHash<QString, QSet<QString>> &dependenciesMap); // TEST: NO

    void addError(const QString &error); // TEST: NO
    const QStringList& getErrors() const; // TEST: NO

    bool handleSource(const QString &source); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    static QStringList                   sIncludes;
    static QSet<QString>                 sSources;
    static qint64                        sNumberOfThreads;
    static qint64                        sNumberOfBlockedThreads;
    static QHash<QString, QSet<QString>> sDependencies;
    static QMutex                        sSourcesMutex;
    static QSemaphore                    sSourcesSemaphore;

    QString     mWorkingDirectory;
    QStringList mErrors;
};



#endif // COM_NGOS_DEVTOOLS_QMAKE_THREADS_SEARCHDEPENDENCIESTHREAD_H
