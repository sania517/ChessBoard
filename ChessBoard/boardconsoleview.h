#ifndef BOARDCONSOLEVIEW_H
#define BOARDCONSOLEVIEW_H
#include "observer.h"
namespace fan {
class ChessBoard ;
}

class BoardConsoleView : public Observer
{

public:
    BoardConsoleView();
    void show() const;
    //void update();
//    void update(fan::ChessBoard & board_contr);
    void up_date();

private:
    const char* m_data[8][8];
   // fan::ChessBoard & m_board;
};

#endif // BOARDCONSOLEVIEW_H
