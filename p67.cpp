#include <iostream>
#include <fstream>

/*
Triangle
By starting at the top of the triangle and moving to adjacent numbers on the row below,
the maximum total from top to bottom is 27.

        5
      9  6
    4   6  8
  0   7  1   5

I.e. 5 + 9 + 6 + 7 = 27.

Write a program in a language of your choice to find the maximum total from top to bottom in triangle.txt,
a text file containing a triangle with 100 rows. Send your solution and resume to [123456 AT yodle dot com],
replacing 123456 with the maximum sum for the triangle.
*/

using namespace std;

#define NUMROWS 100

static int tree[NUMROWS][NUMROWS] = {0};
static int maxTotal = 0;

int getSum(int numRows);
void printTree();

int p67_main(int argc, char **argv)
{
    ifstream fin(argv[1]);

    int row = 0, col = 0;
    while(fin.good()) {
        fin >> tree[row][col];
        if(col == row) {
            row++;
            col = 0;
        }
        else {
            col++;
        }
    }

    cout << "max total: " << getSum(NUMROWS) << endl;

    return 0;
}

int getSum(int numRows)
{
    for(int ii = numRows-2; ii >= 0; ii--) {
        for(int jj = 0; jj <= ii; jj++) {
            if((tree[ii][jj] + tree[ii+1][jj]) > (tree[ii][jj] + tree[ii+1][jj+1])) {
                tree[ii][jj] += tree[ii+1][jj];
            }
            else {
                tree[ii][jj] += tree[ii+1][jj+1];
            }
        }
    }

    return tree[0][0];
}

void printTree()
{
    for(int ii = 0; ii < NUMROWS; ii++) {
        for(int jj = 0; jj <= ii; jj++) {
            cout << tree[ii][jj] << " ";
        }
        cout << endl;
    }
}

