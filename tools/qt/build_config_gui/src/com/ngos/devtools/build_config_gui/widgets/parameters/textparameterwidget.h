#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_TEXTPARAMETERWIDGET_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_TEXTPARAMETERWIDGET_H



#include <com/ngos/devtools/build_config_gui/widgets/parameters/parameterwidget.h>

#include <com/ngos/devtools/build_config_gui/widgets/common/trackinglineedit.h>



class TextParameterWidget: public ParameterWidget
{
    Q_OBJECT

public:
    explicit TextParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent = nullptr); // TEST: NO

    void setValue(const QString &value) override; // TEST: NO

protected:
    QString generatePrivateDetails() override; // TEST: NO

private slots:
    void lineEditTextChanged(const QString &text); // TEST: NO

private:
    TrackingLineEdit *mLineEdit;
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_TEXTPARAMETERWIDGET_H
