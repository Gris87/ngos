#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



namespace __cxxabiv1
{



class __si_class_type_info
{
    virtual void dummy(); // TEST: NO
};



class __class_type_info
{
    virtual void dummy(); // TEST: NO
};



class __vmi_class_type_info
{
    virtual void dummy(); // TEST: NO
};



void __si_class_type_info::dummy()
{
    COMMON_LT((""));
}

void __class_type_info::dummy()
{
    COMMON_LT((""));
}

void __vmi_class_type_info::dummy()
{
    COMMON_LT((""));
}



};



u64 __cxa_pure_virtual;
