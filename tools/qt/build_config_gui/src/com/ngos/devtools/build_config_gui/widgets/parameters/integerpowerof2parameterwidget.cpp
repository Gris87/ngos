#include "integerpowerof2parameterwidget.h"

#include <QDebug>
#include <QVBoxLayout>

#include "com/ngos/devtools/build_config_gui/widgets/common/trackinggroupbox.h"



IntegerPowerOf2ParameterWidget::IntegerPowerOf2ParameterWidget(const QString &id, const QHash<QString, QString> &metaInformation, QHash<QString, OptionInfo> &options, QWidget *parent)
    : ParameterWidget(id, metaInformation, options, parent)
    , mComboBox(0)
    , mMinimum()
    , mMaximum()
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



    mMinimum = metaInformation.value("Minimum");
    mMaximum = metaInformation.value("Maximum");



    if (!mMinimum.startsWith("0x"))
    {
        qCritical() << "Unexpected format for minimum value" << mMinimum << "specified for Integer (Power of 2) parameter" << mId;

        return;
    }

    if (!mMaximum.startsWith("0x"))
    {
        qCritical() << "Unexpected format for maximum value" << mMaximum << "specified for Integer (Power of 2) parameter" << mId;

        return;
    }



    bool    ok1          = false;
    quint64 minimumValue = mMinimum.mid(2).toULongLong(&ok1, 16);

    if (!ok1)
    {
        qCritical() << "Unexpected format for minimum value" << mMinimum << "specified for Integer (Power of 2) parameter" << mId;

        return;
    }



    bool    ok2          = false;
    quint64 maximumValue = mMaximum.mid(2).toULongLong(&ok2, 16);

    if (!ok2)
    {
        qCritical() << "Unexpected format for maximum value" << mMaximum << "specified for Integer (Power of 2) parameter" << mId;

        return;
    }



    quint64 value = 1;

    for (qint64 i = 0; i < 64; ++i)
    {
        if (value > maximumValue)
        {
            break;
        }

        if (value >= minimumValue)
        {
            mOptionsList.append(QString("0x%1").arg(value, 16, 16, QChar('0')));
        }

        value <<= 1;
    }



    mComboBox->addItems(mOptionsList);



    if (!mOptionsList.contains(mDefault))
    {
        qCritical() << "Invalid default value" << mValue << "specified for Integer (Power of 2) parameter" << mId;

        return;
    }



    qint64 index = mOptionsList.indexOf(mValue);

    if (index < 0)
    {
        qCritical() << "Invalid value" << mValue << "specified for Integer (Power of 2) parameter" << mId;

        return;
    }

    mComboBox->setCurrentIndex(index);



    connect(mComboBox, SIGNAL(currentIndexChanged(qint32)), this, SLOT(comboboxCurrentIndexChanged(qint32)));
    connect(mComboBox, SIGNAL(entered()),                   this, SLOT(widgetEntered()));
    connect(mComboBox, SIGNAL(leaved()),                    this, SLOT(widgetLeaved()));
    connect(groupBox,  SIGNAL(entered()),                   this, SLOT(widgetEntered()));
    connect(groupBox,  SIGNAL(leaved()),                    this, SLOT(widgetLeaved()));
}

void IntegerPowerOf2ParameterWidget::setValue(const QString &value)
{
    ParameterWidget::setValue(value);



    qint64 index = mOptionsList.indexOf(mValue);

    if (index < 0)
    {
        qCritical() << "Invalid value" << mValue << "specified for Integer (Power of 2) parameter" << mId;

        return;
    }

    mComboBox->setCurrentIndex(index);
}

QString IntegerPowerOf2ParameterWidget::generatePrivateDetails()
{
    QString values = "Integer (Power of 2)";

    return  "<h2>Values:</h2>" +
            values + "<br>" +
            "<br>" +
            "<b>Minimum:</b> " + mMinimum + "<br>" +
            "<b>Maximum:</b> " + mMaximum + "<br>" +
            "<br>" +
            "<b>Default:</b> " + mDefault + "<br>" +
            "<b>Current:</b> " + mValue;
}

void IntegerPowerOf2ParameterWidget::comboboxCurrentIndexChanged(qint32 index)
{
    setValue(mOptionsList.at(index));
}
