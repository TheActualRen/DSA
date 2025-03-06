#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void backtrack(vector<string> &ans, int open, int close, string current_str, int n) {
		if (current_str.length() == n * 2) {
			ans.push_back(current_str);
			return;
		}

		if (open < n) {
			backtrack(ans, open + 1, close, current_str + "(", n);
		}

		if (close < open) {
			backtrack(ans, open, close + 1, current_str + ")", n);
		}
	}

    vector<string> generateParenthesis(int n) {
		vector<string> ans;
		backtrack(ans, 0, 0, "", n);

		return ans;
    }
};
