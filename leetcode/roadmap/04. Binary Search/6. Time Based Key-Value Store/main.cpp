#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:	
	unordered_map< string, vector<pair<string, int>> > map;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
		map[key].push_back( {value, timestamp} );
    }
    
    string get(string key, int timestamp) {
		if (map.find(key) == map.end()) {
			return "";
		}

		string ans;
		int low = 0; int high = map[key].size() - 1;

		while (low <= high) {
			int mp = low + (high - low) / 2;

			if (map[key][mp].second <= timestamp) {
				ans = map[key][mp].first;
				low = mp + 1;
			} else {
				high = mp - 1;
			}
		}

		return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
