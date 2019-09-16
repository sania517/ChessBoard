#include "reader.h"
#include <fstream>
#include <iostream>
#include "koordinaty_xoda.h"



void Reader::readGame(kind_of_game kog)
{
  std::fstream in;

  if (kog == chess){
    in.open("chessOut.out");
  }
  if (kog ==chekers){
     in.open("chekersOut.out");
  }
    if(!in){
        std::cout << "Can not open file: "<< "chessOut.out" << " for read\n" ;
        return;
    }

    koordinaty_Xoda * kx;
    char ch_in_y ;
    char ch_in_i ;
    char ch_out_y;
    char ch_out_i;

    while ((ch_in_y = in.get()) !=  EOF) {


     ch_in_i = in.get();
     in.get();
     ch_out_y = in.get();
     ch_out_i = in.get();
     //std::cout << ch_in_y << " " << ch_in_i << " " << ch_out_y << " " << ch_out_i << std::endl;
     while (in.get() != '\n' ){
         continue;
     }
 kx = new koordinaty_Xoda{int(ch_in_y-'0'), int(ch_in_i-'0'), int(ch_out_y-'0'), int(ch_out_i-'0')};
// r_xods.emplace_back(int(ch_in_y-'0'), int(ch_in_i-'0'), int(ch_out_y-'0'), int(ch_out_i-'0'));

 r_xods.push_back(kx);
    }

    in.close();
     //std::cout <<"r_xods.size(): " << r_xods.size();
}


