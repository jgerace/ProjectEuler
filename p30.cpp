#include <iostream>

/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

using namespace std;

#define EXP 5

static int pow(int base, int exp);

int p30_main(int argc, char **argv)
{
    int num = 10;
    int sum = 0;
    while(1) {
        int temp = num;
        int digitSum = 0;
        while(temp > 0) {
            int digit = temp % 10;
            digitSum += pow(digit, EXP);
            if(digitSum > num) {
                break;
            }
            temp /= 10;
        }
        if(digitSum == num) {
            sum += num;
        }

        if(num > 354294) {
            // 6 * 9^5 = 354294. This is the largest 6-digit number we can have. 7 * 9^5 still limits us to a
            // 6-digit sum of digits (413343) so nothing larger than 354294 can be written as the sum of its digits
            // raised to the 5th power. I did this calculation manually.
            break;
        }
        num++;
    }

    cout << sum << endl;

    return 0;
}

int pow(int base, int exp)
{
    int prod = base;
    for(int ii = 1; ii < exp; ii++) {
        prod *= base;
    }

    return prod;
}
