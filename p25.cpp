#include <iostream>
#include <vector>

/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

using namespace std;

vector<int> add(vector<int> v1, vector<int> v2);

int p25_main(int argc, char **argv)
{
    vector<int> fm1;
    fm1.push_back(1);

    vector<int> fm2;
    fm2.push_back(1);

    vector<int> fn;

    int ii = 3;
    do{
        fn = add(fm2, fm1);
        if(fn.size() == 1000) {
            cout << ii << endl;
            break;
        }
        fm2 = fm1;
        fm1 = fn;
        ii++;
    } while(1);

    return 0;
}

vector<int> add(vector<int> v1, vector<int> v2)
{
    vector<int> num;

    int carry = 0;
    for(int ii = 0; ii < v2.size(); ii++) {
        int digit = 0;
        if(ii < v1.size()) {
            digit = v1[ii];
        }
        int sum = digit + v2[ii] + carry;
        carry = sum / 10;
        num.push_back(sum % 10);
    }

    if(carry) {
        if(v2.size() > v1.size()) {
            carry += v2[v2.size()-1];
        }
        num.push_back(carry);
    }

    return num;
}

