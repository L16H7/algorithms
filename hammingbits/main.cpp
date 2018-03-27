#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <algorithm>

using namespace std;

void removeSpaces(string &str)
{
    // To keep track of non-space character count
    int count = 0;
 
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}

int hammingDistance(string str1, string str2)
{
    int count = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            count++;
        }
    }
    return count;
}

void generateOneDistanceBits(string bit) {
    vector<string> neighbors;
    for (int i = 0; i < bit.length(); i++) {
        string copy = bit;
        copy[i] = bit[i] == '1' ? '0' : '1';
        neighbors.push_back(copy);
    }

    for (string s : neighbors) {
        cout << s << endl;
    }
}

int main () {
    int N;
    cin >> N;
    int L;
    cin >> L;

    string str;
    unordered_set<string> bits;

    std::getline(std::cin, str);
    while (N--) {
        std::getline(std::cin, str);
        // cout << bit << endl;
        // str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
        removeSpaces(str);
        bits.insert(str);
    }

    cout << bits.size() << endl;

    generateOneDistanceBits("100110");

    for (const auto& bit : bits) {
        for (int i = 0; i < bit.length(); i++) {
            string copy = bit;
            copy[i] = bit[i] == '1' ? '0' : '1';
            std::unordered_set<std::string>::const_iterator found = bits.find(copy);

            if (found != bits.end()) {
                cout << "FOUND: " << endl;
            }
        } 
    }
    /*
    for (int i = 0; i < bits.size(); i++) {
        for (int j = i + 1; j < bits.size(); j++) {

            if (hammingDistance(bits[i], bits[j]) > 2) {
              continue;
            } else {
              cout << (i + 1) << " " << (j + 1) << " " << hammingDistance(bits[i], bits[j]) << endl;
            }

        }
    }
    */

    return 0;
}