#include <iostream>

/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

1 1 1 1 1 1 1 1 1 1
1 2 3 4 5 6 7 8 9 10
1 3 6 10 15 21 28 36 45 55
1 4 10
1 5 15
1 6 21
1 7 28
1 8 36
1 9 45
1 1055

*/

using namespace std;

#define NUMROWS 20
#define NUMCOLS 20

long long countIterative();
long long countRecursive(int rows, int cols);

int p15_main(int argc, char **argv)
{
    long long numRoutes;

    numRoutes = countIterative();

    // don't use the recursive solution for numbers greater than 15. it takes too long. especially for 20x20.
    //numRoutes = countRecursive(NUMROWS, NUMCOLS);

    cout << numRoutes << endl;

    return 0;
}

long long countIterative()
{
    // number of vertices in a 2x2 grid amounts to 3x3, hence the +1 in the dimensions
    long long grid[NUMROWS+1][NUMCOLS+1];

    // initialize edge rows/cols
    for(int ii = 0; ii < NUMCOLS+1; ii++) {
        grid[0][ii] = 1;
    }
    for(int ii = 0; ii < NUMROWS+1; ii++) {
        grid[ii][0] = 1;
    }

    // calculate rest of grid
    for(int ii = 1; ii < NUMROWS+1; ii++) {
        for(int jj = 1; jj < NUMCOLS+1; jj++) {
            grid[ii][jj] = grid[ii-1][jj] + grid[ii][jj-1];
        }
    }

    return grid[NUMROWS][NUMCOLS];
}

// the +1 in the iterative solution is implicit in here in that we DON'T index things, so counting down to 0,
// in the 20x20 example, will include numbers 1 through 20 plus 0, which is 21 numbers - the number of vertices.
long long countRecursive(int rows, int cols)
{
    if(rows == 0 || cols == 0) {
        return 1;
    }

    return countRecursive(rows-1, cols) + countRecursive(rows, cols-1);
}

