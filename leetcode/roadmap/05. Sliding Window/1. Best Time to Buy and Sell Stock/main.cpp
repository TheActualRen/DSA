#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int maxP = 0;
		int lp = 0; int rp = 1;

		while (rp < prices.size()) {
            maxP = max(maxP, prices[rp] - prices[lp]);
			if (prices[rp] < prices[lp]) {
				lp = rp;
			}
			rp++;
		}

		return maxP;
    }
};
