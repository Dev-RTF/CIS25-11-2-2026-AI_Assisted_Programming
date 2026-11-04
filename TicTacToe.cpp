#include "TicTacToe.h"

#include <cctype>
#include <iostream>
#include <limits>
#include <stdexcept>

TicTacToe::TicTacToe(int roundsToWin, char playerOne, char playerTwo, Grid grid)
    : grid(grid),
      playerOne(playerOne, "Player 1"),
      playerTwo(playerTwo, "Player 2"),
      roundsToWin(roundsToWin),
      playerOneWins(0),
      playerTwoWins(0),
      currentPlayer(0) {
    if (roundsToWin <= 0) {
        throw std::invalid_argument("The number of rounds to win must be positive.");
    }
    if (playerOne == playerTwo ||
        std::isspace(static_cast<unsigned char>(playerOne)) ||
        std::isspace(static_cast<unsigned char>(playerTwo)) ||
        playerOne == '\0' || playerTwo == '\0') {
        throw std::invalid_argument("Players must use two different, visible symbols.");
    }
}

char TicTacToe::decideTurn() {
    return currentPlayer == 0 ? playerOne.getSymbol() : playerTwo.getSymbol();
}

char TicTacToe::decideWinner() {
    if (grid.hasWon(playerOne.getSymbol())) {
        return playerOne.getSymbol();
    }
    if (grid.hasWon(playerTwo.getSymbol())) {
        return playerTwo.getSymbol();
    }
    return '\0';
}

void TicTacToe::play() {
    while (playerOneWins < roundsToWin && playerTwoWins < roundsToWin) {
        grid.reset();
        currentPlayer = 0;
        std::cout << "\nNew round. First to " << roundsToWin << " round wins.\n";

        while (true) {
            grid.drawGrid();
            const char symbol = decideTurn();
            const Player& player = currentPlayer == 0 ? playerOne : playerTwo;
            int row;
            int column;

            std::cout << player.getName() << " (" << symbol
                      << "), enter row and column (1-" << grid.getRows()
                      << ", 1-" << grid.getColumns() << "): ";

            if (!(std::cin >> row >> column)) {
                if (std::cin.eof()) {
                    std::cout << "\nInput ended. Exiting the game.\n";
                    return;
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter two whole numbers.\n";
                continue;
            }

            if (row < 1 || row > grid.getRows() ||
                column < 1 || column > grid.getColumns() ||
                !grid.placeMark(row - 1, column - 1, symbol)) {
                std::cout << "That position is invalid or already occupied. Try again.\n";
                continue;
            }

            const char winner = decideWinner();
            if (winner != '\0') {
                grid.drawGrid();
                if (winner == playerOne.getSymbol()) {
                    ++playerOneWins;
                    std::cout << playerOne.getName() << " wins this round!\n";
                } else {
                    ++playerTwoWins;
                    std::cout << playerTwo.getName() << " wins this round!\n";
                }
                break;
            }

            if (grid.isFull()) {
                grid.drawGrid();
                std::cout << "This round is a draw.\n";
                break;
            }

            currentPlayer = 1 - currentPlayer;
        }

        std::cout << "Score: " << playerOne.getName() << ' ' << playerOneWins
                  << " - " << playerTwoWins << ' ' << playerTwo.getName() << '\n';
    }

    const Player& champion = playerOneWins == roundsToWin ? playerOne : playerTwo;
    std::cout << champion.getName() << " wins the game!\n";
}
