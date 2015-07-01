#include <iostream>
#include <vector>
#include <set>

/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

using namespace std;

void doPermute(vector<char> str, string permuteStr);

set<string> permutations; // will sort lexicographically for us

int p24_main(int argc, char **argv)
{
    vector<char> nums;
    for(char ii = '0'; ii <= '9'; ii++) {
        nums.push_back(ii);
    }

    doPermute(nums, "");

    int ii = 1;
    for(set<string>::iterator iter = permutations.begin(); iter != permutations.end(); iter++) {
        if(ii == 1000000) {
            cout << *iter << endl;
        }
        ii++;
    }

    return 0;
}

// could use library function std::next_permutation() instead, but that would take the difficulty out of the problem
void doPermute(vector<char> str, string permuteStr)
{
    if(str.size() == 0) {
        permutations.insert(permuteStr);
        return;
    }

    for(int ii = 0; ii < str.size(); ii++) {
        char temp = str[ii];
        str.erase(str.begin()+ii);
        doPermute(str, permuteStr + temp);
        str.insert(str.begin()+ii, temp);
    }
}
