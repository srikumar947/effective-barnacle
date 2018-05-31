/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
     ↓
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
     ↓   ↓    ↓    ↓  ↓
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
     ↓   ↓    ↓
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true

Your ValidWordAbbr object will be instantiated and called as such:
ValidWordAbbr obj = new ValidWordAbbr(dictionary);
bool param_1 = obj.isUnique(word);

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class ValidWordAbbr {
public:
    unordered_map <string, vector<string>> map;
    ValidWordAbbr(vector<string> dictionary) {
        for (string word:dictionary) {
            string temp = word[0] + to_string(word.size() - 2) + word[word.size() - 1];
            if (notPresent(word, temp))
                map[temp].push_back(word);
        }
    }

    bool notPresent(string word, string temp) {
        for (int it = 0; it < map[temp].size(); it++) {
            if (map[temp][it] == word)
                return false;
        }
        return true;
    }

    bool isUnique(string word) {
        string check = "";
        check = word[0] + to_string(word.size() - 2) + word[word.size() - 1];
        auto it = map.find(check);
        if (it == map.end() || (map[check].size() == 1 && map[check][0] == word))
            return true;
        return false;
    }
};

int main () {
    vector<string> dictionary = {"a", "a"};
    string s;

    ValidWordAbbr obj(dictionary);

    cout << "\nEnter the string: ";
    cin >> s;

    cout << "\nUnique: " << obj.isUnique(s);

    cout << "\n\n";
}
