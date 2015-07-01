#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

using namespace std;

static bool isCircularPrime(int num);
static bool isPrime(int num);
static void getPrimes(int limit, set<int>& primes);

set<int> primes;

int p35_main(int argc, char **argv)
{
    getPrimes(1000000, primes);

    set<int> circularPrimes;
    set<int>::iterator iter;
    for(iter = primes.begin(); iter != primes.end(); iter++) {
        if(isCircularPrime(*iter)) {
            circularPrimes.insert(*iter);
        }
    }

    cout << circularPrimes.size() << endl;

    return 0;
}

bool isCircularPrime(int num)
{
    char cnum[7];
    snprintf(cnum, sizeof(cnum), "%d", num);
    int cnumLen = strlen(cnum);

    if(num > 10) {
        for(int ii = 0; ii < cnumLen; ii++) {
            switch(cnum[ii] - '0')
            {
            case 2:
            case 4:
            case 5:
            case 6:
            case 8:
                return false;
            }
        }
    }

    int ii = 0;
    while(1) {
        if(!isPrime(num)) {
            return false;
        }

        if(ii == strlen(cnum)-1) {
            break;
        }

        // rotate
        char temp = cnum[0];
        for(int jj = 1; jj < cnumLen; jj++) {
            cnum[jj-1] = cnum[jj];
        }
        cnum[cnumLen-1] = temp;
        num = atoi(cnum);

        ii++;
    }

    return true;
}

void getPrimes(int limit, set<int>& primes)
{
    primes.insert(2);
    primes.insert(3);
    set<int>::iterator iter;
    for(int ii = 5; ii < limit; ii++) {
        if(isPrime(ii)) {
            primes.insert(ii);
        }
    }
}

bool isPrime(int n) {
	if(n == 1) { // 1 is not prime
        return false;
	}
	else if(n < 4) { // 2 and 3 are prime
        return true;
	}
	else if(n % 2 == 0) { // even numbers are not prime aside from 2
        return false;
	}
	else if(n < 9) { // 5 and 7 are prime
        return true;
	}
	else if(n % 3 == 0) { // multiples of 3 are not prime aside from 3
        return false;
	}
	else { // a prime can be expressed in the form of either 6k+1 or 6k-1
        for(int ii = 5; ii * ii <= n; ii += 6) {
            if(n % ii == 0 || n % (ii+2) == 0) {
                return false;
            }
        }
	}

	return true;
}

