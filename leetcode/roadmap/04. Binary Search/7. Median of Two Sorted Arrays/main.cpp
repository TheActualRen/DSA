#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
		if (a.size() > b.size()) {
			swap(a, b);
		}

		const int m = a.size();
		const int n = b.size();

		int low = 0; int high = m;

		while (low <= high) {
			int mid_a = low + (high - low) / 2;
			int mid_b = (m + n + 1) / 2 - mid_a;

			int left_a = INT_MIN; int left_b = INT_MIN;
			int right_a = INT_MAX; int right_b = INT_MAX;

			if (mid_a - 1 >= 0) {
				left_a = a[mid_a - 1];
			} 

			if (mid_a < m) {
				right_a = a[mid_a];
			}

			if (mid_b - 1 >= 0) {
				left_b = b[mid_b - 1];
			}

			if (mid_b < n) {
				right_b = b[mid_b];
			}

			cout << "mid_a: " << mid_a << endl;
			cout << "mid_b: " << mid_b << endl;
			cout << "left_a: " << left_a << endl;
			cout << "left_b: " << left_b << endl;
			cout << "right_a: " << right_a << endl;
			cout << "right_b: " << right_b << endl;

			if (left_a <= right_b && left_b <= right_a) {
				if ((m + n) % 2 != 0) {
					return static_cast<double>(max(left_a, left_b));
				} else {
					return ( max(left_a, left_b) + min(right_a, right_b) ) / 2.0;
				}
			} else if (left_a > right_b) {
				high = mid_a - 1;
			} else {
				low = mid_a + 1;
			}
		}
		return 0.0;
    }
};

int main() {
	vector<int> a = {1, 1, 13, 17, 19};
	vector<int> b = {1, 7, 9, 9, 12, 13, 17};

	Solution sol;
	cout << sol.findMedianSortedArrays(a, b);
}

