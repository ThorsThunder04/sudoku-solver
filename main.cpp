#include <iostream>
#include <vector>
#include "solver.h"
#include "main.h"


/**
 * @brief given a 2D vector of integers, print out each row of the vector with the integers separated by spaces
 *
 * @param (std::vector<std::vector<int>>) grid: the given 2D vector of integers
 */
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

            // lazy method of me dealing with people entering invalid numbers for their sudoku (will maybe change later on)
            if (in_num > n2) {
                in_num = 0;
            }

            line_vect.push_back(in_num);
        }

        grid.push_back(line_vect);
    }

    for (int i = 0; i < 2*n2-1; i++) {std::cout <<"-";}

    std::cout << std::endl;
    display_grid(grid);

    // initializing search paramaters
    int r = 0;
    int c = 0;

    return 0;
}
