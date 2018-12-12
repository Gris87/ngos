#include "memorymapthread.h"



MemoryMapThread::MemoryMapThread(HexGraphicsView *hexGraphicsView, qint64 start, qint64 end)
    : QThread()
    , mIsRunning(true)
    , mHexGraphicsView(hexGraphicsView)
    , mStart(start)
    , mEnd(end)
    , mResult()
{
    // Nothing
}

void MemoryMapThread::stop()
{
    mIsRunning = false;
}

const QList<MemoryMapInfo>& MemoryMapThread::getResult() const
{
    return mResult;
}

void MemoryMapThread::run()
{
    qint64                              lastSection = 0;
    QList<ElfSectionHeaderTableEntry *> sections    = mHexGraphicsView->getGdbProcess()->getElfObject().getSections();



    QBrush *lastBrush  = 0;
    qint64  brushCount = 0;

    for (qint64 i = mStart; i < mEnd; ++i)
    {
        QBrush *brush = mHexGraphicsView->getBrushForByte(i, &lastSection, &sections);

        if (brush != lastBrush)
        {
            if (brushCount > 0)
            {
                mResult.append(MemoryMapInfo(lastBrush, brushCount));
            }



            brushCount = 0;

            lastBrush = brush;
        }

        ++brushCount;
    }

    if (brushCount > 0)
    {
        mResult.append(MemoryMapInfo(lastBrush, brushCount));
    }
}
