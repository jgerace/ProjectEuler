#include <iostream>
#include <set>

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

using namespace std;

#define MAXNUM 10000

static int getDivisorSum(int num);

int p21_main(int argc, char **argv)
{
    set<int> amicableNums;
    for(int a = 2; a < MAXNUM; a++) {
        int b = getDivisorSum(a);
        int divSumB = getDivisorSum(b);
        if(a != b && a == divSumB) {
            amicableNums.insert(a);
            amicableNums.insert(b);
        }
    }

    int sum = 0;
    for(set<int>::iterator iter = amicableNums.begin(); iter != amicableNums.end(); iter++) {
        sum += *iter;
    }
    cout << "sum: " << sum << endl;

    return 0;
}

int getDivisorSum(int num)
{
    int sum = 0;
    for(int ii = 1; ii < num/2+1; ii++) {
        if(num % ii == 0) {
            sum += ii;
        }
    }
    return sum;
}
