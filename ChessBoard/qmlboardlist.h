#ifndef QMLBOARDLIST_H
#define QMLBOARDLIST_H
#include <QAbstractListModel>
#include <array>
#include "chessboard.h"
#include <QString>



class QmlBoardList : public QAbstractListModel
{

    Q_OBJECT

public:

    QmlBoardList(QObject *parent = Q_NULLPTR);
    QHash<int,QByteArray> roleNames() const;

    enum ChessBoardRoles {UrlRole = Qt::UserRole+1};

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
   // bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
   // Qt::ItemFlags flags(const QModelIndex &index) const;
    void moveData(int begin, int end);
    void fillList(fan::ChessBoard & board);


private:
   std::array<QString, 64> m_list;

};

#endif // QMLBOARDLIST_H
