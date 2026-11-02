#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Grid.h"
#include "Player.h"

class TicTacToe {
    private:
        Grid grid;
        
    public:
        // creates a game
        TicTacToe(int roundsToWin, char playerOne, char playerTwo, Grid grid);

        // decide whose turn it is
        char decideTurn();

        char decideWinner();
};

#endif