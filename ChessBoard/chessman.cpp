#include "chessman.h"
#include <iostream>
#include "chessboard.h"
#include "factory_of_figure.h"

namespace fan {


King::King(Color setColor): Object(setColor){}
const char* King::view() const
{
    if (color== white)
    return "*K*";
    else
        return " K ";
}

const char* King::fileNameToView()const
{
    if (color== white)
    return "wK.png";
    else
        return "bK.png";
}


bool King::proverkaXoda(koordinaty_Xoda &xod, ChessBoard *board) const{
    //bool vector = false;
    int delta_y = xod.m_out_y-xod.m_in_y;
    int delta_i = xod.m_out_i - xod.m_in_i;
    if ( !(delta_i >= -1 && delta_i<=1 && delta_y >= -1 && delta_y <=1 && ( delta_y || delta_i ) ) ){
        return false;
    }

    if ( auto tempObjeck = board->get(xod.m_out_y,xod.m_out_i)  ){
        if (tempObjeck->getColor() == color){
            return false;
        }
    }

board->transition();


    board->set (board->get(xod.m_in_y,xod.m_in_i), xod.m_out_y, xod.m_out_i);
    board->set (nullptr,xod.m_in_y,xod.m_in_i);

return true;
}


//-----------------------------------------------------
Queen::Queen(Color setColor): Object(setColor){}
const char* Queen::view() const
{
    if (color== white)
    return "*Q*";
    else
        return " Q ";
}

const char* Queen::fileNameToView()const
{
    if (color== white)
    return "wQ.png";
    else
        return "bQ.png";
}


bool Queen::proverkaXoda(koordinaty_Xoda &xod, ChessBoard *board) const{

    int delta_y = xod.m_out_y-xod.m_in_y;
    int modulDdelta_y;
    int step_y=0;
    if (delta_y < 0){
         modulDdelta_y = - delta_y;
         step_y = -1;
    } else {
        modulDdelta_y = delta_y;
        if (delta_y){
           step_y=1;
        }

    }

    int delta_i = xod.m_out_i - xod.m_in_i;
    int modulDdelta_i;
    int step_i=0;
    if (delta_i < 0){
        modulDdelta_i = - delta_i;
        step_i = -1;
    } else {
        modulDdelta_i = delta_i;
        if (delta_i){
            step_i=1;
        }

    }


    if ( !( ((modulDdelta_y && !modulDdelta_i) || (!modulDdelta_y && modulDdelta_i) || (modulDdelta_y == modulDdelta_i )) && ( modulDdelta_y || modulDdelta_i ) ) ){
        return false;
    }

    const Object * tempObjeck;

    if ( tempObjeck = board->get(xod.m_out_y,xod.m_out_i)  ){
        if (tempObjeck->getColor() == color){
            return false;
        }
    }

    delta_i = delta_i - step_i;
    delta_y = delta_y - step_y;

    while(delta_i || delta_y){

        if ( tempObjeck = board->get((xod.m_in_y + delta_y),(xod.m_in_i +delta_i)) ){
            return false;
        }
        delta_i = delta_i - step_i;
        delta_y = delta_y - step_y;

    }

    board->transition();
    board->set (board->get(xod.m_in_y,xod.m_in_i), xod.m_out_y, xod.m_out_i);
    board->set (nullptr,xod.m_in_y,xod.m_in_i);

    return true;
}
//------------------------------------------------------
Rook::Rook(Color setColor): Object(setColor){}
const char* Rook::view() const
{
    if (color== white)
    return "*R*";
    else
        return " R ";
}

const char* Rook::fileNameToView()const
{
    if (color== white)
    return "wR.png";
    else
        return "bR.png";
}


bool Rook::proverkaXoda(koordinaty_Xoda &xod,  ChessBoard *board) const{


    int delta_y = xod.m_out_y-xod.m_in_y;
    //int modulDdelta_y;
    int step_y=0;
    if (delta_y < 0){
         //modulDdelta_y = - delta_y;
         step_y = -1;
    } else {
        //modulDdelta_y = delta_y;
        if (delta_y){
           step_y=1;
        }

    }

    int delta_i = xod.m_out_i - xod.m_in_i;
    //int modulDdelta_i;
    int step_i=0;
    if (delta_i < 0){
        //modulDdelta_i = - delta_i;
        step_i = -1;
    } else {
        //modulDdelta_i = delta_i;
        if (delta_i){
            step_i=1;
        }

    }

    if( !((delta_y && !delta_i) || (!delta_y && delta_i)) ){
        return false;
    }

    const Object * tempObjeck;

    if ( tempObjeck = board->get(xod.m_out_y,xod.m_out_i)  ){
        if (tempObjeck->getColor() == color){
            return false;
        }
    }

    delta_i = delta_i - step_i;
    delta_y = delta_y - step_y;

    while(delta_i || delta_y){

        if ( tempObjeck = board->get((xod.m_in_y + delta_y),(xod.m_in_i +delta_i)) ){
            return false;
        }
        delta_i = delta_i - step_i;
        delta_y = delta_y - step_y;

    }

    board->transition();
    board->set (board->get(xod.m_in_y,xod.m_in_i), xod.m_out_y, xod.m_out_i);
    board->set (nullptr,xod.m_in_y,xod.m_in_i);

    return true;
}
//------------------------------------------------------

Bishop::Bishop(Color setColor): Object(setColor){}
const char* Bishop::view() const
{
    if (color== white)
    return "*B*";
    else
        return " B ";
}

const char* Bishop::fileNameToView()const
{
    if (color== white)
    return "wB.png";
    else
        return "bB.png";
}


bool Bishop::proverkaXoda(koordinaty_Xoda &xod,  ChessBoard *board) const{

    int delta_y = xod.m_out_y-xod.m_in_y;
    int modulDdelta_y;
    int step_y = 0;
    if (delta_y < 0){
         modulDdelta_y = - delta_y;
         step_y = -1;
    } else {
        modulDdelta_y = delta_y;
        if (delta_y){
           step_y=1;
        }

    }

    int delta_i = xod.m_out_i - xod.m_in_i;
    int modulDdelta_i;
    int step_i = 0;
    if (delta_i < 0){
        modulDdelta_i = - delta_i;
        step_i = -1;
    } else {
        modulDdelta_i = delta_i;
        if (delta_i){
            step_i=1;
        }

    }

    if ( !(delta_y == delta_i && delta_y != 0) ){
        return false;
    }

    const Object * tempObjeck;

    if ( tempObjeck = board->get(xod.m_out_y,xod.m_out_i)  ){
        if (tempObjeck->getColor() == color){
            return false;
        }
    }

    delta_i = delta_i - step_i;
    delta_y = delta_y - step_y;

    while(delta_i || delta_y){

        if ( tempObjeck = board->get((xod.m_in_y + delta_y),(xod.m_in_i +delta_i)) ){
            return false;
        }
        delta_i = delta_i - step_i;
        delta_y = delta_y - step_y;

    }

    board->transition();
    board->set (board->get(xod.m_in_y,xod.m_in_i), xod.m_out_y, xod.m_out_i);
    board->set (nullptr,xod.m_in_y,xod.m_in_i);

    return true;

}
//------------------------------------------------------

Knight::Knight(Color setColor): Object(setColor){}
const char* Knight::view() const
{
    if (color== white)
    return "*H*";
    else
        return " H ";
}

const char* Knight::fileNameToView()const
{
    if (color== white)
    return "wN.png";
    else
        return "bN.png";
}


bool Knight::proverkaXoda(koordinaty_Xoda &xod,  ChessBoard *board) const{

    int delta_y = xod.m_out_y - xod.m_in_y;
    if (delta_y < 0)
        delta_y = - delta_y;

    int delta_i = xod.m_out_i - xod.m_in_i;
    if (delta_i < 0)
        delta_i = - delta_i;

    if ( !((delta_i == 2 && delta_y == 1 ) || (delta_i == 1 && delta_y == 2 )) ){
        return false;
    }

    const Object * tempObjeck;

    if ( tempObjeck = board->get(xod.m_out_y,xod.m_out_i)  ){
        if (tempObjeck->getColor() == color){
            return false;
        }
    }

    board->transition();
    board->set (board->get(xod.m_in_y,xod.m_in_i), xod.m_out_y, xod.m_out_i);
    board->set (nullptr,xod.m_in_y,xod.m_in_i);

    return true;
}
//---------------------------------------------------------
Pawn::Pawn(Color setColor): Object(setColor){}
const char* Pawn::view() const
{
    if (color== white)
    return "*P*";
    else
        return " P ";
}
const char* Pawn::fileNameToView()const
{
    if (color== white)
    return "wP.png";
    else
        return "bP.png";
}


bool Pawn::proverkaXoda(koordinaty_Xoda &xod,  ChessBoard *board) const{

    int out_y, out_i, in_y, in_i, step;

    if (color == white){
        out_y = xod.m_out_y;
        out_i = xod.m_out_i;
        in_y = xod.m_in_y;
        in_i = xod.m_in_i;
        step = 1;
    } else{
        out_y = 7 - xod.m_out_y;
        out_i = 7 - xod.m_out_i;
        in_y = 7 - xod.m_in_y;
        in_i = 7 - xod.m_in_i;
        step = -1;
    }


    int delta_y = out_y - in_y;
    if (delta_y < 0)
        delta_y = - delta_y;

    int delta_i = out_i - in_i;

    const Object * tempObjeck;

    //if (color == white){


    if ( delta_i < 1 || delta_i > 2 || delta_y > 1 || ( delta_i == 2 && delta_y == 1)){
    return false;
    }

    bool tempBool = false;

        if( delta_y == 0 ) {
            if ( (delta_i == 1) && !(tempObjeck = board->get(xod.m_out_y, xod.m_out_i)) ){

                tempBool = true;
            }
            if (delta_i == 2 && in_i == 1 && !(tempObjeck = board->get(xod.m_out_y, xod.m_out_i)) && !(tempObjeck = board->get(xod.m_out_y, (xod.m_out_i-step)))  ){

                tempBool = true;
            }
        }
        if (delta_i == 1 && delta_y == 1 && (tempObjeck = board->get(xod.m_out_y, xod.m_out_i)) ){
            if (tempObjeck->getColor() != color){

            tempBool = true;
            } else return false;
        }





        if (!tempBool){
            return false;
        }

        tempObjeck = board->get(xod.m_in_y, xod.m_in_i);

    if (out_i == 7){ //проверка на изменение пешки на королеву


        Factory_of_Queen* foq = new Factory_of_Queen();
        Object* queen = foq->createFigure( tempObjeck->getColor() );
        board->set (queen, xod.m_out_y, xod.m_out_i);
        delete foq;
    } else {
        board->set (tempObjeck, xod.m_out_y, xod.m_out_i);
    }

    board->set (nullptr,xod.m_in_y,xod.m_in_i);
    board->transition();

    return true;




}
//----------------------------------------------------------



Cheker::Cheker(Color setColor): Object(setColor){}

const char* Cheker::view() const{
    if (color== white)
    return "*C*";
    else
        return " C ";
}
const char* Cheker::fileNameToView()const
{
    if (color== white)
    return "wP.png";
    else
        return "bP.png";
}



bool Cheker::proverkaXoda(koordinaty_Xoda &xod, ChessBoard *board) const{

    if (board->getSaveQueue()){
        koordinaty_Xoda* last = board->returnLastXod();
        if( (last->m_out_y != xod.m_in_y) || (last->m_out_i != xod.m_in_i)){
            std::cout << "The previous player did not finish the move the figure\n";
            return false;
        }
    }




    int out_y, out_i, in_y, in_i, /*step_i,*/ dir_y = 1, dir_i = 1;
    if ((xod.m_out_y - xod.m_in_y) < 0){
        dir_y = -1;
    }

    if ((xod.m_out_i - xod.m_in_i) < 0){
        dir_i = -1;
    }


    if (color == white){
        out_y = xod.m_out_y;
        out_i = xod.m_out_i;
        in_y = xod.m_in_y;
        in_i = xod.m_in_i;
        //step_i = 1;
    } else{
        out_y = 7 - xod.m_out_y;
        out_i = 7 - xod.m_out_i;
        in_y = 7 - xod.m_in_y;
        in_i = 7 - xod.m_in_i;
        //step_i = -1;
    }

    int delta_y = out_y - in_y;
    int delta_i = out_i - in_i;

    if (delta_y < 0){
        delta_y = - delta_y;
    }

     int sign_delta_i = 1;



    //int sign_delta_i = delta_i < 0 ? -1 : 1;

    if (delta_i < 0){
            sign_delta_i = -1;
            delta_i = - delta_i;
        }


    if ( (delta_y != delta_i) || !delta_y || delta_y > 2 ){
        return false;
    }



    const Object * tempObjeck;

    if ( (delta_y == 1 && delta_i == 1) ){
        if(sign_delta_i > 0){
            if ( !(tempObjeck = board->get(xod.m_out_y, xod.m_out_i) ) ){
                board->transition();
                board->setSaveQueue(false);
                tempObjeck = board->get(xod.m_in_y, xod.m_in_i);
                board->set(tempObjeck, xod.m_out_y, xod.m_out_i );
                board->set(nullptr, xod.m_in_y, xod.m_in_i);


                return true;

             } else {
                return false;
             }


        } else {
            return false;
        }

    }

    if (delta_y == 2 && !(tempObjeck = board->get(xod.m_out_y, xod.m_out_i))  ){
        if (tempObjeck = board->get( (xod.m_in_y + dir_y), (xod.m_in_i + dir_i) ) ){
            if (tempObjeck->getColor() != this->color){
                board->set(nullptr, (xod.m_in_y + dir_y), (xod.m_in_i + dir_i));

            } else return false;

        } else return false;

    } else return false;


        tempObjeck = board->get(xod.m_in_y, xod.m_in_i);

    if (out_i == 7){ //проверка на изменение пешки на королеву


        Factory_of_QueenCheker* foq = new Factory_of_QueenCheker();
        Object* queenCheker = foq->createFigure( tempObjeck->getColor() );
        board->set (queenCheker, xod.m_out_y, xod.m_out_i);
        delete foq;
    } else {
        board->set (tempObjeck, xod.m_out_y, xod.m_out_i);
    }

    board->set (nullptr,xod.m_in_y,xod.m_in_i);



bool tempBool = false;

if ( ( (xod.m_out_y + 2) < 8) && ( (xod.m_out_i + 2) < 8) ){
    if ( !(tempObjeck = board->get((xod.m_out_y + 2), (xod.m_out_i + 2) ) ) ) {
        if (tempObjeck = board->get((xod.m_out_y + 1), (xod.m_out_i + 1)) ){
            if (tempObjeck->getColor() != this->color){
                tempBool=true;
            }
        }
    }
}

if ( ( (xod.m_out_y + 2) < 8) && ( (xod.m_out_i - 2) >= 0) ){
    if ( !(tempObjeck = board->get((xod.m_out_y + 2), (xod.m_out_i - 2) ) ) ) {
        if (tempObjeck = board->get((xod.m_out_y + 1), (xod.m_out_i - 1)) ){
            if (tempObjeck->getColor() != this->color){
                tempBool=true;
            }
        }
    }
}

if ( ( (xod.m_out_y - 2) >= 0) && ( (xod.m_out_i + 2) < 7) ){
    if ( !(tempObjeck = board->get((xod.m_out_y - 2), (xod.m_out_i + 2) ) ) ) {
        if (tempObjeck = board->get((xod.m_out_y - 1), (xod.m_out_i + 1)) ){
            if (tempObjeck->getColor() != this->color){
                tempBool=true;
            }
        }
    }
}

if ( ( (xod.m_out_y - 2) >= 0) && ( (xod.m_out_i - 2) >= 0) ){
    if ( !(tempObjeck = board->get((xod.m_out_y - 2), (xod.m_out_i - 2) ) ) ) {
        if (tempObjeck = board->get((xod.m_out_y - 1), (xod.m_out_i - 1)) ){
            if (tempObjeck->getColor() != this->color){
                tempBool=true;
            }
        }
    }
}

if (tempBool){
    board->setSaveQueue(true);

} else {
    board->setSaveQueue(false);
    board->transition();
}

    return true;

}
//----------------------------------------------------------

QueenCheker::QueenCheker(Color setColor): Object(setColor){}




const char* QueenCheker::view() const{
    if (color== white)
    return "*Q*";
    else
        return " Q ";
}

const char* QueenCheker::fileNameToView()const
{
    if (color== white)
    return "wQ.png";
    else
        return "bQ.png";
}

bool QueenCheker::proverkaXoda(koordinaty_Xoda &xod, ChessBoard *board) const
{
    if (board->getSaveQueue()){
        koordinaty_Xoda* last = board->returnLastXod();
        if( (last->m_out_y != xod.m_in_y) || (last->m_out_i != xod.m_in_i)){
            std::cout << "The previous player did not finish the move the figure";
            return false;
        }
    }


    int delta_y = xod.m_out_y - xod.m_in_y;
    //int modulDdelta_y;
    int step_y=0;
    if (delta_y < 0){
         //modulDdelta_y = - delta_y;
         step_y = -1;
    } else {
        //modulDdelta_y = delta_y;
        if (delta_y){
           step_y=1;
        }

    }
    int delta_i = xod.m_out_i - xod.m_in_i;
    int modulDdelta_i;
    int step_i = 0;
    if (delta_i < 0){
        modulDdelta_i = - delta_i;
        step_i = -1;
    } else {
        modulDdelta_i = delta_i;
        if (delta_i){
            step_i = 1;
        }

    }



    const Object * tempObjeck;


    if ( !( (modulDdelta_i != 0) && (delta_i == delta_y) && !(tempObjeck = board->get(xod.m_out_y,xod.m_out_i)) ) ){
        return false;
    }
int count_step = 1;
bool flag = false;
while(modulDdelta_i > count_step ){

    tempObjeck = board->get( (xod.m_in_y + step_y * count_step), (xod.m_in_i + step_i * count_step) );
    count_step++;

    if (tempObjeck){
        if ( tempObjeck->getColor() == color ){
            return false;
        }
        if (!flag){
            flag = true;
        } else return false;
    } else {
        flag = false;
    }

}

count_step = 1;
while(modulDdelta_i > count_step ){

        board->set(nullptr, (xod.m_in_y + step_y * count_step), (xod.m_in_i + step_i * count_step));
        count_step++;
}




bool tempBool = false;

    int temp_delta_i;
    int temp_delta_y;
    int temp_delta;
//---------------------------------------------------------- +1 +1
    temp_delta_i = 7 - xod.m_out_i;
    temp_delta_y = 7 - xod.m_out_y;
    if (temp_delta_i > temp_delta_y){
        temp_delta = temp_delta_i;
    } else {
        temp_delta = temp_delta_y;
    }

    for (int q = 1; q < (temp_delta - 1); q++){
        if( tempObjeck = board->get( (xod.m_out_y+q), (xod.m_out_i+q) ) ){
            if (tempObjeck->getColor() != this->color){
                if ( !(tempObjeck = board->get( (xod.m_out_y+q+1), (xod.m_out_i+q+1) ) ) ){
                    tempBool = true;
                    break;
                }
            } else break;
        }
    }
//---------------------------------------------------------- -1 -1
    temp_delta_i = xod.m_out_i;
    temp_delta_y = xod.m_out_y;
    if (temp_delta_i > temp_delta_y){
        temp_delta = temp_delta_i;
    } else {
        temp_delta = temp_delta_y;
    }

    for (int q = 1; q < (temp_delta - 1); q++){
        if( tempObjeck = board->get( (xod.m_out_y-q), (xod.m_out_i-q) ) ){
            if (tempObjeck->getColor() != this->color){
                if ( !(tempObjeck = board->get( (xod.m_out_y-q-1), (xod.m_out_i-q-1) ) ) ){
                    tempBool = true;
                    break;
                }
            } else break;
        }
    }
//---------------------------------------------------------- +1 -1
    temp_delta_i = xod.m_out_i;
    temp_delta_y = 7 - xod.m_out_y;
    if (temp_delta_i > temp_delta_y){
        temp_delta = temp_delta_i;
    } else {
        temp_delta = temp_delta_y;
    }

    for (int q = 1; q < (temp_delta - 1); q++){
        if( tempObjeck = board->get( (xod.m_out_y+q), (xod.m_out_i-q) ) ){
            if (tempObjeck->getColor() != this->color){
                if ( !(tempObjeck = board->get( (xod.m_out_y+q+1), (xod.m_out_i-q-1) ) ) ){
                    tempBool = true;
                    break;
                }
            } else break;
        }
    }
//---------------------------------------------------------- -1 +1
    temp_delta_i = 7 - xod.m_out_i;
    temp_delta_y =  xod.m_out_y;
    if (temp_delta_i > temp_delta_y){
        temp_delta = temp_delta_i;
    } else {
        temp_delta = temp_delta_y;
    }

    for (int q = 1; q < (temp_delta - 1); q++){
        if( tempObjeck == board->get( (xod.m_out_y-q), (xod.m_out_i+q) ) ){
            if (tempObjeck->getColor() != this->color){
                if ( !(tempObjeck = board->get( (xod.m_out_y-q-1), (xod.m_out_i+q+1) ) ) ){
                    tempBool = true;
                    break;
                }
            } else break;
        }
    }

if (tempBool){
    board->setSaveQueue(true);

} else {
    board->setSaveQueue(false);
    board->transition();
}















    return true;
}
//----------------------------------------------------------
}
