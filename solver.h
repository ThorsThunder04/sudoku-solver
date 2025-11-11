#include <vector>

#ifndef SOLVER_H
#define SOLVER_H

/**
 * @brief increments the coordinates to which box of the sudoku grid we want to look at next
 *
 * @param (int*) r: current row on the grid
 * @param (int*) c: current column on the grid
 * @param (int*) n2: size of the grid, such that the grid's dimensions are `n2 * n2`
 *
 * @returns `false` if it's reached the end of the grid (no more boxes to increment to), otherwise `true`
 */
bool next_box(int* r, int* c, int n2);

/**
 * @brief given a 2D vector of integers, print out each row of the vector with the integers separated by spaces
 *
 * @param (std::vector<std::vector<int>>) grid: the given 2D vector of integers
 */
void display_grid(std::vector<std::vector<int>> grid);

#endif
