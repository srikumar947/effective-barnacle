/*
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode {
    vector<int> prefix;
    vector<TrieNode*> children;
    TrieNode() {
        children.resize(26, NULL);
    }
};

TrieNode* buildTrie(vector<string> words) {
    TrieNode *root = new TrieNode();
    for (int i = 0; i < words.size(); i++) {
        TrieNode *t = root;
        for (int j = 0; j < words[i].size(); j++) {
            if (t->children[words[i][j] - 'a'] == NULL)
                t->children[words[i][j] - 'a'] = new TrieNode();
            t = t->children[words[i][j] - 'a'];
            t->prefix.push_back(i);
        }
    }
    return root;
}

void backtrack(vector<string>& board, int level, vector<vector<string>>& ret, TrieNode *root, vector<string>& words) {
    if (level >= words[0].size()) {
        ret.push_back(board);
        return;
    }

    string temp = "";
    for (int i = 0; i < level; i++)
        temp += board[i][level];

    TrieNode *t = root;
    for (int i = 0; i < temp.size(); i++)
        if (!(t = t->children[temp[i] - 'a']))
            return;
    for (auto i : t->prefix) {
        board[level] = words[i];
        backtrack(board, level + 1, ret, root, words);
    }
}

vector<vector<string>> wordSquares(vector<string>& words) {
    vector<vector<string>> ret;
    if (words.size() < 1)
        return ret;

    TrieNode *root = buildTrie(words);
    vector<string> board(words[0].size());

    for (auto w : words) {
        board[0] = w;
        backtrack(board, 1, ret, root, words);
    }

    return ret;
}

int main() {
    int i, n;
    string temp;
    vector<string> words;

    cout << "\n Enter number of words: ";
    cin >> n;

    cout << "\n Enter words: ";
    for (i = 0; i < n; i++) {
        cin >> temp;
        words.push_back(temp);
    }

    vector<vector<string>> ret = wordSquares(words);

    cout << "\n Word Squares: \n";
    for (i = 0; i < ret.size(); i++) {
        for (n = 0; n < ret[i].size(); n++) {
            cout << ret[i][n] << "\n";
        }
        cout << "\n\n";
    }


    cout << "\n\n";
    return 0;
}
