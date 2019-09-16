#include "controller.h"
#include <iostream>
#include "chessman.h"
#include "xod.h"
#include "boardconsoleview.h"
#include "koordinaty_xoda.h"
#include "factory_of_figure.h"


//Controller::Controller()
//{
//}
Controller::Controller(kind_of_game kog,need_to_read ntr)
    : modeKindGame(kog), modeRead(ntr)
{
    fill_board();
    m_qml_board_list.fillList(_board);


}


void Controller::fill_board()

{

    if (!modeKindGame){
        modeKindGame = kindOfGame().return_kind_game();
    }

    using namespace fan;

    if (modeKindGame == chess){

        _board.setPlayer(fan::Object::white);
        _board.setPlayer(fan::Object::black);

    Factory_of_King  * factoryKing   = new Factory_of_King();
    Factory_of_Queen * factoryQueen  = new Factory_of_Queen();
    Factory_of_Rook  * factoryRook   = new Factory_of_Rook();
    Factory_of_Knight* factoryknight = new Factory_of_Knight();
    Factory_of_Bishop* factoryBishop = new Factory_of_Bishop();
    Factory_of_Pawn  * factoryPawn   = new Factory_of_Pawn();

    Object * kingWhite   = factoryKing->createFigure(fan::Object::white);
    Object * queenWhite  = factoryQueen->createFigure(fan::Object::white);
    Object * rookWhite   = factoryRook->createFigure(fan::Object::white);
    Object * knightWhite = factoryknight->createFigure(fan::Object::white);
    Object * bishopWhite = factoryBishop->createFigure(fan::Object::white);
    Object * pawnWhite   = factoryPawn->createFigure(fan::Object::white);

    Object * kingBlack   = factoryKing->createFigure(fan::Object::black);
    Object * queenBlack  = factoryQueen->createFigure(fan::Object::black);
    Object * rookBlack   = factoryRook->createFigure(fan::Object::black);
    Object * knightBlack = factoryknight->createFigure(fan::Object::black);
    Object * bishopBlack = factoryBishop->createFigure(fan::Object::black);
    Object * pawnBlack   = factoryPawn->createFigure(fan::Object::black);

    delete factoryKing;
    delete factoryQueen;
    delete factoryRook;
    delete factoryknight;
    delete factoryBishop;
    delete factoryPawn;

    //fan::King   * kingWhite = new King(fan::Object::white);
    //fan::Queen  * queenWhite = new Queen(fan::Object::white)  ;
    //fan::Rook   * rookWhite = new Rook(Object::white);
    //fan::Knight * knightWhite = new Knight(Object::white);
    //fan::Bishop * bishopWhite = new Bishop(Object::white);
    //fan::Pawn   * pawnWhite = new Pawn(Object::white);

    _board.set(kingWhite, 3, 0);
    _board.set(queenWhite, 4, 0);
    _board.set(bishopWhite, 5, 0);
    _board.set(bishopWhite, 2, 0);
    _board.set(rookWhite, 0, 0);
    _board.set(rookWhite, 7, 0);
    _board.set(knightWhite, 1, 0);
    _board.set(knightWhite, 6, 0);

    _board.set(pawnWhite, 0, 1);
    _board.set(pawnWhite, 1, 1);
    _board.set(pawnWhite, 2, 1);
    _board.set(pawnWhite, 3, 1);
    _board.set(pawnWhite, 4, 1);
    _board.set(pawnWhite, 5, 1);
    _board.set(pawnWhite, 6, 1);
    _board.set(pawnWhite, 7, 1);

    //fan::King * kingBlack = new King(fan::Object::black);
    //fan::Queen * queenBlack = new Queen(fan::Object::black)  ;
    //fan::Rook  * rookBlack = new Rook(Object::black);
    //fan::Knight  * knightBlack = new Knight(Object::black);
    //fan::Bishop  * bishopBlack = new Bishop(Object::black);
    //fan::Pawn *  pawnBlack = new Pawn(Object::black);

    _board.set(kingBlack, 3, 7);
    _board.set(queenBlack, 4, 7);
    _board.set(bishopBlack, 5, 7);
    _board.set(bishopBlack, 2, 7);
    _board.set(rookBlack, 0, 7);
    _board.set(rookBlack, 7, 7);
    _board.set(knightBlack, 1, 7);
    _board.set(knightBlack, 6, 7);

    _board.set(pawnBlack, 0, 6);
    _board.set(pawnBlack, 1, 6);
    _board.set(pawnBlack, 2, 6);
    _board.set(pawnBlack, 3, 6);
    _board.set(pawnBlack, 4, 6);
    _board.set(pawnBlack, 5, 6);
    _board.set(pawnBlack, 6, 6);
    _board.set(pawnBlack, 7, 6);
    }
    if (modeKindGame == chekers){

        _board.setPlayer(fan::Object::white);
        _board.setPlayer(fan::Object::black);

        Factory_of_Cheker * factoryCheker = new Factory_of_Cheker();
        Factory_of_QueenCheker * factoryQueenCheker = new Factory_of_QueenCheker();
        Object * chekerWhite = factoryCheker->createFigure(fan::Object::white);
        Object * chekerBlack = factoryCheker->createFigure(fan::Object::black);
        //Object * queenChekerWhite = factoryQueenCheker->createFigure(fan::Object::white);
        //Object * queenChekerBlack = factoryQueenCheker->createFigure(fan::Object::black);

        delete factoryCheker;
        delete factoryQueenCheker;

        _board.set(chekerWhite, 0, 0);
        _board.set(chekerWhite, 2, 0);
        _board.set(chekerWhite, 4, 0);
        _board.set(chekerWhite, 6, 0);
        _board.set(chekerWhite, 1, 1);
        _board.set(chekerWhite, 3, 1);
        _board.set(chekerWhite, 5, 1);
        _board.set(chekerWhite, 7, 1);
        _board.set(chekerWhite, 0, 2);
        _board.set(chekerWhite, 2, 2);
        _board.set(chekerWhite, 4, 2);
        _board.set(chekerWhite, 6, 2);

        _board.set(chekerBlack, 7, 7);
        _board.set(chekerBlack, 5, 7);
        _board.set(chekerBlack, 3, 7);
        _board.set(chekerBlack, 1, 7);
        _board.set(chekerBlack, 6, 6);
        _board.set(chekerBlack, 4, 6);
        _board.set(chekerBlack, 2, 6);
        _board.set(chekerBlack, 0, 6);
        _board.set(chekerBlack, 7, 5);
        _board.set(chekerBlack, 5, 5);
        _board.set(chekerBlack, 3, 5);
        _board.set(chekerBlack, 1, 5);


    }
}



