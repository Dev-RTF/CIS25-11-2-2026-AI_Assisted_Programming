#ifndef GRID_H
#define GRID_H

class Grid {
    private:
        int rows;
        int columns;
    public:
        // set rows and columns
        Grid(int rows, int columns);

        // draws the board
        void drawGrid();

        // getters
        int getRows() const;
        int getColumns() const;

};

#endif