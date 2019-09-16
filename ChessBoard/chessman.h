#ifndef CHESSMAN_H
#define CHESSMAN_H

#include "object.h"
#include "chessboard.h"

namespace fan {

class King: public Object
{
public:
    const char* view() const;
    const char* fileNameToView()const;
    bool proverkaXoda(koordinaty_Xoda & xod, fan::ChessBoard * board) const;
    King(Color setColor);

};

class Queen: public Object
{
public:

    bool proverkaXoda(koordinaty_Xoda & xod,  fan::ChessBoard * board)  const;
    Queen(Color setColor);
    const char* view() const;
    const char* fileNameToView()const;
};

class Rook: public Object
{
public:

    bool proverkaXoda(koordinaty_Xoda & xod,  fan::ChessBoard * board)  const;
    Rook(Color setColor);
    const char* view() const;
    const char* fileNameToView()const;
};

class Bishop: public Object
{
public:

    bool proverkaXoda(koordinaty_Xoda & xod,  fan::ChessBoard * board)  const;
    Bishop(Color setColor);
    const char* view() const;
    const char* fileNameToView()const;
};

class Knight: public Object
{
public:

    bool proverkaXoda(koordinaty_Xoda & xod,  fan::ChessBoard * board)  const;
    Knight(Color setColor);
    const char* view() const;
    const char* fileNameToView()const;
};

class Pawn: public Object
{
public:

    bool proverkaXoda(koordinaty_Xoda & xod,  fan::ChessBoard * board)  const;
    Pawn(Color setColor);
    const char* view() const;
    const char* fileNameToView()const;
};

class Cheker: public Object
{
public:

    bool proverkaXoda(koordinaty_Xoda & xod,  fan::ChessBoard * board)  const;
    Cheker(Color setColor);
    const char* view() const;
    const char* fileNameToView()const;
};

class QueenCheker: public Object
{
public:

    bool proverkaXoda(koordinaty_Xoda & xod,  fan::ChessBoard * board) const;
    QueenCheker(Color setColor);
    const char* view() const;
    const char* fileNameToView()const;
};


}

#endif // CHESSMAN_H
