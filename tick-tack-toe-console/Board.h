#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
private:
    char grid[3][3];
    int filledCells; // Counter for filled cells

public:
    Board();

    // Method to display the board
    void drawBoard() const;

    // Method to check if a move is valid
    bool isValidMove(int row, int col) const;

    // Method to make a move
    void makeMove(int row, int col, char symbol);

    // Method to check for a win
    bool checkWin(char symbol) const;

    // Method to check if board is full using the counter
    bool isFull() const;

    // Method to get the number of filled cells
    int getFilledCellsCount() const;
};

#endif // BOARD_H