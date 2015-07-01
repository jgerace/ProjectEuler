#include <iostream>
#include <vector>

/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

using namespace std;

#define MAXNUM 100

int p20_main(int argc, char **argv)
{
    vector<int> num;
    num.push_back(MAXNUM);

    int carry;
    for(int ii = MAXNUM-1; ii > 0; ii--) {
        carry = 0;
        for(int jj = 0; jj < num.size(); jj++) {
            int product = num[jj] * ii + carry;
            carry = product / 10;
            num[jj] = product % 10;
        }

        // carry can be > 100, so we have to put each digit in its own spot
        if(carry) {
            int temp;
            while(carry > 9) {
                temp = carry % 10;
                num.push_back(temp);
                carry = carry / 10;
            }
            num.push_back(carry);
        }
    }

    int sum = 0;
    for(int ii = 0; ii < num.size(); ii++) {
        sum += num[ii];
    }
    cout << sum << endl;

    return 0;
}
