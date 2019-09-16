#ifndef SAVE_H
#define SAVE_H
#include "observer.h"
#include "chessboard.h"
#include "kindofgame.h"



class Save : public Observer
{
public:
    Save(){}
    void setFileForSave(kind_of_game kog) {m_kind_of_game = kog;}
    void up_date();
    void clearFile();
    //void setBoard(fan::ChessBoard *board);
private:
    kind_of_game m_kind_of_game = emptyKindGame;
   //fan::ChessBoard & m_board;
};

#endif // SAVE_H
