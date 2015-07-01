#include <iostream>

/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

using namespace std;

int getCollatzLen(int num);

int p14_main(int argc, char **argv)
{
    int maxLen = 0;
    int startNum = 0;
    for(int ii = 1; ii < 1000000; ii++) {
        int len = getCollatzLen(ii);
        if(len > maxLen) {
            maxLen = len;
            startNum = ii;
        }
    }

    cout << "num: " << startNum << " length: " << maxLen << endl;

    return 0;
}

int getCollatzLen(int num)
{
    int len = 1;
    unsigned long long term = num;

    while(term != 1) {
        if(term % 2 == 0) {
            term = term/2;
        }
        else {
            term = 3 * term + 1;
        }
        len++;
    }

    return len;
}
