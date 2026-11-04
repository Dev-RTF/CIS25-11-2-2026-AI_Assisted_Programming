#include "TicTacToe.h"

int main() {
    TicTacToe game(2, 'X', 'O', Grid(3, 3));
    game.play();
    return 0;
}
