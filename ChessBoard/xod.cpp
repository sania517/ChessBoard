#include "xod.h"
#include <iostream>
#include <cctype>
#include "controller.h"

Xod::Xod(Controller &contr)
    :m_contr(contr)
{}

void Xod::readXod()
{

    do{

    char in ='o', out;
    int in_i = -1;
    int in_y = -1;
    int out_i = -1;
    int out_y = -1;
    std::cout << "Enter koordinati figuri otkyda kuda v formate a0 a0 or Q for quit\n__ __\b\b\b\b\b";
    std::cin.get(in);
    if (toupper(in) == 'Q'){
        return;
    }
    std::cin >> in_i;
    std::cin.get();
    std::cin.get(out) >> out_i;
    while(std::cin.get() != '\n')
        continue;
    if ((in <= 'h') && (in >='a') && (out <= 'h') && (out >='a') && (in_i <=8) && (in_i >=1) && (out_i <=8) && (out_i >=1))
    {
        in_y = in - 'a';
        out_y = out - 'a';
        in_i--;
        out_i--;

        if ((in_i == out_i) &&(in_y == out_y)){
           std::cout << "Void XOD !!!" ;
           continue;
        }

        koordinaty_Xoda * k_xod = new koordinaty_Xoda {in_y, in_i, out_y, out_i};

        m_contr.addXod(k_xod);

    }



    }while(true);



}
