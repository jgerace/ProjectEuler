#include <iostream>
#include <cstdio>
#include <cstring>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

using namespace std;

static bool isPalindrome(char *num, int len);

int p4_main(int argc, char **argv)
{
    int largest = 0;
    int total;
    char ctotal[10] = "\0";
    for(int ii = 999; ii > 99; ii--) {
        for(int jj = 999; jj > 99; jj--) {
            total = ii * jj;
            snprintf(ctotal, sizeof(ctotal), "%d", total);

            if(isPalindrome(ctotal, strlen(ctotal))) {
                if(largest < total) {
                    largest = total;
                }
            }
        }
    }

    cout << largest << endl;

    return 0;
}

bool isPalindrome(char *num, int len)
{
    int startIdx = 0;
    int endIdx = len - 1;

    while(startIdx < endIdx) {
        if(num[startIdx] != num[endIdx]) {
            return false;
        }
        startIdx++;
        endIdx--;
    }

    return true;
}
