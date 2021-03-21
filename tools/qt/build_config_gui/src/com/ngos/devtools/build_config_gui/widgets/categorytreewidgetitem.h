#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_CATEGORYTREEWIDGETITEM_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_CATEGORYTREEWIDGETITEM_H



#include <QTreeWidgetItem>

#include <QScrollArea>
#include <QVBoxLayout>



class CategoryTreeWidgetItem: public QTreeWidgetItem
{
public:
    CategoryTreeWidgetItem(const QString &title, QWidget *parent = nullptr); // TEST: NO

    QScrollArea* getPage() const; // TEST: NO
    QVBoxLayout* getLayout() const; // TEST: NO

private:
    QScrollArea *mPage;
    QVBoxLayout *mLayout;
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_CATEGORYTREEWIDGETITEM_H
