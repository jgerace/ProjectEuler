#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <set>

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

using namespace std;

static bool isPandigital(int multiplicand, int multiplier, int product);
static int getNumDigits(int num);
static int pow(int base, int exp);

int p32_main(int argc, char **argv)
{
    int sum = 0;
    set<int> prods;
    for(int ii = 1; ii <= 9876; ii++) {
        int numDigits = 5 - getNumDigits(ii);
        int start = pow(10, numDigits-1);
        int end = pow(10, numDigits) - 1;
        for(int jj = start; jj < end; jj++) {
            int prod = ii * jj;
            if(isPandigital(ii, jj, prod) && (prods.find(prod) == prods.end())) {
                sum += prod;
                prods.insert(prod);
            }
        }
    }

    cout << sum << endl;

    return 0;
}

bool isPandigital(int multiplicand, int multiplier, int product)
{
    bool digits[9] = {0};

    ostringstream oss;
    oss << multiplicand << multiplier << product;

    string nums = oss.str();

    for(int ii = 0; ii < nums.size() ; ii++) {
        int digit = nums[ii] - '0';
        if(digit == 0) {
            return false;
        }

        if(digits[digit - 1]) {
            return false;
        }
        else {
            digits[nums[ii] - '0' - 1] = true;
        }
    }

    for(int ii = 0; ii < 9; ii++) {
        if(digits[ii] == false) {
            return false;
        }
    }

    return true;
}

int getNumDigits(int num)
{
    int numDigits = 0;
    do {
        num /= 10;
        numDigits++;
    } while(num > 0);
    return numDigits;
}

int pow(int base, int exp)
{
    if(exp == 0) {
        return 1;
    }

    int prod = base;
    for(int ii = 0; ii < exp-1; ii++) {
        prod *= base;
    }

    return prod;
}