void Controller::start()
{
    if (_board.getNuberOfPlayers() < 2)
    {
    std::cout << "Not set number players. ERROR CODING"  ;
    return;
    }
    _board.addObserv(&m_view);
    save_in_file.setFileForSave(modeKindGame);


    if (!modeRead){
        modeRead = NeedToRead().get_need_to_read();
    }

    if (modeRead == read){
        read_in_file.readGame(modeKindGame);
        std::vector<koordinaty_Xoda * > & read_xods_invert = read_in_file.getXodsInFile();

        int sizeVector = read_xods_invert.size();

        for (int i=0; i < sizeVector; i++){

            addXod(read_xods_invert[i]);

        }

    }else if (modeRead == not_read){
        save_in_file.clearFile();

    }


    _board.addObserv(&save_in_file);

    m_view.up_date();

    Xod xod_(*this);

    xod_.readXod();
}

void Controller::addXod(koordinaty_Xoda *k_xoda)
{
    std::cout << "!";
    _board.setXod(k_xoda);
}
void Controller::move(int in, int out)
{

    int in_i = in / 8;
    int in_y = in % 8;
    int out_i = out / 8;
    int out_y = out % 8;

    koordinaty_Xoda * qml_k_xoda = new koordinaty_Xoda{in_y, in_i, out_y, out_i};
    if (_board.setXod(qml_k_xoda)){
        m_qml_board_list.moveData(in,out);
    }



}

fan::ChessBoard & Controller::getBoard()
{
  return _board;
}

QmlBoardList* Controller::get_QmlBoardList()
{
    return &m_qml_board_list;
}






