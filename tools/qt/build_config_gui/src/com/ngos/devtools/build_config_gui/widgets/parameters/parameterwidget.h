#ifndef BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_PARAMETERWIDGET_H
#define BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_PARAMETERWIDGET_H



#include <QWidget>

#include "src/other/optioninfo.h"



class ParameterWidget: public QWidget
{
    Q_OBJECT

public:
    explicit ParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent = 0); // TEST: NO

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



#endif // BUILD_CONFIG_GUI_SRC_WIDGETS_PARAMETERS_PARAMETERWIDGET_H
