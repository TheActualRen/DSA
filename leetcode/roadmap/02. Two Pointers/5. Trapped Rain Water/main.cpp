#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		int agua = 0;       

		int l = 0; int r = height.size() - 1;
		int lMax = 0; int rMax = 0;

		while (l < r) {
            if (height[l] < height[r]) {
				lMax = max(lMax, height[l]);
				agua += lMax - height[l];
				l++;
			}

            else {
				rMax = max(rMax, height[r]);
				agua += rMax - height[r];
				r--;
			} 
		}

		return agua;
    }
};
