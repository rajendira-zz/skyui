#include "programwidget.h"
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QImage>
#include <QPalette>
#include "headermodel.h"

ProgramWidget::ProgramWidget(QWidget *parent) : QTabWidget(parent)
{
    table = new TableModel(this);
    setupViewer();
    setupTabs();
}

void ProgramWidget::setupViewer()
{
}

void ProgramWidget::setupTabs()
{
    QStringList groups;
    groups << "All Channels" << "Entertainment" << "Sports" << "Movies" << "HD Channels" << "Lifestyle";

    for (int i = 0; i < groups.size(); ++i) {
        QString str = groups.at(i);

        proxyModel = new QSortFilterProxyModel(this);
        //proxyModel = new HeaderModel(this);
        proxyModel->setSourceModel(table);
        proxyModel->setDynamicSortFilter(true);

        QTableView *tableView = new QTableView;
        tableView->setModel(proxyModel);
        tableView->setSortingEnabled(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->hide();//->setStretchLastSection(true);
        tableView->verticalHeader()->show();
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);

        QString newStr = QString("^[%1].*").arg(str);

        //proxyModel->setFilterRegExp(QRegExp(newStr, Qt::CaseInsensitive));
        //proxyModel->setFilterKeyColumn(0);
        proxyModel->sort(0, Qt::AscendingOrder);

        connect(tableView->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SIGNAL(selectionChanged(QItemSelection)));

        addTab(tableView, str);
        QPalette Pal(palette());
        Pal.setColor(QPalette::Background, Qt::red);
        setPalette(Pal);
    }
}
