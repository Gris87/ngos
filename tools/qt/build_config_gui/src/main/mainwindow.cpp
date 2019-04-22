#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QQueue>
#include <QSettings>

#include "src/main/aboutdialog.h"
#include "src/other/global.h"
#include "src/widgets/categorytreewidgetitem.h"
#include "src/widgets/parameters/booleanparameterwidget.h"
#include "src/widgets/parameters/comboboxparameterwidget.h"
#include "src/widgets/parameters/integerpowerof2parameterwidget.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow())
    , mOptions()
    , mParameters()
{
    ui->setupUi(this);

    ui->splitter->setSizes(QList<qint32>() << 160 << 360 << 480);

    loadWindowState();
}

MainWindow::~MainWindow()
{
    saveWindowState();

    delete ui;
}

void MainWindow::loadBuildConfigFile()
{
    QString filePath = Global::sProjectDir + "/include/buildconfig.h";



    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "Failed to read file:" << filePath;

        return;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString &line = lines[i];

        if (line.endsWith('\r'))
        {
            line.remove(line.length() - 1, 1);
        }
    }

    parseBuildConfigFile(lines);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (ui->actionSave->isEnabled())
    {
        qint64 pressedButton = QMessageBox::question(this, tr("Save changes"), tr("Do you want to save changes before exit?"), QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel);

        if (pressedButton == QMessageBox::Yes)
        {
            on_actionSave_triggered();

            event->accept();
        }
        else
        if (pressedButton == QMessageBox::No)
        {
            event->accept();
        }
        else
        if (pressedButton == QMessageBox::Cancel)
        {
            event->ignore();
        }
        else
        {
            qCritical() << "Unexpected pressed button" << pressedButton;
        }
    }
    else
    {
        event->accept();
    }
}

void MainWindow::on_actionReload_triggered()
{
    mOptions.clear();
    mParameters.clear();



    QQueue<CategoryTreeWidgetItem *> categories;

    for (qint64 i = 0; i < ui->categoriesTreeWidget->topLevelItemCount(); ++i)
    {
        categories.enqueue((CategoryTreeWidgetItem *)ui->categoriesTreeWidget->topLevelItem(i));
    }



    while (!categories.isEmpty())
    {
        CategoryTreeWidgetItem *treeItem = categories.dequeue();

        for (qint64 i = 0; i < treeItem->childCount(); ++i)
        {
            categories.enqueue((CategoryTreeWidgetItem *)treeItem->child(i));
        }

        delete treeItem->getPage();
    }

    ui->categoriesTreeWidget->clear();



    loadBuildConfigFile();
}

void MainWindow::on_actionSave_triggered()
{
    QString filePath = Global::sProjectDir + "/include/buildconfig.h";



    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "Failed to read file:" << filePath;

        return;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString &line = lines[i];

        if (line.endsWith('\r'))
        {
            line.remove(line.length() - 1, 1);
        }
    }



    QHashIterator<QString, ParameterWidget *> it(mParameters);

    while (it.hasNext())
    {
        it.next();

        QString parameter = it.key();
        QString value     = it.value()->value();



        bool found = false;

        for (qint64 i = 0; i < lines.length(); ++i)
        {
            QString &line = lines[i];

            if (line.startsWith("#define " + parameter + ' '))
            {
                found = true;

                qint64 index = parameter.length() + 9;

                while (index < line.length() && line.at(index) == ' ')
                {
                    ++index;
                }

                line = line.left(index) + value;

                break;
            }
        }

        if (!found)
        {
            qCritical() << "Parameter" << parameter << "not found";
        }
    }



    QString newContent = lines.join('\n');

    if (newContent != content)
    {
        if (!file.open(QIODevice::WriteOnly))
        {
            qCritical() << "Failed to write file:" << filePath;

            return;
        }

        file.write(newContent.toUtf8());
        file.close();
    }



    ui->actionSave->setEnabled(false);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionReset_triggered()
{
    QHashIterator<QString, ParameterWidget *> it(mParameters);

    while (it.hasNext())
    {
        it.next();

        it.value()->reset();
    }
}

void MainWindow::on_categoriesTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem * /*previous*/)
{
    if (current)
    {
        CategoryTreeWidgetItem *categoryItem = (CategoryTreeWidgetItem *)current;

        ui->parametersStackedWidget->setCurrentWidget(categoryItem->getPage());
    }
}

void MainWindow::parameterValueChanged()
{
    QHashIterator<QString, ParameterWidget *> it(mParameters);

    while (it.hasNext())
    {
        it.next();

        it.value()->handleValueChanged(mParameters);
    }

    ui->actionSave->setEnabled(true);
}

void MainWindow::parameterDetailsUpdated(const QString &details)
{
    ui->detailsLabel->setText(details);
}

