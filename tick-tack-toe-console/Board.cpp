#include "Board.h"
#include <iostream> // Needed for std::cout, std::endl

// Use standard namespace for brevity in implementation file
using namespace std;

// Constructor definition
Board::Board() : filledCells(0) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

// Method to display the board
void Board::drawBoard() const {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Method to check if a move is valid
bool Board::isValidMove(int row, int col) const {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ');
}

// Method to make a move
void Board::makeMove(int row, int col, char symbol) {
    if (isValidMove(row, col)) {
        grid[row][col] = symbol;
        filledCells++; // Increment counter when a cell is filled
    }
}

// Method to check for a win
bool Board::checkWin(char symbol) const {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        return true;
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
        return true;
    }

    return false;
}

// Method to check if board is full using the counter
bool Board::isFull() const {
    return filledCells == 9;
}

// Method to get the number of filled cells
int Board::getFilledCellsCount() const {
    return filledCells;
}