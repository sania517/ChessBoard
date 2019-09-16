#include "boardconsoleview.h"

#include <string>
#include <iostream>

#include "chessboard.h"

namespace {
/*
  " _______________________________________________ \n"
  "|     |     |     |     |     |     |     |     |\n"
8 "|     |     |     |     |     |     |     |     |\n"
  "|_____|_____|_____|_____|_____|_____|_____|_____|\n"
  "|     |     |     |     |     |     |     |     |\n"
7 "|     |     |     |     |     |     |     |     |\n"
  "|_____|_____|_____|_____|_____|_____|_____|_____|\n"
  "|     |     |     |     |     |     |     |     |\n"
6 "|     |     |     |     |     |     |     |     |\n"
  "|_____|_____|_____|_____|_____|_____|_____|_____|\n"
  "|     |     |     |     |     |     |     |     |\n"
5 "|     |     |     |     |     |     |     |     |\n"
  "|_____|_____|_____|_____|_____|_____|_____|_____|\n"
  "|     |     |     |     |     |     |     |     |\n"
4 "|     |     |     |     |     |     |     |     |\n"
  "|_____|_____|_____|_____|_____|_____|_____|_____|\n"
  "|     |     |     |     |     |     |     |     |\n"
3 "|     |     |     |     |     |     |     |     |\n"
  "|_____|_____|_____|_____|_____|_____|_____|_____|\n"
  "|     |     |     |     |     |     |     |     |\n"
2 "|     |     |     |     |     |     |     |     |\n"
  "|_____|_____|_____|_____|_____|_____|_____|_____|\n"
  "|     |     |     |     |     |     |     |     |\n"
1 "|     |     |     |     |     |     |     |     |\n"
  "|_____|_____|_____|_____|_____|_____|_____|_____|\n"

//          a     b     c     d     e     f     g     h
*/

const char top[] = "   a     b     c     d     e     f     g     h\n";
const char Empty[] = "   ";
const char TopLine[] =       " _______________________________________________ \n";
const char MiddleLine[] =    "|     |     |     |     |     |     |     |     |\n";
const char BottomLine[] = "|_____|_____|_____|_____|_____|_____|_____|_____|\n";
const char Prefix[] = "| ";
const char Suffix[] = " ";
}

BoardConsoleView::BoardConsoleView()
    :Observer()
{
    for (unsigned int i = 0; i < 8; ++i) {
        for (unsigned int j = 0; j < 8; ++j) {
            m_data[i][j] = Empty;



        }
    }

}




void BoardConsoleView::up_date()
{
    for (unsigned int i = 0; i < 8; ++i) {
        for (unsigned int j = 0; j < 8; ++j) {
            if (auto element = ob_board->get(i,j)) {
                m_data[i][j] = element->view();
            } else {
                m_data[i][j] = Empty;
            }
        }
    }

    show();
}


void BoardConsoleView::show() const
{
    //system("cls");


    std::cout << top << TopLine;
    for (int j = 7; j >= 0; --j) {
        std::cout << MiddleLine;
        for (int i = 0; i < 8; ++i) {
            std::cout << Prefix << m_data[i][j] << Suffix ;
        }
        std::cout << "|" << "   " << j+1 << "\n";
        std::cout << BottomLine;

    }



}
