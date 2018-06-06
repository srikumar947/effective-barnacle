/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

Your Trie object will be instantiated and called as such:
Trie obj;
obj.insert(word);
bool param_2 = obj.search(word);
bool param_3 = obj.startsWith(prefix);
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
	struct TrieNode {
		char x;
		vector<TrieNode*> next;
		TrieNode(char c) : x(c), next(0) {}
	};

	TrieNode *root;

    Trie() {
		root = new TrieNode(' ');
    }

	TrieNode* find(vector<TrieNode*>& t, char x) {
		for (int i = 0; i < t.size(); i++)
			if (t[i]->x == x)
				return t[i];

		return NULL;
	}

    /** Inserts a word into the trie. */
    void insert(string word) {
		int i = 0;
		TrieNode *t = root;

		TrieNode *p = find(t->next, word[i]);

		while (i < word.size() && p != NULL) {
			t = p;
			p = find(t->next, word[++i]);
		}

		while (i < word.size()) {
			TrieNode *c = new TrieNode(word[i++]);
			t->next.push_back(c);
			t = c;
		}

		TrieNode *c = new TrieNode('1');
		t->next.push_back(c);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
		int i = 0;
		TrieNode *t = root;
		TrieNode *p = find(t->next, word[i]);

		while (i < word.size() && p != NULL) {
			t = p;
			p = find(t->next, word[++i]);
		}

		if (i == word.size()) {
			for (i = 0; i < t->next.size(); i++)
				if (t->next[i]->x == '1')
					return true;
		}

		return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		int i = 0;
		TrieNode *t = root;
		TrieNode *p = find(t->next, prefix[i]);

		while (i < prefix.size() && p != NULL) {
			t = p;
			p = find(t->next, prefix[++i]);
		}

		return i == prefix.size();
    }

	void print() {
		queue<TrieNode*> q;
		q.push(root);

		while (!q.empty()) {
			TrieNode *temp = q.front();
			q.pop();

			cout << temp->x << " ";
			for (int i = 0; i < temp->next.size(); i++)
				q.push(temp->next[i]);
		}
	}
};

int main () {
	Trie obj;
	obj.insert("apple");
	cout << obj.search("apple") << " ";
	cout << obj.search("app") << " ";
	cout << obj.startsWith("app") << " ";
	obj.insert("app");
	cout << obj.search("app");

	cout << "\n\n";
	return 0;
}
