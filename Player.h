#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    private:
        char symbol;
        std::string name;
    public:
        // the player picks their symbol (X or O)
        Player(char symbol, std::string name);
        // getters
        char getSymbol() const;
        std::string getName() const;        
};

#endif