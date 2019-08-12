#ifndef BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_BOOLEANPARAMETERWIDGET_H
#define BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_BOOLEANPARAMETERWIDGET_H



#include "src/widgets/parameters/parameterwidget.h"

#include "src/widgets/common/trackingcheckbox.h"



class BooleanParameterWidget: public ParameterWidget
{
    Q_OBJECT

public:
    explicit BooleanParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent = 0); // TEST: NO

    void setValue(const QString &value) override; // TEST: NO

protected:
    QString generatePrivateDetails() override; // TEST: NO

private slots:
    void checkboxToggled(bool checked); // TEST: NO

private:
    TrackingCheckBox *mCheckBox;
    QString           mTrueValue;
    QString           mFalseValue;
    QString           mTrueDescription;
    QString           mFalseDescription;
};



#endif // BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_BOOLEANPARAMETERWIDGET_H
