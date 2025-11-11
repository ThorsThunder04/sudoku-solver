#include <iostream>
#include <vector>
#include <unordered_set>
#include "solver.h"

/**
 * @brief increments the coordinates to which box of the sudoku grid we want to look at next
 *
 * @param (int*) r: current row on the grid
 * @param (int*) c: current column on the grid
 * @param (int*) n2: size of the grid, such that the grid's dimensions are `n2 * n2`
 *
 * @returns `false` if it's reached the end of the grid (no more boxes to increment to), otherwise `true`
 */
bool next_box(int* r, int* c, int n2) {

    if (*r == n2-1) {
        if (*r == *c) {
            return false; // we've reached the bottom right corner of the grid
        } else {
            *r = 0;
            (*c)++;
        }
    }
    return true;
}

/**
    * @brief given a coordinate, a number to place there and a grid, check if placing the number in that row breaks the validity of the sudoku grid
    *
    * @param (int) sol: the number we want to place
    * @param (int) r: the row on the grid
    * @param (std::vector<std::vector<int>>) grid: the grid with all the numbers of the sudoku
    *
    * @returns true if we can place the given number on this row, false otherwise
    */
bool check_row(int sol, int r, std::vector<std::vector<int>> grid) {

    std::unordered_set<int> seen;

    for (int c = 0; c < (int)grid.size(); c++) {
        int n = grid[r][c];
        if (n != 0)
            seen.insert(n);
    }

    // check if number isn't already present in the row
    return (seen.count(sol) == 0);

}

/**
 * @brief given a column, a number to place int it and a grid, check if placing the number in that column breaks the validity of the sudoku grid
 *
 * @param (int) sol: the number we want to place
 * @param (int) c: the column on the grid
 * @param (std::vector<std::vector<int>>) grid: the grid with all the numbers of the sudoku
 *
 * @returns true if we can plcae the given number on this column, false otherwise
 */
bool check_col(int sol, int c, std::vector<std::vector<int>> grid) {

    std::unordered_set<int> seen;

    for (int r = 0; r < (int)grid[0].size(); r++) {
        int n = grid[r][c];
        if (n != 0)
            seen.insert(n);
    }

    // check if number isn't already in the column
    return (seen.count(sol) == 0);
}

/**
 * @brief given a coordinate, a number to place there and a grid, check if placing the number in that sub-grid breaks the validity of the sudoku grid
 *
 * @param (int) sol: the number we want to place
 * @param (int) r: the row on the grid
 * @param (int) c: the column on the grid
 * @param <int> sgn: sub-grid size
 * @param (std::vector<std::vector<int>>) grid: the grid with all the numbers of the sudoku
 *
 * @returns true if placing a number at grid[r][c] is valid, false otherwise
 */
bool check_subgrid(int sol, int r, int c, int sgn, std::vector<std::vector<int>> grid) {

    std::unordered_set<int> seen;

    // find the starting row and column of the current sub-grid
    int sr = r / sgn;
    int sc = c / sgn;

    for (int ro = sr; ro < sr + sgn; ro++) {
        for (int co = sc; co < sr + sgn; co++) {
            int n = grid[ro][co];
            if (n != 0)
                seen.insert(n);
        }
    }

    // check if number isn't already in the sub-grid
    return (seen.count(sol) == 0);
}
