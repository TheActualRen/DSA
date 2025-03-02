#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str;
        
        for (string str : strs) {
            encoded_str += str + "|";
        }

        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> decoded_str;
        string word;

        for (char ch : s) {
            if (ch != '|') {
                word += ch;
            } else {
                decoded_str.push_back(word);
                word.clear();
            }
        }

        return decoded_str;
    }
};

