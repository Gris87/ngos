#ifndef BUILD_CONFIG_GUI_SRC_WIDGETS_CATEGORYTREEWIDGETITEM_H
#define BUILD_CONFIG_GUI_SRC_WIDGETS_CATEGORYTREEWIDGETITEM_H



#include <QTreeWidgetItem>

#include <QScrollArea>
#include <QVBoxLayout>



class CategoryTreeWidgetItem : public QTreeWidgetItem
{
public:
    CategoryTreeWidgetItem(const QString &title, QWidget *parent = 0); // TEST: NO

    QScrollArea* getPage() const; // TEST: NO
    QVBoxLayout* getLayout() const; // TEST: NO

private:
    QScrollArea *mPage;
    QVBoxLayout *mLayout;
};



#endif // BUILD_CONFIG_GUI_SRC_WIDGETS_CATEGORYTREEWIDGETITEM_H
