#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_OTHER_OPTIONINFO_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_OTHER_OPTIONINFO_H



#include <QString>



struct OptionInfo
{
    OptionInfo() // TEST: NO
    {
        this->id          = "";
        this->value       = "";
        this->description = "";
    }

    OptionInfo(const QString &id, const QString &value, const QString &description) // TEST: NO
    {
        this->id          = id;
        this->value       = value;
        this->description = description;
    }



    QString id;
    QString value;
    QString description;
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_OTHER_OPTIONINFO_H
