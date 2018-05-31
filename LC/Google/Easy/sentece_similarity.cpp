/*
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size())
        return false;

    unordered_map <string, vector<string>> map;

    int i = 0;

    for (i = 0; i < pairs.size(); i++) {
        map[pairs[i].first].push_back(pairs[i].second);
        map[pairs[i].second].push_back(pairs[i].first);
    }

    for (i = 0; i < words1.size(); i++) {
        if (words1[i] != words2[i] && find(map[words1[i]].begin(), map[words1[i]].end(), words2[i]) == map[words1[i]].end())
            return false;
    }

    return true;
}

int main () {
    vector<pair<string, string>> pairs;
    pair<string, string> ins;
    vector<string> w1, w2;
    string x, y;
    int n, i;

    cout << "\n Enter number of words: ";
    cin >> n;

    cout << "\n Enter words: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        w1.push_back(x);
    }

    cout << "\n Enter number of words: ";
    cin >> n;

    cout << "\n Enter words: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        w2.push_back(x);
    }

    cout << "\n Enter number of pairs: ";
    cin >> n;

    cout << "\n Enter pairs: ";
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        ins.first = x;
        ins.second = y;
        pairs.push_back(ins);
    }


    cout << "\n Similar: " << areSentencesSimilar(w1, w2, pairs);

    cout << "\n\n";
}
