#include <iostream>
#include <vector>

/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

using namespace std;

static void printNum(vector<int> num);

int p16_main(int argc, char **argv)
{
    vector<int> num;
    num.push_back(2);

    // calculating product such that least significant digit is element 0, most significant is element num.size()-1
    int carry;
    for(int ii = 1; ii <= 999; ii++) {
        carry = 0;
        for(int jj = 0; jj < num.size(); jj++) {
            int product = num[jj] * 2 + carry;
            carry = product / 10;
            num[jj] = product % 10;
        }
        if(carry) {
            num.push_back(carry);
        }
    }

    //printNum(num);

    int sum = 0;
    for(int ii = 0; ii < num.size(); ii++) {
        sum += num[ii];
    }

    cout << "sum: " << sum << endl;

    return 0;
}

void printNum(vector<int> num)
{
    for(int ii = num.size()-1; ii >= 0; ii--) {
        cout << num[ii];
    }
    cout << endl;
}
