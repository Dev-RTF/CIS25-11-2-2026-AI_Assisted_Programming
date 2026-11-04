#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Grid.h"
#include "Player.h"

class TicTacToe {
    private:
        Grid grid;
        Player playerOne;
        Player playerTwo;
        int roundsToWin;
        int playerOneWins;
        int playerTwoWins;
        int currentPlayer;
        
    public:
        // creates a game
        TicTacToe(int roundsToWin, char playerOne, char playerTwo, Grid grid);

        // returns the symbol of the player whose turn it is
        char decideTurn();

        // returns the winning symbol, or '\0' when there is no winner
        char decideWinner();

        // plays rounds until one player reaches the target number of wins
        void play();
};

#endif