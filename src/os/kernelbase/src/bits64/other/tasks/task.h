#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASK_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASK_H



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



extern Task initTask;
extern u8   initStack[THREAD_SIZE];



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_TASK_H
