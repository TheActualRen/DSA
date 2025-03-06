#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
		vector<pair<int, float>> pos_and_times;

		for (int i = 0; i < pos.size(); i++) {
			float time_to_target = static_cast<float>(target - pos[i]) / speed[i];
			pos_and_times.push_back( {pos[i], time_to_target} );
		}

		sort(pos_and_times.begin(), pos_and_times.end());

		float min_time = 0.0;
		int car_fleet = 0;
		for (int i = pos_and_times.size() - 1; i >= 0; --i) {
			if (pos_and_times[i].second > min_time) {
				car_fleet++;
				min_time = pos_and_times[i].second;
			}
		}

		return car_fleet;
    }
};

int main () {
	int target = 12;
	vector<int> pos = {10,8,0,5,3};
	vector<int> speed = {2,4,1,1,3};

	Solution sol;

	int ans = sol.carFleet(target, pos, speed);
	cout << ans << endl;
}
