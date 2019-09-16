#include "kindofgame.h"
#include <iostream>

kindOfGame::kindOfGame()
{

}

kind_of_game kindOfGame::return_kind_game(){

   // kind_of_game game;
    int game_int= -1;
    for(;;){
        std::cout << "Enter the kind of Game:\n" << "1 - Chess\n" << "2 - Chekers\n";
        std::cin >> game_int;

        while (std::cin.get() != '\n'){
            continue;
        }
        if ( game_int >= 1 && game_int <=2){
            game = kind_of_game(game_int);
            break;
        }
        std::cout << "Your entered wrong kind of game!!!\n Make your correct choice\n";
    }
    if (game == chess)
        std::cout << "Your enter chess\n";
    if (game == chekers)
        std::cout << "Your enter chekers\n";

    return game;
}
