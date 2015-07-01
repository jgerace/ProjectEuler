#include <iostream>

/*
Euler discovered the remarkable quadratic formula:

n^2 + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.

The incredible formula n^2 − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n^2     + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

using namespace std;

static int getNumPrimes(int a, int b);
static bool isPrime(int num);

int p27_main(int argc, char **argv)
{
    int maxPrimes = 0;
    int maxA, maxB;
    int a, b;
    for(a = -999; a < 1000; a++) {
        for(b = -999; b < 1000; b++) {
            int primes = getNumPrimes(a, b);
            if(primes > maxPrimes) {
                maxPrimes = primes;
                maxA = a;
                maxB = b;
            }
        }
    }

    cout << maxA * maxB << endl;

    return 0;
}

int getNumPrimes(int a, int b)
{
    int count = 0;
    int n = 0;

    while(1) {
        int total = n*n + (a*n) + b;
        if(isPrime(total)) {
            count++;
        }
        else {
            break;
        }
        n++;
    }

    return count;
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
