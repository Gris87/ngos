#ifndef BUILD_CONFIG_MAKER_SRC_MAIN_BUILDCONFIGMAKER_H
#define BUILD_CONFIG_MAKER_SRC_MAIN_BUILDCONFIGMAKER_H



#include <QMap>



class BuildConfigMaker
{
public:
    BuildConfigMaker(const QString &buildConfigPath, QMap<QString, QString> parameters); // TEST: NO

    qint64 process(); // TEST: NO

private:
    QString                mBuildConfigPath;
    QMap<QString, QString> mParameters;
};



#endif // BUILD_CONFIG_MAKER_SRC_MAIN_BUILDCONFIGMAKER_H
