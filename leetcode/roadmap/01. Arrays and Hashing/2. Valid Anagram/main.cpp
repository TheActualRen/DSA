#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		unordered_map<char, int> map;

		for (char ch : s) {
			map[ch]++;
		}

		for (char ch : t) {
			if (map.find(ch) == map.end() || map[ch] == 0) {
				return false;
			}

			map[ch]--;
		}

		return true;
    }
};
