#include <iostream>
#include <vector>

/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

using namespace std;

static bool isAbundant(int num);

int p23_main(int argc, char **argv)
{
    vector<int> abundantNums;
    for(int ii = 12; ii < 28123; ii++) {
        if(isAbundant(ii)) {
            abundantNums.push_back(ii);
        }
    }

    bool nums[56246]; // 56246 = 28123 + 28123 -> largest num that might not be sum of two abundant nums
    for(int ii = 0; ii < abundantNums.size(); ii++) {
        for(int jj = 0; jj < abundantNums.size(); jj++) {
            nums[abundantNums[ii] + abundantNums[jj]] = true;
        }
    }

    int sum = 0;
    for(int ii = 0; ii < 28124; ii++) { // only have to search up to 28123 since all larger nums can be written as sum of two abundant nums
        if(!nums[ii]) {
            sum += ii;
        }
    }

    cout << sum << endl;

    return 0;
}

bool isAbundant(int num)
{
    int sum = 0;
    for(int ii = 1; ii < num/2+1; ii++) {
        if(num % ii == 0) {
            sum += ii;
        }
    }

    if(sum > num) {
        return true;
    }

    return false;
}
