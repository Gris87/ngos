#include "comboboxparameterwidget.h"

#include <QDebug>
#include <QVBoxLayout>

#include "src/com/ngos/devtools/build_config_gui/widgets/common/trackinggroupbox.h"



ComboboxParameterWidget::ComboboxParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent)
    : ParameterWidget(id, metaInformation, options, parent)
    , mComboBox(0)
    , mOptionsDescriptions()
    , mOptionsList()
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);



    TrackingGroupBox *groupBox = new TrackingGroupBox(mName, this);
    layout->addWidget(groupBox);



    QVBoxLayout *layout2 = new QVBoxLayout(groupBox);

    layout2->setSpacing(4);
    layout2->setContentsMargins(4, 4, 4, 4);



    mComboBox = new TrackingComboBox(groupBox);
    layout2->addWidget(mComboBox);



    QString metaValues = metaInformation.value("Values");

    mOptionsList = metaValues.split(',');

    for (qint64 i = 0; i < mOptionsList.length(); ++i)
    {
        QString &option = mOptionsList[i];
        option          = option.trimmed();



        OptionInfo optionInfo = options.value(option);

        if (optionInfo.description != "")
        {
            mOptionsDescriptions.insert(option, optionInfo.description);
        }
        else
        {
            qCritical() << "Description not found for option" << option << "for ComboBox parameter" << mId;

            return;
        }
    }

    mComboBox->addItems(mOptionsList);



    if (!mOptionsDescriptions.contains(mDefault))
    {
        qCritical() << "Invalid default value" << mValue << "specified for ComboBox parameter" << mId;

        return;
    }



    qint64 index = mOptionsList.indexOf(mValue);

    if (index < 0)
    {
        qCritical() << "Invalid value" << mValue << "specified for ComboBox parameter" << mId;

        return;
    }

    mComboBox->setCurrentIndex(index);



    connect(mComboBox, SIGNAL(currentIndexChanged(qint32)), this, SLOT(comboboxCurrentIndexChanged(qint32)));
    connect(mComboBox, SIGNAL(entered()),                   this, SLOT(widgetEntered()));
    connect(mComboBox, SIGNAL(leaved()),                    this, SLOT(widgetLeaved()));
    connect(groupBox,  SIGNAL(entered()),                   this, SLOT(widgetEntered()));
    connect(groupBox,  SIGNAL(leaved()),                    this, SLOT(widgetLeaved()));
}

void ComboboxParameterWidget::setValue(const QString &value)
{
    ParameterWidget::setValue(value);



    qint64 index = mOptionsList.indexOf(mValue);

    if (index < 0)
    {
        qCritical() << "Invalid value" << mValue << "specified for ComboBox parameter" << mId;

        return;
    }

    mComboBox->setCurrentIndex(index);
}

QString ComboboxParameterWidget::generatePrivateDetails()
{
    qint64 maxLen = 0;

    for (qint64 i = 0; i < mOptionsList.length(); ++i)
    {
        QString option = mOptionsList.at(i);

        if (option.length() > maxLen)
        {
            maxLen = option.length();
        }
    }



    QString values;

    for (qint64 i = 0; i < mOptionsList.length(); ++i)
    {
        QString option = mOptionsList.at(i);



        QString value = QString("%1 - %2").arg(option, -maxLen, QChar(' ')).arg(mOptionsDescriptions.value(option)).replace(' ', "&nbsp;");

        if (option == mDefault)
        {
            value = "<b>" + value + "</b>";
        }



        if (i > 0)
        {
            values.append("<br>");
        }

        values.append(value);
    }



    QString defaultValue = QString("%1 - %2").arg(mDefault, -qMax(mDefault.length(), mValue.length()), QChar(' ')).arg(mOptionsDescriptions.value(mDefault)).replace(' ', "&nbsp;");
    QString currentValue = QString("%1 - %2").arg(mValue,   -qMax(mDefault.length(), mValue.length()), QChar(' ')).arg(mOptionsDescriptions.value(mValue)).replace(' ',   "&nbsp;");



    return  "<h2>Values:</h2>" +
            values + "<br>" +
            "<br>" +
            "<b>Default:</b> " + defaultValue + "<br>" +
            "<b>Current:</b> " + currentValue;
}

void ComboboxParameterWidget::comboboxCurrentIndexChanged(qint32 index)
{
    setValue(mOptionsList.at(index));
}
