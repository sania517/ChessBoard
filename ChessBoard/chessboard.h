#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <cstddef>
#include <vector>
#include "object.h"
#include "observer.h"
#include "koordinaty_xoda.h"
#include "rotationqueue.h"
//#include "qmlboardlist.h"
#include <iostream>

//class QmlBoardList;

namespace fan {

class ChessBoard
{
public:
    ChessBoard() : m_board{{nullptr}} {};
    void set(const Object* object, size_t x, size_t y) { m_board[x][y] = object;}
    void setPlayer(fan::Object::Color colorPlayer) { m_rotationQueue.push_back(colorPlayer);}
    int getNuberOfPlayers(){ return m_rotationQueue.size();}
    const Object* get(size_t x, size_t y) const {return m_board[x][y];}
    void addObserv(Observer *obser) { m_observers.push_back(obser); obser->setBoard(this); }
    bool setXod( koordinaty_Xoda *xod);
    koordinaty_Xoda * returnLastXod();
    void transition(){m_rotationQueue++;}
    void setSaveQueue(bool sq){saveQueue = sq;}
    bool getSaveQueue(){return saveQueue;}
private:
    const Object* m_board[8][8];
    //BoardConsoleView * _view;
    std::vector<Observer * > m_observers;
    std::vector<koordinaty_Xoda *> xods;
    RotationQueue m_rotationQueue;
    bool saveQueue = false;
    //QmlBoardList * _qmlBoardList;

};

}

#endif // CHESSBOARD_H
