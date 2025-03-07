#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int max_area = 0;
		stack< pair<int, int> > stack;

		for (int i = 0; i < heights.size(); i++) {
			int start = i;

			while (!stack.empty() && heights[i] < stack.top().second) {
				int idx = stack.top().first;
				int h = stack.top().second;
				stack.pop();

				max_area = max(max_area, h * (i - idx));
				start = idx;
			}

			stack.push( {start, heights[i]} );
		}

		while (!stack.empty()) {
			int idx = stack.top().first;
			int h = stack.top().second;
			stack.pop();

			max_area = max( max_area, h * static_cast<int>(heights.size() - idx) );
		}

		return max_area;
    }
};

int main() {
	Solution sol;
	vector<int> heights = {2,1,5,6,2,3};
	
	cout << sol.largestRectangleArea(heights) << endl;
}
