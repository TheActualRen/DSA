#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b ) {
		if (a.size() > b.size()) {
			swap(a, b);
		}

		const int m = a.size();
		const int n = b.size();
		const int all = m + n;

		int low = 0; int high = m;

		while (low <= high) {
			int mid_a = low + (high - low) / 2;
			int mid_b = (all + 1) / 2 - mid_a;

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

			if (left_a <= right_b && left_b <= right_a) {
				if (all % 2 == 1) {
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
