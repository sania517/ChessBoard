#ifndef ROTATIONQUEUE_H
#define ROTATIONQUEUE_H

#include <list>
#include <memory>
#include "object.h"



class RotationQueue : public std::list<fan::Object::Color>
{

    //using std::list<std::unique_ptr<fan::Object::Color>>::list;
    //using std::list<std::unique_ptr<fan::Object::Color>>::emplace_back;
    //using std::list<std::unique_ptr<fan::Object::Color>>::front;
    //using std::list<fan::Object::Color>::push_back;
    //using std::list<fan::Object::Color>::size;
 public:
    void operator++()
    {
        this->emplace_back(std::move(this->front()));
        this->pop_front();
        return;
    }

    void operator ++(int)
    {
        this->emplace_back(std::move(this->front()));
        this->pop_front();
        return;

    }


};

#endif // ROTATIONQUEUE_H
