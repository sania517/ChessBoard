#ifndef FACTORY_OF_OBJECT_H
#define FACTORY_OF_OBJECT_H
#include "object.h"


class Factory_of_Object
{
public:
    virtual fan::Object* createFigure(fan::Object::Color setColor) = 0;
    virtual ~Factory_of_Object() {}
};

#endif // FACTORY_OF_OBJECT_H
