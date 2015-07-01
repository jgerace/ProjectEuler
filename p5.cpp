#include <iostream>

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

using namespace std;

bool isDivisible(int num);

int p5_main(int argc, char **argv)
{
    int num = 20;
    while(!isDivisible(num)) {
        num += 20; // must be a multiple of 20
    }

    cout << num << endl;

    return 0;
}

// is num evenly divisible by all numbers from 1 - 20
bool isDivisible(int num)
{
    for(int ii = 2; ii <= 20; ii++) {
        if(num % ii != 0) {
            return false;
        }
    }
    return true;
}

