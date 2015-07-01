#include <iostream>

/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that
49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

using namespace std;

static void getDigits(int num, int& tens, int& ones);
static bool isDiv(double num1, double denom1, double num2, double denom2);

int p33_main(int argc, char **argv)
{
    int numProd = 1;
    int denomProd = 1;
    for(int denominator = 11; denominator < 100; denominator++) {
        for(int numerator = 10; numerator < denominator; numerator++) {
            int numTens, numOnes;
            int denomTens, denomOnes;
            getDigits(numerator, numTens, numOnes);
            getDigits(denominator, denomTens, denomOnes);

            if(numerator == denominator || (numOnes == 0 && numOnes == denomOnes)) {
                continue;
            }

            int num = 0, denom = 0;
            if(numTens == denomTens || numTens == denomOnes) {
                num = numOnes;
            }
            else if(numOnes != 0 && (numOnes == denomOnes || numOnes == denomTens)) {
                num = numTens;
            }

            if(denomOnes != 0 && (denomTens == numTens || denomTens == numOnes)) {
                denom = denomOnes;
            }
            else if(denomOnes == numOnes || denomOnes == numTens) {
                denom = denomTens;
            }

            if(denom == 0 || num == 0) {
                continue;
            }

            if(isDiv(numerator, denominator, num, denom)) {
                numProd *= num;
                denomProd *= denom;
            }
        }
    }

    cout << numProd << "/" << denomProd << endl; // simplify fraction by hand

    return 0;
}

void getDigits(int num, int& tens, int& ones)
{
    ones = num % 10;

    tens = 0;
    if(num >= 10) {
        tens = num / 10;
    }
}

bool isDiv(double num1, double denom1, double num2, double denom2)
{
    double frac1 = num1/denom1;
    double frac2 = num2/denom2;
    if(frac1 == frac2) {
        return true;
    }
    return false;
}
