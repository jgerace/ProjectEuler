#include <iostream>
#include <set>

/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2 = 0.5
1/3 = 0.(3)
1/4 = 0.25
1/5 = 0.2
1/6 = 0.1(6)
1/7 = 0.(142857)
1/8 = 0.125
1/9 = 0.(1)
1/10 = 0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

using namespace std;

int getDecimalCycleLen(int num);

int p26_main(int argc, char **argv)
{
    int maxLen = 0;
    int maxNum = 0;
    for(int ii = 3; ii < 1000; ii++) {
        int cycleLen = getDecimalCycleLen(ii);
        if(cycleLen > maxLen) {
            maxLen = cycleLen;
            maxNum = ii;
        }
    }

    cout << maxNum << endl;

    return 0;
}

int getDecimalCycleLen(int num)
{
    set<int> foundRemainders;
    int remainder = 1 % num;
    do {
        foundRemainders.insert(remainder);
        remainder *= 10;
        remainder %= num;
    } while(foundRemainders.find(remainder) == foundRemainders.end());

    return foundRemainders.size();
}
