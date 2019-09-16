#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "chessboard.h"
#include <vector>
#include "koordinaty_xoda.h"
#include "save.h"
#include "boardconsoleview.h"
#include "reader.h"
#include "kindofgame.h"
#include "needtoread.h"
#include <QObject>
#include "qmlboardlist.h"



class Controller : public QObject
{
    Q_OBJECT
public:

    Q_INVOKABLE void move(int in, int out);




public:
    Controller(kind_of_game kog,need_to_read ntr);
    //Controller();
    void start();
    void fill_board();
    void addXod(koordinaty_Xoda * k_xoda);
    fan::ChessBoard & getBoard();
    QmlBoardList* get_QmlBoardList();
    //BoardConsoleView & getView();
    //virtual void up_date();
private:

    kind_of_game modeKindGame;
    need_to_read modeRead ;
    BoardConsoleView m_view;
    Save save_in_file;
    fan::ChessBoard _board;
    Reader read_in_file;
    QmlBoardList m_qml_board_list;

    //std:: vector<koordinaty_Xoda *> xods;
};






#endif // CONTROLLER_H
