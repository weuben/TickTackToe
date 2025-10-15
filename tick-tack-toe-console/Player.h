#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// Player class to represent a player in game
class Player {
private:
    char symbol;
    std::string name;

public:
    // Constructor
    Player(char sym = 'X', std::string n = "Player X");

    // Getter methods (defined inline for simplicity, or in Player.cpp)
    char getSymbol() const { return symbol; }
    std::string getName() const { return name; }
};

#endif // PLAYER_H