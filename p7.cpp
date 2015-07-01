#include <iostream>
#include <vector>

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

using namespace std;

int p7_main(int argc, char **argv)
{
    vector<int> primes;
    primes.push_back(2);

    int num = 2;
    while(primes.size() != 10001) {
        bool isPrime = true;
        vector<int>::iterator iter;
        for(iter = primes.begin(); iter != primes.end(); iter++) {
            if(num % *iter == 0) {
                isPrime = false;
            }
        }

        if(isPrime) {
            primes.push_back(num);
        }

        num++;
    }

    cout << primes[10000] << endl;

    return 0;
}



