#include <iostream>

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

using namespace std;

int p3_main(int argc, char **argv)
{
    long long num = 600851475143;
    long long largestPrimeFactor = 0;
    for(long long ii = 2; ii <= num; ii++) {
        while(num % ii == 0) {
            num /= ii;
            largestPrimeFactor = ii;
        }
    }

    cout << largestPrimeFactor << endl;

    return 0;
}
