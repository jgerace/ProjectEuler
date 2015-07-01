#include <iostream>
#include <fstream>
#include <string>
#include <set>

/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

using namespace std;

static int getNameScore(string name);

int p22_main(int argc, char **argv)
{
    ifstream fin(argv[1]);

    set<string> names;

    while(fin.good()) {
        string name;
        getline(fin, name, ',');
        name = name.substr(1, name.length()-2); // ditch the quotes
        names.insert(name);
    }

    int ii = 1;
    long long totalScore = 0;
    for(set<string>::iterator iter = names.begin(); iter != names.end(); iter++) {
        totalScore += getNameScore(*iter) * ii;
        ii++;
    }

    cout << totalScore << endl;

    return 0;
}

int getNameScore(string name)
{
    int score = 0;
    for(int ii = 0; ii < name.length(); ii++) {
        score += name[ii] - '@'; // '@' comes before 'A' in ASCII
    }

    return score;
}
