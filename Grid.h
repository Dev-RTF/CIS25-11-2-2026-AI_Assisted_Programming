#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
    private:
        int rows;
        int columns;
        std::vector<std::vector<char>> cells;
    public:
        // set rows and columns
        Grid(int rows, int columns);

        // draws the board
        void drawGrid();

        // places a mark using zero-based row and column indexes
        bool placeMark(int row, int column, char symbol);

        // checks the board state
        bool hasWon(char symbol) const;
        bool isFull() const;
        void reset();

        // getters
        int getRows() const;
        int getColumns() const;

};

#endif