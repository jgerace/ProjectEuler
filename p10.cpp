#include <iostream>
#include <vector>

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

using namespace std;

int p10_main(int argc, char **argv)
{
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);

    long long sum = 5;
    for(int ii = 5; ii < 2000000; ii+=2) {
        bool isPrime = true;
        vector<int>::iterator iter;
        for(iter = primes.begin(); iter != primes.end(); iter++) {
            if(ii % *iter == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            sum += ii;
            primes.push_back(ii);
        }
    }

    cout << sum << endl;

    return 0;
}

