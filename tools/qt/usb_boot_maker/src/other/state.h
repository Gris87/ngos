#ifndef STATE_H
#define STATE_H



#include <Qt>



enum class State: quint8
{
    INITIAL,
    GET_LATEST_VERSION,
    GET_FILE_LIST,
    DOWNLOAD,
    BURNING
};



#endif // STATE_H
