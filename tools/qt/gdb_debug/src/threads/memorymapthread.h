#ifndef GDB_DEBUG_SRC_THREADS_MEMORYMAPTHREAD_H
#define GDB_DEBUG_SRC_THREADS_MEMORYMAPTHREAD_H



#include <QThread>

#include "src/other/memorymapinfo.h"
#include "src/widgets/hexgraphicsview.h"



class MemoryMapThread: public QThread
{
public:
    MemoryMapThread(HexGraphicsView *hexGraphicsView, qint64 start, qint64 end); // TEST: NO

    void stop(); // TEST: NO

    const QList<MemoryMapInfo>& getResult() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool                  mIsRunning;
    HexGraphicsView      *mHexGraphicsView;
    qint64                mStart;
    qint64                mEnd;
    QList<MemoryMapInfo>  mResult;
};



#endif // GDB_DEBUG_SRC_THREADS_MEMORYMAPTHREAD_H