void MainWindow::parseBuildConfigFile(const QStringList &lines)
{
    QHash<QString, QHash<QString, QString>> parameters;
    QStringList                             parametersIds;



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (line.startsWith("#define "))
        {
            QString rightPart = line.mid(8).trimmed();

            qint64 index = rightPart.indexOf(' ');

            if (index >= 0)
            {
                QString id    = rightPart.left(index).trimmed();
                QString value = rightPart.mid(index + 1).trimmed();

                if (id.startsWith("OPTION_"))
                {
                    QString description;



                    qint64 index2 = value.indexOf("//");

                    if (index2 >= 0)
                    {
                        description = value.mid(index2 + 2).trimmed();
                        value       = value.left(index2).trimmed();
                    }



                    mOptions.insert(id, OptionInfo(id, value, description));
                }
                else
                if (id.startsWith("NGOS_BUILD_"))
                {
                    if (
                        i > 0
                        &&
                        lines.at(i - 1).trimmed() == "***/"
                       )
                    {
                        QStringList metaData;



                        qint64 position = i - 2;

                        while (position >= 0)
                        {
                            QString metaLine = lines.at(position).trimmed();

                            if (metaLine == "/***")
                            {
                                break;
                            }



                            if (metaLine.startsWith("***"))
                            {
                                metaLine = metaLine.mid(3).trimmed();
                            }
                            else
                            {
                                qCritical() << "Meta information should start with ***:" << metaLine;
                            }



                            if (metaLine != "")
                            {
                                metaData.prepend(metaLine);
                            }



                            --position;
                        }



                        QHash<QString, QString> metaInformation;

                        for (qint64 j = 0; j < metaData.length(); ++j)
                        {
                            QString metaLine = metaData.at(j);

                            qint64 index2 = metaLine.indexOf(':');

                            if (index2 >= 0)
                            {
                                QString metaName  = metaLine.left(index2).trimmed();
                                QString metaValue = metaLine.mid(index2 + 1).trimmed();

                                if (metaValue.endsWith('\\'))
                                {
                                    metaValue = metaValue.remove(metaValue.length() - 1, 1).trimmed();

                                    do
                                    {
                                        ++j;

                                        if (j >= metaData.length())
                                        {
                                            break;
                                        }



                                        QString metaNextValue = metaData.at(j);

                                        if (metaNextValue.endsWith('\\'))
                                        {
                                            metaNextValue = metaNextValue.remove(metaNextValue.length() - 1, 1).trimmed();

                                            metaValue.append('\n');
                                            metaValue.append(metaNextValue);
                                        }
                                        else
                                        {
                                            metaValue.append('\n');
                                            metaValue.append(metaNextValue);

                                            break;
                                        }
                                    } while(true);
                                }

                                metaInformation.insert(metaName, metaValue);
                            }
                            else
                            {
                                qCritical() << "Failed to parse attribute name in meta information:" << metaLine;
                            }
                        }



                        if (!metaInformation.contains("Category"))
                        {
                            qCritical() << "Meta information \"Category\" not found for parameter:" << id;

                            continue;
                        }

                        if (!metaInformation.contains("Name"))
                        {
                            qCritical() << "Meta information \"Name\" not found for parameter:" << id;

                            continue;
                        }

                        if (!metaInformation.contains("Description"))
                        {
                            qCritical() << "Meta information \"Description\" not found for parameter:" << id;

                            continue;
                        }

                        if (!metaInformation.contains("Type"))
                        {
                            qCritical() << "Meta information \"Type\" not found for parameter:" << id;

                            continue;
                        }

                        if (!metaInformation.contains("Default"))
                        {
                            qCritical() << "Meta information \"Default\" not found for parameter:" << id;

                            continue;
                        }

                        if (metaInformation.contains("Value"))
                        {
                            qCritical() << "Meta information \"Value\" was specified for parameter:" << id;

                            continue;
                        }



                        QString metaType = metaInformation.value("Type");

                        if (metaType == "Boolean")
                        {
                            if (!metaInformation.contains("Values"))
                            {
                                qCritical() << "Meta information \"Values\" not found for parameter:" << id;

                                continue;
                            }

                            if (!metaInformation.contains("Value description"))
                            {
                                qCritical() << "Meta information \"Value description\" not found for parameter:" << id;

                                continue;
                            }
                        }
                        else
                        if (metaType == "Combobox")
                        {
                            if (!metaInformation.contains("Values"))
                            {
                                qCritical() << "Meta information \"Values\" not found for parameter:" << id;

                                continue;
                            }
                        }
                        else
                        if (metaType.startsWith("Integer"))
                        {
                            if (!metaInformation.contains("Minimum"))
                            {
                                qCritical() << "Meta information \"Minimum\" not found for parameter:" << id;

                                continue;
                            }

                            if (!metaInformation.contains("Maximum"))
                            {
                                qCritical() << "Meta information \"Maximum\" not found for parameter:" << id;

                                continue;
                            }
                        }
                        else
                        {
                            qCritical() << "Unexpected meta information \"Type\" (" << metaType << ") was specified for parameter:" << id;

                            continue;
                        }



                        metaInformation.insert("Value", value);

                        parameters.insert(id, metaInformation);
                        parametersIds.append(id);
                    }
                    else
                    {
                        if (!parameters.contains(id))
                        {
                            qCritical() << "Parameter without meta information:" << id;
                        }
                    }
                }
                else
                {
                    qCritical() << "Unexpected ID found:" << id;
                }
            }
            else
            {
                if (line != "#define BUILDCONFIG_H")
                {
                    qCritical() << "Failed to parse line:" << line;
                }
            }
        }
    }



    buildParameters(parameters, parametersIds);
}

