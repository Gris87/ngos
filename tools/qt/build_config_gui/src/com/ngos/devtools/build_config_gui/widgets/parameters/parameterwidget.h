#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_PARAMETERWIDGET_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_PARAMETERWIDGET_H



#include <QWidget>

#include <QHash>

#include <com/ngos/devtools/build_config_gui/other/optioninfo.h>



class ParameterWidget: public QWidget
{
    Q_OBJECT

public:
    explicit ParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent = nullptr); // TEST: NO

    virtual void setValue(const QString &value); // TEST: NO
    QString value() const; // TEST: NO

    void reset(); // TEST: NO

    void handleValueChanged(const QHash<QString, ParameterWidget *> &parameters); // TEST: NO

protected slots:
    void widgetEntered(); // TEST: NO
    void widgetLeaved(); // TEST: NO

protected:
    virtual QString generatePrivateDetails(); // TEST: NO

    QString mId;
    QString mName;
    QString mDescription;
    QString mEnabled;
    QString mDefault;
    QString mValue;

private:
    QString generateDetails(); // TEST: NO

    static ParameterWidget *sHoveredWidget;

signals:
    void valueChanged(); // TEST: NO
    void detailsUpdated(const QString &details); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_PARAMETERS_PARAMETERWIDGET_H
