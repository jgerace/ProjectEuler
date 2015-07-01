#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

using namespace std;

static bool isLRTruncatable(int num);
static bool isPrime(int num);

int p37_main(int argc, char **argv)
{
    int count = 0;
    int sum = 0;
    char cnum[8];
    for(int ii = 11; ii > 0; ii++) {
        if(count == 11) {
            break;
        }
        else if(!isPrime(ii)) {
            continue;
        }

        snprintf(cnum, sizeof(cnum), "%d", ii);
        if(isLRTruncatable(ii)) {
            cout << ii << endl;
            sum += ii;
            count++;
        }
    }

    cout << sum << endl;

    return 0;
}

bool isLRTruncatable(int num)
{
    int temp = num;

    // right to left
    while(num > 0) {
        if(!isPrime(num)) {
            return false;
        }
        num /= 10;
    }

    num = temp;
    // left to right
    int tens = 1;
    while(tens < num) tens *= 10;
    tens /= 10;

    while(1) {
        num %= tens;

        if(!isPrime(num)) {
            return false;
        }
        tens /= 10;
        if(tens == 1) {
            break;
        }
    }

    return true;
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
