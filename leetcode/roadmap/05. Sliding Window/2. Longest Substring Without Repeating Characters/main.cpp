#include <bits/stdc++.h>
using namespace std;

// Initial thoughts: hashset

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_set<char> hashset;

		int maxSubstring = 0;
		int l = 0; int r = 0;

		while (r < s.size()) {
			while (hashset.find(s[r]) != hashset.end()) {
				hashset.erase(hashset.find(s[l]));
				l++;
			}

			hashset.insert(s[r]);
			
			maxSubstring = max(maxSubstring, static_cast<int>(hashset.size()));
			r++;
		}

		return maxSubstring;
    }
};

