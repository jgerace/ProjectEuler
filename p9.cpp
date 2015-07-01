#include <iostream>

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

using namespace std;

int p9_main(int argc, char **argv)
{
    bool doBreak = false;
    int aa, bb, cc;
    for(aa = 3; aa < 1000; aa++) {
        for(bb = 4; bb < 1000; bb++) {
            if(aa*aa + bb*bb == (1000 - aa - bb)*(1000 - aa - bb)) {
                doBreak = true;
                break;
            }
        }
        if(doBreak) {
            break;
        }
    }

    cc = 1000 - aa - bb;
    cout << "a: " << aa << " b: " << bb << " c: " << cc << endl;
    cout << "abc = " << aa * bb * cc << endl;
    return 0;
}



