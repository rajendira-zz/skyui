#ifndef PROGRAMWIDGET_H
#define PROGRAMWIDGET_H

#include <QTabWidget>
#include <QItemSelection>
#include "tablemodel.h"
//#include "newprogramtab.h"
#include "headermodel.h"

class QSortFilterProxyModel;
class QItemSelectionModel;
class HeaderModel;

class ProgramWidget: public QTabWidget
{
    Q_OBJECT

public:
    ProgramWidget(QWidget *parent=0);

public slots:

signals:
    void selectionChanged(const QItemSelection &selected);

private:
    void setupViewer();
    void setupTabs();

    TableModel *table;
    QSortFilterProxyModel *proxyModel;
    //HeaderModel *proxyModel;
};

#endif // PROGRAMWIDGET_H
