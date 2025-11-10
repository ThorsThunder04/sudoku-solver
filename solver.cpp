#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>

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


void display_grid(std::vector<std::vector<int>> grid) {

    for (int r = 0; r < (int)grid.size(); r++) {
        for (int c = 0; c < (int)grid[r].size(); c++) {
            std::cout << grid[r][c] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {

    // n is the "subgrid" dimension.
    // ex: on a 9x9 sudoku, the subgrid dimension would be 3
    int n;
    std::cout << "Enter subgrid size (= 3 on a 9x9 sudoku): ";
    std::cin >> n;
    int n2 = n*n;

    std::vector<std::vector<int>> grid;
    // set default size for vectors

    std::cout << "Enter each line of your sudoku problem." << std::endl << "Separte each number by a space and write 0 for missing numbers." << std::endl;
    std::cout << "You must input " << n2 << " numbers per line:" << std::endl;

    int in_num;

    // for each line
    for (int i = 0; i < n2; i++) {

        std::vector<int> line_vect;

        // for each column
        for (int j = 0; j < n2; j++) {
            std::cin >> in_num;
            line_vect.push_back(in_num);
        }

        grid.push_back(line_vect);
    }

    for (int i = 0; i < 2*n2-1; i++) {std::cout <<"-";}

    std::cout << std::endl;
    display_grid(grid);


    return 0;
}
