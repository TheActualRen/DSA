#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
		int low = 1; int high = *max_element(piles.begin(), piles.end());
		int min_munching_rate = high;

		while (low <= high) {
			int munching_rate = low + (high - low) / 2;

			bool valid = true;
			int time_to_eat = h;

			for (int pile : piles) {
				if (pile % munching_rate == 0) {
					time_to_eat -= (pile / munching_rate);
				} else {
					time_to_eat -= ( (pile / munching_rate) + 1);
				}

				if (time_to_eat < 0) {
					valid = false;
					break;
				}	
			}

			if (!valid) {
				low = munching_rate + 1;
			} else {
				high = munching_rate - 1;
				min_munching_rate = munching_rate;
			}
		}

		return min_munching_rate;
    }
};

int main() {
	vector<int> piles = {3, 6, 7, 11};
	int h = 8;

	Solution sol;

	cout << sol.minEatingSpeed(piles, h) << endl;
}