void MainWindow::buildParameters(const QHash<QString, QHash<QString, QString>> &parameters, const QStringList &parametersIds)
{
    for (qint64 i = 0; i < parametersIds.length(); ++i)
    {
        QString                 id              = parametersIds.at(i);
        QHash<QString, QString> metaInformation = parameters.value(id);



        QString metaCategory = metaInformation.value("Category");
        QString metaType     = metaInformation.value("Type");

        QStringList categories  = metaCategory.split("->");
        QString     topCategory = categories.first().trimmed();



        CategoryTreeWidgetItem *categoryItem = 0;

        for (qint64 j = 0; j < ui->categoriesTreeWidget->topLevelItemCount(); ++j)
        {
            CategoryTreeWidgetItem *treeItem = (CategoryTreeWidgetItem *)ui->categoriesTreeWidget->topLevelItem(j);

            if (treeItem->text(0) == topCategory)
            {
                categoryItem = treeItem;

                break;
            }
        }

        if (!categoryItem) // categoryItem == 0
        {
            categoryItem = new CategoryTreeWidgetItem(topCategory, this);

            ui->parametersStackedWidget->addWidget(categoryItem->getPage());

            ui->categoriesTreeWidget->addTopLevelItem(categoryItem);
        }



        for (qint64 j = 1; j < categories.length(); ++j)
        {
            QString subCategory = categories.at(j).trimmed();



            CategoryTreeWidgetItem *subCategoryItem = 0;

            for (qint64 k = 0; k < categoryItem->childCount(); ++k)
            {
                CategoryTreeWidgetItem *treeItem = (CategoryTreeWidgetItem *)categoryItem->child(k);

                if (treeItem->text(0) == subCategory)
                {
                    subCategoryItem = treeItem;

                    break;
                }
            }

            if (!subCategoryItem) // subCategoryItem == 0
            {
                subCategoryItem = new CategoryTreeWidgetItem(subCategory, this);

                ui->parametersStackedWidget->addWidget(subCategoryItem->getPage());

                categoryItem->addChild(subCategoryItem);
            }



            categoryItem = subCategoryItem;
        }



        ParameterWidget *parameterWidget = 0;

        if (metaType == "Boolean")
        {
            parameterWidget = new BooleanParameterWidget(id, metaInformation, mOptions, categoryItem->getPage());
        }
        else
        if (metaType == "Combobox")
        {
            parameterWidget = new ComboboxParameterWidget(id, metaInformation, mOptions, categoryItem->getPage());
        }
        else
        if (metaType == "Integer (Power of 2)")
        {
            parameterWidget = new IntegerPowerOf2ParameterWidget(id, metaInformation, mOptions, categoryItem->getPage());
        }
        else
        {
            qCritical() << "Unexpected meta information \"Type\" (" << metaType << ") was specified for parameter:" << id;

            continue;
        }



        categoryItem->getLayout()->addWidget(parameterWidget);

        connect(parameterWidget, SIGNAL(valueChanged()),                  this, SLOT(parameterValueChanged()));
        connect(parameterWidget, SIGNAL(detailsUpdated(const QString &)), this, SLOT(parameterDetailsUpdated(const QString &)));

        mParameters.insert(id, parameterWidget);
    }



    parameterValueChanged();
    ui->actionSave->setEnabled(false);



    ui->categoriesTreeWidget->expandAll();
}

void MainWindow::saveWindowState()
{
    QSettings settings("NGOS", "build_config_gui");

    settings.setValue("MainWindow/geometry",      saveGeometry());
    settings.setValue("MainWindow/windowState",   saveState());
    settings.setValue("MainWindow/splitterState", ui->splitter->saveState());
}

void MainWindow::loadWindowState()
{
    QSettings settings("NGOS", "build_config_gui");

    // Ignore CppAlignmentVerifier [BEGIN]
    restoreGeometry(           settings.value("MainWindow/geometry").toByteArray());
    restoreState(              settings.value("MainWindow/windowState").toByteArray());
    ui->splitter->restoreState(settings.value("MainWindow/splitterState").toByteArray());
    // Ignore CppAlignmentVerifier [END]
}
