#include <iostream>
#include <cstdio>
#include <cstring>

/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

using namespace std;

static int getFactorialSum(int num);
static int factorial(int num);

// factorials for 0 through 9: wouldn't want to calculate for each number over and over and over...
int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

// this program finds "factorions"
int p34_main(int argc, char **argv)
{
    int sum = 0;
    // upper limit b/c 9!*7 = 2540160 -> any number larger than 9,999,999 would require an 8-digit sum,
    // which isn't possible. In reality, the largest factorion we will find is < 50,000
    for(int ii = 3; ii <= 2540160; ii++) {
        if(getFactorialSum(ii) == ii) {
            sum += ii;
            //cout << "found: " << ii << endl;
        }
    }

    cout << sum << endl;
    return 0;
}

int getFactorialSum(int num)
{
    char cnum[8];
    snprintf(cnum, sizeof(cnum), "%d", num);

    int sum = 0;
    for(int ii = 0; ii < strlen(cnum); ii++) {
        sum += factorials[cnum[ii]-'0'];
    }
    return sum;
}
