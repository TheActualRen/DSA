#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int low = 0; int high = nums.size() - 1;

		while (low <= high) {
			int mp = low + (high - low) / 2;

			if (nums[mp] < target) {
				low = mp + 1;
			} else if (nums[mp] > target) {
				high = mp - 1;
			} else {
				return mp;
			}
		}

		return -1;
    }
};
