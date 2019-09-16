#include "save.h"
#include "chessboard.h"
#include <fstream>
#include <iostream>
#include "koordinaty_xoda.h"


void Save::clearFile()
{
    std::ofstream outFile;

    if (m_kind_of_game == chess){
        outFile.open("chessOut.out");
    }

    if (m_kind_of_game == chekers){
        outFile.open("chekersOut.out");
    }

    if (!outFile)
        {
       std::cout << "Error  could not open file for write"  ;
         return;
        }
    outFile.close();
}

void Save::up_date()
{
    std::ofstream outFile;

    if (m_kind_of_game == chess){
        outFile.open("chessOut.out", std::ios::app);
    }

    if (m_kind_of_game == chekers){
        outFile.open("chekersOut.out", std::ios::app);
    }

    if (!outFile){
        std::cout << "Error  could not open file: for write"  ;
        return;
    }
    koordinaty_Xoda * kx = ob_board->returnLastXod();
    outFile << kx->m_in_y<< kx->m_in_i << " "  << kx->m_out_y<< kx->m_out_i<< std::endl;
    outFile.close();

}


