#ifndef READER_H
#define READER_H
#include <fstream>
#include <vector>
#include "koordinaty_xoda.h"
#include "kindofgame.h"


class Reader
{
public:
    Reader(){}
    void readGame(kind_of_game kog);
    std::vector<koordinaty_Xoda*> & getXodsInFile() { return r_xods;}
private:

std::vector<koordinaty_Xoda*>  r_xods;
};

#endif // READER_H
