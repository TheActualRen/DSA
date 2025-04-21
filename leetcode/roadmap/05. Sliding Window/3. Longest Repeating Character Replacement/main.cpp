#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
		int l = 0; int r = 0;
		int longest = 0;

		unordered_map<char, int> map; 
		int max_freq = 0;

		while (r < s.length()) {
			map[s[r]]++;
			max_freq = max(max_freq, map[s[r]]);

			while ((r - l + 1 - max_freq) > k) {
				map[s[l]]--;
				l++;
			}

			longest = max(longest, r - l + 1);
			r++;
		}

		return longest;
    }
};

int main() {
	Solution sol;
	string s = "XYYX";
	int k = 2;

	cout << sol.characterReplacement(s, k) << endl;
}

