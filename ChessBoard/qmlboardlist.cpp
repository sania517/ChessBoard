#include "qmlboardlist.h"
//#include <QObject>
#include <QAbstractListModel>
#include <QString>

QmlBoardList::QmlBoardList(QObject *parent)
    :QAbstractListModel(parent)
{

    for (int i = 0; i < 8; i++){
        for(int y = 0; y < 8; y++){
                m_list[i+y*8] = " ";
        }
    }
}

void QmlBoardList::fillList(fan::ChessBoard &board)
{
    for (int i = 0; i < 8; i++){
        for(int y = 0; y < 8; y++){
            if (auto temp = board.get(i,y)){
                m_list[i+y*8] = temp->fileNameToView();
            } else {
                m_list[i+y*8] = " ";
            }
        }
    }

}

int QmlBoardList::rowCount(const QModelIndex &) const
{
    return m_list.size();
}

QVariant QmlBoardList::data(const QModelIndex &index, int role) const
{

    return "figure/chess24/"+m_list[index.row()];
}

void QmlBoardList::moveData(int begin, int end)
{
    m_list[end] = m_list[begin];
    m_list[begin] = " ";

    QModelIndex beginIndex = createIndex(begin,0);
    QModelIndex endIndex   = createIndex(end,0);

    emit dataChanged(beginIndex, beginIndex);
    emit dataChanged(endIndex,endIndex);
}

QHash<int,QByteArray> QmlBoardList::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[UrlRole] = "urlChess";
    return roles;
}


