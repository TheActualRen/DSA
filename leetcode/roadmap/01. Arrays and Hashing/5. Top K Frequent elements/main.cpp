#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		vector<vector<int>> bucket(nums.size() + 1);
		vector<int> ans;

		for (int num : nums) {
			map[num]++;
		}

		for (auto pair : map) {
			bucket[pair.second].push_back(pair.first);
		}

		for (int i = bucket.size() - 1; i >= 0; --i) {
			if (k > 0) {
				for (int num : bucket[i]) {
					ans.push_back(num);
					k--;
				}
			} else {
				break;
			}
		}

		return ans;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {1,1,1,2,2,3};
	int k = 2;

	vector<int> ans = sol.topKFrequent(nums, k);

	for (int num : ans) {
		cout << num << " ";
	}

	cout << endl;
}
