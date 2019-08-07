#ifndef QMAKE_SRC_THREADS_SEARCHDEPENDENCIESTHREAD_H
#define QMAKE_SRC_THREADS_SEARCHDEPENDENCIESTHREAD_H



#include <QThread>

#include <QMap>
#include <QMutex>
#include <QSemaphore>



class SearchDependenciesThread: public QThread
{
public:
    SearchDependenciesThread(const QString &workingDirectory); // TEST: NO

    static void init(const QStringList &includes, const QStringList &sources, qint64 numberOfThreads); // TEST: NO
    static QString takeSource(); // TEST: NO
    static void addDependencies(const QString &source, const QStringList &dependencies); // TEST: NO
    static QMap<QString, QStringList> buildDependenciesMap(); // TEST: NO
    static QStringList buildDependenciesForSource(const QString &source, QMap<QString, QStringList> &dependenciesMap); // TEST: NO

    void addError(const QString &error); // TEST: NO
    const QStringList& getErrors() const; // TEST: NO

    bool handleSource(const QString &source); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    static QStringList                sIncludes;
    static QStringList                sSources;
    static qint64                     sNumberOfThreads;
    static qint64                     sNumberOfBlockedThreads;
    static QMap<QString, QStringList> sDependencies;
    static QMutex                     sSourcesMutex;
    static QSemaphore                 sSourcesSemaphore;

    QString     mWorkingDirectory;
    QStringList mErrors;
};



#endif // QMAKE_SRC_THREADS_SEARCHDEPENDENCIESTHREAD_H
