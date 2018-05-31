/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
Example 1:
Input:
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input:
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].

aaabbcc
<b>aaa</b>bbcc

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(int x, int y) : start(x), end(y) {}
};

vector<Interval> createIntervals(string s, vector<string> dict) {
    vector<Interval> store;
    int pos, i, n = dict.size();

    for (i = 0; i < n; i++) {
        pos = s.find(dict[i]);
        while (pos != string::npos) {
            Interval in(pos, pos + dict[i].size() - 1);
            store.push_back(in);
            pos = s.find(dict[i], pos + 1);
        }
    }
    return store;
}

vector<Interval> mergeIntervals(vector<Interval> store) {
    if (store.size() < 2)
        return store;

    vector<Interval> merged;
    sort(store.begin(), store.end(), [](Interval a, Interval b) {return a.start < b.start;});
    merged.push_back(store[0]);
    for (int i = 1; i < store.size(); i++) {
        if (store[i].start <= merged.back().end + 1)
            merged.back().end = max(merged.back().end, store[i].end);
        else
            merged.push_back(store[i]);
    }
    return merged;
}

string bold(vector<Interval> merged, string s) {
    if (merged.size() < 1)
        return s;

    for (int i = 0; i < merged.size(); i++) {
        s.insert(merged[i].start + i*7, "<b>");
        s.insert(merged[i].end + 4 + i*7, "</b>");
    }
    return s;
}

string addBoldTag(string s, vector<string>& dict) {
    if (dict.size() < 1)
        return s;

    vector<Interval> store, merged;
    int i, pos = -1, n = dict.size();

    store = createIntervals(s, dict);
    merged = mergeIntervals(store);
    s = bold(merged, s);

    return s;
}

int main () {
    string ret;
    vector<string> dict;
    string s;
    int i, n, j;

    cout << "\nEnter number of words: ";
    cin >> n;

    cout << "\nEnter words - \n";
    for (i = 0; i < n; i++) {
        cin >> s;
        dict.push_back(s);
    }

    cout << "\nEnter the string: ";
    cin >> s;

    ret = addBoldTag(s, dict);

    cout << "\nBolded String: " << ret;

    cout << "\n\n";
}
