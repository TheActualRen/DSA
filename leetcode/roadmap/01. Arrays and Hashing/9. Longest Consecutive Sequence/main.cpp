#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		int longestSequence = 0;
		unordered_set<int> set;

		for (int num : nums) {
			set.insert(num);
		}

		for (int num : set) {
			if (set.find(num - 1) == set.end()) {
				int count = 0;

				while (set.find(num + count) != set.end()) {
					count++;
				}
				
				longestSequence = max(longestSequence, count);
			}
		}

		return longestSequence;
    }
};
