#include <iostream>

/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

using namespace std;

int p28_main(int argc, char **argv)
{
    int sideLen = 1;
    int sum = 1;
    int counter = 1;
    for(int ii = 3; ii <= 1001; ii+=2) {
        sideLen = ii;
        for(int jj = 0; jj < 4; jj++) { // 4 sides to the square
            counter += sideLen-1;
            sum += counter;
        }
    }

    cout << sum << endl;

    return 0;
}

