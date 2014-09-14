#include "headermodel.h"

HeaderModel::HeaderModel()
{
}

QVariant HeaderModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal)
    {
        if(role == Qt::DisplayRole)
            switch(section)
            {
            case 0: return "Id";            break;
            case 1: return "Designation";   break;

            default:
                return QString("Column %1").arg(section + 1);
                break;
            }
    }
    else if(orientation == Qt::Vertical)
    {
        if(role == Qt::DecorationRole)
            return QIcon("imgs/arrow.png");
    }

    return QVariant();
}
