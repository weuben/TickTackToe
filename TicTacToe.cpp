#include "TicTacToe.h"
#include <iostream> // Needed for std::cout, std::cin, std::endl
#include <string>   // Needed for std::string

// Use standard namespace for brevity in implementation file
using namespace std;

// Constructor definition
TicTacToe::TicTacToe() : currentPlayerIndex(0) {
    players[0] = Player('X', "Player X");
    players[1] = Player('O', "Player O");
}

// Method to get the current player
Player& TicTacToe::getCurrentPlayer() {
    return players[currentPlayerIndex];
}

// Method to switch turns
void TicTacToe::switchTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

// Method to play the game
void TicTacToe::play() {
    int row, col;
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!board.isFull()) {
        // Display the board
        board.drawBoard();

        Player& currentPlayer = getCurrentPlayer();

        // Get valid input
        while (true) {
            cout << currentPlayer.getName() << " (" << currentPlayer.getSymbol()
                 << "), enter row (1-3) and column (1-3): ";
            // Using cin directly is fine here, assuming standard input.
            if (!(cin >> row >> col)) {
                // Handle non-integer input to prevent infinite loop
                cout << "Invalid input. Please enter numbers." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            row--; col--; // Convert to 0-indexed

            if (board.isValidMove(row, col)) {
                break;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        // Make move
        board.makeMove(row, col, currentPlayer.getSymbol());

        // Check for win
        if (board.checkWin(currentPlayer.getSymbol())) {
            board.drawBoard();
            cout << currentPlayer.getName() << " wins!" << endl;
            return;
        }

        // Switch turns
        switchTurn();
    }

    // Game ended in a draw
    board.drawBoard();
    cout << "It's a draw!" << endl;
}