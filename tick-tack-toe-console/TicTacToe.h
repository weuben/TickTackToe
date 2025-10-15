#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Board.h"
#include "Player.h"

// Game class to manage the game logic
class TicTacToe {
private:
    Board board;
    Player players[2];
    int currentPlayerIndex;

public:
    // Constructor
    TicTacToe();

    // Method to get the current player
    Player& getCurrentPlayer();

    // Method to switch turns
    void switchTurn();

    // Method to play the game
    void play();
};

#endif // TICTACTOE_H