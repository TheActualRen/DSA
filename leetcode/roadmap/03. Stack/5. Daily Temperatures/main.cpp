#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int> &temps) {
		vector<int> ans(temps.size(), 0);
		stack<int> stack;

		for (int i = temps.size() - 1; i >= 0; --i) {
			while (!stack.empty() && temps[i] >= temps[stack.top()]) {
				cout << stack.top() << " has been popped from the stack" << endl;
				stack.pop();
			}

			if (!stack.empty()) {
				ans[i] = stack.top() - i;
			}

			stack.push(i);
			cout << i << " has been pushed to the stack" << endl;
		}

		cout << endl;
		
		return ans;
	}
};

int main() {
	vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
	Solution sol;

	vector<int> ans = sol.dailyTemperatures(temps);

	for (int num : ans) {
		cout << num << " ";
	}

	cout << endl;
}
