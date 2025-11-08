#include <iostream>
#include <string>
#include <array>



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


int main() {

    return 0;
}
