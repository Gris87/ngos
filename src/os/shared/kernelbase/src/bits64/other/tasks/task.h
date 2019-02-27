#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASK_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASK_H



#include <kernelbase/src/bits64/other/kerneldefines.h>
#include <kernelbase/src/bits64/other/tasks/taskstate.h>
#include <kernelbase/src/bits64/other/tasks/threadinfo.h>
#include <ngos/types.h>



struct Task
{
    ThreadInfo  threadInfo;
    TaskState   state;
    u8         *stack;
    u64         stackCanary;
};



extern Task initTask;               // initTask declared in task.cpp file
extern u8   initStack[THREAD_SIZE]; // initStack declared in task.cpp file



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASK_H
