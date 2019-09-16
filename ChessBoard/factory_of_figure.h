#ifndef FACTORY_OF_FIGURE_H
#define FACTORY_OF_FIGURE_H
#include "factory_of_object.h"
#include "chessman.h"

class Factory_of_King : public Factory_of_Object
{
public:
    fan::Object* createFigure(fan::Object::Color setColor){
        return new fan::King(setColor);
    }
};

class Factory_of_Queen : public Factory_of_Object
{
public:
    fan::Object* createFigure(fan::Object::Color setColor){
        return new fan::Queen(setColor);
    }
};

class Factory_of_Rook : public Factory_of_Object
{
public:
    fan::Object* createFigure(fan::Object::Color setColor){
        return new fan::Rook(setColor);
    }
};

class Factory_of_Bishop : public Factory_of_Object
{
public:
    fan::Object* createFigure(fan::Object::Color setColor){
        return new fan::Bishop(setColor);
    }
};

class Factory_of_Knight : public Factory_of_Object
{
public:
    fan::Object* createFigure(fan::Object::Color setColor){
        return new fan::Knight(setColor);
    }
};

class Factory_of_Pawn : public Factory_of_Object
{
public:
    fan::Object* createFigure(fan::Object::Color setColor){
        return new fan::Pawn(setColor);
    }
};

class Factory_of_Cheker : public Factory_of_Object
{
public:
    fan::Object* createFigure(fan::Object::Color setColor){
        return new fan::Cheker(setColor);
    }
};

class Factory_of_QueenCheker : public Factory_of_Object
{
public:
    fan::Object* createFigure(fan::Object::Color setColor){
        return new fan::QueenCheker(setColor);
    }
};

#endif // FACTORY_OF_FIGURE_H
