#include "burnthread.h"



BurnThread::BurnThread()
    : QThread()
    , mIsRunning(true)
{
    // Nothing
}

void BurnThread::stop()
{
    mIsRunning = false;
}
