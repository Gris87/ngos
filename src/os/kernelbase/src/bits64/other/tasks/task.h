#ifndef OS_COMMON_SRC_BITS64_TASKS_TASK_H
#define OS_COMMON_SRC_BITS64_TASKS_TASK_H



#include <ngos/types.h>
#include <src/bits64/other/kerneldefines.h>
#include <src/bits64/other/tasks/taskstate.h>
#include <src/bits64/other/tasks/threadinfo.h>



struct Task
{
    ThreadInfo  threadInfo;
    TaskState   state;
    u8         *stack;
    u64         stackCanary;
};



extern Task initTask;               // initTask declared in task.cpp file
extern u8   initStack[THREAD_SIZE]; // initStack declared in task.cpp file



#endif // OS_COMMON_SRC_BITS64_TASKS_TASK_H
