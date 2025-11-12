#include <vector>
#include <unordered_set>
#include <iostream>
#include "solver.h"

/**
 * @brief increments the coordinates to which box of the sudoku grid we want to look at next
 *
 * @param (std::pair<int, int>*) pos: current position in the grid
 * @param (int*) n2: size of the grid, such that the grid's dimensions are `n2 * n2`
 *
 * @returns `true` if it's reached the end of the grid (no more boxes to increment to), otherwise `false`
 */
bool next_box(std::pair<int, int> *pos, int n2) {

    if (pos->first >= n2-1) {
        if (pos->first <= pos->second) {
            return true; // we've reached the bottom right corner of the grid
        } else {
            pos->first = 0;
            pos->second++;
        }
    } else {
        pos->first++;
    }
    return false;
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
 * @param (std::pair<int, int>*) pos: the current position in the grid
 * @param (int) sgn: sub-grid size
 * @param (std::vector<std::vector<int>>) grid: the grid with all the numbers of the sudoku
 *
 * @returns true if placing a number at grid[r][c] is valid, false otherwise
 */
bool check_subgrid(int sol, std::pair<int, int> *pos,int sgn, std::vector<std::vector<int>> grid) {

    std::unordered_set<int> seen;

    // find the starting row and column of the current sub-grid
    int r = pos->first - (pos->first % sgn);
    int c = pos->second - (pos->second %sgn);

    for (int ro = r; ro < r + sgn; ro++) {
        for (int co = c; co < c + sgn; co++) {
            int num = grid[ro][co];
            if (num != 0)
                seen.insert(num);
        }
    }


    // check if number isn't already in the sub-grid
    return (seen.count(sol) == 0);
}

/**
 * @brief recursively searches for the solution to the given sudoku grid
 *
 * @param (std::vector<std::vector<int>>) grid: the sudoku grid to solve
 * @param (int) n: the size of the sudoku's sub-grids
 * @param (std::pair<int, int>) pos: the starting position for the search
 *
 * @returns true if the grid is solvable, false otherwise
 */
bool solve_sudoku(std::vector<std::vector<int>> &grid, int n, std::pair<int, int> pos) {

    // move coordinates until next empty box is found
    bool done = false;
    while (grid[pos.first][pos.second] != 0 && !done) {
        done = next_box(&pos, n*n);
    }

    // if we manage to find no more empty boxes, then the sudoku should be solved now
    if (done) {
        return true;
    }

    int k;
    for (k = 1; k <= n*n; k++) {

        // check if k can be placed at the current position
        if (check_row(k, pos.first, grid) && check_col(k, pos.second, grid) && check_subgrid(k, &pos, n, grid)) {

            grid[pos.first][pos.second] = k;

            std::pair<int, int> new_pos = pos;
            next_box(&new_pos, n*n);

            if (solve_sudoku(grid, n, new_pos)) {
                return true;
            }
        }
    }

    grid[pos.first][pos.second] = 0;
    return false;
}
