#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Board.h"
#include "Player.h"


class TicTacToe {
private:
    Board board;
    Player players[2];
    int currentPlayerIndex;

public:
    TicTacToe();

    Player& getCurrentPlayer();

    void switchTurn();

    void play();
};

#endif // TICTACTOE_H