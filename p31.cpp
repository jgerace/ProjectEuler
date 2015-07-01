#include <iostream>

/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?
*/

using namespace std;

int recursive(int idx, int sum);
int iterative();

int p31_main(int argc, char **argv)
{
    //cout << iterative() << endl;
    cout << recursive(0, 0) << endl;

    return 0;
}

int values[] = {1, 2, 5, 10, 20, 50, 100, 200};
int recursive(int idx, int sum)
{
    if(idx == 8) {
        return sum == 200;
    }

    int count = 0;
    int maxCoins = (200 - sum) / values[idx];
    for(int ii = 0; ii <= maxCoins; ii++) {
        count += recursive(idx+1, sum + ii*values[idx]);
    }

    return count;
}

int iterative()
{
    int sum;
    int numWays = 0;
    for(int L2 = 0; L2 <= 1; L2++) {
        for(int L1 = 0; L1 <= 2; L1++) {
            for(int p50 = 0; p50 <= 4; p50++) {
                for(int p20 = 0; p20 <= 10; p20++) {
                    for(int p10 = 0; p10 <= 20; p10++) {
                        for(int p5 = 0; p5 <= 40; p5++) {
                            for(int p2 = 0; p2 <= 100; p2++) {
                                for(int p1 = 0; p1 <= 200; p1++) {
                                    sum = L2*200 + L1*100 + p50*50 + p20*20 + p10*10 + p5*5 + p2*2 + p1;
                                    if(sum == 200) {
                                        numWays++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return numWays;
}
