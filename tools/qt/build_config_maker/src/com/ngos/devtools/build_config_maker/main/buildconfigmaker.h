#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_MAKER_MAIN_BUILDCONFIGMAKER_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_MAKER_MAIN_BUILDCONFIGMAKER_H



#include <QMap>



class BuildConfigMaker
{
public:
    BuildConfigMaker(const QString &buildConfigPath, bool reset, QMap<QString, QString> parameters); // TEST: NO

    qint64 process(); // TEST: NO

private:
    QString                mBuildConfigPath;
    bool                   mReset;
    QMap<QString, QString> mParameters;
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_MAKER_MAIN_BUILDCONFIGMAKER_H
