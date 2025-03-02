#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end()); // makes it the same as Two Sum II       
		
		set<vector<int>> set;

		for (int i = 0; i < nums.size(); i++) {
			int target = 0 - nums[i];
			int l = i + 1; int r = nums.size() - 1;

			while (l < r) {
				if (nums[l] + nums[r] < target) {
					l++;
				} else if (nums[l] + nums[r] > target) {
					r--;
				} else {
					set.insert( {nums[i], nums[l], nums[r]} );
					l++;
					r--;
				}
			}
		}

		return vector<vector<int>>(set.begin(), set.end());
    }
};
