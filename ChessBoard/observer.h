#ifndef OBSERVER_H
#define OBSERVER_H


namespace fan {
class ChessBoard;
}

class Observer
{
public:
    Observer(){}
    virtual void up_date() = 0;
    void setBoard (fan::ChessBoard * board) { ob_board = board;}
protected:
    fan::ChessBoard * ob_board;

};

#endif // OBSERVER_H
