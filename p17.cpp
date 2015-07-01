#include <iostream>
#include <string>

/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

using namespace std;

int getLetterCountForNum(int num);

int p17_main(int argc, char **argv)
{
    int total = 0;
    for(int ii = 1; ii <= 1000; ii++) {
        total += getLetterCountForNum(ii);
    }

    cout << total << endl;

    return 0;
}

int getLetterCountForNum(int num)
{
    string digits[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    string outputStr = "";

    int thousands = num / 1000;
    if(thousands) {
        outputStr += "onethousand";
        num = num % 1000;
    }

    int hundreds = num / 100;
    if(hundreds) {
        outputStr += digits[hundreds-1] + "hundred";
        num = num % 100;
        if(num) {
            outputStr += "and";
        }
    }

    if(num != 0) {
        if(num < 20) {
            outputStr += digits[num-1];
        }
        else if(num > 0) {
            int tensDigit = num / 10;
            if(tensDigit) {
                outputStr += tens[tensDigit - 2];
            }
            num = num % 10;

            if(num > 0) {
                outputStr += digits[num-1];
            }
        }
    }

    return outputStr.size();
}
