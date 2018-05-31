/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.

Your Codec object will be instantiated and called as such:
Codec codec;
codec.decode(codec.encode(strs));
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Codec {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for (string temp:strs)
            ret += to_string(temp.size()) + '!' + temp;
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> output;
        int iterator = 0;

        while (iterator < s.size()) {
            int pos = s.find_first_of('!', iterator);
            int n = atoi(&s[iterator]);                 // int n = stoi(s.substr(iterator, 1)); Either will work
            iterator = pos + 1;
            output.push_back(s.substr(iterator, n));
            iterator += n;
        }

        return output;
    }
};



int main () {
    vector<string> input, output;
    string x, ret;
    int i, n;

    cout << "\n Enter number of strings: ";
    cin >> n;

    cout << "\n Enter strings: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        input.push_back(x);
    }

    Codec codec;

    ret = codec.encode(input);
    cout << "\n Encoded string is: " << ret;

    output = codec.decode(ret);
    cout << "\n Decoded string is: ";

    for (i = 0; i < output.size(); i++)
        cout << output[i] << " ";

    cout << "\n\n";
}
