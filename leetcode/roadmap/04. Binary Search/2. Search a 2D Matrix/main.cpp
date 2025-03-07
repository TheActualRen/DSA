#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		int rows = matrix.size();
		int cols = matrix[0].size();

		int low = 0;
		int high = rows * cols - 1;

		while (low <= high) {
		    int mp = low + (high - low) / 2;
		    int m_val = matrix[mp / cols][mp % cols];
			cout << m_val << endl;

			if (m_val < target) {
				low = mp + 1;
			} else if (m_val > target) {
				high = mp - 1;
			} else {
				return true;
			}
		}

		return false;
	}
};

int main() {
	vector<vector<int>> matrix = {
		{1,3,5,7},
		{10,11,16,20},
		{23,30,34,60}
	};
	int target = 13;

	Solution sol;

	cout << sol.searchMatrix(matrix, target);
}
