/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    int i = 0;

    for (i = 0; i < magazine.size(); i++) {
        if (map.find(magazine[i]) != map.end())
            map[magazine[i]] += 1;
        else
            map[magazine[i]] = 1;
    }

    for (i = 0; i < ransomNote.size(); i++) {
        if (map.find(ransomNote[i]) == map.end() || map[ransomNote[i]] < 1)
            return false;
        map[ransomNote[i]] -= 1;
    }

    return true;
}

int main() {
    string ransomNote, magazine;

    cout << "\n Enter the Ransom Note: ";
    cin >> ransomNote;

    cout << "\n Enter the Magazine: ";
    cin >> magazine;

    cout << "\n Note can constructed: " << canConstruct(ransomNote, magazine);

    cout << "\n\n";
    return 0;
}
