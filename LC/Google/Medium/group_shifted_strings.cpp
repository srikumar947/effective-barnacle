/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

Input

["fpbnsbrkbcyzdmmmoisaa","cpjtwqcdwbldwwrryuclcngw","a","fnuqwejouqzrif","js","qcpr","zghmdiaqmfelr","iedda","l","dgwlvcyubde","lpt","qzq","zkddvitlk","xbogegswmad","mkndeyrh","llofdjckor","lebzshcb","firomjjlidqpsdeqyn","dclpiqbypjpfafukqmjnjg","lbpabjpcmkyivbtgdwhzlxa","wmalmuanxvjtgmerohskwil","yxgkdlwtkekavapflheieb","oraxvssurmzybmnzhw","ohecvkfe","kknecibjnq","wuxnoibr","gkxpnpbfvjm","lwpphufxw","sbs","txb","ilbqahdzgij","i","zvuur","yfglchzpledkq","eqdf","nw","aiplrzejplumda","d","huoybvhibgqibbwwdzhqhslb","rbnzendwnoklpyyyauemm"]

d i a l
js nw
lpt txb
qzq sbs
eqdf qcpr
iedda zvuur
mkndeyrh wuxnoibr
ohecvkfe lebzshcb
lwpphufxw zkddvitlk
llofdjckor kknecibjnq
gkxpnpbfvjm xbogegswmad
ilbqahdzgij dgwlvcyubde
zghmdiaqmfelr yfglchzpledkq
fnuqwejouqzrif aiplrzejplumda
oraxvssurmzybmnzhw firomjjlidqpsdeqyn
rbnzendwnoklpyyyauemm fpbnsbrkbcyzdmmmoisaa
yxgkdlwtkekavapflheieb dclpiqbypjpfafukqmjnjg
wmalmuanxvjtgmerohskwil lbpabjpcmkyivbtgdwhzlxa
huoybvhibgqibbwwdzhqhslb cpjtwqcdwbldwwrryuclcngw
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool shifting (string a, string b) {
    for (int i = 1; i < a.size(); i++) {
        if ((a[i] - a[i - 1] + 26) % 26 !=  (b[i] - b[i - 1] + 26) % 26)
            return false;
    }
    return true;
}

bool isPresent (string s, vector<vector<string>> store) {
    for (int i = 0; i < store.size(); i++) {
        for (int j = 0; j < store[i].size(); j++) {
            if (s == store[i][j])
                return true;
        }
    }
    return false;
}

vector<vector<string>> groupStrings(vector<string>& input) {
    vector<vector<string>> ret;

    if (input.size() < 1)
        return ret;

    if (input.size() == 1) {
        ret.push_back(input);
        return ret;
    }

    sort(input.begin(), input.end(), [](string a, string b) {return a.size() < b.size();});

    int i = 0, n, j = 0, flag = 0;
    string check;
    vector<string> temp;

    while (input[i].size() == 0)
        i += 1;

    while (i < input.size() - 1) {
        if (isPresent(input[i], ret)) {
            i += 1;
            continue;
        }

        temp.clear();
        temp.push_back(input[i]);
        n = input[i].size();
        check = input[i];
        j = i + 1;
        flag = 0;

        while (j < input.size() && input[j].size() == n) {
            if (shifting(input[j], check))
                temp.push_back(input[j]);
            j += 1;
        }

        if (j - i == temp.size())
            i = j;

        else
            i += 1;

        ret.push_back(temp);
    }

    if (i == input.size() - 1 && !isPresent(input[i], ret)) {
        temp.clear();
        temp.push_back(input[i]);
        ret.push_back(temp);
    }

    return ret;
}

int main () {
    vector<vector<string>> ret;
    vector<string> input = {"fpbnsbrkbcyzdmmmoisaa", "cpjtwqcdwbldwwrryuclcngw", "a", "fnuqwejouqzrif", "js", "qcpr", "zghmdiaqmfelr", "iedda", "l", "dgwlvcyubde", "lpt", "qzq", "zkddvitlk", "xbogegswmad", "mkndeyrh", "llofdjckor", "lebzshcb", "firomjjlidqpsdeqyn", "dclpiqbypjpfafukqmjnjg", "lbpabjpcmkyivbtgdwhzlxa", "wmalmuanxvjtgmerohskwil", "yxgkdlwtkekavapflheieb", "oraxvssurmzybmnzhw", "ohecvkfe", "kknecibjnq", "wuxnoibr", "gkxpnpbfvjm", "lwpphufxw", "sbs", "txb", "ilbqahdzgij", "i", "zvuur", "yfglchzpledkq", "eqdf", "nw", "aiplrzejplumda", "d", "huoybvhibgqibbwwdzhqhslb", "rbnzendwnoklpyyyauemm"};
    string temp;
    int i, n, j;
    /*
    cout << "\nEnter number of strings: ";
    cin >> n;

    cout << "\nEnter strings - \n";
    for (i = 0; i < n; i++) {
        cin >> temp;
        input.push_back(temp);
    }
    */
    ret = groupStrings(input);

    cout << "\nGrouped Strings - \n";
    for (i = 0; i < ret.size(); i++) {
        for (j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";
}
