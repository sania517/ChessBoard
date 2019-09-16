#ifndef KINDOFGAME_H
#define KINDOFGAME_H


enum kind_of_game {emptyKindGame,chess, chekers};

class kindOfGame
{
private:

kind_of_game game = emptyKindGame;

public:
    kind_of_game return_kind_game();
    kindOfGame();
};

#endif // KINDOFGAME_H
