#include "chessboard.h"

namespace fan {




bool ChessBoard::setXod(koordinaty_Xoda *xod)
{
    const Object * object;
    if ( !(object = get(xod->m_in_y, xod->m_in_i) ) ){
        std::cout << "Empty figure";
        return false;
    }

    if (m_rotationQueue.front() != object->getColor()){
        std::cout << "XODIT DRUGOY IGROK !!!/n";
        return false;
    }




    if ( object->proverkaXoda(*xod, this) && object){
        //object->proverkaXoda(*xod, this);
        xods.push_back(xod);


        int size = m_observers.size();
        for (;size > 0; --size){
        m_observers[size-1]->up_date();
        }
        return true;


    } else {
        std::cout << "Figura TAK HE XODIT\n";
        return false;
    }
}

koordinaty_Xoda * ChessBoard::returnLastXod()
{
    int sizeVectorXods = xods.size();
    return xods[sizeVectorXods - 1];
}






}
