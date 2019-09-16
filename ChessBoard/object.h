#ifndef OBJECT_H
#define OBJECT_H

#include "koordinaty_xoda.h"

namespace fan {

class ChessBoard;
class Object
{
public:
    enum Color {white,black };

    Object (Color setColor) : color(setColor){;}
    Color getColor() const {return color;}
    virtual const char* view() const = 0;
    virtual const char* fileNameToView() const {return "   ";}


    virtual bool proverkaXoda(koordinaty_Xoda & xod,  ChessBoard * board) const = 0;
protected:
    Color color;

};

}

#endif // OBJECT_H
