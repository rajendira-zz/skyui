#ifndef HEADERMODEL_H
#define HEADERMODEL_H

#include <QIdentityProxyModel>

class HeaderModel : public QIdentityProxyModel
{
public:
    explicit HeaderModel(QObject * parent = 0)
        : QIdentityProxyModel(parent)
    { }
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

};

#endif // HEADERMODEL_H
