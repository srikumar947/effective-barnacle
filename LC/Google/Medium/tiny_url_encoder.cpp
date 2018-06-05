/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	unordered_map<string, string> map;

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		auto pos = longUrl.find_last_of('/');
		string x = longUrl.substr(pos + 1);
		map[x] = longUrl;
		return x;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return map[shortUrl];
	}
};

int main () {
	Solution obj;
	string s, pass = "https://leetcode.com/problems/", enc, dec;
	cout << "\n Enter last part of url: ";
	cin >> s;
	pass += s;
	enc = obj.encode(pass);
	cout << "\n Encoded: " << enc;
	dec = obj.decode(enc);
	cout << "\n Decoded: " << dec;

	cout << "\n\n";
	return 0;
}
