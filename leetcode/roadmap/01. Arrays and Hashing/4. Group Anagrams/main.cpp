#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string gen_f_string(string &str) {
		string f_string;
		vector<int> f_map(26, 0);

		for (char ch : str) {
			f_map[ch - 'a']++;
		}

		char ch = 'a';

		for (int f : f_map) {
			f_string += ch;
			f_string += to_string(f);
			ch++;
		
		}

		return f_string;
	}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> map;

		for (string str : strs) {
			map[gen_f_string(str)].push_back(str);
		}

		vector<vector<string>> ans;

		for (auto pair : map) {
			ans.push_back(pair.second);
		}

		return ans;
    }
};
