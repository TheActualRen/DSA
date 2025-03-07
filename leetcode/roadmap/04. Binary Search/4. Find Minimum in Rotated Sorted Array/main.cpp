#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		int low = 0; int high = nums.size() - 1;

		while (low < high) {
			int mp = low + (high - low) / 2;

            if (nums[mp] > nums[high]) {
				low = mp + 1;
			} else {
				high = mp;
			}
		}

		return nums[low];
    }
};
