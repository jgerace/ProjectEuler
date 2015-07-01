#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

/*
The decimal number, 585 = 1001001001 (base 2, binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

using namespace std;

static string intToReverseBinary(int num);
static bool isPalindrome(const char *num, int len);

int p36_main(int argc, char **argv)
{
    int sum = 0;
    for(int ii = 1; ii < 1000000; ii++) {
        char cnum[8];
        snprintf(cnum, sizeof(cnum), "%d", ii);
        if(!isPalindrome(cnum, strlen(cnum))) {
            continue;
        }
        string revBin = intToReverseBinary(ii);
        if(isPalindrome(revBin.c_str(), revBin.length())) {
            sum += ii;
        }
    }

    cout << sum << endl;

    return 0;
}

bool isPalindrome(const char *num, int len)
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

string intToReverseBinary(int num)
{
    char binary[25];

    int ii = 0;
    while(num != 0) {
        binary[ii] = (num % 2) + '0';
        num /= 2;
        ii++;
    }
    binary[ii] = '\0';

    return binary;
}
