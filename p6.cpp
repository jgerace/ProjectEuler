#include <iostream>

/*
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

using namespace std;

long long sumOfSquares(int num);
long long squareOfSums(int num);

#define NUM 100

int p6_main(int argc, char **argv)
{
    cout << squareOfSums(NUM) - sumOfSquares(NUM) << endl;

    return 0;
}

long long sumOfSquares(int num)
{
    long long sum = 0;
    for(int ii = 1; ii <= num; ii++) {
        sum += ii*ii;
    }

    return sum;
}

long long squareOfSums(int num)
{
    long long sum = 0;
    for(int ii = 1; ii <= num; ii++) {
        sum += ii;
    }

    return sum*sum;
}



