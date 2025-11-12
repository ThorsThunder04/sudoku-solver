#include <vector>
#include <unordered_map>

#ifndef SOLVER_H
#define SOLVER_H

/**
 * @brief increments the coordinates to which box of the sudoku grid we want to look at next
 *
 * @param (std::pair<int, int>*) pos: current position in the grid
 * @param (int*) n2: size of the grid, such that the grid's dimensions are `n2 * n2`
 *
 * @returns `true` if it's reached the end of the grid (no more boxes to increment to), otherwise `false`
 */
bool next_box(std::pair<int, int> *pos, int n2);

/**
 * @brief given a row, a number to place in it and a grid, check if placing the number in that row breaks the validity of the sudoku grid
 *
 * @param (int) sol: the number we want to place
 * @param (int) r: the row on the grid
 * @param (std::vector<std::vector<int>>) grid: the grid with all the numbers of the sudoku
 *
 * @returns true if we can place the given number on this row, false otherwise
 */
bool check_row(int sol, int r, std::vector<std::vector<int>> grid);

/**
 * @brief given a column, a number to place int it and a grid, check if placing the number in that column breaks the validity of the sudoku grid
 *
 * @param (int) sol: the number we want to place
 * @param (int) c: the column on the grid
 * @param (std::vector<std::vector<int>>) grid: the grid with all the numbers of the sudoku
 *
 * @returns true if we can plcae the given number on this column, false otherwise
 */
bool check_col(int sol, int c, std::vector<std::vector<int>> grid);

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
bool check_subgrid(int sol, std::pair<int, int> *pos,int sgn, std::vector<std::vector<int>> grid);

/**
 * @brief recursively searches for the solution to the given sudoku grid
 *
 * @param (std::vector<std::vector<int>>) grid: the sudoku grid to solve
 * @param (int) n: the size of the sudoku's sub-grids
 * @param (std::pair<int, int>) pos: the starting position for the search
 *
 * @returns true if the grid is solvable, false otherwise
 */
bool solve_sudoku(std::vector<std::vector<int>> &grid, int n, std::pair<int, int> pos);

#endif
