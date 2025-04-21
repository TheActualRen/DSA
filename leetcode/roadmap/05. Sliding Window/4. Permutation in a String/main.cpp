#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
		if (s1.length() > s2.length()) {
			return false;
		}

		vector<int> f1(26, 0);
		vector<int> f2(26, 0);

		for (int i = 0; i < s1.length(); i++) {
			f1[s1[i] - 'a']++;
			f2[s2[i] - 'a']++;
		}

		int l = 0; int r = s1.length() - 1; 
        while (r < s2.length()) {
			if (f1 == f2) {
				return true;
			}
            r++;

			if (r < s2.length()) {
				f2[s2[r] - 'a']++;
				f2[s2[l] - 'a']--;
			}

			l++;
		}

		return false;
	}
};

int main() {
	Solution sol;
	string s1 = "abc";
	string s2 = "lecabee";

	cout << sol.checkInclusion(s1, s2) << endl;
}
