#include "Grid.h"

#include <iostream>
#include <stdexcept>

Grid::Grid(int rows, int columns)
    : rows(rows), columns(columns) {
    if (rows <= 0 || columns <= 0) {
        throw std::invalid_argument("Grid dimensions must be positive.");
    }
    cells.assign(rows, std::vector<char>(columns, ' '));
}

void Grid::drawGrid() {
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            std::cout << ' ' << cells[row][column] << ' ';
            if (column < columns - 1) {
                std::cout << '|';
            }
        }
        std::cout << '\n';

        if (row < rows - 1) {
            for (int column = 0; column < columns; ++column) {
                std::cout << "---";
                if (column < columns - 1) {
                    std::cout << '+';
                }
            }
            std::cout << '\n';
        }
    }
}

bool Grid::placeMark(int row, int column, char symbol) {
    if (row < 0 || row >= rows || column < 0 || column >= columns ||
        symbol == ' ' || symbol == '\0' || cells[row][column] != ' ') {
        return false;
    }
    cells[row][column] = symbol;
    return true;
}

bool Grid::hasWon(char symbol) const {
    if (symbol == ' ' || symbol == '\0') {
        return false;
    }

    for (int row = 0; row < rows; ++row) {
        bool completeRow = true;
        for (int column = 0; column < columns; ++column) {
            if (cells[row][column] != symbol) {
                completeRow = false;
                break;
            }
        }
        if (completeRow) {
            return true;
        }
    }

    for (int column = 0; column < columns; ++column) {
        bool completeColumn = true;
        for (int row = 0; row < rows; ++row) {
            if (cells[row][column] != symbol) {
                completeColumn = false;
                break;
            }
        }
        if (completeColumn) {
            return true;
        }
    }

    if (rows == columns) {
        bool mainDiagonal = true;
        bool reverseDiagonal = true;
        for (int index = 0; index < rows; ++index) {
            if (cells[index][index] != symbol) {
                mainDiagonal = false;
            }
            if (cells[index][columns - index - 1] != symbol) {
                reverseDiagonal = false;
            }
        }
        return mainDiagonal || reverseDiagonal;
    }

    return false;
}

bool Grid::isFull() const {
    for (const auto& row : cells) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

void Grid::reset() {
    for (auto& row : cells) {
        for (char& cell : row) {
            cell = ' ';
        }
    }
}

int Grid::getRows() const {
    return rows;
}

int Grid::getColumns() const {
    return columns;
}
