#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		// inp : {1, 2, 3, 4}
		// lhs : {1, 1, 2, 6}
		// rhs : {24, 12, 4, 1}
		// ans : {24, 12, 8, 6}
		
		vector<int> ans = {1};

		int curr_multiple = 1;

		for (int i = 0; i < nums.size() - 1; i++) {
			curr_multiple *= nums[i];
			ans.push_back(curr_multiple);
		}

		curr_multiple = 1;

		for (int i = nums.size() - 1; i > 0; --i) {
			curr_multiple *= nums[i];
			ans[i - 1] *= curr_multiple;
		}

		return ans;
    }
};
