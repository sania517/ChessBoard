#include "needtoread.h"
#include <iostream>

NeedToRead::NeedToRead()
{

}

need_to_read NeedToRead::get_need_to_read(){
    int vibor = -1;
    for(;;){
    std::cout << "Enter choice:\n 1 - new Game Chess\n" <<"2 = return last Game Chess\n";
    std::cin >> vibor;

    while (std::cin.get() != '\n'){
        continue;
    }
        if (vibor == 1){
            std::cout << "Your choice new Game\n";
            break;
        }
        if (vibor == 2){
            std::cout << "Your choice last Game\n";
            break;
        }
    std::cout << "Your entered wrong read mode!!!\n Make your correct choice\n";


    }
    return need_to_read(vibor);
}





